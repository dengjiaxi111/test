#include "nav_components/hole_passage_planner.hpp"

namespace nav_components {
using namespace nav_core;
namespace {
constexpr double pi=3.14159265358979323846;
nav_msgs::msg::Path routeMessage(const std::vector<HolePoint> &points,const std_msgs::msg::Header &header) {
    nav_msgs::msg::Path path;path.header=header;
    for(auto p:points) {
        geometry_msgs::msg::PoseStamped pose;pose.header=header;
        pose.pose.position.x=p.x;pose.pose.position.y=p.y;pose.pose.orientation.w=1;
        path.poses.push_back(pose);
    }
    return path;
}
void append(std::vector<HolePoint> &out,const std::vector<HolePoint> &points) {
    for(auto p:points) if(out.empty()||holeNorm(p-out.back())>1e-10) out.push_back(p);
}
std::vector<HolePoint> line(HolePoint a,HolePoint b,double resolution) {
    const int count=std::max(1,static_cast<int>(std::ceil(holeNorm(b-a)/resolution)));
    std::vector<HolePoint> points;
    for(int i=0;i<=count;++i) points.push_back(a+(b-a)*(static_cast<double>(i)/count));
    return points;
}
double pathLength(const std::vector<HolePoint> &points) {
    double result=0;
    for(std::size_t i=1;i<points.size();++i) result+=holeNorm(points[i]-points[i-1]);
    return result;
}
double pathMaximumCurvature(const std::vector<HolePoint> &points) {
    double maximum=0;
    for(std::size_t i=1;i+1<points.size();++i) {
        const auto a=points[i]-points[i-1],b=points[i+1]-points[i];
        const double denominator=holeNorm(a)*holeNorm(b)*holeNorm(points[i+1]-points[i-1]);
        if(denominator>1e-12) maximum=std::max(maximum,2*std::abs(holeCross(a,b))/denominator);
    }
    return maximum;
}
}

HolePassageCheck HolePassagePlanner::planSingleRoute(const nav_msgs::msg::Path &seed,HolePoint start,HolePoint goal,
        const nav_msgs::msg::OccupancyGrid &map,double threshold,nav_msgs::msg::Path &route,bool &constrained,
        std::optional<HolePoint> start_velocity,std::chrono::steady_clock::time_point request_deadline) {
    route=nav_msgs::msg::Path();constrained=false;
    if(!config_.enabled) return holeCheck(true,"HOLE_PLANNER_DISABLED");
    if(!terrain_) return holeCheck(false,"TERRAIN_UNAVAILABLE");
    if(seed.header.frame_id!="map"||(!map.header.frame_id.empty()&&map.header.frame_id!="map"))
        return holeCheck(false,"FRAME_MISMATCH");
    const auto request_check=checkHoleMapSegment(map,threshold,start,start);
    if(!request_check.valid) return request_check;
    const auto goal_check=checkHoleMapSegment(map,threshold,goal,goal);
    if(!goal_check.valid) return goal_check;
    std::vector<HolePoint> seed_points;
    for(const auto &pose:seed.poses) seed_points.push_back({pose.pose.position.x,pose.pose.position.y});
    const HolePathPolyline seed_path(seed_points);
    // 两种模式均由实际 A* 路线触发；无种子时不按距离强行选择洞口。
    if(!seed_path.valid) return holeCheck(false,"ASTAR_SEED_REQUIRED");
    struct Hole {HoleGeometryPreview g;HoleTraversalDistances distances;std::vector<HolePathCrossing> crossings;};
    std::vector<Hole> holes;
    int crossing_count=0;std::size_t selected=0;
    for(const auto &region:terrain_->getRegions()) {
        if(region.type!="low_clearance"&&region.type!="2") continue;
        Hole h;h.g=geometry(region,h.distances,&start);
        if(h.g.reason=="HOLE_DISABLED") continue;
        if(!h.g.geometry_valid) return holeCheck(false,h.g.reason);
        if(holeStrictlyInside(h.g.polygon,start)||holeStrictlyInside(h.g.polygon,goal))
            return holeCheck(false,"PARTIAL_PASSAGE_REQUIRES_LATER_STAGE",start);
        if(seed_path.valid) h.crossings=holePathCrossings(h.g,seed_path);
        if(!h.crossings.empty()) {selected=holes.size();crossing_count+=h.crossings.size();}
        holes.push_back(std::move(h));
    }
    if(crossing_count>1) return holeCheck(false,"MULTIPLE_PASSAGES_REQUIRE_LATER_STAGE");
    if(crossing_count==0) {
        publishDiagnostics();return holeCheck(true,"PATH_VALID_NO_PASSAGE");
    }
    const auto &g=holes[selected].g;const auto distances=holes[selected].distances;
    if(!g.valid) return holeCheck(false,g.reason);
    const auto begin=std::chrono::steady_clock::now();
    const auto hard_deadline=std::min(request_deadline,begin+
        std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::duration<double>(config_.planning_timeout)));
    const auto deadline=begin+(hard_deadline-begin)*9/10;
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,threshold,a,b);};
    const HoleSegmentCheck outside=[&](HolePoint a,HolePoint b) {
        const auto check=collision(a,b);if(!check.valid) return check;
        for(const auto &h:holes) {
            double lo,hi;
            if(holeClip(h.g.polygon,a,b,lo,hi)) return holeCheck(false,"CONNECTION_CROSSES_HOLE",a);
        }
        return holeCheck(true,"OK");
    };
    const HoleSegmentCheck inside=[&](HolePoint a,HolePoint b) {
        if(!holeContains(g.polygon,a)||!holeContains(g.polygon,b)) return holeCheck(false,"SIDE_CROSSING",b);
        return collision(a,b);
    };
    const HoleHullCheck outside_hull=[&](const std::vector<HolePoint> &controls) {
        const auto check=checkHoleMapHull(map,threshold,controls);if(!check.valid) return check;
        for(const auto &h:holes) {
            for(auto p:controls) if(holeStrictlyInside(h.g.polygon,p)) return holeCheck(false,"CONNECTION_CROSSES_HOLE",p);
            for(auto a:controls) for(auto b:controls) {
                double lo,hi;if(holeClip(h.g.polygon,a,b,lo,hi)) return holeCheck(false,"CONNECTION_CROSSES_HOLE",a);
            }
            // Reject a hole entirely enclosed by the curve hull as well as crossing hull edges.
            for(auto p:h.g.polygon) for(std::size_t a=0;a<controls.size();++a)
                for(std::size_t b=a+1;b<controls.size();++b) for(std::size_t c=b+1;c<controls.size();++c) {
                    const double area=holeCross(controls[b]-controls[a],controls[c]-controls[a]);
                    if(std::abs(area)<1e-12) continue;
                    const double sign=area>0?1:-1;
                    if(sign*holeCross(controls[b]-controls[a],p-controls[a])>=0&&
                       sign*holeCross(controls[c]-controls[b],p-controls[b])>=0&&
                       sign*holeCross(controls[a]-controls[c],p-controls[c])>=0)
                        return holeCheck(false,"CONNECTION_CROSSES_HOLE",p);
                }
        }
        return holeCheck(true,"CURVE_HULL_VALID");
    };
    const HoleHullCheck inside_hull=[&](const std::vector<HolePoint> &controls) {
        for(auto p:controls) if(!holeContains(g.polygon,p)) return holeCheck(false,"SIDE_CROSSING",p);
        return checkHoleMapHull(map,threshold,controls);
    };
    const auto connect=[&](HolePoint p,HolePoint tangent,const std::vector<HolePoint> &targets,
            std::optional<HolePoint> final,const HoleSegmentCheck &segments,const HoleHullCheck &hulls) {
        if(config_.optimization.enabled) return optimizeHoleConnection(p,tangent,targets,final,
            config_.optimization,config_.search,map,segments,hulls,distance_query_,deadline);
        const auto legacy=searchHoleConnection(p,tangent,targets,final,config_.search,segments,deadline);
        HoleOptimizedConnection result;result.check=legacy.check;result.points=result.seed=legacy.points;
        result.expansions=legacy.expansions;result.length=result.seed_length=pathLength(result.points);
        result.maximum_curvature=pathMaximumCurvature(result.points);return result;
    };
    std::vector<HolePassageCandidate> passages;
    if(config_.mode==HolePassageMode::Centerline) {
        for(const auto &d:g.directions) passages.push_back(centerlineHoleCandidate(g,d));
        std::stable_sort(passages.begin(),passages.end(),[&](const auto &a,const auto &b) {
            return holeNorm(start-a.S)+holeNorm(goal-a.T)<holeNorm(start-b.S)+holeNorm(goal-b.T);
        });
    } else {
        const auto original=freeHoleCandidate(g,distances,seed_path,holes[selected].crossings.front());
        passages.push_back(original);
        const auto direction=std::find_if(g.directions.begin(),g.directions.end(),[&](const auto &d) {
            return d.entry_edge_id==original.entry_edge&&d.exit_edge_id==original.exit_edge;
        });
        if(direction==g.directions.end()) return holeCheck(false,"INVALID_PASSAGE_EDGES_OR_DIRECTION",original.E);
        const auto positions=[&](int edge,HolePoint reference) {
            const auto a=g.polygon[edge],v=g.polygon[(edge+1)%4]-a;
            const double length=holeNorm(v),f=holeDot(reference-a,v)/(length*length);
            std::vector<HolePoint> result{reference};
            // 排除角点，保留原始进出位置，再沿通行边双向搜索。
            const int count=static_cast<int>(std::min(128.0,std::ceil(length/config_.edge_step)));
            for(int k=1;k<=count;++k) for(int sign:{-1,1}) {
                const double t=f+sign*k*config_.edge_step/length;
                if(t>1e-6&&t<1-1e-6) result.push_back(a+v*t);
            }
            result.push_back(a+v*0.5);return result;
        };
        const auto entries=positions(original.entry_edge,original.E),exits=positions(original.exit_edge,original.X);
        const auto add=[&](HolePoint E,HolePoint X,HolePoint u) {
            if(holeNorm(X-E)<1e-9) return;
            HolePassageCandidate c=original;c.E=E;c.X=X;c.u_in=c.u_out=u;
            c.S=E-u*distances.forEntry(c.entry_edge).entry_straight_length;c.T=X+u*distances.forEntry(c.entry_edge).exit_straight_length;
            c.inside={E,X};passages.push_back(std::move(c));
        };
        for(auto E:entries) for(auto X:exits) add(E,X,(X-E)*(1/holeNorm(X-E)));
        for(auto E:entries) for(double degree=-config_.max_angle_deg;degree<=config_.max_angle_deg+1e-9;degree+=config_.angle_step_deg) {
            const double a=degree*pi/180;const auto t=direction->tangent;
            const HolePoint u{t.x*std::cos(a)-t.y*std::sin(a),t.x*std::sin(a)+t.y*std::cos(a)};
            const auto x0=g.polygon[original.exit_edge],v=g.polygon[(original.exit_edge+1)%4]-x0;
            const double den=holeCross(u,v);if(std::abs(den)<1e-9) continue;
            const double distance=holeCross(x0-E,v)/den,fraction=holeCross(x0-E,u)/den;
            if(distance>0&&fraction>1e-6&&fraction<1-1e-6) add(E,E+u*distance,u);
        }
        const auto cost=[&](const HolePassageCandidate &c) {
            return holeNorm(c.E-original.E)+holeNorm(c.X-original.X)+
                0.1*(1-holeDot(c.u_in,original.u_in)+1-holeDot(c.u_out,original.u_out));
        };
        std::stable_sort(passages.begin(),passages.end(),[&](const auto &a,const auto &b){return cost(a)<cost(b);});
        std::vector<HolePassageCandidate> unique;
        for(const auto &c:passages) {
            if(std::any_of(unique.begin(),unique.end(),[&](const auto &v) {
                return holeNorm(c.E-v.E)+holeNorm(c.X-v.X)+holeNorm(c.u_in-v.u_in)+holeNorm(c.u_out-v.u_out)<1e-8;
            })) continue;
            unique.push_back(c);if(unique.size()==static_cast<std::size_t>(config_.max_candidates)) break;
        }
        passages=std::move(unique);
    }
    std::vector<double> prepare_distances{distances.prepare_distance};
    if(config_.mode==HolePassageMode::Centerline&&!distances.manual_range&&config_.search_prepare_distance) {
        std::vector<double> extra;
        const int count=static_cast<int>(std::floor((config_.prepare_max-config_.prepare_min)/config_.prepare_step+1e-9));
        for(int i=0;i<=count;++i) {
            const double distance=config_.prepare_min+i*config_.prepare_step;
            if(distance>=0&&std::abs(distance-distances.prepare_distance)>1e-9) extra.push_back(distance);
        }
        std::stable_sort(extra.begin(),extra.end(),[&](double a,double b) {
            return std::abs(a-distances.prepare_distance)<std::abs(b-distances.prepare_distance);
        });
        prepare_distances.insert(prepare_distances.end(),extra.begin(),extra.end());
    }
    std::optional<HolePoint> reverse_motion;
    if(start_velocity&&holeFinite(*start_velocity)&&holeNorm(*start_velocity)>config_.min_motion_speed)
        reverse_motion=*start_velocity*(-1/holeNorm(*start_velocity));
    const auto record=[&](HoleRouteAttempt attempt) {
        RCLCPP_INFO(node_->get_logger(),"过洞搜索: hole=%s edges=%d->%d prepare=%.2fm expansions=%d seed=%.3fm length=%.3fm max_k=%.3f opt_ms=%.2f optimized=%s result=%s @ (%.3f, %.3f)",
            attempt.passage.hole_id.c_str(),attempt.passage.entry_edge,attempt.passage.exit_edge,
            attempt.prepare_distance,attempt.expansions,attempt.seed_length,attempt.path_length,attempt.maximum_curvature,attempt.optimization_ms,
            attempt.optimized?"true":"false",attempt.check.reason.c_str(),attempt.check.point.x,attempt.check.point.y);
        route_attempts_.push_back(std::move(attempt));
    };
    for(auto c:passages) for(double prepare:prepare_distances) {
        if(!distances.manual_range&&prepare<distances.forEntry(c.entry_edge).entry_straight_length)continue;
        HoleRouteAttempt attempt;attempt.manual_range=distances.manual_range;attempt.passage=c;attempt.prepare_distance=prepare;
        std::vector<HolePoint> interior_seed=c.inside;
        if(config_.mode==HolePassageMode::Centerline) {
            attempt.A=c.E-c.u_in*prepare;attempt.D=c.X+c.u_out*distances.departure_distance;
        }
        const auto fail=[&](const std::string &stage,HolePassageCheck check) {
            check.reason=stage+": "+check.reason;attempt.check=check;record(attempt);
        };
        if(std::chrono::steady_clock::now()>=deadline) {
            fail("ROUTE",holeCheck(false,"PLANNING_TIMEOUT"));publishDiagnostics();
            return holeCheck(false,"NO_VALID_HOLE_ROUTE: PLANNING_TIMEOUT");
        }
        if(config_.mode==HolePassageMode::Centerline&&!distances.manual_range) {
            const auto check=outside(attempt.A,attempt.A);
            if(!check.valid) {fail("PREPARE_POINT_UNREACHABLE",check);continue;}
            if(!config_.normal_departure) {
                const auto departure_check=outside(attempt.D,attempt.D);
                if(!departure_check.valid) {fail("DEPARTURE_POINT_UNREACHABLE",departure_check);continue;}
            }
        }
        if(config_.mode==HolePassageMode::Free) {
            // 先校验洞外直线，再为进出运动方向生成洞内种子。
            auto check=collision(c.S,c.E);if(check.valid) check=collision(c.X,c.T);
            if(!check.valid) {fail("STRAIGHT_SEGMENT_BLOCKED",check);continue;}
            const auto interior=connect(c.E,c.u_in,{c.X},c.u_out,inside,inside_hull);
            attempt.expansions+=interior.expansions;
            if(!interior.check.valid) {attempt.points=interior.points;fail("INSIDE_CONNECTION_FAILED",interior.check);continue;}
            c.inside=interior.points;attempt.passage=c;
            interior_seed=interior.seed;
            attempt.seed_length+=interior.seed_length;attempt.optimization_ms+=interior.elapsed_ms;
            attempt.maximum_curvature=std::max(attempt.maximum_curvature,interior.maximum_curvature);
        }
        auto candidate_distances=distances;candidate_distances.prepare_distance=prepare;
        const auto check=validateHoleCandidate(g,candidate_distances,config_.validation,c,collision);
        if(!check.valid) {fail("PASSAGE",check);continue;}
        std::vector<HolePoint> approach_targets;
        if(config_.mode==HolePassageMode::Centerline&&!distances.manual_range) approach_targets.push_back(attempt.A);
        HoleOptimizedConnection approach;
        if(config_.feasible_approach) {
            approach_targets.push_back(c.S);
            std::optional<HolePoint> initial;
            if(start_velocity&&holeNorm(*start_velocity)>config_.min_motion_speed)initial=*start_velocity;
            approach=planFeasibleHoleApproach(start,approach_targets,initial,c.u_in,config_.optimization,
                config_.search,map,outside,outside_hull,distance_query_,deadline);
        } else {
            approach_targets.push_back(start);
            approach=connect(c.S,c.u_in*-1,approach_targets,reverse_motion,outside,outside_hull);
            std::reverse(approach.points.begin(),approach.points.end());
            std::reverse(approach.seed.begin(),approach.seed.end());
        }
        attempt.expansions+=approach.expansions;
        attempt.points=approach.points;
        if(!approach.check.valid) {fail("APPROACH_CONNECTION_FAILED",approach.check);continue;}
        attempt.approach_method=approach.check.reason;
        attempt.approach_smoothing_failure=approach.smoothing_failure;
        std::vector<HolePoint> departure_targets;
        if(!distances.manual_range&&!config_.normal_departure&&config_.mode==HolePassageMode::Centerline) departure_targets.push_back(attempt.D);
        departure_targets.push_back(goal);
        auto departure=(config_.normal_departure||distances.manual_range)?normalDeparture(c.T,c.u_out,goal,map,threshold,outside,outside_hull,deadline):
            connect(c.T,c.u_out,departure_targets,std::nullopt,outside,outside_hull);
        attempt.expansions+=departure.expansions;
        if(!departure.check.valid) {attempt.points=departure.points;fail("EXIT_CONNECTION_FAILED",departure.check);continue;}
        attempt.points=approach.points;
        append(attempt.points,line(c.S,c.E,config_.search.sample_resolution));
        append(attempt.points,c.inside);
        append(attempt.points,line(c.X,c.T,config_.search.sample_resolution));
        append(attempt.points,departure.points);
        attempt.approach=approach.points;attempt.departure=departure.points;attempt.interior=c.inside;
        attempt.seed=approach.seed;
        append(attempt.seed,line(c.S,c.E,config_.search.sample_resolution));
        append(attempt.seed,interior_seed);append(attempt.seed,line(c.X,c.T,config_.search.sample_resolution));
        append(attempt.seed,departure.seed);
        attempt.seed_length=pathLength(attempt.seed);
        attempt.optimization_ms+=approach.elapsed_ms+departure.elapsed_ms;
        auto message=routeMessage(attempt.points,seed.header);message.header.stamp=node_->now();
        for(auto &p:message.poses) p.header=message.header;
        const auto final_check=validatePath(message,map,threshold,false,hard_deadline);
        if(!final_check.valid) {fail("FINAL_PATH",final_check);continue;}
        if(path_passages_.size()!=1||path_passages_.front().hole_id!=c.hole_id) {
            fail("FINAL_PATH",holeCheck(false,"UNEXPECTED_PASSAGE"));continue;
        }
        if(config_.mode==HolePassageMode::Free&&!distances.manual_range) {
            const HolePathPolyline path(attempt.points);const auto crossings=holePathCrossings(g,path);
            if(crossings.front().entry_arc+1e-9<distances.prepare_distance||
               (!config_.normal_departure&&path.arc.back()-crossings.front().exit_arc+1e-9<distances.departure_distance)) {
                fail("FINAL_PATH",holeCheck(false,"INSUFFICIENT_PREPARE_OR_DEPARTURE_LENGTH"));continue;
            }
        }
        attempt.path_length=pathLength(attempt.points);
        attempt.maximum_curvature=std::max({attempt.maximum_curvature,approach.maximum_curvature,departure.maximum_curvature});
        attempt.optimized=config_.optimization.enabled;
        if(config_.optimization.enforce_max_curvature && attempt.maximum_curvature>
           config_.search.max_curvature*(1+1e-5)) {
            fail("FINAL_PATH",holeCheck(false,"MAX_CURVATURE_EXCEEDED"));continue;
        }
        attempt.check=holeCheck(true,"ROUTE_VALID");record(attempt);
        RCLCPP_INFO(node_->get_logger(),"过洞接入: hole=%s S=(%.3f,%.3f) 方法=%s 平滑后备原因=%s",
            c.hole_id.c_str(),c.S.x,c.S.y,attempt.approach_method.c_str(),
            approach.smoothing_failure.empty()?"none":approach.smoothing_failure.c_str());
        selected_route_={attempt};constrained=true;route=std::move(message);
        route_publisher_->publish(routeMessage(attempt.seed,route.header));publishDiagnostics();
        statistics_.stop_reason="SINGLE_ROUTE_VALID";return holeCheck(true,"ROUTE_VALID");
    }
    publishDiagnostics();
    return route_attempts_.empty()?holeCheck(false,"NO_PASSAGE_CANDIDATE"):
        holeCheck(false,"NO_VALID_HOLE_ROUTE: "+route_attempts_.back().check.reason,route_attempts_.back().check.point);
}

} // namespace nav_components
