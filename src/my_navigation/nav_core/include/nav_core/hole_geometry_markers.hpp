#pragma once
#include "nav_core/hole_geometry.hpp"
#include <visualization_msgs/msg/marker_array.hpp>

namespace nav_core {
inline visualization_msgs::msg::MarkerArray holeGeometryMarkers(
        const HoleGeometryPreview &preview, bool selected=true, bool departure_axis_reference=false) {
    using Marker=visualization_msgs::msg::Marker;
    visualization_msgs::msg::MarkerArray output;
    int id=0;
    const auto point=[](HolePoint p, double z=0.16) {
        geometry_msgs::msg::Point result; result.x=p.x; result.y=p.y; result.z=z; return result;
    };
    const auto base=[&](int type,const std::string &kind,bool preferred=true) {
        Marker m;
        m.header.frame_id="map"; m.ns="hole_preview/"+preview.id+"/"+kind;
        m.id=id++; m.type=type; m.action=Marker::ADD; m.pose.orientation.w=1;
        m.scale.x=m.scale.y=m.scale.z=1;
        m.color.r=0.2f; m.color.g=1; m.color.b=0.5f;
        m.color.a=selected?(preferred?1.0f:0.4f):0.5f;
        return m;
    };
    if(preview.polygon.size()==4&&std::all_of(preview.polygon.begin(),preview.polygon.end(),holeFinite)) {
        for(int i=0;i<4;++i) {
            auto m=base(Marker::LINE_STRIP,"edges"); m.scale.x=0.045;
            const bool long_edge=i%2==preview.long_edge_pair;
            m.color.r=long_edge?0.0f:1.0f; m.color.g=long_edge?0.9f:0.4f; m.color.b=long_edge?1.0f:0.1f;
            if(!preview.geometry_valid) {m.color.r=1;m.color.g=0;m.color.b=0;}
            m.points={point(preview.polygon[i]),point(preview.polygon[(i+1)%4])};
            output.markers.push_back(m);
        }
    }
    for(std::size_t i=0;i<preview.directions.size();++i) {
        const auto &d=preview.directions[i];
        auto fixed=base(Marker::LINE_STRIP,"fixed_straight",i==0);
        fixed.scale.x=i==0?0.035:0.018;
        fixed.points={point(d.S,0.18+i*0.02),point(d.T,0.18+i*0.02)};
        output.markers.push_back(fixed);
        auto centre=base(Marker::LINE_STRIP,"centerline",i==0);
        centre.scale.x=0.065; centre.color.r=1; centre.color.g=1; centre.color.b=0;
        centre.points={point(d.E,0.22+i*0.02),point(d.X,0.22+i*0.02)};
        output.markers.push_back(centre);
        auto arrow=base(Marker::ARROW,"direction",i==0);
        arrow.scale.x=0.04; arrow.scale.y=0.10; arrow.scale.z=0.12;
        arrow.points={point(d.E,0.27+i*0.08),point(d.X,0.27+i*0.08)};
        output.markers.push_back(arrow);
        auto corridor=base(Marker::LINE_STRIP,"geometric_corridor",i==0);
        corridor.scale.x=0.02; corridor.color.r=0.5; corridor.color.g=0.5; corridor.color.b=1;
        for (auto p : preview.polygon) corridor.points.push_back(point(p,0.14));
        if (!corridor.points.empty()) corridor.points.push_back(corridor.points.front());
        output.markers.push_back(corridor);
        const std::array<HolePoint,6> points={d.A,d.S,d.E,d.X,d.T,d.D};
        const std::array<std::string,6> names={"A","S","E","X","T","D"};
        const auto name=[&](std::size_t j){return j==5&&departure_axis_reference&&!preview.manual_range?std::string("D axis reference"):names[j];};
        for(std::size_t j=0;j<points.size();++j) {
            if(preview.manual_range && j==0)continue;
            bool duplicate=false;
            for(std::size_t k=preview.manual_range?1:0;k<j;++k) if(holeNorm(points[j]-points[k])<=1e-9) duplicate=true;
            if(duplicate) continue;
            std::string text=name(j);
            for(std::size_t k=j+1;k<points.size();++k) if(holeNorm(points[j]-points[k])<=1e-9) text+="="+name(k);
            auto sphere=base(Marker::SPHERE,"waypoints",i==0);
            sphere.pose.position=point(points[j],0.3+i*0.08);
            sphere.scale.x=sphere.scale.y=sphere.scale.z=0.09;
            output.markers.push_back(sphere);
            auto label=base(Marker::TEXT_VIEW_FACING,"waypoint_labels",i==0);
            label.pose.position=point(points[j],0.5+i*0.18); label.scale.z=0.14;
            label.text=text+" ["+std::to_string(d.entry_edge_id)+"->"+std::to_string(d.exit_edge_id)+"]";
            output.markers.push_back(label);
        }
    }
    if(!preview.polygon.empty()&&std::all_of(preview.polygon.begin(),preview.polygon.end(),holeFinite)) {
        HolePoint center;
        for(auto p:preview.polygon) center=center+p*(1.0/preview.polygon.size());
        auto label=base(Marker::TEXT_VIEW_FACING,"diagnostics"); label.scale.z=0.14;
        label.pose.position=point(center,0.85); label.color.r=1; label.color.g=preview.valid?1:0.2;
        label.text=preview.id+" "+preview.reason+"\nwidth="+std::to_string(preview.opening_width)+
            " depth="+std::to_string(preview.depth)+"\nangle="+std::to_string(preview.max_rectangle_error_deg)+
            " parallel="+std::to_string(preview.max_parallel_error_deg)+
            "\ngeometry/parameters/start="+std::to_string(preview.geometry_revision)+"/"+
            std::to_string(preview.parameter_revision)+"/"+std::to_string(preview.start_revision);
        if(!preview.has_start) label.text+="\nSelect debug start with Publish Point";
        if(!preview.warning.empty()) label.text+="\n"+preview.warning;
        output.markers.push_back(label);
    }
    return output;
}
} // namespace nav_core
