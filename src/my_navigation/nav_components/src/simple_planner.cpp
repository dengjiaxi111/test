// nav_components/src/simple_planner.cpp
// A* 路径规划 + B样条平滑 + B样条优化

#include "nav_components/simple_planner.hpp"
#include "nav_components/layered_map_manager.hpp"
#include <cmath>
#include <algorithm>
#include <limits>
#include <utility>
#include "nav_components/planner/normal_navigation_segment.hpp"

namespace nav_components {

void SimplePlanner::initialize(rclcpp::Node* node) {
    node_ = node;
    hole_passage_planner_.initialize(node);
    obstacle_threshold_ = node_->declare_parameter("planner.obstacle_threshold", 99);
    cost_weight_ = node_->declare_parameter("planner.cost_weight", 0.5);
    enable_smooth_ = node_->declare_parameter("planner.enable_smooth", true);
    
    enable_path_cache_ = node_->declare_parameter("planner.enable_path_cache", true);
    enable_auto_prune_ = node_->declare_parameter("planner.enable_auto_prune", true);
    goal_change_tolerance_ = node_->declare_parameter("planner.goal_change_tolerance", 0.2);
    obstacle_check_threshold_ = node_->declare_parameter("planner.obstacle_check_threshold", 95);
    esdf_warn_min_safe_dist_ = node_->declare_parameter("planner.esdf_warn_min_safe_dist", 0.12);
    start_deviation_threshold_ = node_->declare_parameter("planner.start_deviation_threshold", 1.0);
    astar_max_attempts_ = node_->declare_parameter("planner.astar_max_attempts", 2);
    astar_max_iterations_ = node_->declare_parameter("planner.astar_max_iterations", 0);
    astar_threshold_step_ = node_->declare_parameter("planner.astar_threshold_step", 10);
    prune_distance_ = node_->declare_parameter("planner.prune_distance", 0.5);
    publish_astar_raw_path_ = node_->declare_parameter("planner.publish_astar_raw_path", true);
    allow_raw_fallback_on_smooth_fail_ =
        node_->declare_parameter("planner.allow_raw_fallback_on_smooth_fail", false);
    publish_failure_debug_markers_ =
        node_->declare_parameter("planner.publish_failure_debug_markers", true);
    failure_marker_scale_ =
        node_->declare_parameter("planner.failure_marker_scale", 0.14);
    if (astar_max_attempts_ < 1) {
        RCLCPP_WARN(node_->get_logger(),
            "planner.astar_max_attempts=%d 非法，自动修正为 1", astar_max_attempts_);
        astar_max_attempts_ = 1;
    }
    if (astar_threshold_step_ < 0) {
        RCLCPP_WARN(node_->get_logger(),
            "planner.astar_threshold_step=%d 非法，自动修正为 0", astar_threshold_step_);
        astar_threshold_step_ = 0;
    }
    SmoothParams smooth_params;
    smooth_params.resample_interval = node_->declare_parameter("planner.resample_interval", 0.3);
    smooth_params.output_resolution = node_->declare_parameter("planner.smooth_resolution", 0.05);
    
    // 优化参数
    smooth_params.enable_optimization = node_->declare_parameter("planner.enable_optimization", true);
    smooth_params.lambda_smooth = node_->declare_parameter("planner.opt_lambda_smooth", 10.0);
    smooth_params.lambda_collision = node_->declare_parameter("planner.opt_lambda_collision", 5.0);
    smooth_params.safe_dist = node_->declare_parameter("planner.opt_safe_dist", 0.3);
    smooth_params.opt_max_iter = node_->declare_parameter("planner.opt_max_iter", 50);
    
    // 曲率自适应参数
    smooth_params.curvature_adaptive = node_->declare_parameter("planner.opt_curvature_adaptive", true);
    smooth_params.curvature_weight = node_->declare_parameter("planner.opt_curvature_weight", 2.0);
    
    // 窄通道中心吸引参数
    smooth_params.narrow_passage_align = node_->declare_parameter("planner.narrow_passage_align", true);
    smooth_params.narrow_passage_thresh = node_->declare_parameter("planner.narrow_passage_thresh", 0.6);
    smooth_params.lambda_align = node_->declare_parameter("planner.opt_lambda_align", 3.0);
    smooth_params.align_entry_points = node_->declare_parameter("planner.align_entry_points", 2);
    smooth_params.narrow_min_consecutive = node_->declare_parameter("planner.narrow_min_consecutive", 3);
    smoother_.setParams(smooth_params);
    hole_passage_planner_.setNormalSegmentPlanner([this](auto start,auto tangent,auto goal,
            const auto &map,double threshold,const auto &collision,const auto &hull,auto deadline) {
        const auto seed_search=[&](nav_core::HolePoint a,nav_core::HolePoint b,
                std::vector<nav_core::HolePoint> &points,int &expansions) {
            int sx,sy,gx,gy;
            if(!worldToMap(a.x,a.y,sx,sy)||!worldToMap(b.x,b.y,gx,gy))return false;
            nav_msgs::msg::Path seed;std_msgs::msg::Header header;header.frame_id="map";
            const auto saved_deadline=hole_request_deadline_;const auto saved_threshold=obstacle_threshold_;
            hole_request_deadline_=std::min(hole_request_deadline_,deadline);
            obstacle_threshold_=static_cast<int8_t>(threshold);
            const bool ok=runAstar(sx,sy,gx,gy,header,seed,nullptr,nullptr,collision,&expansions);
            hole_request_deadline_=saved_deadline;obstacle_threshold_=saved_threshold;
            for(const auto &pose:seed.poses)points.push_back({pose.pose.position.x,pose.pose.position.y});
            if(ok&&points.size()==1&&nav_core::holeNorm(b-a)>1e-9)points.push_back(b);
            return ok;
        };
        return planNormalNavigationSegment(start,tangent,goal,smoother_,map,threshold,collision,hull,
            node_->get_parameter("hole_planner.search.sample_resolution").as_double(),
            static_cast<int>(node_->get_parameter("hole_planner.search.max_expansions").as_int()),
            deadline,seed_search,node_->get_parameter("hole_planner.connection.enforce_max_curvature").as_bool()?
                std::optional<double>{node_->get_parameter("hole_planner.connection.max_curvature").as_double()}:std::nullopt);
    });
    
    // 创建调试可视化发布器
    astar_raw_path_pub_ = node_->create_publisher<nav_msgs::msg::Path>(
        "plan_astar_raw", 10);
    ctrl_pts_pub_ = node_->create_publisher<visualization_msgs::msg::MarkerArray>(
        "debug/control_points", 10);
    plan_failure_pub_ = node_->create_publisher<visualization_msgs::msg::MarkerArray>(
        "debug/planner_failures", 10);
}

void SimplePlanner::setSpecialTerrainConstraint(
    nav_core::SpecialTerrainConstraint::Ptr constraint) {
    special_terrain_constraint_ = std::move(constraint);
    smoother_.setSpecialTerrainConstraint(special_terrain_constraint_);
    clearCache();
}

void SimplePlanner::setTerrainRegionMap(TerrainRegionMap::ConstPtr regions,bool preserve_commitment) {
    terrain_regions_ = std::move(regions);
    hole_passage_planner_.setTerrain(terrain_regions_,preserve_commitment);
    clearCache();
}

void SimplePlanner::setMap(nav_core::MapInterface::Ptr map) {
    map_ = map;
    hole_passage_planner_.setDistanceQuery({});
    
    if (!map) {
        grid_map_ = nullptr;
        map_manager_ = nullptr;
        return;
    }
    
    // 统一使用 LayeredMapManager 提供的 costmap（膨胀后的地图）
    map_manager_ = std::dynamic_pointer_cast<LayeredMapManager>(map);
    if (map_manager_ && map_manager_->getCostmap()) {
        grid_map_ = map_manager_->getCostmap();
        width_ = grid_map_->info.width;
        height_ = grid_map_->info.height;
        resolution_ = grid_map_->info.resolution;
        origin_x_ = grid_map_->info.origin.position.x;
        origin_y_ = grid_map_->info.origin.position.y;
        
        if (map_manager_->hasEsdf()) {
            hole_passage_planner_.setDistanceQuery(
                [this](double x,double y,double *gx,double *gy) {
                    return map_manager_->getEsdfDistanceWithGradient(x,y,gx,gy);
                });
            smoother_.setESDFCallback(
                [this](double x, double y, double* gx, double* gy) -> double {
                    return map_manager_->getEsdfDistanceWithGradient(x, y, gx, gy);
                });
            RCLCPP_INFO(node_->get_logger(), "B样条优化: ESDF 回调已设置");
        }

    } else {
        RCLCPP_ERROR(node_->get_logger(), 
            "SimplePlanner: 需要 LayeredMapManager 且 costmap 可用");
        grid_map_ = nullptr;
    }
}

bool SimplePlanner::worldToMap(double wx, double wy, int& mx, int& my) {
    mx = static_cast<int>((wx - origin_x_) / resolution_);
    my = static_cast<int>((wy - origin_y_) / resolution_);
    return mx >= 0 && mx < width_ && my >= 0 && my < height_;
}

void SimplePlanner::mapToWorld(int mx, int my, double& wx, double& wy) {
    wx = origin_x_ + (mx + 0.5) * resolution_;
    wy = origin_y_ + (my + 0.5) * resolution_;
}

void SimplePlanner::invalidateMapCaches() {
    clearCache();
    hole_passage_planner_.clearConnectionCache();
    if(map_manager_)setMap(map_manager_);
}

void SimplePlanner::clearCache() {
    cached_path_ = nav_msgs::msg::Path();
    cached_path_constrained_=false;
    cached_goal_ = geometry_msgs::msg::PoseStamped();
    hole_passage_planner_.clearDiagnostics();
}

bool SimplePlanner::isValid(int x, int y) {
    if(!blocked_holes_.empty()&&terrain_regions_) {
        const double wx=origin_x_+(x+0.5)*resolution_,wy=origin_y_+(y+0.5)*resolution_;
        for(const auto& region:terrain_regions_->getRegions())if(blocked_holes_.count(region.id)&&
            TerrainRegionMap::pointInPolygon(region.polygon,wx,wy))return false;
    }

    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return false;
    }
    int8_t val = grid_map_->data[y * width_ + x];
    return val >= 0 && val < obstacle_threshold_;
}

// 获取代价值（归一化到 0~1）
double SimplePlanner::getCost(int x, int y) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return 1.0;
    }
    int8_t val = grid_map_->data[y * width_ + x];
    if (val < 0 || val >= obstacle_threshold_) {
        return 1.0;
    }
    return static_cast<double>(val) / 100.0;
}

double SimplePlanner::heuristic(int x1, int y1, int x2, int y2) {
    return std::hypot(x2 - x1, y2 - y1);
}

bool SimplePlanner::findNearestFreeCell(int cx, int cy, int& fx, int& fy, int max_radius) {
    // BFS 螺旋搜索：从 (cx, cy) 开始逐层扩展，找到最近的可通行格子
    // 返回 true 表示找到，结果存入 (fx, fy)
    for (int r = 1; r <= max_radius; ++r) {
        // 搜索正方形环上的所有格子
        for (int dx = -r; dx <= r; ++dx) {
            for (int dy = -r; dy <= r; ++dy) {
                // 只搜索外环（跳过内部已搜过的区域）
                if (std::abs(dx) != r && std::abs(dy) != r) continue;
                
                int nx = cx + dx;
                int ny = cy + dy;
                if (isValid(nx, ny)) {
                    fx = nx;
                    fy = ny;
                    return true;
                }
            }
        }
    }
    return false;
}

bool SimplePlanner::plan(
    const geometry_msgs::msg::PoseStamped& start,
    const geometry_msgs::msg::PoseStamped& goal,
    nav_msgs::msg::Path& path)
{
    const auto request_begin=std::chrono::steady_clock::now();
    double astar_ms=0,outer_validation_ms=0;
    hole_passage_planner_.resetStatistics();
    hole_request_deadline_=std::chrono::steady_clock::time_point::max();
    const auto reset_deadline=std::shared_ptr<void>(nullptr,[&](void*) {
        hole_request_deadline_=std::chrono::steady_clock::time_point::max();
        const auto &stats=hole_passage_planner_.statistics();
        RCLCPP_INFO(node_->get_logger(),"规划汇总: total=%.1fms astar=%.1fms outer_validation=%.1fms hole=%.1fms first_valid=%.1fms post_first=%.1fms | geometry=%.1f connectivity=%.1f candidates=%.1f seed_search=%.1f fit=%.1f curve_check=%.1f candidate_check=%.1f final_check=%.1f cache_check=%.1f ms | optimized=%d fits=%d iterations=%d cache_hits=%d cache_rejected=%d disconnected=%d stop=%s",
            std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-request_begin).count(),
            astar_ms,outer_validation_ms,stats.total_ms,stats.first_valid_ms,stats.post_first_valid_ms,
            stats.geometry_ms,stats.connectivity_ms,stats.candidate_ms,stats.connection_search_ms,
            stats.curve_fit_ms,stats.curve_validation_ms,stats.candidate_validation_ms,stats.final_validation_ms,
            stats.cache_lookup_ms,stats.optimized_edges,stats.fits,stats.iterations,stats.cache_hits,
            stats.cache_rejected,stats.connectivity_rejected,stats.stop_reason.c_str());
    });
    clearPlanningFailureMarkers(goal.header.frame_id);
    last_removed_prefix_=0;
    hole_passage_planner_.setBlockedHoleIds(blocked_holes_);
    hole_passage_planner_.refreshConfiguration();
    if (hole_configuration_revision_ != hole_passage_planner_.configurationRevision()) {
        hole_configuration_revision_ = hole_passage_planner_.configurationRevision();
        clearCache();
    }
    
    if (map_manager_) {
        auto latest_costmap = map_manager_->getCostmap();
        if (latest_costmap) {
            grid_map_ = latest_costmap;
            width_ = grid_map_->info.width;
            height_ = grid_map_->info.height;
            resolution_ = grid_map_->info.resolution;
            origin_x_ = grid_map_->info.origin.position.x;
            origin_y_ = grid_map_->info.origin.position.y;
        }
    }
    
    if (!grid_map_) {
        RCLCPP_ERROR(node_->get_logger(), "地图未设置或 costmap 不可用");
        publishPlanningFailureMarkers(goal.header.frame_id,
            {{start.pose.position.x, start.pose.position.y, "start(no_map)", 1.0f, 0.1f, 0.1f},
             {goal.pose.position.x, goal.pose.position.y, "goal(no_map)", 1.0f, 0.6f, 0.1f}});
        return false;
    }
    
    if(cached_path_constrained_&&!hole_passage_planner_.cacheEnabled())cached_path_=nav_msgs::msg::Path();
    if (enable_path_cache_ && !cached_path_.poses.empty()) {
        if (!goalChanged(goal)) {
            // 目标未变化，先检查起点是否偏离缓存路径过远
            double min_dist_to_path = std::numeric_limits<double>::max();
            for (const auto& pose : cached_path_.poses) {
                double dx = start.pose.position.x - pose.pose.position.x;
                double dy = start.pose.position.y - pose.pose.position.y;
                double dist = std::hypot(dx, dy);
                min_dist_to_path = std::min(min_dist_to_path, dist);
            }
            
            if (min_dist_to_path > start_deviation_threshold_) {
                RCLCPP_WARN(node_->get_logger(), 
                    "规划器: 起点偏离缓存路径过远 (%.2f m > %.2f m)，重新规划",
                    min_dist_to_path, start_deviation_threshold_);
                // 清空缓存，强制重新规划
                cached_path_ = nav_msgs::msg::Path();
            } 
            else if (validatePath(cached_path_)) {
                // 起点在路径附近且路径无障碍物，复用缓存
                
                if (enable_auto_prune_) {
                    path = prunePath(cached_path_, start);
                } else {
                    path = cached_path_;
                }
                // 剩余路线仍独立检查，已通过的洞前阶段不要求折返补走。
                if (validatePath(path)) {hole_passage_planner_.markWholePathReuse();return true;}
                cached_path_ = nav_msgs::msg::Path();
            } else {
                // 清空缓存，强制重新规划
                cached_path_ = nav_msgs::msg::Path();
            }
        }
    }
    
    int sx, sy, gx, gy;
    if (!worldToMap(start.pose.position.x, start.pose.position.y, sx, sy) ||
        !worldToMap(goal.pose.position.x, goal.pose.position.y, gx, gy)) {
        RCLCPP_ERROR(node_->get_logger(), "起点或终点超出地图范围");
        publishPlanningFailureMarkers(goal.header.frame_id,
            {{start.pose.position.x, start.pose.position.y, "start(out_of_map)", 1.0f, 0.1f, 0.1f},
             {goal.pose.position.x, goal.pose.position.y, "goal(out_of_map)", 1.0f, 0.6f, 0.1f}});
        return false;
    }
    
    // 起点终点有效性检查
    if (!isValid(sx, sy)) {
        RCLCPP_ERROR(node_->get_logger(), "起点(%d,%d)在障碍物中", sx, sy);
        publishPlanningFailureMarkers(goal.header.frame_id,
            {{start.pose.position.x, start.pose.position.y, "start(in_obstacle)", 1.0f, 0.1f, 0.1f}});
        return false;
    }
    
    if (!isValid(gx, gy)) {
        // 终点在障碍物中，尝试调整到附近可通行点
        int free_x, free_y;
        if (findNearestFreeCell(gx, gy, free_x, free_y)) {
            double wx, wy;
            mapToWorld(free_x, free_y, wx, wy);
            double escape_dist = std::hypot(free_x - gx, free_y - gy) * resolution_;
            RCLCPP_WARN(node_->get_logger(), 
                "终点(%d,%d)在障碍物中，调整到最近可通行点(%d,%d)，距离%.2fm",
                gx, gy, free_x, free_y, escape_dist);
            gx = free_x;
            gy = free_y;
        } else {
            RCLCPP_ERROR(node_->get_logger(), "终点在障碍物中且无法找到附近可通行格子");
            publishPlanningFailureMarkers(goal.header.frame_id,
                {{goal.pose.position.x, goal.pose.position.y, "goal(in_obstacle)", 1.0f, 0.1f, 0.1f}});
            return false;
        }
    }
    
    auto planning_goal=goal;
    if(!isValid(static_cast<int>((goal.pose.position.x-origin_x_)/resolution_),
                static_cast<int>((goal.pose.position.y-origin_y_)/resolution_))) {
        mapToWorld(gx,gy,planning_goal.pose.position.x,planning_goal.pose.position.y);
    }
    const int max_attempts = astar_max_attempts_;
    const int threshold_step = astar_threshold_step_;
    const int original_threshold = obstacle_threshold_;
    int attempts_done = 0;
    
    for (int attempt = 0; attempt < max_attempts; ++attempt) {
        if(std::chrono::steady_clock::now()>=hole_request_deadline_)break;
        attempts_done++;
        int current_threshold =
            std::clamp(original_threshold - attempt * threshold_step, 1, 100);

        obstacle_threshold_ = current_threshold;

        nav_msgs::msg::Path raw_path;
        raw_path.header=goal.header;
        int fail_best_x = sx;
        int fail_best_y = sy;
        const auto astar_begin=std::chrono::steady_clock::now();
        const bool astar_success = runAstar(
            sx, sy, gx, gy, goal.header, raw_path, &fail_best_x, &fail_best_y);

        astar_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-astar_begin).count();
        obstacle_threshold_ = original_threshold;
        
        if (!astar_success) {
            double fw = 0.0;
            double fy = 0.0;
            mapToWorld(fail_best_x, fail_best_y, fw, fy);
            publishPlanningFailureMarkers(goal.header.frame_id,
                {{goal.pose.position.x, goal.pose.position.y, "goal", 1.0f, 0.2f, 0.2f},
                 {fw, fy, "astar_frontier", 1.0f, 1.0f, 0.1f}});
            RCLCPP_WARN(node_->get_logger(), 
                "A*规划失败 (阈值=%d)", current_threshold);
            if(!hole_passage_planner_.enabled()) continue;
        }

        if (publish_astar_raw_path_ && astar_raw_path_pub_) {
            nav_msgs::msg::Path astar_path_msg = raw_path;
            astar_path_msg.header.stamp = node_->now();
            for (auto& pose : astar_path_msg.poses) {
                pose.header.stamp = astar_path_msg.header.stamp;
            }
            astar_raw_path_pub_->publish(astar_path_msg);
        }
        hole_passage_planner_.buildCandidates(raw_path, *grid_map_, obstacle_check_threshold_);
        nav_msgs::msg::Path hole_route;
        bool constrained=false;
        if(hole_passage_planner_.enabled()&&hole_request_deadline_==std::chrono::steady_clock::time_point::max())
            hole_request_deadline_=std::chrono::steady_clock::now()+std::chrono::duration_cast<std::chrono::steady_clock::duration>(
                std::chrono::duration<double>(node_->get_parameter("hole_planner.search.planning_timeout").as_double()));
        const auto route_check=hole_passage_planner_.planRoute(raw_path,
            {start.pose.position.x,start.pose.position.y},
            {planning_goal.pose.position.x,planning_goal.pose.position.y},
            *grid_map_,obstacle_check_threshold_,hole_route,constrained,start_velocity_,hole_request_deadline_);
        if(route_check.valid&&!constrained)hole_request_deadline_=std::chrono::steady_clock::time_point::max();
        if(!route_check.valid) {
            RCLCPP_WARN(node_->get_logger(),"过洞连接搜索失败: %s",route_check.reason.c_str());
            publishPlanningFailureMarkers(goal.header.frame_id,
                {{route_check.point.x,route_check.point.y,route_check.reason,1.0f,0.3f,0.1f}});
            continue;
        }
        if(constrained) {
            // 洞口规划器已分别优化自由曲线并插入固定直线，整条 B 样条会破坏硬约束。
            bool valid=false;
            {HoleTimingScope timer(outer_validation_ms);valid=validatePath(hole_route);}
            if(!valid||std::chrono::steady_clock::now()>=hole_request_deadline_)continue;
            path=std::move(hole_route);
            publishControlPoints({},goal.header.frame_id);
            if(enable_path_cache_&&hole_passage_planner_.cacheEnabled()) {cached_path_=path;cached_goal_=goal;cached_path_constrained_=true;}
            clearPlanningFailureMarkers(goal.header.frame_id);
            return true;
        }
        
        nav_msgs::msg::Path smoothed_path;
        if (enable_smooth_ && raw_path.poses.size() >= 4) {
            if (!smoother_.smooth(raw_path, smoothed_path)) {
                smoothed_path = raw_path;
                RCLCPP_WARN(node_->get_logger(), "平滑失败，使用原始路径");
            } else {
                if (map_manager_ && map_manager_->hasEsdf()) {
                    double min_dist = 1e9;
                    geometry_msgs::msg::PoseStamped worst_pose;
                    int unsafe_count = 0;
                    const double min_safe_dist = esdf_warn_min_safe_dist_;
                    
                    for (const auto& pose : smoothed_path.poses) {
                        double grad_x = 0, grad_y = 0;
                        double dist = map_manager_->getEsdfDistanceWithGradient(
                            pose.pose.position.x, pose.pose.position.y, &grad_x, &grad_y);
                        
                        if (dist < min_dist) {
                            min_dist = dist;
                            worst_pose = pose;
                        }
                        if (dist < min_safe_dist) {
                            unsafe_count++;
                        }
                    }
                    
                    if (unsafe_count > 0) {
                        RCLCPP_WARN(node_->get_logger(), 
                            "平滑路径过于接近障碍物: %d/%zu 点 ESDF < %.2fm, 最小=%.3fm @ (%.2f, %.2f)",
                            unsafe_count, smoothed_path.poses.size(), min_safe_dist, min_dist,
                            worst_pose.pose.position.x, worst_pose.pose.position.y);
                    }
                }
                
                publishControlPoints(smoother_.getLastControlPoints(), goal.header.frame_id);
            }
        } else {
            smoothed_path = raw_path;
        }
        
        if (validatePath(smoothed_path)) {
            RCLCPP_DEBUG(node_->get_logger(), 
                "规划成功 (阈值=%d): A*=%zu点 -> 平滑=%zu点", 
                current_threshold, raw_path.poses.size(), smoothed_path.poses.size());
            clearPlanningFailureMarkers(goal.header.frame_id);
            path = smoothed_path;
            
            if (enable_path_cache_ && (hole_passage_planner_.pathPassages().empty()||hole_passage_planner_.cacheEnabled())) {
                cached_path_ = path;
                cached_path_constrained_=!hole_passage_planner_.pathPassages().empty();
                cached_goal_ = goal;
            }
            return true;
        } else if (enable_smooth_ && allow_raw_fallback_on_smooth_fail_ && validatePath(raw_path)) {
            RCLCPP_WARN(node_->get_logger(),
                "平滑路径验证失败，回退到原始A*路径: A*=%zu点, 平滑=%zu点",
                raw_path.poses.size(), smoothed_path.poses.size());
            clearPlanningFailureMarkers(goal.header.frame_id);
            path = raw_path;

            if (enable_path_cache_ && (hole_passage_planner_.pathPassages().empty()||hole_passage_planner_.cacheEnabled())) {
                cached_path_ = path;
                cached_path_constrained_=!hole_passage_planner_.pathPassages().empty();
                cached_goal_ = goal;
            }
            return true;
        } else {
            if (has_last_validate_fail_point_) {
                publishPlanningFailureMarkers(goal.header.frame_id,
                    {{last_validate_fail_x_, last_validate_fail_y_,
                      "invalid_path_pt", 1.0f, 0.3f, 0.1f}});
            } else if (!smoothed_path.poses.empty()) {
                const auto& p = smoothed_path.poses.front().pose.position;
                publishPlanningFailureMarkers(goal.header.frame_id,
                    {{p.x, p.y, "invalid_path_pt(fallback)", 1.0f, 0.3f, 0.1f}});
            }
            RCLCPP_DEBUG(node_->get_logger(), 
                "路径验证失败 (阈值=%d)，尝试降低阈值", current_threshold);
        }

        if (threshold_step == 0) {
            break;
        }
    }
    
    RCLCPP_ERROR(node_->get_logger(),
        "规划失败: 尝试了 %d 次，均未成功 (step=%d)",
        attempts_done, threshold_step);
    return false;
}

bool SimplePlanner::runAstar(int sx, int sy, int gx, int gy,
                              const std_msgs::msg::Header& header,
                              nav_msgs::msg::Path& path,
                              int* fail_best_x,
                              int* fail_best_y,
                              const nav_core::HoleSegmentCheck &segment_check,int *expansion_count) {
    auto cmp = [](Node* a, Node* b) { return a->f() > b->f(); };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> open(cmp);
    std::vector<std::unique_ptr<Node>> all_nodes;
    std::vector<bool> closed(width_ * height_, false);
    std::vector<double> best_g(width_ * height_, std::numeric_limits<double>::infinity());
    std::vector<Node*> best_node(width_ * height_, nullptr);
    
    auto start_node = std::make_unique<Node>();
    start_node->x = sx; start_node->y = sy;
    start_node->g = 0; start_node->h = heuristic(sx, sy, gx, gy);
    int start_idx = sy * width_ + sx;
    best_g[start_idx] = 0.0;
    best_node[start_idx] = start_node.get();
    open.push(start_node.get());
    all_nodes.push_back(std::move(start_node));
    
    const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    const double move_cost[] = {1, 1.414, 1, 1.414, 1, 1.414, 1, 1.414};
    
    Node* goal_node = nullptr;
    Node* closest_node = nullptr;
    double closest_h = std::numeric_limits<double>::infinity();
    int iterations = 0;
    const int auto_max_iter = std::min(width_ * height_ * 2, 1000000);
    const int max_iter = (astar_max_iterations_ > 0) ? astar_max_iterations_ : auto_max_iter;
    
    while (!open.empty() && iterations++ < max_iter) {
        if(std::chrono::steady_clock::now()>=hole_request_deadline_)break;
        Node* curr = open.top();
        open.pop();

        if (curr->h < closest_h) {
            closest_h = curr->h;
            closest_node = curr;
        }
        
        if (curr->x == gx && curr->y == gy) {
            goal_node = curr;
            break;
        }
        
        int idx = curr->y * width_ + curr->x;
        if (closed[idx]) {
            continue;
        }
        closed[idx] = true;
        
        for (int i = 0; i < 8; i++) {
            int nx = curr->x + dx[i];
            int ny = curr->y + dy[i];

            // 对角扩展时，要求两个正交相邻格都可通行，防止穿角
            if (dx[i] != 0 && dy[i] != 0) {
                const int ortho_x = curr->x + dx[i];
                const int ortho_y = curr->y + dy[i];
                if (!isValid(ortho_x, curr->y) || !isValid(curr->x, ortho_y)) {
                    continue;
                }
            }

            if(segment_check) {
                double ax,ay,bx,by;mapToWorld(curr->x,curr->y,ax,ay);mapToWorld(nx,ny,bx,by);
                if(!segment_check({ax,ay},{bx,by}).valid)continue;
            }
            double special_terrain_cost = 0.0;
            if (special_terrain_constraint_) {
                double from_wx = 0.0;
                double from_wy = 0.0;
                double to_wx = 0.0;
                double to_wy = 0.0;
                mapToWorld(curr->x, curr->y, from_wx, from_wy);
                mapToWorld(nx, ny, to_wx, to_wy);
                if (!special_terrain_constraint_->isTransitionAllowed(
                        from_wx, from_wy, to_wx, to_wy)) {
                    continue;
                }
                special_terrain_cost = std::max(
                    0.0, special_terrain_constraint_->transitionCost(
                             from_wx, from_wy, to_wx, to_wy));
            }

            if (!isValid(nx, ny)) {
                continue;
            }
            int nidx = ny * width_ + nx;
            if (closed[nidx]) {
                continue;
            }
            
            double cell_cost = getCost(nx, ny);
            double total_cost =
                move_cost[i] + cost_weight_ * cell_cost + special_terrain_cost;
            double tentative_g = curr->g + total_cost;
            if (tentative_g + 1e-9 >= best_g[nidx]) {
                continue;
            }
            
            auto new_node = std::make_unique<Node>();
            new_node->x = nx; new_node->y = ny;
            new_node->g = tentative_g;
            new_node->h = heuristic(nx, ny, gx, gy);
            new_node->parent = curr;
            best_g[nidx] = tentative_g;
            best_node[nidx] = new_node.get();
            
            open.push(new_node.get());
            all_nodes.push_back(std::move(new_node));
        }
    }
    
    if(expansion_count)*expansion_count=iterations;
    if (!goal_node) {
        if (closest_node) {
            if (fail_best_x) {
                *fail_best_x = closest_node->x;
            }
            if (fail_best_y) {
                *fail_best_y = closest_node->y;
            }
        }
        return false;
    }
    
    std::vector<geometry_msgs::msg::PoseStamped> waypoints;
    for (Node* n = best_node[gy * width_ + gx]; n != nullptr; n = n->parent) {
        geometry_msgs::msg::PoseStamped pose;
        pose.header = header;
        mapToWorld(n->x, n->y, pose.pose.position.x, pose.pose.position.y);
        pose.pose.orientation.w = 1.0;
        waypoints.push_back(pose);
    }
    
    std::reverse(waypoints.begin(), waypoints.end());
    
    path.header = header;
    path.poses = waypoints;
    return true;
}

void SimplePlanner::clearPlanningFailureMarkers(const std::string& frame_id) {
    if (!publish_failure_debug_markers_ || !plan_failure_pub_ || frame_id.empty()) {
        return;
    }
    visualization_msgs::msg::MarkerArray markers;
    visualization_msgs::msg::Marker del;
    del.header.frame_id = frame_id;
    del.header.stamp = node_->now();
    del.ns = "planner_failures";
    del.action = visualization_msgs::msg::Marker::DELETEALL;
    markers.markers.push_back(del);
    plan_failure_pub_->publish(markers);
}

void SimplePlanner::publishPlanningFailureMarkers(const std::string& frame_id,
                                                  const std::vector<FailurePoint>& points) {
    if (!publish_failure_debug_markers_ || !plan_failure_pub_ || frame_id.empty()) {
        return;
    }

    visualization_msgs::msg::MarkerArray markers;
    auto stamp = node_->now();

    visualization_msgs::msg::Marker del;
    del.header.frame_id = frame_id;
    del.header.stamp = stamp;
    del.ns = "planner_failures";
    del.action = visualization_msgs::msg::Marker::DELETEALL;
    markers.markers.push_back(del);

    int id = 0;
    for (const auto& fp : points) {
        visualization_msgs::msg::Marker sphere;
        sphere.header.frame_id = frame_id;
        sphere.header.stamp = stamp;
        sphere.ns = "planner_failures";
        sphere.id = id++;
        sphere.type = visualization_msgs::msg::Marker::SPHERE;
        sphere.action = visualization_msgs::msg::Marker::ADD;
        sphere.pose.position.x = fp.x;
        sphere.pose.position.y = fp.y;
        sphere.pose.position.z = 0.10;
        sphere.pose.orientation.w = 1.0;
        sphere.scale.x = failure_marker_scale_;
        sphere.scale.y = failure_marker_scale_;
        sphere.scale.z = failure_marker_scale_;
        sphere.color.r = fp.r;
        sphere.color.g = fp.g;
        sphere.color.b = fp.b;
        sphere.color.a = 0.95f;
        markers.markers.push_back(sphere);

        visualization_msgs::msg::Marker text;
        text.header.frame_id = frame_id;
        text.header.stamp = stamp;
        text.ns = "planner_failures";
        text.id = id++;
        text.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
        text.action = visualization_msgs::msg::Marker::ADD;
        text.pose.position.x = fp.x;
        text.pose.position.y = fp.y;
        text.pose.position.z = 0.26;
        text.pose.orientation.w = 1.0;
        text.scale.z = std::max(0.08, failure_marker_scale_ * 0.75);
        text.color.r = 1.0f;
        text.color.g = 1.0f;
        text.color.b = 1.0f;
        text.color.a = 0.95f;
        text.text = fp.label;
        markers.markers.push_back(text);
    }

    plan_failure_pub_->publish(markers);
}

void SimplePlanner::publishControlPoints(const std::vector<Eigen::Vector2d>& ctrl_pts,
                                          const std::string& frame_id) {
    if (!ctrl_pts_pub_) return;
    if(ctrl_pts.empty()) {
        visualization_msgs::msg::MarkerArray clear;
        visualization_msgs::msg::Marker m;m.header.frame_id=frame_id;m.action=visualization_msgs::msg::Marker::DELETEALL;
        clear.markers.push_back(m);ctrl_pts_pub_->publish(clear);return;
    }
    
    visualization_msgs::msg::MarkerArray markers;
    
    // Marker 1: 控制点球体
    visualization_msgs::msg::Marker points_marker;
    points_marker.header.frame_id = frame_id;
    points_marker.header.stamp = node_->now();
    points_marker.ns = "control_points";
    points_marker.id = 0;
    points_marker.type = visualization_msgs::msg::Marker::SPHERE_LIST;
    points_marker.action = visualization_msgs::msg::Marker::ADD;
    points_marker.scale.x = 0.08;
    points_marker.scale.y = 0.08;
    points_marker.scale.z = 0.08;
    points_marker.color.r = 1.0;
    points_marker.color.g = 0.5;
    points_marker.color.b = 0.0;
    points_marker.color.a = 1.0;
    
    for (const auto& pt : ctrl_pts) {
        geometry_msgs::msg::Point p;
        p.x = pt.x();
        p.y = pt.y();
        p.z = 0.05;
        points_marker.points.push_back(p);
    }
    markers.markers.push_back(points_marker);
    
    // Marker 2: 控制多边形（连线）
    visualization_msgs::msg::Marker line_marker;
    line_marker.header.frame_id = frame_id;
    line_marker.header.stamp = node_->now();
    line_marker.ns = "control_polygon";
    line_marker.id = 1;
    line_marker.type = visualization_msgs::msg::Marker::LINE_STRIP;
    line_marker.action = visualization_msgs::msg::Marker::ADD;
    line_marker.scale.x = 0.02;
    line_marker.color.r = 0.0;
    line_marker.color.g = 0.8;
    line_marker.color.b = 0.2;
    line_marker.color.a = 0.8;
    
    for (const auto& pt : ctrl_pts) {
        geometry_msgs::msg::Point p;
        p.x = pt.x();
        p.y = pt.y();
        p.z = 0.05;
        line_marker.points.push_back(p);
    }
    markers.markers.push_back(line_marker);
    
    // Marker 3: 序号标签
    for (size_t i = 0; i < ctrl_pts.size(); ++i) {
        visualization_msgs::msg::Marker text_marker;
        text_marker.header.frame_id = frame_id;
        text_marker.header.stamp = node_->now();
        text_marker.ns = "control_point_ids";
        text_marker.id = static_cast<int>(i + 100);
        text_marker.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
        text_marker.action = visualization_msgs::msg::Marker::ADD;
        text_marker.pose.position.x = ctrl_pts[i].x();
        text_marker.pose.position.y = ctrl_pts[i].y();
        text_marker.pose.position.z = 0.15;
        text_marker.scale.z = 0.1;
        text_marker.color.r = 1.0;
        text_marker.color.g = 1.0;
        text_marker.color.b = 1.0;
        text_marker.color.a = 1.0;
        text_marker.text = std::to_string(i);
        markers.markers.push_back(text_marker);
    }
    
    ctrl_pts_pub_->publish(markers);
}

bool SimplePlanner::validatePath(const nav_msgs::msg::Path& path) {
    has_last_validate_fail_point_ = false;

    if (path.poses.empty() || !map_manager_) {
        return false;
    }
    
    auto latest_costmap = map_manager_->getCostmap();
    if (!latest_costmap) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000,
            "无法获取最新Costmap进行路径验证");
        return false;
    }

    const auto hole_check = hole_passage_planner_.validatePath(
        path, *latest_costmap, obstacle_check_threshold_, true, hole_request_deadline_);
    if (!hole_check.valid) {
        has_last_validate_fail_point_ = true;
        last_validate_fail_x_ = hole_check.point.x;
        last_validate_fail_y_ = hole_check.point.y;
        RCLCPP_WARN(node_->get_logger(), "过洞路径校验失败: %s", hole_check.reason.c_str());
        return false;
    }
    
    int cm_width = latest_costmap->info.width;
    int cm_height = latest_costmap->info.height;
    double cm_resolution = latest_costmap->info.resolution;
    double cm_origin_x = latest_costmap->info.origin.position.x;
    double cm_origin_y = latest_costmap->info.origin.position.y;
    
    int8_t max_cost_on_path = 0;

    for (const auto& pose : path.poses) {
        int mx = static_cast<int>((pose.pose.position.x - cm_origin_x) / cm_resolution);
        int my = static_cast<int>((pose.pose.position.y - cm_origin_y) / cm_resolution);
        
        if (mx < 0 || mx >= cm_width || my < 0 || my >= cm_height) {
            continue;
        }
        
        int idx = my * cm_width + mx;
        if (idx < 0 || idx >= static_cast<int>(latest_costmap->data.size())) {
            continue;
        }
        
        int8_t val = latest_costmap->data[idx];
        if (val > max_cost_on_path) {
            max_cost_on_path = val;
        }
        
        if (val >= obstacle_check_threshold_ || val < 0) {
            has_last_validate_fail_point_ = true;
            last_validate_fail_x_ = pose.pose.position.x;
            last_validate_fail_y_ = pose.pose.position.y;
            RCLCPP_WARN(node_->get_logger(), 
                "路径点 (%.2f, %.2f) 与障碍物重合: costmap=%d >= %d", 
                pose.pose.position.x, pose.pose.position.y, 
                static_cast<int>(val), static_cast<int>(obstacle_check_threshold_));
            return false;
        }
    }

    if (special_terrain_constraint_ && path.poses.size() >= 2) {
        for (size_t i = 1; i < path.poses.size(); ++i) {
            const auto& from = path.poses[i - 1].pose.position;
            const auto& to = path.poses[i].pose.position;
            if (!special_terrain_constraint_->isTransitionAllowed(
                    from.x, from.y, to.x, to.y)) {
                has_last_validate_fail_point_ = true;
                last_validate_fail_x_ = to.x;
                last_validate_fail_y_ = to.y;
                RCLCPP_WARN(node_->get_logger(),
                            "路径与特殊地形方向约束冲突: idx=%zu",
                            i - 1);
                return false;
            }
        }
    }

    RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *node_->get_clock(), 2000,
        "路径验证通过: %zu点, 路径最大代价=%d, 阈值=%d",
        path.poses.size(), static_cast<int>(max_cost_on_path),
        static_cast<int>(obstacle_check_threshold_));
    
    return true;
}

bool SimplePlanner::goalChanged(const geometry_msgs::msg::PoseStamped& new_goal) {
    if (cached_goal_.header.frame_id.empty()) {
        return true;
    }
    
    double dx = new_goal.pose.position.x - cached_goal_.pose.position.x;
    double dy = new_goal.pose.position.y - cached_goal_.pose.position.y;
    double dist = std::hypot(dx, dy);
    
    return dist > goal_change_tolerance_;
}

nav_msgs::msg::Path SimplePlanner::prunePath(
    const nav_msgs::msg::Path& path,
    const geometry_msgs::msg::PoseStamped& current_pose)
{
    if (path.poses.empty()) {
        return path;
    }
    
    double min_dist = std::numeric_limits<double>::max();
    size_t nearest_idx = 0;
    
    for (size_t i = 0; i < path.poses.size(); ++i) {
        double dx = path.poses[i].pose.position.x - current_pose.pose.position.x;
        double dy = path.poses[i].pose.position.y - current_pose.pose.position.y;
        double dist = std::hypot(dx, dy);
        
        if (dist < min_dist) {
            min_dist = dist;
            nearest_idx = i;
        }
    }
    
    size_t prune_start_idx = 0;
    double accumulated_dist = 0.0;
    
    for (size_t i = 0; i < nearest_idx; ++i) {
        double dx = path.poses[nearest_idx].pose.position.x - path.poses[i].pose.position.x;
        double dy = path.poses[nearest_idx].pose.position.y - path.poses[i].pose.position.y;
        accumulated_dist = std::hypot(dx, dy);
        
        if (accumulated_dist <= prune_distance_) {
            prune_start_idx = i;
            break;
        }
    }
    
    last_removed_prefix_=0;
    for(std::size_t i=1;i<=prune_start_idx;++i)last_removed_prefix_+=std::hypot(
        path.poses[i].pose.position.x-path.poses[i-1].pose.position.x,
        path.poses[i].pose.position.y-path.poses[i-1].pose.position.y);
    nav_msgs::msg::Path pruned_path;
    pruned_path.header = path.header;
    pruned_path.poses.assign(path.poses.begin() + prune_start_idx, path.poses.end());
    
    return pruned_path;
}


}  // namespace nav_components

namespace nav_components {
HoleSelectedSnapshot SimplePlanner::freezeHoleExecutionPlan(const nav_msgs::msg::Path& path) {
    // 此方法只在接纳入口调用，不在周期诊断中覆盖正在执行的快照。
    if(!validatePath(path))throw std::runtime_error("cannot freeze invalid final path");
    HoleSelectedSnapshot s;s.path=path;s.passages=hole_passage_planner_.pathPassages();
    s.preparation=hole_passage_planner_.preparationEvents();s.departure=hole_passage_planner_.departureEvents();
    s.selected=hole_passage_planner_.selectedRoute();
    s.terrain_revision=hole_passage_planner_.terrainRevision();s.configuration_revision=hole_passage_planner_.configurationRevision();
    // 地图内容摘要标识校验快照；不将接纳次数或 ROS 时间戳冒充地图版本。
    std::uint64_t digest=1469598103934665603ULL;
    const auto mix=[&](const void* data,std::size_t size){const auto* bytes=static_cast<const unsigned char*>(data);
        for(std::size_t i=0;i<size;++i){digest^=bytes[i];digest*=1099511628211ULL;}};
    mix(grid_map_->data.data(),grid_map_->data.size());
    mix(&grid_map_->info.width,sizeof(grid_map_->info.width));mix(&grid_map_->info.height,sizeof(grid_map_->info.height));
    mix(&grid_map_->info.resolution,sizeof(grid_map_->info.resolution));
    const auto& origin=grid_map_->info.origin;
    for(double value:{origin.position.x,origin.position.y,origin.orientation.x,origin.orientation.y,origin.orientation.z,origin.orientation.w})mix(&value,sizeof(value));
    s.map_revision=digest;s.removed_prefix=last_removed_prefix_;
    cached_selection_=s;return s;
}
}
