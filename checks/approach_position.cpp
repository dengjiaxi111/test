#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.enabled=true;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{5,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
    const std::array<double,6> arcs{.2,1.,2.,3.,3.5,3.5};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;std::string error;
    assert(core.acceptPlan(p,in,error));StructureRequest request;
    auto step=[&](double x,double y) {
        in.now+=.2;in.pose_received=in.now;in.position={x,y};
        if(request.id)in.feedback={"s","g",request.id,request.revision,in.now,0.,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        auto out=core.update(in);if(out.request)request=*out.request;return out;
    };
    for(double x:{.2,.4,.6,.8})assert(step(x,0).state!=State::HOLD);
    auto out=step(1.,.16);
    assert(out.state!=State::HOLD&&out.decision==Decision::CONTINUE);
    assert(out.stop_arc&&*out.stop_arc<2.); // Keep moving to correct, but no unchecked entry.
    {
        auto crossed=core;auto sample=in;sample.now+=1.;sample.pose_received=sample.now;sample.feedback.received=sample.now;sample.position={2.01,.16};
        assert(crossed.update(sample).state==State::HOLD);
    }
    out=step(1.2,.10);assert(out.state!=State::HOLD&&!out.stop_arc);
    for(double x:{1.4,1.6,1.8,2.,2.2})assert(step(x,.10).state!=State::HOLD);
    out=step(2.3,.16);assert(out.state==State::HOLD); // Inside remains strict.
    std::cout<<"PASS: approach lateral error keeps correction alive and gates entry; inside violation stops\n";
}
