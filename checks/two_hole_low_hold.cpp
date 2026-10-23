#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;

struct Fixture {
    Config config;
    nav_components::SlopeHoleController core;
    Plan plan;
    Input input;
    StructureRequest request;
    std::uint64_t low_id=0;
    bool final_clear=true;
    Fixture(bool second=true,bool beyond=false):config([]{
        Config c;c.enabled=true;c.traverse_timeout=4.;return c;
    }()),core(config) {
        plan.session="s";plan.goal="g";plan.id=1;plan.path={{0,0},{12,0}};
        auto add=[&](const std::string& uid,const std::array<double,6>& arcs) {
            Passage p;p.uid=uid;p.hole_id=uid;p.validated=true;
            for(std::size_t i=0;i<6;++i)p.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(plan.path));
            plan.passages.push_back(p);
        };
        add("one",{.2,.3,1.,1.3,2.,2.});
        if(second)add("two",beyond?std::array<double,6>{13.,13.2,14.,14.3,15.,15.}:
                                      std::array<double,6>{7.,7.2,8.,8.3,9.,9.});
        input.pose_valid=true;input.command_requested=true;
        std::string error;assert(core.acceptPlan(plan,input,error));
    }
    Output step(double x,double dt=.1) {
        input.now+=dt;input.pose_received=input.now;input.position={x,0};
        if(request.id) {
            input.feedback={"s","g",request.id,request.revision,input.now,0.,request.target,
                ActionStatus::COMPLETED,true,true,true,{}};
            if(x>=2.)input.feedback.cleared_traversals.insert("one");
            if(x>=9.&&final_clear)input.feedback.cleared_traversals.insert("two");
        }
        auto out=core.update(input);
        if(out.request){request=*out.request;if(request.target==Posture::LOW&&!low_id)low_id=request.id;}
        assert(out.state!=State::HOLD&&out.decision==Decision::CONTINUE);
        return out;
    }
    void advance(double to) {
        while(input.position.x+.10001<to)step(input.position.x+.1);
        step(to);
    }
};

int main() {
    Fixture f;
    f.input.entry_rotation_ready=false;
    assert(!f.step(.1).hold_gimbal_heading);
    assert(!f.step(.2).hold_gimbal_heading); // 请求LOW不等于准备完成。
    assert(!f.step(.3).hold_gimbal_heading); // LOW完成但未对准，不能锁存。
    f.input.entry_rotation_ready=true;f.input.entry_rotation_uid="two";
    assert(!f.step(.4).hold_gimbal_heading); // 不得复用另一洞的反馈。
    f.input.entry_rotation_uid="one";
    assert(f.step(.5).hold_gimbal_heading);
    f.advance(2.1);
    assert(f.core.visits().at("one").complete);
    assert(!f.core.visits().at("two").demand); // A2 is still ahead.
    assert(!f.core.entryAuthorized("two"));
    assert(f.request.target==Posture::LOW&&f.request.id==f.low_id);
    assert(f.request.traversal_uids.empty()); // Do not invent a second demand early.
    assert(f.step(2.1).hold_gimbal_heading); // D1不能释放云台。
    f.advance(4.);
    for(int i=0;i<60;++i) {
        auto out=f.step(4.,.1); // Connector time must not consume passage timeout.
        assert(out.state==State::TRAVERSE&&out.speed_limit==f.config.flat_speed);
        assert(out.hold_gimbal_heading);
        assert(f.request.target==Posture::LOW&&f.request.id==f.low_id);
    }
    {
        auto paused=f.core;auto sample=f.input;
        paused.reportMotionFailure(sample.now);
        assert(paused.update(sample).hold_gimbal_heading); // 安全禁止覆盖保持，但不丢掉保持需求。
    }
    f.input.entry_rotation_ready=false;f.input.entry_rotation_uid="two";
    f.advance(7.1);
    assert(f.core.visits().at("two").demand&&!f.core.entryAuthorized("two"));
    assert(f.step(7.1).hold_gimbal_heading); // 云台保持不代替第二洞入口许可。
    f.input.entry_rotation_ready=true;
    assert(f.step(7.2).hold_gimbal_heading);
    assert(f.core.visits().at("two").demand&&f.core.entryAuthorized("two"));
    assert(f.request.target==Posture::LOW&&f.request.id==f.low_id);
    f.final_clear=false;f.advance(9.1);
    assert(!f.core.visits().at("two").complete&&f.request.target==Posture::LOW);
    assert(f.step(9.1).hold_gimbal_heading); // D2已到但整车净空尚未确认。
    f.final_clear=true;assert(!f.step(9.2).hold_gimbal_heading);
    assert(f.core.visits().at("two").complete);
    assert(f.request.target==Posture::NORMAL&&f.request.id!=f.low_id);

    Fixture single(false);single.advance(2.1);
    assert(single.request.target==Posture::NORMAL);
    assert(!single.step(2.1).hold_gimbal_heading);
    Fixture beyond(true,true);beyond.advance(2.1);
    assert(beyond.request.target==Posture::NORMAL); // No holding for a hole beyond the goal.
    assert(!beyond.step(2.1).hold_gimbal_heading);
    Fixture replan;replan.advance(3.);
    auto remaining=replan.plan;remaining.id=2;remaining.passages.erase(remaining.passages.begin()+1);
    std::string error;assert(replan.core.acceptPlan(remaining,replan.input,error));
    assert(!replan.step(3.1).hold_gimbal_heading);assert(replan.request.target==Posture::NORMAL);
    std::cout<<"PASS: C++ holds LOW and aligned gimbal heading until final clearance; A, entry gates, safety, single-hole and replan semantics preserved\n";
}
