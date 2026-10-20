#include "nav_components/hole_plan_adapter.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
static nav_msgs::msg::Path path(const std::vector<Point>& points) {
    nav_msgs::msg::Path p;p.header.frame_id="map";
    for(auto q:points){geometry_msgs::msg::PoseStamped s;s.pose.position.x=q.x;s.pose.position.y=q.y;p.poses.push_back(s);}return p;
}
int main() {
    nav_components::HoleSelectedSnapshot s;s.path=path({{0,0},{5,0}});
    nav_core::HolePassageCandidate c;c.hole_id="h";c.mode=nav_core::HolePassageMode::Centerline;
    c.entry_edge=0;c.exit_edge=2;c.S={1,0};c.E={2,0};c.X={3,0};c.T={4,0};
    c.entry_arc=2;c.exit_arc=3;c.u_in=c.u_out={1,0};c.check=nav_core::holeCheck(true,"valid");s.passages={c};
    nav_core::HolePreparationEvent a;a.hole_id="h";a.passage_index=0;a.preparation_arc=1.5;s.preparation={a};
    nav_core::HoleDepartureEvent d;d.hole_id="h";d.entry_edge=0;d.exit_edge=2;d.departure_arc=4;d.planning_policy="manual_range_end";s.departure={d};
    Config config;std::uint64_t uid=0;
    auto initial=nav_components::makeHoleExecutionPlan(s,nullptr,config,"session","goal",1,nullptr,0,uid);
    assert(event(initial.passages[0],EventType::A).arc==1.5); // A在S之后合法。
    nav_components::HoleSelectedSnapshot remaining;remaining.path=path({{3.4,0},{5,0}});
    auto next=nav_components::makeHoleExecutionPlan(remaining,nullptr,config,"session","goal",2,&initial,3.4,uid);
    assert(next.passages.size()==1&&next.passages[0].uid==initial.passages[0].uid);
    assert(event(next.passages[0],EventType::X).range==Range::BEFORE_PATH);
    assert(std::abs(event(next.passages[0],EventType::T).arc-0.6)<1e-6);
    remaining.path=path({{3.4,0},{3.4,0.5},{5,0.5}});bool rejected=false;
    try{nav_components::makeHoleExecutionPlan(remaining,nullptr,config,"session","goal",3,&initial,3.4,uid);}
    catch(const std::runtime_error&){rejected=true;}
    assert(rejected); // 剩余出口直线被转弯破坏，必须拒绝。
    s.preparation.clear();rejected=false;
    try{nav_components::makeHoleExecutionPlan(s,nullptr,config,"session","goal",4,nullptr,0,uid);}
    catch(const std::runtime_error&){rejected=true;}
    assert(rejected); // 旧A缺元数据不猜默认值。
    nav_components::HoleRouteAttempt chosen;chosen.passage=c;chosen.A={1.2,0};chosen.prepare_distance=0.8;chosen.check=c.check;s.selected={chosen};
    auto legacy=nav_components::makeHoleExecutionPlan(s,nullptr,config,"session","goal",5,nullptr,0,uid);
    assert(std::abs(event(legacy.passages[0],EventType::A).arc-1.2)<1e-6);
    std::cout<<"PASS: selected A, UID carry, remaining exit straight, invalid replan, legacy metadata\n";
}
