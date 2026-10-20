#include "nav_components/translation_recovery.hpp"
#include "nav_components/layered_map_manager.hpp"
#include "nav_components/recovery_manager.hpp"
#include <iostream>
#include <thread>
using namespace nav_components;
void check(bool result,const char* reason) {if(!result) throw std::runtime_error(reason);}
int main(int argc,char** argv) {
    rclcpp::init(argc,argv);
    auto node=std::make_shared<rclcpp::Node>("motion_test");
    nav_msgs::msg::OccupancyGrid grid;
    grid.header.frame_id="map"; grid.info.width=20; grid.info.height=20;
    grid.info.resolution=0.1; grid.info.origin.orientation.w=1;
    grid.data.assign(400,0);
    check(omni_motion::costAt(grid,-0.001,0.5)==-1,"negative boundary truncation");
    check(omni_motion::clearSegment(grid,grid,0.2,0.2,1.2,1.2,99,false),"free diagonal");
    auto obstacle=grid; obstacle.data[7*20+7]=100;
    check(!omni_motion::clearSegment(grid,obstacle,0.2,0.2,1.2,1.2,99,true),"must not cross raw obstacle");
    auto unknown=grid; unknown.data[7*20+7]=-1;
    check(!omni_motion::clearSegment(grid,unknown,0.2,0.2,1.2,1.2,99,true),"must not cross unknown");
    // Sparse columns used to underflow the EDT envelope index. Compare all
    // costs against brute-force Euclidean distances, including an unknown cell.
    auto sparse=std::make_shared<nav_msgs::msg::OccupancyGrid>(obstacle);
    sparse->data[5*20+14]=-1;
    InflationParams checked_inflation;
    auto inflated_sparse=CostmapInflater::inflate(sparse,checked_inflation);
    std::vector<float> distances(400);
    for(int y=0;y<20;++y) for(int x=0;x<20;++x)
        distances[y*20+x]=std::min(std::hypot(x-7,y-7),std::hypot(x-14,y-5))*sparse->info.resolution;
    auto expected=CostmapInflater::fromEsdf(distances,20,20,sparse->info.resolution,0,0,checked_inflation);
    for(size_t i=0;i<400;++i) check(std::abs(int(inflated_sparse->data[i])-int(expected->data[i]))<=1,"EDT differs from Euclidean oracle");
    auto inflated=grid; inflated.data[2*20+2]=100;
    check(omni_motion::clearSegment(inflated,grid,0.25,0.25,0.65,0.25,99,true),"escape existing inflation");
    inflated.data[2*20+5]=100;
    check(!omni_motion::clearSegment(inflated,grid,0.25,0.25,0.65,0.25,99,true),"no reentry to inflation");
    geometry_msgs::msg::PoseStamped pose;
    pose.header.frame_id="map";
    pose.pose.position.x=-1; pose.pose.position.y=-2;
    pose.pose.orientation.z=std::sqrt(0.5); pose.pose.orientation.w=std::sqrt(0.5);
    auto cmd=omni_motion::toward(pose,-0.5,-2,0.2,0.02);
    check(std::abs(cmd.linear.x)<1e-9 && std::abs(cmd.linear.y+0.2)<1e-9,"map -> fake direction");
    bool safe=true;
    TranslationRecovery recovery("side",M_PI/2,0.3,0.2,3,0.01,1,
        [&](const auto&,double,double){return safe;});
    recovery.initialize(node.get(),[&](const auto& c){cmd=c;});
    recovery.start(pose);
    check(recovery.update(pose)==nav_core::RecoveryStatus::RUNNING,"recovery starts");
    check(cmd.linear.y>0 && std::abs(cmd.angular.z)<1e-9,"lateral recovery without angular velocity");
    // Fixed fake yaw never changes. Translation alone must finish.
    pose.pose.position.x-=0.3;
    check(recovery.update(pose)==nav_core::RecoveryStatus::SUCCEEDED,"translation completes without yaw change");
    check(cmd.linear.x==0 && cmd.linear.y==0,"success stops");
    recovery.start(pose); safe=false;
    check(recovery.update(pose)==nav_core::RecoveryStatus::FAILED,"blocked recovery fails");
    check(cmd.linear.x==0 && cmd.linear.y==0,"failure stops");
    recovery.cancel(); check(cmd.linear.x==0 && cmd.linear.y==0,"cancel stops");
    auto managed=std::make_shared<TranslationRecovery>("managed",0,0.3,0.2,3,0.01,1,
        [](const auto&,double,double){return true;});
    managed->initialize(node.get(),[&](const auto& c){cmd=c;});
    RecoveryManager recoveries;
    recoveries.addRecovery(managed);
    recoveries.start(nav_core::RecoveryTrigger::STUCK,pose);
    recoveries.updateCurrent(pose);
    recoveries.reset();
    check(recoveries.updateCurrent(pose)==nav_core::RecoveryStatus::IDLE,"reset must cancel previous recovery state");
    check(cmd.linear.x==0 && cmd.linear.y==0,"manager reset stops");
    // Dynamic grid must use its header frame and its rotated grid origin.
    auto buffer=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    LayeredMapManager manager;
    manager.initialize(node.get(),buffer);
    InflationParams inflation;
    manager.createBlankStaticMap(8,8,0.1,inflation);
    auto local=std::make_shared<nav_msgs::msg::OccupancyGrid>();
    local->header.frame_id="map";
    local->info.width=local->info.height=1; local->info.resolution=1;
    local->info.origin.position.x=1; local->info.origin.position.y=2;
    local->info.origin.orientation.z=local->info.origin.orientation.w=std::sqrt(0.5);
    local->data={100};
    manager.updateDynamicLayer(local);
    check(omni_motion::costAt(*manager.getFusedMap(),0.5,2.5)==100,"dynamic map frame/origin projection");
    local->data.clear();
    manager.updateDynamicLayer(local);
    check(omni_motion::costAt(*manager.getFusedMap(),0.5,2.5)==100,"malformed grid must not erase valid map");
    std::cout<<"Omni recovery / swept segment / map-frame direction tests passed\n";
    rclcpp::shutdown();
}
