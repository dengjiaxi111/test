#pragma once

#include "nav_components/terrain_region_map.hpp"
#include "nav_components/planner/hole_connection_search.hpp"
#include "nav_components/planner/hole_connection_optimizer.hpp"
#include <nav_core/hole_geometry_yaml.hpp>
#include <nav_core/hole_passage.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/path.hpp>
#include <rclcpp/rclcpp.hpp>
#include <list>
#include <set>
#include <map>
#include <visualization_msgs/msg/marker_array.hpp>

namespace nav_components {

// 精确遍历线段触及的栅格；未知、越界及错误地图均拒绝。
nav_core::HolePassageCheck checkHoleMapSegment(const nav_msgs::msg::OccupancyGrid &map,
    double obstacle_threshold, nav_core::HolePoint a, nav_core::HolePoint b);

struct HoleRouteAttempt {
    nav_core::HolePassageCandidate passage;
    nav_core::HolePoint A,D; // 旧配置的几何点；人工范围仅为内部 S/T 别名，真实 A/D 读取最终路径事件。
    double prepare_distance=0;
    nav_core::HolePassageCheck check;
    int expansions=0;
    double path_length=0;
    double maximum_curvature=0;
    bool optimized=false,manual_range=false;
    std::string approach_method;
    std::string approach_smoothing_failure;
    double seed_length=0,optimization_ms=0;
    std::vector<nav_core::HolePoint> seed,approach,departure,interior;
    std::vector<nav_core::HolePoint> points;
};

struct HolePlanningStatistics {
    double total_ms=0, geometry_ms=0, connectivity_ms=0, candidate_ms=0;
    double connection_search_ms=0, curve_fit_ms=0, curve_validation_ms=0;
    double candidate_validation_ms=0, final_validation_ms=0, cache_lookup_ms=0;
    double first_valid_ms=-1, post_first_valid_ms=0;
    int candidates=0, optimized_edges=0, failed_edges=0, timeout_edges=0;
    int iterations=0, fits=0, cache_hits=0, cache_rejected=0, connectivity_rejected=0;
    std::string stop_reason="NOT_STARTED";
};

// 累加互不重叠的分项范围；总耗时另行记录，不与分项重复相加。
struct HoleTimingScope {
    double &target;
    std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
    explicit HoleTimingScope(double &value):target(value) {}
    ~HoleTimingScope() {target+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-begin).count();}
};

// 单洞/多洞通行搜索、受约束连续曲线优化与独立校验。
class HolePassagePlanner {
public:
    void initialize(rclcpp::Node *node);
    void setExecutionActivePredicate(std::function<bool()> predicate) { execution_active_=std::move(predicate); }
    void setTerrain(TerrainRegionMap::ConstPtr terrain, bool preserve_commitment=false) { terrain_=std::move(terrain); if(!preserve_commitment) {previous_route_=nav_msgs::msg::Path();committed_passages_.clear();committed_departure_events_.clear();event_path_=nav_msgs::msg::Path();} ++terrain_revision_; clearConnectionCache(); clearDiagnostics(); }
    using NormalSegmentPlanner=std::function<HoleOptimizedConnection(nav_core::HolePoint,nav_core::HolePoint,
        nav_core::HolePoint,const nav_msgs::msg::OccupancyGrid &,double,const nav_core::HoleSegmentCheck &,
        const HoleHullCheck &,std::chrono::steady_clock::time_point)>;
    void setNormalSegmentPlanner(NormalSegmentPlanner planner) {normal_segment_planner_=std::move(planner);}
    void setDistanceQuery(HoleDistanceQuery query) { distance_query_=std::move(query); }
    nav_core::HolePassageCheck validateTerrainUpdate(TerrainRegionMap::ConstPtr next,
        std::optional<nav_core::HolePoint> executing_position=std::nullopt) const;
    void setBlockedHoleIds(std::set<std::string> ids) { blocked_holes_=std::move(ids);clearConnectionCache(); }
    bool enabled() const;
    bool cacheEnabled() const { return config_.cache_enabled; }
    const HolePlanningStatistics &statistics() const { return statistics_; }
    void markWholePathReuse() { statistics_.stop_reason="WHOLE_PATH_CACHE"; }
    void resetStatistics() { statistics_=HolePlanningStatistics{}; }
    void clearConnectionCache() { connection_cache_.clear(); geometry_cache_.clear(); connectivity_map_.reset(); }
    // 用于同时使路径缓存和候选缓存失效，读取已提交的参数。
    bool refreshConfiguration();
    std::uint64_t configurationRevision() const { return configuration_revision_; }
    std::uint64_t terrainRevision() const { return terrain_revision_; }
    void buildCandidates(const nav_msgs::msg::Path &seed,
                         const nav_msgs::msg::OccupancyGrid &map, double threshold);
    nav_core::HolePassageCheck validatePath(const nav_msgs::msg::Path &path,
                         const nav_msgs::msg::OccupancyGrid &map, double threshold, bool publish_diagnostics=true,
                         std::chrono::steady_clock::time_point deadline=std::chrono::steady_clock::time_point::max());
    nav_core::HolePassageCheck planRoute(const nav_msgs::msg::Path &seed,
                         nav_core::HolePoint start, nav_core::HolePoint goal,
                         const nav_msgs::msg::OccupancyGrid &map, double threshold,
                         nav_msgs::msg::Path &route, bool &constrained,
                         std::optional<nav_core::HolePoint> start_velocity=std::nullopt,
                         std::chrono::steady_clock::time_point deadline=std::chrono::steady_clock::time_point::max());
    const std::vector<nav_core::HolePassageCandidate> &candidates() const { return candidates_; }
    const std::vector<nav_core::HolePassageCandidate> &pathPassages() const { return path_passages_; }
    const std::vector<nav_core::HolePreparationEvent> &preparationEvents() const {return preparation_events_;}
    const std::vector<nav_core::HoleDepartureEvent> &departureEvents() const {return departure_events_;}
    const std::vector<HoleRouteAttempt> &routeAttempts() const { return route_attempts_; }
    // 只读已选路线元数据，不使用包含失败尝试的调试数组。
    const std::vector<HoleRouteAttempt>& selectedRoute() const {return selected_route_;}
    void clearDiagnostics();
private:
    nav_core::HolePassageCheck planSingleRoute(const nav_msgs::msg::Path &seed,
        nav_core::HolePoint start,nav_core::HolePoint goal,const nav_msgs::msg::OccupancyGrid &map,
        double threshold,nav_msgs::msg::Path &route,bool &constrained,std::optional<nav_core::HolePoint> start_velocity,
        std::chrono::steady_clock::time_point deadline);
    struct Configuration {
        bool enabled=false;
        bool normal_departure=false;
        std::string approach_policy="continuous";
        bool feasible_approach=false;
        nav_core::HolePassageMode mode=nav_core::HolePassageMode::Free;
        nav_core::HolePreviewConfiguration preview;
        nav_core::HolePassageValidationParams validation;
        HoleConnectionSearchParams search;
        HoleConnectionOptimizationParams optimization;
        bool search_prepare_distance=true;
        double prepare_min=1.0,prepare_max=3.0,prepare_step=0.25;
        double planning_timeout=5.0;
        double edge_step=0.1,angle_step_deg=15.0,max_angle_deg=60.0;
        double min_motion_speed=0.05;
        int max_candidates=64;
        bool global_enabled=true;
        bool responsive=false,cache_enabled=false;
        int shortlist_size=3,cache_max_entries=128;
        double improvement_timeout=0.15,relative_cost_gap=0.1;
        int graph_max_nodes=192,graph_max_expansions=256,graph_max_passages=8;
        double route_curvature_weight=0.002,route_clearance_weight=0.2,prepare_deviation_weight=0.1;
    };
    HoleOptimizedConnection normalDeparture(nav_core::HolePoint start,nav_core::HolePoint tangent,
        nav_core::HolePoint goal,const nav_msgs::msg::OccupancyGrid &map,double threshold,
        const nav_core::HoleSegmentCheck &collision,const HoleHullCheck &hull,
        std::chrono::steady_clock::time_point deadline);
    NormalSegmentPlanner normal_segment_planner_;
    HolePlanningStatistics statistics_;
    std::uint64_t terrain_revision_=0;
    std::list<std::pair<std::string,HoleOptimizedConnection>> connection_cache_;
    mutable std::map<std::string,std::pair<nav_core::HoleGeometryPreview,nav_core::HoleTraversalDistances>> geometry_cache_;
    nav_msgs::msg::OccupancyGrid::SharedPtr connectivity_map_;
    double connectivity_threshold_=0;
    std::vector<int> connectivity_components_;
    Configuration readConfiguration(const std::vector<rclcpp::Parameter> &overrides={}) const;
    nav_core::HoleGeometryPreview geometry(const TerrainRegion &region,
                    nav_core::HoleTraversalDistances &distances, const nav_core::HolePoint *start) const;
    void updateDepartureEvents(const nav_msgs::msg::Path &message,bool commit);
    void publishDiagnostics();
    rclcpp::Node *node_=nullptr;
    TerrainRegionMap::ConstPtr terrain_;
    Configuration config_;
    std::set<std::string> blocked_holes_;
    std::string configuration_signature_;
    std::uint64_t configuration_revision_=0;
    std::vector<nav_core::HolePassageCandidate> candidates_,path_passages_;
    std::vector<HoleRouteAttempt> route_attempts_,selected_route_;
    std::vector<nav_core::HolePreparationEvent> preparation_events_;
    std::vector<nav_core::HoleDepartureEvent> departure_events_,committed_departure_events_;
    nav_msgs::msg::Path event_path_;
    std::uint64_t path_revision_=0;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr publisher_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr route_publisher_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameter_callback_;
    rclcpp::TimerBase::SharedPtr configuration_timer_;
    std::function<bool()> execution_active_;
    HoleDistanceQuery distance_query_;
    nav_msgs::msg::Path previous_route_;
    std::vector<nav_core::HolePassageCandidate> committed_passages_;
};
} // namespace nav_components
