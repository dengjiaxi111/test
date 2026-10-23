#include "nav_core/hole_execution_types.hpp"
#include <cassert>
#include <iostream>
using namespace nav_core::hole_exec;
int main() {
    std::vector<SpeedRegion> r{{1.,2.,.35,Travel::RESTRICTED}};
    const double before=previewLimit(1.-1e-9,2.,r,1.5,.1);
    std::cout<<"before="<<before<<" inside="<<previewLimit(1.,2.,r,1.5,.1)<<std::endl;
    assert(before>=.35-1e-8);
    assert(std::abs(before-.35)<1e-6);
    assert(previewLimit(.9,2.,{},1.5,.1,1.)>0);
    assert(previewLimit(1.,2.,{},1.5,.1,1.)==0);
    // S-E=.5且E前停车余量=.45，S处必须已降到剩余.05m内能停住。
    const double approach=previewLimit(0.,.35,{},1.5,.1,.05);
    assert(approach<.35&&approach*.1+approach*approach/(2*1.5)<=.05+1e-9);
}
