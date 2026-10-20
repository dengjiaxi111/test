#include "nav_components/planner/normal_navigation_segment.hpp"

namespace nav_components {
using namespace nav_core;
HoleOptimizedConnection planNormalNavigationSegment(HolePoint start,HolePoint tangent,HolePoint goal,
        PathSmoother &smoother,const nav_msgs::msg::OccupancyGrid &map,double threshold,
        const HoleSegmentCheck &collision,const HoleHullCheck &hull,double sample_resolution,
        int expansion_budget,std::chrono::steady_clock::time_point deadline,
        const NormalSegmentSeedSearch &search,std::optional<double> maximum_curvature) {
    HoleOptimizedConnection result;result.check=holeCheck(false,"NORMAL_SEGMENT_FAILED",start);
    const auto begin=std::chrono::steady_clock::now();
    const auto done=[&]() {result.elapsed_ms=std::chrono::duration<double,std::milli>(
        std::chrono::steady_clock::now()-begin).count();return result;};
    if(holeNorm(goal-start)<1e-9) {
        result.check=collision(start,start);result.points=result.seed={start};return done();
    }
    if(!holeFinite(tangent)||holeNorm(tangent)<1e-12) {result.check=holeCheck(false,"INVALID_START_TANGENT",start);return done();}
    tangent=tangent*(1/holeNorm(tangent));
    const auto grid_search=[&](HolePoint a,HolePoint b,std::vector<HolePoint> &points) {
        const auto t=std::chrono::steady_clock::now();int expanded=0;
        bool ok=search?search(a,b,points,expanded):searchHoleGridConnection(a,b,map,collision,
            expansion_budget,deadline,points,expanded);
        result.expansions+=expanded;
        result.seed_search_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-t).count();
        if(ok&&!points.empty()){points.front()=a;points.back()=b;}
        return ok;
    };
    // 最多三个普通搜索种子。后两个仅在主拟合失败时提供转向/绕行选择。
    // 辅助点只属于种子，曲线无强制经过它们的约束。
    for(int variant=0;variant<3;++variant) {
        if(std::chrono::steady_clock::now()>=deadline){result.check=holeCheck(false,"NORMAL_SEGMENT_TIMEOUT",start);break;}
        std::vector<HolePoint> seed;
        if(variant==0) {
            if(collision(start,goal).valid)seed={start,goal};
            else if(!grid_search(start,goal,seed))continue;
        } else {
            const HolePoint side{-tangent.y,tangent.x};
            const double scale=std::min(smoother.getParams().resample_interval,holeNorm(goal-start)*.5);
            const auto bend=start+tangent*scale+side*(variant==1?scale:-scale);
            std::vector<HolePoint> first,last;
            if(!grid_search(start,bend,first)||!grid_search(bend,goal,last))continue;
            seed=std::move(first);seed.insert(seed.end(),last.begin()+1,last.end());
        }
        bool valid=seed.size()>1;
        for(std::size_t i=1;valid&&i<seed.size();++i)valid=collision(seed[i-1],seed[i]).valid;
        if(!valid)continue;
        nav_msgs::msg::Path raw;raw.header.frame_id="map";
        for(auto p:seed){geometry_msgs::msg::PoseStamped pose;pose.header=raw.header;
            pose.pose.position.x=p.x;pose.pose.position.y=p.y;pose.pose.orientation.w=1;raw.poses.push_back(pose);}
        for(double support:{1.0,.35}) {
            if(std::chrono::steady_clock::now()>=deadline)break;
            std::vector<HoleBezierSpan> spans;
            const auto fit_begin=std::chrono::steady_clock::now();
            const bool fit=smoother.smoothBoundary(raw,Eigen::Vector2d(tangent.x,tangent.y),support,spans);
            result.curve_fit_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-fit_begin).count();
            ++result.fits;if(!fit)continue;
            std::vector<HolePoint> points;double curvature=0;
            const auto check_begin=std::chrono::steady_clock::now();
            auto check=validateHoleCurve(spans,hull,sample_resolution,maximum_curvature,deadline,points,curvature);
            result.curve_validation_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-check_begin).count();
            result.check=check;if(!check.valid)continue;
            // 用首跨度上的极近采样点准确表达起始切线，避免发布折线首弦产生假折角。
            // 这是已校验曲线的采样，不增加 T 后必须直行的几何范围。
            if(check.valid&&!spans.empty()&&points.size()>1) {
                const auto &c=spans.front().controls;const double t=1e-4,q=1-t;
                const auto near=c[0]*(q*q*q)+c[1]*(3*q*q*t)+c[2]*(3*q*t*t)+c[3]*(t*t*t);
                if(holeNorm(near-start)>1e-10&&holeNorm(near-start)<holeNorm(points[1]-start))points.insert(points.begin()+1,near);
            }
            if(points.size()<2||holeNorm(points.front()-start)>1e-7||holeNorm(points.back()-goal)>1e-7||
               !holeDirectionMatches(points[1]-points[0],tangent,3.0)) {
                result.check=holeCheck(false,"NORMAL_SEGMENT_BOUNDARY_MISMATCH",start);continue;
            }
            for(std::size_t i=1;check.valid&&i<points.size();++i) {
                if(std::chrono::steady_clock::now()>=deadline)check=holeCheck(false,"NORMAL_SEGMENT_TIMEOUT",points[i]);
                else check=collision(points[i-1],points[i]);
            }
            result.check=check;if(!check.valid)continue;
            result.spans=std::move(spans);result.points=std::move(points);result.seed=seed;
            result.length=HolePathPolyline(result.points).arc.back();result.seed_length=HolePathPolyline(seed).arc.back();
            result.maximum_curvature=curvature;result.check=holeCheck(true,"NORMAL_SEGMENT_VALID");return done();
        }
    }
    return done();
}
} // namespace nav_components
