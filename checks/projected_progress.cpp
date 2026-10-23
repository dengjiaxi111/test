#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.enabled=true;c.simulation_only=true;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="projection-test";p.goal="goal";p.id=1;p.path={{0,0},{4,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
    // S may precede A; exercise event deduplication without a posture request.
    const std::array<double,6> arcs{1.2,.2,2.,3.,3.5,3.5};
    for(std::size_t i=0;i<arcs.size();++i)
        passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.now=1;in.pose_received=1;in.pose_valid=true;in.position={1.05,0};
    std::string error;assert(core.acceptPlan(p,in,error));
    auto first=core.update(in);assert(first.events.size()==1&&first.events.front().type==EventType::S);
    auto step=[&](double x) {in.now+=.003;in.pose_received=in.now;in.position={x,0};return core.update(in);};
    // Each sample retreats only 1cm, but accumulated retreat exceeds per-sample reach.
    for(int i=1;i<=7;++i) {
        const auto out=step(1.05-i*.01);
        assert(out.state!=State::HOLD);assert(out.events.empty());
        assert(std::abs(out.progress-1.05)<1e-9);
    }
    for(int i=6;i>=0;--i) {
        const auto out=step(1.05-i*.01);
        assert(out.state!=State::HOLD);assert(out.events.empty());
    }
    assert(core.visits().at("one").emitted.count(EventType::S)==1);
    // Gradual retreat beyond the .15m window must be detected by its actual arc,
    // rather than hidden by projection clamping at the permitted lower bound.
    for(int i=1;i<=15;++i) {
        const auto out=step(1.05-i*.01);
        assert(out.state!=State::HOLD);assert(out.events.empty());
    }
    const auto rejected=step(1.05-.16);
    assert(rejected.state==State::HOLD);
    assert(rejected.reason=="unreliable progress/localization jump");
    assert(core.visits().at("one").emitted.count(EventType::S)==1);
    std::cout<<"PASS: per-sample reverse projection is distinct from committed event progress\n";
}
