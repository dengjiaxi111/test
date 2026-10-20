#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
void check_entry(bool allow_entry) {
    Config c;c.enabled=true;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{4,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
    const std::array<double,6> arcs{.2,.4,2.,3.,3.5,3.5};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;in.measured_speed=0.;in.entry_rotation_ready=false;
    std::string error;assert(core.acceptPlan(p,in,error));
    StructureRequest request;
    auto step=[&](double x) {
        in.now+=.2;in.pose_received=in.now;in.position={x,0};
        if(request.id)in.feedback={"s","g",request.id,request.revision,in.now,0.,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        auto out=core.update(in);if(out.request)request=*out.request;return out;
    };
    for(int i=1;i<=19;++i) {
        const auto out=step(i*.1);
        if(i>=3){assert(out.stop_arc);assert(*out.stop_arc<2.);}
        assert(!core.visits().at("one").emitted.count(EventType::E));
    }
    // 准备完成但未确认停转，实际越过E必须拒绝发出“成功进入”事件。
    in.entry_rotation_ready=allow_entry;
    const auto denied=step(2.);
    if(allow_entry){assert(denied.state==State::TRAVERSE);assert(core.visits().at("one").emitted.count(EventType::E));}
    else{assert(denied.state==State::HOLD);assert(!core.visits().at("one").emitted.count(EventType::E));}
}
int main() {
    check_entry(false);check_entry(true);
    std::cout<<"PASS: 低姿态完成不代替停转许可，E上游停车边界、拒绝及有效反馈后进入\n";
}
