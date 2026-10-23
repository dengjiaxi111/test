#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.enabled=true;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{2,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
    const std::array<double,6> arcs{.1,.2,.6,1.2,2.8,2.8};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;std::string error;
    assert(core.acceptPlan(p,in,error));StructureRequest request;
    auto step=[&](double x,double y) {
        in.now+=.2;in.pose_received=in.now;in.position={x,y};
        if(request.id)in.feedback={"s","g",request.id,request.revision,in.now,0.,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        auto out=core.update(in);if(out.request)request=*out.request;return out;
    };
    for(double x:{.1,.3,.5,.7,.9,1.1,1.3,1.5,1.7,1.9})assert(step(x,0).state!=State::HOLD);
    assert(step(2.16,0).state!=State::HOLD); // Longitudinal overshoot is not lateral deviation.
    assert(core.entryPositionReady());
    assert(step(2.16,.16).state!=State::HOLD); // Already past X and no physical slope: ordinary tracking owns it.
    in.command_requested=true;
    for(int i=0;i<20;++i)assert(step(1.8,.1).state!=State::HOLD);
    std::cout<<"PASS: after physical terrain, ordinary endpoint correction is not passage lateral/stall failure\n";
}
