#include "nav_components/hole_plan_adapter.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main(int argc,char** argv) {
    assert(argc==2);
    auto terrain=std::make_shared<nav_components::TerrainRegionMap>();std::string error;
    assert(terrain->loadFromFile(argv[1],"map",&error));
    auto make=[&](std::initializer_list<double> xs){
        nav_components::HoleSelectedSnapshot snap;snap.path.header.frame_id="map";
        for(double x:xs){geometry_msgs::msg::PoseStamped p;p.pose.position.x=x;snap.path.poses.push_back(p);}
        std::uint64_t uid=0;return nav_components::makeHoleExecutionPlan(snap,terrain,Config{},"s","g",1,nullptr,0,uid);
    };
    auto full=make({-1,0,.25,.5,1,1.5,2,3});
    assert(full.speeds.empty());assert(full.slopes.size()==1);
    assert(full.slopes[0].uphill&&full.slopes[0].entry_complete&&full.slopes[0].exit_complete);
    assert(std::abs(full.slopes[0].begin-1)<1e-8&&std::abs(full.slopes[0].end-3)<1e-8);
    auto foot=make({0,.25,1,2,3});assert(foot.slopes.size()==1&&foot.slopes[0].entry_complete);
    auto mid=make({.5,1,1.5});assert(mid.slopes.size()==1&&!mid.slopes[0].entry_complete&&!mid.slopes[0].exit_complete);
    auto down=make({3,2,1,0,-1});assert(down.slopes.size()==1&&!down.slopes[0].uphill);
    std::cout<<"PASS: merged physical slope boundaries, stopped-at-foot start, clipped mid-slope and no terrain speed regions\n";
}
