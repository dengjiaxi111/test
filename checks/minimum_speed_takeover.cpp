#include "nav_core/slope_speed_takeover.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.boost_speed=2;c.boost_acceleration=2;
    SlopeSpeedTakeover control;
    assert(!control.update(c,"s",0,0,0,1,false).active);
    auto r=control.update(c,"s",1,0,0,0,true);
    assert(r.active&&r.speed<=.041);
    double previous=r.speed;
    for(int i=1;i<=300;++i) {
        r=control.update(c,"s",1+i*.02,i<100?-.1:2.1,0,1.9,true);
        assert(r.active&&!r.failed&&r.speed>=previous&&r.speed<=2.);
        previous=r.speed;
    }
    assert(std::abs(r.speed-2.)<1e-9);
    assert(!control.update(c,"s",7.1,2,2,1.9,false).active);
    r=control.update(c,"next",8,0,0,1.9,true);
    assert(r.active&&r.speed<=.041);
    r=control.update(c,"next",7.9,0,0,1.9,true);
    assert(!r.active);
    std::cout<<"PASS: signed-speed monitoring, persistent uphill ownership, ramp and safety cancellation\n";
}
