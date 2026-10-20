#include "nav_components/planner/hole_connection_optimizer.hpp"
#include <algorithm>
#include <cmath>

namespace nav_components {
namespace {
using namespace nav_core;
using Clock=std::chrono::steady_clock;
void append(std::vector<HolePoint> &points,HolePoint p) {
    if(points.empty()||holeNorm(points.back()-p)>1e-10)points.push_back(p);
}
void appendLine(std::vector<HolePoint> &points,HolePoint to,double resolution) {
    if(points.empty()){points.push_back(to);return;}
    const auto from=points.back();const int n=std::max(1,static_cast<int>(std::ceil(holeNorm(to-from)/resolution)));
    for(int i=1;i<=n;++i)append(points,i==n?to:from+(to-from)*(static_cast<double>(i)/n));
}
double length(const std::vector<HolePoint> &points) {
    double value=0;for(std::size_t i=1;i<points.size();++i)value+=holeNorm(points[i]-points[i-1]);return value;
}
}

HoleOptimizedConnection planFeasibleHoleApproach(HolePoint start,const std::vector<HolePoint> &targets,
        std::optional<HolePoint> initial,std::optional<HolePoint> final,
        const HoleConnectionOptimizationParams &params,const HoleConnectionSearchParams &search,
        const nav_msgs::msg::OccupancyGrid &map,const HoleSegmentCheck &collision,const HoleHullCheck &hull,
        const HoleDistanceQuery &distance,
        Clock::time_point deadline) {
    const auto begin=Clock::now();HoleOptimizedConnection result;
    result.check=holeCheck(false,"NO_FEASIBLE_APPROACH",start);
    const auto finish=[&]() {
        result.elapsed_ms=std::chrono::duration<double,std::milli>(Clock::now()-begin).count();return result;
    };
    if(!holeFinite(start)||targets.empty()||!collision||!hull||!validHoleOptimizationParams(params)||
       !validHoleConnectionSearchParams(search)||params.enforce_max_curvature||
       (initial&&(!holeFinite(*initial)||holeNorm(*initial)<1e-9))||
       (final&&(!holeFinite(*final)||holeNorm(*final)<1e-9))) {
        result.check=holeCheck(false,"INVALID_FEASIBLE_APPROACH_REQUEST",start);return finish();
    }
    deadline=std::min(deadline,begin+std::chrono::duration_cast<Clock::duration>(std::chrono::duration<double>(search.timeout)));
    // 分段保存必经点；只圆滑各段内部，不能用一条曲线跳过旧配置的 A/D。
    std::vector<std::vector<HolePoint>> legs;
    HolePoint previous=start;result.seed={start};
    for(auto target:targets) {
        if(!holeFinite(target)){result.check=holeCheck(false,"INVALID_CONNECTION_REQUEST",target);return finish();}
        auto check=collision(previous,previous);if(check.valid)check=collision(target,target);
        if(!check.valid){result.check=check;return finish();}
        if(Clock::now()>=deadline){result.check=holeCheck(false,"APPROACH_SEARCH_TIMEOUT",target);return finish();}
        if(holeNorm(target-previous)<1e-10){previous=target;continue;}
        std::vector<HolePoint> leg;const auto search_begin=Clock::now();
        const bool found=searchHoleGridConnection(previous,target,map,collision,search.max_expansions,deadline,leg,result.expansions);
        result.seed_search_ms+=std::chrono::duration<double,std::milli>(Clock::now()-search_begin).count();
        if(!found){result.check=holeCheck(false,Clock::now()>=deadline?"APPROACH_SEARCH_TIMEOUT":"NO_FEASIBLE_APPROACH",target);return finish();}
        for(std::size_t i=1;i<leg.size();++i) {
            if(Clock::now()>=deadline){result.check=holeCheck(false,"APPROACH_SEARCH_TIMEOUT",leg[i]);return finish();}
            check=collision(leg[i-1],leg[i]);if(!check.valid){result.check=check;return finish();}
            appendLine(result.seed,leg[i],search.sample_resolution);
        }
        legs.push_back(std::move(leg));previous=target;
    }
    result.seed_length=length(result.seed);result.points={start};
    if(params.enabled&&params.approach_smoothing_timeout>0&&!legs.empty()&&Clock::now()<deadline) {
        const auto now=Clock::now();
        // 为局部圆滑保留剩余时间的 20%；总预算耗尽也不能丢掉已经验证的折线。
        const auto smooth_deadline=std::min(now+(deadline-now)*4/5,now+
            std::chrono::duration_cast<Clock::duration>(std::chrono::duration<double>(params.approach_smoothing_timeout)));
        HoleOptimizedConnection smooth;
        if(!initial&&final) {
            // 与原首洞接入一致：从 S 反向拟合，固定 S 切向，静止起点可自由选择接入方向。
            std::vector<HolePoint> reversed(targets.rbegin()+1,targets.rend());reversed.push_back(start);
            smooth=optimizeHoleConnection(targets.back(),*final*-1,reversed,std::nullopt,params,search,
                map,collision,hull,distance,smooth_deadline);
            std::reverse(smooth.points.begin(),smooth.points.end());
            std::reverse(smooth.seed.begin(),smooth.seed.end());
            std::reverse(smooth.spans.begin(),smooth.spans.end());
            for(auto &span:smooth.spans)std::reverse(span.controls.begin(),span.controls.end());
        } else {
            const auto tangent=initial?*initial:legs.front()[1]-start;
            smooth=optimizeHoleConnection(start,tangent,targets,final,params,search,map,collision,hull,distance,smooth_deadline);
        }
        // 保留搜索/优化的实际统计；后备不携带失败曲线的控制点。
        result.expansions+=smooth.expansions;result.iterations+=smooth.iterations;result.fits+=smooth.fits;
        result.seed_search_ms+=smooth.seed_search_ms;result.curve_fit_ms+=smooth.curve_fit_ms;
        result.curve_validation_ms+=smooth.curve_validation_ms;
        if(smooth.check.valid) {
            result.points=std::move(smooth.points);result.spans=std::move(smooth.spans);
            result.length=smooth.length;result.cost=smooth.cost;result.maximum_curvature=smooth.maximum_curvature;
            result.check=holeCheck(true,"FEASIBLE_APPROACH_CONTINUOUS");return finish();
        }
        result.smoothing_failure=smooth.check.reason;
    }
    // 每处至多三次；曲线碰撞、尖点或超时均保留已验证折线。
    const auto curve=[&](const HoleBezierSpan &span,std::vector<HolePoint> &samples) {
        ++result.fits;const auto check_begin=Clock::now();double curvature=0;
        auto check=validateHoleCurve({span},hull,search.sample_resolution,std::nullopt,deadline,samples,curvature);
        if(check.valid)for(std::size_t i=1;i<samples.size();++i) {
            check=collision(samples[i-1],samples[i]);if(!check.valid)break;
        }
        result.curve_validation_ms+=std::chrono::duration<double,std::milli>(Clock::now()-check_begin).count();
        if(check.valid)result.maximum_curvature=std::max(result.maximum_curvature,curvature);
        return check.valid;
    };
    const auto appendCurve=[&](const std::vector<HolePoint> &samples) {
        appendLine(result.points,samples.front(),search.sample_resolution);
        for(auto p:samples)append(result.points,p);
    };
    for(std::size_t leg_id=0;leg_id<legs.size();++leg_id) {
        const auto &leg=legs[leg_id];
        if(params.enabled&&leg_id==0&&initial) {
            const auto v=(leg[1]-leg[0])*(1/holeNorm(leg[1]-leg[0]));const auto u=*initial*(1/holeNorm(*initial));
            if(!holeDirectionMatches(v,u,1e-3)) {
                bool rounded=false;
                for(double f:{.25,.125,.0625}) {
                    if(Clock::now()>=deadline)break;
                    const double h=std::min(holeNorm(leg[1]-leg[0]),params.control_spacing)*f;
                    const auto q=leg[0]+v*h;std::vector<HolePoint> samples;
                    if(curve(HoleBezierSpan{{leg[0],leg[0]+u*(h/3),q-v*(h/3),q}},samples)) {
                        appendCurve(samples);rounded=true;++result.rounded_corners;break;
                    }
                }
                if(!rounded)++result.retained_corners;
            }
        }
        for(std::size_t i=1;i+1<leg.size();++i) {
            const auto incoming=leg[i]-leg[i-1],outgoing=leg[i+1]-leg[i];
            if(holeDirectionMatches(incoming,outgoing,1e-3)){appendLine(result.points,leg[i],search.sample_resolution);continue;}
            bool rounded=false;
            if(params.enabled)for(double f:{.25,.125,.0625}) {
                if(Clock::now()>=deadline)break;
                const double trim=std::min(holeNorm(incoming),holeNorm(outgoing))*f;
                const auto a=leg[i]-incoming*(trim/holeNorm(incoming)),b=leg[i]+outgoing*(trim/holeNorm(outgoing));
                std::vector<HolePoint> samples;
                // 二次 Bezier 升阶为三次；两端切向与保留折线一致。
                if(curve(HoleBezierSpan{{a,a+(leg[i]-a)*(2.0/3),b+(leg[i]-b)*(2.0/3),b}},samples)) {
                    appendCurve(samples);rounded=true;++result.rounded_corners;break;
                }
            }
            if(!rounded){appendLine(result.points,leg[i],search.sample_resolution);++result.retained_corners;}
        }
        if(params.enabled&&leg_id+1==legs.size()&&final) {
            const auto end=leg.back(),v=(end-leg[leg.size()-2])*(1/holeNorm(end-leg[leg.size()-2]));
            const auto u=*final*(1/holeNorm(*final));
            if(!holeDirectionMatches(v,u,1e-3)) {
                bool rounded=false;
                for(double f:{.25,.125,.0625}) {
                    if(Clock::now()>=deadline)break;
                    const double h=std::min(holeNorm(end-leg[leg.size()-2]),params.control_spacing)*f;
                    const auto q=end-v*h;std::vector<HolePoint> samples;
                    if(curve(HoleBezierSpan{{q,q+v*(h/3),end-u*(h/3),end}},samples)) {
                        appendCurve(samples);rounded=true;++result.rounded_corners;break;
                    }
                }
                if(!rounded)++result.retained_corners;
            }
        }
        appendLine(result.points,leg.back(),search.sample_resolution);
    }
    // 此结果允许分段折角，不将局部曲线伪装成全程连续的 spans 缓存。
    result.length=result.cost=length(result.points);
    result.check=holeCheck(true,result.retained_corners?(result.rounded_corners?
        "FEASIBLE_APPROACH_PARTIAL_SMOOTHING":"FEASIBLE_APPROACH_POLYLINE"):
        "FEASIBLE_APPROACH_SMOOTHED");
    return finish();
}
} // namespace nav_components
