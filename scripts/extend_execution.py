from pathlib import Path
R=Path(__file__).resolve().parents[1]/'src/my_navigation'
p=R/'nav_core/include/nav_core/hole_execution_types.hpp';s=p.read_text()
s=s.replace('enum class ActionStatus { EXECUTING, COMPLETED, FAILED };','enum class ActionStatus { EXECUTING, COMPLETED, FAILED, CANCELLED };')
s=s.replace('bool centerline=true,validated=false;','bool centerline=true,validated=false,uphill_entry=false;\n    Point retreat_anchor,entry_direction; bool retreat_anchor_valid=false;')
s=s.replace('std::set<std::string> cleared_traversals;','std::set<std::string> cleared_traversals;\n    bool action_stopped=false,retry_allowed=false; std::uint16_t fault_code=0;')
s=s.replace('StructureFeedback feedback;\n};','StructureFeedback feedback;\n    bool command_requested=false; double chassis_yaw=0;\n};')
s=s.replace('bool pause_progress_timeout=false,allow_recovery=false;','bool pause_progress_timeout=false,allow_recovery=false,cancel_request=false;\n    std::uint32_t attempt=0;')
s=s.replace(' X(blocked_ttl,30.0,', ''' X(ack_timeout,1.0,"机构接收确认最大等待","s") \\
 X(stop_ack_timeout,2.0,"旧动作停止确认最大等待","s") \\
 X(stall_timeout,2.5,"有前进指令时无路径进展期限","s") \\
 X(stall_progress,0.05,"有效路径进展阈值","m") \\
 X(retreat_speed,0.15,"上坡失败后向下退让上限","m/s") \\
 X(retreat_timeout,12.0,"单次退让期限","s") \\
 X(stopped_speed,0.03,"停稳速度阈值","m/s") \\
 X(settle_time,0.20,"停稳连续确认时间","s") \\
 X(alignment_tolerance,0.05,"底盘四面对准误差","rad") \\
 X(blocked_ttl,30.0,''')
s=s.replace('int max_replans=2;','int max_replans=2,max_action_retries=2,max_traversal_retries=2;')
p.write_text(s)
p=R/'nav_components/src/hole_execution_config.cpp';s=p.read_text().replace('"max_replans"})','"max_replans","max_action_retries","max_traversal_retries"})')
s=s.replace('for(auto item:n)', 'if(n["max_action_retries"])c.max_action_retries=n["max_action_retries"].as<int>();\n    if(n["max_traversal_retries"])c.max_traversal_retries=n["max_traversal_retries"].as<int>();\n    for(auto item:n)');p.write_text(s)
p=R/'nav_components/include/nav_components/slopehole_controller.hpp';s=p.read_text()
s=s.replace('void reportPathFailure(double now);','void reportPathFailure(double now);\n    void completeRetreat(double arc,const Input& input);\n    bool lowReady(const Input& input) const {return matching(input,nav_core::hole_exec::Posture::LOW);}')
s=s.replace('std::string reason_=', '''double attempt_started_=-1,progress_started_=-1,progress_anchor_=0,cancel_started_=-1,stop_stable_since_=-1;
    bool cancelling_=false,emergency_=false;
    std::map<nav_core::hole_exec::Posture,int> action_retries_;
    std::vector<nav_core::hole_exec::FiredEvent> event_history_;
    std::uint32_t attempt_=0;
    std::string reason_=''')
p.write_text(s)
p=R/'nav_components/src/slopehole_controller.cpp';s=p.read_text()
s=s.replace('if(!same){visits_.clear();request_.reset();had_low_=false;state_=State::NORMAL;}', 'if(!same){visits_.clear();request_.reset();had_low_=false;state_=State::NORMAL;action_retries_.clear();attempt_=0;attempt_started_=-1;progress_started_=-1;cancelling_=false;emergency_=false;event_history_.clear();}')
s=s.replace('v.emitted.insert(item.type);out.events.push_back({item.uid,item.type,item.s,progress_,++next_event_});','v.emitted.insert(item.type);out.events.push_back({item.uid,item.type,item.s,progress_,++next_event_});event_history_.push_back(out.events.back());')
s=s.replace('Output out;out.state=state_;out.progress=progress_;','Output out;out.state=state_;out.progress=progress_;out.attempt=attempt_;')
s=s.replace('if(feedback_fresh&&in.feedback.status==ActionStatus::FAILED)hold(in.now,"structure action failed");','if(feedback_fresh&&in.feedback.status==ActionStatus::FAILED) {hold(in.now,"structure action failed");if(!cancelling_){cancelling_=true;cancel_started_=in.now;}}')
s=s.replace('if(!updateProgress(in,invalid)){hold(in.now,invalid);out.pause_progress_timeout=true;return done();}', 'if(!updateProgress(in,invalid)){hold(in.now,invalid);out.pause_progress_timeout=true;if(in.now-state_started_>=config_.hold_timeout)out.decision=Decision::FAILURE;return done();}')
s=s.replace('if(state_==State::HOLD) {\n        out.pause_progress_timeout=true;', '''if(state_==State::HOLD) {
        out.pause_progress_timeout=true;
        if(cancelling_) {
            out.cancel_request=true;
            if(feedback_fresh && in.feedback.action_stopped && in.feedback.retry_allowed && request_) {
                auto target=request_->target;
                if(action_retries_[target]>=config_.max_action_retries) {out.decision=Decision::FAILURE;out.reason="structure retry budget exhausted";return done();}
                ++action_retries_[target];request_.reset();cancelling_=false;
                transition(target==Posture::LOW?State::PREPARE:State::RESTORE,in.now,"old action stopped; new action attempt");
            } else {
                if(in.now-cancel_started_>=config_.stop_ack_timeout){out.decision=Decision::FAILURE;out.reason="no stopped/retry confirmation";}
                return done();
            }
        }
        if(state_==State::HOLD && in.recovery_authorized && in.recovery_action_verified && matching(in,Posture::LOW) &&
            (reason_=="traverse no progress"||reason_=="traverse deadline"||reason_=="path blocked"||reason_=="motion blocked/controller unavailable")) {
            out.decision=Decision::RECOVERY;out.allow_recovery=true;return done();
        }''')
# Once cancellation has moved to a new action state, skip HOLD-only exits.
s=s.replace('if(in.now-state_started_>=config_.hold_timeout) {','if(state_==State::HOLD && in.now-state_started_>=config_.hold_timeout) {')
s=s.replace('        if((reason_=="structure feedback stale"', '        if(state_!=State::HOLD) { /* new action attempt already authorized above */ }\n        else if((reason_=="structure feedback stale"')
s=s.replace('if(in.now-request_started_>config_.prepare_timeout){hold(in.now,"preparation timeout");return done();}', '''if(!freshFeedback(in)&&in.now-request_started_>config_.ack_timeout){hold(in.now,"structure acknowledgement missing");return done();}
            if(in.now-request_started_>config_.prepare_timeout){hold(in.now,"preparation timeout");cancelling_=true;cancel_started_=in.now;out.cancel_request=true;return done();}''')
s=s.replace('if(in.now-state_started_>config_.traverse_timeout){hold(in.now,"traverse deadline");return done();}', '''if(attempt_started_<0)attempt_started_=in.now;
            if(in.now-attempt_started_>config_.traverse_timeout){hold(in.now,"traverse deadline");return done();}
            if(in.command_requested) {
                if(progress_started_<0||progress_-progress_anchor_>=config_.stall_progress){progress_anchor_=progress_;progress_started_=in.now;}
                if(in.now-progress_started_>config_.stall_timeout){hold(in.now,"traverse no progress");return done();}
            }else {progress_started_=-1;progress_anchor_=progress_;}''')
s=s.replace('if(in.now-request_started_>config_.restore_timeout){hold(in.now,"restore timeout");return done();}', 'if(in.now-request_started_>config_.restore_timeout){hold(in.now,"restore timeout");cancelling_=true;cancel_started_=in.now;out.cancel_request=true;return done();}')
s=s.replace('    out.speed_limit=previewLimit(', '''    // 已发出的紧停必须停稳；准备完成不能使停车/加速指令交替。
    if(emergency_) {
        if(in.measured_speed<config_.stopped_speed){if(stop_stable_since_<0)stop_stable_since_=in.now;}
        else stop_stable_since_=-1;
        if(stop_stable_since_>=0&&in.now-stop_stable_since_>=config_.settle_time&&matching(in,Posture::LOW)) {emergency_=false;stop_stable_since_=-1;}
        else {out.decision=Decision::STOP;out.speed_limit=0;out.pause_progress_timeout=true;out.reason="emergency stop; waiting for stopped and prepared";return done();}
    }
    if(out.stop_arc&&in.measured_speed>config_.stopped_speed) {
        const double need=in.measured_speed*config_.control_latency+in.measured_speed*in.measured_speed/(2*config_.braking_deceleration);
        if(*out.stop_arc-progress_<need-0.03) {emergency_=true;out.decision=Decision::STOP;out.speed_limit=0;out.pause_progress_timeout=true;out.reason="emergency braking distance insufficient";return done();}
    }
    out.speed_limit=previewLimit(''')
insert='''
void SlopeHoleController::completeRetreat(double arc,const Input& in) {
    if(!matching(in,Posture::LOW)||!in.pose_valid||in.measured_speed>config_.stopped_speed)
        throw std::runtime_error("retreat handover without stopped low posture");
    const double old_progress=progress_;
    progress_=arc;last_position_=in.position;last_pose_time_=in.pose_received;progress_started_=-1;
    for(const auto& p:plan_.passages)if(event(p,EventType::E).arc>=arc&&event(p,EventType::E).arc<=old_progress+epsilon) {
        auto& v=visits_.at(p.uid);v.demand=true;v.complete=false;v.phase=Phase::ENTRY_STRAIGHT;
        for(auto e:{EventType::E,EventType::X,EventType::T,EventType::D})v.emitted.erase(e);
    }
    ++attempt_;attempt_started_=in.now;transition(State::PREPARE,in.now,"retreated to S; reentry gates renewed");
}
'''
pos=s.rfind('} // namespace nav_components');s=s[:pos]+insert+s[pos:];p.write_text(s)
# Additional wire fields, keeping old constants stable.
p=R/'nav_interfaces/msg/HoleStructureFeedback.msg';s=p.read_text()+'''\n# 旧动作已结束/取消且关节停止；并非“上位机已经发出零指令”。
bool action_stopped
# 机构当前明确允许发起新动作；未知时false。
bool retry_allowed
# 0无故障；具体故障码由机构适配端定义。
uint16 fault_code
# 状态3：旧动作取消，仍需action_stopped确认。
uint8 CANCELLED=3
''';p.write_text(s)
p=R/'nav_interfaces/msg/HoleTraversalState.msg';p.write_text(p.read_text()+'''\n# 本次通行尝试编号，0为首次，1/2为两次重试。
uint32 attempt
# 专用恢复阶段：0无，1停稳，2校验，3退让，4目标停稳，5重入检查。
uint8 recovery_phase
''')
p=R/'nav_interfaces/msg/HoleTraversalEvent.msg';p.write_text(p.read_text()+'\n# 所属尝试编号；历史事件不因倒退删除。\nuint32 attempt\n')
p=R/'nav_interfaces/msg/HoleTraversal.msg';p.write_text(p.read_text()+'\n# 本次入口方向与关联坡上坡方向一致；首版只允许此类失败后退让。\nbool uphill_entry\n')
print('pure execution and wire changes applied')
