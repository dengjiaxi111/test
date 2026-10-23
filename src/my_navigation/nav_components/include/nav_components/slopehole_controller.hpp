#pragma once
// 目标：nav_components/include/nav_components/slopehole_controller.hpp。
#include "nav_core/hole_execution_types.hpp"
namespace nav_components {
class SlopeHoleController {
public:
    using Config=nav_core::hole_exec::Config;
    using Plan=nav_core::hole_exec::Plan;
    using Input=nav_core::hole_exec::Input;
    using Output=nav_core::hole_exec::Output;
    explicit SlopeHoleController(Config config={});
    bool acceptPlan(const Plan& plan,const Input& input,std::string& error);
    Output update(const Input& input);
    void invalidate(const std::string& reason); // 保留结构需求、阶段和去重记录。
    void closeGoal(nav_core::hole_exec::PlanStatus status=nav_core::hole_exec::PlanStatus::CANCELLED);                         // 取消/成功/失败：撤销运动，不自动抬高。
    void reportMotionFailure(double now);     // 求解器/碰撞失败转 HOLD，避免通用恢复绕过。
    void reportPathFailure(double now);
    void reportBoostFailure(double now);
    bool tunnelOccupied() const {return tunnel_occupied_;}
    void completeRetreat(double arc,const Input& input);
    // 仿真调参只更换数值和限速；保留通行、机构请求、进度与事件历史。
    void applyRuntimeConfig(const Config& config,std::vector<nav_core::hole_exec::SpeedRegion> speeds) noexcept;
    bool lowReady(const Input& input) const {return matching(input,nav_core::hole_exec::Posture::LOW);}
    bool entryAuthorized(const std::string& uid) const {return plan_valid_&&!closed_&&entry_authorized_.count(uid);}
    bool entryPositionReady() const {return lateral_error_<=config_.max_lateral_error;}
    bool occupied() const;
    bool canAcceptNewGoal() const;
    const Plan& plan() const {return plan_;}
    const std::map<std::string,nav_core::hole_exec::Visit>& visits() const {return visits_;}
    nav_core::hole_exec::State state() const {return state_;}
private:
    void transition(nav_core::hole_exec::State next,double now,const std::string& reason);
    void hold(double now,const std::string& reason);
    bool freshFeedback(const Input& in) const;
    bool matching(const Input& in,nav_core::hole_exec::Posture target) const;
    void request(nav_core::hole_exec::Posture target,const Input& in,Output& out);
    bool updateProgress(const Input& in,std::string& reason);
    void schedule(const Input& in,Output& out);
    Config config_;
    Plan plan_;
    std::map<std::string,nav_core::hole_exec::Visit> visits_;
    std::set<std::string> entry_authorized_; // 当前LOW请求下，按通行保存初次严格准备许可。
    nav_core::hole_exec::State state_=nav_core::hole_exec::State::NORMAL,resume_=nav_core::hole_exec::State::NORMAL;
    std::optional<nav_core::hole_exec::StructureRequest> request_;
    double progress_=0,last_projected_arc_=0,last_now_=-1,last_pose_time_=-1,state_started_=0,request_started_=0,last_sent_=-1;
    nav_core::hole_exec::Point last_position_;
    bool have_progress_=false,plan_valid_=false,closed_=false,had_low_=false;
    bool gimbal_heading_held_=false; // 与连续洞LOW保持共用释放时机。
    std::map<std::string,double> tunnel_started_;
    bool tunnel_occupied_=false;
    double attempt_started_=-1,progress_started_=-1,progress_anchor_=0,cancel_started_=-1,stop_stable_since_=-1;
    bool cancelling_=false,emergency_=false;
    double input_stable_since_=-1,lateral_error_=0;
    std::map<nav_core::hole_exec::Posture,int> action_retries_;
    std::vector<nav_core::hole_exec::FiredEvent> event_history_;
    std::uint32_t attempt_=0;
    std::string reason_="initial NORMAL";
    std::uint64_t next_request_=0,next_event_=0;
};
} // namespace nav_components
