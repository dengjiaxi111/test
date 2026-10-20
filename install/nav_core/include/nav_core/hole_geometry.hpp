#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace nav_core {

// Pure metre-based geometry. No ROS, YAML, map, or robot footprint dependency.
struct HolePoint { double x = 0.0, y = 0.0; };
inline HolePoint operator+(HolePoint a, HolePoint b) { return {a.x+b.x,a.y+b.y}; }
inline HolePoint operator-(HolePoint a, HolePoint b) { return {a.x-b.x,a.y-b.y}; }
inline HolePoint operator*(HolePoint a, double s) { return {a.x*s,a.y*s}; }
inline double holeDot(HolePoint a, HolePoint b) { return a.x*b.x+a.y*b.y; }
inline double holeCross(HolePoint a, HolePoint b) { return a.x*b.y-a.y*b.x; }
inline double holeNorm(HolePoint a) { return std::hypot(a.x,a.y); }
inline bool holeFinite(HolePoint a) { return std::isfinite(a.x)&&std::isfinite(a.y); }

struct HoleTraversalDistances {
    double prepare_distance = 1.5;
    double entry_straight_length = 0.8;
    double exit_straight_length = 0.5;
    double departure_distance = 0.8;
    // 地图物理边绑定的固定范围；长度单位米，-1 表示沿用角色距离。
    bool manual_range = false; // 独立人工范围：A 为路径事件，D 与 T 重合。
    double prepare_path_distance = 1.5; // A 到 E 沿最终路径的提前距离（米）。
    int range_edge = -1;
    std::array<double,2> range_extensions{};
    bool range_bidirectional = true;
    std::string range_source = "role_distances";
    HoleTraversalDistances forEntry(int edge) const {
        auto d=*this;
        if(range_edge>=0 && edge>=0) {
            const int side=edge==range_edge?0:1;
            d.entry_straight_length=range_extensions[side];
            d.exit_straight_length=range_extensions[1-side];
            if(manual_range) {d.prepare_distance=d.entry_straight_length;d.departure_distance=d.exit_straight_length;}
        }
        return d;
    }
};
struct HoleGeometryParams {
    double rectangle_angle_tolerance_deg = 3.0;
    double parallel_tolerance_deg = 3.0;
    double min_long_short_ratio = 1.2;
    double max_centerline_difference = 0.02;
    double max_axis_difference_deg = 3.0;
    double entry_tie_distance = 0.001;
};
struct HoleGeometryInput {
    std::string id;
    std::string frame_id = "map";
    std::vector<HolePoint> polygon;
    int passable_edge_pair = -1;
    bool enabled = true;
    bool bidirectional = true;
};
struct HoleDirectionGeometry {
    int entry_edge_id = -1, exit_edge_id = -1;
    HolePoint A, S, E, X, T, D, tangent, lateral;
    double length = 0.0;
    double min_left_width = 0.0, min_right_width = 0.0;
    double start_distance = 0.0;
    bool start_in_entry_half_plane = false;
};
struct HoleGeometryPreview {
    std::string id, reason, warning;
    bool manual_range=false;
    bool geometry_valid = false, valid = false, near_square = false;
    bool has_start = false, start_inside = false;
    int long_edge_pair = -1;
    double area = 0.0, opening_width = 0.0, depth = 0.0;
    double max_rectangle_error_deg = 0.0, max_parallel_error_deg = 0.0;
    double centerline_difference = 0.0, axis_difference_deg = 0.0;
    std::array<double,4> edge_lengths{};
    std::vector<HolePoint> polygon;
    std::vector<HoleDirectionGeometry> directions; // Preferred candidate first.
    std::uint64_t geometry_revision = 0, parameter_revision = 0, start_revision = 0;
};

inline bool validHoleDistances(const HoleTraversalDistances &d) {
    return std::isfinite(d.prepare_distance)&&std::isfinite(d.entry_straight_length)&&
        std::isfinite(d.exit_straight_length)&&std::isfinite(d.departure_distance)&&
        d.entry_straight_length>=0&&d.exit_straight_length>=0&&
        d.prepare_distance>=d.entry_straight_length&&d.departure_distance>=d.exit_straight_length;
}
inline bool validHoleGeometryParams(const HoleGeometryParams &p) {
    return std::isfinite(p.rectangle_angle_tolerance_deg)&&p.rectangle_angle_tolerance_deg>=0&&p.rectangle_angle_tolerance_deg<45&&
        std::isfinite(p.parallel_tolerance_deg)&&p.parallel_tolerance_deg>=0&&p.parallel_tolerance_deg<45&&
        std::isfinite(p.min_long_short_ratio)&&p.min_long_short_ratio>=1&&
        std::isfinite(p.max_centerline_difference)&&p.max_centerline_difference>=0&&
        std::isfinite(p.max_axis_difference_deg)&&p.max_axis_difference_deg>=0&&p.max_axis_difference_deg<45&&
        std::isfinite(p.entry_tie_distance)&&p.entry_tie_distance>=0;
}
inline double holeSegmentDistance(HolePoint p, HolePoint a, HolePoint b) {
    const auto v=b-a;
    if(holeDot(v,v)<=1e-20)return holeNorm(p-a);
    const double u=std::clamp(holeDot(p-a,v)/holeDot(v,v),0.0,1.0);
    return holeNorm(p-(a+v*u));
}
inline bool holeContains(const std::vector<HolePoint> &p, HolePoint q) {
    bool positive=false,negative=false;
    for(std::size_t i=0;i<p.size();++i) {
        const double c=holeCross(p[(i+1)%p.size()]-p[i],q-p[i]);
        positive|=c>1e-9; negative|=c< -1e-9;
    }
    return !(positive&&negative);
}

inline HoleGeometryPreview buildHoleGeometry(const HoleGeometryInput &input,
        const HoleGeometryParams &params = {}, const HoleTraversalDistances &distances = {},
        const HolePoint *start = nullptr) {
    constexpr double degrees=180.0/3.14159265358979323846;
    HoleGeometryPreview result;result.manual_range=distances.manual_range;
    result.id=input.id;
    const auto fail=[&](const std::string &why) { result.reason=why; result.directions.clear(); return result; };
    if(!validHoleGeometryParams(params)) return fail("INVALID_GEOMETRY_PARAMETERS");
    if(input.frame_id!="map") return fail("FRAME_MISMATCH: expected map coordinates");
    result.polygon=input.polygon;
    if(result.polygon.size()>4&&holeFinite(result.polygon.front())&&holeFinite(result.polygon.back())&&
        holeNorm(result.polygon.front()-result.polygon.back())<=1e-9) result.polygon.pop_back();
    if(result.polygon.size()!=4) return fail("INVALID_HOLE_GEOMETRY: expected four vertices");
    const auto &p=result.polygon;
    for(int i=0;i<4;++i) {
        if(!holeFinite(p[i])) return fail("INVALID_HOLE_GEOMETRY: non-finite vertex");
        for(int j=0;j<i;++j) if(holeNorm(p[i]-p[j])<=1e-9)
            return fail("INVALID_HOLE_GEOMETRY: duplicate vertices");
    }
    double signed_area=0;
    bool positive=false,negative=false;
    for(int i=0;i<4;++i) {
        const auto u=p[(i+1)%4]-p[i],v=p[(i+2)%4]-p[(i+1)%4];
        const double length=holeNorm(u),next=holeNorm(v);
        result.edge_lengths[i]=length;
        if(!std::isfinite(length)||!std::isfinite(next)||length<=0.01||next<=0.01)
            return fail("INVALID_HOLE_GEOMETRY: degenerate edge");
        const auto un=u*(1/length),vn=v*(1/next);
        const double turn=holeCross(un,vn);
        positive|=turn>1e-12; negative|=turn< -1e-12;
        if(std::abs(turn)<=1e-12) return fail("INVALID_HOLE_GEOMETRY: collinear vertices");
        result.max_rectangle_error_deg=std::max(result.max_rectangle_error_deg,
            std::abs(90.0-std::atan2(std::abs(turn),holeDot(un,vn))*degrees));
        signed_area+=holeCross(p[i]-p[0],p[(i+1)%4]-p[0]);
    }
    result.area=std::abs(signed_area)*0.5;
    if(positive==negative) return fail("INVALID_HOLE_GEOMETRY: nonconvex or self-intersecting boundary");
    if(!std::isfinite(result.area)||result.area<=1e-6) return fail("INVALID_HOLE_GEOMETRY: degenerate area");
    for(int i=0;i<2;++i) {
        const auto a=(p[i+1]-p[i])*(1/result.edge_lengths[i]);
        const auto b=(p[(i+3)%4]-p[i+2])*(1/result.edge_lengths[i+2]);
        result.max_parallel_error_deg=std::max(result.max_parallel_error_deg,
            std::acos(std::clamp(std::abs(holeDot(a,b)),0.0,1.0))*degrees);
    }
    const double pair0=(result.edge_lengths[0]+result.edge_lengths[2])*0.5;
    const double pair1=(result.edge_lengths[1]+result.edge_lengths[3])*0.5;
    result.long_edge_pair=pair0>=pair1?0:1;
    result.opening_width=std::max(pair0,pair1);
    result.depth=std::min(pair0,pair1);
    result.near_square=std::max(pair0,pair1)/std::min(pair0,pair1)<params.min_long_short_ratio;
    result.geometry_valid=result.max_rectangle_error_deg<=params.rectangle_angle_tolerance_deg+1e-9&&
        result.max_parallel_error_deg<=params.parallel_tolerance_deg+1e-9;
    if(!result.geometry_valid) return fail("INVALID_HOLE_GEOMETRY: rectangle/parallel tolerance exceeded");
    if(!input.enabled) return fail("HOLE_DISABLED");
    if(input.passable_edge_pair<0) return fail(result.near_square?"AMBIGUOUS_ENTRY_EDGES: select a pair manually":"UNCONFIRMED_PASSABLE_EDGES");
    if(input.passable_edge_pair>1) return fail("INVALID_PASSABLE_EDGES");
    const int pair=input.passable_edge_pair;
    const double opening=pair==0?pair0:pair1,side=pair==0?pair1:pair0;
    if(!result.near_square&&opening<side) return fail("INVALID_PASSABLE_EDGES: selected pair is shorter");
    result.opening_width=opening;
    if(result.near_square) result.warning="Near square: direction confirmed manually";
    if(!validHoleDistances(distances)) return fail("INVALID_DISTANCE_PARAMETERS: require prepare >= entry >= 0 and departure >= exit >= 0");
    if(distances.range_edge>=0) {
        if(distances.range_edge!=pair || !std::isfinite(distances.range_extensions[0]) ||
           !std::isfinite(distances.range_extensions[1]) || distances.range_extensions[0]<0 || distances.range_extensions[1]<0)
            return fail("INVALID_STRAIGHT_RANGE: edge binding or length");
        const auto a=(p[pair+1]-p[pair])*(1/result.edge_lengths[pair]);
        const auto b=(p[(pair+3)%4]-p[pair+2])*(1/result.edge_lengths[pair+2]);
        if(std::abs(holeCross(a,b))>1e-6)
            return fail("INVALID_RANGE_NORMAL: fixed bidirectional axis requires parallel passable edges; rectify rectangle");
    }
    for(int entry:{pair,pair+2}) {
        const auto directional=distances.forEntry(entry);
        if ((entry==pair || input.bidirectional) && !validHoleDistances(directional))
            return fail("INVALID_RANGE_DISTANCE_ORDER: A >= entry and D >= exit required");
        HoleDirectionGeometry d;
        d.entry_edge_id=entry; d.exit_edge_id=(entry+2)%4;
        const auto a=p[entry],b=p[(entry+1)%4],c=p[d.exit_edge_id],e=p[(d.exit_edge_id+1)%4];
        d.E=(a+b)*0.5;
        const auto v=e-c;
        const double projected=holeDot(d.E-c,v)/holeDot(v,v);
        if(projected< -1e-9||projected>1+1e-9) return fail("INVALID_CENTERLINE: foot is outside exit edge");
        d.X=c+v*std::clamp(projected,0.0,1.0);
        // 固定地图范围的双向预览共享同一条轴，不能各自投影得到不同直线。
        if(distances.range_edge>=0 && entry!=pair) {
            d.E=result.directions.front().X;
            d.X=result.directions.front().E;
        }
        d.length=holeNorm(d.X-d.E);
        if(!std::isfinite(d.length)||d.length<=0.01) return fail("INVALID_CENTERLINE: zero passage length");
        d.tangent=(d.X-d.E)*(1/d.length);
        d.lateral={-d.tangent.y,d.tangent.x};
        if(!holeContains(p,d.E)||!holeContains(p,d.X)||!holeContains(p,(d.E+d.X)*0.5))
            return fail("INVALID_CENTERLINE: line leaves the polygon");
        d.min_left_width=d.min_right_width=std::numeric_limits<double>::infinity();
        // Side intersections are affine along the straight axis. Their minima
        // occur at E or X; no sparse sampling assumption is needed.
        for(auto q:{d.E,d.X}) {
            double left=0,right=0;
            for(int edge:{(entry+1)%4,(entry+3)%4}) {
                const auto s0=p[edge],sv=p[(edge+1)%4]-s0;
                const double den=holeCross(d.lateral,sv);
                if(std::abs(den)<1e-12) return fail("INVALID_CENTERLINE: parallel side boundary");
                const double lateral=holeCross(s0-q,sv)/den;
                const double along=holeCross(s0-q,d.lateral)/den;
                if(along< -1e-8||along>1+1e-8) return fail("INVALID_CENTERLINE: side intersection outside boundary");
                if(lateral>0) left=lateral; else right=-lateral;
            }
            if(left<=1e-9||right<=1e-9) return fail("INVALID_CENTERLINE: no geometric side width");
            d.min_left_width=std::min(d.min_left_width,left);
            d.min_right_width=std::min(d.min_right_width,right);
        }
        d.A=d.E-d.tangent*directional.prepare_distance;
        d.S=d.E-d.tangent*directional.entry_straight_length;
        d.T=d.X+d.tangent*directional.exit_straight_length;
        d.D=d.X+d.tangent*directional.departure_distance;
        if(!holeFinite(d.A)||!holeFinite(d.S)||!holeFinite(d.T)||!holeFinite(d.D))
            return fail("INVALID_DISTANCE_PARAMETERS: waypoint overflow");
        if(start) {
            if(!holeFinite(*start)) return fail("INVALID_DEBUG_START");
            d.start_distance=holeSegmentDistance(*start,a,b);
            // Outward half-plane is defined by the entry edge, not the
            // slightly different normal of the opposite edge.
            const double start_cross=holeCross(b-a,*start-a);
            const double inside_cross=holeCross(b-a,(c+e)*0.5-a);
            d.start_in_entry_half_plane=start_cross*inside_cross<=1e-12;
        }
        result.directions.push_back(d);
    }
    const auto &forward=result.directions[0],&reverse=result.directions[1];
    result.centerline_difference=std::max(holeNorm(forward.E-reverse.X),holeNorm(forward.X-reverse.E));
    result.axis_difference_deg=std::acos(std::clamp(-holeDot(forward.tangent,reverse.tangent),-1.0,1.0))*degrees;
    if(result.centerline_difference>params.max_centerline_difference+1e-9||
        result.axis_difference_deg>params.max_axis_difference_deg+1e-9)
        return fail("INVALID_CENTERLINE: bidirectional axes disagree");
    result.depth=(forward.length+reverse.length)*0.5;
    result.has_start=start!=nullptr;
    result.start_inside=start&&holeContains(p,*start);
    if(!input.bidirectional) result.directions.resize(1);
    else if(start&&result.directions[1].start_distance+params.entry_tie_distance<result.directions[0].start_distance)
        std::swap(result.directions[0],result.directions[1]);
    if(result.start_inside) result.warning+=(result.warning.empty()?"":"; ")+std::string("Start inside hole: dedicated traversal planning required");
    result.valid=true;
    result.reason="OK";
    return result;
}
}  // namespace nav_core
