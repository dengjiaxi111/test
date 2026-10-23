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
        // 全程未取得对准许可，LOW完成本身不能放行。
        const auto out=step(i*.1);
        if(i>=3){assert(out.stop_arc);assert(*out.stop_arc<2.);}
        assert(!core.visits().at("one").emitted.count(EventType::E));
    }
    // 准备完成但未确认停转，实际越过E必须拒绝发出“成功进入”事件。
    const auto old_id=core.plan().id;
    c.boost_speed=3.;c.acceleration_limit=10.;
    core.applyRuntimeConfig(c,core.plan().speeds);
    assert(core.plan().id==old_id+1&&core.plan().passages[0].uid=="one");
    assert(core.visits().at("one").emitted.count(EventType::A));
    assert(core.visits().at("one").emitted.count(EventType::S));
    assert(core.lowReady(in)); // 在线调参没有丢掉原动作请求和反馈匹配。
    in.entry_rotation_ready=allow_entry;
    const auto denied=step(2.);
    if(allow_entry){assert(denied.state==State::TRAVERSE);assert(core.visits().at("one").emitted.count(EventType::E));}
    else{assert(denied.state==State::HOLD);assert(!core.visits().at("one").emitted.count(EventType::E));}
}
void check_committed_entry(bool uphill) {
    Config c;c.enabled=true;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{6,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;passage.uphill_entry=uphill;
    const std::array<double,6> arcs{.2,.4,2.,3.,3.5,3.5};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;in.entry_rotation_ready=false;
    std::string error;assert(core.acceptPlan(p,in,error));
    StructureRequest request;
    auto step=[&](double x,bool fresh=true) {
        in.now+=.2;in.pose_received=in.now;in.position={x,0};
        if(request.id&&fresh)in.feedback={"s","g",request.id,request.revision,in.now,0.,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        auto out=core.update(in);if(out.request)request=*out.request;return out;
    };
    step(.2);
    {
        auto wrong=core;auto sample=in;sample.now+=.1;sample.pose_received=sample.now;
        sample.entry_rotation_ready=true;sample.entry_rotation_uid="two";
        sample.feedback={"s","g",request.id,request.revision,sample.now,0.,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        const auto result=wrong.update(sample);
        assert(result.stop_arc&&!wrong.entryAuthorized("one")&&!wrong.entryAuthorized("two"));
    }
    in.entry_rotation_ready=true;
    auto out=step(.4);assert(out.decision==Decision::CONTINUE&&!out.stop_arc);
    // 已放行，越过E前停车线；再出现坡面角速度波动，不得挂回身后的停车线。
    for(double x:{.6,.8,1.,1.2,1.4,1.7}) {
        out=step(x);assert(out.decision==Decision::CONTINUE&&!out.stop_arc);
    }
    in.entry_rotation_ready=false;in.measured_speed=1.;
    out=step(1.9);
    assert(out.decision==Decision::CONTINUE&&!out.stop_arc);
    out=step(2.1);
    assert(out.state==State::TRAVERSE&&out.decision==Decision::CONTINUE&&!out.stop_arc);
    assert(core.visits().at("one").emitted.count(EventType::E));
    // 同UID普通重规划不丢失许可。
    p.id=core.plan().id+1;assert(core.acceptPlan(p,in,error));
    out=step(2.2);assert(out.decision==Decision::CONTINUE);
    assert(core.entryAuthorized("one"));
    // 同一动作重发、在线速度调参不产生新进入动作。
    const auto old_request=request.id;
    core.applyRuntimeConfig(c,p.speeds);
    out=step(2.3);assert(core.entryAuthorized("one")&&request.id==old_request);
    // 另一通行不能继承许可；绑定的对准UID必须一致。
    assert(!core.entryAuthorized("two"));
    {
        auto changed=core;auto next=p;next.id=core.plan().id+1;
        ++next.passages[0].requirement_revision;
        assert(changed.acceptPlan(next,in,error));
        assert(!changed.entryAuthorized("one"));
        auto changed_in=in;changed_in.now+=.01;changed_in.pose_received=changed_in.now;
        const auto result=changed.update(changed_in);
        assert(result.decision!=Decision::CONTINUE); // 已在结构内，旧LOW不能放行新需求。
        assert(!changed.entryAuthorized("one"));
    }
    {
        auto failed=core;auto fault=in;fault.now+=.01;fault.pose_received=fault.now;
        fault.feedback.received=fault.now;fault.feedback.status=ActionStatus::FAILED;
        assert(failed.update(fault).state==State::HOLD&&!failed.entryAuthorized("one"));
    }
    {
        auto retreated=core;auto stopped=in;stopped.measured_speed=0;stopped.position={.4,0};
        retreated.completeRetreat(.4,stopped);
        assert(!retreated.entryAuthorized("one"));
        stopped.now+=.1;stopped.pose_received=stopped.now;stopped.feedback.received=stopped.now;
        auto result=retreated.update(stopped);
        assert(result.stop_arc&&!retreated.entryAuthorized("one"));
    }
    {
        auto closed=core;closed.closeGoal();assert(!closed.entryAuthorized("one"));
        auto invalid=core;invalid.invalidate("test");assert(!invalid.entryAuthorized("one"));
    }
    // 许可不能掩盖真实机构反馈过期。
    step(2.2,false);out=step(2.2,false);out=step(2.2,false);
    assert(out.state==State::HOLD&&out.decision!=Decision::CONTINUE);
    assert(!core.entryAuthorized("one"));
}
void check_shrink_gate() {
    Config c;c.enabled=true;c.flat_speed=1.;c.braking_deceleration=1.5;c.control_latency=.1;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{4,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
    const std::array<double,6> arcs{.2,.4,2.,3.,3.5,3.5};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;in.measured_speed=0.;in.entry_rotation_ready=false;
    std::string error;assert(core.acceptPlan(p,in,error));
    auto step=[&](double x) {
        in.now+=.2;in.pose_received=in.now;in.position={x,0};return core.update(in);
    };
    step(.1);
    auto waiting=step(.2);
    assert(waiting.state==State::PREPARE);
    assert(waiting.decision==Decision::CONTINUE&&waiting.speed_limit>0.);
    assert(waiting.stop_arc&&*waiting.stop_arc>.4);
    assert(waiting.request&&waiting.request->target==Posture::LOW);
    assert(waiting.speed_limit==c.flat_speed); // A时不增加固定准备限速。
    const auto request=*waiting.request;
    in.feedback={"s","g",request.id,request.revision,in.now,0.,Posture::LOW,ActionStatus::EXECUTING,false,false,true,{}};
    in.entry_rotation_ready=false;
    in.feedback.received=in.now+.2;
    const auto running=step(.4);
    assert(!running.cancel_request&&running.state==State::PREPARE);
    if(running.request)assert(running.request->id==request.id);
}
void check_preparation_braking() {
    Config c;c.enabled=true;c.flat_speed=3.;c.braking_deceleration=1.5;c.control_latency=.1;
    c.entry_margin=.45;
    nav_components::SlopeHoleController core(c);
    Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{5,0}};
    Passage passage;passage.uid="one";passage.hole_id="A";passage.validated=true;
    const std::array<double,6> arcs{.5,1.2,2.,3.,3.5,3.5};
    for(std::size_t i=0;i<arcs.size();++i)passage.events[i]=makeEvent(static_cast<EventType>(i),arcs[i],Polyline(p.path));
    p.passages.push_back(passage);
    Input in;in.pose_valid=true;in.pose_received=0;in.position={.5,0};in.measured_speed=2.;in.entry_rotation_ready=false;
    std::string error;assert(core.acceptPlan(p,in,error));
    auto out=core.update(in);
    assert(out.request&&out.request->target==Posture::LOW); // 紧停也不阻止A启动LOW。
    const auto request=*out.request;
    assert(out.decision==Decision::STOP&&out.reason.find("emergency")!=std::string::npos);
    {
        // 先取得初次许可，随后才完成平移停稳；不应再次要求角速度稳定。
        auto settling=core;auto sample=in;sample.measured_speed=0;sample.entry_rotation_ready=true;
        sample.feedback={"s","g",request.id,request.revision,.1,0,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
        sample.now=.1;sample.pose_received=.1;
        assert(settling.update(sample).decision==Decision::STOP);
        assert(settling.entryAuthorized("one"));
        sample.entry_rotation_ready=false;sample.now=.4;sample.pose_received=.4;sample.feedback.received=.4;
        assert(settling.update(sample).decision==Decision::CONTINUE);
    }
    auto step=[&](double now) {
        in.now=now;in.pose_received=now;in.feedback.received=now;return core.update(in);
    };
    in.measured_speed=0;
    in.feedback={"s","g",request.id,request.revision,0,0,Posture::LOW,ActionStatus::COMPLETED,false,false,true,{}};
    step(.1);out=step(.4);
    assert(out.decision==Decision::STOP); // 已LOW但尚未对准，不得解锁入口。
    in.entry_rotation_ready=true;out=step(.5);
    assert(out.decision==Decision::CONTINUE&&!out.stop_arc&&out.speed_limit==c.flat_speed);

    // LOW执行中即使对准已好，也须在停车边界减速；完成后才撤销边界。
    nav_components::SlopeHoleController waiting(c);
    in.now=0;in.pose_received=0;in.position={.5,0};in.feedback={};in.measured_speed=0;
    assert(waiting.acceptPlan(p,in,error));out=waiting.update(in);assert(out.request);
    const auto pending=*out.request;
    in.feedback={"s","g",pending.id,pending.revision,1.,0,Posture::LOW,ActionStatus::EXECUTING,false,false,true,{}};
    in.now=1.;in.pose_received=1.;in.position={1.5,0};out=waiting.update(in);
    assert(out.stop_arc&&out.speed_limit<c.flat_speed);
    assert(out.speed_limit*c.control_latency+out.speed_limit*out.speed_limit/(2*c.braking_deceleration)<=.05+1e-8);

    // 未许可越E的异常须有期限，不能每帧提前返回无限等待。
    in.now=2.;in.pose_received=2.;in.position={2.,0};in.feedback.received=2.;
    out=waiting.update(in);assert(out.state==State::HOLD);
    in.now=2.+c.hold_timeout+.01;in.pose_received=in.now;in.feedback.received=in.now;
    out=waiting.update(in);assert(out.decision==Decision::FAILURE&&out.pause_progress_timeout);
    assert(!waiting.visits().at("one").emitted.count(EventType::E));
    // 不允许A位于停车线之后/线上，否则预览制动会阻断A触发。
    for(double late_a:{1.6,1.55,1.545}) {
        auto invalid=p;invalid.passages[0].events[0]=makeEvent(EventType::A,late_a,Polyline(p.path));
        nav_components::SlopeHoleController check(c);
        in.position={0,0};in.now=0;in.pose_received=0;
        assert(!check.acceptPlan(invalid,in,error)&&error.find("parking boundary")!=std::string::npos);
    }
}
int main() {
    check_committed_entry(false);check_committed_entry(true);
    check_shrink_gate();
    check_preparation_braking();
    check_entry(false);check_entry(true);
    std::cout<<"PASS: 初次LOW/对准许可、上下坡许可保持、请求/需求/退让清理及真实过期停车\n";
}
