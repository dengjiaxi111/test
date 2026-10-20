#include "nav_components/hole_passage_planner.hpp"
#include <sstream>
#include <iomanip>
#include <limits>
#include "nav_components/planner/normal_navigation_segment.hpp"
#include <nav_core/hole_grid_collision.hpp>

namespace nav_components {
using namespace nav_core;

HolePassageCheck checkHoleMapSegment(const nav_msgs::msg::OccupancyGrid &map,
        double threshold,HolePoint a,HolePoint b) {
    return nav_core::checkHoleGridSegment(map,threshold,a,b);
}

void HolePassagePlanner::initialize(rclcpp::Node *node) {
    node_=node;
    // 几何预览与规划器共享参数；支持独立初始化以便离线测试。
    const auto boolean=[&](const std::string &name,bool value) {
        if(!node_->has_parameter(name)) node_->declare_parameter(name,value);
    };
    const auto number=[&](const std::string &name,double value) {
        if(!node_->has_parameter(name)) node_->declare_parameter(name,value);
    };
    const auto integer=[&](const std::string &name,int value) {
        if(!node_->has_parameter(name)) node_->declare_parameter(name,value);
    };
    boolean("hole_planner.enabled",false);
    boolean("hole_planner.publish_debug_markers",true);
    boolean("hole_planner.use_global_distances",false);
    if(!node_->has_parameter("hole_planner.mode")) node_->declare_parameter("hole_planner.mode","free");
    number("hole_planner.geometry.rectangle_angle_tolerance_deg",3.0);
    number("hole_planner.geometry.parallel_tolerance_deg",3.0);
    number("hole_planner.geometry.min_long_short_ratio",1.2);
    number("hole_planner.geometry.max_centerline_difference",0.02);
    number("hole_planner.geometry.max_axis_difference_deg",3.0);
    number("hole_planner.approach.prepare_distance",1.5);
    number("hole_planner.approach.entry_straight_length",0.8);
    number("hole_planner.departure.exit_straight_length",0.5);
    number("hole_planner.departure.departure_distance",0.8);
    if(!node_->has_parameter("hole_planner.departure.planning_policy"))
        node_->declare_parameter("hole_planner.departure.planning_policy","legacy_constrained");
    number("hole_planner.validation.waypoint_tolerance",0.02);
    number("hole_planner.validation.tangent_tolerance_deg",3.0);
    number("hole_planner.validation.side_margin",0.0);
    boolean("hole_planner.approach.search_prepare_distance",true);
    number("hole_planner.approach.prepare_distance_min",1.0);
    number("hole_planner.approach.prepare_distance_max",3.0);
    number("hole_planner.approach.prepare_distance_step",0.25);
    boolean("hole_planner.optimization.enabled",true);
    number("hole_planner.connection.max_curvature",1.0);
    boolean("hole_planner.connection.enforce_max_curvature",false);
    number("hole_planner.connection.smoothing_timeout",0.2);
    if(!node_->has_parameter("hole_planner.connection.approach_policy"))
        node_->declare_parameter("hole_planner.connection.approach_policy","continuous");
    integer("hole_planner.optimization.max_iterations",100);
    number("hole_planner.optimization.control_spacing",0.3);
    number("hole_planner.optimization.length_weight",1.0);
    number("hole_planner.optimization.curvature_weight",0.02);
    number("hole_planner.optimization.curvature_change_weight",0.002);
    number("hole_planner.optimization.obstacle_weight",5.0);
    number("hole_planner.optimization.reference_weight",0.1);
    number("hole_planner.optimization.safe_distance",0.3);
    number("hole_planner.search.state_resolution",0.1);
    integer("hole_planner.search.heading_bins",72);
    number("hole_planner.search.primitive_length",0.2);
    number("hole_planner.search.sample_resolution",0.025);
    integer("hole_planner.search.max_expansions",20000);
    number("hole_planner.search.connection_timeout",0.5);
    number("hole_planner.search.planning_timeout",5.0);
    number("hole_planner.search.min_motion_speed",0.05);
    number("hole_planner.free.edge_step",0.1);
    number("hole_planner.free.angle_step_deg",15.0);
    number("hole_planner.free.max_angle_deg",60.0);
    integer("hole_planner.free.max_candidates",64);
    boolean("hole_planner.global.enabled",true);
    if(!node_->has_parameter("hole_planner.global.planning_policy")) node_->declare_parameter("hole_planner.global.planning_policy","compare");
    integer("hole_planner.global.shortlist_size",3);
    number("hole_planner.global.improvement_timeout",0.15);
    number("hole_planner.global.relative_cost_gap",0.1);
    boolean("hole_planner.cache.enabled",false);
    integer("hole_planner.cache.max_entries",128);
    number("hole_planner.optimization.relative_improvement_tolerance",0.001);
    integer("hole_planner.optimization.stagnation_iterations",5);
    integer("hole_planner.global.max_nodes",192);
    integer("hole_planner.global.max_expansions",256);
    integer("hole_planner.global.max_passages",8);
    number("hole_planner.global.curvature_weight",0.002);
    number("hole_planner.global.clearance_weight",0.2);
    number("hole_planner.global.prepare_deviation_weight",0.1);
    config_=readConfiguration();
    publisher_=node_->create_publisher<visualization_msgs::msg::MarkerArray>(
        "hole_passage_markers",rclcpp::QoS(1).transient_local().reliable());
    route_publisher_=node_->create_publisher<nav_msgs::msg::Path>("plan_hole_raw",rclcpp::QoS(1).transient_local());
    parameter_callback_=node_->add_on_set_parameters_callback([this](const auto &batch) {
        rcl_interfaces::msg::SetParametersResult result; result.successful=true;
        try {
            readConfiguration(batch);
            if(execution_active_ && execution_active_()) for(const auto &parameter:batch) {
                const auto &name=parameter.get_name();
                const bool distance=name=="hole_planner.approach.prepare_distance" ||
                    name=="hole_planner.approach.entry_straight_length" ||
                    name=="hole_planner.departure.exit_straight_length" ||
                    name=="hole_planner.departure.departure_distance" || name=="hole_planner.use_global_distances";
                if(name.rfind("hole_planner.",0)==0 && name!="hole_planner.publish_debug_markers" && name!="hole_planner.cache.enabled" && !distance &&
                   parameter!=node_->get_parameter(name))
                    throw std::invalid_argument("Navigation is active; change hole planning parameters after stopping the current goal");
            }
        } catch(const std::exception &e) {result.successful=false;result.reason=e.what();}
        return result;
    });
    refreshConfiguration();
    configuration_timer_=node_->create_wall_timer(std::chrono::milliseconds(100),[this]() {
        refreshConfiguration();
    });
}
HolePassagePlanner::Configuration HolePassagePlanner::readConfiguration(
        const std::vector<rclcpp::Parameter> &overrides) const {
    const auto get=[&](const std::string &name) {
        const auto found=std::find_if(overrides.begin(),overrides.end(),[&](const auto &p){return p.get_name()==name;});
        return found==overrides.end()?node_->get_parameter(name):*found;
    };
    const auto integer=[&](const std::string &name,int minimum,int maximum) {
        const auto value=get(name).as_int();
        if(value<minimum||value>maximum) throw std::invalid_argument("Invalid integer parameter: "+name);
        return static_cast<int>(value);
    };
    Configuration c;
    c.enabled=get("hole_planner.enabled").as_bool();
    c.mode=holePassageMode(get("hole_planner.mode").as_string());
    const auto departure_policy=get("hole_planner.departure.planning_policy").as_string();
    if(departure_policy!="normal_navigation"&&departure_policy!="legacy_constrained")
        throw std::invalid_argument("Invalid hole departure planning_policy");
    c.normal_departure=departure_policy=="normal_navigation";
    c.preview.publish_debug_markers=get("hole_planner.publish_debug_markers").as_bool();
    c.preview.use_global_distances=get("hole_planner.use_global_distances").as_bool();
    auto &g=c.preview.geometry; auto &d=c.preview.distances; auto &v=c.validation;
    g.rectangle_angle_tolerance_deg=get("hole_planner.geometry.rectangle_angle_tolerance_deg").as_double();
    g.parallel_tolerance_deg=get("hole_planner.geometry.parallel_tolerance_deg").as_double();
    g.min_long_short_ratio=get("hole_planner.geometry.min_long_short_ratio").as_double();
    g.max_centerline_difference=get("hole_planner.geometry.max_centerline_difference").as_double();
    g.max_axis_difference_deg=get("hole_planner.geometry.max_axis_difference_deg").as_double();
    d.prepare_distance=get("hole_planner.approach.prepare_distance").as_double();
    d.entry_straight_length=get("hole_planner.approach.entry_straight_length").as_double();
    d.exit_straight_length=get("hole_planner.departure.exit_straight_length").as_double();
    d.departure_distance=get("hole_planner.departure.departure_distance").as_double();
    v.waypoint_tolerance=get("hole_planner.validation.waypoint_tolerance").as_double();
    v.tangent_tolerance_deg=get("hole_planner.validation.tangent_tolerance_deg").as_double();
    v.side_margin=get("hole_planner.validation.side_margin").as_double();
    c.search_prepare_distance=get("hole_planner.approach.search_prepare_distance").as_bool();
    c.prepare_min=get("hole_planner.approach.prepare_distance_min").as_double();
    c.prepare_max=get("hole_planner.approach.prepare_distance_max").as_double();
    c.prepare_step=get("hole_planner.approach.prepare_distance_step").as_double();
    c.optimization.enabled=get("hole_planner.optimization.enabled").as_bool();
    c.optimization.max_iterations=integer("hole_planner.optimization.max_iterations",1,1000);
    c.optimization.control_spacing=get("hole_planner.optimization.control_spacing").as_double();
    c.optimization.length_weight=get("hole_planner.optimization.length_weight").as_double();
    c.optimization.curvature_weight=get("hole_planner.optimization.curvature_weight").as_double();
    c.optimization.curvature_change_weight=get("hole_planner.optimization.curvature_change_weight").as_double();
    c.optimization.obstacle_weight=get("hole_planner.optimization.obstacle_weight").as_double();
    c.optimization.reference_weight=get("hole_planner.optimization.reference_weight").as_double();
    c.optimization.safe_distance=get("hole_planner.optimization.safe_distance").as_double();
    c.search.max_curvature=get("hole_planner.connection.max_curvature").as_double();
    c.optimization.enforce_max_curvature=get("hole_planner.connection.enforce_max_curvature").as_bool();
    c.optimization.approach_smoothing_timeout=get("hole_planner.connection.smoothing_timeout").as_double();
    c.approach_policy=get("hole_planner.connection.approach_policy").as_string();
    if(c.approach_policy!="feasibility_first"&&c.approach_policy!="continuous")
        throw std::invalid_argument("hole_planner.connection.approach_policy must be feasibility_first or continuous");
    c.feasible_approach=c.approach_policy=="feasibility_first"&&!c.optimization.enforce_max_curvature;
    v.require_external_tangents=!c.feasible_approach;
    c.search.state_resolution=get("hole_planner.search.state_resolution").as_double();
    c.search.heading_bins=integer("hole_planner.search.heading_bins",16,720);
    c.search.primitive_length=get("hole_planner.search.primitive_length").as_double();
    c.search.sample_resolution=get("hole_planner.search.sample_resolution").as_double();
    c.search.max_expansions=integer("hole_planner.search.max_expansions",1,2000000);
    c.search.timeout=get("hole_planner.search.connection_timeout").as_double();
    c.planning_timeout=get("hole_planner.search.planning_timeout").as_double();
    c.min_motion_speed=get("hole_planner.search.min_motion_speed").as_double();
    c.edge_step=get("hole_planner.free.edge_step").as_double();
    c.angle_step_deg=get("hole_planner.free.angle_step_deg").as_double();
    c.max_angle_deg=get("hole_planner.free.max_angle_deg").as_double();
    c.max_candidates=integer("hole_planner.free.max_candidates",1,512);
    c.global_enabled=get("hole_planner.global.enabled").as_bool();
    const auto policy=get("hole_planner.global.planning_policy").as_string();
    if(policy!="responsive"&&policy!="compare") throw std::invalid_argument("Invalid hole planning_policy");
    c.responsive=c.optimization.responsive=policy=="responsive";
    c.shortlist_size=integer("hole_planner.global.shortlist_size",1,64);
    c.improvement_timeout=get("hole_planner.global.improvement_timeout").as_double();
    c.relative_cost_gap=get("hole_planner.global.relative_cost_gap").as_double();
    if(!std::isfinite(c.improvement_timeout)||c.improvement_timeout<0||c.improvement_timeout>10||
       !std::isfinite(c.relative_cost_gap)||c.relative_cost_gap<0||c.relative_cost_gap>1)
        throw std::invalid_argument("Invalid hole responsive budget or cost gap");
    c.cache_enabled=get("hole_planner.cache.enabled").as_bool();
    c.cache_max_entries=integer("hole_planner.cache.max_entries",1,4096);
    c.optimization.relative_improvement_tolerance=get("hole_planner.optimization.relative_improvement_tolerance").as_double();
    c.optimization.stagnation_iterations=integer("hole_planner.optimization.stagnation_iterations",1,1000);
    c.graph_max_nodes=integer("hole_planner.global.max_nodes",2,1024);
    c.graph_max_expansions=integer("hole_planner.global.max_expansions",1,10000);
    c.graph_max_passages=integer("hole_planner.global.max_passages",1,64);
    c.route_curvature_weight=get("hole_planner.global.curvature_weight").as_double();
    c.route_clearance_weight=get("hole_planner.global.clearance_weight").as_double();
    c.prepare_deviation_weight=get("hole_planner.global.prepare_deviation_weight").as_double();
    for(double weight:{c.route_curvature_weight,c.route_clearance_weight,c.prepare_deviation_weight})
        if(!std::isfinite(weight)||weight<0||weight>10000) throw std::invalid_argument("Invalid hole global cost weight");
    if(!validHoleGeometryParams(g)||!validHoleDistances(d)||!validHolePassageParams(v))
        throw std::invalid_argument("Invalid hole geometry, distances or validation tolerances");
    if(!validHoleOptimizationParams(c.optimization)||!validHoleConnectionSearchParams(c.search)||!std::isfinite(c.prepare_min)||c.prepare_min<0||
       !std::isfinite(c.prepare_max)||c.prepare_max<c.prepare_min||!std::isfinite(c.prepare_step)||c.prepare_step<=0||
       (c.prepare_max-c.prepare_min)/c.prepare_step>1000||
       !std::isfinite(c.planning_timeout)||c.planning_timeout<=0||
       !std::isfinite(c.min_motion_speed)||c.min_motion_speed<0||
       !std::isfinite(c.edge_step)||c.edge_step<=0||!std::isfinite(c.angle_step_deg)||c.angle_step_deg<=0||
       !std::isfinite(c.max_angle_deg)||c.max_angle_deg<0||c.max_angle_deg>=89||
       c.max_angle_deg/c.angle_step_deg>90||c.max_candidates<1||c.max_candidates>512)
        throw std::invalid_argument("Invalid hole connection search parameters");
    // 全局距离变化必须连同单洞覆盖一起检查，拒绝只更新了一半的顺序关系。
    if(terrain_) for(const auto &region:terrain_->getRegions()) {
        if(region.type!="low_clearance"&&region.type!="2") continue;
        const auto resolved=resolveHoleDistances(region.raw["traversal"],c.preview);
        if(!validHoleDistances(resolved) || (resolved.range_edge>=0 && resolved.range_bidirectional &&
            !validHoleDistances(resolved.forEntry(resolved.range_edge+2))))
            throw std::invalid_argument("Invalid resolved distances for hole "+region.id);
    }
    return c;
}
nav_core::HolePassageCheck HolePassagePlanner::validateTerrainUpdate(TerrainRegionMap::ConstPtr next,
        std::optional<HolePoint> position) const {
    try {
        const auto configuration=readConfiguration();
        for(const auto &region:next->getRegions()) {
            if(region.type!="low_clearance" && region.type!="2")continue;
            HoleGeometryInput input;input.id=region.id;input.frame_id=region.frame_id;
            input.passable_edge_pair=region.passable_edge_pair;
            for(auto p:region.polygon)input.polygon.push_back({p.x,p.y});
            const auto t=region.raw["traversal"];
            if(t && t["enabled"])input.enabled=t["enabled"].as<bool>();
            if(t && t["bidirectional"])input.bidirectional=t["bidirectional"].as<bool>();
            const auto distances=resolveHoleDistances(t,configuration.preview);
            if(input.enabled && (input.passable_edge_pair>=0 || distances.range_edge>=0)) {
                const auto g=buildHoleGeometry(input,configuration.preview.geometry,distances);
                if(!g.valid)return holeCheck(false,region.id+": "+g.reason);
            }
        }
        if(position && terrain_) {
            // 使用已采用路径的实际 S/E/X/T，free 模式也保护入口及出口直线。
            for(const auto &passage:committed_passages_) {
                bool committed=holeSegmentDistance(*position,passage.S,passage.E)<=configuration.validation.waypoint_tolerance ||
                    holeSegmentDistance(*position,passage.X,passage.T)<=configuration.validation.waypoint_tolerance;
                const auto old=std::find_if(terrain_->getRegions().begin(),terrain_->getRegions().end(),
                    [&](const auto &r){return r.id==passage.hole_id;});
                if(old==terrain_->getRegions().end())continue;
                std::vector<HolePoint> polygon;for(auto p:old->polygon)polygon.push_back({p.x,p.y});
                committed=committed || holeContains(polygon,*position);
                if(!committed)continue;
                const auto replacement=std::find_if(next->getRegions().begin(),next->getRegions().end(),
                    [&](const auto &r){return r.id==old->id;});
                if(replacement==next->getRegions().end() || YAML::Dump(old->raw)!=YAML::Dump(replacement->raw))
                    return holeCheck(false,"ACTIVE_STRAIGHT_COMMITMENT: "+old->id+"，离开固定直线后再重载",*position);
            }
        }
        return holeCheck(true,"TERRAIN_SNAPSHOT_VALID");
    } catch(const std::exception &error) {return holeCheck(false,error.what());}
}
bool HolePassagePlanner::enabled() const { return node_ && node_->get_parameter("hole_planner.enabled").as_bool(); }
bool HolePassagePlanner::refreshConfiguration() {
    const auto previous_mode=config_.mode;
    config_=readConfiguration();
    if(previous_mode!=config_.mode||!config_.enabled)previous_route_=nav_msgs::msg::Path();
    std::ostringstream s; s<<std::setprecision(17);
    const auto &g=config_.preview.geometry;const auto &d=config_.preview.distances;const auto &v=config_.validation;
    s<<config_.normal_departure<<' '<<config_.enabled<<' '<<static_cast<int>(config_.mode)<<' '<<config_.preview.publish_debug_markers<<' '
     <<config_.preview.use_global_distances<<' '
     <<g.rectangle_angle_tolerance_deg<<' '<<g.parallel_tolerance_deg<<' '<<g.min_long_short_ratio<<' '
     <<g.max_centerline_difference<<' '<<g.max_axis_difference_deg<<' '
     <<d.prepare_distance<<' '<<d.entry_straight_length<<' '<<d.exit_straight_length<<' '<<d.departure_distance<<' '
     <<v.waypoint_tolerance<<' '<<v.tangent_tolerance_deg<<' '<<v.side_margin<<' '
     <<config_.search_prepare_distance<<' '<<config_.prepare_min<<' '<<config_.prepare_max<<' '<<config_.prepare_step<<' '
     <<config_.optimization.enabled<<' '<<config_.search.max_curvature<<' '<<config_.optimization.enforce_max_curvature<<' '
     <<config_.optimization.max_iterations<<' '<<config_.optimization.control_spacing<<' '<<config_.approach_policy<<' '
     <<config_.optimization.approach_smoothing_timeout<<' '
     <<config_.optimization.length_weight<<' '<<config_.optimization.curvature_weight<<' '
     <<config_.optimization.curvature_change_weight<<' '<<config_.optimization.obstacle_weight<<' '
     <<config_.optimization.reference_weight<<' '<<config_.optimization.safe_distance<<' '
     <<config_.search.state_resolution<<' '<<config_.search.heading_bins<<' '
     <<config_.search.primitive_length<<' '<<config_.search.sample_resolution<<' '<<config_.search.max_expansions<<' '
     <<config_.search.timeout<<' '<<config_.planning_timeout<<' '<<config_.min_motion_speed<<' '
     <<config_.edge_step<<' '<<config_.angle_step_deg<<' '<<config_.max_angle_deg<<' '<<config_.max_candidates;
    s<<' '<<config_.global_enabled<<' '<<config_.graph_max_nodes<<' '<<config_.graph_max_expansions<<' '
     <<config_.graph_max_passages<<' '<<config_.route_curvature_weight<<' '<<config_.route_clearance_weight<<' '
     <<config_.prepare_deviation_weight;
    s<<' '<<config_.responsive<<' '<<config_.shortlist_size<<' '<<config_.improvement_timeout<<' '
     <<config_.relative_cost_gap<<' '<<config_.cache_enabled<<' '<<config_.cache_max_entries<<' '
     <<config_.optimization.relative_improvement_tolerance<<' '<<config_.optimization.stagnation_iterations;
    if(s.str()==configuration_signature_) return false;
    clearConnectionCache();
    configuration_signature_=s.str(); ++configuration_revision_; clearDiagnostics(); return true;
}
HoleOptimizedConnection HolePassagePlanner::normalDeparture(HolePoint start,HolePoint tangent,
        HolePoint goal,const nav_msgs::msg::OccupancyGrid &map,double threshold,
        const HoleSegmentCheck &collision,const HoleHullCheck &hull,
        std::chrono::steady_clock::time_point deadline) {
    HoleOptimizedConnection result;
    deadline=std::min(deadline,std::chrono::steady_clock::now()+std::chrono::duration_cast<std::chrono::steady_clock::duration>(
        std::chrono::duration<double>(config_.search.timeout)));
    if(normal_segment_planner_)result=normal_segment_planner_(start,tangent,goal,map,threshold,collision,hull,deadline);
    else {
        PathSmoother smoother;smoother.setESDFCallback(distance_query_);
        result=planNormalNavigationSegment(start,tangent,goal,smoother,map,threshold,collision,hull,
            config_.search.sample_resolution,config_.search.max_expansions,deadline,{},
            config_.optimization.enforce_max_curvature?std::optional<double>{config_.search.max_curvature}:std::nullopt);
    }
    statistics_.connection_search_ms+=result.seed_search_ms;statistics_.curve_fit_ms+=result.curve_fit_ms;
    statistics_.curve_validation_ms+=result.curve_validation_ms;statistics_.fits+=result.fits;
    return result;
}
HoleGeometryPreview HolePassagePlanner::geometry(const TerrainRegion &region,
        HoleTraversalDistances &distances,const HolePoint *start) const {
    const auto with_start=[&](HoleGeometryPreview result) {
        if(!start||!result.valid)return result;
        if(!holeFinite(*start)){result.valid=false;result.reason="INVALID_DEBUG_START";return result;}
        result.has_start=true;result.start_inside=holeContains(result.polygon,*start);
        HolePoint center{};for(auto p:result.polygon)center=center+p;center=center*0.25;
        for(auto &d:result.directions) {
            const auto a=result.polygon[d.entry_edge_id],b=result.polygon[(d.entry_edge_id+1)%4];
            d.start_distance=holeSegmentDistance(*start,a,b);
            d.start_in_entry_half_plane=holeCross(b-a,*start-a)*holeCross(b-a,center-a)<=1e-12;
        }
        if(result.directions.size()==2&&result.directions[1].start_distance+config_.preview.geometry.entry_tie_distance<result.directions[0].start_distance)
            std::swap(result.directions[0],result.directions[1]);
        if(result.start_inside)result.warning+=(result.warning.empty()?"":"; ")+std::string("Start inside hole: dedicated traversal planning required");
        return result;
    };
    const auto cached=geometry_cache_.find(region.id);
    if(cached!=geometry_cache_.end()) {distances=cached->second.second;return with_start(cached->second.first);}
    HoleGeometryInput input; input.id=region.id; input.frame_id=region.frame_id;
    input.passable_edge_pair=region.passable_edge_pair;
    for(auto p:region.polygon) input.polygon.push_back({p.x,p.y});
    const auto t=region.raw["traversal"];
    if(t&&t["enabled"]) input.enabled=t["enabled"].as<bool>();
    if(t&&t["bidirectional"]) input.bidirectional=t["bidirectional"].as<bool>();
    distances=resolveHoleDistances(t,config_.preview);
    auto result=buildHoleGeometry(input,config_.preview.geometry,distances,nullptr);
    result.geometry_revision=terrain_revision_;result.parameter_revision=configuration_revision_;
    RCLCPP_DEBUG(node_->get_logger(),"洞口 %s 范围来源=%s 版本=%lu 边=%d/%d 两侧=%.3f/%.3f m",
        region.id.c_str(),distances.range_source.c_str(),terrain_revision_,distances.range_edge,
        distances.range_edge<0?-1:distances.range_edge+2,distances.range_extensions[0],distances.range_extensions[1]);
    geometry_cache_[region.id]={result,distances};return with_start(result);
}
static HolePathPolyline polyline(const nav_msgs::msg::Path &path) {
    std::vector<HolePoint> points;
    for(const auto &p:path.poses) points.push_back({p.pose.position.x,p.pose.position.y});
    return HolePathPolyline(points);
}
void HolePassagePlanner::buildCandidates(const nav_msgs::msg::Path &seed,
        const nav_msgs::msg::OccupancyGrid &map,double threshold) {
    refreshConfiguration(); candidates_.clear();path_passages_.clear();
    if(!config_.enabled || !terrain_) {publishDiagnostics();return;}
    if(seed.header.frame_id!="map" || (!map.header.frame_id.empty()&&map.header.frame_id!="map")) {
        HolePassageCandidate c;c.mode=config_.mode;c.check=holeCheck(false,"FRAME_MISMATCH");
        candidates_.push_back(c);publishDiagnostics();return;
    }
    const auto path=polyline(seed);
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,threshold,a,b);};
    for(const auto &region:terrain_->getRegions()) {
        if(region.type!="low_clearance"&&region.type!="2") continue;
        if(blocked_holes_.count(region.id))continue;
        HoleTraversalDistances distances; const auto g=geometry(region,distances,path.valid?&path.points.front():nullptr);
        if(!g.valid) {
            if(g.reason=="HOLE_DISABLED") continue;
            HolePassageCandidate c;c.hole_id=region.id;c.mode=config_.mode;c.check=holeCheck(false,g.reason);
            candidates_.push_back(c);continue;
        }
        if(config_.mode==HolePassageMode::Centerline) for(const auto &direction:g.directions) {
            auto c=centerlineHoleCandidate(g,direction);
            c.check=validateHoleCandidate(g,distances,config_.validation,c,collision);candidates_.push_back(c);
        } else if(path.valid) for(const auto &crossing:holePathCrossings(g,path)) {
            auto c=freeHoleCandidate(g,distances,path,crossing);
            c.check=crossing.partial?holeCheck(false,"PARTIAL_PASSAGE_REQUIRES_LATER_STAGE",c.E)
                :validateHoleCandidate(g,distances,config_.validation,c,collision);
            candidates_.push_back(c);
        }
    }
    publishDiagnostics();
}
HolePassageCheck HolePassagePlanner::validatePath(const nav_msgs::msg::Path &message,
        const nav_msgs::msg::OccupancyGrid &map,double threshold,bool publish_diagnostics,
        std::chrono::steady_clock::time_point deadline) {
    refreshConfiguration(); path_passages_.clear();departure_events_.clear();preparation_events_.clear();
    if(!config_.enabled) {if(publish_diagnostics)publishDiagnostics();return holeCheck(true,"HOLE_PLANNER_DISABLED");}
    if(!terrain_) return holeCheck(false,"TERRAIN_UNAVAILABLE");
    if(message.header.frame_id!="map" || (!map.header.frame_id.empty()&&map.header.frame_id!="map"))
        return holeCheck(false,"FRAME_MISMATCH");
    if(message.poses.size()==1) {
        const auto &p=message.poses.front().pose.position;
        const auto check=checkHoleMapSegment(map,threshold,{p.x,p.y},{p.x,p.y});
        if(check.valid)updateDepartureEvents(message,publish_diagnostics);
        if(publish_diagnostics)publishDiagnostics();return check;
    }
    const auto path=polyline(message);
    if(!path.valid) return holeCheck(false,"INVALID_PATH");
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,threshold,a,b);};
    for(std::size_t i=1;i<path.points.size();++i) {
        if(std::chrono::steady_clock::now()>=deadline)return holeCheck(false,"FINAL_VALIDATION_TIMEOUT");
        const auto check=collision(path.points[i-1],path.points[i]);
        if(!check.valid) {if(publish_diagnostics)publishDiagnostics();return check;}
    }
    HolePassageCheck overall=holeCheck(true,"PATH_VALID_NO_PASSAGE");
    for(const auto &region:terrain_->getRegions()) {
        if(region.type!="low_clearance"&&region.type!="2") continue;
        if(std::chrono::steady_clock::now()>=deadline)return holeCheck(false,"FINAL_VALIDATION_TIMEOUT");
        HoleTraversalDistances distances;const auto g=geometry(region,distances,&path.points.front());
        if(g.reason=="HOLE_DISABLED") continue;
        // 不合格但具有可裁剪边界的洞口不授权穿越；无关绕行仍可用。
        if(!g.geometry_valid) {
            overall=holeCheck(false,g.reason);break;
        }
        const auto crossings=holePathCrossings(g,path);
        if(blocked_holes_.count(region.id)&&!crossings.empty())return holeCheck(false,"HOLE_TEMPORARILY_BLOCKED");
        if(!crossings.empty()&&!g.valid) {overall=holeCheck(false,g.reason);break;}
        for(const auto &crossing:crossings) {
            HolePassageCandidate c;
            const auto check=validateHolePathPassage(g,distances,config_.validation,path,crossing,config_.mode,collision,&c,true);
            path_passages_.push_back(c);
            if(!check.valid) {overall=check;break;}
            if(distances.manual_range && config_.mode==HolePassageMode::Centerline) {
                const auto direction=std::find_if(g.directions.begin(),g.directions.end(),[&](const auto &d){return d.entry_edge_id==c.entry_edge;});
                if(direction==g.directions.end())return holeCheck(false,"MANUAL_RANGE_DIRECTION_MISMATCH");
                const auto &d=*direction;
                if((c.entry_complete&&holeNorm(c.E-d.E)>1e-6)||
                   (c.exit_complete&&holeNorm(c.X-d.X)>1e-6))
                    return holeCheck(false,"MANUAL_RANGE_ENDPOINT_MISMATCH");
                const auto points=path.slice(c.entry_complete?std::max(0.0,c.entry_arc-distances.forEntry(c.entry_edge).entry_straight_length):c.entry_arc,
                    c.exit_complete?std::min(path.arc.back(),c.exit_arc+distances.forEntry(c.entry_edge).exit_straight_length):c.exit_arc);
                for(auto p:points)if(std::abs(holeCross(d.tangent,p-d.E))>1e-6)
                    return holeCheck(false,"MANUAL_STRAIGHT_RANGE_MISMATCH",p);
                for(std::size_t i=1;i<points.size();++i) {
                    const auto delta=points[i]-points[i-1];const double n=holeNorm(delta);
                    if(n>1e-10 && (holeDot(delta,d.tangent)<0 || std::abs(holeCross(delta,d.tangent))/n>1.746e-6))
                        return holeCheck(false,"MANUAL_STRAIGHT_DIRECTION_MISMATCH",points[i]);
                }
            }
            overall=holeCheck(true,"PATH_PASSAGE_VALID");
        }
        if(!overall.valid) break;
    }
    std::stable_sort(path_passages_.begin(),path_passages_.end(),[](const auto &a,const auto &b) {
        return a.entry_arc<b.entry_arc;
    });
    if(overall.valid&&!path_passages_.empty()&&config_.optimization.enabled&&config_.optimization.enforce_max_curvature) {
        for(std::size_t i=1;i+1<path.points.size();++i) {
            const auto a=path.points[i]-path.points[i-1],b=path.points[i+1]-path.points[i];
            const double denominator=holeNorm(a)*holeNorm(b)*holeNorm(path.points[i+1]-path.points[i-1]);
            if(denominator>1e-15&&2*std::abs(holeCross(a,b))/denominator>config_.search.max_curvature*(1+1e-3)) {
                overall=holeCheck(false,"MAX_CURVATURE_EXCEEDED",path.points[i]);break;
            }
        }
    }
    if(std::chrono::steady_clock::now()>=deadline)return holeCheck(false,"FINAL_VALIDATION_TIMEOUT");
    if(overall.valid)updateDepartureEvents(message,publish_diagnostics);
    if(publish_diagnostics && overall.valid)committed_passages_=path_passages_;
    if(publish_diagnostics)publishDiagnostics();return overall;
}
void HolePassagePlanner::updateDepartureEvents(const nav_msgs::msg::Path &message,bool commit) {
    preparation_events_.clear();
    const auto path=polyline(message);if(path.points.empty())return;
    const auto previous=polyline(event_path_);
    bool changed=path.points.size()!=previous.points.size();
    if(!changed)for(std::size_t i=0;i<path.points.size();++i)if(holeNorm(path.points[i]-previous.points[i])>1e-9){changed=true;break;}
    const auto revision=path_revision_+(changed?1:0);
    const auto make=[&](const std::string &id,int entry,int exit,double exit_arc,bool exit_complete) {
        const auto region=std::find_if(terrain_->getRegions().begin(),terrain_->getRegions().end(),[&](const auto &r){return r.id==id;});
        if(region==terrain_->getRegions().end())return;
        HoleTraversalDistances distances;const auto g=geometry(*region,distances,nullptr);
        const auto d=distances.forEntry(entry);
        HoleDepartureEvent event;event.hole_id=id;event.entry_edge=entry;event.exit_edge=exit;
        event.exit_arc=exit_arc;event.departure_distance=d.departure_distance;
        event.departure_arc=exit_arc+d.departure_distance;
        const bool arc_event=d.manual_range||config_.normal_departure||config_.mode==HolePassageMode::Free;
        event.kind=arc_event?"path_arc_event":"axis_waypoint";
        event.planning_policy=d.manual_range?"manual_range_end":(config_.normal_departure?"normal_navigation":"legacy_constrained");
        event.range_source=d.range_source;event.terrain_revision=terrain_revision_;
        event.configuration_revision=configuration_revision_;event.path_revision=revision;
        if(!exit_complete)event.status="exit_not_reached";
        else if(event.departure_arc< -1e-9)event.status="passed";
        else if(event.departure_arc>path.arc.back()+1e-9)event.status="beyond_path";
        else {
            event.status="on_path";
            if(arc_event){event.point=path.at(std::max(0.0,event.departure_arc));event.point_valid=true;}
            else {
                const auto direction=std::find_if(g.directions.begin(),g.directions.end(),[&](const auto &v){return v.entry_edge_id==entry;});
                if(direction!=g.directions.end()) {
                    event.point=direction->D;
                    // 旧策略用几何 waypoint 的实际位置定位，不把弧长值假冒旧 D。
                    double best=std::numeric_limits<double>::infinity();
                    for(std::size_t i=1;i<path.points.size();++i) {
                        const auto a=path.points[i-1],v=path.points[i]-a;
                        const double t=std::clamp(holeDot(event.point-a,v)/holeDot(v,v),0.0,1.0);
                        const double distance=holeNorm(a+v*t-event.point);
                        if(distance<best){best=distance;event.departure_arc=path.arc[i-1]+t*(path.arc[i]-path.arc[i-1]);}
                    }
                    event.point_valid=best<=config_.validation.waypoint_tolerance;
                    if(!event.point_valid)event.status="axis_waypoint_absent";
                }
            }
        }
        departure_events_.push_back(event);
    };
    for(const auto &c:path_passages_)make(c.hole_id,c.entry_edge,c.exit_edge,c.exit_arc,c.exit_complete);
    for(std::size_t i=0;i<path_passages_.size();++i) {
        const auto &c=path_passages_[i];
        const auto region=std::find_if(terrain_->getRegions().begin(),terrain_->getRegions().end(),[&](const auto &r){return r.id==c.hole_id;});
        if(region==terrain_->getRegions().end())continue;
        HoleTraversalDistances d;geometry(*region,d,nullptr);if(!d.manual_range)continue;
        HolePreparationEvent event;event.hole_id=c.hole_id;event.entry_edge=c.entry_edge;event.exit_edge=c.exit_edge;
        event.passage_index=i;event.entry_arc=c.entry_arc;event.prepare_path_distance=d.prepare_path_distance;
        event.preparation_arc=c.entry_arc-d.prepare_path_distance;event.range_source=d.range_source;
        event.terrain_revision=terrain_revision_;event.configuration_revision=configuration_revision_;event.path_revision=revision;
        if(!c.entry_complete) {event.status="entry_not_on_path";event.preparation_required_at_start=true;}
        else if(event.preparation_arc<0) {event.status="before_path";event.preparation_required_at_start=true;}
        else {event.status="on_path";event.point=path.at(event.preparation_arc);event.point_valid=true;}
        preparation_events_.push_back(event);
    }
    // 起点已越过 X 时，按上一次有效路径定位历史出口；保留尚未结束的 D。
    const bool manual_departure=std::any_of(committed_departure_events_.begin(),committed_departure_events_.end(),
        [](const auto &event){return event.planning_policy=="manual_range_end";});
    if((config_.normal_departure||manual_departure)&&previous.valid&&holeNorm(path.points.back()-previous.points.back())<1e-7) {
        double best=std::numeric_limits<double>::infinity(),position_arc=0;
        for(std::size_t i=1;i<previous.points.size();++i) {
            const auto a=previous.points[i-1],v=previous.points[i]-a;
            const double t=std::clamp(holeDot(path.points.front()-a,v)/holeDot(v,v),0.0,1.0);
            const double distance=holeNorm(a+v*t-path.points.front());
            if(distance<best){best=distance;position_arc=previous.arc[i-1]+t*(previous.arc[i]-previous.arc[i-1]);}
        }
        if(best<=config_.validation.waypoint_tolerance)for(const auto &old:committed_departure_events_) {
            if(old.kind!="path_arc_event"||old.status=="exit_not_reached"||old.exit_arc>position_arc+1e-9)continue;
            if(std::any_of(departure_events_.begin(),departure_events_.end(),[&](const auto &e){return e.hole_id==old.hole_id;}))continue;
            make(old.hole_id,old.entry_edge,old.exit_edge,old.exit_arc-position_arc,true);
        }
    }
    std::stable_sort(departure_events_.begin(),departure_events_.end(),[](const auto &a,const auto &b){return a.departure_arc<b.departure_arc;});
    if(commit){event_path_=message;committed_departure_events_=departure_events_;path_revision_=revision;}
}
void HolePassagePlanner::clearDiagnostics() {
    candidates_.clear();path_passages_.clear();route_attempts_.clear();departure_events_.clear();preparation_events_.clear();
    if(route_publisher_) {nav_msgs::msg::Path empty;empty.header.frame_id="map";route_publisher_->publish(empty);}
    publishDiagnostics();
}
void HolePassagePlanner::publishDiagnostics() {
    if(!publisher_) return;
    visualization_msgs::msg::MarkerArray array;
    visualization_msgs::msg::Marker clear;clear.action=visualization_msgs::msg::Marker::DELETEALL;
    array.markers.push_back(clear);
    if(config_.enabled&&config_.preview.publish_debug_markers) {
        int id=0;
        const auto append=[&](const HolePassageCandidate &c,bool final_path) {
            visualization_msgs::msg::Marker m;m.header.frame_id="map";m.header.stamp=node_->now();
            m.ns=final_path?"hole_path_validation":"hole_passage_candidates";m.id=id++;
            m.action=visualization_msgs::msg::Marker::ADD;m.type=visualization_msgs::msg::Marker::LINE_LIST;
            m.pose.orientation.w=1;m.scale.x=final_path?0.045:0.025;m.color.a=0.9;
            m.color.r=c.check.valid?0.1:1.0;m.color.g=c.check.valid?1.0:0.15;m.color.b=final_path?0.1:1.0;
            const auto point=[](HolePoint p){geometry_msgs::msg::Point q;q.x=p.x;q.y=p.y;q.z=0.12;return q;};
            if(c.entry_edge>=0&&c.exit_edge>=0) {
                for(auto p:{c.S,c.E,c.X,c.T}) m.points.push_back(point(p));
                if(c.mode==HolePassageMode::Centerline) {m.points.push_back(point(c.E));m.points.push_back(point(c.X));}
                array.markers.push_back(m);
            }
            m.id=id++;m.type=visualization_msgs::msg::Marker::TEXT_VIEW_FACING;m.points.clear();
            m.pose.position=point(c.E);m.pose.position.z=0.3;m.scale.z=0.12;
            m.text=c.hole_id+" "+(c.mode==HolePassageMode::Free?"free":"centerline")+
                (final_path?" path: ":" candidate only: ")+c.check.reason;
            array.markers.push_back(m);
        };
        for(const auto &c:candidates_) append(c,false);
        for(const auto &c:path_passages_) append(c,true);
        for(const auto &event:preparation_events_) {
            visualization_msgs::msg::Marker m;m.header.frame_id="map";m.header.stamp=node_->now();
            m.ns="hole_preparation_events";m.id=id++;m.action=visualization_msgs::msg::Marker::ADD;
            m.pose.orientation.w=1;m.color.a=1;m.color.r=.95;m.color.g=.25;m.color.b=1;
            m.type=visualization_msgs::msg::Marker::TEXT_VIEW_FACING;m.scale.z=.12;
            if(event.point_valid){m.pose.position.x=event.point.x;m.pose.position.y=event.point.y;}
            else if(!event_path_.poses.empty())m.pose.position=event_path_.poses.front().pose.position;
            m.pose.position.z=.5;m.text=event.hole_id+" A "+event.status+" ready before E; distance="+std::to_string(event.prepare_path_distance);
            array.markers.push_back(m);
            if(event.point_valid) {m.id=id++;m.type=visualization_msgs::msg::Marker::SPHERE;m.scale.x=m.scale.y=m.scale.z=.11;m.pose.position.z=.18;array.markers.push_back(m);}
        }
        for(const auto &event:departure_events_) {
            visualization_msgs::msg::Marker m;m.header.frame_id="map";m.header.stamp=node_->now();
            m.ns="hole_departure_events";m.id=id++;m.action=visualization_msgs::msg::Marker::ADD;
            m.pose.orientation.w=1;m.color.a=1;m.color.r=1;m.color.g=.65;m.color.b=.1;
            m.type=visualization_msgs::msg::Marker::TEXT_VIEW_FACING;m.scale.z=.12;
            if(event.point_valid){m.pose.position.x=event.point.x;m.pose.position.y=event.point.y;}
            else if(!path_passages_.empty()){m.pose.position.x=path_passages_.back().T.x;m.pose.position.y=path_passages_.back().T.y;}
            m.pose.position.z=.4;m.text=event.hole_id+" D "+event.kind+" "+event.status+
                " path="+std::to_string(event.path_revision)+" s="+std::to_string(event.departure_arc);
            array.markers.push_back(m);
            if(event.point_valid){m.id=id++;m.type=visualization_msgs::msg::Marker::SPHERE;m.scale.x=m.scale.y=m.scale.z=.09;
                m.pose.position.z=.16;array.markers.push_back(m);}
        }
        for(const auto &attempt:route_attempts_) {
            visualization_msgs::msg::Marker m;m.header.frame_id="map";m.header.stamp=node_->now();
            m.ns="hole_connection_routes";m.id=id++;m.pose.orientation.w=1;
            m.action=visualization_msgs::msg::Marker::ADD;m.type=visualization_msgs::msg::Marker::LINE_STRIP;
            m.scale.x=attempt.check.valid?0.04:0.015;m.color.a=attempt.check.valid?1:0.35;
            m.color.r=attempt.check.valid?0.1:1;m.color.g=attempt.check.valid?0.8:0.2;m.color.b=0.7;
            for(auto p:attempt.points) {geometry_msgs::msg::Point q;q.x=p.x;q.y=p.y;q.z=0.16;m.points.push_back(q);}
            if(!m.points.empty()&&(!attempt.check.valid||attempt.approach.empty())) array.markers.push_back(m);
            if(attempt.check.valid) {
                const auto segment=[&](const std::vector<HolePoint> &points,const std::string &name,float red,float green,float blue) {
                    auto s=m;s.ns=name;s.id=id++;s.points.clear();s.color.r=red;s.color.g=green;s.color.b=blue;
                    for(auto p:points) {geometry_msgs::msg::Point q;q.x=p.x;q.y=p.y;q.z=0.16;s.points.push_back(q);}
                    if(!s.points.empty()) array.markers.push_back(s);
                };
                segment(attempt.approach,"hole_approach",0.15,0.7,1.0);
                segment(attempt.interior,"hole_interior",0.1,0.9,0.3);
                segment(attempt.departure,"hole_departure",1.0,0.65,0.1);
            }
            m.id=id++;m.type=visualization_msgs::msg::Marker::TEXT_VIEW_FACING;m.points.clear();
            const bool strict=attempt.passage.mode==HolePassageMode::Centerline&&!attempt.manual_range;
            const auto label_point=strict?attempt.A:attempt.passage.S;
            m.pose.position.x=label_point.x;m.pose.position.y=label_point.y;m.pose.position.z=0.5;m.scale.z=0.1;
            m.text=attempt.passage.hole_id+(strict?" A="+std::to_string(attempt.prepare_distance):" free")+" "+attempt.check.reason;
            if(attempt.check.valid) m.text+=" L="+std::to_string(attempt.path_length)+" k="+std::to_string(attempt.maximum_curvature);
            array.markers.push_back(m);
            if(attempt.passage.mode==HolePassageMode::Centerline) {
                m.id=id++;m.type=visualization_msgs::msg::Marker::SPHERE_LIST;m.scale.x=m.scale.y=m.scale.z=0.08;
                for(auto p:config_.normal_departure?std::vector<HolePoint>{attempt.A}:std::vector<HolePoint>{attempt.A,attempt.D}) {geometry_msgs::msg::Point q;q.x=p.x;q.y=p.y;q.z=0.16;m.points.push_back(q);}
                array.markers.push_back(m);
            }
        }
    }
    publisher_->publish(array);
}
} // namespace nav_components
