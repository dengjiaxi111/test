// 目标：nav_components/test/test_slopehole_controller.cpp。无需ROS/硬件。
#include "nav_components/slopehole_controller.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
using nav_components::SlopeHoleController;
static Passage passage(const Polyline& path,const std::string& uid,double a,double s,double e,double x,double t) {
    Passage p;p.uid=uid;p.hole_id=uid;p.entry_edge=0;p.exit_edge=2;p.validated=true;
    const std::array<double,6> values{a,s,e,x,t,t};
    for(std::size_t j=0;j<6;++j)p.events[j]=makeEvent(static_cast<EventType>(j),values[j],path);
    p.straights.push_back({s,t,{1,0},false});return p;
}
struct Fixture {
    Config config;SlopeHoleController fsm;Plan plan;Input in;StructureRequest request;
    Fixture():config([]{Config c;c.enabled=true;return c;}()),fsm(config) {
        plan.session="s";plan.goal="g";plan.id=1;plan.path={{0,0},{7,0}};
        plan.passages={passage(Polyline(plan.path),"one",1,1.2,2,3,3.5)};
        in.pose_valid=true;in.now=0;in.pose_received=0;in.measured_speed=0.2;
    }
    void accept(){std::string err;assert(fsm.acceptPlan(plan,in,err));}
    Output step(double x) {
        in.now+=0.5;in.pose_received=in.now;in.position={x,0};
        if(in.feedback.received>=0)in.feedback.received=in.now;
        auto out=fsm.update(in);if(out.request)request=*out.request;return out;
    }
    void low(bool completed=true) {
        in.feedback.session="s";in.feedback.goal="g";in.feedback.request_id=request.id;
        in.feedback.revision=request.revision;in.feedback.target=Posture::LOW;
        in.feedback.status=completed?ActionStatus::COMPLETED:ActionStatus::EXECUTING;
        in.feedback.moving_transition_supported=true;in.feedback.received=in.now;
    }
    void advance(double to) {while(in.position.x+0.099<to)step(in.position.x+0.1);step(to);}
};
int main(){
    // 平面累计弧长与插值；越界事件不能夹成端点。
    Polyline turn({{0,0},{3,0},{3,4}});assert(turn.length()==7);
    assert(makeEvent(EventType::A,-1,turn).range==Range::BEFORE_PATH);
    assert(!makeEvent(EventType::D,8,turn).point_valid);
    // 前方低速区触发提前制动，不等到区内才降速。
    const std::vector<SpeedRegion> regions{{2,3,0.1,Travel::RESTRICTED}};
    assert(previewLimit(1.99,1,regions,0.3,0.15)<0.2);
    assert(previewLimit(2.2,1,regions,0.3,0.15)==0.1);
    // 移动准备；旧请求反馈不授权进入，真实准备完成后继续同一路线。
    Fixture f;f.accept();f.advance(1.0);assert(f.fsm.state()==State::PREPARE&&f.request.id);
    f.low(false);auto moving=f.step(1.1);assert(moving.decision==Decision::CONTINUE&&moving.stop_arc);
    f.in.feedback.request_id+=100;auto stale=f.step(1.2);
    assert(stale.state!=State::TRAVERSE&&!f.fsm.visits().at("one").emitted.count(EventType::E));
    f.low();f.advance(1.5);assert(f.fsm.state()==State::TRAVERSE);
    f.advance(3.6);assert(f.fsm.visits().at("one").demand); // D不证明整车退出。
    f.in.feedback.whole_vehicle_clear=f.in.feedback.normal_clearance=true;
    f.in.feedback.cleared_traversals.insert("one");auto restore=f.step(3.7);
    assert(restore.state==State::RESTORE&&restore.decision==Decision::CONTINUE);
    assert(f.request.target==Posture::NORMAL);
    f.in.feedback.target=Posture::NORMAL;f.in.feedback.request_id=f.request.id;
    f.in.feedback.status=ActionStatus::EXECUTING;assert(f.step(3.8).state==State::RESTORE);
    f.in.feedback.status=ActionStatus::COMPLETED;assert(f.step(3.9).state==State::NORMAL);
    // A可以在S后面；准备/路径阶段分开。
    Fixture a;a.plan.passages[0]=passage(Polyline(a.plan.path),"one",1.5,1.2,2,3,3.5);a.accept();a.advance(1.3);
    assert(a.fsm.visits().at("one").phase==Phase::ENTRY_STRAIGHT);
    assert(!a.fsm.visits().at("one").demand);a.advance(1.5);assert(a.fsm.state()==State::PREPARE);
    // 两洞需求交叠；D1不会撤销洞2要求或请求抬高。
    Fixture multi;multi.plan.passages.push_back(passage(Polyline(multi.plan.path),"two",2.5,3.8,4,5,5.5));
    multi.accept();multi.advance(1);multi.low();multi.advance(3.6);
    multi.in.feedback.whole_vehicle_clear=multi.in.feedback.normal_clearance=true;
    multi.in.feedback.cleared_traversals.insert("one");multi.step(3.7);
    assert(!multi.fsm.visits().at("one").demand&&multi.fsm.visits().at("two").demand);
    assert(multi.fsm.state()==State::TRAVERSE);
    // 定位跳跃不能批量伪造安全通过；取消保留结构要求。
    Fixture jump;jump.accept();jump.advance(1);jump.low();jump.step(1.1);
    assert(jump.step(4).state==State::HOLD);assert(!jump.fsm.visits().at("one").emitted.count(EventType::E));
    jump.fsm.closeGoal();assert(jump.fsm.occupied()&&!jump.fsm.canAcceptNewGoal());
    // 源数据已过期，即使收到重复心跳也不能继续；恢复时只按当前请求确认。
    Fixture expired;expired.accept();expired.advance(1);expired.low();expired.step(1.1);
    expired.in.feedback.source_age=2;
    assert(expired.step(1.2).state==State::HOLD);
    expired.in.feedback.source_age=0;assert(expired.step(1.3).state==State::TRAVERSE);
    // 未进入结构时，合法绕行可取消旧需求并安全请求NORMAL，不能把它当完成过洞。
    Fixture abort;abort.accept();abort.advance(1);abort.low();abort.step(1.1);
    abort.in.feedback.whole_vehicle_clear=abort.in.feedback.normal_clearance=true;
    auto bypass=abort.plan;bypass.id=2;bypass.passages.clear();std::string abort_error;
    assert(abort.fsm.acceptPlan(bypass,abort.in,abort_error));
    assert(abort.step(1.2).state==State::RESTORE);
    // 路径阻塞只在显式重新校验后续行；与控制器求解失败区分。
    Fixture blocked;blocked.accept();blocked.advance(1);blocked.low();blocked.step(1.1);
    blocked.fsm.reportPathFailure(blocked.in.now);assert(blocked.step(1.1).state==State::HOLD);
    blocked.in.continuation_verified=true;assert(blocked.step(1.2).state==State::TRAVERSE);
    // 同次通行换plan保持准备与事件历史，旧plan不得重复接纳。
    Fixture re;re.accept();re.advance(1);re.low();re.step(1.1);
    auto replacement=re.plan;replacement.id=2;std::string err;
    assert(re.fsm.acceptPlan(replacement,re.in,err));
    assert(re.fsm.visits().at("one").emitted.count(EventType::A));
    assert(!re.fsm.acceptPlan(replacement,re.in,err));
    std::cout<<"PASS: arc, preview braking, moving prepare/restore, feedback identity, overlap, jump, cancel, replan\n";
}
