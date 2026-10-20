#include "nav_components/hole_passage_planner.hpp"
#include <queue>
#include <map>
#include <limits>
#include <iomanip>
#include <sstream>

namespace nav_components {
using namespace nav_core;
namespace {
using Time=std::chrono::steady_clock;
using Deadline=Time::time_point;
nav_msgs::msg::Path message(const std::vector<HolePoint> &points,const std_msgs::msg::Header &header) {
    nav_msgs::msg::Path path;path.header=header;
    for(auto p:points) {geometry_msgs::msg::PoseStamped pose;pose.header=header;
        pose.pose.position.x=p.x;pose.pose.position.y=p.y;pose.pose.orientation.w=1;path.poses.push_back(pose);}
    return path;
}
void append(std::vector<HolePoint> &out,const std::vector<HolePoint> &points) {
    for(auto p:points) if(out.empty()||holeNorm(out.back()-p)>1e-10) out.push_back(p);
}
std::vector<HolePoint> line(HolePoint a,HolePoint b,double resolution) {
    const int count=std::max(1,static_cast<int>(std::ceil(holeNorm(b-a)/resolution)));
    std::vector<HolePoint> points;for(int i=0;i<=count;++i) points.push_back(a+(b-a)*(double(i)/count));return points;
}
double length(const std::vector<HolePoint> &points) {
    double result=0;for(std::size_t i=1;i<points.size();++i) result+=holeNorm(points[i]-points[i-1]);return result;
}
// Every chord of the hull and every polygon vertex inside a hull triangle is checked.
bool hullOverlaps(const std::vector<HolePoint> &controls,const std::vector<HolePoint> &polygon) {
    for(auto p:controls) if(holeStrictlyInside(polygon,p)) return true;
    for(auto a:controls) for(auto b:controls) {double lo,hi;if(holeClip(polygon,a,b,lo,hi))return true;}
    for(auto p:polygon) for(std::size_t a=0;a<controls.size();++a)
        for(std::size_t b=a+1;b<controls.size();++b) for(std::size_t c=b+1;c<controls.size();++c) {
            const double area=holeCross(controls[b]-controls[a],controls[c]-controls[a]);if(std::abs(area)<1e-12)continue;
            const double sign=area>0?1:-1;
            if(sign*holeCross(controls[b]-controls[a],p-controls[a])>=0&&
               sign*holeCross(controls[c]-controls[b],p-controls[b])>=0&&
               sign*holeCross(controls[a]-controls[c],p-controls[c])>=0)return true;
        }
    return false;
}
struct Hole {HoleGeometryPreview geometry;HoleTraversalDistances distances;std::vector<HolePathCrossing> crossings;};
struct Node {
    std::size_t hole=0;
    HoleRouteAttempt attempt;
    std::vector<std::size_t> holes;
    std::vector<HoleRouteAttempt> shared;
    std::vector<HolePoint> body,raw;
    std::optional<HolePoint> prepare,departure;
    HolePoint in,out;
    bool from_start=false,to_goal=false;
    bool exit_only=false,manual_range=false;
    double cost=0;
};
// Optimistic connectivity only rejects impossible outside connections. Boundary
// cells stay open; the curve and segment validators still enforce exact geometry.
class OutsideConnectivity {
    const nav_msgs::msg::OccupancyGrid &map_;
    std::vector<int> components_;
public:
    OutsideConnectivity(const nav_msgs::msg::OccupancyGrid &map,double threshold,const std::vector<Hole> &holes):map_(map) {
        const auto &m=map.info;const int w=m.width,h=m.height;const double r=m.resolution;
        components_.resize(w*h,-1);
        for(int i=0;i<w*h;++i)if(map.data[i]<0||map.data[i]>=threshold)components_[i]=-2;
        for(const auto &hole:holes) {
            double xmin=1e30,xmax=-1e30,ymin=1e30,ymax=-1e30;
            for(auto p:hole.geometry.polygon){xmin=std::min(xmin,p.x);xmax=std::max(xmax,p.x);ymin=std::min(ymin,p.y);ymax=std::max(ymax,p.y);}
            const int x0=std::max(0,int(std::floor((xmin-m.origin.position.x)/r))),x1=std::min(w-1,int(std::floor((xmax-m.origin.position.x)/r)));
            const int y0=std::max(0,int(std::floor((ymin-m.origin.position.y)/r))),y1=std::min(h-1,int(std::floor((ymax-m.origin.position.y)/r)));
            for(int y=y0;y<=y1;++y)for(int x=x0;x<=x1;++x) {
                const HolePoint p{m.origin.position.x+x*r,m.origin.position.y+y*r};
                if(holeStrictlyInside(hole.geometry.polygon,p)&&holeStrictlyInside(hole.geometry.polygon,p+HolePoint{r,0})&&
                   holeStrictlyInside(hole.geometry.polygon,p+HolePoint{0,r})&&holeStrictlyInside(hole.geometry.polygon,p+HolePoint{r,r}))components_[y*w+x]=-2;
            }
        }
        const int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
        std::vector<int> open;int component=0;
        for(int source=0;source<w*h;++source)if(components_[source]==-1) {
            open.clear();open.push_back(source);components_[source]=component;
            for(std::size_t i=0;i<open.size();++i) {
                const int id=open[i],x=id%w,y=id/w;
                for(int k=0;k<8;++k) {
                    const int nx=x+dx[k],ny=y+dy[k];if(nx<0||ny<0||nx>=w||ny>=h)continue;
                    const int next=ny*w+nx;if(components_[next]!=-1)continue;
                    // Occupancy cells are closed squares, so diagonal corner cutting is forbidden.
                    if(dx[k]&&dy[k]&&(components_[y*w+nx]==-2||components_[ny*w+x]==-2))continue;
                    components_[next]=component;open.push_back(next);
                }
            }
            ++component;
        }
    }
    OutsideConnectivity(const nav_msgs::msg::OccupancyGrid &map,const std::vector<int> &components):map_(map),components_(components) {}
    const std::vector<int> &components() const {return components_;}
    bool connected(HolePoint a,HolePoint b) const {
        const auto id=[&](HolePoint p) {
            const auto &m=map_.info;const int x=std::floor((p.x-m.origin.position.x)/m.resolution),y=std::floor((p.y-m.origin.position.y)/m.resolution);
            return x<0||y<0||x>=int(m.width)||y>=int(m.height)?-1:components_[y*m.width+x];
        };
        const int ca=id(a),cb=id(b);return ca<0||cb<0||ca==cb;
    }
};
}

HolePassageCheck HolePassagePlanner::planRoute(const nav_msgs::msg::Path &seed,HolePoint start,HolePoint goal,
        const nav_msgs::msg::OccupancyGrid &map,double threshold,nav_msgs::msg::Path &route,bool &constrained,
        std::optional<HolePoint> start_velocity,Deadline request_deadline) {
    selected_route_.clear();

    statistics_=HolePlanningStatistics{};statistics_.stop_reason="REQUEST_REJECTED";
    const auto request_begin=Time::now();
    const auto record=std::shared_ptr<void>(nullptr,[&](void*) {
        statistics_.total_ms=std::chrono::duration<double,std::milli>(Time::now()-request_begin).count();
        if(statistics_.first_valid_ms>=0)statistics_.post_first_valid_ms=statistics_.total_ms-statistics_.first_valid_ms;
    });
    refreshConfiguration();route=nav_msgs::msg::Path();constrained=false;route_attempts_.clear();path_passages_.clear();publishDiagnostics();
    if(route_publisher_) {nav_msgs::msg::Path empty;empty.header.frame_id="map";route_publisher_->publish(empty);}
    if(!config_.enabled)return holeCheck(true,"HOLE_PLANNER_DISABLED");
    if(!terrain_)return holeCheck(false,"TERRAIN_UNAVAILABLE");
    if(seed.header.frame_id!="map"||(!map.header.frame_id.empty()&&map.header.frame_id!="map"))return holeCheck(false,"FRAME_MISMATCH");
    const auto begin=request_begin;
    const auto hard_deadline=std::min(request_deadline,begin+std::chrono::duration_cast<Time::duration>(std::chrono::duration<double>(config_.planning_timeout)));
    auto deadline=begin+(hard_deadline-begin)*9/10; // 留出最终接纳校验时间。
    if(Time::now()>=deadline)return holeCheck(false,"PLANNING_TIMEOUT");
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,threshold,a,b);};
    for(auto p:{start,goal}) {const auto check=collision(p,p);if(!check.valid)return check;}
    std::vector<HolePoint> seed_points;for(const auto &p:seed.poses)seed_points.push_back({p.pose.position.x,p.pose.position.y});
    const HolePathPolyline seed_path(seed_points);
    std::vector<Hole> holes;int crossing_count=0;bool partial=false;
    {HoleTimingScope timer(statistics_.geometry_ms);
    for(const auto &region:terrain_->getRegions()) {
        if(Time::now()>=deadline)return holeCheck(false,"GEOMETRY_TIMEOUT");
        if(region.type!="low_clearance"&&region.type!="2")continue;
        if(blocked_holes_.count(region.id))continue;
        Hole h;h.geometry=geometry(region,h.distances,&start);
        if(h.geometry.reason=="HOLE_DISABLED")continue;
        if(!h.geometry.geometry_valid)return holeCheck(false,h.geometry.reason);
        h.crossings=holePathCrossings(h.geometry,seed_path);crossing_count+=h.crossings.size();
        partial|=holeStrictlyInside(h.geometry.polygon,start)||holeStrictlyInside(h.geometry.polygon,goal);
        holes.push_back(std::move(h));
    }
    }
    if(!seed_path.valid&&holeNorm(goal-start)>1e-8&&!config_.global_enabled)return holeCheck(false,"ASTAR_SEED_REQUIRED");
    struct Commitment {std::size_t hole;HolePassageCandidate passage;bool entry_line=false,exit_line=false;};
    std::vector<Commitment> commitments;
    if(!previous_route_.poses.empty()&&holeNorm(goal-HolePoint{previous_route_.poses.back().pose.position.x,
        previous_route_.poses.back().pose.position.y})<1e-7) {
        std::vector<HolePoint> old_points;
        for(const auto &p:previous_route_.poses)old_points.push_back({p.pose.position.x,p.pose.position.y});
        HolePathPolyline old_path(old_points);
        for(std::size_t id=0;id<holes.size();++id)for(const auto &crossing:holePathCrossings(holes[id].geometry,old_path)) {
            auto c=freeHoleCandidate(holes[id].geometry,holes[id].distances,old_path,crossing);c.mode=config_.mode;
            const auto d=std::find_if(holes[id].geometry.directions.begin(),holes[id].geometry.directions.end(),[&](const auto &v){
                return (crossing.entry_edge<0||crossing.entry_edge==v.entry_edge_id)&&
                       (crossing.exit_edge<0||crossing.exit_edge==v.exit_edge_id)&&holeDot(c.X-c.E,v.tangent)>0;
            });
            if(d==holes[id].geometry.directions.end())continue;
            c.entry_edge=d->entry_edge_id;c.exit_edge=d->exit_edge_id;
            if(config_.mode==HolePassageMode::Centerline)c=centerlineHoleCandidate(holes[id].geometry,*d);
            const bool entry_line=holeSegmentDistance(start,c.S,c.E)<1e-7;
            const bool exit_line=holeSegmentDistance(start,c.X,c.T)<1e-7;
            if(entry_line||exit_line||holeStrictlyInside(holes[id].geometry.polygon,start))
                commitments.push_back({id,c,entry_line,exit_line});
        }
    }
    if(seed_path.valid&&crossing_count==0&&!partial&&commitments.empty()){statistics_.stop_reason="NO_PASSAGE";return holeCheck(true,"PATH_VALID_NO_PASSAGE");}
    if(!config_.global_enabled)
        return planSingleRoute(seed,start,goal,map,threshold,route,constrained,start_velocity,hard_deadline);
    if(holes.empty())return holeCheck(true,"PATH_VALID_NO_PASSAGE");
    if(holeNorm(goal-start)<1e-9) {
        route=message({start},seed.header);constrained=true;return holeCheck(true,"PATH_VALID_STATIONARY");
    }
    const HoleSegmentCheck outside=[&](HolePoint a,HolePoint b) {
        const auto check=collision(a,b);if(!check.valid)return check;
        for(const auto &h:holes) {double lo,hi;if(holeClip(h.geometry.polygon,a,b,lo,hi))return holeCheck(false,"CONNECTION_CROSSES_HOLE",a);}
        return holeCheck(true,"OK");
    };
    const HoleHullCheck outside_hull=[&](const std::vector<HolePoint> &controls) {
        const auto check=checkHoleMapHull(map,threshold,controls);if(!check.valid)return check;
        for(const auto &h:holes)if(hullOverlaps(controls,h.geometry.polygon))return holeCheck(false,"CONNECTION_CROSSES_HOLE",controls.front());
        return holeCheck(true,"CURVE_HULL_VALID");
    };
    // Full candidate cost has metre units: length + curvature integral + clearance deficit integral.
    const auto score=[&](const std::vector<HolePoint> &points) {
        double cost=length(points);
        for(std::size_t i=1;!config_.feasible_approach&&i+1<points.size();++i) {
            const auto a=points[i]-points[i-1],b=points[i+1]-points[i];
            const double ds=0.5*(holeNorm(a)+holeNorm(b)),den=holeNorm(a)*holeNorm(b)*holeNorm(points[i+1]-points[i-1]);
            if(den>1e-15){const double k=2*std::abs(holeCross(a,b))/den;cost+=config_.route_curvature_weight*k*k*ds;}
        }
        if(distance_query_)for(std::size_t i=1;i<points.size();++i) {
            const auto p=(points[i-1]+points[i])*0.5;const double d=distance_query_(p.x,p.y,nullptr,nullptr);
            if(!std::isfinite(d))return std::numeric_limits<double>::infinity();
            const double deficit=std::max(0.0,config_.optimization.safe_distance-d);
            cost+=config_.route_clearance_weight*deficit*deficit*holeNorm(points[i]-points[i-1]);
        }
        return cost;
    };
    const auto connect=[&](HolePoint a,HolePoint tangent,const std::vector<HolePoint> &targets,
            std::optional<HolePoint> final,const HoleSegmentCheck &segments,const HoleHullCheck &hull,Deadline until) {
        HoleOptimizedConnection result;result.check=holeCheck(false,"CONNECTION_FAILED");
        // Exact aligned connections avoid spending the optimization budget on a straight line.
        std::vector<HolePoint> points{a};HolePoint previous=a;bool straight=true;
        for(auto p:targets) {
            if(holeNorm(p-previous)>1e-9&&!holeDirectionMatches(p-previous,tangent,1e-5))straight=false;
            if(!segments(previous,p).valid)straight=false;
            append(points,line(previous,p,config_.search.sample_resolution));previous=p;
        }
        if(final&&!holeDirectionMatches(tangent,*final,1e-5))straight=false;
        if(straight) {result.points=result.seed=std::move(points);result.length=result.seed_length=length(result.points);
            result.check=holeCheck(true,"CONNECTION_VALID");return result;}
        if(config_.optimization.enabled) {
            ++statistics_.optimized_edges;
            result=optimizeHoleConnection(a,tangent,targets,final,config_.optimization,
                config_.search,map,segments,hull,distance_query_,until);
            statistics_.connection_search_ms+=result.seed_search_ms;
            statistics_.curve_fit_ms+=result.curve_fit_ms;statistics_.curve_validation_ms+=result.curve_validation_ms;
            statistics_.iterations+=result.iterations;statistics_.fits+=result.fits;
            return result;
        }
        HoleTimingScope timer(statistics_.connection_search_ms);
        const auto legacy=searchHoleConnection(a,tangent,targets,final,config_.search,segments,until);
        result.check=legacy.check;result.points=result.seed=legacy.points;result.expansions=legacy.expansions;
        result.length=result.seed_length=length(result.points);return result;
    };
    std::vector<HolePoint> best_points,best_seed;std::vector<HoleRouteAttempt> best_attempts;
    double best_cost=std::numeric_limits<double>::infinity();
    const auto retain=[&](const std::vector<HolePoint> &points,const std::vector<HolePoint> &raw,
            const std::vector<HoleRouteAttempt> &attempts,double deviation) {
        if(points.empty()||holeNorm(points.front()-start)>1e-7||holeNorm(points.back()-goal)>1e-7)return;
        HolePassageCheck check;
        {HoleTimingScope timer(statistics_.candidate_validation_ms);
         check=validatePath(message(points,seed.header),map,threshold,false,deadline);}
        if(!check.valid)return;
        if(path_passages_.size()>static_cast<std::size_t>(config_.graph_max_passages))return;
        const HolePathPolyline path(points);
        for(const auto &attempt:attempts)if(!attempt.manual_range&&attempt.passage.mode==HolePassageMode::Centerline) {
            const auto u=attempt.passage.u_in;
            for(auto p:config_.normal_departure?std::vector<HolePoint>{attempt.A}:std::vector<HolePoint>{attempt.A,attempt.D}) {
                if(std::abs(holeCross(u,start-p))<1e-8&&holeDot(start-p,u)>1e-8)continue;
                if(std::abs(holeCross(u,goal-p))<1e-8&&holeDot(goal-p,u)<-1e-8)continue;
                if(std::none_of(points.begin(),points.end(),[&](auto q){return holeNorm(q-p)<1e-7;}))return;
            }
        }
        for(const auto &commit:commitments) {
            for(const auto &c:path_passages_)if(c.hole_id==holes[commit.hole].geometry.id&&
                (c.entry_edge!=commit.passage.entry_edge||c.exit_edge!=commit.passage.exit_edge))return;
            if(commit.exit_line) {
                const auto end=holeSegmentDistance(goal,start,commit.passage.T)<1e-7?goal:commit.passage.T;
                const double remaining=holeNorm(end-start);
                if(path.arc.back()+1e-8<remaining)return;
                for(auto p:path.slice(0,remaining))if(std::abs(holeCross(commit.passage.u_out,p-start))>1e-8||
                    holeDot(p-start,commit.passage.u_out)<-1e-9)return;
                if(holeNorm(path.at(remaining)-end)>1e-7)return;
                if(remaining<path.arc.back()-1e-9&&!holeDirectionMatches(path.tangent(remaining,true),
                    commit.passage.u_out,config_.validation.tangent_tolerance_deg))return;
            }
        }
        const double cost=score(points)+deviation;
        if(cost<best_cost){
            if(statistics_.first_valid_ms<0) {
                statistics_.first_valid_ms=std::chrono::duration<double,std::milli>(Time::now()-begin).count();
                if(config_.responsive)deadline=std::min(deadline,Time::now()+std::chrono::duration_cast<Time::duration>(
                    std::chrono::duration<double>(config_.improvement_timeout)));
            }
            best_cost=cost;best_points=points;best_seed=raw;best_attempts=attempts;
        }
    };
    // Coaxial passages share overlapping straight requirements; every configured keypoint is inserted once.
    if(holeNorm(goal-start)>1e-8) {
        const auto u=(goal-start)*(1/holeNorm(goal-start));bool aligned=true;std::vector<HolePoint> marks{start,goal};
        std::vector<HoleRouteAttempt> attempts;
        for(const auto &h:holes) {
            const HolePathPolyline direct({start,goal});if(holePathCrossings(h.geometry,direct).empty())continue;
            auto d=std::find_if(h.geometry.directions.begin(),h.geometry.directions.end(),[&](const auto &v) {
                return holeDirectionMatches(u,v.tangent,1e-5)&&std::abs(holeCross(u,v.E-start))<1e-8;
            });
            if(d==h.geometry.directions.end()){aligned=false;break;}
            HoleRouteAttempt attempt;attempt.passage=centerlineHoleCandidate(h.geometry,*d);attempt.passage.mode=config_.mode;
            attempt.manual_range=h.distances.manual_range;
            attempt.A=d->A;attempt.D=d->D;attempt.prepare_distance=h.distances.prepare_distance;
            attempt.optimized=config_.optimization.enabled;attempt.check=holeCheck(true,"SHARED_STRAIGHT_VALID");
            for(auto p:config_.normal_departure?std::vector<HolePoint>{d->A,d->S,d->E,d->X,d->T}:std::vector<HolePoint>{d->A,d->S,d->E,d->X,d->T,d->D}) {
                const double t=holeDot(p-start,u);if(t>0&&t<holeNorm(goal-start))marks.push_back(p);
            }
            attempts.push_back(attempt);
        }
        if(start_velocity&&holeNorm(*start_velocity)>config_.min_motion_speed&&
           !holeDirectionMatches(*start_velocity,u,config_.validation.tangent_tolerance_deg))aligned=false;
        if(aligned&&!attempts.empty()) {
            std::sort(marks.begin(),marks.end(),[&](auto a,auto b){return holeDot(a-start,u)<holeDot(b-start,u);});
            std::vector<HolePoint> points;for(std::size_t i=1;i<marks.size();++i)append(points,line(marks[i-1],marks[i],config_.search.sample_resolution));
            retain(points,points,attempts,0);
        }
    }
    // The ordinary seed is only retained if the independent validator proves all hole constraints.
    if(seed_path.valid&&config_.mode==HolePassageMode::Free) {
        bool straight=true;
        for(std::size_t i=1;i+1<seed_path.points.size();++i)
            if(!holeDirectionMatches(seed_path.points[i]-seed_path.points[i-1],
                seed_path.points[i+1]-seed_path.points[i],1e-5))straight=false;
        std::vector<double> marks=seed_path.arc;
        for(const auto &h:holes)for(const auto &crossing:h.crossings)
            for(double s:{crossing.entry_arc-h.distances.prepare_distance,crossing.entry_arc-h.distances.forEntry(crossing.entry_edge).entry_straight_length,
                crossing.entry_arc,crossing.exit_arc,crossing.exit_arc+h.distances.forEntry(crossing.entry_edge).exit_straight_length,
                crossing.exit_arc+h.distances.departure_distance})
                if(s>=0&&s<=seed_path.arc.back())marks.push_back(s);
        std::sort(marks.begin(),marks.end());std::vector<HolePoint> points;
        for(double s:marks)append(points,{seed_path.at(s)});
        if(straight)retain(points,seed_path.points,{},0);
    }
    // Bypass generation has a bounded share of the budget so passage search can still finish.
    const auto try_bypass=[&]() {
    std::vector<HolePoint> bypass;int grid_expansions=0;
    if(best_cost>holeNorm(goal-start)+1e-8&&!partial&&commitments.empty()&&config_.global_enabled&&searchHoleGridConnection(start,goal,map,outside,config_.search.max_expansions,
            std::min(deadline,begin+std::chrono::duration_cast<Time::duration>(std::chrono::duration<double>(config_.search.timeout))),bypass,grid_expansions)) {
        // Smooth with exact endpoint constraints before retaining the complete candidate.
        if(bypass.size()>1) {
            const auto tangent=start_velocity&&holeNorm(*start_velocity)>config_.min_motion_speed?*start_velocity:bypass[1]-bypass[0];
            const auto smooth=connect(start,tangent,{goal},std::nullopt,outside,outside_hull,
                std::min(deadline,begin+std::chrono::duration_cast<Time::duration>(std::chrono::duration<double>(config_.planning_timeout*0.2))));
            if(smooth.check.valid)retain(smooth.points,smooth.seed,{},0);
        }
    }
    };
    if(!config_.responsive)try_bypass();
    std::vector<Node> nodes;
    if(connectivity_map_&&(connectivity_map_->info!=map.info||connectivity_map_->header.frame_id!=map.header.frame_id))clearConnectionCache();
    const auto connectivity_begin=Time::now();
    std::unique_ptr<OutsideConnectivity> connectivity_ptr;
    const bool same_map=connectivity_map_&&connectivity_threshold_==threshold&&
        connectivity_map_->info==map.info&&connectivity_map_->header.frame_id==map.header.frame_id&&connectivity_map_->data==map.data;
    if(same_map)connectivity_ptr=std::make_unique<OutsideConnectivity>(map,connectivity_components_);
    else {
        connectivity_ptr=std::make_unique<OutsideConnectivity>(map,threshold,holes);
        connectivity_map_=std::make_shared<nav_msgs::msg::OccupancyGrid>(map);connectivity_threshold_=threshold;
        connectivity_components_=connectivity_ptr->components();
    }
    const auto &connectivity=*connectivity_ptr;
    statistics_.connectivity_ms=std::chrono::duration<double,std::milli>(Time::now()-connectivity_begin).count();
    const auto candidate_begin=Time::now();
    const double candidate_work_before=statistics_.connection_search_ms+statistics_.curve_fit_ms+statistics_.curve_validation_ms;
    // Merge fixed bodies intersecting another hole on the same forward axis. The full
    // straight union includes interleaved A/D events, so no backward connector is needed.
    const auto share=[&](Node &n)->bool {
        n.holes={n.hole};
        const auto u=n.attempt.passage.u_in,origin=n.attempt.passage.E;
        if(!holeDirectionMatches(u,n.attempt.passage.u_out,1e-5))return true;
        for(auto p:n.body)if(std::abs(holeCross(u,p-origin))>1e-8)return true;
        double lo=holeDot(n.body.front()-origin,u),hi=holeDot(n.body.back()-origin,u);
        n.shared={n.attempt};
        for(std::size_t iteration=0;iteration<holes.size();++iteration) {
            bool extended=false;
            for(std::size_t id=0;id<holes.size();++id) {
                if(std::find(n.holes.begin(),n.holes.end(),id)!=n.holes.end())continue;
                double a,b;bool intersects=holeClip(holes[id].geometry.polygon,origin+u*lo,origin+u*hi,a,b);
                if(config_.mode==HolePassageMode::Centerline)for(const auto &d:holes[id].geometry.directions) {
                    if(!holeDirectionMatches(u,d.tangent,1e-5)||std::abs(holeCross(u,d.E-origin))>1e-8)continue;
                    double low=lo,high=hi;
                    for(const auto &attempt:n.shared){low=std::min(low,holeDot(attempt.A-origin,u));high=std::max(high,holeDot((config_.normal_departure?attempt.passage.T:attempt.D)-origin,u));}
                    intersects|=holeDot(d.A-origin,u)<=high+1e-8&&holeDot((config_.normal_departure?d.T:d.D)-origin,u)>=low-1e-8;
                }
                if(config_.mode==HolePassageMode::Centerline)for(const auto &attempt:n.shared)if(!attempt.manual_range)
                    intersects|=holeStrictlyInside(holes[id].geometry.polygon,attempt.A)||
                                (!config_.normal_departure&&holeStrictlyInside(holes[id].geometry.polygon,attempt.D));
                if(!intersects)continue;
                const auto &h=holes[id];HolePassageCandidate passage;
                if(config_.mode==HolePassageMode::Centerline) {
                    auto d=std::find_if(h.geometry.directions.begin(),h.geometry.directions.end(),[&](const auto &v){
                        return holeDirectionMatches(u,v.tangent,1e-5)&&std::abs(holeCross(u,v.E-origin))<1e-8;
                    });
                    if(d==h.geometry.directions.end())return false;
                    passage=centerlineHoleCandidate(h.geometry,*d);
                } else {
                    double low=lo,high=hi;
                    for(auto p:h.geometry.polygon){low=std::min(low,holeDot(p-origin,u)-1);high=std::max(high,holeDot(p-origin,u)+1);}
                    HolePathPolyline axis({origin+u*low,origin+u*high});
                    const auto crossings=holePathCrossings(h.geometry,axis);
                    if(crossings.size()!=1||crossings.front().partial)return false;
                    passage=freeHoleCandidate(h.geometry,h.distances,axis,crossings.front());
                    if(!validateHoleCandidate(h.geometry,h.distances,config_.validation,passage,collision).valid)return false;
                }
                HoleRouteAttempt attempt;attempt.passage=passage;attempt.prepare_distance=h.distances.prepare_distance;
                attempt.manual_range=h.distances.manual_range;
                attempt.A=passage.E-u*h.distances.prepare_distance;attempt.D=passage.X+u*h.distances.departure_distance;
                if(attempt.manual_range){attempt.A=passage.S;attempt.D=passage.T;}
                attempt.optimized=config_.optimization.enabled;attempt.check=holeCheck(true,"SHARED_STRAIGHT_VALID");
                lo=std::min(lo,holeDot(passage.S-origin,u));hi=std::max(hi,holeDot(passage.T-origin,u));
                n.holes.push_back(id);n.shared.push_back(attempt);extended=true;
            }
            if(!extended)break;
        }
        if(n.holes.size()==1){n.shared.clear();return true;}
        if(n.holes.size()>static_cast<std::size_t>(config_.graph_max_passages))return false;
        std::vector<HolePoint> marks;
        n.prepare.reset();n.departure.reset();
        if(config_.mode==HolePassageMode::Centerline) {
            for(const auto &attempt:n.shared)if(!attempt.manual_range) {
                if(!n.prepare||holeDot(attempt.A-origin,u)<holeDot(*n.prepare-origin,u))n.prepare=attempt.A;
                if(!config_.normal_departure&&(!n.departure||holeDot(attempt.D-origin,u)>holeDot(*n.departure-origin,u)))n.departure=attempt.D;
            }
            for(const auto &attempt:n.shared) {
                if(attempt.manual_range)continue;
                if(n.prepare&&holeNorm(attempt.A-*n.prepare)>1e-8)lo=std::min(lo,holeDot(attempt.A-origin,u));
                if(n.departure&&holeNorm(attempt.D-*n.departure)>1e-8)hi=std::max(hi,holeDot(attempt.D-origin,u));
            }
        }
        for(const auto &attempt:n.shared) {
            const auto &c=attempt.passage;
            for(auto p:{c.S,c.E,c.X,c.T})marks.push_back(p);
            if(!attempt.manual_range&&config_.mode==HolePassageMode::Centerline)for(auto p:config_.normal_departure?std::vector<HolePoint>{attempt.A}:std::vector<HolePoint>{attempt.A,attempt.D}) {
                marks.push_back(p);
            }
        }
        if(std::abs(holeCross(u,start-origin))<1e-8) {
            const double s=holeDot(start-origin,u);
            if(s>=lo-1e-8&&s<=hi+1e-8){lo=s;n.from_start=true;n.prepare.reset();}
            else if(n.prepare&&s>holeDot(*n.prepare-origin,u)&&s<lo)n.prepare.reset();
        }
        if(std::abs(holeCross(u,goal-origin))<1e-8) {
            const double s=holeDot(goal-origin,u);
            if(s>=lo-1e-8&&s<=hi+1e-8){hi=s;n.to_goal=true;n.departure.reset();}
            else if(n.departure&&s<holeDot(*n.departure-origin,u)&&s>hi)n.departure.reset();
        }
        if(hi<=lo+1e-9)return false;
        n.in=origin+u*lo;n.out=origin+u*hi;
        marks.push_back(n.in);marks.push_back(n.out);
        std::sort(marks.begin(),marks.end(),[&](auto a,auto b){return holeDot(a-origin,u)<holeDot(b-origin,u);});
        n.body.clear();HolePoint previous=n.in;
        for(auto p:marks)if(holeDot(p-origin,u)>=lo-1e-8&&holeDot(p-origin,u)<=hi+1e-8) {
            append(n.body,line(previous,p,config_.search.sample_resolution));previous=p;
        }
        n.raw=n.body;
        std::stable_sort(n.shared.begin(),n.shared.end(),[&](const auto &a,const auto &b){
            return holeDot(a.passage.E-origin,u)<holeDot(b.passage.E-origin,u);
        });
        n.manual_range=n.shared.back().manual_range;
        return true;
    };
    // Preserve actual free-mode crossings first. Direction alternatives use positions sampled on their own edges.
    for(std::size_t hi=0;hi<holes.size()&&nodes.size()<static_cast<std::size_t>(config_.graph_max_nodes);++hi) {
        if(best_cost<=holeNorm(goal-start)+1e-8)break;
        const auto &h=holes[hi];if(!h.geometry.valid)continue;
        const auto node_deadline=std::min(deadline,Time::now()+std::chrono::duration_cast<Time::duration>(
            std::chrono::duration<double>(config_.planning_timeout*0.3/(holes.size()-hi))));
        std::vector<HolePassageCandidate> candidates;
        for(const auto &commit:commitments)if(commit.hole==hi)candidates.push_back(commit.passage);
        if(config_.mode==HolePassageMode::Free&&seed_path.valid)for(const auto &crossing:h.crossings) {
            auto actual=freeHoleCandidate(h.geometry,h.distances,seed_path,crossing);
            if(!crossing.partial)candidates.push_back(actual);
            else for(const auto &d:h.geometry.directions) {
                if((crossing.entry_edge>=0&&crossing.entry_edge!=d.entry_edge_id)||
                   (crossing.exit_edge>=0&&crossing.exit_edge!=d.exit_edge_id))continue;
                auto c=centerlineHoleCandidate(h.geometry,d);c.mode=HolePassageMode::Free;
                if(crossing.entry_edge>=0)c.E=actual.E;
                if(crossing.exit_edge>=0)c.X=actual.X;
                c.u_in=actual.u_in;c.u_out=actual.u_out;
                c.S=c.E-c.u_in*h.distances.forEntry(c.entry_edge).entry_straight_length;c.T=c.X+c.u_out*h.distances.forEntry(c.entry_edge).exit_straight_length;
                candidates.push_back(c);
            }
        }
        for(const auto &d:h.geometry.directions) {
            auto c=centerlineHoleCandidate(h.geometry,d);c.mode=config_.mode;
            candidates.push_back(c);
            if(config_.mode==HolePassageMode::Free) {
                const auto edge=h.geometry.polygon[d.entry_edge_id];
                const auto v=h.geometry.polygon[(d.entry_edge_id+1)%4]-edge;
                const double width=holeNorm(v);const auto lateral=v*(1/width);
                std::vector<HolePoint> entries{c.E},exits{c.X};
                for(int k=1;k<=std::min(64,int(std::ceil(width/config_.edge_step)));++k)for(int sign:{-1,1}) {
                    const double offset=sign*k*config_.edge_step;if(std::abs(offset)>=width*0.5-1e-6)continue;
                    auto shifted=c;shifted.E=c.E+lateral*offset;shifted.X=c.X+lateral*offset;
                    shifted.S=shifted.E-shifted.u_in*h.distances.forEntry(c.entry_edge).entry_straight_length;
                    shifted.T=shifted.X+shifted.u_out*h.distances.forEntry(c.entry_edge).exit_straight_length;shifted.inside={shifted.E,shifted.X};
                    candidates.push_back(shifted);
                    entries.push_back(shifted.E);exits.push_back(shifted.X);
                }
                const auto add=[&](HolePoint E,HolePoint X,HolePoint u) {
                    auto candidate=c;candidate.E=E;candidate.X=X;candidate.u_in=candidate.u_out=u;
                    candidate.S=E-u*h.distances.forEntry(c.entry_edge).entry_straight_length;candidate.T=X+u*h.distances.forEntry(c.entry_edge).exit_straight_length;
                    candidate.inside={E,X};candidates.push_back(candidate);
                };
                for(auto E:entries)for(auto X:exits)if(holeNorm(X-E)>1e-8)
                    add(E,X,(X-E)*(1/holeNorm(X-E)));
                for(auto E:entries)for(int sign:{-1,1})
                    for(double degree=config_.angle_step_deg;degree<=config_.max_angle_deg+1e-9;degree+=config_.angle_step_deg) {
                        const double angle=sign*degree*3.14159265358979323846/180;
                        const HolePoint u{d.tangent.x*std::cos(angle)-d.tangent.y*std::sin(angle),
                            d.tangent.x*std::sin(angle)+d.tangent.y*std::cos(angle)};
                        const auto x0=h.geometry.polygon[d.exit_edge_id],v=h.geometry.polygon[(d.exit_edge_id+1)%4]-x0;
                        const double den=holeCross(u,v);if(std::abs(den)<1e-9)continue;
                        const double distance=holeCross(x0-E,v)/den,fraction=holeCross(x0-E,u)/den;
                        if(distance>0&&fraction>1e-6&&fraction<1-1e-6)add(E,E+u*distance,u);
                    }
            }
        }
        if(config_.mode==HolePassageMode::Free&&seed_path.valid&&!h.crossings.empty()) {
            const auto reference=freeHoleCandidate(h.geometry,h.distances,seed_path,h.crossings.front());
            std::stable_sort(candidates.begin(),candidates.end(),[&](const auto &a,const auto &b) {
                return holeNorm(a.E-reference.E)+holeNorm(a.X-reference.X)<holeNorm(b.E-reference.E)+holeNorm(b.X-reference.X);
            });
        }
        int accepted=0;
        const int hole_budget=std::max(1,std::min(config_.max_candidates,
            int((config_.graph_max_nodes-nodes.size())/(holes.size()-hi))));
        for(auto c:candidates) {
            if(Time::now()>=node_deadline||nodes.size()>=static_cast<std::size_t>(config_.graph_max_nodes)||accepted>=hole_budget)break;
            bool direction_allowed=true,exit_only=false;
            for(const auto &commit:commitments)if(commit.hole==hi) {
                if(c.entry_edge!=commit.passage.entry_edge||c.exit_edge!=commit.passage.exit_edge)direction_allowed=false;
                if(commit.entry_line&&(holeNorm(c.E-commit.passage.E)>1e-8||
                    !holeDirectionMatches(c.u_in,commit.passage.u_in,1e-5)))direction_allowed=false;
                if(commit.exit_line) {
                    exit_only=true;
                    if(holeNorm(c.X-commit.passage.X)>1e-8||!holeDirectionMatches(c.u_out,commit.passage.u_out,1e-5))direction_allowed=false;
                }
            }
            if(!direction_allowed)continue;
            if(std::any_of(nodes.begin(),nodes.end(),[&](const auto &n){return n.hole==hi&&
                holeNorm(n.attempt.passage.E-c.E)+holeNorm(n.attempt.passage.X-c.X)+
                holeNorm(n.attempt.passage.u_in-c.u_in)+holeNorm(n.attempt.passage.u_out-c.u_out)<1e-8;}))continue;
            const HoleSegmentCheck inside=[&](HolePoint a,HolePoint b){
                if(!holeContains(h.geometry.polygon,a)||!holeContains(h.geometry.polygon,b))return holeCheck(false,"SIDE_CROSSING",a);
                return collision(a,b);
            };
            const HoleHullCheck hull=[&](const std::vector<HolePoint> &p){
                for(auto q:p)if(!holeContains(h.geometry.polygon,q))return holeCheck(false,"SIDE_CROSSING",q);
                return checkHoleMapHull(map,threshold,p);
            };
            Node n;n.hole=hi;n.manual_range=h.distances.manual_range;n.attempt.manual_range=h.distances.manual_range;n.attempt.passage=c;n.attempt.prepare_distance=h.distances.prepare_distance;
            n.attempt.A=c.E-c.u_in*h.distances.prepare_distance;n.attempt.D=c.X+c.u_out*h.distances.departure_distance;
            if(n.manual_range){n.attempt.A=c.S;n.attempt.D=c.T;}
            n.prepare=!h.distances.manual_range&&config_.mode==HolePassageMode::Centerline?std::optional<HolePoint>{n.attempt.A}:std::nullopt;
            n.departure=!h.distances.manual_range&&!config_.normal_departure&&config_.mode==HolePassageMode::Centerline?std::optional<HolePoint>{n.attempt.D}:std::nullopt;
            n.in=c.S;n.out=c.T;
            const bool start_inside=holeStrictlyInside(h.geometry.polygon,start),goal_inside=holeStrictlyInside(h.geometry.polygon,goal);
            if(start_inside) {
                if(config_.mode==HolePassageMode::Centerline&&std::abs(holeCross(c.u_in,start-c.E))>config_.validation.waypoint_tolerance)continue;
                n.from_start=true;n.in=start;n.prepare.reset();c.E=c.S=start;c.entry_complete=false;
            } else if(holeNorm(start-c.E)>1e-9&&std::abs(holeCross(c.u_in,start-c.E))<1e-8) {
                const double s=holeDot(start-c.E,c.u_in);
                if(s>=-h.distances.forEntry(c.entry_edge).entry_straight_length-1e-8&&s<=1e-8){n.from_start=true;n.in=c.S=start;n.prepare.reset();}
                else if(s>-h.distances.prepare_distance&&s<0)n.prepare.reset();
            }
            if(goal_inside) {
                if(config_.mode==HolePassageMode::Centerline&&std::abs(holeCross(c.u_out,goal-c.X))>config_.validation.waypoint_tolerance)continue;
                n.to_goal=true;n.out=goal;n.departure.reset();c.X=c.T=goal;c.exit_complete=false;
            } else if(std::abs(holeCross(c.u_out,goal-c.X))<1e-8) {
                const double s=holeDot(goal-c.X,c.u_out);
                if(s>=-1e-8&&s<=h.distances.forEntry(c.entry_edge).exit_straight_length+1e-8){n.to_goal=true;n.out=c.T=goal;n.departure.reset();}
                else if(s>=0&&s<h.distances.departure_distance)n.departure.reset();
            }
            if(exit_only) {
                n.exit_only=true;n.from_start=true;n.in=start;n.prepare.reset();
                c.S=c.E=c.X=start;c.entry_complete=c.exit_complete=false;
                if(holeDot(goal-start,c.u_out)>=-1e-8&&holeSegmentDistance(goal,start,c.T)<1e-7) {
                    n.to_goal=true;n.out=c.T=goal;n.departure.reset();
                }
                if(n.departure&&holeDot(*n.departure-start,c.u_out)<=0)n.departure.reset();
            }
            if(!exit_only&&!start_inside&&!goal_inside&&holeDot(c.X-c.E,c.u_in)<=1e-8)continue;
            HoleOptimizedConnection interior;
            if(exit_only) {c.inside={start};interior.points=interior.seed=c.inside;interior.check=holeCheck(true,"REMAINING_EXIT");}
            else if(config_.mode==HolePassageMode::Free) {
                if(start_inside&&start_velocity&&holeNorm(*start_velocity)>config_.min_motion_speed)c.u_in=*start_velocity*(1/holeNorm(*start_velocity));
                else if(start_inside&&seed_path.valid)c.u_in=seed_path.tangent(0,true);
                interior=connect(c.E,c.u_in,{c.X},c.u_out,inside,hull,node_deadline);
                if(!interior.check.valid)continue;c.inside=interior.points;
            } else {c.inside=line(c.E,c.X,config_.search.sample_resolution);interior.points=interior.seed=c.inside;}
            append(n.body,line(c.S,c.E,config_.search.sample_resolution));append(n.body,c.inside);append(n.body,line(c.X,c.T,config_.search.sample_resolution));
            append(n.raw,line(c.S,c.E,config_.search.sample_resolution));append(n.raw,interior.seed);append(n.raw,line(c.X,c.T,config_.search.sample_resolution));
            n.attempt.passage=c;n.attempt.interior=c.inside;n.attempt.maximum_curvature=interior.maximum_curvature;
            n.attempt.optimization_ms=interior.elapsed_ms;n.attempt.expansions=interior.expansions;
            n.attempt.optimized=config_.optimization.enabled;n.attempt.check=holeCheck(true,"PASSAGE_GRAPH_NODE_VALID");
            if(!share(n))continue;
            bool valid=true;for(std::size_t i=1;i<n.body.size();++i)if(!collision(n.body[i-1],n.body[i]).valid)valid=false;
            if(!valid)continue;
            for(std::size_t other=0;other<holes.size();++other)
                if(std::find(n.holes.begin(),n.holes.end(),other)==n.holes.end())
                for(std::size_t i=1;i<n.body.size();++i){double lo,up;if(holeClip(holes[other].geometry.polygon,n.body[i-1],n.body[i],lo,up))valid=false;}
            if(!valid)continue;
            // Independently validate this fixed passage, including legitimate endpoint clipping.
            const auto body_path=HolePathPolyline(n.body);
            for(auto id:n.holes) {
                const auto &other=holes[id];const auto crossings=holePathCrossings(other.geometry,body_path);
                if(n.exit_only&&id==hi&&crossings.empty())continue;
                if(crossings.size()!=1||!validateHolePathPassage(other.geometry,other.distances,config_.validation,
                    body_path,crossings.front(),config_.mode,collision,nullptr,true).valid)valid=false;
            }
            if(!valid)continue;
            n.cost=score(n.body);nodes.push_back(n);++accepted;
            if(config_.mode==HolePassageMode::Centerline&&!h.distances.manual_range&&config_.search_prepare_distance&&n.prepare&&holeNorm(*n.prepare-n.attempt.A)<1e-8) {
                std::vector<double> alternatives;
                for(double distance=config_.prepare_min;distance<=config_.prepare_max+1e-9;distance+=config_.prepare_step)
                    if(distance>=h.distances.forEntry(c.entry_edge).entry_straight_length&&std::abs(distance-h.distances.prepare_distance)>1e-8)alternatives.push_back(distance);
                std::stable_sort(alternatives.begin(),alternatives.end(),[&](double a,double b){
                    return std::abs(a-h.distances.prepare_distance)<std::abs(b-h.distances.prepare_distance);
                });
                for(double distance:alternatives) {
                    if(accepted>=hole_budget||nodes.size()>=static_cast<std::size_t>(config_.graph_max_nodes))break;
                    auto alternative=n;alternative.attempt.prepare_distance=distance;
                    alternative.attempt.A=c.E-c.u_in*distance;alternative.prepare=alternative.attempt.A;
                    for(auto &attempt:alternative.shared)if(attempt.passage.hole_id==h.geometry.id) {
                        attempt.A=alternative.attempt.A;attempt.prepare_distance=distance;
                    }
                    if(!outside(*alternative.prepare,*alternative.prepare).valid)continue;
                    nodes.push_back(std::move(alternative));++accepted;
                }
            }
        }
    }
    statistics_.candidate_ms=std::max(0.0,std::chrono::duration<double,std::milli>(Time::now()-candidate_begin).count()-
        (statistics_.connection_search_ms+statistics_.curve_fit_ms+statistics_.curve_validation_ms-candidate_work_before));
    statistics_.candidates=nodes.size();
    struct Edge {bool tried=false;HoleOptimizedConnection connection;double cost=0;};
    std::map<std::pair<int,int>,Edge> edges;
    const int target=nodes.size();
    const auto edge=[&](int from,int to,Deadline until)->Edge& {
        auto &e=edges[{from,to}];if(e.tried)return e;e.tried=true;
        if(Time::now()>=until){e.tried=false;e.connection.check=holeCheck(false,"GRAPH_TIMEOUT");return e;}
        const HolePoint a=from<0?start:nodes[from].out,b=to==target?goal:nodes[to].in;
        if(from<0&&to<target&&nodes[to].from_start) {
            if(holeNorm(a-b)<1e-8){e.connection.points=e.connection.seed={a};e.connection.check=holeCheck(true,"REMAINING_ENTRY");return e;}
        }
        if(from>=0&&nodes[from].to_goal&&to==target) {
            if(holeNorm(a-b)<1e-8){e.connection.points=e.connection.seed={a};e.connection.check=holeCheck(true,"REMAINING_EXIT");return e;}
        }
        if((from>=0&&nodes[from].to_goal)||(to<target&&nodes[to].from_start))return e;
        std::vector<HolePoint> waypoints;
        if(from>=0&&nodes[from].departure)waypoints.push_back(*nodes[from].departure);
        if(to<target&&nodes[to].prepare)waypoints.push_back(*nodes[to].prepare);
        waypoints.push_back(b);
        HolePoint previous=a;
        for(auto p:waypoints) {
            const auto check=outside(p,p);
            if(!check.valid){e.connection.check=check;return e;}
            if(!connectivity.connected(previous,p)){++statistics_.connectivity_rejected;e.connection.check=holeCheck(false,"CONNECTION_DISCONNECTED",p);return e;}
            previous=p;
        }
        std::string cache_key;
        if(config_.cache_enabled&&from>=0&&to<target&&!nodes[from].from_start&&!nodes[to].to_goal) {
            std::ostringstream key;key<<std::setprecision(17)<<terrain_revision_<<' '<<configuration_revision_<<' '
                <<map.header.frame_id<<' '<<map.info.width<<' '<<map.info.height<<' '<<map.info.resolution<<' '
                <<map.info.origin.position.x<<' '<<map.info.origin.position.y<<' '<<map.info.origin.position.z<<' '
                <<map.info.origin.orientation.x<<' '<<map.info.origin.orientation.y<<' '<<map.info.origin.orientation.z<<' '
                <<map.info.origin.orientation.w<<' '<<threshold<<' '<<a.x<<' '<<a.y<<' '
                <<nodes[from].attempt.passage.u_out.x<<' '<<nodes[from].attempt.passage.u_out.y<<' '
                <<nodes[to].attempt.passage.u_in.x<<' '<<nodes[to].attempt.passage.u_in.y;
            for(auto p:waypoints)key<<' '<<p.x<<' '<<p.y;
            cache_key=key.str();
            HoleTimingScope timer(statistics_.cache_lookup_ms);
            auto cached=std::find_if(connection_cache_.begin(),connection_cache_.end(),[&](const auto &entry){return entry.first==cache_key;});
            if(cached!=connection_cache_.end()) {
                bool valid=Time::now()<until;
                if(!cached->second.spans.empty()) {
                    std::vector<HolePoint> checked;double curvature=0;
                    valid=valid&&validateHoleCurve(cached->second.spans,outside_hull,config_.search.sample_resolution,
                        config_.optimization.enforce_max_curvature?std::optional<double>{config_.search.max_curvature}:std::nullopt,
                        until,checked,curvature).valid;
                }
                for(std::size_t i=1;valid&&i<cached->second.points.size();++i)
                    valid=Time::now()<until&&outside(cached->second.points[i-1],cached->second.points[i]).valid;
                if(valid) {
                    e.connection=cached->second;e.cost=score(e.connection.points);e.connection.cost=e.cost;
                    if(std::isfinite(e.cost)) {
                        ++statistics_.cache_hits;connection_cache_.splice(connection_cache_.begin(),connection_cache_,cached);return e;
                    }
                }
                ++statistics_.cache_rejected;connection_cache_.erase(cached);
            }
        }
        if(from>=0&&to==target&&(config_.normal_departure||nodes[from].manual_range))
            e.connection=normalDeparture(a,nodes[from].attempt.passage.u_out,b,map,threshold,outside,outside_hull,until);
        else if(config_.feasible_approach&&to<target) {
            std::optional<HolePoint> initial;
            if(from>=0)initial=nodes[from].attempt.passage.u_out;
            else if(start_velocity&&holeNorm(*start_velocity)>config_.min_motion_speed)initial=*start_velocity;
            e.connection=planFeasibleHoleApproach(a,waypoints,initial,nodes[to].attempt.passage.u_in,
                config_.optimization,config_.search,map,outside,outside_hull,distance_query_,until);
            ++statistics_.optimized_edges;
            statistics_.connection_search_ms+=e.connection.seed_search_ms;
            statistics_.curve_fit_ms+=e.connection.curve_fit_ms;
            statistics_.curve_validation_ms+=e.connection.curve_validation_ms;
            statistics_.fits+=e.connection.fits;
            statistics_.iterations+=e.connection.iterations;
        }
        else if(from>=0)e.connection=connect(a,nodes[from].attempt.passage.u_out,waypoints,
            to<target?std::optional<HolePoint>{nodes[to].attempt.passage.u_in}:std::nullopt,outside,outside_hull,until);
        else {
            // Reverse generation fixes S's tangent while allowing a stationary start to choose its own direction.
            std::reverse(waypoints.begin(),waypoints.end());waypoints.erase(waypoints.begin());waypoints.push_back(a);
            std::optional<HolePoint> reverse_motion;
            if(start_velocity&&holeNorm(*start_velocity)>config_.min_motion_speed)reverse_motion=*start_velocity*(-1/holeNorm(*start_velocity));
            e.connection=connect(b,nodes[to].attempt.passage.u_in*-1,waypoints,reverse_motion,outside,outside_hull,until);
            std::reverse(e.connection.points.begin(),e.connection.points.end());std::reverse(e.connection.seed.begin(),e.connection.seed.end());
        }
        if(e.connection.check.valid) {
            e.cost=score(e.connection.points);
            if(!cache_key.empty()&&std::isfinite(e.cost)) {
                connection_cache_.push_front({cache_key,e.connection});
                while(connection_cache_.size()>static_cast<std::size_t>(config_.cache_max_entries))connection_cache_.pop_back();
            }
        } else {
            ++statistics_.failed_edges;
            if(e.connection.check.reason.find("TIMEOUT")!=std::string::npos) {
                ++statistics_.timeout_edges;e.tried=false; // 超时不是永久不可达。
            }
        }
        return e;
    };
    const auto assemble=[&](const std::vector<int> &chain,const Edge &last) {
        std::vector<HolePoint> points,raw;std::vector<HoleRouteAttempt> attempts;int previous=-1;double deviation=0;
        for(int id:chain) {
            auto attempt=nodes[id].attempt;const auto &connection=edges.at({previous,id}).connection;
            append(points,connection.points);append(points,nodes[id].body);append(raw,connection.seed);append(raw,nodes[id].raw);
            attempt.approach=connection.points;attempt.seed=connection.seed;append(attempt.seed,nodes[id].raw);
            attempt.approach_method=connection.check.reason;
            attempt.approach_smoothing_failure=connection.smoothing_failure;
            attempt.points=points;attempt.path_length=length(points);attempt.seed_length=length(attempt.seed);
            attempt.maximum_curvature=std::max(attempt.maximum_curvature,connection.maximum_curvature);
            attempt.optimization_ms+=connection.elapsed_ms;attempt.expansions+=connection.expansions;
            attempt.check=holeCheck(true,"ROUTE_VALID");
            if(nodes[id].shared.empty())attempts.push_back(attempt);
            else {
                auto shared=nodes[id].shared;shared.front().approach=connection.points;shared.front().approach_method=connection.check.reason;
                shared.front().approach_smoothing_failure=connection.smoothing_failure;
                for(auto &a:shared){a.points=points;a.seed=raw;a.path_length=length(points);a.seed_length=length(raw);}
                attempts.insert(attempts.end(),shared.begin(),shared.end());
            }
            previous=id;
            deviation+=config_.prepare_deviation_weight*std::abs(attempt.prepare_distance-holes[nodes[id].hole].distances.prepare_distance);
        }
        append(points,last.connection.points);append(raw,last.connection.seed);
        if(!attempts.empty()) {attempts.back().departure=last.connection.points;attempts.back().points=points;
            attempts.back().path_length=length(points);attempts.back().seed_length=length(raw);attempts.back().seed=raw;}
        retain(points,raw,attempts,deviation);
    };
    // First try to complete the seed's whole passage order. Preparation alternatives
    // must not consume the budget before we ever attempt the second passage.
    struct SeedPassage {std::size_t hole;HolePathCrossing crossing;};
    std::vector<SeedPassage> ordered;
    for(std::size_t h=0;h<holes.size();++h)for(const auto &c:holes[h].crossings)ordered.push_back({h,c});
    std::stable_sort(ordered.begin(),ordered.end(),[](const auto &a,const auto &b){return a.crossing.entry_arc<b.crossing.entry_arc;});
    const auto seed_deadline=std::min(deadline,begin+std::chrono::duration_cast<Time::duration>(std::chrono::duration<double>(config_.planning_timeout*0.65)));
    int seed_expanded=0;
    std::function<bool(std::vector<int>,std::vector<std::size_t>)> complete_seed;
    complete_seed=[&](std::vector<int> chain,std::vector<std::size_t> used) {
        if(Time::now()>=seed_deadline||seed_expanded>=config_.graph_max_expansions/2)return false;
        const auto next=std::find_if(ordered.begin(),ordered.end(),[&](const auto &v){return std::find(used.begin(),used.end(),v.hole)==used.end();});
        const int from=chain.empty()?-1:chain.back();
        if(next==ordered.end()) {
            if(from<0)return false;
            const auto &finish=edge(from,target,seed_deadline);
            if(!finish.connection.check.valid)return false;
            assemble(chain,finish);return !best_points.empty();
        }
        std::vector<int> choices;
        for(int id=0;id<target;++id) {
            if(std::find(nodes[id].holes.begin(),nodes[id].holes.end(),next->hole)==nodes[id].holes.end()||
               used.size()+nodes[id].holes.size()>static_cast<std::size_t>(config_.graph_max_passages)||
               std::any_of(nodes[id].holes.begin(),nodes[id].holes.end(),[&](auto h){return std::find(used.begin(),used.end(),h)!=used.end();}))continue;
            bool compatible=true;
            const auto &attempts=nodes[id].shared.empty()?std::vector<HoleRouteAttempt>{nodes[id].attempt}:nodes[id].shared;
            for(const auto &attempt:attempts)for(const auto &v:ordered)if(attempt.passage.hole_id==holes[v.hole].geometry.id) {
                const auto &c=v.crossing;
                if((c.entry_edge>=0&&c.entry_edge!=attempt.passage.entry_edge)||(c.exit_edge>=0&&c.exit_edge!=attempt.passage.exit_edge))compatible=false;
            }
            if(compatible)choices.push_back(id);
        }
        const auto preference=[&](int id) {
            const auto &n=nodes[id];double value=std::abs(n.attempt.prepare_distance-holes[n.hole].distances.prepare_distance);
            if(config_.mode==HolePassageMode::Free)value+=holeNorm(n.attempt.passage.E-seed_path.at(next->crossing.entry_arc))+
                holeNorm(n.attempt.passage.X-seed_path.at(next->crossing.exit_arc));
            return value;
        };
        std::stable_sort(choices.begin(),choices.end(),[&](int a,int b){return preference(a)<preference(b);});
        for(int id:choices) {
            if(Time::now()>=seed_deadline||seed_expanded>=config_.graph_max_expansions/2)break;
            ++seed_expanded;const auto &connection=edge(from,id,seed_deadline);if(!connection.connection.check.valid)continue;
            auto following=chain;following.push_back(id);auto covered=used;covered.insert(covered.end(),nodes[id].holes.begin(),nodes[id].holes.end());
            if(complete_seed(std::move(following),std::move(covered)))return true;
        }
        return false;
    };
    if(best_cost>holeNorm(goal-start)+1e-8&&!ordered.empty())complete_seed({},{});
    if(config_.responsive&&Time::now()<deadline)try_bypass();
    struct State {double lower=0,cost=0;int current=-1;std::vector<int> chain;int pending=-1;};
    const auto cmp=[](const State &a,const State &b){return a.lower>b.lower;};
    std::priority_queue<State,std::vector<State>,decltype(cmp)> queue(cmp);
    queue.push({holeNorm(goal-start),0,-1,{}});int expanded=0;
    std::vector<State> deferred;
    const auto promote=[&]() {
        std::stable_sort(deferred.begin(),deferred.end(),[](const auto &a,const auto &b){return a.lower<b.lower;});
        const auto count=std::min(deferred.size(),static_cast<std::size_t>(config_.shortlist_size));
        for(std::size_t i=0;i<count;++i)queue.push(std::move(deferred[i]));
        deferred.erase(deferred.begin(),deferred.begin()+count);
    };
    while((!queue.empty()||!deferred.empty())&&expanded<config_.graph_max_expansions&&Time::now()<deadline) {
        if(queue.empty())promote();
        const double frontier_lower=std::min(queue.top().lower,deferred.empty()?std::numeric_limits<double>::infinity():
            std::min_element(deferred.begin(),deferred.end(),[](const auto &a,const auto &b){return a.lower<b.lower;})->lower);
        if(config_.responsive&&std::isfinite(best_cost)&&best_cost<=frontier_lower*(1+config_.relative_cost_gap)+1e-8) {
            statistics_.stop_reason="QUALITY_ACCEPTED";break;
        }
        auto state=queue.top();queue.pop();if(state.lower>=best_cost-1e-8)continue;++expanded;
        if(state.pending>=0) {
            const int id=state.pending;const auto &connection=edge(state.current,id,deadline);
            if(!connection.connection.check.valid)continue;
            if(id==target){assemble(state.chain,connection);continue;}
            state.current=id;state.pending=-1;state.chain.push_back(id);
            state.cost+=connection.cost+nodes[id].cost;
            state.lower=state.cost+holeNorm(goal-nodes[id].out);
            if(state.lower<best_cost-1e-8)queue.push(std::move(state));
            continue;
        }
        if(state.current>=0) {
            auto finish=state;finish.pending=target;finish.lower=state.cost+holeNorm(goal-nodes[state.current].out);
            if(finish.lower<best_cost-1e-8)queue.push(std::move(finish));
        }
        std::vector<std::size_t> used;
        for(auto id:state.chain)used.insert(used.end(),nodes[id].holes.begin(),nodes[id].holes.end());
        if(static_cast<int>(used.size())>=config_.graph_max_passages)continue;
        const auto p=state.current<0?start:nodes[state.current].out;
        std::vector<int> next;
        for(int id=0;id<target;++id) {
            if(used.size()+nodes[id].holes.size()>static_cast<std::size_t>(config_.graph_max_passages)||
                std::any_of(nodes[id].holes.begin(),nodes[id].holes.end(),[&](auto h){
                    return std::find(used.begin(),used.end(),h)!=used.end();
                }))continue;
            const double lower=state.cost+holeNorm(nodes[id].in-p)+nodes[id].cost+holeNorm(goal-nodes[id].out);
            if(lower<best_cost-1e-8)next.push_back(id);
        }
        std::stable_sort(next.begin(),next.end(),[&](int a,int b){
            return holeNorm(nodes[a].in-p)+nodes[a].cost+holeNorm(goal-nodes[a].out)<
                   holeNorm(nodes[b].in-p)+nodes[b].cost+holeNorm(goal-nodes[b].out);
        });
        for(int id:next) {
            auto successor=state;successor.pending=id;
            successor.lower=state.cost+holeNorm(nodes[id].in-p)+nodes[id].cost+holeNorm(goal-nodes[id].out);
            if(config_.responsive)deferred.push_back(std::move(successor));
            else queue.push(std::move(successor));
        }
    }
    if(statistics_.stop_reason!="QUALITY_ACCEPTED")statistics_.stop_reason=
        Time::now()>=deadline?(best_points.empty()?"SOLVE_BUDGET_EXHAUSTED":"IMPROVEMENT_BUDGET_EXHAUSTED"):
        expanded>=config_.graph_max_expansions?"EXPANSION_BUDGET_EXHAUSTED":
        (best_points.empty()?"NO_VALID_CANDIDATE":"NO_BETTER_CANDIDATE");
    if(best_points.empty()) {
        int reported=0;
        for(const auto &item:edges)if(!item.second.connection.check.valid&&reported++<12) {
            const auto from=item.first.first,to=item.first.second;
            const auto a=from<0?start:nodes[from].out,b=to==target?goal:nodes[to].in;
            const auto &check=item.second.connection.check;
            RCLCPP_WARN(node_->get_logger(),"洞前接入失败: %s -> %s (%.3f,%.3f)->(%.3f,%.3f) 原因=%s 位置=(%.3f,%.3f)",
                from<0?"start":nodes[from].attempt.passage.hole_id.c_str(),
                to==target?"goal":nodes[to].attempt.passage.hole_id.c_str(),a.x,a.y,b.x,b.y,
                check.reason.c_str(),check.point.x,check.point.y);
        }
        RCLCPP_WARN(node_->get_logger(),"全局过洞失败: nodes=%zu expanded=%d",nodes.size(),expanded);
        path_passages_.clear();publishDiagnostics();
        return holeCheck(false,Time::now()>=deadline?"NO_VALID_HOLE_GRAPH_ROUTE: PLANNING_TIMEOUT":"NO_VALID_HOLE_GRAPH_ROUTE",start);
    }
    route=message(best_points,seed.header);route.header.stamp=node_->now();for(auto &p:route.poses)p.header=route.header;
    HolePassageCheck final;
    {HoleTimingScope timer(statistics_.final_validation_ms);final=validatePath(route,map,threshold,false,hard_deadline);}
    if(!final.valid){statistics_.stop_reason=final.reason;route=nav_msgs::msg::Path();return final;}
    constrained=true;route_attempts_=best_attempts;selected_route_=best_attempts;
    for(const auto &attempt:route_attempts_)if(!attempt.approach_method.empty())
        RCLCPP_INFO(node_->get_logger(),"过洞接入: hole=%s S=(%.3f,%.3f) 方法=%s 平滑后备原因=%s",
            attempt.passage.hole_id.c_str(),attempt.passage.S.x,attempt.passage.S.y,attempt.approach_method.c_str(),
            attempt.approach_smoothing_failure.empty()?"none":attempt.approach_smoothing_failure.c_str());
    if(!path_passages_.empty()||commitments.empty())previous_route_=route;
    if(route_attempts_.empty()&&!path_passages_.empty())for(const auto &c:path_passages_) {
        HoleRouteAttempt attempt;attempt.passage=c;attempt.check=c.check;
        attempt.points=attempt.seed=best_points;attempt.path_length=attempt.seed_length=length(best_points);
        route_attempts_.push_back(std::move(attempt));
    }
    if(route_publisher_)route_publisher_->publish(message(best_seed,route.header));publishDiagnostics();
    RCLCPP_DEBUG(node_->get_logger(),"全局过洞选路: passages=%zu nodes=%zu graph_expanded=%d length=%.3fm cost=%.3f elapsed=%.1fms",
        path_passages_.size(),nodes.size(),expanded+seed_expanded,length(best_points),best_cost,std::chrono::duration<double,std::milli>(Time::now()-begin).count());
    RCLCPP_DEBUG(node_->get_logger(),"过洞分项: geometry=%.1f connectivity=%.1f candidates=%.1f seed_search=%.1f fit=%.1f curve_check=%.1f candidate_check=%.1f final_check=%.1f cache_check=%.1f ms | optimized=%d fits=%d iterations=%d cache_hits=%d cache_rejected=%d disconnected=%d stop=%s",
        statistics_.geometry_ms,statistics_.connectivity_ms,statistics_.candidate_ms,statistics_.connection_search_ms,
        statistics_.curve_fit_ms,statistics_.curve_validation_ms,statistics_.candidate_validation_ms,statistics_.final_validation_ms,
        statistics_.cache_lookup_ms,statistics_.optimized_edges,statistics_.fits,statistics_.iterations,statistics_.cache_hits,
        statistics_.cache_rejected,statistics_.connectivity_rejected,statistics_.stop_reason.c_str());
    return holeCheck(true,path_passages_.empty()?"BYPASS_ROUTE_VALID":"HOLE_GRAPH_ROUTE_VALID");
}
} // namespace nav_components
