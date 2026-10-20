#include "nav_components/hole_geometry_previewer.hpp"
#include <nav_core/hole_geometry_markers.hpp>

namespace nav_components {
void HoleGeometryPreviewer::initialize(rclcpp::Node *node, TerrainRegionMap::ConstPtr terrain) {
    node_=node; terrain_=std::move(terrain);
    node_->declare_parameter("hole_planner.enabled",false); // 阶段二规划校验开关，预览独立生效。
    if(!node_->has_parameter("hole_planner.departure.planning_policy"))
        node_->declare_parameter("hole_planner.departure.planning_policy","legacy_constrained");
    const std::vector<std::pair<std::string,double>> values={
        {"hole_planner.geometry.rectangle_angle_tolerance_deg",3.0},
        {"hole_planner.geometry.parallel_tolerance_deg",3.0},
        {"hole_planner.geometry.min_long_short_ratio",1.2},
        {"hole_planner.geometry.max_centerline_difference",0.02},
        {"hole_planner.geometry.max_axis_difference_deg",3.0},
        {"hole_planner.approach.prepare_distance",1.5},
        {"hole_planner.approach.entry_straight_length",0.8},
        {"hole_planner.departure.exit_straight_length",0.5},
        {"hole_planner.departure.departure_distance",0.8}};
    for(const auto &value:values) node_->declare_parameter(value.first,value.second);
    node_->declare_parameter("hole_planner.publish_debug_markers",true);
    node_->declare_parameter("hole_planner.use_global_distances",false); // 统一使用全局四个距离，供正常导航在线调整。
    const auto apply=[](nav_core::HolePreviewConfiguration &c,const rclcpp::Parameter &p) {
        const auto &name=p.get_name();
        if(name=="hole_planner.geometry.rectangle_angle_tolerance_deg") c.geometry.rectangle_angle_tolerance_deg=p.as_double();
        else if(name=="hole_planner.geometry.parallel_tolerance_deg") c.geometry.parallel_tolerance_deg=p.as_double();
        else if(name=="hole_planner.geometry.min_long_short_ratio") c.geometry.min_long_short_ratio=p.as_double();
        else if(name=="hole_planner.geometry.max_centerline_difference") c.geometry.max_centerline_difference=p.as_double();
        else if(name=="hole_planner.geometry.max_axis_difference_deg") c.geometry.max_axis_difference_deg=p.as_double();
        else if(name=="hole_planner.approach.prepare_distance") c.distances.prepare_distance=p.as_double();
        else if(name=="hole_planner.approach.entry_straight_length") c.distances.entry_straight_length=p.as_double();
        else if(name=="hole_planner.departure.exit_straight_length") c.distances.exit_straight_length=p.as_double();
        else if(name=="hole_planner.departure.departure_distance") c.distances.departure_distance=p.as_double();
        else if(name=="hole_planner.departure.planning_policy") {
            const auto policy=p.as_string();
            if(policy!="normal_navigation"&&policy!="legacy_constrained")throw std::runtime_error("Invalid departure planning_policy");
            c.departure_axis_reference=policy=="normal_navigation";
        }
        else if(name=="hole_planner.publish_debug_markers") c.publish_debug_markers=p.as_bool();
        else if(name=="hole_planner.use_global_distances") c.use_global_distances=p.as_bool();
    };
    for(const auto &value:values) apply(config_,node_->get_parameter(value.first));
    apply(config_,node_->get_parameter("hole_planner.publish_debug_markers"));
    apply(config_,node_->get_parameter("hole_planner.use_global_distances"));
    apply(config_,node_->get_parameter("hole_planner.departure.planning_policy"));
    if(!nav_core::validHoleGeometryParams(config_.geometry)||!nav_core::validHoleDistances(config_.distances))
        throw std::runtime_error("Invalid hole_planner geometry or distances");
    publisher_=node_->create_publisher<visualization_msgs::msg::MarkerArray>("hole_geometry_markers",rclcpp::QoS(1).transient_local().reliable());
    subscription_=node_->create_subscription<geometry_msgs::msg::PointStamped>("/clicked_point",10,
        [this](geometry_msgs::msg::PointStamped::ConstSharedPtr message) {
            const nav_core::HolePoint start{message->point.x,message->point.y};
            if(message->header.frame_id!="map"||!nav_core::holeFinite(start)) {
                RCLCPP_WARN(node_->get_logger(),"Hole preview start must be finite map coordinates"); return;
            }
            start_=start; has_start_=true; ++start_revision_; dirty_=true;
        });
    // Validate the entire proposed parameter batch, then read committed values
    // in the timer. This cannot publish a change rejected by another callback.
    parameter_callback_=node_->add_on_set_parameters_callback([this,apply](const std::vector<rclcpp::Parameter> &batch) {
        rcl_interfaces::msg::SetParametersResult result; result.successful=true;
        auto candidate=config_;
        try {
            for(const auto &parameter:batch) apply(candidate,parameter);
            if(!nav_core::validHoleGeometryParams(candidate.geometry)||!nav_core::validHoleDistances(candidate.distances))
                throw std::runtime_error("require finite tolerances, prepare >= entry >= 0 and departure >= exit >= 0");
        } catch(const std::exception &error) {result.successful=false;result.reason=error.what();}
        return result;
    });
    timer_=node_->create_wall_timer(std::chrono::milliseconds(100),[this,values,apply]() {
        auto next=config_;
        bool changed=false;
        for(const auto &value:values) {
            const auto parameter=node_->get_parameter(value.first);
            // Compare serialized configuration values through the apply helper.
            apply(next,parameter);
        }
        apply(next,node_->get_parameter("hole_planner.publish_debug_markers"));
        apply(next,node_->get_parameter("hole_planner.use_global_distances"));
        apply(next,node_->get_parameter("hole_planner.departure.planning_policy"));
        changed=next.geometry.rectangle_angle_tolerance_deg!=config_.geometry.rectangle_angle_tolerance_deg||
            next.geometry.parallel_tolerance_deg!=config_.geometry.parallel_tolerance_deg||
            next.geometry.min_long_short_ratio!=config_.geometry.min_long_short_ratio||
            next.geometry.max_centerline_difference!=config_.geometry.max_centerline_difference||
            next.geometry.max_axis_difference_deg!=config_.geometry.max_axis_difference_deg||
            next.departure_axis_reference!=config_.departure_axis_reference||
            next.distances.prepare_distance!=config_.distances.prepare_distance||
            next.distances.entry_straight_length!=config_.distances.entry_straight_length||
            next.distances.exit_straight_length!=config_.distances.exit_straight_length||
            next.distances.departure_distance!=config_.distances.departure_distance||
            next.use_global_distances!=config_.use_global_distances||
            next.publish_debug_markers!=config_.publish_debug_markers;
        if(changed) {config_=next;++parameter_revision_;dirty_=true;}
        if(dirty_) rebuild();
    });
    rebuild();
}
void HoleGeometryPreviewer::rebuild() {
    previews_.clear();
    visualization_msgs::msg::MarkerArray array;
    visualization_msgs::msg::Marker clear; clear.action=visualization_msgs::msg::Marker::DELETEALL;
    array.markers.push_back(clear);
    for(const auto &region:terrain_->getRegions()) {
        if(region.type!="low_clearance"&&region.type!="2") continue;
        nav_core::HoleGeometryInput input;
        input.id=region.id;input.frame_id=region.frame_id;input.passable_edge_pair=region.passable_edge_pair;
        for(auto p:region.polygon) input.polygon.push_back({p.x,p.y});
        const auto traversal=region.raw["traversal"];
        nav_core::HoleGeometryPreview preview;
        try {
            if(traversal&&traversal["enabled"]) input.enabled=traversal["enabled"].as<bool>();
            if(traversal&&traversal["bidirectional"]) input.bidirectional=traversal["bidirectional"].as<bool>();
            const auto distances=nav_core::resolveHoleDistances(traversal,config_);
            preview=nav_core::buildHoleGeometry(input,config_.geometry,distances,has_start_?&start_:nullptr);
        } catch(const std::exception &error) {preview.id=region.id;preview.reason=error.what();preview.polygon=input.polygon;}
        preview.geometry_revision=terrain_revision_;preview.parameter_revision=parameter_revision_;preview.start_revision=start_revision_;
        if(config_.publish_debug_markers) {
            auto markers=nav_core::holeGeometryMarkers(preview,true,config_.departure_axis_reference);
            for(auto &marker:markers.markers) {marker.header.stamp=node_->now();array.markers.push_back(std::move(marker));}
        }
        RCLCPP_INFO(node_->get_logger(),"Hole preview %s: %s width=%.3f depth=%.3f angle_error=%.3f parallel_error=%.3f",
            region.id.c_str(),preview.reason.c_str(),preview.opening_width,preview.depth,preview.max_rectangle_error_deg,preview.max_parallel_error_deg);
        previews_.push_back(std::move(preview));
    }
    publisher_->publish(array);dirty_=false;
}
} // namespace nav_components
