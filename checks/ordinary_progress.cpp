#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
#include <limits>
using namespace nav_core::hole_exec;

Plan plan(bool hole) {
    Plan p;p.session="ordinary-test";p.goal="goal";p.id=1;p.path={{0,0},{1,0}};
    if(hole) {
        Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
        const std::array<double,6> arcs{.6,.7,.8,.9,1.,1.};
        for(std::size_t i=0;i<arcs.size();++i)
            passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
        p.passages.push_back(passage);
    }
    return p;
}
Output moved(bool hole,Point position) {
    Config c;c.enabled=true;c.simulation_only=true;
    nav_components::SlopeHoleController core(c);
    Input in;in.now=0;in.pose_received=0;in.pose_valid=true;in.measured_speed=0;
    std::string error;assert(core.acceptPlan(plan(hole),in,error));
    in.now=3.;in.pose_received=3.;in.position=position;
    return core.update(in);
}
int main() {
    // Ordinary controller owns endpoint overshoot and ordinary tracking tolerance.
    const auto lateral=moved(false,{.3,.4});
    assert(lateral.state==State::NORMAL&&lateral.decision==Decision::CONTINUE);
    const auto overshoot=moved(false,{1.4,0});
    assert(overshoot.state==State::NORMAL&&overshoot.decision==Decision::CONTINUE);
    assert(overshoot.progress==1.);
    // A plan containing a passage retains narrow-corridor safety checks.
    const auto strict=moved(true,{.85,.4});
    assert(strict.state==State::HOLD);
    assert(strict.reason=="inside passage lateral limit exceeded");
    const auto strict_endpoint=moved(true,{1.4,0});
    assert(strict_endpoint.state==State::HOLD);
    // Input freshness/finite feedback remains mandatory even without a passage.
    Config c;c.enabled=true;c.simulation_only=true;
    nav_components::SlopeHoleController core(c);
    Input in;in.pose_valid=true;in.pose_received=0;std::string error;
    assert(core.acceptPlan(plan(false),in,error));
    in.now=1.; // stale pose
    assert(core.update(in).state==State::HOLD);
    in.now=1.1;in.pose_received=in.now;in.measured_speed=std::numeric_limits<double>::quiet_NaN();
    assert(core.update(in).state==State::HOLD);
    std::cout<<"PASS: ordinary tracking and endpoint tolerance stay with controller; hole guards remain strict\n";
}
