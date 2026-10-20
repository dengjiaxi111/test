#pragma once
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <tf2/utils.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <algorithm>
#include <cmath>

namespace nav_components::omni_motion {
inline int costAt(const nav_msgs::msg::OccupancyGrid& grid, double x, double y) {
    const auto& info=grid.info;
    if(!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(info.resolution) ||
       info.resolution<=0 || grid.data.size()!=size_t(info.width)*info.height) return -1;
    const double yaw=tf2::getYaw(info.origin.orientation);
    const double dx=x-info.origin.position.x, dy=y-info.origin.position.y;
    const double fx=(std::cos(yaw)*dx+std::sin(yaw)*dy)/info.resolution;
    const double fy=(-std::sin(yaw)*dx+std::cos(yaw)*dy)/info.resolution;
    if(!std::isfinite(fx) || !std::isfinite(fy) || fx<0 || fy<0 || fx>=info.width || fy>=info.height) return -1;
    const int ix=int(std::floor(fx)),iy=int(std::floor(fy));
    return grid.data[size_t(iy)*info.width+ix];
}
// Escape can leave an existing inflated area, but cannot enter unknown/raw
// obstacles, increase lethal cost, or re-enter inflation after reaching free space.
inline bool clearSegment(const nav_msgs::msg::OccupancyGrid& costmap,
                         const nav_msgs::msg::OccupancyGrid& occupancy,
                         double x0,double y0,double x1,double y1,int threshold,bool escape) {
    int previous=costAt(costmap,x0,y0);
    if(previous<0 || (!escape && previous>=threshold)) return false;
    bool escaped=previous<threshold;
    const double distance=std::hypot(x1-x0,y1-y0);
    if(!std::isfinite(distance) || costmap.info.resolution<=0 || occupancy.info.resolution<=0) return false;
    const double step=std::min(costmap.info.resolution,occupancy.info.resolution)*0.5;
    const int samples=std::max(1,int(std::ceil(distance/step)));
    for(int i=0;i<=samples;++i) {
        const double ratio=double(i)/samples, x=x0+ratio*(x1-x0), y=y0+ratio*(y1-y0);
        const int raw=costAt(occupancy,x,y), cost=costAt(costmap,x,y);
        if(raw<0 || raw>=50 || cost<0) return false;
        if(cost>=threshold && (!escape || escaped || cost>previous)) return false;
        if(cost<threshold) escaped=true;
        previous=cost;
    }
    return true;
}
inline geometry_msgs::msg::Twist toward(const geometry_msgs::msg::PoseStamped& pose,
                                        double x,double y,double speed,double dt) {
    geometry_msgs::msg::Twist command;
    const double dx=x-pose.pose.position.x,dy=y-pose.pose.position.y;
    const double distance=std::hypot(dx,dy), yaw=tf2::getYaw(pose.pose.orientation);
    if(distance<=1e-9 || !std::isfinite(distance) || !std::isfinite(yaw) || speed<=0 || dt<=0) return command;
    const double gain=std::min(speed,distance/dt)/distance;
    command.linear.x=gain*(std::cos(yaw)*dx+std::sin(yaw)*dy);
    command.linear.y=gain*(-std::sin(yaw)*dx+std::cos(yaw)*dy);
    return command;
}
} // namespace nav_components::omni_motion
