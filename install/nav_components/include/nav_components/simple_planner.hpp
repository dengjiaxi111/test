// nav_components/include/nav_components/simple_planner.hpp
// A* 规划器 + B 样条平滑与优化

#pragma once

#include <limits>
#include <set>
#include <memory>
#include <queue>
#include <string>
#include <vector>

#include <nav_core/planner_base.hpp>
#include <nav_core/special_terrain_constraint.hpp>
#include "nav_components/terrain_region_map.hpp"
#include "nav_components/hole_passage_planner.hpp"
#include "nav_components/hole_selected_snapshot.hpp"
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

#include "nav_components/planner/path_smoother.hpp"

namespace nav_components {

class LayeredMapManager;

class SimplePlanner : public nav_core::PlannerBase {
public:
    void initialize(rclcpp::Node* node) override;
    void setMap(nav_core::MapInterface::Ptr map) override;

    bool plan(const geometry_msgs::msg::PoseStamped& start,
              const geometry_msgs::msg::PoseStamped& goal,
              nav_msgs::msg::Path& path) override;

    // 注入可选的特殊地形规划约束。默认未设置，不影响普通 A*/B 样条规划。
    void setSpecialTerrainConstraint(
        nav_core::SpecialTerrainConstraint::Ptr constraint);

    // Read-only semantic data for future constraints; this does not change A*.
    void setTerrainRegionMap(TerrainRegionMap::ConstPtr regions,bool preserve_commitment=false);
    nav_core::HolePassageCheck validateTerrainUpdate(TerrainRegionMap::ConstPtr regions,
        std::optional<nav_core::HolePoint> position=std::nullopt) const {
        return hole_passage_planner_.validateTerrainUpdate(std::move(regions),position);
    }
    const TerrainRegionMap::ConstPtr& terrainRegionMap() const { return terrain_regions_; }
    void setHoleExecutionActivePredicate(std::function<bool()> predicate) {
        hole_passage_planner_.setExecutionActivePredicate(std::move(predicate));
    }
    void setStartVelocity(nav_core::HolePoint velocity) { start_velocity_=velocity; }

    bool validatePath(const nav_msgs::msg::Path& path);

    bool worldToMap(double wx, double wy, int& mx, int& my);
    void mapToWorld(int mx, int my, double& wx, double& wy);
    bool isValid(int x, int y);
    HoleSelectedSnapshot freezeHoleExecutionPlan(const nav_msgs::msg::Path& path);
    void setBlockedHoleIds(const std::set<std::string>& ids) { blocked_holes_=ids;clearCache(); }
    void clearCache();
    void invalidateMapCaches();
    const HolePlanningStatistics &holeStatistics() const { return hole_passage_planner_.statistics(); }
    const std::vector<nav_core::HolePreparationEvent> &holePreparationEvents() const {return hole_passage_planner_.preparationEvents();}
    const std::vector<nav_core::HoleDepartureEvent> &holeDepartureEvents() const {return hole_passage_planner_.departureEvents();}
    void clearHoleConnectionCache() { hole_passage_planner_.clearConnectionCache(); }

private:
    struct Node {
        int x;
        int y;
        double g;
        double h;
        Node* parent = nullptr;

        double f() const { return g + h; }
    };

    double getCost(int x, int y);
    double heuristic(int x1, int y1, int x2, int y2);

    bool goalChanged(const geometry_msgs::msg::PoseStamped& new_goal);
    nav_msgs::msg::Path prunePath(
        const nav_msgs::msg::Path& path,
        const geometry_msgs::msg::PoseStamped& current_pose);

    bool runAstar(int sx, int sy, int gx, int gy,
                  const std_msgs::msg::Header& header,
                  nav_msgs::msg::Path& path,
                  int* fail_best_x = nullptr,
                  int* fail_best_y = nullptr,
                  const nav_core::HoleSegmentCheck &segment_check={},
                  int *expansion_count=nullptr);

    bool findNearestFreeCell(int cx, int cy, int& fx, int& fy,
                             int max_radius = 50);

    std::set<std::string> blocked_holes_;
    double last_removed_prefix_=0;
    HoleSelectedSnapshot cached_selection_;
    rclcpp::Node* node_ = nullptr;

    nav_msgs::msg::OccupancyGrid::SharedPtr grid_map_;
    std::shared_ptr<LayeredMapManager> map_manager_;
    nav_core::SpecialTerrainConstraint::Ptr special_terrain_constraint_;
    TerrainRegionMap::ConstPtr terrain_regions_;
    HolePassagePlanner hole_passage_planner_;
    std::uint64_t hole_configuration_revision_=0;
    std::optional<nav_core::HolePoint> start_velocity_;

    int8_t obstacle_threshold_ = 99;
    double cost_weight_ = 0.5;

    double resolution_ = 0.05;
    double origin_x_ = 0.0;
    double origin_y_ = 0.0;
    int width_ = 0;
    int height_ = 0;

    PathSmoother smoother_;
    bool enable_smooth_ = true;

    bool cached_path_constrained_=false;
    std::chrono::steady_clock::time_point hole_request_deadline_=std::chrono::steady_clock::time_point::max();
    nav_msgs::msg::Path cached_path_;
    geometry_msgs::msg::PoseStamped cached_goal_;
    double goal_change_tolerance_ = 0.2;
    double obstacle_check_threshold_ = 95;
    double esdf_warn_min_safe_dist_ = 0.12;
    double start_deviation_threshold_ = 1.0;
    int astar_max_attempts_ = 2;
    int astar_max_iterations_ = 0;
    int astar_threshold_step_ = 10;
    bool enable_path_cache_ = true;
    bool enable_auto_prune_ = true;
    double prune_distance_ = 0.5;
    bool publish_astar_raw_path_ = true;
    bool allow_raw_fallback_on_smooth_fail_ = false;

    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr astar_raw_path_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr
        ctrl_pts_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr
        plan_failure_pub_;

    bool publish_failure_debug_markers_ = true;
    double failure_marker_scale_ = 0.14;
    bool has_last_validate_fail_point_ = false;
    double last_validate_fail_x_ = 0.0;
    double last_validate_fail_y_ = 0.0;

    struct FailurePoint {
        double x = 0.0;
        double y = 0.0;
        std::string label;
        float r = 1.0f;
        float g = 0.0f;
        float b = 0.0f;
    };

    void publishControlPoints(
        const std::vector<Eigen::Vector2d>& ctrl_pts,
        const std::string& frame_id);
    void publishPlanningFailureMarkers(
        const std::string& frame_id,
        const std::vector<FailurePoint>& points);
    void clearPlanningFailureMarkers(const std::string& frame_id);
};

}  // namespace nav_components
