#include "nav_components/omni_model.hpp"
#include <cassert>
#include <iostream>
using namespace nav_components::omni;
void near(double a,double b) { assert(std::abs(a-b)<1e-9); }
int main() {
    for(double radius:{0.05,0.3,1.0}) {
        const auto p=[&](double angle){return Vec{radius*std::cos(angle),radius*std::sin(angle)};};
        const double k=pathCurvature(p(0),p(0.01),p(0.033));near(k,1/radius);
        const double speed=curvatureSpeed(k,1.5,0.08);near(speed*speed*k,1.5);
        assert(speed<curvatureSpeed(0,1.5,0.08));
    }
    near(pathCurvature({0,0},{0,0},{1,0}),0);
    assert(std::isinf(pathCurvature({0,0},{1,0},{0,0})));
    auto x=step({1,2,3,-4},{2,1},0.1);
    near(x[0],1.31); near(x[1],1.605); near(x[2],3.2); near(x[3],-3.9);
    for(double alpha: {0.0,0.8,1.0}) {
        VelocityObserver observer(alpha);
        auto start=observer.update(10,{1,2},true);
        observer.record(10,start,{2,4});
        auto fused=observer.update(10.02,{0,0},true);
        near(fused[0],(1-alpha)*2); near(fused[1],(1-alpha)*4);
        auto half=observer.update(10.01,{0,0},true);
        near(half[0],(1-alpha)*1.5);
        auto held=observer.update(10.08,{0,0},true);
        near(held[0],(1-alpha)*2); // no indefinite acceleration extrapolation
        if(alpha>0) {
            bool rejected=false;
            try { observer.update(10.04,{0,0},false); } catch(...) { rejected=true; }
            assert(rejected);
        }
    }
    VelocityObserver pure(0);
    near(pure.update(1,{99,99},false)[0],0);
    pure.record(1,{0,0},{0.4,0}); // final clipped target, not unconstrained optimizer result
    near(pure.update(1.02,{99,99},false)[0],0.4);
    pure.reset(); near(pure.update(2,{0,0},false)[0],0);
    auto diagonal=limit({3,4},2); near(norm(diagonal),2);
    auto forward=rotate({1,0},M_PI/2); near(forward[0],0); near(forward[1],1);
    auto inverse=rotate(forward,-M_PI/2); near(inverse[0],1); near(inverse[1],0);
    assert(!fresh(1,2,1)); assert(!fresh(2,1,0.1));
    assert(fresh(1790185873.400540,1790185873.4005402,0.5));
    assert(fresh(1790244246.896,1790244246.897,0.5));
    assert(!fresh(1790244246.896,1790244246.916,0.5));
    std::cout<<"Omni model/fusion/protection tests passed\n";
}
