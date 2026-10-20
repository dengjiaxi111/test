#pragma once

#include <nav_core/hole_passage.hpp>
#include <chrono>

namespace nav_components {

struct HoleConnectionSearchParams {
    double max_curvature=1.0;       // 搜索片段最大曲率（1/米），不涉及车体朝向
    double state_resolution=0.1;    // 搜索位置状态分辨率（米）
    int heading_bins=72;            // 运动方向离散数量
    double primitive_length=0.2;    // 每个运动片段的长度（米）
    double sample_resolution=0.025; // 输出折线最大采样间距（米）
    int max_expansions=20000;       // 每次连接搜索最多展开的状态数量
    double timeout=0.5;             // 每次连接搜索时间上限（秒）
};
bool validHoleConnectionSearchParams(const HoleConnectionSearchParams &params);

struct HoleConnectionSearchResult {
    nav_core::HolePassageCheck check;
    std::vector<nav_core::HolePoint> points;
    int expansions=0;
};

// 带运动方向及必经点阶段的搜索；在预算内比较路线长度，OMPL 提供 Dubins 终端连接。
HoleConnectionSearchResult searchHoleConnection(
    nav_core::HolePoint start, nav_core::HolePoint initial_tangent,
    const std::vector<nav_core::HolePoint> &waypoints,
    const std::optional<nav_core::HolePoint> &final_tangent,
    const HoleConnectionSearchParams &params,
    const nav_core::HoleSegmentCheck &collision,
    std::chrono::steady_clock::time_point deadline);

} // namespace nav_components
