#include "nav_components/slopehole_controller.hpp"
#include <tuple>
namespace nav_components {
using namespace nav_core::hole_exec;
SlopeHoleController::SlopeHoleController(Config c):config_(c) {
#define HOLE_EXEC_CHECK(name,value,meaning,unit) if(!std::isfinite(c.name)||c.name<0||(c.name==0&&std::string(#name)!="minimum_entry_speed"&&std::string(#name)!="minimum_slope_speed"))throw std::invalid_argument(#name " must be finite and positive");
    HOLE_EXEC_DOUBLE_PARAMETERS(HOLE_EXEC_CHECK)
#undef HOLE_EXEC_CHECK
    if((c.minimum_entry_speed>0&&c.minimum_entry_speed+c.speed_recover_margin>c.boost_speed)||
       (c.minimum_slope_speed>0&&c.minimum_slope_speed+c.speed_recover_margin>c.boost_speed))
        throw std::invalid_argument("boost_speed must exceed enabled minimum speed by recovery margin");
    if(c.max_replans<0||c.event_tolerance>=c.entry_margin)throw std::invalid_argument("invalid retry/tolerance relationship");
}
void SlopeHoleController::applyRuntimeConfig(const Config& c,std::vector<SpeedRegion> speeds) noexcept {
    config_=c;plan_.speeds=std::move(speeds);
    if(plan_.id){++plan_.id;++plan_.parameter_revision;}
}
bool SlopeHoleController::occupied() const {
    for(const auto& pair:visits_)if(pair.second.demand)return true;
    return had_low_||state_==State::RESTORE;
}
bool SlopeHoleController::canAcceptNewGoal() const {return !occupied();}
void SlopeHoleController::transition(State next,double now,const std::string& reason) {
    if(next!=state_){state_=next;state_started_=now;}reason_=reason;
}
void SlopeHoleController::hold(double now,const std::string& reason) {
    if(state_!=State::HOLD)resume_=state_;
    // 同一异常不反复重置 HOLD 起始时间。
    transition(State::HOLD,now,reason);
}
void SlopeHoleController::invalidate(const std::string& reason) {entry_authorized_.clear();if(!plan_valid_&&reason_==reason)return;plan_valid_=false;reason_=reason;plan_.status=PlanStatus::INVALIDATED;plan_.reason=reason;if(plan_.id)++plan_.id;}
void SlopeHoleController::closeGoal(PlanStatus status){closed_=true;invalidate("goal closed; preserve physical posture requirements");plan_.status=status;}
void SlopeHoleController::reportMotionFailure(double now){hold(now,"motion blocked/controller unavailable");}
void SlopeHoleController::reportBoostFailure(double now){hold(now,"minimum speed takeover ineffective");}
void SlopeHoleController::reportPathFailure(double now){hold(now,"path blocked");}
bool SlopeHoleController::acceptPlan(const Plan& p,const Input& in,std::string& error) {
    try {
        Polyline path(p.path);
        if(p.frame!="map"||p.session.empty()||p.goal.empty()||!p.id||p.status!=PlanStatus::ACTIVE)
            throw std::runtime_error("invalid plan identity/status/frame");
        const bool same=p.session==plan_.session&&p.goal==plan_.goal;
        if(same&&p.id<=plan_.id)throw std::runtime_error("old/duplicate plan version");
        if(!same&&occupied())throw std::runtime_error("new goal/session needs physical handover");
        auto start=path.project(in.position,0,path.length());
        std::set<std::string> ids;
        for(const auto& v:p.passages) {
            if(v.uid.empty()||!ids.insert(v.uid).second||!v.validated||(!v.centerline&&!config_.allow_free))
                throw std::runtime_error("unvalidated/duplicate/unsupported passage");
            for(std::size_t j=0;j<6;++j) {
                const auto& e=v.events[j];
                if(static_cast<std::size_t>(e.type)!=j)throw std::runtime_error("event types/order inconsistent");
                if(e.range==Range::UNKNOWN)continue;
                if(!std::isfinite(e.arc))throw std::runtime_error("nonfinite event arc");
                if(e.range==Range::ON_PATH&&(!e.point_valid||holeNorm(e.point-path.at(e.arc))>0.03))
                    throw std::runtime_error("event/path mismatch");
            }
            // A 只要求早于 E；不要求 A 在 S 前面。
            if(event(v,EventType::A).range!=Range::UNKNOWN&&event(v,EventType::E).range!=Range::UNKNOWN&&
                event(v,EventType::A).arc>=event(v,EventType::E).arc)throw std::runtime_error("A must precede E");
            const auto& a=event(v,EventType::A);const auto& e=event(v,EventType::E);
            if(a.range==Range::ON_PATH&&e.range==Range::ON_PATH&&start.arc+epsilon<a.arc&&
               a.arc+config_.event_tolerance>=e.arc-config_.entry_margin)
                throw std::runtime_error("A must precede the E parking boundary: increase prepare_path_distance or reduce entry_margin");
            for(int j=2;j<6;++j)if(v.events[j].range!=Range::UNKNOWN&&v.events[j-1].range!=Range::UNKNOWN&&
                v.events[j].arc+epsilon<v.events[j-1].arc)throw std::runtime_error("S/E/X/T/D out of order");
        }
        for(const auto& r:p.speeds)if(!std::isfinite(r.begin)||!std::isfinite(r.end)||
            !std::isfinite(r.limit)||r.begin>r.end||r.limit<=0)throw std::runtime_error("invalid speed region");
        for(const auto& r:p.slopes)if(r.id.empty()||!std::isfinite(r.begin)||!std::isfinite(r.end)||
            r.begin<0||r.end<=r.begin||r.end>path.length()+epsilon)
            throw std::runtime_error("invalid merged slope section");
        std::vector<std::string> safely_abandoned;
        if(same)for(const auto& old:plan_.passages) {
            const auto it=visits_.find(old.uid);if(it==visits_.end()||!it->second.demand)continue;
            if(!ids.count(old.uid)) {
                const auto& entrance=event(old,EventType::E);
                if(entrance.range==Range::ON_PATH&&progress_<entrance.arc&&freshFeedback(in)&&
                   in.feedback.whole_vehicle_clear&&in.feedback.normal_clearance) {
                    safely_abandoned.push_back(old.uid);continue;
                }
                throw std::runtime_error("active traversal lost during replan");
            }
            const auto& next=*std::find_if(p.passages.begin(),p.passages.end(),[&](const auto& n){return n.uid==old.uid;});
            if(next.entry_edge!=old.entry_edge||next.exit_edge!=old.exit_edge)throw std::runtime_error("active direction changed");
        }
        if(start.lateral>config_.max_lateral_error)throw std::runtime_error("new plan projection too far");
        bool changed_requirements=!same;
        for(const auto& next:p.passages) {
            auto old=std::find_if(plan_.passages.begin(),plan_.passages.end(),[&](const auto& x){return x.uid==next.uid;});
            if(old!=plan_.passages.end()&&old->requirement_revision!=next.requirement_revision)changed_requirements=true;
        }
        if(!same){tunnel_started_.clear();visits_.clear();request_.reset();had_low_=false;gimbal_heading_held_=false;state_=State::NORMAL;action_retries_.clear();attempt_=0;attempt_started_=-1;progress_started_=-1;cancelling_=false;emergency_=false;event_history_.clear();}
        if(changed_requirements){request_.reset();entry_authorized_.clear();}
        for(const auto& uid:safely_abandoned){visits_.at(uid).demand=false;entry_authorized_.erase(uid);}
        for(auto it=entry_authorized_.begin();it!=entry_authorized_.end();) {
            if(!ids.count(*it))it=entry_authorized_.erase(it);else ++it;
        }
        plan_=p;for(const auto& v:p.passages)visits_.try_emplace(v.uid);
        progress_=start.arc;last_projected_arc_=start.arc;lateral_error_=start.lateral;have_progress_=true;last_position_=in.position;last_pose_time_=in.pose_received;
        plan_valid_=true;closed_=false;
        if(state_==State::HOLD)transition(resume_,in.now,"new plan explicitly revalidated");
        reason_="accepted immutable plan";
        return true;
    }catch(const std::exception& e){error=e.what();plan_valid_=false;entry_authorized_.clear();return false;}
}
bool SlopeHoleController::freshFeedback(const Input& in) const {
    const auto& f=in.feedback;
    return request_&&f.session==request_->session&&f.goal==request_->goal&&
        f.request_id==request_->id&&f.revision==request_->revision&&f.target==request_->target&&
        f.received>=request_started_&&in.now>=f.received&&in.now-f.received<=config_.feedback_timeout&&
        std::isfinite(f.source_age)&&f.source_age>=0&&f.source_age<=config_.feedback_timeout;
}
bool SlopeHoleController::matching(const Input& in,Posture target) const {
    return freshFeedback(in)&&request_->target==target&&in.feedback.status==ActionStatus::COMPLETED;
}
void SlopeHoleController::request(Posture target,const Input& in,Output& out) {
    if(!request_||request_->target!=target) {
        entry_authorized_.clear(); // 新动作/恢复NORMAL不能复用旧LOW许可。
        request_=StructureRequest{plan_.session,plan_.goal,++next_request_,plan_.parameter_revision^(plan_.terrain_revision<<32),target,{}};
        request_started_=in.now;last_sent_=-1;
        if(target==Posture::LOW)had_low_=true;
        if(target==Posture::NORMAL)gimbal_heading_held_=false; // 最后D及整车净空已由恢复分支确认。
    }
    request_->traversal_uids.clear();
    for(const auto& v:visits_)if(v.second.demand)request_->traversal_uids.push_back(v.first);
    if(last_sent_<0||in.now-last_sent_>=config_.request_interval){out.request=request_;last_sent_=in.now;}
}
bool SlopeHoleController::updateProgress(const Input& in,std::string& reason) {
    if(!in.pose_valid||!holeFinite(in.position)||!std::isfinite(in.pose_received)||in.now<in.pose_received||
       in.now-in.pose_received>config_.pose_timeout||!std::isfinite(in.measured_speed)||in.measured_speed<0) {
        reason="pose/velocity invalid or stale";return false;
    }
    try {
        Polyline p(plan_.path);
        const double elapsed=std::max(0.0,in.pose_received-last_pose_time_);
        const double reach=std::max({config_.flat_speed,config_.boost_speed,in.measured_speed})*elapsed+
            0.5*config_.acceleration_limit*elapsed*elapsed+config_.progress_slack;
        if(holeNorm(in.position-last_position_)>reach) {
            reason="unreliable progress/localization jump";return false;
        }
        if(plan_.passages.empty()) {
            // 普通路径的偏离、终点容差和重新规划由原导航控制器处理；
            // 这里的进度只用于显示，不能用洞内窄通道阈值抢占普通导航。
            const auto q=p.project(in.position,0.,p.length());
            progress_=std::max(progress_,q.arc);last_projected_arc_=q.arc;
            last_position_=in.position;last_pose_time_=in.pose_received;
            return true;
        }
        // 搜索额外覆盖一帧可达距离，才能看见越过后退边界的真实投影；
        // 否则夹在边界上的结果会使下面的后退窗口检查永远无法触发。
        const auto q=p.project(in.position,std::max(0.0,progress_-config_.backward_window-reach),
            std::min(p.length(),progress_+config_.forward_window));
        const Point tangent=p.at(std::min(p.length(),q.arc+.005))-p.at(std::max(0.,q.arc-.005));
        const double lateral=std::abs(holeCross(in.position-q.point,tangent))/std::max(holeNorm(tangent),epsilon);
        bool strict=false,enclosed=false;
        for(const auto& passage:plan_.passages) {
            const auto visit=visits_.find(passage.uid);
            if(visit!=visits_.end()&&visit->second.complete)continue;
            const auto& s=event(passage,EventType::S);const auto& t=event(passage,EventType::X);
            if(s.range==Range::UNKNOWN||t.range==Range::UNKNOWN){strict=enclosed=true;break;}
            if(s.range==Range::AFTER_PATH||t.range==Range::BEFORE_PATH)continue;
            const double begin=s.range==Range::BEFORE_PATH?0.:s.arc;
            const double end=t.range==Range::AFTER_PATH?p.length():t.arc;
            const auto inside=[&](double arc){return arc>=begin-epsilon&&arc<=end+epsilon;};
            if(inside(last_projected_arc_)||inside(q.arc)){strict=true;break;}
        }
        for(const auto& passage:plan_.passages) {
            if(visits_.at(passage.uid).complete)continue;
            const auto& e=event(passage,EventType::E);const auto& t=event(passage,EventType::X);
            if(e.range==Range::UNKNOWN||t.range==Range::UNKNOWN){enclosed=true;break;}
            if(e.range==Range::AFTER_PATH||t.range==Range::BEFORE_PATH)continue;
            const double begin=std::max(0.,e.arc),end=std::min(p.length(),t.arc);
            if((last_projected_arc_>=begin&&last_projected_arc_<=end)||
               (q.arc>=begin&&q.arc<=end))enclosed=true;
        }
        // 洞口X可能早于坡面末端；实际坡面上的进度/横差保护仍保留。
        for(const auto& slope:plan_.slopes)if((q.arc>=slope.begin&&q.arc<=slope.end)||
            (last_projected_arc_>=slope.begin&&last_projected_arc_<=slope.end))strict=enclosed=true;
        // S-E是洞外纠偏段，横差只阻止进入，不冻结正常纠偏。
        // 真正跳变/后退仍检查；洞内与实际坡面继续执行横差保护。
        if(enclosed&&lateral>config_.max_lateral_error){reason="inside passage lateral limit exceeded";return false;}
        if(strict&&(q.arc<progress_-config_.backward_window||
            std::abs(q.arc-last_projected_arc_)>reach)) {
            reason="unreliable progress/localization jump";return false;
        }
        lateral_error_=lateral;
        // 单次采样的运动量与上一投影比较；事件进度仍只增不减，不因小回滑重放事件。
        progress_=std::max(progress_,q.arc);last_projected_arc_=q.arc;last_position_=in.position;last_pose_time_=in.pose_received;return true;
    }catch(const std::exception& e){reason=e.what();return false;}
}
void SlopeHoleController::schedule(const Input& in,Output& out) {
    // 严格对准只授予一次许可。后续坡面姿态/角速度扰动不撤销本次通行。
    // 与适配器一样只检查首个活跃通行，防止同一帧对准结果放行后面的洞。
    if(matching(in,Posture::LOW)&&state_!=State::HOLD)for(const auto& p:plan_.passages) {
        const auto& v=visits_.at(p.uid);if(v.complete)continue;
        const auto& a=event(p,EventType::A);
        if(a.range==Range::AFTER_PATH||(a.range==Range::ON_PATH&&progress_+epsilon<a.arc))continue;
        if(in.entry_rotation_ready&&(in.entry_rotation_uid.empty()||in.entry_rotation_uid==p.uid)) {
            entry_authorized_.insert(p.uid);
            // LOW和实测对准均完成后锁存；D1释放单洞需求不释放云台朝向。
            gimbal_heading_held_=true;
        }
        break;
    }
    struct Item {double s;std::string uid;EventType type;};std::vector<Item> due;
    for(const auto& p:plan_.passages) {
        auto& v=visits_.at(p.uid);
        if(v.complete)continue;
        const auto& a=event(p,EventType::A);
        // BEFORE_PATH/入口历史未知：立刻登记需求，绝不推断准备已完成。
        if(a.range==Range::BEFORE_PATH||a.range==Range::UNKNOWN)v.demand=true;
        for(const auto& e:p.events)if(e.range==Range::ON_PATH&&!v.emitted.count(e.type)&&
            progress_+epsilon>=e.arc)due.push_back({e.arc,p.uid,e.type});
    }
    std::sort(due.begin(),due.end(),[](const auto& a,const auto& b){return std::tie(a.s,a.type,a.uid)<std::tie(b.s,b.type,b.uid);});
    // 先处理这一控制周期所有新增/完成需求，最后才判断全局恢复。
    for(const auto& item:due) {
        auto& v=visits_.at(item.uid);
        if(item.type==EventType::E&&!matching(in,Posture::LOW))throw std::runtime_error("entry crossed before preparation confirmed");
        if(item.type==EventType::E&&!entryAuthorized(item.uid))throw std::runtime_error("entry crossed before alignment and rotation stop confirmed");
        if(item.type==EventType::E&&!entryPositionReady())throw std::runtime_error("entry crossed before lateral position corrected");
        if(item.type==EventType::A)v.demand=true;
        if(item.type==EventType::S)v.phase=Phase::ENTRY_STRAIGHT;
        if(item.type==EventType::E)v.phase=Phase::IN_HOLE;
        if(item.type==EventType::X)v.phase=Phase::EXIT_STRAIGHT;
        if(item.type==EventType::T)v.phase=Phase::DEPARTING;
        // D 只标记路径阶段，结构释放还需真实反馈。
        if(item.type==EventType::D)v.phase=Phase::COMPLETE;
        v.emitted.insert(item.type);out.events.push_back({item.uid,item.type,item.s,progress_,++next_event_});event_history_.push_back(out.events.back());
    }
    for(const auto& p:plan_.passages) {
        auto& v=visits_.at(p.uid);
        const auto& d=event(p,EventType::D);
        const bool reached=v.emitted.count(EventType::D)||(d.range==Range::BEFORE_PATH);
        if(v.demand&&reached&&matching(in,Posture::LOW)&&in.feedback.whole_vehicle_clear&&
           in.feedback.normal_clearance&&in.feedback.cleared_traversals.count(p.uid)) {
            v.demand=false;v.complete=true;v.phase=Phase::COMPLETE;entry_authorized_.erase(p.uid);
        }
    }
}
Output SlopeHoleController::update(const Input& in) {
    Output out;out.state=state_;out.progress=progress_;out.attempt=attempt_;
    const auto done=[&](){out.state=state_;out.progress=progress_;out.hold_gimbal_heading=gimbal_heading_held_;if(out.reason.empty())out.reason=reason_;return out;};
    if(!config_.enabled){out.decision=Decision::CONTINUE;out.speed_limit=std::numeric_limits<double>::infinity();return done();}
    if(!std::isfinite(in.now)||in.now<last_now_){out.decision=Decision::FAILURE;out.reason="clock reversed";return done();}
    last_now_=in.now;
    if(in.fatal_fault){out.decision=Decision::FAILURE;out.reason="fatal chassis/structure fault";return done();}
    if(!plan_valid_||closed_){out.reason=reason_;out.pause_progress_timeout=occupied();return done();}
    const bool feedback_fresh=freshFeedback(in);
    if(!matching(in,Posture::LOW))entry_authorized_.clear(); // 真实失联/机构未就绪仍需重新准备。
    if(feedback_fresh&&in.feedback.status==ActionStatus::FAILED) {hold(in.now,"structure action failed");if(!cancelling_){cancelling_=true;cancel_started_=in.now;}}
    else if((state_==State::TRAVERSE||state_==State::RESTORE)&&!feedback_fresh&&
        in.now-request_started_>config_.ack_timeout)hold(in.now,"structure feedback stale");
    std::string invalid;
    if(!updateProgress(in,invalid)){input_stable_since_=-1;hold(in.now,invalid);out.pause_progress_timeout=true;if(in.now-state_started_>=config_.hold_timeout)out.decision=Decision::FAILURE;return done();}
    if(!config_.simulation_only&&!config_.physical_parameters_confirmed&&!plan_.passages.empty()) {
        hold(in.now,"physical parameters/interfaces not confirmed");out.pause_progress_timeout=true;return done();
    }
    try{schedule(in,out);}catch(const std::exception& e){
        hold(in.now,e.what());out.reason=e.what();out.pause_progress_timeout=true;
        if(in.now-state_started_>=config_.hold_timeout)out.decision=Decision::FAILURE;
        return done();
    }
    const double terrain_limit=config_.flat_speed;
    // 北理式区域停留计时：真实参考点进入本次洞多边形开始，退出才清除。
    // 不从TRAVERSE开始计时，也不以是否有进展作为15s触发条件。
    tunnel_occupied_=false;
    for(const auto& p:plan_.passages) {
        const auto& v=visits_.at(p.uid);
        const bool inside=!v.complete && (p.polygon.empty()?
            (progress_>=event(p,EventType::E).arc && progress_<event(p,EventType::X).arc):
            nav_core::holeContains(p.polygon,in.position));
        if(inside) {
            tunnel_occupied_=true;
            auto started=tunnel_started_.emplace(p.uid,in.now).first;
            if(state_!=State::HOLD && in.now-started->second>=config_.tunnel_timeout)
                hold(in.now,"tunnel residence timeout");
        }else tunnel_started_.erase(p.uid);
    }
    bool demand=false,entered=false,entries_authorized=true;
    for(const auto& p:plan_.passages) {
        const auto& v=visits_.at(p.uid);demand|=v.demand;
        if(v.demand&&!entryAuthorized(p.uid))entries_authorized=false;
        if(v.demand&&(event(p,EventType::E).range==Range::BEFORE_PATH||event(p,EventType::E).range==Range::UNKNOWN||
           progress_>=event(p,EventType::E).arc))entered=true;
        if(v.demand&&(!matching(in,Posture::LOW)||(!v.emitted.count(EventType::E)&&
            (!entryAuthorized(p.uid)||!entryPositionReady())))) {
            const auto& e=event(p,EventType::E);
            if(e.range==Range::UNKNOWN||e.range==Range::BEFORE_PATH)out.stop_arc=progress_;
            else {const double stop=e.arc-config_.entry_margin;if(!out.stop_arc||stop<*out.stop_arc)out.stop_arc=stop;}
        }
    }
    // 同一计划的连续洞共用LOW；尚未到下一洞A时只保留结构状态，
    // 不提前登记该洞需求或授予对准/入口许可。
    const bool hold_low_for_next=had_low_&&!demand&&std::any_of(plan_.passages.begin(),plan_.passages.end(),[&](const auto& p){
        return !visits_.at(p.uid).complete&&event(p,EventType::A).range!=Range::AFTER_PATH;
    });
    bool can_restore=had_low_&&!demand&&feedback_fresh&&in.feedback.whole_vehicle_clear&&in.feedback.normal_clearance;
    bool terrain_active=tunnel_occupied_;
    for(const auto& p:plan_.passages)if(visits_.at(p.uid).demand&&!visits_.at(p.uid).emitted.count(EventType::X))terrain_active=true;
    for(const auto& slope:plan_.slopes)if(last_projected_arc_>=slope.begin&&last_projected_arc_<=slope.end)terrain_active=true;
    if(!in.corridor_clear||!in.controller_available)hold(in.now,"motion blocked/controller unavailable");
    if(state_==State::HOLD) {
        out.pause_progress_timeout=true;
        if(request_&&!cancelling_)request(request_->target,in,out);
        if(cancelling_) {
            out.cancel_request=true;
            if(feedback_fresh && in.feedback.action_stopped && in.feedback.retry_allowed && request_) {
                auto target=request_->target;
                if(action_retries_[target]>=config_.max_action_retries) {out.decision=Decision::FAILURE;out.reason="structure retry budget exhausted";return done();}
                ++action_retries_[target];request_.reset();cancelling_=false;out.cancel_request=false;
                transition(target==Posture::LOW?State::PREPARE:State::RESTORE,in.now,"old action stopped; new action attempt");
            } else {
                if(in.now-cancel_started_>=config_.stop_ack_timeout){out.decision=Decision::FAILURE;out.reason="no stopped/retry confirmation";}
                return done();
            }
        }
        if(state_==State::HOLD && in.recovery_authorized && in.recovery_action_verified && matching(in,Posture::LOW) &&
            (reason_=="traverse no progress"||reason_=="traverse deadline"||reason_=="path blocked"||reason_=="motion blocked/controller unavailable"||reason_=="tunnel residence timeout"||reason_=="minimum speed takeover ineffective")) {
            out.decision=Decision::RECOVERY;out.allow_recovery=true;return done();
        }
        if(state_==State::HOLD && in.now-state_started_>=config_.hold_timeout) {
            if(reason_=="structure action failed"){out.decision=Decision::FAILURE;return done();}
            // 结构外换路优先；洞内保持停车，不放行现有四向平移恢复。
            if(!entered&&feedback_fresh&&in.feedback.whole_vehicle_clear&&in.feedback.normal_clearance) {
                out.decision=Decision::REPLAN;
                for(const auto& p:plan_.passages)if(visits_.at(p.uid).demand){out.blocked_hole=p.hole_id;break;}
            }else if(!occupied()&&in.recovery_authorized&&in.recovery_action_verified) {
                out.decision=Decision::RECOVERY;out.allow_recovery=true;
            }else out.decision=Decision::FAILURE;
            return done();
        }
        if(state_!=State::HOLD) { /* new action attempt already authorized above */ }
        else if(reason_=="pose/velocity invalid or stale") {
            // updateProgress已重新验证当前采样、真实位移和路径约束。
            // 仅短暂反馈失效可自动恢复，真正跳变/偏离仍须显式处理。
            if(input_stable_since_<0)input_stable_since_=in.now;
            if(in.now-input_stable_since_<config_.settle_time)return done();
            input_stable_since_=-1;transition(resume_,in.now,"pose/velocity feedback revalidated");
        }else if((reason_=="structure feedback stale"||reason_=="restore clearance lost")&&resume_==State::RESTORE&&
            feedback_fresh&&in.feedback.status!=ActionStatus::FAILED&&in.feedback.whole_vehicle_clear&&in.feedback.normal_clearance) {
            request_.reset();transition(State::RESTORE,in.now,"restore clearance revalidated; issue new request");
        }else if((reason_=="structure feedback stale"||reason_=="structure acknowledgement missing")&&request_&&
            freshFeedback(in)&&in.feedback.status!=ActionStatus::FAILED&&in.feedback.status!=ActionStatus::CANCELLED)
            transition(resume_,in.now,"structure feedback restored");
        else if(in.continuation_verified&&in.corridor_clear&&in.controller_available&&(reason_=="motion blocked/controller unavailable"||reason_=="path blocked"))
            transition(resume_,in.now,"local continuation verified");
        else return done();
    }
    if(demand) {
        if(state_==State::RESTORE)transition(State::PREPARE,in.now,"new demand interrupts restoration; request low again");
        if(!matching(in,Posture::LOW)) {
            if(state_!=State::PREPARE)transition(State::PREPARE,in.now,"A reached or remaining preparation required");
            // A当帧发LOW，与对准并行；严格对准只控制E进入许可。
            request(Posture::LOW,in,out);
            if(!freshFeedback(in)&&in.now-request_started_>config_.ack_timeout){hold(in.now,"structure acknowledgement missing");return done();}
            if(in.now-request_started_>config_.prepare_timeout){hold(in.now,"preparation timeout");cancelling_=true;cancel_started_=in.now;out.cancel_request=true;return done();}
            // 等待首个应答时继续按E停车包络前进；显式不支持移动变形的接口仍须停车。
            if(entered||(freshFeedback(in)&&!in.feedback.moving_transition_supported))out.stop_arc=progress_;
            out.speed_limit=terrain_limit;
        }else {
            request(Posture::LOW,in,out); // 刷新活跃通行集合，传输重发保持同一动作编号。
            had_low_=true;
            if(state_!=State::TRAVERSE)transition(State::TRAVERSE,in.now,"low posture confirmed");
            if(attempt_started_<0)attempt_started_=in.now;
            if(terrain_active&&!tunnel_occupied_&&in.now-attempt_started_>config_.traverse_timeout){hold(in.now,"traverse deadline");return done();}
            if(in.command_requested&&!tunnel_occupied_&&terrain_active) {
                if(progress_started_<0||progress_-progress_anchor_>=config_.stall_progress){progress_anchor_=progress_;progress_started_=in.now;}
                if(in.now-progress_started_>config_.stall_timeout){hold(in.now,"traverse no progress");return done();}
            }else {progress_started_=-1;progress_anchor_=progress_;}
            out.speed_limit=terrain_limit;
        }
    }else if(hold_low_for_next) {
        if(!matching(in,Posture::LOW)){hold(in.now,"structure feedback stale");return done();}
        request(Posture::LOW,in,out); // 同一动作编号，已完成的下降不会重新执行。
        transition(State::TRAVERSE,in.now,"holding low between consecutive passages");
        // 洞间普通连接路段不计入下一洞的通行/无进展期限。
        attempt_started_=-1;progress_started_=-1;progress_anchor_=progress_;
        out.speed_limit=terrain_limit;
    }else if(had_low_) {
        if(state_!=State::RESTORE) {
            if(!can_restore){hold(in.now,"restore clearance not confirmed");return done();}
            transition(State::RESTORE,in.now,"all traversal demands released with clearance");
        }
        // 恢复期间也持续检查净空；完成反馈必须对应 NORMAL 请求。
        if(!in.feedback.whole_vehicle_clear||!in.feedback.normal_clearance){hold(in.now,"restore clearance lost");return done();}
        request(Posture::NORMAL,in,out);
        if(matching(in,Posture::NORMAL)) {had_low_=false;transition(State::NORMAL,in.now,"normal posture confirmed");out.speed_limit=terrain_limit;}
        else {
            if(in.now-request_started_>config_.restore_timeout){hold(in.now,"restore timeout");cancelling_=true;cancel_started_=in.now;out.cancel_request=true;return done();}
            out.speed_limit=config_.restore_speed;
            if(!in.feedback.moving_transition_supported)out.stop_arc=progress_;
        }
    }else {transition(State::NORMAL,in.now,"ordinary path following");out.speed_limit=terrain_limit;}
    // 已发出的紧停必须停稳；准备完成不能使停车/加速指令交替。
    if(emergency_) {
        if(in.measured_speed<config_.stopped_speed){if(stop_stable_since_<0)stop_stable_since_=in.now;}
        else stop_stable_since_=-1;
        if(stop_stable_since_>=0&&in.now-stop_stable_since_>=config_.settle_time&&matching(in,Posture::LOW)&&entries_authorized) {emergency_=false;stop_stable_since_=-1;}
        else {out.decision=Decision::STOP;out.speed_limit=0;out.pause_progress_timeout=true;out.reason="emergency stop; waiting for stopped and prepared";return done();}
    }
    if(out.stop_arc&&in.measured_speed>config_.stopped_speed) {
        const double need=in.measured_speed*config_.control_latency+in.measured_speed*in.measured_speed/(2*config_.braking_deceleration);
        if(*out.stop_arc-progress_<need-0.03) {emergency_=true;out.decision=Decision::STOP;out.speed_limit=0;out.pause_progress_timeout=true;out.reason="emergency braking distance insufficient";return done();}
    }
    out.speed_limit=previewLimit(progress_,out.speed_limit,plan_.speeds,config_.braking_deceleration,config_.control_latency,out.stop_arc);
    if(out.stop_arc&&*out.stop_arc<=progress_+config_.event_tolerance) {
        out.decision=Decision::STOP;out.pause_progress_timeout=true;out.speed_limit=0;
    }else out.decision=Decision::CONTINUE;
    return done();
}

void SlopeHoleController::completeRetreat(double arc,const Input& in) {
    if(!matching(in,Posture::LOW)||!in.pose_valid||in.measured_speed>config_.stopped_speed)
        throw std::runtime_error("retreat handover without stopped low posture");
    const double old_progress=progress_;
    entry_authorized_.clear(); // 退让后的下一次进入重新取得许可。
    progress_=arc;last_projected_arc_=arc;last_position_=in.position;last_pose_time_=in.pose_received;progress_started_=-1;
    for(const auto& p:plan_.passages)if(event(p,EventType::E).arc>=arc&&event(p,EventType::E).arc<=old_progress+epsilon) {
        auto& v=visits_.at(p.uid);v.demand=true;v.complete=false;v.phase=Phase::ENTRY_STRAIGHT;
        for(auto e:{EventType::E,EventType::X,EventType::T,EventType::D})v.emitted.erase(e);
    }
    tunnel_started_.clear();tunnel_occupied_=false;
    ++attempt_;attempt_started_=in.now;transition(State::PREPARE,in.now,"retreated to S; reentry gates renewed");
}
} // namespace nav_components
