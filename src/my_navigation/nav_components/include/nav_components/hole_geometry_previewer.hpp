#pragma once
#include "nav_components/terrain_region_map.hpp"
#include <nav_core/hole_geometry_yaml.hpp>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

namespace nav_components {
// Stage-one preview only. Does not install planning constraints or change paths.
class HoleGeometryPreviewer {
public:
    void initialize(rclcpp::Node *node, TerrainRegionMap::ConstPtr terrain);
    void setTerrain(TerrainRegionMap::ConstPtr terrain) {terrain_=std::move(terrain);++terrain_revision_;dirty_=true;}
    const std::vector<nav_core::HoleGeometryPreview> &previews() const { return previews_; }
    const nav_core::HolePreviewConfiguration &configuration() const { return config_; }
private:
    void rebuild();
    rclcpp::Node *node_ = nullptr;
    TerrainRegionMap::ConstPtr terrain_;
    nav_core::HolePreviewConfiguration config_;
    nav_core::HolePoint start_;
    bool has_start_ = false, dirty_ = true;
    std::uint64_t start_revision_ = 0, parameter_revision_ = 1, terrain_revision_ = 1;
    std::vector<nav_core::HoleGeometryPreview> previews_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr publisher_;
    rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameter_callback_;
};
} // namespace nav_components
