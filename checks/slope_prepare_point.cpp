#include "nav_core/hole_execution_types.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Plan p;p.path={{0,0},{12,0}};
    for(auto spec:{std::array<double,2>{.2,2.},std::array<double,2>{7.8,9.3}}) {
        Passage q;const double a=spec[0],e=spec[1];
        q.events[0]=makeEvent(EventType::A,a,Polyline(p.path));
        q.events[2]=makeEvent(EventType::E,e,Polyline(p.path));p.passages.push_back(q);
    }
    p.slopes={{"up",1.3,2.1,true},{"down",7.9,8.84,false}};
    const auto points=p.path;
    advanceSlopePreparation(p,.5);
    assert(event(p.passages[0],EventType::A).arc==.2);
    assert(std::abs(event(p.passages[1],EventType::A).arc-7.4)<1e-9);
    assert(p.path.size()==points.size()&&p.path.back().x==points.back().x);
    advanceSlopePreparation(p,.5);assert(std::abs(event(p.passages[1],EventType::A).arc-7.4)<1e-9);
    p.slopes[0].begin=.1;advanceSlopePreparation(p,.5);
    assert(event(p.passages[0],EventType::A).range==Range::BEFORE_PATH);
    std::cout<<"PASS: execution A advances for uphill/downhill, earlier A survives, path stays unchanged\n";
}
