#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.enabled=true;c.flat_speed=2;c.traverse_timeout=60;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{5,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;passage.uphill_entry=true;
    passage.polygon={{1,-.2},{2,-.2},{2,.2},{1,.2}};
    const std::array<double,6> arcs{.1,.2,1.,2.,2.5,2.5};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;in.entry_rotation_ready=true;in.measured_speed=0;
    std::string error;assert(core.acceptPlan(p,in,error));StructureRequest request;
    auto step=[&](double x,double dt=.1){
        in.now+=dt;in.pose_received=in.now;in.position={x,0};
        if(request.id)in.feedback={"s","g",request.id,request.revision,in.now,0,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        auto out=core.update(in);if(out.request)request=*out.request;return out;
    };
    for(int i=1;i<=9;++i)assert(step(i*.1).state!=State::HOLD);
    // 洞外机构准备时间不算入15s区域停留。
    for(int i=0;i<100;++i)assert(step(.9).state!=State::HOLD);
    assert(!core.tunnelOccupied());assert(step(1.01).state!=State::HOLD);assert(core.tunnelOccupied());
    in.command_requested=true;
    // 北理式计时覆盖洞内原2.5s无进展判定，即使完全不动，15s前也不误提前触发。
    for(int i=0;i<140;++i)assert(step(1.01).state!=State::HOLD);
    Output out;for(int i=0;i<12;++i)out=step(1.01);
    assert(out.state==State::HOLD&&out.reason=="tunnel residence timeout");
    in.recovery_authorized=true;in.recovery_action_verified=true;
    assert(step(1.01).decision==Decision::RECOVERY);
    std::cout<<"PASS: actual hole residence timer, no PREPARE dwell, 15s HOLD to dedicated recovery\n";
}
