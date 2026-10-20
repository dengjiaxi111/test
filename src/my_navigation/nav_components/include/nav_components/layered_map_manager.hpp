// nav_components/include/nav_components/layered_map_manager.hpp
// 分层地图管理器 - 融合静态地图与动态局部障碍物层

#pragma once

#include <atomic>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <nav_core/map_interface.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "nav_components/static_map_loader.hpp"
#include <nav_core/raster_edit.hpp>
#include "nav_components/costmap_inflater.hpp"
#include "nav_components/esdf_map.hpp"
#include "nav_components/terrain_region_map.hpp"

namespace nav_components {

/**
 * @brief 分层地图管理器
 *
 * 仅负责静态占据层、动态障碍层、膨胀代价地图和 ESDF。
 * 启动时可用独立 hole_clearance 模块处理静态投影。动态融合不清除语义区域。
 * 具体路径约束由独立规划模块实现提供。
 */
class LayeredMapManager : public nav_core::MapInterface {
public:
    using Ptr = std::shared_ptr<LayeredMapManager>;

    LayeredMapManager();
    ~LayeredMapManager() = default;

    void initialize(rclcpp::Node* node,
                    std::shared_ptr<tf2_ros::Buffer> tf_buffer);

    bool loadStaticMap(const std::string& yaml_path,
                       const InflationParams& params);
    void setHoleClearance(const TerrainRegionMap::ConstPtr& terrain, bool enabled,
                          double before_distance, double after_distance);
    bool reloadTerrainClearance(const std::string &map_path, TerrainRegionMap::ConstPtr terrain,
                               std::string *error);
    void setStaticMap(nav_msgs::msg::OccupancyGrid::SharedPtr map);
    struct TemporaryMapSnapshot {
        nav_msgs::msg::OccupancyGrid source;
        std::vector<std::uint32_t> indices;
        std::vector<int8_t> values;
        std::string source_id;
        std::uint64_t revision=0;
    };
    TemporaryMapSnapshot temporaryMapSnapshot() const;
    bool applyTemporaryEdits(const std::string &source_id, std::uint64_t expected_revision,
        const std::vector<std::uint32_t> &indices, const std::vector<int8_t> &values,
        std::string *error);

    void setInflationParams(const InflationParams& params);

    void createBlankStaticMap(double width_m, double height_m,
                              double resolution,
                              const InflationParams& params);

    void updateDynamicLayer(
        const nav_msgs::msg::OccupancyGrid::SharedPtr& local_map);

    nav_msgs::msg::OccupancyGrid::SharedPtr getStaticMap() const;
    nav_msgs::msg::OccupancyGrid::SharedPtr getFusedMap() const;
    nav_msgs::msg::OccupancyGrid::SharedPtr getCostmap() const;
    nav_msgs::msg::OccupancyGrid::SharedPtr getEsdfVis() const;
    EsdfMap::Ptr getEsdf() const;

    bool hasMap() const { return static_map_ != nullptr; }
    bool hasEsdf() const { return esdf_ != nullptr; }

    void setEsdfEnabled(bool enabled) { esdf_enabled_ = enabled; }
    void setEsdfVisMaxDist(double dist) { esdf_vis_max_dist_ = dist; }
    void setEnablePerformanceLogging(bool enabled) {
        enable_performance_logging_ = enabled;
    }
    void setStaticLayerEnabled(bool enabled) {
        static_layer_enabled_ = enabled;
    }

    nav_core::MapType type() const override {
        return nav_core::MapType::COSTMAP;
    }
    double resolution() const override { return resolution_; }
    bool hasDistance() const override { return esdf_ != nullptr; }

    void getBounds(double& min_x, double& min_y,
                   double& max_x, double& max_y) const override;
    nav_core::MapQuery query(double x, double y) const override;

    double getEsdfDistanceWithGradient(double x, double y,
                                       double* gx, double* gy) const;

    void setObstacleThreshold(int8_t thresh) {
        obstacle_threshold_ = thresh;
    }

private:
    // 调用方持有 map_mutex_。全部图层构建成功后统一替换，异常不改变旧快照。
    void adoptRasterSnapshot(nav_msgs::msg::OccupancyGrid::SharedPtr source,
        TerrainRegionMap::ConstPtr terrain, std::vector<int8_t> overrides);
    void rebuildFusedMap();
    void rebuildCostmap();
    void rebuildCostmapFromEsdf();
    void rebuildEsdf();

    bool transformOdomToMap(double ox, double oy,
                            double& mx, double& my) const;

    rclcpp::Node* node_ = nullptr;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    rclcpp::Logger logger_;

    nav_msgs::msg::OccupancyGrid::SharedPtr source_map_;  // 清障前的原始地图，临时应用绝不改写它
    std::vector<int8_t> raster_overrides_;  // 清障后应用，优先于洞口清障
    std::uint64_t raster_revision_=0;
    nav_msgs::msg::OccupancyGrid::SharedPtr static_map_;
    nav_msgs::msg::OccupancyGrid::SharedPtr dynamic_map_;
    // 最近一次动态网格投影的实际占用，包含与静态障碍重叠的格子，重载 Terrain 时保留。
    std::vector<std::pair<std::size_t, int8_t>> dynamic_obstacles_;
    nav_msgs::msg::OccupancyGrid::SharedPtr fused_map_;
    nav_msgs::msg::OccupancyGrid::SharedPtr costmap_;
    nav_msgs::msg::OccupancyGrid::SharedPtr esdf_vis_;
    EsdfMap::Ptr esdf_;

    InflationParams inflation_params_;
    double resolution_ = 0.05;
    double origin_x_ = 0.0;
    double origin_y_ = 0.0;
    int width_ = 0;
    int height_ = 0;
    int8_t obstacle_threshold_ = 50;

    std::atomic<bool> esdf_enabled_{false};
    double esdf_vis_max_dist_ = 2.0;

    bool static_layer_enabled_ = true;
    bool enable_performance_logging_ = false;
    TerrainRegionMap::ConstPtr terrain_regions_;
    bool hole_clearance_enabled_ = false;
    double hole_clearance_before_ = 0.0;
    double hole_clearance_after_ = 0.0;

    std::string map_frame_ = "map";
    std::string odom_frame_ = "odom";

    mutable std::mutex map_mutex_;

    struct DynamicLayerBounds {
        int min_x = 0;
        int max_x = 0;
        int min_y = 0;
        int max_y = 0;
        bool valid = false;
    } last_dynamic_bounds_;
};

}  // namespace nav_components
