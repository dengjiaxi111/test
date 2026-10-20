from pathlib import Path
r=Path(__file__).resolve().parents[1]/'src/my_navigation'
p=r/'nav_components/include/nav_components/slopehole_ros_adapter.hpp';s=p.read_text()
s=s.replace('#include <geometry_msgs/msg/twist.hpp>','#include <geometry_msgs/msg/twist.hpp>\n#include <std_msgs/msg/float64.hpp>\n#include <functional>')
s=s.replace('    bool canRecover() const;','''    bool canRecover() const;
    void recordCommand(double speed){last_command_speed_=speed;}
    bool specialRecovery() const {return retreat_phase_!=0;}
    void prepareRetreat(const geometry_msgs::msg::PoseStamped&,const std::function<bool(double,double)>&);
    int updateRetreat(const geometry_msgs::msg::PoseStamped&,double,const std::function<bool(double,double)>&,geometry_msgs::msg::Twist&);
    void publishExecution();''')
s=s.replace('    std::string session_,goal_;','''    std::string session_,goal_;
    double last_command_speed_=0,retreat_started_=0,retreat_progress_time_=0,retreat_best_=0,retreat_stable_=-1,retreat_arc_=0;
    int retreat_phase_=0;
    nav_core::hole_exec::Point retreat_target_,retreat_direction_;
    std::string retreat_uid_;
    std::map<std::string,int> traversal_retries_;
    std::map<std::string,double> alignment_targets_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr alignment_pub_;''')
p.write_text(s)
p=r/'nav_components/src/slopehole_ros_adapter.cpp';s=p.read_text()
s=s.replace('#include <random>','#include <random>\n#include <tf2/utils.h>\n#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>')
s=s.replace('steadySeconds()', 'node_->now().seconds()')
# remove invalid renamed free helper; all business clocks use ROS time in isolated sim.
s=s.replace('static double node_->now().seconds(){return std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();}\n','')
s=s.replace('    plan_pub_=', '    alignment_pub_=n->create_publisher<std_msgs::msg::Float64>("hole_alignment_target",10);\n    plan_pub_=',1)
s=s.replace('m->status>2','m->status>3')
s=s.replace('{m->cleared_traversal_uids.begin(),m->cleared_traversal_uids.end()}};', '{m->cleared_traversal_uids.begin(),m->cleared_traversal_uids.end()},m->action_stopped,m->retry_allowed,m->fault_code};')
s=s.replace('goal_=std::to_string(++goal_sequence_);', 'goal_=std::to_string(++goal_sequence_);alignment_targets_.clear();traversal_retries_.clear();retreat_phase_=0;')
s=s.replace('in.measured_speed=speed;', 'in.measured_speed=speed;in.chassis_yaw=tf2::getYaw(p.pose.orientation);in.command_requested=last_command_speed_>0.05;in.recovery_authorized=retreat_phase_!=0;in.recovery_action_verified=retreat_phase_!=0;')
s=s.replace('    if(output_.request) {','''    if(output_.cancel_request) {
        nav_interfaces::msg::HoleStructureRequest cancel;cancel.header.stamp=node_->now();cancel.session_id=session_;cancel.goal_id=goal_;
        cancel.target=0;cancel.cancel_motion=true;request_pub_->publish(cancel);
    }
    if(output_.request) {''')
start='    nav_interfaces::msg::HoleTraversalState s;s.header.stamp=node_->now();'
pos=s.index(start)
s=s[:pos]+'''    // 四面对准目标每次通行只选一次。目标轴来自真实通道，不来自云台yaw。
    std_msgs::msg::Float64 heading;heading.data=std::numeric_limits<double>::quiet_NaN();
    for(const auto& p:core_.plan().passages) {
        const auto& begin=event(p,EventType::S);const auto& end=event(p,EventType::D);
        if(end.arc<output_.progress||begin.arc-output_.progress>1.5)continue;
        auto it=alignment_targets_.find(p.uid);
        if(it==alignment_targets_.end()) {
            const double yaw=tf2::getYaw(pose.pose.orientation),axis=std::atan2(p.entry_direction.y,p.entry_direction.x);
            double best=axis,err=10;
            for(int k=0;k<4;++k){double candidate=axis+k*M_PI/2,d=std::abs(std::remainder(candidate-yaw,2*M_PI));if(d<err){err=d;best=candidate;}}
            it=alignment_targets_.emplace(p.uid,best).first;
        }
        heading.data=it->second;
        if(output_.decision==Decision::CONTINUE&&std::abs(std::remainder(heading.data-tf2::getYaw(pose.pose.orientation),2*M_PI))>config_.alignment_tolerance) {
            output_.decision=Decision::STOP;output_.speed_limit=0;output_.pause_progress_timeout=true;output_.reason="aligning chassis to selected face";
        }
        break;
    }
    alignment_pub_->publish(heading);
    publishExecution();return output_;
}
void SlopeHoleRosAdapter::publishExecution() {
'''+s[pos:]
s=s.replace('s.speed_limit=output_.speed_limit;s.reason=output_.reason;', 's.speed_limit=output_.speed_limit;s.reason=output_.reason;s.attempt=output_.attempt;s.recovery_phase=retreat_phase_;')
s=s.replace('m.traversal_uid=e.uid;', 'm.attempt=output_.attempt;m.traversal_uid=e.uid;')
s=s.replace('    return output_;\n}\nMotionConstraints', '}\nMotionConstraints')
s=s.replace('    if(!enabled()||std::hypot(cmd.linear.x,cmd.linear.y)<epsilon)return true;', '''    if(!enabled()||std::hypot(cmd.linear.x,cmd.linear.y)<epsilon)return true;
    if(recovery&&retreat_phase_==3) {
        const double yaw=std::atan2(retreat_direction_.y,retreat_direction_.x);
        // 指令在fake中，由updateRetreat按当前yaw生成；除专用退让外仍拒绝普通恢复。
        (void)yaw;return node_->now().seconds()-updated_<=config_.pose_timeout&&std::hypot(cmd.linear.x,cmd.linear.y)<=config_.retreat_speed+1e-6;
    }''')
s=s.replace('t.centerline=v.centerline;', 't.uphill_entry=v.uphill_entry;t.centerline=v.centerline;')
insert='''
void SlopeHoleRosAdapter::prepareRetreat(const geometry_msgs::msg::PoseStamped& pose,const std::function<bool(double,double)>& valid) {
    if(retreat_phase_||output_.state!=State::HOLD||!core_.lowReady(input(pose,0)))return;
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
    cmd={};updated_=node_->now().seconds();auto in=input(pose,speed);
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
            const double yaw=tf2::getYaw(pose.pose.orientation),wx=-v*retreat_direction_.x,wy=-v*retreat_direction_.y;
            cmd.linear.x=std::cos(yaw)*wx+std::sin(yaw)*wy;cmd.linear.y=-std::sin(yaw)*wx+std::cos(yaw)*wy;
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
'''
pos=s.rfind('\n}');s=s[:pos]+insert+s[pos:];p.write_text(s)
print('adapter and dedicated recovery applied')
