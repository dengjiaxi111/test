#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.enabled=true;c.simulation_only=true;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="feedback";p.goal="one";p.id=1;p.path={{0,0},{10,0}};
    Input in;in.now=1;in.pose_received=1;in.pose_valid=true;
    std::string error;assert(core.acceptPlan(p,in,error));
    assert(core.update(in).decision==Decision::CONTINUE);
    in.now=1.02;in.pose_valid=false;
    assert(core.update(in).state==State::HOLD);
    in.now=1.04;in.pose_received=1.04;in.pose_valid=true;
    core.update(in);
    in.now=1.04+c.settle_time+.01;in.pose_received=in.now;
    const auto restored=core.update(in);
    assert(restored.state==State::NORMAL&&restored.decision==Decision::CONTINUE);
    // A real gap must still stop; no cached measurement may extend its lifetime.
    in.now+=c.pose_timeout+.01;
    assert(core.update(in).state==State::HOLD);
    in.now+=c.hold_timeout+.01;
    assert(core.update(in).decision==Decision::FAILURE);
    std::cout<<"PASS: fresh stable input resumes transient HOLD; persistent loss still fails\n";
}
