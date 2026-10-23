#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.enabled=true;c.simulation_only=true;c.flat_speed=2.;c.acceleration_limit=2.;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="connector";p.goal="g";p.id=1;p.path={{0,0},{8,0}};
    for(int n=0;n<2;++n) {
        const double offset=n?5.:0.;
        Passage passage;passage.uid=n?"second":"first";passage.hole_id=passage.uid;passage.validated=true;
        const std::array<double,6> arcs{.1,.2,.4,.8,1.,1.2};
        for(std::size_t i=0;i<arcs.size();++i)
            passage.events[i]=makeEvent(static_cast<EventType>(i),offset+arcs[i],Polyline(p.path));
        p.passages.push_back(passage);
    }
    Input in;in.pose_valid=true;in.pose_received=0;std::string error;
    assert(core.acceptPlan(p,in,error));StructureRequest request;
    auto step=[&](double x,double y=0.,double dt=.1) {
        in.now+=dt;in.pose_received=in.now;in.position={x,y};
        if(request.id)in.feedback={p.session,p.goal,request.id,request.revision,in.now,0.,request.target,
            ActionStatus::COMPLETED,true,true,true,{"first"}};
        auto out=core.update(in);if(out.request)request=*out.request;return out;
    };
    for(int i=1;i<=16;++i)assert(step(i*.1).state!=State::HOLD);
    assert(core.visits().at("first").complete);
    const auto connector=step(1.7,.4,1.);
    assert(connector.state==State::TRAVERSE&&connector.decision==Decision::CONTINUE);
    assert(request.target==Posture::LOW); // Keep LOW across the connector without freezing correction.
    assert(step(1.8,0.,1.).state!=State::HOLD);
    for(int i=19;i<=51;++i)assert(step(i*.1).state!=State::HOLD);
    const auto strict=step(5.2,.4,1.);
    assert(strict.state!=State::HOLD&&strict.stop_arc);
    const auto inside=step(5.5,.4,1.);
    assert(inside.state==State::HOLD);
    std::cout<<"PASS: connector/approach tracking can correct; entry is gated and inside remains strict\n";
}
