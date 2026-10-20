#pragma once

#include "nav_components/planner/hole_connection_search.hpp"
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <array>

namespace nav_components {

using HoleHullCheck=std::function<nav_core::HolePassageCheck(const std::vector<nav_core::HolePoint> &)>;
using HoleDistanceQuery=std::function<double(double,double,double *,double *)>;

struct HoleConnectionOptimizationParams {
    bool enabled=true;                 // 启用受约束连接曲线优化
    bool enforce_max_curvature=false;   // 启用可选的硬曲率上限
    bool responsive=false;             // 快速策略优先返回收敛且合法的主拟合
    double relative_improvement_tolerance=0.001; // 相对改善不足时的收敛阈值
    int stagnation_iterations=5;        // 连续改善不足的迭代数
    int max_iterations=100;             // 单个种子的优化迭代上限
    double control_spacing=0.3;         // 控制点目标间距（米）
    double length_weight=1.0;           // 归一化路径长度权重
    double curvature_weight=0.02;       // 归一化曲率平方积分权重
    double curvature_change_weight=0.002; // 归一化曲率变化权重
    double obstacle_weight=5.0;         // ESDF 障碍距离权重
    double reference_weight=0.1;        // 偏离种子路线权重
    double safe_distance=0.3;           // 软障碍距离（米），不是车体半径
    double approach_smoothing_timeout=0.2; // 可行优先接入的整段样条优化上限（秒），0 跳过；仍受单连接总预算限制
};
bool validHoleOptimizationParams(const HoleConnectionOptimizationParams &params);

// 自由空间种子与绕行候选复用连续碰撞检查；展开数量和截止时间共同限制预算。
bool searchHoleGridConnection(nav_core::HolePoint start,nav_core::HolePoint goal,
    const nav_msgs::msg::OccupancyGrid &map,const nav_core::HoleSegmentCheck &collision,int budget,
    std::chrono::steady_clock::time_point deadline,std::vector<nav_core::HolePoint> &out,int &expansions);

struct HoleBezierSpan {
    std::array<nav_core::HolePoint,4> controls;
};
struct HoleOptimizedConnection {
    nav_core::HolePassageCheck check;
    std::vector<nav_core::HolePoint> points,seed;
    std::vector<HoleBezierSpan> spans;
    double length=0,seed_length=0,maximum_curvature=0,cost=0,elapsed_ms=0;
    int expansions=0,iterations=0,fits=0;
    double seed_search_ms=0,curve_fit_ms=0,curve_validation_ms=0;
    int rounded_corners=0,retained_corners=0;
    std::string smoothing_failure; // 整段平滑失败后保留后备时的诊断原因
};

// 连续曲线以控制点凸包递归检查；无法证明无碰撞或无尖点时拒绝。
nav_core::HolePassageCheck validateHoleCurve(const std::vector<HoleBezierSpan> &spans,
    const HoleHullCheck &hull_check,double resolution,std::optional<double> maximum_curvature,
    std::chrono::steady_clock::time_point deadline,std::vector<nav_core::HolePoint> &points,
    double &observed_curvature);

HoleOptimizedConnection optimizeHoleConnection(nav_core::HolePoint start,nav_core::HolePoint initial_tangent,
    const std::vector<nav_core::HolePoint> &waypoints,std::optional<nav_core::HolePoint> final_tangent,
    const HoleConnectionOptimizationParams &params,const HoleConnectionSearchParams &search,
    const nav_msgs::msg::OccupancyGrid &map,const nav_core::HoleSegmentCheck &collision,
    const HoleHullCheck &hull_check,const HoleDistanceQuery &distance,
    std::chrono::steady_clock::time_point deadline);

// 麦轮底盘接入：保留合法折线后优先使用原样条优化，失败才局部圆滑/折线；必经点不移动。
// 硬曲率约束须使用 optimizeHoleConnection，不允许经由此接口绕过。
HoleOptimizedConnection planFeasibleHoleApproach(nav_core::HolePoint start,
    const std::vector<nav_core::HolePoint> &waypoints,std::optional<nav_core::HolePoint> initial_tangent,
    std::optional<nav_core::HolePoint> final_tangent,const HoleConnectionOptimizationParams &params,
    const HoleConnectionSearchParams &search,const nav_msgs::msg::OccupancyGrid &map,
    const nav_core::HoleSegmentCheck &collision,const HoleHullCheck &hull_check,const HoleDistanceQuery &distance,
    std::chrono::steady_clock::time_point deadline);

// 覆盖凸包内部接触的栅格，供连续样条校验使用。
nav_core::HolePassageCheck checkHoleMapHull(const nav_msgs::msg::OccupancyGrid &map,double threshold,
    const std::vector<nav_core::HolePoint> &controls);

} // namespace nav_components
