#include "nav_components/hole_plan_adapter.hpp"
namespace nav_components {
using namespace nav_core::hole_exec;
Plan makeHoleExecutionPlan(const HoleSelectedSnapshot& snap,const TerrainRegionMap::ConstPtr& terrain,
    const Config& config,const std::string& session,const std::string& goal,std::uint64_t id,
    const Plan* previous,double previous_progress,std::uint64_t& next_uid) {
    Plan plan;plan.session=session;plan.goal=goal;plan.id=id;plan.frame=snap.path.header.frame_id;
    plan.terrain_revision=snap.terrain_revision;plan.parameter_revision=snap.configuration_revision;
    plan.map_revision=snap.map_revision;
    for(const auto& p:snap.path.poses)plan.path.push_back({p.pose.position.x,p.pose.position.y});
    Polyline path(plan.path);std::set<std::string> used;
    const bool same=previous&&previous->session==session&&previous->goal==goal;
    for(std::size_t index=0;index<snap.passages.size();++index) {
        const auto& c=snap.passages[index];Passage p;
        p.hole_id=c.hole_id;p.entry_edge=c.entry_edge;p.exit_edge=c.exit_edge;
        p.centerline=c.mode==nav_core::HolePassageMode::Centerline;p.validated=c.check.valid;
        p.requirement_revision=snap.configuration_revision^(snap.terrain_revision<<32);
        p.retreat_anchor=c.S;p.retreat_anchor_valid=c.entry_straight_complete;p.entry_direction=c.u_in;
        if(terrain)for(const auto& region:terrain->getRegions())if(region.id==p.hole_id) {
            auto attr=region.attributes();if(attr["related_slope_id"])for(const auto& slope:terrain->getRegions())
                if(slope.id==attr["related_slope_id"].as<std::string>()) {
                    auto a=slope.attributes();if(a["uphill_yaw_deg"]) {double yaw=a["uphill_yaw_deg"].as<double>()*M_PI/180.;p.uphill_entry=holeDot(c.u_in,{std::cos(yaw),std::sin(yaw)})>0.5;}
                }
        }
        if(same)for(const auto& old:previous->passages)if(!used.count(old.uid)&&old.hole_id==p.hole_id&&
            old.entry_edge==p.entry_edge&&old.exit_edge==p.exit_edge) {
            // 有完整入口时用物理位置区分同一洞的不同穿越；剩余通行用方向及上下文匹配。
            const auto& e=event(old,EventType::E);
            if(c.entry_complete&&e.point_valid&&holeNorm(e.point-c.E)>0.05)continue;
            p.uid=old.uid;if(!p.retreat_anchor_valid&&old.retreat_anchor_valid){p.retreat_anchor=old.retreat_anchor;p.retreat_anchor_valid=true;}break;
        }
        if(p.uid.empty())p.uid=session+":"+goal+":"+std::to_string(++next_uid);
        used.insert(p.uid);
        auto prep=std::find_if(snap.preparation.begin(),snap.preparation.end(),[&](const auto& e){return
            e.hole_id==c.hole_id&&e.passage_index==static_cast<int>(index);});
        auto departure=std::find_if(snap.departure.begin(),snap.departure.end(),[&](const auto& e){return
            e.hole_id==c.hole_id&&e.entry_edge==c.entry_edge&&e.exit_edge==c.exit_edge;});
        bool a_unknown=false;
        double a=0,s=c.entry_arc-holeNorm(c.E-c.S),e=c.entry_arc,x=c.exit_arc,t=x+holeNorm(c.T-c.X),d=t;
        if(prep!=snap.preparation.end())a=prep->preparation_arc;
        else {
            // 旧配置必须使用真正选择的 A；没有选择元数据时拒绝，不能拿 YAML 默认冒充。
            if(!c.entry_complete)a_unknown=true;
            else {
                auto chosen=std::find_if(snap.selected.begin(),snap.selected.end(),[&](const auto& v){return
                    v.passage.hole_id==c.hole_id&&v.passage.entry_edge==c.entry_edge&&v.passage.exit_edge==c.exit_edge&&v.check.valid;});
                if(chosen==snap.selected.end())throw std::runtime_error("legacy A selected metadata unavailable: "+c.hole_id);
                if(p.centerline) {
                    const auto q=path.project(chosen->A,std::max(0.0,e-chosen->prepare_distance-0.1),e);
                    if(q.lateral<=0.03)a=q.arc;
                    else if(q.arc<=epsilon)a_unknown=true; // 当前路径没有实际A，不把起点伪装成A。
                    else throw std::runtime_error("selected legacy A not on final path");
                }else a=e-chosen->prepare_distance;
            }
        }
        if(departure!=snap.departure.end()) {
            d=departure->departure_arc;
            if(departure->planning_policy=="manual_range_end")t=d;
            if(departure->status=="axis_waypoint_absent")throw std::runtime_error("legacy D is absent from accepted route");
        }
        const std::array<double,6> values{a,s,e,x,t,d};
        for(std::size_t j=0;j<6;++j)p.events[j]=makeEvent(static_cast<EventType>(j),values[j],path);
        if(a_unknown){p.events[0].range=Range::UNKNOWN;p.events[0].point_valid=false;}
        if(!c.entry_complete) {
            // 候选 E 是被截断的当前片段起点，不能发布假的进入事件。
            p.events[2].range=Range::UNKNOWN;p.events[2].point_valid=false;
            p.events[0].range=Range::UNKNOWN;p.events[0].point_valid=false;
        }
        if(!c.entry_straight_complete){p.events[1].range=Range::BEFORE_PATH;p.events[1].point_valid=false;}
        if(!c.exit_complete)for(auto j:{3,4,5}){p.events[j].range=Range::AFTER_PATH;p.events[j].arc=path.length()+1;p.events[j].point_valid=false;}
        if(p.centerline)p.straights.push_back({std::max(0.0,s),std::min(path.length(),t),c.u_in,!c.entry_straight_complete||!c.exit_straight_complete});
        else {p.straights.push_back({std::max(0.0,s),e,c.u_in,!c.entry_straight_complete});p.straights.push_back({x,std::min(path.length(),t),c.u_out,!c.exit_straight_complete});}
        plan.passages.push_back(p);
    }
    // 新路径起点已过 X 时，新 crossings 可以为空；仍迁移未完成的出口直线/T/D。
    if(same) {
        Polyline old(previous->path);
        const auto anchor=old.project(path.points.front(),std::max(0.0,previous_progress-config.backward_window),
            std::min(old.length(),previous_progress+config.forward_window));
        for(const auto& p:previous->passages)if(!used.count(p.uid)&&event(p,EventType::D).arc>anchor.arc&&
            event(p,EventType::E).arc<=previous_progress) {
            if(anchor.lateral>0.03)throw std::runtime_error("cannot migrate committed exit range to different corridor");
            Passage remaining=p;
            for(auto& ev:remaining.events)if(ev.range!=Range::UNKNOWN)ev=makeEvent(ev.type,ev.arc-anchor.arc,path);
            for(auto& line:remaining.straights) {
                line.begin=std::max(0.0,line.begin-anchor.arc);line.end=std::min(path.length(),line.end-anchor.arc);line.remaining=true;
                if(line.end>line.begin) {
                    const Point u=line.direction;const Point start=path.at(line.begin);
                    std::vector<Point> samples{path.at(line.end)};
                    for(std::size_t k=0;k<path.points.size();++k)if(path.arcs[k]>line.begin&&path.arcs[k]<line.end)samples.push_back(path.points[k]);
                    for(auto q:samples)if(std::abs(holeCross(u,q-start))>1e-5||holeDot(u,q-start)<-epsilon)
                        throw std::runtime_error("replan broke committed exit straight");
                }
            }
            plan.passages.push_back(std::move(remaining));
        }
    }
    // 坡面不重定义六事件，只产生速度区间；上下坡按实际路径切向与地图上坡轴判断。
    if(terrain)for(const auto& region:terrain->getRegions())if(region.type=="slope") {
        const auto attrs=region.attributes();if(!attrs["uphill_yaw_deg"])throw std::runtime_error("slope lacks uphill direction");
        const double yaw=attrs["uphill_yaw_deg"].as<double>()*3.14159265358979323846/180;
        const Point up{std::cos(yaw),std::sin(yaw)};
        // 逐线段与多边形边精确求交，避免用稀疏采样漏过坡段。
        for(std::size_t j=1;j<path.points.size();++j) {
            const auto a=path.points[j-1],v=path.points[j]-a;const double length=holeNorm(v);
            std::vector<double> cuts{0,1};
            for(std::size_t k=0;k<region.polygon.size();++k) {
                const auto b=region.polygon[k],c=region.polygon[(k+1)%region.polygon.size()];
                const Point w{c.x-b.x,c.y-b.y},delta{b.x-a.x,b.y-a.y};const double det=holeCross(v,w);
                if(std::abs(det)<epsilon)continue;const double t0=holeCross(delta,w)/det,u=holeCross(delta,v)/det;
                if(t0>0&&t0<1&&u>=0&&u<=1)cuts.push_back(t0);
            }
            std::sort(cuts.begin(),cuts.end());
            for(std::size_t k=1;k<cuts.size();++k) {
                const Point mid=a+v*((cuts[k]+cuts[k-1])/2);
                if(!TerrainRegionMap::pointInPolygon(region.polygon,mid.x,mid.y))continue;
                const double align=holeDot(v,up)/length;
                if(std::abs(align)<0.5)throw std::runtime_error("ambiguous/sideways slope traversal");
                const double begin=path.arcs[j-1]+cuts[k-1]*length,end=path.arcs[j-1]+cuts[k]*length;
                plan.speeds.push_back({begin,end,align>0?config.uphill_speed:config.downhill_speed,align>0?Travel::UPHILL:Travel::DOWNHILL});
            }
        }
        // 这是用户新增策略：上坡结束后低速。地图关联属性区分受限型，不按ID字母猜类型。
        const auto relation=attrs["hole_relative_to_slope"];
        if(true) { // 用户确认：每次到达坡顶后开始减速。
            double end=-1;
            for(const auto& v:plan.speeds)if(v.kind==Travel::UPHILL&&v.end>end) {
                const Point q=path.at(std::max(v.begin,v.end-1e-6));
                if(TerrainRegionMap::pointInPolygon(region.polygon,q.x,q.y))end=v.end;
            }
            if(end>=0)plan.speeds.push_back({end,end+config.post_slope_distance,config.restricted_speed,Travel::CREST});
        }
    }
    return plan;
}
}
