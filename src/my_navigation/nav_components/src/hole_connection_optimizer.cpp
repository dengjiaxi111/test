#include "nav_components/planner/hole_connection_optimizer.hpp"
#include "nav_components/hole_passage_planner.hpp"
#include <Eigen/Dense>
#include <unsupported/Eigen/Splines>
#include <queue>
#include <limits>

namespace nav_components {
using namespace nav_core;
namespace {
using Spline=Eigen::Spline<double,2,3>;
using Matrix=Eigen::MatrixXd;
double length(const std::vector<HolePoint> &p) {
    double value=0;for(std::size_t i=1;i<p.size();++i) value+=holeNorm(p[i]-p[i-1]);return value;
}
HolePoint point(const Eigen::Vector2d &p) {return {p.x(),p.y()};}
Eigen::Vector2d vector(HolePoint p) {return {p.x,p.y};}
void append(std::vector<HolePoint> &out,HolePoint p) {
    if(out.empty()||holeNorm(out.back()-p)>1e-10) out.push_back(p);
}
std::vector<HolePoint> convexHull(std::vector<HolePoint> p) {
    std::sort(p.begin(),p.end(),[](auto a,auto b){return a.x<b.x||(a.x==b.x&&a.y<b.y);});
    p.erase(std::unique(p.begin(),p.end(),[](auto a,auto b){return holeNorm(a-b)<1e-12;}),p.end());
    if(p.size()<3) return p;
    std::vector<HolePoint> h;
    for(auto q:p) {while(h.size()>1&&holeCross(h.back()-h[h.size()-2],q-h.back())<=0) h.pop_back();h.push_back(q);}
    const auto lower=h.size();
    for(int i=static_cast<int>(p.size())-2;i>=0;--i) {
        while(h.size()>lower&&holeCross(h.back()-h[h.size()-2],p[i]-h.back())<=0) h.pop_back();h.push_back(p[i]);
    }
    h.pop_back();return h;
}
bool intersectsCell(const std::vector<HolePoint> &h,double x,double y,double r) {
    for(std::size_t i=0;i<h.size();++i) {
        const auto e=h[(i+1)%h.size()]-h[i];const HolePoint n{-e.y,e.x};
        if(holeNorm(n)<1e-12) continue;
        double lo=std::numeric_limits<double>::infinity(),hi=-lo;
        for(auto q:h) {const double v=holeDot(q,n);lo=std::min(lo,v);hi=std::max(hi,v);}
        double cl=std::numeric_limits<double>::infinity(),ch=-cl;
        for(auto q:std::vector<HolePoint>{{x,y},{x+r,y},{x+r,y+r},{x,y+r}}) {
            const double v=holeDot(q,n);cl=std::min(cl,v);ch=std::max(ch,v);
        }
        if(hi<cl-1e-12||ch<lo-1e-12) return false;
    }
    return true;
}
HolePoint evaluate(const HoleBezierSpan &s,double t,int derivative=0) {
    const auto &b=s.controls;const double u=1-t;
    if(derivative==1) return (b[1]-b[0])*(3*u*u)+(b[2]-b[1])*(6*u*t)+(b[3]-b[2])*(3*t*t);
    if(derivative==2) return (b[2]-b[1]*2+b[0])*(6*u)+(b[3]-b[2]*2+b[1])*(6*t);
    return b[0]*(u*u*u)+b[1]*(3*u*u*t)+b[2]*(3*u*t*t)+b[3]*(t*t*t);
}
std::pair<HoleBezierSpan,HoleBezierSpan> split(const HoleBezierSpan &s) {
    const auto &b=s.controls;
    const auto a=(b[0]+b[1])*0.5,c=(b[1]+b[2])*0.5,d=(b[2]+b[3])*0.5;
    const auto e=(a+c)*0.5,f=(c+d)*0.5,m=(e+f)*0.5;
    return {HoleBezierSpan{{b[0],a,e,m}},HoleBezierSpan{{m,f,d,b[3]}}};
}
struct Seed {std::vector<HolePoint> points;std::vector<double> mandatory;};
bool gridConnection(HolePoint start,HolePoint goal,const nav_msgs::msg::OccupancyGrid &map,
        const HoleSegmentCheck &collision,int budget,std::chrono::steady_clock::time_point deadline,
        std::vector<HolePoint> &out,int &expansions) {
    if(collision(start,goal).valid) {out={start,goal};return true;}
    const auto &m=map.info;const int w=m.width,h=m.height;const double r=m.resolution;
    const auto index=[&](HolePoint p){return std::pair<int,int>{static_cast<int>(std::floor((p.x-m.origin.position.x)/r)),
        static_cast<int>(std::floor((p.y-m.origin.position.y)/r))};};
    const auto xy=[&](int id){return HolePoint{m.origin.position.x+(id%w+0.5)*r,m.origin.position.y+(id/w+0.5)*r};};
    const auto [sx,sy]=index(start);const auto [gx,gy]=index(goal);
    if(sx<0||sy<0||gx<0||gy<0||sx>=w||gx>=w||sy>=h||gy>=h) return false;
    const int source=sy*w+sx,target=gy*w+gx;
    std::vector<double> cost(w*h,std::numeric_limits<double>::infinity());std::vector<int> parent(w*h,-1);
    using Item=std::pair<double,int>;std::priority_queue<Item,std::vector<Item>,std::greater<Item>> queue;
    cost[source]=0;queue.emplace(holeNorm(goal-start),source);
    const int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
    while(!queue.empty()&&expansions<budget&&std::chrono::steady_clock::now()<deadline) {
        const auto [f,id]=queue.top();queue.pop();const auto p=id==source?start:xy(id);
        if(f>cost[id]+holeNorm(goal-p)+1e-8) continue;
        ++expansions;
        if(id==target&&collision(p,goal).valid) {
            std::vector<HolePoint> reverse{goal};for(int v=id;v!=-1;v=parent[v]) append(reverse,v==source?start:xy(v));
            std::reverse(reverse.begin(),reverse.end());out.clear();
            // Visibility shortcuts remove grid zigzags without crossing occupied or unauthorized cells.
            for(std::size_t i=0;i<reverse.size();) {
                append(out,reverse[i]);if(i+1==reverse.size()) break;
                auto next=i+1;for(auto j=reverse.size()-1;j>i+1;--j) if(collision(reverse[i],reverse[j]).valid){next=j;break;}
                i=next;
            }
            return true;
        }
        for(int k=0;k<8;++k) {
            const int nx=id%w+dx[k],ny=id/w+dy[k];if(nx<0||ny<0||nx>=w||ny>=h) continue;
            const int n=ny*w+nx;const auto q=xy(n);
            if(!collision(p,q).valid) continue;
            const double g=cost[id]+holeNorm(q-p);if(g>=cost[n]-1e-9) continue;
            cost[n]=g;parent[n]=id;queue.emplace(g+holeNorm(goal-q),n);
        }
    }
    return false;
}
Eigen::RowVectorXd basis(const Spline::KnotVectorType &knots,int count,double t,int derivative) {
    const auto values=Spline::BasisFunctionDerivatives(t,derivative,3,knots);
    const int span=Spline::Span(t,3,knots);Eigen::RowVectorXd row=Eigen::RowVectorXd::Zero(count);
    for(int j=0;j<4;++j) row[span-3+j]=values(derivative,j);return row;
}
struct Fit {
    Spline::KnotVectorType knots;
    Matrix controls,nullspace,constraints,values;
    std::vector<Matrix> samples;
    std::vector<Eigen::Vector2d> reference;
};
Fit fitSeed(const Seed &seed,HolePoint initial,std::optional<HolePoint> final,
        const HoleConnectionOptimizationParams &params,double handle_scale) {
    const HolePathPolyline poly(seed.points);const double total=poly.arc.back();
    const int constraints=2+2+(final?2:0)+seed.mandatory.size();
    const int count=std::clamp(std::max(constraints+2,static_cast<int>(std::ceil(total/params.control_spacing))+4),8,128);
    Fit fit;fit.knots.resize(count+4);
    for(int i=0;i<count+4;++i) fit.knots[i]=i<4?0:(i>=count?1:static_cast<double>(i-3)/(count-3));
    Matrix a(constraints,count),b(constraints,2);int row=0;
    const auto add=[&](double t,int order,HolePoint value) {
        a.row(row)=basis(fit.knots,count,t,order);b.row(row)=vector(value).transpose();++row;
    };
    add(0,0,seed.points.front());add(1,0,seed.points.back());
    add(0,1,initial*(total*handle_scale/holeNorm(initial)));add(0,2,{0,0});
    if(final) {add(1,1,*final*(total*handle_scale/holeNorm(*final)));add(1,2,{0,0});}
    for(double t:seed.mandatory) add(t,0,poly.at(t*total));
    const auto solver=a.completeOrthogonalDecomposition();fit.controls=solver.solve(b);
    fit.nullspace=a.fullPivLu().kernel();
    if(fit.nullspace.cols()>0) {
        const Matrix orthogonal=fit.nullspace.householderQr().householderQ()*Matrix::Identity(count,fit.nullspace.cols());
        fit.nullspace=orthogonal;
    }
    const int samples=std::clamp(count*3,32,192),rows=samples*(params.enforce_max_curvature?2:1);
    Matrix q(rows,count),reference=Matrix::Zero(rows,2);
    for(int i=0;i<samples;++i) {
        const double t=static_cast<double>(i)/(samples-1);q.row(i)=basis(fit.knots,count,t,0);
        reference.row(i)=vector(poly.at(t*total)).transpose();
        if(params.enforce_max_curvature)
            q.row(samples+i)=std::sqrt(params.curvature_weight)*basis(fit.knots,count,t,2);
    }
    if(fit.nullspace.cols()>0) fit.controls+=fit.nullspace*(q*fit.nullspace).colPivHouseholderQr().solve(reference-q*fit.controls);
    fit.constraints=std::move(a);fit.values=std::move(b);
    const int evaluations=48;
    for(int i=0;i<evaluations;++i) {
        const double t=static_cast<double>(i)/(evaluations-1);Matrix derivatives(4,count);
        for(int j=0;j<4;++j) derivatives.row(j)=basis(fit.knots,count,t,j);
        fit.samples.push_back(std::move(derivatives));fit.reference.push_back(vector(poly.at(t*total)));
    }
    return fit;
}
double objective(const Fit &fit,const Matrix &controls,double scale,const HoleConnectionOptimizationParams &p,
        const HoleDistanceQuery &distance,Matrix *gradient=nullptr) {
    struct Sample {
        Eigen::Matrix<double,4,2> derivatives;
        Eigen::Vector2d position_gradient=Eigen::Vector2d::Zero();
        double speed=0,curvature=0,speed_weight=0,curvature_weight=0;
    };
    std::vector<Sample> samples(fit.samples.size());
    double cost=0;const double dt=1.0/(fit.samples.size()-1);
    if(gradient) gradient->setZero(controls.rows(),2);
    for(std::size_t i=0;i<fit.samples.size();++i) {
        auto &sample=samples[i];sample.derivatives=fit.samples[i]*controls;
        const auto &v=sample.derivatives;const double speed=v.row(1).norm();sample.speed=speed;
        if(!std::isfinite(speed)||speed<scale*1e-8) return std::numeric_limits<double>::infinity();
        const double k=(v(1,0)*v(2,1)-v(1,1)*v(2,0))/(speed*speed*speed);
        sample.curvature=k;
        cost+=p.length_weight*speed*dt/scale+p.curvature_weight*k*k*scale*speed*dt;
        sample.speed_weight=p.length_weight*dt/scale+p.curvature_weight*k*k*scale*dt;
        sample.curvature_weight=2*p.curvature_weight*k*scale*speed*dt;
        if(i) {
            const double delta=k-samples[i-1].curvature,weight=p.curvature_change_weight*scale*scale*scale/dt;
            cost+=weight*delta*delta/speed;
            sample.speed_weight-=weight*delta*delta/(speed*speed);
            sample.curvature_weight+=2*weight*delta/speed;
            samples[i-1].curvature_weight-=2*weight*delta/speed;
        }
        cost+=p.reference_weight*(v.row(0).transpose()-fit.reference[i]).squaredNorm()*dt/(scale*scale);
        sample.position_gradient=2*p.reference_weight*(v.row(0).transpose()-fit.reference[i])*dt/(scale*scale);
        if(distance&&p.obstacle_weight>0) {
            double gx=std::numeric_limits<double>::quiet_NaN(),gy=gx;
            const double d=distance(v(0,0),v(0,1),gradient?&gx:nullptr,gradient?&gy:nullptr);
            if(!std::isfinite(d)) return std::numeric_limits<double>::infinity();
            const double deficit=std::max(0.0,p.safe_distance-d);
            cost+=p.obstacle_weight*deficit*deficit*dt/(scale*scale);
            if(gradient&&deficit>0) {
                // Distance providers without a gradient use only two spatial differences.
                const double epsilon=1e-4*scale;
                if(!std::isfinite(gx)) gx=(distance(v(0,0)+epsilon,v(0,1),nullptr,nullptr)-
                    distance(v(0,0)-epsilon,v(0,1),nullptr,nullptr))/(2*epsilon);
                if(!std::isfinite(gy)) gy=(distance(v(0,0),v(0,1)+epsilon,nullptr,nullptr)-
                    distance(v(0,0),v(0,1)-epsilon,nullptr,nullptr))/(2*epsilon);
                sample.position_gradient-=2*p.obstacle_weight*deficit*dt/(scale*scale)*Eigen::Vector2d{gx,gy};
            }
        }
    }
    if(gradient) for(std::size_t i=0;i<samples.size();++i) {
        const auto &s=samples[i];const auto &v=s.derivatives;
        const Eigen::Vector2d velocity=v.row(1).transpose(),acceleration=v.row(2).transpose();
        const double speed3=s.speed*s.speed*s.speed;
        Eigen::Matrix<double,3,2> local;
        local.row(0)=s.position_gradient.transpose();
        local.row(1)=(s.speed_weight*velocity/s.speed+s.curvature_weight*(
            Eigen::Vector2d{acceleration.y(),-acceleration.x()}/speed3-3*s.curvature*velocity/(s.speed*s.speed))).transpose();
        local.row(2)=(s.curvature_weight*Eigen::Vector2d{-velocity.y(),velocity.x()}/speed3).transpose();
        *gradient+=fit.samples[i].topRows(3).transpose()*local;
    }
    return cost;
}
std::vector<HoleBezierSpan> spans(const Fit &fit,const Matrix &controls,const std::vector<double> &mandatory) {
    const Spline spline(fit.knots,controls.transpose());std::vector<double> cuts{0,1};
    for(auto t:fit.knots) if(t>0&&t<1) cuts.push_back(t);
    cuts.insert(cuts.end(),mandatory.begin(),mandatory.end());std::sort(cuts.begin(),cuts.end());
    cuts.erase(std::unique(cuts.begin(),cuts.end(),[](auto a,auto b){return std::abs(a-b)<1e-10;}),cuts.end());
    std::vector<HoleBezierSpan> result;
    for(std::size_t i=1;i<cuts.size();++i) {
        const auto a=spline.derivatives(cuts[i-1],1),b=spline.derivatives(cuts[i],1);
        const double h=(cuts[i]-cuts[i-1])/3;
        result.push_back({{point(a.col(0)),point(a.col(0)+a.col(1)*h),point(b.col(0)-b.col(1)*h),point(b.col(0))}});
    }
    return result;
}
} // namespace

bool searchHoleGridConnection(HolePoint start,HolePoint goal,const nav_msgs::msg::OccupancyGrid &map,
        const HoleSegmentCheck &collision,int budget,std::chrono::steady_clock::time_point deadline,
        std::vector<HolePoint> &out,int &expansions) {
    if(!collision||!checkHoleMapSegment(map,99,start,start).valid||!checkHoleMapSegment(map,99,goal,goal).valid)
        return false;
    return gridConnection(start,goal,map,collision,budget,deadline,out,expansions);
}

bool validHoleOptimizationParams(const HoleConnectionOptimizationParams &p) {
    if(!std::isfinite(p.approach_smoothing_timeout)||p.approach_smoothing_timeout<0||p.approach_smoothing_timeout>10)return false;
    if(!std::isfinite(p.relative_improvement_tolerance)||p.relative_improvement_tolerance<0||p.relative_improvement_tolerance>1||
       p.stagnation_iterations<1||p.stagnation_iterations>1000)return false;
    if(p.max_iterations<1||p.max_iterations>1000||!std::isfinite(p.control_spacing)||p.control_spacing<0.05||p.control_spacing>2) return false;
    for(double v:{p.length_weight,p.curvature_weight,p.curvature_change_weight,p.obstacle_weight,p.reference_weight,p.safe_distance})
        if(!std::isfinite(v)||v<0||v>10000) return false;
    return p.length_weight>0;
}
HolePassageCheck checkHoleMapHull(const nav_msgs::msg::OccupancyGrid &map,double threshold,const std::vector<HolePoint> &controls) {
    if(controls.empty()) return holeCheck(false,"EMPTY_CURVE_HULL");
    for(auto p:controls) {auto check=checkHoleMapSegment(map,threshold,p,p);if(!check.valid) return check;}
    const auto h=convexHull(controls);const auto &m=map.info;double xmin=h[0].x,xmax=xmin,ymin=h[0].y,ymax=ymin;
    for(auto p:h){xmin=std::min(xmin,p.x);xmax=std::max(xmax,p.x);ymin=std::min(ymin,p.y);ymax=std::max(ymax,p.y);}
    const double r=m.resolution,ox=m.origin.position.x,oy=m.origin.position.y;
    const int x0=std::floor((xmin-ox)/r-1e-9),x1=std::floor((xmax-ox)/r+1e-9);
    const int y0=std::floor((ymin-oy)/r-1e-9),y1=std::floor((ymax-oy)/r+1e-9);
    for(int y=y0;y<=y1;++y) for(int x=x0;x<=x1;++x) {
        if(!intersectsCell(h,ox+x*r,oy+y*r,r)) continue;
        if(x<0||y<0||x>=static_cast<int>(m.width)||y>=static_cast<int>(m.height)) return holeCheck(false,"OUT_OF_MAP");
        const int value=map.data[static_cast<std::size_t>(y)*m.width+x];
        if(value<0||value>=threshold) return holeCheck(false,value<0?"UNKNOWN_CELL":"OCCUPIED_CELL",{ox+(x+0.5)*r,oy+(y+0.5)*r});
    }
    return holeCheck(true,"CURVE_HULL_VALID");
}

HolePassageCheck validateHoleCurve(const std::vector<HoleBezierSpan> &spans,const HoleHullCheck &hull_check,
        double resolution,std::optional<double> maximum_curvature,std::chrono::steady_clock::time_point deadline,
        std::vector<HolePoint> &points,double &observed_curvature) {
    points.clear();observed_curvature=0;
    if(spans.empty()||!hull_check||!std::isfinite(resolution)||resolution<=0) return holeCheck(false,"INVALID_CURVE");
    std::function<HolePassageCheck(const HoleBezierSpan &,int)> visit;
    visit=[&](const HoleBezierSpan &s,int depth)->HolePassageCheck {
        if(std::chrono::steady_clock::now()>=deadline) return holeCheck(false,"CURVE_CHECK_TIMEOUT");
        for(auto p:s.controls) if(!holeFinite(p)) return holeCheck(false,"NONFINITE_CURVE");
        const auto &b=s.controls;const auto hull=hull_check(std::vector<HolePoint>(b.begin(),b.end()));
        const std::array<HolePoint,3> v{{(b[1]-b[0])*3,(b[2]-b[1])*3,(b[3]-b[2])*3}};
        double vx0=v[0].x,vx1=vx0,vy0=v[0].y,vy1=vy0;
        for(auto p:v){vx0=std::min(vx0,p.x);vx1=std::max(vx1,p.x);vy0=std::min(vy0,p.y);vy1=std::max(vy1,p.y);}
        const auto nearest=[](double lo,double hi){return lo>0?lo:(hi<0?-hi:0);};
        const double min_speed=std::hypot(nearest(vx0,vx1),nearest(vy0,vy1));
        double cross_bound=0;
        for(auto derivative:v) for(auto second:std::array<HolePoint,2>{{(b[2]-b[1]*2+b[0])*6,(b[3]-b[2]*2+b[1])*6}})
            cross_bound=std::max(cross_bound,std::abs(holeCross(derivative,second)));
        const double bound=min_speed>1e-14?cross_bound/(min_speed*min_speed*min_speed):std::numeric_limits<double>::infinity();
        double diameter=0;for(auto a:b) for(auto c:b) diameter=std::max(diameter,holeNorm(a-c));
        const bool tangent_cone=holeDirectionMatches(v[0],v[1],1)&&holeDirectionMatches(v[0],v[2],1);
        const bool regular=min_speed>1e-14;
        const bool curvature_valid=!maximum_curvature||bound<=*maximum_curvature*(1+1e-6);
        if(hull.valid&&regular&&curvature_valid&&diameter<=resolution&&tangent_cone) {
            for(double t:{0.0,0.5,1.0}) {
                const auto d=evaluate(s,t,1),dd=evaluate(s,t,2);const double speed=holeNorm(d);
                observed_curvature=std::max(observed_curvature,std::abs(holeCross(d,dd))/(speed*speed*speed));
            }
            append(points,b[0]);append(points,b[3]);return holeCheck(true,"CURVE_VALID");
        }
        if(depth>=20) return !hull.valid?hull:holeCheck(false,regular?"MAX_CURVATURE_EXCEEDED":"DEGENERATE_CURVE",b[0]);
        auto [left,right]=split(s);auto check=visit(left,depth+1);if(!check.valid) return check;return visit(right,depth+1);
    };
    for(std::size_t i=0;i<spans.size();++i) {
        if(i&&(holeNorm(spans[i-1].controls[3]-spans[i].controls[0])>1e-7||
               !holeDirectionMatches(evaluate(spans[i-1],1,1),evaluate(spans[i],0,1),1e-3)))
            return holeCheck(false,"CURVE_SEAM_MISMATCH");
        const auto check=visit(spans[i],0);if(!check.valid) return check;
    }
    return holeCheck(true,"CURVE_VALID");
}

HoleOptimizedConnection optimizeHoleConnection(HolePoint start,HolePoint initial_tangent,
        const std::vector<HolePoint> &requested,std::optional<HolePoint> final_tangent,
        const HoleConnectionOptimizationParams &params,const HoleConnectionSearchParams &search,
        const nav_msgs::msg::OccupancyGrid &map,const HoleSegmentCheck &collision,const HoleHullCheck &hull_check,
        const HoleDistanceQuery &distance,std::chrono::steady_clock::time_point deadline) {
    const auto begin=std::chrono::steady_clock::now();HoleOptimizedConnection result;
    result.check=holeCheck(false,"NO_VALID_CONTINUOUS_CONNECTION");result.cost=std::numeric_limits<double>::infinity();
    if(!validHoleOptimizationParams(params)||!validHoleConnectionSearchParams(search)||!collision||!hull_check||
       !holeFinite(start)||!holeFinite(initial_tangent)||holeNorm(initial_tangent)<1e-9||requested.empty()||
       (final_tangent&&(!holeFinite(*final_tangent)||holeNorm(*final_tangent)<1e-9))) {
        result.check=holeCheck(false,"INVALID_CONNECTION_REQUEST");return result;
    }
    deadline=std::min(deadline,begin+std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::duration<double>(search.timeout)));
    std::vector<HolePoint> targets;
    for(auto p:requested) {
        if(!holeFinite(p)){result.check=holeCheck(false,"INVALID_CONNECTION_REQUEST",p);return result;}
        const auto check=collision(p,p);if(!check.valid){result.check=check;return result;}
        if(targets.empty()||holeNorm(p-targets.back())>1e-8) targets.push_back(p);
    }
    auto check=collision(start,start);if(!check.valid){result.check=check;return result;}
    while(targets.size()>1&&holeNorm(start-targets.front())<1e-8) targets.erase(targets.begin());
    if(targets.size()==1&&holeNorm(start-targets.front())<1e-8) {
        if(final_tangent&&!holeDirectionMatches(initial_tangent,*final_tangent,1e-3)) return result;
        result.points=result.seed={start};result.cost=0;result.check=holeCheck(true,"CONNECTION_VALID");return result;
    }
    // Exact short tangent guards survive the conversion to a published polyline.
    const double guard=std::min(0.002,holeNorm(targets.front()-start)*0.05);
    const auto initial=start+initial_tangent*(guard/holeNorm(initial_tangent));
    check=collision(start,initial);if(!check.valid){result.check=check;return result;}
    const auto finish=targets.back();std::vector<HolePoint> suffix;
    if(final_tangent) {
        const auto before=finish-*final_tangent*(std::min(0.002,holeNorm(finish-initial)*0.05)/holeNorm(*final_tangent));
        check=collision(before,finish);if(!check.valid){result.check=check;return result;}
        targets.back()=before;suffix.push_back(finish);
    }
    std::vector<Seed> seeds;Seed direct;direct.points={initial};
    for(auto p:targets) append(direct.points,p);seeds.push_back(direct);
    bool fallback_generated=false;
    const auto fallback=[&]() {
        fallback_generated=true;const auto seed_begin=std::chrono::steady_clock::now();
        Seed grid;grid.points={initial};
        bool grid_valid=true;
        for(auto p:targets) {
            std::vector<HolePoint> segment;
            if(!gridConnection(grid.points.back(),p,map,collision,search.max_expansions,deadline,segment,result.expansions)){grid_valid=false;break;}
            for(auto q:segment) append(grid.points,q);
        }
        if(grid_valid&&grid.points.size()>1&&grid.points.size()!=direct.points.size()) seeds.push_back(grid);
        // A valid directional seed remains useful when a tight obstacle corridor defeats the 2D fit.
        if(params.enforce_max_curvature&&std::chrono::steady_clock::now()<deadline) {
            auto legacy_search=search;legacy_search.timeout=std::min(search.timeout*0.35,0.2);
            const auto legacy=searchHoleConnection(initial,initial_tangent,targets,final_tangent,legacy_search,collision,deadline);
            result.expansions+=legacy.expansions;
            if(legacy.check.valid) {
                if(params.responsive)seeds.push_back({legacy.points,{}});
                else seeds.insert(seeds.begin(),{legacy.points,{}});
            }
        }
        result.seed_search_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-seed_begin).count();
    };
    if(!params.responsive)fallback();
    double scale=0;HolePoint previous=start;for(auto p:requested){scale+=holeNorm(p-previous);previous=p;}scale=std::max(scale,0.1);
    for(std::size_t seed_index=0;seed_index<seeds.size();++seed_index) {
        auto seed=seeds[seed_index];bool seed_converged=false;
        if(std::chrono::steady_clock::now()>=deadline) break;
        const HolePathPolyline poly(seed.points);if(!poly.valid) continue;
        std::size_t cursor=0;
        for(std::size_t k=0;k+1<targets.size();++k) {
            while(cursor<poly.points.size()&&holeNorm(poly.points[cursor]-targets[k])>1e-7) ++cursor;
            if(cursor<poly.points.size()&&poly.arc[cursor]>1e-8&&poly.arc[cursor]<poly.arc.back()-1e-8)
                seed.mandatory.push_back(poly.arc[cursor]/poly.arc.back());
        }
        for(double handle:{0.5,0.25,1.0}) {
            if(std::chrono::steady_clock::now()>=deadline) break;
            const auto fit_begin=std::chrono::steady_clock::now();
            const double validation_before=result.curve_validation_ms;
            ++result.fits;
            auto fit=fitSeed(seed,initial_tangent,final_tangent,params,handle);auto controls=fit.controls;
            bool converged=fit.nullspace.cols()==0;int stagnant=0;
            double cost=objective(fit,controls,scale,params,distance);
            const auto retain=[&](const Matrix &candidate,double candidate_cost) {
                if(!std::isfinite(candidate_cost)||candidate_cost>=result.cost) return;
                const Matrix residual=fit.constraints*candidate-fit.values;
                if(!candidate.allFinite()||!residual.allFinite()) return;
                for(int row=0;row<residual.rows();++row)
                    if(residual.row(row).norm()>1e-8*(1+fit.values.row(row).norm())) return;
                auto curve=spans(fit,candidate,seed.mandatory);std::vector<HolePoint> points;double curvature=0;
                const auto validation_begin=std::chrono::steady_clock::now();
                const auto check=validateHoleCurve(curve,hull_check,search.sample_resolution,
                    params.enforce_max_curvature?std::optional<double>{search.max_curvature}:std::nullopt,deadline,points,curvature);
                result.curve_validation_ms+=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-validation_begin).count();
                if(!check.valid){result.check=check;return;}
                std::vector<HolePoint> output{start};for(auto p:points) append(output,p);for(auto p:suffix) append(output,p);
                for(std::size_t i=1;i<output.size();++i) if(!collision(output[i-1],output[i]).valid) return;
                result.points=std::move(output);result.spans=std::move(curve);result.seed={start};
                for(auto p:seed.points) append(result.seed,p);for(auto p:suffix) append(result.seed,p);
                result.cost=candidate_cost;result.length=length(result.points);result.seed_length=length(result.seed);
                result.maximum_curvature=curvature;result.check=holeCheck(true,"CONNECTION_VALID");
            };
            retain(controls,cost);
            // Optimize only in the equality-constraint nullspace, so every accepted iterate preserves the waypoints.
            for(int iteration=0;iteration<params.max_iterations&&fit.nullspace.cols()>0&&
                    std::chrono::steady_clock::now()<deadline;++iteration) {
                Matrix full_gradient;
                cost=objective(fit,controls,scale,params,distance,&full_gradient);
                const Matrix gradient=fit.nullspace.transpose()*full_gradient;
                if(!gradient.allFinite())break;
                if(gradient.norm()<1e-4){converged=true;break;}
                const double previous_cost=cost;
                const Matrix direction=fit.nullspace*gradient;bool accepted=false;
                double step=0.1*scale*scale/std::max(1.0,scale*gradient.norm());
                for(int trial=0;trial<20&&std::chrono::steady_clock::now()<deadline;++trial) {
                    Matrix candidate=controls-step*direction;const double next=objective(fit,candidate,scale,params,distance);
                    if(next<cost) {controls=std::move(candidate);cost=next;accepted=true;break;}step*=0.5;
                }
                ++result.iterations;if(!accepted){converged=true;break;}
                const double relative=(previous_cost-cost)/std::max(1.0,std::abs(previous_cost));
                stagnant=relative<=params.relative_improvement_tolerance?stagnant+1:0;
                if(stagnant>=params.stagnation_iterations){converged=true;break;}
                if(iteration%5==0) retain(controls,cost);
            }
            retain(controls,cost);
            result.curve_fit_ms+=std::max(0.0,std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-fit_begin).count()-
                (result.curve_validation_ms-validation_before));
            seed_converged|=converged;
            if(params.responsive&&converged&&!result.points.empty())break;
        }
        if(params.responsive&&seed_converged&&!result.points.empty())break;
        if(!fallback_generated&&seed_index+1==seeds.size())fallback();
    }
    if(!result.points.empty()) result.check=holeCheck(true,"CONNECTION_VALID");
    else if(std::chrono::steady_clock::now()>=deadline) result.check=holeCheck(false,"CONNECTION_OPTIMIZATION_TIMEOUT");
    result.elapsed_ms=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-begin).count();return result;
}
} // namespace nav_components
