#pragma once
#include "nav_core/hole_geometry.hpp"
#include <yaml-cpp/yaml.h>
#include <optional>

namespace nav_core {
struct HoleStraightRange {
    int edge = -1;
    std::array<double,2> extensions{};
};
inline std::optional<HoleStraightRange> readHoleStraightRange(const YAML::Node &traversal) {
    if(!traversal || !traversal["straight_range"]) return std::nullopt;
    const auto range=traversal["straight_range"];
    if(!range.IsMap() || !range["schema_version"] || range["schema_version"].as<int>()!=1 ||
       !range["binding"] || range["binding"].as<std::string>()!="passable_edges")
        throw std::runtime_error("INVALID_STRAIGHT_RANGE: unknown schema or binding");
    const auto edges=traversal["passable_edges"],sides=range["sides"];
    if(!edges || !edges.IsSequence() || edges.size()!=2 ||
       !sides || !sides.IsSequence() || sides.size()!=2)
        throw std::runtime_error("INVALID_STRAIGHT_RANGE: requires two passable sides");
    const int a=edges[0].as<int>(),b=edges[1].as<int>();
    if(a<0 || a>1 || b!=a+2)
        throw std::runtime_error("INVALID_STRAIGHT_RANGE: invalid passable edge pair");
    HoleStraightRange result; result.edge=a;
    std::array<bool,2> seen{};
    for(const auto &side:sides) {
        if(!side.IsMap() || !side["edge_id"] || !side["extension_length"])
            throw std::runtime_error("INVALID_STRAIGHT_RANGE: incomplete side");
        const int edge=side["edge_id"].as<int>(),i=edge==a?0:(edge==b?1:-1);
        const double value=side["extension_length"].as<double>();
        if(i<0 || seen[i] || !std::isfinite(value) || value<0)
            throw std::runtime_error("INVALID_STRAIGHT_RANGE: duplicate edge or invalid length");
        seen[i]=true;result.extensions[i]=value;
    }
    return result;
}
inline void writeHoleStraightRange(YAML::Node traversal,const std::optional<HoleStraightRange> &range) {
    if(!range) {traversal.remove("straight_range");return;}
    YAML::Node value;
    value["schema_version"]=1;value["binding"]="passable_edges";
    for(int i=0;i<2;++i) {
        YAML::Node side;side["edge_id"]=range->edge+2*i;side["extension_length"]=range->extensions[i];
        value["sides"].push_back(side);
    }
    traversal["straight_range"]=value;
    readHoleStraightRange(traversal);
}
inline HoleTraversalDistances applyHoleStraightRange(HoleTraversalDistances d,
        const std::optional<HoleStraightRange> &range,bool bidirectional=true) {
    if(range) {
        d.range_edge=range->edge;d.range_extensions=range->extensions;
        d.range_bidirectional=bidirectional;d.range_source="map_straight_range";
        d=d.forEntry(range->edge);
    }
    return d;
}
struct HoleDistanceOverrides {
    std::optional<double> prepare_distance, entry_straight_length, exit_straight_length, departure_distance;
    HoleTraversalDistances resolve(HoleTraversalDistances defaults) const {
        if(prepare_distance) defaults.prepare_distance=*prepare_distance;
        if(entry_straight_length) defaults.entry_straight_length=*entry_straight_length;
        if(exit_straight_length) defaults.exit_straight_length=*exit_straight_length;
        if(departure_distance) defaults.departure_distance=*departure_distance;
        return defaults;
    }
};
inline HoleDistanceOverrides readHoleDistanceOverrides(const YAML::Node &node) {
    HoleDistanceOverrides d;
    if(!node) return d;
    if(!node.IsMap()) throw std::runtime_error("traversal must be a mapping");
    if(node["prepare_distance"]) d.prepare_distance=node["prepare_distance"].as<double>();
    if(node["entry_straight_length"]) d.entry_straight_length=node["entry_straight_length"].as<double>();
    if(node["exit_straight_length"]) d.exit_straight_length=node["exit_straight_length"].as<double>();
    if(node["departure_distance"]) d.departure_distance=node["departure_distance"].as<double>();
    return d;
}
inline void writeHoleDistanceOverrides(YAML::Node traversal, const HoleDistanceOverrides &d) {
    if(d.prepare_distance) traversal["prepare_distance"]=*d.prepare_distance;
    if(d.entry_straight_length) traversal["entry_straight_length"]=*d.entry_straight_length;
    if(d.exit_straight_length) traversal["exit_straight_length"]=*d.exit_straight_length;
    if(d.departure_distance) traversal["departure_distance"]=*d.departure_distance;
}
struct HolePreviewConfiguration {
    HoleGeometryParams geometry;
    HoleTraversalDistances distances;
    bool use_global_distances=false; // 仅覆盖旧角色距离；独立文件确认的人工范围始终优先。
    bool publish_debug_markers=true;
    bool departure_axis_reference=false; // 普通接续策略下，预览轴线 D 仅作距离参考。
};
inline HoleTraversalDistances resolveHoleDistances(const YAML::Node &traversal,
                                                   const HolePreviewConfiguration &config) {
    // 即使全局覆盖也解析格式，损坏的人工范围不能静默退回角色距离。
    const auto range=readHoleStraightRange(traversal);
    if(range && traversal["prepare_path_distance"]) {
        auto d=config.distances;d.manual_range=true;
        d.prepare_path_distance=traversal["prepare_path_distance"].as<double>();
        if(!std::isfinite(d.prepare_path_distance)||d.prepare_path_distance<=0)
            throw std::runtime_error("INVALID_PREPARE_PATH_DISTANCE");
        d=applyHoleStraightRange(d,range,!traversal["bidirectional"]||traversal["bidirectional"].as<bool>());
        d.range_source="manual_passage_config";return d;
    }
    if(config.use_global_distances) {auto d=config.distances;d.range_source="global_override";return d;}
    const auto overrides=readHoleDistanceOverrides(traversal);
    auto defaults=config.distances;
    defaults.range_source=(overrides.prepare_distance || overrides.entry_straight_length ||
        overrides.exit_straight_length || overrides.departure_distance)?"legacy_hole_role":"global_default";
    return applyHoleStraightRange(overrides.resolve(defaults),range,
        !traversal || !traversal["bidirectional"] || traversal["bidirectional"].as<bool>());
}
inline HolePreviewConfiguration readHolePreviewConfiguration(const YAML::Node &root) {
    HolePreviewConfiguration config;
    const auto node=root["nav_server"]["ros__parameters"]["hole_planner"];
    if(!node) return config;
    const auto geometry=node["geometry"];
    if(geometry) {
        if(geometry["rectangle_angle_tolerance_deg"]) config.geometry.rectangle_angle_tolerance_deg=geometry["rectangle_angle_tolerance_deg"].as<double>();
        if(geometry["parallel_tolerance_deg"]) config.geometry.parallel_tolerance_deg=geometry["parallel_tolerance_deg"].as<double>();
        if(geometry["min_long_short_ratio"]) config.geometry.min_long_short_ratio=geometry["min_long_short_ratio"].as<double>();
        if(geometry["max_centerline_difference"]) config.geometry.max_centerline_difference=geometry["max_centerline_difference"].as<double>();
        if(geometry["max_axis_difference_deg"]) config.geometry.max_axis_difference_deg=geometry["max_axis_difference_deg"].as<double>();
    }
    const auto approach=node["approach"],departure=node["departure"];
    if(approach) {
        if(approach["prepare_distance"]) config.distances.prepare_distance=approach["prepare_distance"].as<double>();
        if(approach["entry_straight_length"]) config.distances.entry_straight_length=approach["entry_straight_length"].as<double>();
    }
    if(departure) {
        if(departure["planning_policy"]) {
            const auto policy=departure["planning_policy"].as<std::string>();
            if(policy!="normal_navigation"&&policy!="legacy_constrained")throw std::runtime_error("Invalid departure planning_policy");
            config.departure_axis_reference=policy=="normal_navigation";
        }
        if(departure["exit_straight_length"]) config.distances.exit_straight_length=departure["exit_straight_length"].as<double>();
        if(departure["departure_distance"]) config.distances.departure_distance=departure["departure_distance"].as<double>();
    }
    if(node["publish_debug_markers"]) config.publish_debug_markers=node["publish_debug_markers"].as<bool>();
    if(node["use_global_distances"]) config.use_global_distances=node["use_global_distances"].as<bool>();
    if(!validHoleDistances(config.distances)||!validHoleGeometryParams(config.geometry))
        throw std::runtime_error("Invalid hole_planner preview configuration");
    return config;
}
} // namespace nav_core
