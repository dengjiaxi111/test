#pragma once

#include "nav_components/terrain_region_map.hpp"
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <string>

namespace nav_components {

// Extend the confirmed rectangle at edges pair and pair+2 only. Width is
// unchanged. The two distances refer to stable edge IDs, not robot direction.
bool buildHoleClearPolygon(const TerrainRegion &region, double before_distance,
                           double after_distance, std::vector<TerrainPoint> &polygon,
                           std::string *error = nullptr);

bool holeClearCellIndices(const nav_msgs::msg::OccupancyGrid &map,
                          const TerrainRegion &region, double before_distance,
                          double after_distance, std::vector<int> &indices,
                          std::string *error = nullptr);

// Change occupied cells in the startup static map only; preserve unknown cells.
// Validate all holes before any mutation. Never writes map/terrain files.
bool clearHoleApproachAreas(nav_msgs::msg::OccupancyGrid &map,
                            const TerrainRegionMap &terrain,
                            double before_distance, double after_distance,
                            std::size_t *changed_cells = nullptr,
                            std::string *error = nullptr);

}  // namespace nav_components
