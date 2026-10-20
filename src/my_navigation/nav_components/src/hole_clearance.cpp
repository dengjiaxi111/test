#include "nav_components/hole_clearance.hpp"
#include <nav_core/hole_geometry.hpp>

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace nav_components
{
namespace
{
double cross(double ax, double ay, double bx, double by)
{
  return ax * by - ay * bx;
}

bool inside(const std::vector<TerrainPoint> &polygon, double x, double y)
{
  bool positive = false, negative = false;
  for (std::size_t i = 0; i < polygon.size(); ++i)
  {
    const auto &a = polygon[i];
    const auto &b = polygon[(i + 1) % polygon.size()];
    const double value = cross(b.x - a.x, b.y - a.y, x - a.x, y - a.y);
    positive |= value > 1e-10;
    negative |= value < -1e-10;
  }
  return !(positive && negative);
}
}  // namespace

bool buildHoleClearPolygon(const TerrainRegion &region, double first_distance,
                           double opposite_distance,
                           std::vector<TerrainPoint> &polygon,
                           std::string *error)
{
  polygon.clear();
  try
  {
    if (!std::isfinite(first_distance) || !std::isfinite(opposite_distance) ||
        first_distance < 0.0 || opposite_distance < 0.0)
      throw std::runtime_error("两侧延伸距离必须是有限的非负数");
    nav_core::HoleGeometryInput input;
    input.id = region.id; input.frame_id = region.frame_id;
    input.passable_edge_pair = region.passable_edge_pair;
    for (auto p : region.polygon) input.polygon.push_back({p.x, p.y});
    if (region.type != "low_clearance" && region.type != "2")
      throw std::runtime_error("Static clearing requires a low_clearance region");
    nav_core::HoleGeometryParams params;
    // Retain static clearing's stricter rectangle tolerance. Previewing a
    // mildly skewed rectangle must not silently widen static clearing policy.
    params.rectangle_angle_tolerance_deg = std::asin(0.005) * 180.0 / 3.14159265358979323846;
    params.parallel_tolerance_deg = params.rectangle_angle_tolerance_deg * 2;
    params.min_long_short_ratio = 1.0;
    nav_core::HoleTraversalDistances distances{0, 0, 0, 0};
    const auto geometry = nav_core::buildHoleGeometry(input, params, distances);
    if (!geometry.valid) throw std::runtime_error(geometry.reason);
    const int pair = region.passable_edge_pair;
    std::vector<TerrainPoint> extended;
    for (int i = 0; i < 4; ++i) {
      const auto &p = geometry.polygon[(i + pair) % 4];
      extended.push_back({p.x, p.y});
    }
    const auto tangent = geometry.directions.front().tangent;
    const double tx = tangent.x, ty = tangent.y;
    for (int i = 0; i < 4; ++i)
    {
      const double offset = i < 2 ? -first_distance : opposite_distance;
      extended[i].x += offset * tx;
      extended[i].y += offset * ty;
      if (!std::isfinite(extended[i].x) || !std::isfinite(extended[i].y))
        throw std::runtime_error("清除范围坐标溢出");
    }
    polygon = std::move(extended);
    return true;
  }
  catch (const std::exception &exception)
  {
    if (error) *error = exception.what();
    return false;
  }
}

bool holeClearCellIndices(const nav_msgs::msg::OccupancyGrid &map,
                          const TerrainRegion &region, double first_distance,
                          double opposite_distance, std::vector<int> &indices,
                          std::string *error)
{
  indices.clear();
  std::vector<TerrainPoint> polygon;
  if (!buildHoleClearPolygon(region, first_distance, opposite_distance, polygon, error))
    return false;
  try
  {
    if (map.header.frame_id != region.frame_id)
      throw std::runtime_error("洞口与地图的坐标系不一致");
    const auto &info = map.info;
    const std::size_t count = static_cast<std::size_t>(info.width) * info.height;
    if (info.width == 0 || info.height == 0 || count != map.data.size() ||
        count > static_cast<std::size_t>(std::numeric_limits<int>::max()) ||
        !std::isfinite(info.resolution) || info.resolution <= 0.0f ||
        !std::isfinite(info.origin.position.x) || !std::isfinite(info.origin.position.y))
      throw std::runtime_error("地图尺寸、分辨率或原点无效");
    const auto &q = info.origin.orientation;
    const double norm = std::hypot(q.z, q.w);
    if (!std::isfinite(q.x) || !std::isfinite(q.y) || !std::isfinite(norm) ||
        norm < 1e-12 || std::abs(q.x) > 1e-6 || std::abs(q.y) > 1e-6)
      throw std::runtime_error("地图原点旋转必须是有效的平面旋转");
    const double yaw = 2.0 * std::atan2(q.z, q.w);
    const double cosine = std::cos(yaw), sine = std::sin(yaw);
    // Convert the polygon into map-local metres, including a rotated origin.
    double xmin = std::numeric_limits<double>::infinity(), ymin = xmin;
    double xmax = -xmin, ymax = -xmin;
    for (auto &p : polygon)
    {
      const double dx = p.x - info.origin.position.x, dy = p.y - info.origin.position.y;
      p.x = cosine * dx + sine * dy;
      p.y = -sine * dx + cosine * dy;
      if (!std::isfinite(p.x) || !std::isfinite(p.y))
        throw std::runtime_error("清除范围坐标转换溢出");
      xmin = std::min(xmin, p.x); xmax = std::max(xmax, p.x);
      ymin = std::min(ymin, p.y); ymax = std::max(ymax, p.y);
    }
    // Clamp in floating point before casting, including polygons outside the map.
    const auto bound = [&info](double value, uint32_t limit) {
      return static_cast<int>(std::clamp(std::floor(value / info.resolution),
                                        0.0, static_cast<double>(limit)));
    };
    const int x0 = bound(xmin, info.width), x1 = bound(xmax, info.width);
    const int y0 = bound(ymin, info.height), y1 = bound(ymax, info.height);
    for (int y = y0; y <= y1 && y < static_cast<int>(info.height); ++y)
      for (int x = x0; x <= x1 && x < static_cast<int>(info.width); ++x)
      {
        const int index = y * static_cast<int>(info.width) + x;
        if (map.data[index] > 0 &&
            inside(polygon, (x + 0.5) * info.resolution, (y + 0.5) * info.resolution))
          indices.push_back(index);
      }
    return true;
  }
  catch (const std::exception &exception)
  {
    if (error) *error = exception.what();
    return false;
  }
}
bool clearHoleApproachAreas(nav_msgs::msg::OccupancyGrid &map,
                            const TerrainRegionMap &terrain,
                            double before_distance, double after_distance,
                            std::size_t *changed_cells, std::string *error) {
    if (changed_cells) *changed_cells = 0;
    if (!std::isfinite(before_distance) || !std::isfinite(after_distance) ||
        before_distance < 0.0 || after_distance < 0.0) {
        if (error) *error = "hole_clearance distances must be finite and non-negative";
        return false;
    }
    // Validate every selected hole before changing any cell.
    std::vector<int> all_indices;
    for (const auto &hole : terrain.getRegions()) {
        if (hole.type != "low_clearance" && hole.type != "2") continue;
        const auto traversal = hole.raw["traversal"];
        try {
            if (traversal && traversal["enabled"] && !traversal["enabled"].as<bool>()) continue;
            if (hole.passable_edge_pair < 0) {
                if (traversal && traversal["passable_edges"]) {
                    if (error) *error = "hole " + hole.id + ": invalid passable_edges";
                    return false;
                }
                continue;  // An unconfirmed hole never authorizes clearing.
            }
            double before = before_distance, after = after_distance;
            const auto config = traversal ? traversal["static_clearance"] : YAML::Node(YAML::NodeType::Undefined);
            if (config) {
                if (!config.IsMap()) throw std::runtime_error("static_clearance must be a mapping");
                if (config["enabled"] && !config["enabled"].as<bool>()) continue;
                if (config["before_distance"]) before = config["before_distance"].as<double>();
                if (config["after_distance"]) after = config["after_distance"].as<double>();
            }
            std::vector<int> indices;
            std::string reason;
            if (!holeClearCellIndices(map, hole, before, after, indices, &reason)) {
                if (error) *error = "hole " + hole.id + ": " + reason;
                return false;
            }
            all_indices.insert(all_indices.end(), indices.begin(), indices.end());
        } catch (const std::exception &e) {
            if (error) *error = "hole " + hole.id + ": " + e.what();
            return false;
        }
    }
    std::sort(all_indices.begin(), all_indices.end());
    all_indices.erase(std::unique(all_indices.begin(), all_indices.end()), all_indices.end());
    for (const int index : all_indices) map.data[index] = 0;
    if (changed_cells) *changed_cells = all_indices.size();
    return true;
}
}  // namespace nav_components
