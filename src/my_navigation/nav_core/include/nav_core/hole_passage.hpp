#pragma once

#include "nav_core/hole_geometry.hpp"
#include <functional>
#include <cstdint>
#include <optional>
#include <stdexcept>

namespace nav_core {

enum class HolePassageMode { Free, Centerline };
inline HolePassageMode holePassageMode(const std::string &value) {
    if (value == "free") return HolePassageMode::Free;
    if (value == "centerline") return HolePassageMode::Centerline;
    throw std::invalid_argument("hole_planner.mode must be free or centerline");
}
struct HolePassageValidationParams {
    double waypoint_tolerance = 0.02;      // 约束点位置及直线偏差容差（米）
    double tangent_tolerance_deg = 3.0;    // 路径切线方向容差（度）
    double side_margin = 0.0;              // 路径参考点到洞口侧边的最小距离（米）
    bool require_external_tangents = true; // 连续策略检查 S 前/T 后切线；可行优先仅放宽这两处洞外侧
};
inline bool validHolePassageParams(const HolePassageValidationParams &p) {
    return std::isfinite(p.waypoint_tolerance) && p.waypoint_tolerance > 0 &&
        std::isfinite(p.tangent_tolerance_deg) && p.tangent_tolerance_deg >= 0 &&
        p.tangent_tolerance_deg < 45 && std::isfinite(p.side_margin) && p.side_margin >= 0;
}
struct HolePassageCheck {
    bool valid = false;
    std::string reason;
    HolePoint point;
};
using HoleSegmentCheck = std::function<HolePassageCheck(HolePoint, HolePoint)>;
inline HolePassageCheck holeCheck(bool valid, const std::string &reason, HolePoint point = {}) {
    return {valid, reason, point};
}

// 所有弧长都来自待验证的发布折线，重复点不改变弧长。
struct HolePathPolyline {
    std::vector<HolePoint> points;
    std::vector<double> arc;
    bool valid = false;
    explicit HolePathPolyline(const std::vector<HolePoint> &input) {
        for (auto p : input) {
            if (!holeFinite(p)) return;
            if (!points.empty() && holeNorm(p - points.back()) < 1e-12) continue;
            const double s = points.empty() ? 0.0 : arc.back() + holeNorm(p - points.back());
            if (!std::isfinite(s)) return;
            points.push_back(p); arc.push_back(s);
        }
        valid = points.size() >= 2;
    }
    HolePoint at(double s) const {
        if (s <= 0) return points.front();
        if (s >= arc.back()) return points.back();
        const auto i = static_cast<std::size_t>(std::upper_bound(arc.begin(), arc.end(), s) - arc.begin());
        return points[i-1] + (points[i] - points[i-1]) * ((s - arc[i-1]) / (arc[i] - arc[i-1]));
    }
    HolePoint tangent(double s, bool after) const {
        auto it = after ? std::upper_bound(arc.begin(), arc.end(), s + 1e-10)
                        : std::lower_bound(arc.begin(), arc.end(), s - 1e-10);
        const auto i = std::clamp<std::size_t>(it - arc.begin(), 1, points.size()-1);
        return (points[i] - points[i-1]) * (1 / (arc[i] - arc[i-1]));
    }
    std::vector<HolePoint> slice(double begin, double end) const {
        std::vector<HolePoint> result{at(begin)};
        for (std::size_t i=0; i<points.size(); ++i)
            if (arc[i] > begin + 1e-10 && arc[i] < end - 1e-10) result.push_back(points[i]);
        result.push_back(at(end));
        return result;
    }
};

inline double holeWinding(const std::vector<HolePoint> &polygon) {
    double area=0;
    for (std::size_t i=0; i<polygon.size(); ++i)
        area += holeCross(polygon[i]-polygon[0], polygon[(i+1)%polygon.size()]-polygon[0]);
    return area > 0 ? 1.0 : -1.0;
}
inline bool holeStrictlyInside(const std::vector<HolePoint> &p, HolePoint q) {
    const double sign=holeWinding(p);
    for (std::size_t i=0; i<p.size(); ++i)
        if (sign*holeCross(p[(i+1)%p.size()]-p[i], q-p[i]) <= 1e-10) return false;
    return true;
}
// 凸多边形精确线段裁剪；可识别两个采样点都在洞外的跨洞线段。
inline bool holeClip(const std::vector<HolePoint> &p, HolePoint a, HolePoint b,
                     double &lo, double &hi) {
    lo=0; hi=1;
    const double sign=holeWinding(p);
    for (std::size_t i=0; i<p.size(); ++i) {
        const auto edge=p[(i+1)%p.size()]-p[i];
        const double c=sign*holeCross(edge, a-p[i]);
        const double d=sign*holeCross(edge, b-a);
        if (std::abs(d) < 1e-14) { if (c < -1e-10) return false; }
        else if (d > 0) lo=std::max(lo, -c/d);
        else hi=std::min(hi, -c/d);
        if (lo > hi) return false;
    }
    return hi-lo > 1e-12 && holeStrictlyInside(p, a+(b-a)*((lo+hi)*0.5));
}
inline int holeBoundaryEdge(const std::vector<HolePoint> &p, HolePoint q) {
    int found=-1;
    for (int i=0; i<4; ++i) if (holeSegmentDistance(q,p[i],p[(i+1)%4]) <= 1e-8) {
        if (found >= 0) return -2; // 顶点同时属于两条边，不能作为合法进出点。
        found=i;
    }
    return found;
}
struct HolePathCrossing {
    double entry_arc=0, exit_arc=0;
    int entry_edge=-1, exit_edge=-1;
    bool partial=false;
};
inline std::vector<HolePathCrossing> holePathCrossings(
        const HoleGeometryPreview &geometry, const HolePathPolyline &path) {
    std::vector<HolePathCrossing> result;
    if (!path.valid || !geometry.geometry_valid) return result;
    for (std::size_t i=1; i<path.points.size(); ++i) {
        double lo,hi;
        if (!holeClip(geometry.polygon,path.points[i-1],path.points[i],lo,hi)) continue;
        const double length=path.arc[i]-path.arc[i-1];
        const double begin=path.arc[i-1]+lo*length, end=path.arc[i-1]+hi*length;
        if (!result.empty() && std::abs(result.back().exit_arc-begin) <= 1e-8)
            result.back().exit_arc=end;
        else result.push_back({begin,end,-1,-1,false});
    }
    for (auto &c : result) {
        c.entry_edge=holeBoundaryEdge(geometry.polygon,path.at(c.entry_arc));
        c.exit_edge=holeBoundaryEdge(geometry.polygon,path.at(c.exit_arc));
        c.partial=c.entry_edge == -1 || c.exit_edge == -1;
    }
    return result;
}
// A 是最终路径上的准备触发事件；不能把路径之前的 A 当作准备已经完成。
struct HolePreparationEvent {
    std::string hole_id,status,range_source;
    int entry_edge=-1,exit_edge=-1,passage_index=0;
    double entry_arc=0,preparation_arc=0,prepare_path_distance=0;
    HolePoint point;
    bool point_valid=false,preparation_required_at_start=false;
    std::string ready_required_at="E";
    std::uint64_t terrain_revision=0,configuration_revision=0,path_revision=0;
};
// D 的执行语义。弧长相对于当前最终路径；历史出口弧长可为负数。
struct HoleDepartureEvent {
    std::string hole_id,kind, status,planning_policy,range_source;
    int entry_edge=-1,exit_edge=-1;
    double exit_arc=0,departure_arc=0,departure_distance=0;
    HolePoint point;
    bool point_valid=false;
    std::uint64_t terrain_revision=0,configuration_revision=0,path_revision=0;
};
struct HolePassageCandidate {
    std::string hole_id;
    HolePassageMode mode=HolePassageMode::Free;
    int entry_edge=-1, exit_edge=-1;
    HolePoint S,E,X,T,u_in,u_out;
    std::vector<HolePoint> inside;
    double entry_arc=0, exit_arc=0;
    bool entry_complete=true,exit_complete=true;
    bool entry_straight_complete=true,exit_straight_complete=true;
    double entry_straight_remaining=0,exit_straight_remaining=0;
    HolePassageCheck check;
};
inline HolePassageCandidate centerlineHoleCandidate(const HoleGeometryPreview &g,
                                                   const HoleDirectionGeometry &d) {
    HolePassageCandidate c;
    c.hole_id=g.id; c.mode=HolePassageMode::Centerline;
    c.entry_edge=d.entry_edge_id; c.exit_edge=d.exit_edge_id;
    c.S=d.S; c.E=d.E; c.X=d.X; c.T=d.T; c.u_in=c.u_out=d.tangent;
    c.inside={d.E,d.X}; return c;
}
inline HolePassageCandidate freeHoleCandidate(const HoleGeometryPreview &g,
        const HoleTraversalDistances &configured, const HolePathPolyline &path,
        const HolePathCrossing &crossing) {
    const auto distances=configured.forEntry((crossing.entry_edge>=0?crossing.entry_edge:(crossing.exit_edge>=0?(crossing.exit_edge+2)%4:configured.range_edge)));
    HolePassageCandidate c;
    c.hole_id=g.id; c.entry_edge=crossing.entry_edge; c.exit_edge=crossing.exit_edge;
    c.entry_arc=crossing.entry_arc; c.exit_arc=crossing.exit_arc;
    c.E=path.at(c.entry_arc); c.X=path.at(c.exit_arc);
    c.u_in=path.tangent(c.entry_arc,true); c.u_out=path.tangent(c.exit_arc,false);
    c.S=c.E-c.u_in*distances.entry_straight_length;
    c.T=c.X+c.u_out*distances.exit_straight_length;
    c.inside=path.slice(c.entry_arc,c.exit_arc);
    return c;
}
inline bool holeDirectionMatches(HolePoint a, HolePoint b, double degrees) {
    const double na=holeNorm(a),nb=holeNorm(b);
    return na > 1e-12 && nb > 1e-12 &&
        holeDot(a,b)/(na*nb) >= std::cos(degrees*3.14159265358979323846/180.0)-1e-12;
}

// 独立候选校验，不依赖路径生成器，也不修改候选或静态/动态地图。
inline HolePassageCheck validateHoleCandidate(const HoleGeometryPreview &g,
        const HoleTraversalDistances &configured, const HolePassageValidationParams &params,
        const HolePassageCandidate &c, const HoleSegmentCheck &segment_check) {
    const auto distances=configured.forEntry(c.entry_edge);
    if (!validHolePassageParams(params) || !validHoleDistances(distances))
        return holeCheck(false,"INVALID_VALIDATION_PARAMETERS");
    if (!g.valid) return holeCheck(false,g.reason);
    for (auto p : {c.S,c.E,c.X,c.T,c.u_in,c.u_out})
        if (!holeFinite(p)) return holeCheck(false,"NONFINITE_CANDIDATE");
    if(c.entry_edge < 0 || c.exit_edge < 0)
        return holeCheck(false,"INVALID_ENTRY_EXIT_OR_CORNER",c.E);
    const auto dir=std::find_if(g.directions.begin(),g.directions.end(),[&](const auto &d) {
        return c.entry_edge==d.entry_edge_id && c.exit_edge==d.exit_edge_id;
    });
    if (dir==g.directions.end()) return holeCheck(false,"INVALID_PASSAGE_EDGES_OR_DIRECTION",c.E);
    if (holeBoundaryEdge(g.polygon,c.E)!=c.entry_edge || holeBoundaryEdge(g.polygon,c.X)!=c.exit_edge)
        return holeCheck(false,"INVALID_ENTRY_EXIT_OR_CORNER",c.E);
    if (std::abs(holeNorm(c.u_in)-1)>1e-8 || std::abs(holeNorm(c.u_out)-1)>1e-8)
        return holeCheck(false,"INVALID_PASSAGE_DIRECTION",c.E);
    const auto inward=[&](int edge, HolePoint u) {
        const auto e=g.polygon[(edge+1)%4]-g.polygon[edge];
        return holeWinding(g.polygon)*holeCross(e,u)/holeNorm(e);
    };
    if (inward(c.entry_edge,c.u_in)<=1e-8 || inward(c.exit_edge,c.u_out)>=-1e-8)
        return holeCheck(false,"INVALID_PASSAGE_DIRECTION",c.E);
    // 长度以等式构造，位置容差不能授权缩短配置长度。
    if (holeNorm(c.S-(c.E-c.u_in*distances.entry_straight_length))>1e-8 ||
        holeNorm(c.T-(c.X+c.u_out*distances.exit_straight_length))>1e-8)
        return holeCheck(false,"STRAIGHT_LENGTH_MISMATCH",c.S);
    if (c.mode==HolePassageMode::Centerline &&
        (holeNorm(c.E-dir->E)>params.waypoint_tolerance || holeNorm(c.X-dir->X)>params.waypoint_tolerance ||
         !holeDirectionMatches(c.u_in,dir->tangent,1e-5) ||
         !holeDirectionMatches(c.u_out,dir->tangent,1e-5)))
        return holeCheck(false,"CENTERLINE_MISMATCH",c.E);
    if (c.inside.size()<2 || holeNorm(c.inside.front()-c.E)>1e-8 || holeNorm(c.inside.back()-c.X)>1e-8)
        return holeCheck(false,"INVALID_INSIDE_SEGMENT",c.E);
    const HolePathPolyline inside(c.inside);
    if(!inside.valid || !holeDirectionMatches(inside.tangent(0,true),c.u_in,params.tangent_tolerance_deg) ||
       !holeDirectionMatches(inside.tangent(inside.arc.back(),false),c.u_out,params.tangent_tolerance_deg))
        return holeCheck(false,"INSIDE_CONNECTION_TANGENT_MISMATCH",c.E);
    for (auto p:c.inside) {
        if (!holeFinite(p) || !holeContains(g.polygon,p)) return holeCheck(false,"SIDE_CROSSING",p);
        for (int edge : {(c.entry_edge+1)%4,(c.entry_edge+3)%4}) {
            const auto a=g.polygon[edge],b=g.polygon[(edge+1)%4];
            const double distance=std::abs(holeCross(b-a,p-a))/holeNorm(b-a);
            if (distance <= 1e-9 || distance+1e-9 < params.side_margin)
                return holeCheck(false,"SIDE_MARGIN_VIOLATION",p);
        }
        if (c.mode==HolePassageMode::Centerline &&
            std::abs(holeCross(dir->tangent,p-c.E))>params.waypoint_tolerance)
            return holeCheck(false,"CENTERLINE_MISMATCH",p);
    }
    if (!segment_check) return holeCheck(false,"MAP_UNAVAILABLE");
    for (auto segment : {std::pair<HolePoint,HolePoint>{c.S,c.E},{c.X,c.T}}) {
        const auto check=segment_check(segment.first,segment.second);
        if (!check.valid) return holeCheck(false,"STRAIGHT_SEGMENT_BLOCKED: "+check.reason,check.point);
    }
    for (std::size_t i=1;i<c.inside.size();++i) {
        if (c.mode==HolePassageMode::Centerline && holeDot(c.inside[i]-c.inside[i-1],c.u_in)<-1e-10)
            return holeCheck(false,"NONMONOTONIC_CENTERLINE",c.inside[i]);
        const auto check=segment_check(c.inside[i-1],c.inside[i]);
        if (!check.valid) return holeCheck(false,"PASSAGE_BLOCKED: "+check.reason,check.point);
    }
    return holeCheck(true,"CANDIDATE_VALID");
}

// 特殊起终点仅裁掉路径端点之前/之后的阶段，剩余路径仍须满足原直线和切线。
inline HolePassageCheck validateHoleRemainingPassage(const HoleGeometryPreview &g,
        const HoleTraversalDistances &configured,const HolePassageValidationParams &params,
        const HolePathPolyline &path,const HolePathCrossing &crossing,HolePassageMode mode,
        const HoleSegmentCheck &segment_check,HolePassageCandidate *candidate) {
    auto distances=configured.forEntry((crossing.entry_edge>=0?crossing.entry_edge:(crossing.exit_edge>=0?(crossing.exit_edge+2)%4:configured.range_edge)));
    auto c=freeHoleCandidate(g,distances,path,crossing);c.mode=mode;
    c.entry_complete=crossing.entry_edge>=0;c.exit_complete=crossing.exit_edge>=0;
    const auto finish=[&](HolePassageCheck check){c.check=check;if(candidate)*candidate=c;return check;};
    if(!g.valid||!validHolePassageParams(params)||!validHoleDistances(distances))
        return finish(holeCheck(false,g.valid?"INVALID_VALIDATION_PARAMETERS":g.reason));
    const auto direction=std::find_if(g.directions.begin(),g.directions.end(),[&](const auto &d) {
        return (!c.entry_complete||c.entry_edge==d.entry_edge_id)&&(!c.exit_complete||c.exit_edge==d.exit_edge_id)&&
            (holeDot(c.X-c.E,d.tangent)>1e-10||
             (mode==HolePassageMode::Free&&!c.entry_complete&&!c.exit_complete&&holeDot(c.X-c.E,d.tangent)>=-1e-10));
    });
    if(direction==g.directions.end()) return finish(holeCheck(false,"INVALID_PASSAGE_EDGES_OR_DIRECTION",c.E));
    if(!c.entry_complete&&(crossing.entry_arc>1e-8||!holeStrictlyInside(g.polygon,path.points.front())))
        return finish(holeCheck(false,"INVALID_PARTIAL_ENTRY",c.E));
    if(!c.exit_complete&&(crossing.exit_arc<path.arc.back()-1e-8||!holeStrictlyInside(g.polygon,path.points.back())))
        return finish(holeCheck(false,"INVALID_PARTIAL_EXIT",c.X));
    c.entry_edge=direction->entry_edge_id;c.exit_edge=direction->exit_edge_id;
    distances=configured.forEntry(c.entry_edge);
    if(mode==HolePassageMode::Centerline) {
        c.u_in=c.u_out=direction->tangent;
        for(auto p:c.inside) if(std::abs(holeCross(direction->tangent,p-direction->E))>params.waypoint_tolerance)
            return finish(holeCheck(false,"CENTERLINE_MISMATCH",p));
        if((c.entry_complete&&holeNorm(c.E-direction->E)>params.waypoint_tolerance)||
           (c.exit_complete&&holeNorm(c.X-direction->X)>params.waypoint_tolerance))
            return finish(holeCheck(false,"CENTERLINE_MISMATCH",c.E));
    }
    if(c.entry_complete&&holeBoundaryEdge(g.polygon,c.E)!=c.entry_edge)
        return finish(holeCheck(false,"INVALID_ENTRY_EXIT_OR_CORNER",c.E));
    if(c.exit_complete&&holeBoundaryEdge(g.polygon,c.X)!=c.exit_edge)
        return finish(holeCheck(false,"INVALID_ENTRY_EXIT_OR_CORNER",c.X));
    const auto inward=[&](int edge,HolePoint u){const auto e=g.polygon[(edge+1)%4]-g.polygon[edge];
        return holeWinding(g.polygon)*holeCross(e,u)/holeNorm(e);};
    if((c.entry_complete&&inward(c.entry_edge,c.u_in)<=1e-8)||
       (c.exit_complete&&inward(c.exit_edge,c.u_out)>=-1e-8))
        return finish(holeCheck(false,"INVALID_PASSAGE_DIRECTION",c.E));
    if(!segment_check) return finish(holeCheck(false,"MAP_UNAVAILABLE"));
    for(auto p:c.inside) {
        if(!holeContains(g.polygon,p)) return finish(holeCheck(false,"SIDE_CROSSING",p));
        for(int edge:{(c.entry_edge+1)%4,(c.entry_edge+3)%4}) {
            const auto a=g.polygon[edge],b=g.polygon[(edge+1)%4];
            const double d=std::abs(holeCross(b-a,p-a))/holeNorm(b-a);
            if(d<=1e-9||d+1e-9<params.side_margin) return finish(holeCheck(false,"SIDE_MARGIN_VIOLATION",p));
        }
    }
    for(std::size_t i=1;i<c.inside.size();++i) {
        if(mode==HolePassageMode::Centerline&&holeDot(c.inside[i]-c.inside[i-1],c.u_in)<-1e-10)
            return finish(holeCheck(false,"NONMONOTONIC_CENTERLINE",c.inside[i]));
        const auto check=segment_check(c.inside[i-1],c.inside[i]);if(!check.valid)return finish(check);
    }
    const double s=c.entry_complete?std::max(0.0,c.entry_arc-distances.entry_straight_length):c.entry_arc;
    const double t=c.exit_complete?std::min(path.arc.back(),c.exit_arc+distances.exit_straight_length):c.exit_arc;
    c.entry_straight_remaining=c.entry_arc-s;c.exit_straight_remaining=t-c.exit_arc;
    c.entry_straight_complete=c.entry_complete&&c.entry_straight_remaining+1e-9>=distances.entry_straight_length;
    c.exit_straight_complete=c.exit_complete&&c.exit_straight_remaining+1e-9>=distances.exit_straight_length;
    c.S=path.at(s);c.T=path.at(t);
    const auto straight=[&](double a,double b,HolePoint origin,HolePoint u) {
        for(auto p:path.slice(a,b)) if(std::abs(holeCross(u,p-origin))>params.waypoint_tolerance)
            return holeCheck(false,"STRAIGHT_PATH_MISMATCH",p);
        const auto samples=path.slice(a,b);
        for(std::size_t i=1;i<samples.size();++i) if(holeNorm(samples[i]-samples[i-1])>1e-10&&
            !holeDirectionMatches(samples[i]-samples[i-1],u,params.tangent_tolerance_deg))
            return holeCheck(false,"STRAIGHT_TANGENT_MISMATCH",samples[i]);
        return holeCheck(true,"OK");
    };
    auto check=mode==HolePassageMode::Centerline?straight(s,t,c.E,c.u_in):straight(s,c.entry_arc,c.E,c.u_in);
    if(!check.valid)return finish(check);
    if(mode==HolePassageMode::Free){check=straight(c.exit_arc,t,c.X,c.u_out);if(!check.valid)return finish(check);}
    for(auto seam:{std::pair<double,HolePoint>{s,c.u_in},{c.entry_arc,c.u_in},{c.exit_arc,c.u_out},{t,c.u_out}}) {
        if(seam.first>1e-9&&(params.require_external_tangents||std::abs(seam.first-s)>1e-9)&&
           !holeDirectionMatches(path.tangent(seam.first,false),seam.second,params.tangent_tolerance_deg))
            return finish(holeCheck(false,"CONNECTION_TANGENT_MISMATCH",path.at(seam.first)));
        if(seam.first<path.arc.back()-1e-9&&(params.require_external_tangents||std::abs(seam.first-t)>1e-9)&&
           !holeDirectionMatches(path.tangent(seam.first,true),seam.second,params.tangent_tolerance_deg))
            return finish(holeCheck(false,"CONNECTION_TANGENT_MISMATCH",path.at(seam.first)));
    }
    return finish(holeCheck(true,"PATH_REMAINING_PASSAGE_VALID"));
}

inline HolePassageCheck validateHolePathPassage(const HoleGeometryPreview &g,
        const HoleTraversalDistances &configured, const HolePassageValidationParams &params,
        const HolePathPolyline &path, const HolePathCrossing &crossing,
        HolePassageMode mode, const HoleSegmentCheck &segment_check,
        HolePassageCandidate *candidate=nullptr,bool allow_remaining=false) {
    const auto distances=configured.forEntry((crossing.entry_edge>=0?crossing.entry_edge:(crossing.exit_edge>=0?(crossing.exit_edge+2)%4:configured.range_edge)));
    if(allow_remaining&&(crossing.partial||crossing.entry_arc<distances.entry_straight_length-1e-9||
        crossing.exit_arc+distances.exit_straight_length>path.arc.back()+1e-9))
        return validateHoleRemainingPassage(g,distances,params,path,crossing,mode,segment_check,candidate);
    auto c=freeHoleCandidate(g,distances,path,crossing); c.mode=mode;
    c.entry_straight_remaining=distances.entry_straight_length;c.exit_straight_remaining=distances.exit_straight_length;
    const auto finish=[&](HolePassageCheck check) { c.check=check; if(candidate) *candidate=c; return check; };
    if (crossing.partial) return finish(holeCheck(false,"PARTIAL_PASSAGE_REQUIRES_LATER_STAGE",c.E));
    if (mode==HolePassageMode::Centerline) {
        const auto dir=std::find_if(g.directions.begin(),g.directions.end(),[&](const auto &d) {
            return d.entry_edge_id==c.entry_edge && d.exit_edge_id==c.exit_edge;
        });
        if (dir!=g.directions.end()) {
            if (holeNorm(c.E-dir->E)>params.waypoint_tolerance || holeNorm(c.X-dir->X)>params.waypoint_tolerance)
                return finish(holeCheck(false,"CENTERLINE_MISMATCH",c.E));
            c.u_in=c.u_out=dir->tangent;
            c.S=c.E-c.u_in*distances.entry_straight_length;
            c.T=c.X+c.u_out*distances.exit_straight_length;
        }
    }
    const auto check=validateHoleCandidate(g,distances,params,c,segment_check);
    if (!check.valid) return finish(check);
    const double s=c.entry_arc-distances.entry_straight_length, t=c.exit_arc+distances.exit_straight_length;
    if (s < -1e-9 || t > path.arc.back()+1e-9)
        return finish(holeCheck(false,"INSUFFICIENT_STRAIGHT_LENGTH",s<0?c.S:c.T));
    const auto straight=[&](double begin,double end,HolePoint a,HolePoint u) {
        const auto points=path.slice(begin,end);
        if (holeNorm(path.at(begin)-a)>params.waypoint_tolerance)
            return holeCheck(false,"STRAIGHT_PATH_MISMATCH",path.at(begin));
        for (auto p:points) if (std::abs(holeCross(u,p-a))>params.waypoint_tolerance)
            return holeCheck(false,"STRAIGHT_PATH_MISMATCH",p);
        for (std::size_t i=1;i<points.size();++i)
            if (holeNorm(points[i]-points[i-1])>1e-10 &&
                !holeDirectionMatches(points[i]-points[i-1],u,params.tangent_tolerance_deg))
                return holeCheck(false,"STRAIGHT_TANGENT_MISMATCH",points[i]);
        return holeCheck(true,"OK");
    };
    auto line=mode==HolePassageMode::Centerline ? straight(s,t,c.S,c.u_in)
                                              : straight(s,c.entry_arc,c.S,c.u_in);
    if (!line.valid) return finish(line);
    if (mode==HolePassageMode::Free) {
        line=straight(c.exit_arc,t,c.X,c.u_out); if(!line.valid) return finish(line);
    }
    for (auto seam : {std::pair<double,HolePoint>{s,c.u_in},{c.entry_arc,c.u_in},
                      {c.exit_arc,c.u_out},{t,c.u_out}}) {
        if (seam.first>1e-9 && (params.require_external_tangents||std::abs(seam.first-s)>1e-9) &&
            !holeDirectionMatches(path.tangent(seam.first,false),seam.second,params.tangent_tolerance_deg))
            return finish(holeCheck(false,"CONNECTION_TANGENT_MISMATCH",path.at(seam.first)));
        if (seam.first<path.arc.back()-1e-9 && (params.require_external_tangents||std::abs(seam.first-t)>1e-9) &&
            !holeDirectionMatches(path.tangent(seam.first,true),seam.second,params.tangent_tolerance_deg))
            return finish(holeCheck(false,"CONNECTION_TANGENT_MISMATCH",path.at(seam.first)));
    }
    return finish(holeCheck(true,"PATH_PASSAGE_VALID"));
}
} // namespace nav_core
