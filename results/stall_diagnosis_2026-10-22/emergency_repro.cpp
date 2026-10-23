#include "nav_components/slopehole_controller.hpp"
#include <iostream>
using namespace nav_core::hole_exec;
int main(){
 for(int scenario=0;scenario<4;scenario++){
 Config c;c.enabled=true;c.braking_deceleration=1.5;c.control_latency=.1;c.entry_margin=.45;c.prepare_speed=3.05;c.flat_speed=3.;c.acceleration_limit=10.;c.feedback_timeout=.4;c.pose_timeout=.4;c.traverse_timeout=60.;nav_components::SlopeHoleController fsm(c);Input in;in.pose_valid=true;in.now=0;in.pose_received=0;in.position={1.2,0};in.measured_speed=1.5;in.entry_rotation_ready=(scenario!=0);
 Plan p;p.session="s";p.goal="g";p.id=1;p.path={{0,0},{7,0}};Passage h;h.uid="h";h.hole_id="h";h.validated=true;h.entry_edge=0;h.exit_edge=2;std::array<double,6> a{.5,1.2,2.,3.,3.5,3.5};for(int j=0;j<6;j++)h.events[j]=makeEvent(static_cast<EventType>(j),a[j],Polyline(p.path));p.passages={h};std::string err;if(!fsm.acceptPlan(p,in,err)){std::cout<<err<<"\n";return 1;}
 std::cout<<"SCENARIO "<<scenario<<"\n";std::string previous;StructureRequest request;bool have=false;
 for(int i=0;i<=6000;i++){
 in.now=i*.02;in.pose_received=in.now;in.measured_speed=i?0:1.5;
 if(have&&scenario>=2){in.feedback.session=request.session;in.feedback.goal=request.goal;in.feedback.request_id=request.id;in.feedback.revision=request.revision;in.feedback.target=request.target;in.feedback.received=in.now;in.feedback.source_age=0;in.feedback.moving_transition_supported=true;in.feedback.status=(scenario==3&&in.now>.8)?ActionStatus::COMPLETED:ActionStatus::EXECUTING;}
 auto o=fsm.update(in);if(o.request){request=*o.request;have=true;}
 std::string key=std::to_string(int(o.state))+"/"+std::to_string(int(o.decision))+" "+o.reason+" request="+std::to_string(have);
 if(key!=previous||i==6000){std::cout<<"t="<<in.now<<" "<<key<<"\n";previous=key;}
 if(o.decision==Decision::FAILURE)break;
 }
 }
}
