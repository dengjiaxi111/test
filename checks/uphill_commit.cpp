#include "nav_core/slope_speed_takeover.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    Config c;c.boost_speed=2;c.boost_acceleration=2;
    SlopeSpeedTakeover controller;
    auto r=controller.update(c,"uphill",1.,.5,.5,1.9,true);
    assert(r.active); // Enter the slope without waiting for a speed deficit.
    for(int i=1;i<=60;++i) {
        r=controller.update(c,"uphill",1.+i*.02,2.1,2.,1.9,true);
        assert(r.active&&!r.failed); // Never hand back in the middle of the slope.
    }
    assert(std::abs(r.speed-2.)<1e-9);
    assert(!controller.update(c,"uphill",2.3,2.,2.,1.9,false).active);
    // A safety cancellation starts a new ramp rather than reusing an old target.
    r=controller.update(c,"next",3.,0.,0.,0.,true);
    assert(r.active&&r.speed<=c.boost_acceleration*.02+1e-9);
    std::cout<<"PASS: uphill ownership lasts to geometric exit; cancellation resets ramp\n";
}
