#pragma once
// 目标：nav_core/include/nav_core/hole_execution_types.hpp。纯 C++17，不依赖 ROS。
#include "nav_core/hole_geometry.hpp"
#include <map>
#include <set>
#include <optional>
#include <stdexcept>

namespace nav_core::hole_exec {
using Point = nav_core::HolePoint;
constexpr double epsilon=1e-8;
enum class State { NORMAL, PREPARE, TRAVERSE, RESTORE, HOLD };
enum class Phase { PENDING, ENTRY_STRAIGHT, IN_HOLE, EXIT_STRAIGHT, DEPARTING, COMPLETE };
enum class EventType { A, S, E, X, T, D };
enum class Range { ON_PATH, BEFORE_PATH, AFTER_PATH, UNKNOWN };
enum class Posture { KEEP, LOW, NORMAL };
enum class ActionStatus { EXECUTING, COMPLETED, FAILED, CANCELLED };
enum class PlanStatus { ACTIVE, INVALIDATED, CANCELLED, COMPLETED, FAILED };
enum class Decision { CONTINUE, STOP, REPLAN, RECOVERY, FAILURE };
enum class Travel { FLAT, UPHILL, DOWNHILL, RESTRICTED, CREST };
struct Event {
    EventType type=EventType::A;
    Range range=Range::UNKNOWN;
    double arc=0;
    Point point;
    bool point_valid=false;
};
struct Straight { double begin=0,end=0; Point direction; bool remaining=false; };
struct SpeedRegion { double begin=0,end=0,limit=0; Travel kind=Travel::RESTRICTED; };
struct Passage {
    std::string uid,hole_id;
    int entry_edge=-1,exit_edge=-1;
    bool centerline=true,validated=false,uphill_entry=false;
    Point retreat_anchor,entry_direction; bool retreat_anchor_valid=false;
    std::uint64_t requirement_revision=0;
    std::array<Event,6> events;
    std::vector<Straight> straights;
};
struct Plan {
    std::string session,goal,frame="map",reason;
    std::uint64_t id=0,terrain_revision=0,parameter_revision=0,map_revision=0;
    PlanStatus status=PlanStatus::ACTIVE;
    std::vector<Point> path;
    std::vector<Passage> passages;
    std::vector<SpeedRegion> speeds;
    bool constraints_enabled=true;
};
struct Projection { double arc=0,lateral=0; Point point; };
struct Polyline {
    std::vector<Point> points;
    std::vector<double> arcs;
    explicit Polyline(const std::vector<Point>& input) {
        for(auto p:input) {
            if(!holeFinite(p)) throw std::invalid_argument("nonfinite path");
            if(!points.empty()&&holeNorm(p-points.back())<epsilon)continue;
            arcs.push_back(points.empty()?0:arcs.back()+holeNorm(p-points.back()));points.push_back(p);
        }
        if(points.size()<2)throw std::invalid_argument("path needs two distinct points");
    }
    double length() const {return arcs.back();}
    Point at(double s) const {
        if(!std::isfinite(s)||s< -epsilon||s>length()+epsilon)throw std::out_of_range("event is outside path");
        s=std::clamp(s,0.0,length());
        auto j=std::upper_bound(arcs.begin(),arcs.end(),s);
        const auto i=std::min(std::size_t(j-arcs.begin()),points.size()-1);
        if(!i)return points.front();
        return points[i-1]+(points[i]-points[i-1])*((s-arcs[i-1])/(arcs[i]-arcs[i-1]));
    }
    Projection project(Point p,double lo,double hi) const {
        Projection best;best.lateral=std::numeric_limits<double>::infinity();bool ambiguous=false;
        for(std::size_t i=1;i<points.size();++i) {
            if(arcs[i]<lo||arcs[i-1]>hi)continue;
            const double len=arcs[i]-arcs[i-1];const Point d=points[i]-points[i-1];
            double t=holeDot(p-points[i-1],d)/(len*len);
            t=std::clamp(t,std::max(0.0,(lo-arcs[i-1])/len),std::min(1.0,(hi-arcs[i-1])/len));
            const Point q=points[i-1]+d*t;const double dist=holeNorm(p-q),s=arcs[i-1]+t*len;
            if(dist<best.lateral-1e-7){best={s,dist,q};ambiguous=false;}
            else if(std::abs(dist-best.lateral)<1e-7&&std::abs(s-best.arc)>0.05)ambiguous=true;
        }
        if(!std::isfinite(best.lateral)||ambiguous)throw std::runtime_error("ambiguous/unavailable path progress");
        return best;
    }
};
inline Event makeEvent(EventType type,double s,const Polyline& path) {
    Event e;e.type=type;e.arc=s;
    e.range=s<0?Range::BEFORE_PATH:(s>path.length()?Range::AFTER_PATH:Range::ON_PATH);
    e.point_valid=e.range==Range::ON_PATH;if(e.point_valid)e.point=path.at(s);return e;
}
inline const Event& event(const Passage& p,EventType t){return p.events.at(static_cast<std::size_t>(t));}
struct StructureRequest {
    std::string session,goal;
    std::uint64_t id=0,revision=0;
    Posture target=Posture::KEEP;
    std::vector<std::string> traversal_uids;
};
struct StructureFeedback {
    std::string session,goal;
    std::uint64_t request_id=0,revision=0;
    double received=-1,source_age=0;
    Posture target=Posture::KEEP;
    ActionStatus status=ActionStatus::EXECUTING;
    // 以下均由结构适配层按真实形态/完整包络判断，路径参考点过 D 不会自动生成 true。
    bool whole_vehicle_clear=false,normal_clearance=false,moving_transition_supported=false;
    std::set<std::string> cleared_traversals;
    bool action_stopped=false,retry_allowed=false; std::uint16_t fault_code=0;
};
struct Input {
    double now=0,pose_received=-1,measured_speed=0;
    Point position;
    bool pose_valid=false,corridor_clear=true,controller_available=true,fatal_fault=false;
    // 必须针对具体动作验证。首版不接受任意洞内通用恢复，也不自动倒车。
    bool recovery_action_verified=false,recovery_authorized=false,continuation_verified=false;
    StructureFeedback feedback;
    bool command_requested=false; double chassis_yaw=0;
    // 执行适配检查四面对准、两者实测停转及反馈时效后才置 true。
    bool entry_rotation_ready=true;
};
struct Visit {
    Phase phase=Phase::PENDING;
    bool demand=false,complete=false;
    std::set<EventType> emitted;
};
struct FiredEvent {std::string uid;EventType type;double arc=0,progress=0;std::uint64_t sequence=0;};
struct Output {
    State state=State::NORMAL;
    Decision decision=Decision::STOP;
    double progress=0,speed_limit=0;
    std::optional<double> stop_arc;
    bool pause_progress_timeout=false,allow_recovery=false,cancel_request=false;
    std::uint32_t attempt=0;
    std::optional<StructureRequest> request;
    std::vector<FiredEvent> events;
    std::string reason,blocked_hole;
};
// 数值均为软件示例默认值，现场速度/制动须确认；统一表供加载、校验及参数说明使用。
#define HOLE_EXEC_DOUBLE_PARAMETERS(X) \
 X(flat_speed,0.40,"平地基础上限","m/s") \
 X(uphill_speed,0.35,"上坡基础上限","m/s") \
 X(downhill_speed,0.20,"下坡基础上限","m/s") \
 X(prepare_speed,0.15,"移动变形期间上限","m/s") \
 X(restore_speed,0.15,"移动恢复期间上限","m/s") \
 X(restricted_speed,0.15,"坡顶后受限区上限","m/s") \
 X(post_slope_distance,0.60,"坡顶后低速路径长度","m") \
 X(braking_deceleration,0.30,"最差坡向保证制动减速度，必须实测确认","m/s^2") \
 X(acceleration_limit,0.50,"特殊执行加速度上限","m/s^2") \
 X(control_latency,0.15,"控制与反馈链路延迟预算","s") \
 X(entry_margin,0.15,"E前停车余量","m") \
 X(event_tolerance,0.01,"事件调度数值容差，不放宽E进入许可","m") \
 X(backward_window,0.15,"进度向后投影窗口","m") \
 X(forward_window,1.00,"进度向前投影窗口","m") \
 X(max_lateral_error,0.15,"可靠进度横向误差上限","m") \
 X(progress_slack,0.05,"定位可达位移额外容差","m") \
 X(pose_timeout,0.25,"位姿接收有效期","s") \
 X(feedback_timeout,0.30,"结构反馈源年龄和接收有效期","s") \
 X(prepare_timeout,12.0,"本次准备动作总期限，重传不重置","s") \
 X(traverse_timeout,30.0,"特殊通行最长执行时间","s") \
 X(restore_timeout,8.0,"本次恢复动作总期限","s") \
 X(hold_timeout,5.0,"同一暂停原因的连续等待期限","s") \
 X(request_interval,0.30,"同一请求号传输重发周期","s") \
 X(ack_timeout,1.0,"机构接收确认最大等待","s") \
 X(stop_ack_timeout,2.0,"旧动作停止确认最大等待","s") \
 X(stall_timeout,2.5,"有前进指令时无路径进展期限","s") \
 X(stall_progress,0.05,"有效路径进展阈值","m") \
 X(retreat_speed,0.15,"上坡失败后向下退让上限","m/s") \
 X(retreat_timeout,12.0,"单次退让期限","s") \
 X(stopped_speed,0.03,"停稳速度阈值","m/s") \
 X(settle_time,0.20,"停稳连续确认时间","s") \
 X(alignment_tolerance,0.05,"底盘四面对准误差","rad") \
 X(rotation_stopped_rate,0.03,"底盘和云台相对地面yaw停转阈值","rad/s") \
 X(blocked_ttl,30.0,"本任务禁用堵洞的有效期","s")
struct Config {
#define HOLE_EXEC_FIELD(name,value,meaning,unit) double name=value;
    HOLE_EXEC_DOUBLE_PARAMETERS(HOLE_EXEC_FIELD)
#undef HOLE_EXEC_FIELD
    int max_replans=2,max_action_retries=2,max_traversal_retries=2;
    bool enabled=false,allow_free=false,physical_parameters_confirmed=false;
    bool simulation_only=true;
};
// 前方限速传播：到低速区前就制动；只返回上限，不强迫机器人达到该速度。
inline double previewLimit(double s,double base,const std::vector<SpeedRegion>& regions,
                           double braking,double latency,std::optional<double> stop={}) {
    const auto reachable=[&](double target,double distance) {
        // v*latency+(v²-target²)/(2a)<=distance；保守预留当前反应距离。
        // 已不高于目标速度时不需要制动；延迟预留不能把边界前的
        // 上限压到区内上限以下，否则会在边界制造一次向上的跳变。
        return std::max(target,-braking*latency+std::sqrt(braking*braking*latency*latency+
            target*target+2*braking*std::max(0.0,distance)));
    };
    double limit=base;
    for(const auto& r:regions) {
        if(r.kind==Travel::CREST)continue; // 坡顶事件到达后才触发，不提前套用硬低速。
        if(s>r.end)continue;
        limit=std::min(limit,s>=r.begin?r.limit:reachable(r.limit,r.begin-s));
    }
    if(stop)limit=std::min(limit,reachable(0,*stop-s));
    return std::max(0.0,limit);
}
} // namespace nav_core::hole_exec
namespace nav_core::hole_exec {
struct MotionConstraints {
    bool enabled=false,allowed=false;
    std::uint64_t plan_id=0;
    double valid_until=0,base_speed=0,acceleration=0,braking=0,latency=0;
    std::optional<double> stop_arc;
    std::vector<SpeedRegion> regions;
    std::vector<Point> path;
};
}
