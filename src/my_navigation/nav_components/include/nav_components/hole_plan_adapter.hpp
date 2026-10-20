#pragma once
#include "nav_components/hole_selected_snapshot.hpp"
#include "nav_components/terrain_region_map.hpp"
#include "nav_core/hole_execution_types.hpp"
namespace nav_components {
// 不改写几何路线；将最终选择记录转为带身份的执行快照。
nav_core::hole_exec::Plan makeHoleExecutionPlan(const HoleSelectedSnapshot& snapshot,
    const TerrainRegionMap::ConstPtr& terrain,const nav_core::hole_exec::Config& config,
    const std::string& session,const std::string& goal,std::uint64_t id,
    const nav_core::hole_exec::Plan* previous,double previous_progress,std::uint64_t& next_uid);
}
