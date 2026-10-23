// nav_components/src/layered_map_manager.cpp
// 分层地图管理器实现

#include "nav_components/layered_map_manager.hpp"
#include "nav_components/hole_clearance.hpp"
#include <tf2/utils.h>
#include <algorithm>
#include <cmath>
#include <chrono>

namespace nav_components {
namespace {
constexpr int8_t kInflatedCostObstacleThreshold = 99;
}

LayeredMapManager::LayeredMapManager()
    : logger_(rclcpp::get_logger("layered_map_manager")) {}

void LayeredMapManager::initialize(rclcpp::Node* node,
                                    std::shared_ptr<tf2_ros::Buffer> tf_buffer) {
    node_ = node;
    tf_buffer_ = tf_buffer;
    logger_ = node_->get_logger();
    
    // 读取坐标系参数
    node_->get_parameter_or<std::string>("map_frame", map_frame_, map_frame_);
    node_->get_parameter_or<std::string>("odom_frame", odom_frame_, odom_frame_);

    // 读取性能日志开关（默认 false）
    node_->get_parameter_or<bool>("enable_performance_logging", enable_performance_logging_, enable_performance_logging_);
    
    RCLCPP_INFO(logger_, "LayeredMapManager initialized (map: %s, odom: %s, perf_log: %s)",
                map_frame_.c_str(), odom_frame_.c_str(), 
                enable_performance_logging_ ? "enabled" : "disabled");
}

void LayeredMapManager::setHoleClearance(const TerrainRegionMap::ConstPtr& terrain,
                                         bool enabled, double before_distance,
                                         double after_distance) {
    terrain_regions_ = terrain;
    hole_clearance_enabled_ = enabled;
    hole_clearance_before_ = before_distance;
    hole_clearance_after_ = after_distance;
}

void LayeredMapManager::adoptRasterSnapshot(nav_msgs::msg::OccupancyGrid::SharedPtr source,
        TerrainRegionMap::ConstPtr terrain, std::vector<int8_t> overrides) {
    nav_core::validateRaster(*source);
    auto next=std::make_shared<nav_msgs::msg::OccupancyGrid>(*source);
    if(hole_clearance_enabled_ && terrain) {
        std::string error;
        if(!clearHoleApproachAreas(*next,*terrain,hole_clearance_before_,hole_clearance_after_,nullptr,&error))
            throw std::runtime_error(error);
    }
    nav_core::applyRasterOverrides(*next,overrides);
    next->header.stamp=node_->now();
    auto fused=std::make_shared<nav_msgs::msg::OccupancyGrid>(*next);
    for(const auto &[index,value]:dynamic_obstacles_)
        fused->data[index]=std::max(fused->data[index],value);
    auto costmap=CostmapInflater::inflate(fused,inflation_params_,obstacle_threshold_);
    if(!costmap)throw std::runtime_error("新地图膨胀失败，保留旧地图");
    costmap->header.frame_id=map_frame_;
    EsdfMap::Ptr esdf;
    nav_msgs::msg::OccupancyGrid::SharedPtr vis;
    if(esdf_enabled_) {
        esdf=std::make_shared<EsdfMap>();esdf->buildFromOccupancy(fused,obstacle_threshold_);
        vis=esdf->toOccupancyGrid(esdf_vis_max_dist_);
        if(vis)vis->header.frame_id=map_frame_;
    }
    source_map_=std::move(source);raster_overrides_=std::move(overrides);
    terrain_regions_=std::move(terrain);static_map_=std::move(next);fused_map_=std::move(fused);
    costmap_=std::move(costmap);esdf_=std::move(esdf);esdf_vis_=std::move(vis);
    ++raster_revision_;
}

LayeredMapManager::TemporaryMapSnapshot LayeredMapManager::temporaryMapSnapshot() const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    if(!source_map_)throw std::runtime_error("导航尚未加载原始地图");
    TemporaryMapSnapshot result;result.source=*source_map_;result.revision=raster_revision_;
    result.source_id=nav_core::rasterSourceId(*source_map_);
    nav_core::sparseRasterOverrides(raster_overrides_,result.indices,result.values);
    return result;
}

bool LayeredMapManager::applyTemporaryEdits(const std::string &source_id,std::uint64_t expected_revision,
        const std::vector<std::uint32_t> &indices,const std::vector<int8_t> &values,std::string *error) {
    try {
        std::lock_guard<std::mutex> lock(map_mutex_);
        if(!static_layer_enabled_)throw std::runtime_error("静态地图层未启用，不能应用静态笔迹");
        if(!source_map_ || source_id!=nav_core::rasterSourceId(*source_map_))
            throw std::runtime_error("原始地图不一致，请读取导航当前状态");
        if(expected_revision!=raster_revision_)
            throw std::runtime_error("地图版本已变化，请读取导航当前状态后重新编辑");
        auto overrides=nav_core::rasterOverrides(source_map_->data.size(),indices,values);
        adoptRasterSnapshot(source_map_,terrain_regions_,std::move(overrides));
        return true;
    } catch(const std::exception &e) {if(error)*error=e.what();return false;}
}

bool LayeredMapManager::reloadTerrainClearance(const std::string &map_path,
        TerrainRegionMap::ConstPtr terrain,std::string *error) {
    try {
        auto next=StaticMapLoader::load(map_path,logger_);
        if(!next)throw std::runtime_error("静态地图读取失败，旧地图保持不变");
        const auto origin=YAML::LoadFile(map_path)["origin"];
        if(origin.size()>2 && (!std::isfinite(origin[2].as<double>()) || std::abs(origin[2].as<double>())>1e-6))
            throw std::runtime_error("地图原点旋转不支持临时修改");
        std::lock_guard<std::mutex> lock(map_mutex_);
        if(!source_map_ || !nav_core::sameRasterGeometry(*next,*source_map_))
            throw std::runtime_error("Terrain 重载不能同时更换地图尺寸或原点");
        adoptRasterSnapshot(std::move(next),std::move(terrain),raster_overrides_);
        return true;
    } catch(const std::exception &e) {if(error)*error=e.what();return false;}
}

bool LayeredMapManager::loadStaticMap(const std::string& yaml_path,
                                       const InflationParams& params) {
    std::lock_guard<std::mutex> lock(map_mutex_);
    
    static_map_ = StaticMapLoader::load(yaml_path, logger_);
    if (!static_map_) {
        RCLCPP_ERROR(logger_, "Failed to load static map from: %s", yaml_path.c_str());
        return false;
    }
    source_map_=std::make_shared<nav_msgs::msg::OccupancyGrid>(*static_map_);
    raster_overrides_.assign(source_map_->data.size(),nav_core::kNoRasterOverride);
    ++raster_revision_;
    if (hole_clearance_enabled_ && terrain_regions_) {
        // LayeredMapManager uses axis-aligned global grid indexing throughout.
        const auto origin = YAML::LoadFile(yaml_path)["origin"];
        if (origin.size() > 2 &&
            (!std::isfinite(origin[2].as<double>()) || std::abs(origin[2].as<double>()) > 1e-6)) {
            RCLCPP_ERROR(logger_, "Hole static clearing requires map YAML origin yaw=0");
            static_map_.reset();
            return false;
        }
        std::size_t changed = 0;
        std::string error;
        if (!clearHoleApproachAreas(*static_map_, *terrain_regions_, hole_clearance_before_,
                                    hole_clearance_after_, &changed, &error)) {
            RCLCPP_ERROR(logger_, "Hole clearance preprocessing failed: %s", error.c_str());
            static_map_.reset();
            return false;
        }
        RCLCPP_INFO(logger_, "Hole clearance preprocessing: %zu occupied cells cleared (before=%.2f m, after=%.2f m)",
                    changed, hole_clearance_before_, hole_clearance_after_);
    }
    
    inflation_params_ = params;
    
    // 提取地图元数据
    resolution_ = static_map_->info.resolution;
    origin_x_ = static_map_->info.origin.position.x;
    origin_y_ = static_map_->info.origin.position.y;
    width_ = static_map_->info.width;
    height_ = static_map_->info.height;
    map_frame_ = static_map_->header.frame_id.empty() ? "map" : static_map_->header.frame_id;
    
    // 初始化融合地图（与静态地图相同大小）
    fused_map_ = std::make_shared<nav_msgs::msg::OccupancyGrid>();
    *fused_map_ = *static_map_;  // 初始时等于静态地图
    dynamic_obstacles_.clear();last_dynamic_bounds_={};

    
    // 构建costmap
    rebuildCostmap();
    
    // 如果启用ESDF，构建初始ESDF
    if (esdf_enabled_) {
        rebuildEsdf();
    }
    
    RCLCPP_INFO(logger_, "Static map loaded: %dx%d @ %.3f m/cell, inflation_radius=%.2f",
                width_, height_, resolution_, params.inflation_radius);
    return true;
}

void LayeredMapManager::setStaticMap(nav_msgs::msg::OccupancyGrid::SharedPtr map) {
    if (!map) return;
    
    std::lock_guard<std::mutex> lock(map_mutex_);
    static_map_ = map;
    source_map_=std::make_shared<nav_msgs::msg::OccupancyGrid>(*map);
    raster_overrides_.assign(map->data.size(),nav_core::kNoRasterOverride);
    ++raster_revision_;
    
    resolution_ = map->info.resolution;
    origin_x_ = map->info.origin.position.x;
    origin_y_ = map->info.origin.position.y;
    width_ = map->info.width;
    height_ = map->info.height;
    map_frame_ = map->header.frame_id.empty() ? "map" : map->header.frame_id;
    
    // 初始化融合地图
    fused_map_ = std::make_shared<nav_msgs::msg::OccupancyGrid>();
    *fused_map_ = *static_map_;
    dynamic_obstacles_.clear();last_dynamic_bounds_={};

    
    rebuildCostmap();
    if (esdf_enabled_) {
        rebuildEsdf();
    }
}

void LayeredMapManager::setInflationParams(const InflationParams& params) {
    std::lock_guard<std::mutex> lock(map_mutex_);
    inflation_params_ = params;
    if (fused_map_) {
        rebuildCostmap();
    }
}

void LayeredMapManager::createBlankStaticMap(double width_m, double height_m,
                                              double resolution, const InflationParams& params) {
    std::lock_guard<std::mutex> lock(map_mutex_);
    
    // 计算栅格尺寸
    int width = static_cast<int>(std::ceil(width_m / resolution));
    int height = static_cast<int>(std::ceil(height_m / resolution));
    
    // 创建空白地图
    static_map_ = std::make_shared<nav_msgs::msg::OccupancyGrid>();
    static_map_->header.frame_id = map_frame_;
    static_map_->header.stamp = node_->get_clock()->now();
    
    static_map_->info.resolution = resolution;
    static_map_->info.width = width;
    static_map_->info.height = height;
    
    // 地图中心在原点
    static_map_->info.origin.position.x = -width_m / 2.0;
    static_map_->info.origin.position.y = -height_m / 2.0;
    static_map_->info.origin.position.z = 0.0;
    static_map_->info.origin.orientation.w = 1.0;
    
    // 全部初始化为自由空间 (0)
    static_map_->data.resize(width * height, 0);
    source_map_=std::make_shared<nav_msgs::msg::OccupancyGrid>(*static_map_);
    raster_overrides_.assign(source_map_->data.size(),nav_core::kNoRasterOverride);
    ++raster_revision_;
    
    // 更新成员变量
    resolution_ = static_map_->info.resolution; // Use the published float32 grid resolution consistently.
    origin_x_ = static_map_->info.origin.position.x;
    origin_y_ = static_map_->info.origin.position.y;
    width_ = width;
    height_ = height;
    
    // 初始化融合地图
    fused_map_ = std::make_shared<nav_msgs::msg::OccupancyGrid>();
    *fused_map_ = *static_map_;
    dynamic_obstacles_.clear();last_dynamic_bounds_={};

    
    // 设置膨胀参数并构建Costmap
    inflation_params_ = params;
    rebuildCostmap();
    
    if (esdf_enabled_) {
        rebuildEsdf();
    }
    
    RCLCPP_INFO(logger_, "创建空白静态地图: %dx%d (%.1fm x %.1fm) @ %.3f m/cell",
                width, height, width_m, height_m, resolution);
}

void LayeredMapManager::updateDynamicLayer(
    const nav_msgs::msg::OccupancyGrid::SharedPtr& local_map) {
    
    if (!local_map || !static_map_) {
        return;
    }
    if(local_map->header.frame_id.empty() || !std::isfinite(local_map->info.resolution) ||
       local_map->info.resolution<=0 || local_map->info.width==0 || local_map->info.height==0 ||
       local_map->data.size()!=size_t(local_map->info.width)*local_map->info.height) {
        RCLCPP_WARN_THROTTLE(logger_,*node_->get_clock(),2000,"Reject malformed dynamic grid");
        return;
    }
    
    std::lock_guard<std::mutex> lock(map_mutex_);
    
    // 1. 按消息声明的坐标系变换到map，不将所有动态网格误当成odom。
    geometry_msgs::msg::TransformStamped transform;
    try {
        transform = tf_buffer_->lookupTransform(
            map_frame_, local_map->header.frame_id, tf2::TimePointZero);
    } catch (const tf2::TransformException& ex) {
        RCLCPP_WARN_THROTTLE(logger_, *node_->get_clock(), 2000,
            "Cannot get %s->%s transform: %s", local_map->header.frame_id.c_str(), map_frame_.c_str(), ex.what());
        return;
    }
    
    // 2. 重置融合地图
    if (!fused_map_) {
        fused_map_ = std::make_shared<nav_msgs::msg::OccupancyGrid>();
    }
    
    if (static_layer_enabled_) {
        // 静态层启用：融合地图初始化为静态地图
        *fused_map_ = *static_map_;
    } else {
        // 静态层禁用：融合地图初始化为空白（仅保留动态层）
        *fused_map_ = *static_map_;  // 复用结构
        std::fill(fused_map_->data.begin(), fused_map_->data.end(), 0);  // 清空为free space
    }
    fused_map_->header.stamp = node_->get_clock()->now();
    dynamic_obstacles_.clear();
    
    // 3. 变换参数
    double tx = transform.transform.translation.x;
    double ty = transform.transform.translation.y;
    double yaw = tf2::getYaw(transform.transform.rotation);
    double cos_yaw = std::cos(yaw);
    double sin_yaw = std::sin(yaw);
    
    // 局部地图参数
    double local_res = local_map->info.resolution;
    double local_ox = local_map->info.origin.position.x;
    double local_oy = local_map->info.origin.position.y;
    const double local_yaw=tf2::getYaw(local_map->info.origin.orientation);
    const double local_cos=std::cos(local_yaw),local_sin=std::sin(local_yaw);
    int local_w = local_map->info.width;
    int local_h = local_map->info.height;
    
    // 4. 记录变化区域用于增量ESDF更新
    std::vector<int> changed_cells;
    changed_cells.reserve(local_w * local_h / 4);  // 预估25%变化
    
    DynamicLayerBounds new_bounds;
    new_bounds.min_x = width_;
    new_bounds.min_y = height_;
    new_bounds.max_x = 0;
    new_bounds.max_y = 0;
    
    // 5. 遍历局部地图，投影到全局地图
    for (int ly = 0; ly < local_h; ++ly) {
        for (int lx = 0; lx < local_w; ++lx) {
            int local_idx = ly * local_w + lx;
            int8_t local_val = local_map->data[local_idx];
            
            // 跳过unknown和free（只叠加障碍物）
            if (local_val <= 0) {
                continue;
            }
            
            // 局部栅格中心的odom坐标
            const double cell_x=(lx+0.5)*local_res,cell_y=(ly+0.5)*local_res;
            double odom_x = local_ox + local_cos*cell_x-local_sin*cell_y;
            double odom_y = local_oy + local_sin*cell_x+local_cos*cell_y;
            
            // 变换到map坐标系
            double map_x = cos_yaw * odom_x - sin_yaw * odom_y + tx;
            double map_y = sin_yaw * odom_x + cos_yaw * odom_y + ty;
            
            // 计算全局地图索引
            int gx = static_cast<int>(std::floor((map_x - origin_x_) / resolution_));
            int gy = static_cast<int>(std::floor((map_y - origin_y_) / resolution_));
            
            // 边界检查
            if (gx < 0 || gx >= width_ || gy < 0 || gy >= height_) {
                continue;
            }
            
            int global_idx = gy * width_ + gx;
            dynamic_obstacles_.emplace_back(global_idx,local_val);
            
            // 融合策略
            int8_t fused_val;
            if (static_layer_enabled_) {
                // 静态层启用：取max（保守，障碍物优先）
                int8_t static_val = static_map_->data[global_idx];
                fused_val = std::max(static_val, local_val);
            } else {
                // 静态层禁用：直接使用动态层的值
                fused_val = local_val;
            }
            
            // 记录变化
            if (fused_map_->data[global_idx] != fused_val) {
                fused_map_->data[global_idx] = fused_val;
                changed_cells.push_back(global_idx);
                
                // 更新边界
                new_bounds.min_x = std::min(new_bounds.min_x, gx);
                new_bounds.max_x = std::max(new_bounds.max_x, gx);
                new_bounds.min_y = std::min(new_bounds.min_y, gy);
                new_bounds.max_y = std::max(new_bounds.max_y, gy);
            }
        }
    }
    
    new_bounds.valid = !changed_cells.empty();
    
    // 6. 清除上一次动态层的残留（在新边界外的部分）
    // 保存旧边界用于后续计算
    DynamicLayerBounds old_bounds = last_dynamic_bounds_;
    
    if (old_bounds.valid) {
        for (int gy = old_bounds.min_y; gy <= old_bounds.max_y; ++gy) {
            for (int gx = old_bounds.min_x; gx <= old_bounds.max_x; ++gx) {
                // 跳过当前边界内的栅格（已经更新过了）
                if (new_bounds.valid &&
                    gx >= new_bounds.min_x && gx <= new_bounds.max_x &&
                    gy >= new_bounds.min_y && gy <= new_bounds.max_y) {
                    continue;
                }
                
                int idx = gy * width_ + gx;
                if (idx >= 0 && idx < width_ * height_) {
                    // 恢复基础值
                    int8_t base_val = static_layer_enabled_ ? static_map_->data[idx] : 0;
                    if (fused_map_->data[idx] != base_val) {
                        fused_map_->data[idx] = base_val;
                        changed_cells.push_back(idx);
                    }
                }
            }
        }
    }
    
    // 更新边界记录
    last_dynamic_bounds_ = new_bounds;

    
    // 7. 共享EDT计算优化：ESDF和Costmap复用同一次距离场计算
    auto t_start = std::chrono::high_resolution_clock::now();
    
    // 构建ESDF（含EDT计算）
    if (esdf_enabled_) {
        esdf_ = std::make_shared<EsdfMap>();
        esdf_->buildFromOccupancy(fused_map_, obstacle_threshold_);
    }
    auto t_esdf = std::chrono::high_resolution_clock::now();
    
    // 从ESDF复用距离场生成Costmap
    if (esdf_ && esdf_->hasDistance()) {
        rebuildCostmapFromEsdf();
    } else {
        rebuildCostmap();  // Fallback
    }
    auto t_costmap = std::chrono::high_resolution_clock::now();
    
    // 生成ESDF可视化
    if (esdf_enabled_ && esdf_) {
        esdf_vis_ = esdf_->toOccupancyGrid(esdf_vis_max_dist_);
        if (esdf_vis_) {
            esdf_vis_->header.frame_id = map_frame_;
        }
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    
    // 性能日志（根据开关决定是否输出）
    if (enable_performance_logging_) {
        auto dur_esdf = std::chrono::duration_cast<std::chrono::microseconds>(t_esdf - t_start);
        auto dur_costmap = std::chrono::duration_cast<std::chrono::microseconds>(t_costmap - t_esdf);
        auto dur_vis = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_costmap);
        auto dur_total = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start);
        
        RCLCPP_INFO_THROTTLE(logger_, *node_->get_clock(), 1000,
            "[共享EDT] ESDF: %.2f ms | Costmap: %.2f ms | Vis: %.2f ms | Total: %.2f ms (节省: %.0f%%)",
            dur_esdf.count() / 1000.0, dur_costmap.count() / 1000.0,
            dur_vis.count() / 1000.0, dur_total.count() / 1000.0,
            100.0 * (103.0 - dur_total.count() / 1000.0) / 103.0);
    }
}

void LayeredMapManager::rebuildFusedMap() {
    // 当前实现：在updateDynamicLayer中直接完成
    // 此函数保留用于未来扩展（如多动态层融合）
}

void LayeredMapManager::rebuildCostmap() {
    if (!fused_map_) return;
    costmap_ = CostmapInflater::inflate(fused_map_, inflation_params_, obstacle_threshold_);
    if (costmap_) {
        costmap_->header.frame_id = map_frame_;
    }
}

void LayeredMapManager::rebuildCostmapFromEsdf() {
    if (!fused_map_ || !esdf_) return;
    
    // 从ESDF获取距离场数据
    std::vector<float> distances(width_ * height_);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            int idx = y * width_ + x;
            distances[idx] = esdf_->getDistanceFast(x, y);
        }
    }
    
    // 使用距离场直接生成costmap（无需重复EDT计算）
    costmap_ = CostmapInflater::fromEsdf(
        distances, width_, height_, resolution_,
        origin_x_, origin_y_, inflation_params_);
    
    if (costmap_) {
        costmap_->header.frame_id = map_frame_;
        costmap_->header.stamp = node_->get_clock()->now();
    }
}

void LayeredMapManager::rebuildEsdf() {
    // 仅用于初始化时的ESDF构建（loadStaticMap/setStaticMap调用）
    // 运行时的ESDF在updateDynamicLayer中与costmap共享EDT构建
    if (!fused_map_) return;
    
    esdf_ = std::make_shared<EsdfMap>();
    esdf_->buildFromOccupancy(fused_map_, obstacle_threshold_);
    esdf_vis_ = esdf_->toOccupancyGrid(esdf_vis_max_dist_);
    if (esdf_vis_) {
        esdf_vis_->header.frame_id = map_frame_;
    }
}

bool LayeredMapManager::transformOdomToMap(double ox, double oy,
                                            double& mx, double& my) const {
    if (!tf_buffer_) {
        return false;
    }
    
    try {
        geometry_msgs::msg::TransformStamped transform =
            tf_buffer_->lookupTransform(map_frame_, odom_frame_, tf2::TimePointZero);
        
        double tx = transform.transform.translation.x;
        double ty = transform.transform.translation.y;
        double yaw = tf2::getYaw(transform.transform.rotation);
        
        mx = std::cos(yaw) * ox - std::sin(yaw) * oy + tx;
        my = std::sin(yaw) * ox + std::cos(yaw) * oy + ty;
        return true;
    } catch (const tf2::TransformException&) {
        return false;
    }
}

// ============ 获取地图 ============

nav_msgs::msg::OccupancyGrid::SharedPtr LayeredMapManager::getStaticMap() const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    return static_map_;
}

nav_msgs::msg::OccupancyGrid::SharedPtr LayeredMapManager::getFusedMap() const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    return fused_map_;
}

nav_msgs::msg::OccupancyGrid::SharedPtr LayeredMapManager::getCostmap() const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    return costmap_;
}

nav_msgs::msg::OccupancyGrid::SharedPtr LayeredMapManager::getEsdfVis() const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    return esdf_vis_;
}

EsdfMap::Ptr LayeredMapManager::getEsdf() const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    return esdf_;
}

// ============ MapInterface实现 ============

void LayeredMapManager::getBounds(double& min_x, double& min_y,
                                   double& max_x, double& max_y) const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    min_x = origin_x_;
    min_y = origin_y_;
    max_x = origin_x_ + width_ * resolution_;
    max_y = origin_y_ + height_ * resolution_;
}

nav_core::MapQuery LayeredMapManager::query(double x, double y) const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    
    nav_core::MapQuery result;
    if (!costmap_) return result;
    if(!std::isfinite(x) || !std::isfinite(y) || resolution_<=0 ||
       x<origin_x_ || y<origin_y_ || x>=origin_x_+width_*resolution_ ||
       y>=origin_y_+height_*resolution_) return result;
    
    int mx = static_cast<int>((x - origin_x_) / resolution_);
    int my = static_cast<int>((y - origin_y_) / resolution_);
    
    if (mx < 0 || mx >= width_ || my < 0 || my >= height_) {
        return result;
    }
    
    result.valid = true;
    int8_t val = costmap_->data[my * width_ + mx];
    // 膨胀代价图按规划验收的99阈值查询；原始占据图生成ESDF的阈值保持独立。
    result.occupied = (val < 0 || val >= kInflatedCostObstacleThreshold);
    result.cost = (val >= 0) ? val / 100.0 : 1.0;
    
    // 如果有ESDF，填充距离信息
    if (esdf_) {
        result.distance = esdf_->getDistanceFast(mx, my);
    }
    return result;
}

double LayeredMapManager::getEsdfDistanceWithGradient(double x, double y,
                                                       double* gx, double* gy) const {
    std::lock_guard<std::mutex> lock(map_mutex_);
    
    if (!esdf_) {
        if (gx) *gx = 0;
        if (gy) *gy = 0;
        return 1e6;
    }
    
    double dist = esdf_->getDistanceInterp(x, y);
    
    if (gx && gy) {
        esdf_->getGradient(x, y, *gx, *gy);
    }
    
    return dist;
}

}  // namespace nav_components
