#pragma once
#include "nav_core/hole_passage.hpp"
#include <nav_msgs/msg/occupancy_grid.hpp>

namespace nav_core {
inline HolePassageCheck checkHoleGridSegment(const nav_msgs::msg::OccupancyGrid &map,
        double threshold, HolePoint a, HolePoint b) {
    const auto &info=map.info;
    const double r=info.resolution,ox=info.origin.position.x,oy=info.origin.position.y;
    const auto &q=info.origin.orientation;
    if (!holeFinite(a)||!holeFinite(b)||!std::isfinite(r)||r<=0 ||
        !std::isfinite(ox)||!std::isfinite(oy)||info.width==0||info.height==0 ||
        map.data.size()!=static_cast<std::size_t>(info.width)*info.height ||
        !std::isfinite(threshold)||threshold<=0||threshold>100 ||
        !std::isfinite(q.w)||std::abs(std::abs(q.w)-1)>1e-6 ||
        !std::isfinite(q.x)||!std::isfinite(q.y)||!std::isfinite(q.z)||
        std::abs(q.x)+std::abs(q.y)+std::abs(q.z)>1e-6)
        return holeCheck(false,"INVALID_MAP",a);
    const HolePoint p{(a.x-ox)/r,(a.y-oy)/r},end{(b.x-ox)/r,(b.y-oy)/r};
    for (auto point : {p,end})
        if (!holeFinite(point)||point.x<0||point.y<0||point.x>=info.width||point.y>=info.height)
            return holeCheck(false,"OUT_OF_MAP",{ox+point.x*r,oy+point.y*r});
    const auto delta=end-p;
    // 线段在每个网格边界处及相邻边界之间均检查，包含顶点的四个相邻格。
    // 复杂度为 O(横向跨格数+纵向跨格数)，不会漏掉极短的障碍格交集。
    std::vector<double> cuts{0,1};
    const auto addCuts=[&](double begin,double finish) {
        if (std::abs(finish-begin)<1e-14) return;
        const int first=static_cast<int>(std::ceil(std::min(begin,finish)));
        const int last=static_cast<int>(std::floor(std::max(begin,finish)));
        for (int k=first;k<=last;++k) {
            const double t=(k-begin)/(finish-begin);
            if(t>0&&t<1) cuts.push_back(t);
        }
    };
    addCuts(p.x,end.x); addCuts(p.y,end.y);
    std::sort(cuts.begin(),cuts.end());
    const auto checkAt=[&](double t) {
        const auto point=p+delta*t;
        const int x=static_cast<int>(std::floor(point.x)), y=static_cast<int>(std::floor(point.y));
        const bool on_x=std::abs(point.x-std::round(point.x))<1e-9;
        const bool on_y=std::abs(point.y-std::round(point.y))<1e-9;
        const int bx=on_x?static_cast<int>(std::round(point.x)):x;
        const int by=on_y?static_cast<int>(std::round(point.y)):y;
        for(int cy=by-(on_y?1:0);cy<=by;++cy) for(int cx=bx-(on_x?1:0);cx<=bx;++cx) {
            const HolePoint world{ox+point.x*r,oy+point.y*r};
            if(cx<0||cy<0||cx>=static_cast<int>(info.width)||cy>=static_cast<int>(info.height))
                return holeCheck(false,"OUT_OF_MAP",world);
            const int value=map.data[static_cast<std::size_t>(cy)*info.width+cx];
            if(value<0) return holeCheck(false,"UNKNOWN_CELL",world);
            if(value>=threshold) return holeCheck(false,"OCCUPIED_CELL",world);
        }
        return holeCheck(true,"OK");
    };
    for(std::size_t i=0;i<cuts.size();++i) {
        auto check=checkAt(cuts[i]); if(!check.valid) return check;
        if(i+1<cuts.size()) {check=checkAt((cuts[i]+cuts[i+1])*0.5);if(!check.valid)return check;}
    }
    return holeCheck(true,"OK");
}

} // namespace nav_core
