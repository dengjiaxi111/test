#include "nav_components/slopehole_ros_adapter.hpp"
#include <chrono>
#include <random>
#include <fstream>
#include <cstdio>
#include <tf2/utils.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
namespace nav_components {
using namespace nav_core::hole_exec;
namespace {
// 与普通控制器一致，容纳不同 /clock 订阅者间至多10ms的相位差。
// 超龄、重复和乱序数据仍不得刷新有效样本。
bool sampleFresh(double now,double stamp,double timeout) {
    return std::isfinite(stamp)&&now-stamp>=-.01&&now-stamp<=timeout;
}
}
static Config readConfig(rclcpp::Node* n) {
    if(!n->has_parameter("hole_state_machine.config_file"))n->declare_parameter("hole_state_machine.config_file",std::string{});
    return loadHoleExecutionConfig(n->get_parameter("hole_state_machine.config_file").as_string());
}
SlopeHoleRosAdapter::SlopeHoleRosAdapter(rclcpp::Node* n):node_(n),config_(readConfig(n)),core_(config_) {
    chassis_tf_=std::make_unique<tf2_ros::Buffer>(node_->get_clock());
    chassis_listener_=std::make_unique<tf2_ros::TransformListener>(*chassis_tf_);
    rotation_sub_=n->create_subscription<sensor_msgs::msg::JointState>("/rotation/feedback",10,
        [this](sensor_msgs::msg::JointState::ConstSharedPtr m){
            const double stamp=rclcpp::Time(m->header.stamp).seconds(),now=node_->now().seconds();
            if(m->header.frame_id!="odom"||stamp<=rotation_stamp_||!sampleFresh(now,stamp,config_.feedback_timeout)||
                m->name.size()!=2||m->position.size()!=2||m->velocity.size()!=2||
                m->name[0]!="chassis_world_yaw"||m->name[1]!="gimbal_world_yaw"||
                !std::isfinite(m->position[0])||!std::isfinite(m->position[1])||
                !std::isfinite(m->velocity[0])||!std::isfinite(m->velocity[1]))return;
            rotation_stamp_=stamp;rotation_received_=now;chassis_rate_=m->velocity[0];gimbal_rate_=m->velocity[1];
            rotation_chassis_yaw_=m->position[0];gimbal_yaw_=m->position[1];
        });
    speed_sub_=n->create_subscription<nav_msgs::msg::Odometry>("/Odometry/fake",rclcpp::SensorDataQoS(),
        [this](nav_msgs::msg::Odometry::ConstSharedPtr m){
            if(m->header.frame_id!="odom"||m->child_frame_id!="base_link_fake")return;
            const double stamp=rclcpp::Time(m->header.stamp).seconds();
            const double now=node_->now().seconds();
            if(!std::isfinite(m->twist.twist.linear.x)||!std::isfinite(m->twist.twist.linear.y)||
               stamp<=speed_stamp_||!sampleFresh(now,stamp,config_.feedback_timeout))return;
            velocity_odom_={m->twist.twist.linear.x,m->twist.twist.linear.y};
            measured_speed_=holeNorm(velocity_odom_);
            speed_received_=node_->now().seconds();speed_stamp_=rclcpp::Time(m->header.stamp).seconds();
        });
    session_=std::to_string(std::random_device{}())+"-"+std::to_string(node_->now().seconds());
    alignment_pub_=n->create_publisher<std_msgs::msg::Float64>("hole_alignment_target",10);
    rotation_inhibit_pub_=n->create_publisher<std_msgs::msg::Bool>("hole_rotation_inhibit",10);
    plan_pub_=n->create_publisher<nav_interfaces::msg::NavigationPlan>("navigation_plan",rclcpp::QoS(1).reliable().transient_local());
    request_pub_=n->create_publisher<nav_interfaces::msg::HoleStructureRequest>("hole_structure/request",10);
    state_pub_=n->create_publisher<nav_interfaces::msg::HoleTraversalState>("hole_traversal_state",10);
    event_pub_=n->create_publisher<nav_interfaces::msg::HoleTraversalEvent>("hole_traversal_event",10);
    feedback_sub_=n->create_subscription<nav_interfaces::msg::HoleStructureFeedback>("hole_structure/feedback",10,
        [this](nav_interfaces::msg::HoleStructureFeedback::ConstSharedPtr m){
            const double age=(node_->now()-rclcpp::Time(m->header.stamp)).seconds();
            if(!std::isfinite(age)||age<-.01||age>config_.feedback_timeout||m->target>2||m->status>3||
               (m->simulated!=config_.simulation_only))return;
            feedback_={m->session_id,m->goal_id,m->request_id,m->requirement_revision,node_->now().seconds(),std::max(0.,age),
                static_cast<Posture>(m->target),static_cast<ActionStatus>(m->status),m->whole_vehicle_clear,
                m->normal_clearance,m->moving_transition_supported,{m->cleared_traversal_uids.begin(),m->cleared_traversal_uids.end()},m->action_stopped,m->retry_allowed,m->fault_code};
        });
    initializeTuning();
}
double SlopeHoleRosAdapter::measuredSpeed() const {
    const double now=node_->now().seconds();
    if(speed_received_<0||now-speed_received_>config_.feedback_timeout||now-speed_stamp_>config_.feedback_timeout||now<speed_stamp_-.01)
        return std::numeric_limits<double>::quiet_NaN();
    return measured_speed_;
}
bool SlopeHoleRosAdapter::beginGoal() {
    if(!enabled())return true;
    if(!core_.canAcceptNewGoal()||!canRecover())return false;
    speed_takeover_.reset();takeover_authorized_=false;prepare_started_=-1;prepare_request_id_=0;preparation_remaining_=0;
    goal_=std::to_string(++goal_sequence_);alignment_targets_.clear();aligning_uid_.clear();alignment_stable_=-1;traversal_retries_.clear();retreat_phase_=0;blocked_.clear();replans_=0;updated_=-1;
    std_msgs::msg::Bool inhibit;inhibit.data=false;rotation_inhibit_pub_->publish(inhibit);return true;
}
Input SlopeHoleRosAdapter::input(const geometry_msgs::msg::PoseStamped& p,double speed) const {
    Input in;in.now=node_->now().seconds();
    const double age=(node_->now()-rclcpp::Time(p.header.stamp)).seconds();
    in.pose_received=std::min(in.now,in.now-age);in.position={p.pose.position.x,p.pose.position.y};
    in.pose_valid=p.header.frame_id=="map"&&sampleFresh(in.now,in.now-age,config_.pose_timeout);
    in.measured_speed=speed;
    double chassis_age=std::numeric_limits<double>::quiet_NaN();
    try {
        const auto t=chassis_tf_->lookupTransform("map","chassiss",tf2::TimePointZero);
        chassis_age=(node_->now()-rclcpp::Time(t.header.stamp)).seconds();
        if(!std::isfinite(chassis_age)||chassis_age<-.01||chassis_age>config_.pose_timeout)in.pose_valid=false;
        in.chassis_yaw=tf2::getYaw(t.transform.rotation);
    }catch(const tf2::TransformException&){in.pose_valid=false;}
    if(!in.pose_valid||!std::isfinite(speed))RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
        "Slope input rejected: pose_frame=%s pose_age=%.6f chassis_tf_age=%.6f velocity_receive_age=%.6f velocity_source_age=%.6f speed=%.3f",
        p.header.frame_id.c_str(),age,chassis_age,in.now-speed_received_,in.now-speed_stamp_,speed);
    in.command_requested=last_command_speed_>0.05;in.recovery_authorized=retreat_phase_!=0;in.recovery_action_verified=retreat_phase_!=0;in.feedback=feedback_;in.continuation_verified=continuation_verified_;
    // 同时检查源消息年龄随时间的增长，重复缓存不能延长源数据寿命。
    if(feedback_.received>=0)in.feedback.source_age+=in.now-feedback_.received;
    return in;
}
bool SlopeHoleRosAdapter::acceptPath(SimplePlanner& planner,const nav_msgs::msg::Path& path,
    const geometry_msgs::msg::PoseStamped& pose,std::string& error) {
    if(!enabled())return true;
    try {
        if(!node_->get_parameter("hole_planner.enabled").as_bool())throw std::runtime_error("hole execution requires hole_planner.enabled");
        const auto& old=core_.plan();
        auto snap=planner.freezeHoleExecutionPlan(path);
        plan_sequence_=std::max(plan_sequence_,old.id);
        auto next=makeHoleExecutionPlan(snap,planner.terrainRegionMap(),config_,session_,goal_,++plan_sequence_,
            old.id?&old:nullptr,output_.progress,uid_sequence_);
        const auto original=next.passages;
        advanceSlopePreparation(next,config_.slope_prepare_distance);
        for(std::size_t i=0;i<next.passages.size();++i)if(event(next.passages[i],EventType::A).arc<event(original[i],EventType::A).arc)
            RCLCPP_INFO(node_->get_logger(),"FSM preparation advanced: hole=%s A=%.3f -> %.3f (slope lead %.3fm; path unchanged)",
                next.passages[i].hole_id.c_str(),event(original[i],EventType::A).arc,
                event(next.passages[i],EventType::A).arc,config_.slope_prepare_distance);
        auto in=input(pose,0);
        if(!core_.acceptPlan(next,in,error))return false;
        output_=Output{};updated_=-1;publishPlan();return true;
    }catch(const std::exception& e){error=e.what();core_.invalidate(error);return false;}
}
Output SlopeHoleRosAdapter::tick(const geometry_msgs::msg::PoseStamped& pose,double speed) {
    takeover_authorized_=false;
    if(!enabled()){Output out;out.decision=Decision::CONTINUE;out.speed_limit=std::numeric_limits<double>::infinity();return out;}
    const auto previous=output_;
    auto measured=input(pose,speed);
    measured.entry_rotation_ready=false; // 入洞必须等待真实对准；A发LOW不依赖此许可。
    // 先用实测反馈计算许可，再推进E事件，不能在事件触发后才补检查。
    std_msgs::msg::Float64 heading;heading.data=std::numeric_limits<double>::quiet_NaN();
    bool alignment_needed=false,entry_alignment_needed=false,rotation_fresh=false,orientation_good=false;
    double alignment_remaining=0;
    double effective_progress=output_.progress;
    if(measured.pose_valid&&!core_.plan().path.empty()) {
        Polyline path(core_.plan().path);
        effective_progress=std::max(effective_progress,path.project(measured.position,
            std::max(0.,output_.progress-config_.backward_window),std::min(path.length(),output_.progress+config_.forward_window)).arc);
    }
    for(const auto& p:core_.plan().passages) {
        const auto visit=core_.visits().find(p.uid);
        if(visit!=core_.visits().end()&&visit->second.complete)continue;
        const auto& begin=event(p,EventType::A);
        // A开始对准并同时由核心发LOW；A已过/未知的剩余路径立即准备。
        if(begin.range==Range::AFTER_PATH||(begin.range==Range::ON_PATH&&effective_progress+epsilon<begin.arc))continue;
        alignment_needed=true;
        measured.entry_rotation_uid=p.uid;
        entry_alignment_needed=visit==core_.visits().end()||!visit->second.emitted.count(EventType::E);
        auto it=alignment_targets_.find(p.uid);
        if(it==alignment_targets_.end()) {
            const double axis=std::atan2(p.entry_direction.y,p.entry_direction.x);
            double best=axis,err=10;
            for(int k=0;k<4;++k){double candidate=axis+k*M_PI/2,d=std::abs(std::remainder(candidate-measured.chassis_yaw,2*M_PI));if(d<err){err=d;best=candidate;}}
            it=alignment_targets_.emplace(p.uid,best).first;
        }
        heading.data=it->second;
        if(aligning_uid_!=p.uid){aligning_uid_=p.uid;alignment_stable_=-1;}
        const double now=measured.now;
        rotation_fresh=rotation_received_>=0&&sampleFresh(now,rotation_stamp_,config_.feedback_timeout)&&
            sampleFresh(now,rotation_received_,config_.feedback_timeout);
        orientation_good=measured.pose_valid&&
            std::abs(std::remainder(heading.data-measured.chassis_yaw,2*M_PI))<=config_.alignment_tolerance&&
            std::abs(std::remainder(gimbal_yaw_-rotation_chassis_yaw_,M_PI/2))<=config_.alignment_tolerance;
        const bool settled=orientation_good&&rotation_fresh&&
            std::abs(chassis_rate_)<config_.rotation_stopped_rate&&std::abs(gimbal_rate_)<config_.rotation_stopped_rate;
        if(!settled)alignment_stable_=-1;
        else if(alignment_stable_<0)alignment_stable_=now;
        measured.entry_rotation_ready=settled&&now-alignment_stable_>=config_.settle_time;
        if(!measured.entry_rotation_ready)alignment_remaining=std::max(
            std::abs(std::remainder(heading.data-measured.chassis_yaw,2*M_PI)),
            std::abs(std::remainder(gimbal_yaw_-rotation_chassis_yaw_,M_PI/2)))/config_.alignment_prediction_rate+
            config_.settle_time;
        // 角度接近零不代表已停转。尚无连续稳定确认时保持时间余量，
        // 防止预测突然缩到0.2s，车先加速、实际对准仍未完成而再次急停。
        if(!measured.entry_rotation_ready)alignment_remaining=std::max(alignment_remaining,config_.prepare_prediction_time);
        break;
    }
    if(!alignment_needed){aligning_uid_.clear();alignment_stable_=-1;}
    alignment_pub_->publish(heading);
    updated_=node_->now().seconds();output_=core_.update(measured);continuation_verified_=false;
    if(output_.state==State::HOLD&&previous.state==State::RESTORE) {
        nav_interfaces::msg::HoleStructureRequest keep;keep.header.stamp=node_->now();
        keep.session_id=session_;keep.goal_id=goal_;keep.target=static_cast<std::uint8_t>(Posture::KEEP);
        keep.cancel_motion=true;request_pub_->publish(keep); // 按session/goal停止当前抬高动作，不自动改变形态。
    }
    if(output_.cancel_request) {
        nav_interfaces::msg::HoleStructureRequest cancel;cancel.header.stamp=node_->now();cancel.session_id=session_;cancel.goal_id=goal_;
        cancel.target=0;cancel.cancel_motion=true;request_pub_->publish(cancel);
    }
    if(output_.request) {
        const auto& q=*output_.request;nav_interfaces::msg::HoleStructureRequest m;
        if(q.target==Posture::LOW&&q.id!=prepare_request_id_){prepare_request_id_=q.id;prepare_started_=measured.now;}
        m.header.stamp=node_->now();m.header.frame_id="map";m.session_id=q.session;m.goal_id=q.goal;
        m.request_id=q.id;m.requirement_revision=q.revision;m.target=static_cast<std::uint8_t>(q.target);
        m.traversal_uids=q.traversal_uids;request_pub_->publish(m);
    }
    const double low_remaining=core_.lowReady(measured)?0.:
        std::max(config_.settle_time,config_.prepare_prediction_time-
            (prepare_started_<0?0.:measured.now-prepare_started_));
    preparation_remaining_=alignment_needed&&!core_.entryAuthorized(aligning_uid_)?
        std::max(low_remaining,alignment_remaining):0.;
    // PREPARE沿用普通导航速度，只由未准备完成的E停车包络减速。
    if(entry_alignment_needed&&!core_.entryAuthorized(aligning_uid_)&&output_.decision==Decision::CONTINUE) {
        if(!measured.entry_rotation_ready) {
            output_.reason="moving alignment; stop upstream of E if unfinished";
            if(!rotation_fresh){output_.decision=Decision::STOP;output_.speed_limit=0;output_.pause_progress_timeout=true;output_.reason="rotation feedback missing or stale";}
        }
    }
    std_msgs::msg::Bool inhibit;
    // 正常入口制动只停平移，仍允许对准与LOW完成；故障/HOLD/退让仍禁止旋转。
    inhibit.data=output_.state==State::HOLD||output_.decision==Decision::RECOVERY||output_.decision==Decision::FAILURE;
    rotation_inhibit_pub_->publish(inhibit);
    if(output_.decision==Decision::CONTINUE) {
        const auto limits=constraints();
        output_.speed_limit=limits.base_speed;output_.stop_arc=limits.stop_arc;
        if(output_.stop_arc&&output_.speed_limit<config_.stopped_speed)output_.pause_progress_timeout=true;
    }
    if(output_.state!=previous.state||output_.decision!=previous.decision||output_.reason!=previous.reason)
        RCLCPP_INFO(node_->get_logger(),"Hole execution: state=%d decision=%d progress=%.3f limit=%.3f reason=%s",
            static_cast<int>(output_.state),static_cast<int>(output_.decision),output_.progress,output_.speed_limit,output_.reason.c_str());
    publishExecution();return output_;
}
void SlopeHoleRosAdapter::publishExecution() {
    nav_interfaces::msg::HoleTraversalState s;s.header.stamp=node_->now();s.header.frame_id="map";
    s.session_id=session_;s.goal_id=goal_;s.plan_id=core_.plan().id;s.state=static_cast<std::uint8_t>(output_.state);
    s.decision=static_cast<std::uint8_t>(output_.decision);s.s_progress=output_.progress;
    s.speed_limit=output_.speed_limit;s.reason=output_.reason;s.attempt=output_.attempt;s.recovery_phase=retreat_phase_;
    for(const auto& v:core_.visits()){s.traversal_uids.push_back(v.first);s.phases.push_back(static_cast<std::uint8_t>(v.second.phase));s.preparing_required.push_back(v.second.demand);}
    state_pub_->publish(s);
    for(const auto& e:output_.events) {
        nav_interfaces::msg::HoleTraversalEvent m;m.header=s.header;m.session_id=session_;m.goal_id=goal_;m.plan_id=s.plan_id;
        m.attempt=output_.attempt;m.traversal_uid=e.uid;m.sequence=e.sequence;m.type=static_cast<std::uint8_t>(e.type);m.event_arc=e.arc;m.progress=e.progress;
        event_pub_->publish(m);
    }
}
MotionConstraints SlopeHoleRosAdapter::constraints() const {
    MotionConstraints c;c.enabled=enabled();c.allowed=output_.decision==Decision::CONTINUE;
    c.plan_id=core_.plan().id;c.valid_until=updated_+config_.pose_timeout;c.base_speed=output_.speed_limit;
    c.acceleration=config_.acceleration_limit;c.braking=config_.braking_deceleration;c.latency=config_.control_latency;
    c.stop_arc=output_.stop_arc;c.path=core_.plan().path;
    c.regions=core_.plan().speeds;
    Input feedback;feedback.now=node_->now().seconds();feedback.feedback=feedback_;
    if(feedback_.received>=0)feedback.feedback.source_age+=feedback.now-feedback_.received;
    const bool low_ready=core_.lowReady(feedback);
    for(const auto& p:core_.plan().passages) {
        const auto& e=event(p,EventType::E);const auto& d=event(p,EventType::D);
        const auto visit=core_.visits().find(p.uid);
        // 尚未完成LOW和本洞对准时，以E前停车点反推速度上限。
        // A前也预告，避免高速到A才发现已无足够制动距离；就绪后立即撤销。
        const bool entered=visit!=core_.visits().end()&&visit->second.emitted.count(EventType::E);
        const bool ready=low_ready&&core_.entryAuthorized(p.uid)&&core_.entryPositionReady();
        if(!entered&&!ready&&e.range==Range::ON_PATH) {
            double stop=e.arc-config_.entry_margin;
            // E是洞口，不是坡脚。变形必须在车轮到坡前完成。
            for(const auto& slope:core_.plan().slopes)if(slope.begin<e.arc&&
                slope.end>event(p,EventType::A).arc&&slope.begin>event(p,EventType::A).arc)
                stop=std::min(stop,slope.begin-config_.slope_entry_margin);
            if(!c.stop_arc||stop<*c.stop_arc)c.stop_arc=stop;
            // 完成时间只是速度预测；绝不取代LOW和严格对准的真实放行反馈。
            const double remaining=preparation_remaining_>0?preparation_remaining_:
                std::max(config_.prepare_prediction_time,M_PI/4/config_.alignment_prediction_rate+config_.settle_time);
            c.base_speed=std::min(c.base_speed,std::max(0.,stop-output_.progress)/(remaining+config_.control_latency));
        }
        // 提前减速到可移动恢复的速度；重叠需求尚未结束的D不作为恢复边界。
        bool overlapped=false;
        for(const auto& other:core_.plan().passages)if(other.uid!=p.uid&&
            event(other,EventType::A).range!=Range::UNKNOWN&&event(other,EventType::A).arc<=d.arc&&
            event(other,EventType::D).arc>d.arc)overlapped=true;
        // 姿态恢复许可与地形速度策略分离；上下坡采用相同恢复检查。
        if(output_.state!=State::NORMAL&&!overlapped&&visit!=core_.visits().end()&&!visit->second.complete&&
            d.range!=Range::UNKNOWN&&d.arc<=Polyline(core_.plan().path).length())c.regions.push_back({d.arc,Polyline(core_.plan().path).length(),config_.restore_speed,Travel::RESTRICTED});
    }
    c.base_speed=previewLimit(output_.progress,c.base_speed,c.regions,c.braking,c.latency,c.stop_arc);
    return c;
}
bool SlopeHoleRosAdapter::canRecover() const {
    if(!enabled())return true;
    if(core_.occupied())return false;
    for(const auto& p:core_.plan().passages)for(const auto& s:p.straights)
        if(output_.progress>=s.begin&&output_.progress<=s.end)return false;
    return true;
}
bool SlopeHoleRosAdapter::gate(const geometry_msgs::msg::Twist& cmd,bool recovery,bool takeover) const {
    if(!enabled()||std::hypot(cmd.linear.x,cmd.linear.y)<epsilon)return true;
    if(recovery&&retreat_phase_==3) {
        const double yaw=std::atan2(retreat_direction_.y,retreat_direction_.x);
        // 指令在fake中，由updateRetreat按当前yaw生成；除专用退让外仍拒绝普通恢复。
        (void)yaw;return node_->now().seconds()-updated_<=config_.pose_timeout&&std::hypot(cmd.linear.x,cmd.linear.y)<=config_.retreat_speed+1e-6;
    }
    if(recovery)return canRecover()&&std::hypot(cmd.linear.x,cmd.linear.y)<=config_.flat_speed;
    return updated_>=0&&node_->now().seconds()-updated_<=config_.pose_timeout&&output_.decision==Decision::CONTINUE&&
        std::hypot(cmd.linear.x,cmd.linear.y)<=(takeover&&takeover_authorized_?config_.boost_speed:output_.speed_limit)+1e-6;
}
void SlopeHoleRosAdapter::invalidate(const std::string& reason){if(core_.plan().status!=PlanStatus::ACTIVE)return;core_.invalidate(reason);updated_=-1;publishPlan();}
void SlopeHoleRosAdapter::closeGoal(PlanStatus status) {
    if(!enabled())return;core_.closeGoal(status);updated_=-1;publishPlan();
    // 请求显式停止变形/保持形态；不把取消解释为抬高，也不继续发送旧 LOW 请求。
    nav_interfaces::msg::HoleStructureRequest m;m.header.stamp=node_->now();m.session_id=session_;m.goal_id=goal_;
    m.target=static_cast<std::uint8_t>(Posture::KEEP);m.cancel_motion=true;request_pub_->publish(m);
    std_msgs::msg::Bool inhibit;inhibit.data=status!=PlanStatus::COMPLETED||core_.occupied();rotation_inhibit_pub_->publish(inhibit);
}
void SlopeHoleRosAdapter::motionFailed(){core_.reportMotionFailure(node_->now().seconds());updated_=-1;}
void SlopeHoleRosAdapter::pathBlocked(){core_.reportPathFailure(node_->now().seconds());updated_=-1;}
void SlopeHoleRosAdapter::blockCurrentHole(SimplePlanner& planner) {
    if(++replans_>config_.max_replans)throw std::runtime_error("terrain replan budget exhausted");
    if(!output_.blocked_hole.empty())blocked_[output_.blocked_hole]=node_->now().seconds()+config_.blocked_ttl;
    applyBlocks(planner);invalidate("blocked hole; replan same final goal");
}
void SlopeHoleRosAdapter::applyBlocks(SimplePlanner& planner) {
    std::set<std::string> ids;
    for(auto it=blocked_.begin();it!=blocked_.end();)if(it->second<=node_->now().seconds())it=blocked_.erase(it);else {ids.insert(it->first);++it;}
    planner.setBlockedHoleIds(ids);
}
void SlopeHoleRosAdapter::publishPlan() {
    const auto& p=core_.plan();if(!p.id)return;
    nav_interfaces::msg::NavigationPlan m;m.header.stamp=node_->now();m.header.frame_id=p.frame;
    m.session_id=p.session;m.goal_id=p.goal;m.plan_id=p.id;
    m.status=static_cast<std::uint8_t>(p.status);
    m.reason=p.reason;m.constraints_enabled=p.constraints_enabled;m.terrain_revision=p.terrain_revision;
    m.parameter_revision=p.parameter_revision;m.map_revision=p.map_revision;m.path.header=m.header;
    for(auto q:p.path){geometry_msgs::msg::PoseStamped v;v.header=m.header;v.pose.position.x=q.x;v.pose.position.y=q.y;v.pose.orientation.w=1;m.path.poses.push_back(v);}
    m.path_length=Polyline(p.path).length();
    for(const auto& v:p.passages) {
        nav_interfaces::msg::HoleTraversal t;t.traversal_uid=v.uid;t.hole_id=v.hole_id;t.entry_edge_id=v.entry_edge;t.exit_edge_id=v.exit_edge;
        t.uphill_entry=v.uphill_entry;t.centerline=v.centerline;t.validated=v.validated;t.requirement_revision=v.requirement_revision;
        for(std::size_t j=0;j<6;++j){const auto& e=v.events[j];auto& z=t.events[j];z.type=static_cast<std::uint8_t>(e.type);
            z.range_status=static_cast<std::uint8_t>(e.range);z.s_path=e.arc;z.point_valid=e.point_valid;z.point.x=e.point.x;z.point.y=e.point.y;}
        for(const auto& line:v.straights){nav_interfaces::msg::HoleStraight s;s.s_begin=line.begin;s.s_end=line.end;
            s.direction.x=line.direction.x;s.direction.y=line.direction.y;s.remaining=line.remaining;t.straight_segments.push_back(s);}
        m.passages.push_back(t);
    }
    for(const auto& v:p.speeds){nav_interfaces::msg::HoleSpeedRegion s;s.s_begin=v.begin;s.s_end=v.end;s.speed_limit=v.limit;s.kind=static_cast<std::uint8_t>(v.kind);m.speed_regions.push_back(s);}
    plan_pub_->publish(m);
}
void SlopeHoleRosAdapter::prepareRetreat(const geometry_msgs::msg::PoseStamped& pose,const std::function<bool(double,double)>& valid) {
    if(retreat_phase_||output_.state!=State::HOLD||!core_.lowReady(input(pose,0)))return;
    if(output_.reason!="traverse no progress"&&output_.reason!="traverse deadline"&&
       output_.reason!="path blocked"&&output_.reason!="motion blocked/controller unavailable"&&
       output_.reason!="tunnel residence timeout"&&output_.reason!="minimum speed takeover ineffective")return;
    for(const auto& p:core_.plan().passages) {
        auto it=core_.visits().find(p.uid);
        if(it==core_.visits().end()||!it->second.demand||!p.uphill_entry||!p.retreat_anchor_valid)continue;
        if(traversal_retries_[p.uid]>=config_.max_traversal_retries)continue;
        const Point here{pose.pose.position.x,pose.pose.position.y};const auto delta=here-p.retreat_anchor;
        if(holeDot(delta,p.entry_direction)<0||std::abs(holeCross(delta,p.entry_direction))>config_.max_lateral_error)continue;
        if(!valid(p.retreat_anchor.x,p.retreat_anchor.y))continue;
        const auto s=event(p,EventType::S);if(s.arc<0)continue; // 不猜测已剪掉且不能校验的重入路径。
        retreat_target_=p.retreat_anchor;retreat_direction_=p.entry_direction;retreat_arc_=s.arc;retreat_uid_=p.uid;
        retreat_phase_=1;retreat_started_=node_->now().seconds();retreat_progress_time_=retreat_started_;retreat_best_=holeNorm(delta);retreat_stable_=-1;return;
    }
}
int SlopeHoleRosAdapter::updateRetreat(const geometry_msgs::msg::PoseStamped& pose,double speed,const std::function<bool(double,double)>& valid,geometry_msgs::msg::Twist& cmd) {
    cmd=geometry_msgs::msg::Twist();updated_=node_->now().seconds();auto in=input(pose,speed);
    const auto fail=[&](const std::string& why){output_.reason=why;retreat_phase_=0;publishExecution();return -1;};
    if(!in.pose_valid||!core_.lowReady(in))return fail("retreat pose/low feedback invalid");
    if(updated_-retreat_started_>config_.retreat_timeout)return fail("retreat total timeout");
    const Point here{pose.pose.position.x,pose.pose.position.y};const auto delta=here-retreat_target_;
    const double remaining=holeDot(delta,retreat_direction_);
    if(std::abs(holeCross(delta,retreat_direction_))>config_.max_lateral_error)return fail("retreat left fixed corridor");
    if(retreat_phase_==1) {
        if(speed<config_.stopped_speed){if(retreat_stable_<0)retreat_stable_=updated_;if(updated_-retreat_stable_>=config_.settle_time){retreat_phase_=2;retreat_stable_=-1;}}
        else retreat_stable_=-1;
    } else if(retreat_phase_==2) {
        if(!valid(retreat_target_.x,retreat_target_.y))return fail("retreat collision validation failed");
        retreat_phase_=3;retreat_progress_time_=updated_;retreat_best_=remaining;
    } else if(retreat_phase_==3) {
        if(!valid(retreat_target_.x,retreat_target_.y))return fail("retreat route blocked");
        if(remaining<-.04)return fail("retreat overshot S");
        if(retreat_best_-remaining>=config_.stall_progress){retreat_best_=remaining;retreat_progress_time_=updated_;}
        // 采用北理式总退出期限；不再由2.5s普通无进展计时提前截断。
        if(remaining<=.03){retreat_phase_=4;retreat_stable_=-1;}
        else {
            const double v=std::min(config_.retreat_speed,std::sqrt(2*config_.braking_deceleration*std::max(0.,remaining-.015)));
            // Original fake is parallel to odom/map; no chassis rotation here.
            cmd.linear.x=-v*retreat_direction_.x;cmd.linear.y=-v*retreat_direction_.y;
        }
    } else if(retreat_phase_==4) {
        if(speed<config_.stopped_speed){if(retreat_stable_<0)retreat_stable_=updated_;if(updated_-retreat_stable_>=config_.settle_time)retreat_phase_=5;}
        else retreat_stable_=-1;
    } else if(retreat_phase_==5) {
        if(remaining<-.04||remaining>.05||!valid(retreat_target_.x,retreat_target_.y))return fail("S reentry validation failed");
        ++traversal_retries_[retreat_uid_];speed_takeover_.reset();takeover_authorized_=false;core_.completeRetreat(retreat_arc_,in);alignment_stable_=-1;retreat_phase_=0;output_=Output{};publishExecution();return 1;
    }
    output_.reason="slopehole dedicated retreat";output_.speed_limit=config_.retreat_speed;publishExecution();return 0;
}

// 仅在普通控制器健康时评估补速。候选仍须单独检查并经过统一发布入口。
bool SlopeHoleRosAdapter::applyMinimumSpeed(const geometry_msgs::msg::PoseStamped& pose,
    geometry_msgs::msg::Twist& cmd,bool healthy,double total_limit,
    const std::function<bool(double,double)>& valid,bool& takeover) {
    takeover=false;takeover_authorized_=false;
    const double now=node_->now().seconds();
    auto cancel=[&](){speed_takeover_.reset();return true;};
    if(!enabled()||!healthy||output_.decision!=Decision::CONTINUE||output_.state!=State::TRAVERSE||
       retreat_phase_||!core_.entryAuthorized(aligning_uid_)||
       !core_.lowReady(input(pose,measuredSpeed()))||!std::isfinite(measuredSpeed()))return cancel();
    const auto& plan=core_.plan();Polyline path(plan.path);
    const auto projected=path.project({pose.pose.position.x,pose.pose.position.y},
        std::max(0.,output_.progress-config_.backward_window),std::min(path.length(),output_.progress+config_.forward_window));
    if(projected.lateral>config_.max_lateral_error)return cancel();
    const SlopeSection* slope=nullptr;
    // 前轮早于定位参考点触坡；准备许可有效后在坡脚上游开始爬升指令。
    for(const auto& section:plan.slopes)if(section.uphill&&projected.arc>=std::max(0.,section.begin-config_.slope_entry_margin)&&
        projected.arc<section.end){slope=&section;break;}
    if(!slope)return cancel();
    const bool entry=slope->entry_complete&&projected.arc<slope->begin+config_.entry_zone_length;
    const double minimum=entry?config_.minimum_entry_speed:config_.minimum_slope_speed;
    if(config_.boost_speed>total_limit)return cancel();
    const double a=std::max(0.,projected.arc-0.005),b=std::min(slope->end,projected.arc+0.005);
    const Point delta=path.at(b)-path.at(a);if(holeNorm(delta)<epsilon)return cancel();
    const Point direction=delta*(1./holeNorm(delta));
    double yaw=0;
    try {yaw=tf2::getYaw(chassis_tf_->lookupTransform("map","odom",tf2::TimePointZero).transform.rotation);}
    catch(const tf2::TransformException&){return cancel();}
    const Point measured_map{std::cos(yaw)*velocity_odom_.x-std::sin(yaw)*velocity_odom_.y,
                             std::sin(yaw)*velocity_odom_.x+std::cos(yaw)*velocity_odom_.y};
    const Point normal_map{std::cos(yaw)*cmd.linear.x-std::sin(yaw)*cmd.linear.y,
                           std::sin(yaw)*cmd.linear.x+std::cos(yaw)*cmd.linear.y};
    const auto result=speed_takeover_.update(config_,goal_+":"+slope->id+":"+std::to_string(output_.attempt),now,
        holeDot(measured_map,direction),holeDot(normal_map,direction),minimum,true);
    if(result.failed) {
        core_.reportBoostFailure(now);output_=core_.update(input(pose,measuredSpeed()));publishExecution();
        RCLCPP_WARN(node_->get_logger(),"minimum speed takeover ineffective -> HOLD -> dedicated RECOVERY");return false;
    }
    if(!result.active)return true;
    // 短终点/后续弯道按可用距离限制本次候选，不能因2m/s放不下就彻底取消驱动。
    // 使用路径投影点比较几何，车体数厘米横差不应误判成路径拐弯。
    double straight_end=projected.arc;
    for(std::size_t i=0;i<path.points.size();++i)if(path.arcs[i]>projected.arc) {
        const Point offset=path.points[i]-projected.point;
        if(std::abs(holeCross(direction,offset))>.03||holeDot(direction,offset)<0)break;
        straight_end=path.arcs[i];
    }
    // 后续洞口也有准备停车边界：只约束可用距离，不能取消当前上坡控制权。
    if(output_.stop_arc)straight_end=std::min(straight_end,*output_.stop_arc);
    const double speed=previewLimit(projected.arc,std::min(config_.boost_speed,result.speed),{},
        config_.braking_deceleration,config_.control_latency,straight_end);
    if(speed<.01)return cancel();
    const double distance=speed*config_.control_latency+speed*speed/(2*config_.braking_deceleration);
    const Point here{pose.pose.position.x,pose.pose.position.y};
    Point v=direction*speed+(projected.point-here)*2.;
    if(holeNorm(v)>speed)v=v*(speed/holeNorm(v));
    const Point end=here+v*(distance/std::max(holeNorm(v),epsilon));
    if(!valid(end.x,end.y))return cancel();
    cmd.linear.x=std::cos(yaw)*v.x+std::sin(yaw)*v.y;
    cmd.linear.y=-std::sin(yaw)*v.x+std::cos(yaw)*v.y;
    takeover=takeover_authorized_=true;
    RCLCPP_INFO_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
        "uphill speed ownership: phase=%s forward=%.3f minimum=%.3f target=%.3f command=%.3f",
        entry?"ENTRY":"SLOPE",holeDot(measured_map,direction),minimum,config_.boost_speed,holeNorm(v));
    return true;
}

}
