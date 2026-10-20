#include "nav_components/slopehole_ros_adapter.hpp"
#include <chrono>
#include <random>
#include <tf2/utils.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
namespace nav_components {
using namespace nav_core::hole_exec;
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
            if(m->header.frame_id!="odom"||!std::isfinite(stamp)||stamp<=rotation_stamp_||now<stamp||
                now-stamp>config_.feedback_timeout||m->name.size()!=2||m->velocity.size()!=2||
                m->name[0]!="chassis_world_yaw"||m->name[1]!="gimbal_world_yaw"||
                !std::isfinite(m->velocity[0])||!std::isfinite(m->velocity[1]))return;
            rotation_stamp_=stamp;rotation_received_=now;chassis_rate_=m->velocity[0];gimbal_rate_=m->velocity[1];
        });
    speed_sub_=n->create_subscription<nav_msgs::msg::Odometry>("/Odometry/fake",rclcpp::SensorDataQoS(),
        [this](nav_msgs::msg::Odometry::ConstSharedPtr m){
            if(m->header.frame_id!="odom"||m->child_frame_id!="base_link_fake")return;
            measured_speed_=std::hypot(m->twist.twist.linear.x,m->twist.twist.linear.y);
            speed_received_=node_->now().seconds();speed_stamp_=rclcpp::Time(m->header.stamp).seconds();
        });
    session_=std::to_string(std::random_device{}())+"-"+std::to_string(node_->now().seconds());
    alignment_pub_=n->create_publisher<std_msgs::msg::Float64>("hole_alignment_target",10);
    plan_pub_=n->create_publisher<nav_interfaces::msg::NavigationPlan>("navigation_plan",rclcpp::QoS(1).reliable().transient_local());
    request_pub_=n->create_publisher<nav_interfaces::msg::HoleStructureRequest>("hole_structure/request",10);
    state_pub_=n->create_publisher<nav_interfaces::msg::HoleTraversalState>("hole_traversal_state",10);
    event_pub_=n->create_publisher<nav_interfaces::msg::HoleTraversalEvent>("hole_traversal_event",10);
    feedback_sub_=n->create_subscription<nav_interfaces::msg::HoleStructureFeedback>("hole_structure/feedback",10,
        [this](nav_interfaces::msg::HoleStructureFeedback::ConstSharedPtr m){
            const double age=(node_->now()-rclcpp::Time(m->header.stamp)).seconds();
            if(age<0||age>config_.feedback_timeout||m->target>2||m->status>3||
               (m->simulated!=config_.simulation_only))return;
            feedback_={m->session_id,m->goal_id,m->request_id,m->requirement_revision,node_->now().seconds(),age,
                static_cast<Posture>(m->target),static_cast<ActionStatus>(m->status),m->whole_vehicle_clear,
                m->normal_clearance,m->moving_transition_supported,{m->cleared_traversal_uids.begin(),m->cleared_traversal_uids.end()},m->action_stopped,m->retry_allowed,m->fault_code};
        });
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
    goal_=std::to_string(++goal_sequence_);alignment_targets_.clear();aligned_passages_.clear();aligning_uid_.clear();alignment_stable_=-1;traversal_retries_.clear();retreat_phase_=0;blocked_.clear();replans_=0;updated_=-1;return true;
}
Input SlopeHoleRosAdapter::input(const geometry_msgs::msg::PoseStamped& p,double speed) const {
    Input in;in.now=node_->now().seconds();
    const double age=(node_->now()-rclcpp::Time(p.header.stamp)).seconds();
    in.pose_received=in.now-age;in.position={p.pose.position.x,p.pose.position.y};
    in.pose_valid=p.header.frame_id=="map"&&age>=0&&age<=config_.pose_timeout;
    in.measured_speed=speed;
    try {
        const auto t=chassis_tf_->lookupTransform("map","chassiss",tf2::TimePointZero);
        const double chassis_age=(node_->now()-rclcpp::Time(t.header.stamp)).seconds();
        if(chassis_age<0||chassis_age>config_.pose_timeout)in.pose_valid=false;
        in.chassis_yaw=tf2::getYaw(t.transform.rotation);
    }catch(const tf2::TransformException&){in.pose_valid=false;}
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
        auto in=input(pose,0);
        if(!core_.acceptPlan(next,in,error))return false;
        output_=Output{};updated_=-1;publishPlan();return true;
    }catch(const std::exception& e){error=e.what();core_.invalidate(error);return false;}
}
Output SlopeHoleRosAdapter::tick(const geometry_msgs::msg::PoseStamped& pose,double speed) {
    if(!enabled()){Output out;out.decision=Decision::CONTINUE;out.speed_limit=std::numeric_limits<double>::infinity();return out;}
    const auto previous_state=output_.state;
    auto measured=input(pose,speed);
    // 先用实测反馈计算许可，再推进E事件，不能在事件触发后才补检查。
    std_msgs::msg::Float64 heading;heading.data=std::numeric_limits<double>::quiet_NaN();
    bool alignment_needed=false,rotation_fresh=false,orientation_good=false;
    for(const auto& p:core_.plan().passages) {
        const auto visit=core_.visits().find(p.uid);
        if(visit!=core_.visits().end()&&visit->second.complete)continue;
        const auto& begin=event(p,EventType::S);
        if(begin.arc-output_.progress>1.5)continue;
        alignment_needed=true;
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
        rotation_fresh=rotation_received_>=0&&now>=rotation_stamp_&&now>=rotation_received_&&
            now-rotation_stamp_<=config_.feedback_timeout&&now-rotation_received_<=config_.feedback_timeout;
        orientation_good=measured.pose_valid&&
            std::abs(std::remainder(heading.data-measured.chassis_yaw,2*M_PI))<=config_.alignment_tolerance;
        const bool settled=orientation_good&&rotation_fresh&&
            std::abs(chassis_rate_)<config_.rotation_stopped_rate&&std::abs(gimbal_rate_)<config_.rotation_stopped_rate;
        if(!settled)alignment_stable_=-1;
        else if(alignment_stable_<0)alignment_stable_=now;
        measured.entry_rotation_ready=settled&&now-alignment_stable_>=config_.settle_time;
        if(measured.entry_rotation_ready)aligned_passages_.insert(p.uid);
        break;
    }
    if(!alignment_needed){aligning_uid_.clear();alignment_stable_=-1;}
    alignment_pub_->publish(heading);
    updated_=node_->now().seconds();output_=core_.update(measured);continuation_verified_=false;
    if(output_.state==State::HOLD&&previous_state==State::RESTORE) {
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
        m.header.stamp=node_->now();m.header.frame_id="map";m.session_id=q.session;m.goal_id=q.goal;
        m.request_id=q.id;m.requirement_revision=q.revision;m.target=static_cast<std::uint8_t>(q.target);
        m.traversal_uids=q.traversal_uids;request_pub_->publish(m);
    }
    // 首次必须完成对准和停转。随后小幅角速度波动由E上游停车边界处理，
    // 不在每次加速瞬间直接清零平移；越过E仍检查本周期真实许可。
    if(alignment_needed&&!measured.entry_rotation_ready&&output_.decision==Decision::CONTINUE&&
        (!aligned_passages_.count(aligning_uid_)||!rotation_fresh||!orientation_good)) {
        output_.decision=Decision::STOP;output_.speed_limit=0;output_.pause_progress_timeout=true;
        output_.reason=rotation_fresh?"waiting for chassis alignment and measured rotation stop":"rotation feedback missing or stale";
    }
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
    for(auto region:core_.plan().speeds) {
        if(region.kind==Travel::CREST) {
            if(output_.progress<region.begin||output_.progress>region.end)continue;
            region.begin=output_.progress;region.limit=output_.speed_limit;region.kind=Travel::RESTRICTED;
        }
        c.regions.push_back(region);
    }
    for(const auto& p:core_.plan().passages) {
        const auto& a=event(p,EventType::A);const auto& e=event(p,EventType::E);const auto& d=event(p,EventType::D);
        // NORMAL就提前预告A附近的准备限速，避免到A才瞬间降低硬上限。
        if(output_.state==State::NORMAL&&a.range==Range::ON_PATH&&e.range!=Range::UNKNOWN&&a.arc>=output_.progress)
            c.regions.push_back({a.arc,e.arc,config_.prepare_speed,Travel::RESTRICTED});
        // 提前减速到可移动恢复的速度；重叠需求尚未结束的D不作为恢复边界。
        bool overlapped=false;
        for(const auto& other:core_.plan().passages)if(other.uid!=p.uid&&
            event(other,EventType::A).range!=Range::UNKNOWN&&event(other,EventType::A).arc<=d.arc&&
            event(other,EventType::D).arc>d.arc)overlapped=true;
        auto visit=core_.visits().find(p.uid);
        // 上坡遵守用户策略：到坡顶后才减速，不能为D点恢复而在坡前限速。
        if(!p.uphill_entry&&output_.state!=State::NORMAL&&!overlapped&&visit!=core_.visits().end()&&!visit->second.complete&&
            d.range!=Range::UNKNOWN&&d.arc<=Polyline(core_.plan().path).length())c.regions.push_back({d.arc,Polyline(core_.plan().path).length(),config_.restore_speed,Travel::RESTRICTED});
    }
    return c;
}
bool SlopeHoleRosAdapter::canRecover() const {
    if(!enabled())return true;
    if(core_.occupied())return false;
    for(const auto& p:core_.plan().passages)for(const auto& s:p.straights)
        if(output_.progress>=s.begin&&output_.progress<=s.end)return false;
    return true;
}
bool SlopeHoleRosAdapter::gate(const geometry_msgs::msg::Twist& cmd,bool recovery) const {
    if(!enabled()||std::hypot(cmd.linear.x,cmd.linear.y)<epsilon)return true;
    if(recovery&&retreat_phase_==3) {
        const double yaw=std::atan2(retreat_direction_.y,retreat_direction_.x);
        // 指令在fake中，由updateRetreat按当前yaw生成；除专用退让外仍拒绝普通恢复。
        (void)yaw;return node_->now().seconds()-updated_<=config_.pose_timeout&&std::hypot(cmd.linear.x,cmd.linear.y)<=config_.retreat_speed+1e-6;
    }
    if(recovery)return canRecover()&&std::hypot(cmd.linear.x,cmd.linear.y)<=config_.flat_speed;
    return updated_>=0&&node_->now().seconds()-updated_<=config_.pose_timeout&&output_.decision==Decision::CONTINUE&&
        std::hypot(cmd.linear.x,cmd.linear.y)<=output_.speed_limit+1e-6;
}
void SlopeHoleRosAdapter::invalidate(const std::string& reason){if(core_.plan().status!=PlanStatus::ACTIVE)return;core_.invalidate(reason);updated_=-1;publishPlan();}
void SlopeHoleRosAdapter::closeGoal(PlanStatus status) {
    if(!enabled())return;core_.closeGoal(status);updated_=-1;publishPlan();
    // 请求显式停止变形/保持形态；不把取消解释为抬高，也不继续发送旧 LOW 请求。
    nav_interfaces::msg::HoleStructureRequest m;m.header.stamp=node_->now();m.session_id=session_;m.goal_id=goal_;
    m.target=static_cast<std::uint8_t>(Posture::KEEP);m.cancel_motion=true;request_pub_->publish(m);
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
       output_.reason!="path blocked"&&output_.reason!="motion blocked/controller unavailable")return;
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
        if(updated_-retreat_progress_time_>config_.stall_timeout)return fail("retreat no progress");
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
        ++traversal_retries_[retreat_uid_];core_.completeRetreat(retreat_arc_,in);retreat_phase_=0;output_=Output{};publishExecution();return 1;
    }
    output_.reason="slopehole dedicated retreat";output_.speed_limit=config_.retreat_speed;publishExecution();return 0;
}

}
