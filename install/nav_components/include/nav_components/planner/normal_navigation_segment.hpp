#pragma once

#include "nav_components/planner/path_smoother.hpp"

namespace nav_components {
// 可复用的普通自由段接口。种子搜索可以注入现有普通 A*；独立使用时采用栅格 A*。
using NormalSegmentSeedSearch=std::function<bool(nav_core::HolePoint,nav_core::HolePoint,
    std::vector<nav_core::HolePoint> &,int &)>;
HoleOptimizedConnection planNormalNavigationSegment(nav_core::HolePoint start,
    nav_core::HolePoint tangent,nav_core::HolePoint goal,PathSmoother &smoother,
    const nav_msgs::msg::OccupancyGrid &map,double threshold,
    const nav_core::HoleSegmentCheck &collision,const HoleHullCheck &hull,
    double sample_resolution,int expansion_budget,
    std::chrono::steady_clock::time_point deadline,
    const NormalSegmentSeedSearch &search={},std::optional<double> maximum_curvature=std::nullopt);
} // namespace nav_components
