#include "nav_components/planner/hole_connection_search.hpp"
#include <ompl/base/ScopedState.h>
#include <ompl/base/spaces/DubinsStateSpace.h>
#include <limits>
#include <queue>
#include <unordered_map>

namespace nav_components {
using namespace nav_core;
namespace {
constexpr double pi=3.14159265358979323846;
double angle(HolePoint p) { return std::atan2(p.y,p.x); }
double wrap(double a) { return std::remainder(a,2*pi); }
struct State {
    HolePoint p;
    double yaw=0, cost=0;
    std::size_t phase=0;
    int parent=-1;
    std::vector<HolePoint> edge;
};
struct Key {
    long long x,y;
    int heading;
    std::size_t phase;
    bool operator==(const Key &o) const {return x==o.x&&y==o.y&&heading==o.heading&&phase==o.phase;}
};
struct Hash {
    std::size_t operator()(const Key &k) const {
        std::size_t h=std::hash<long long>{}(k.x);
        for(auto v:{std::hash<long long>{}(k.y),std::hash<int>{}(k.heading),k.phase})
            h^=v+0x9e3779b9+(h<<6)+(h>>2);
        return h;
    }
};
}
bool validHoleConnectionSearchParams(const HoleConnectionSearchParams &p) {
    return std::isfinite(p.max_curvature)&&p.max_curvature>=0.01&&p.max_curvature<=100&&
        std::isfinite(p.state_resolution)&&p.state_resolution>=0.001&&p.state_resolution<=1&&
        p.heading_bins>=16&&p.heading_bins<=720&&
        std::isfinite(p.primitive_length)&&p.primitive_length>=p.state_resolution&&p.primitive_length<=5&&
        std::isfinite(p.sample_resolution)&&p.sample_resolution>=0.0001&&p.sample_resolution<=p.primitive_length&&
        p.max_expansions>0&&p.max_expansions<=2000000&&std::isfinite(p.timeout)&&p.timeout>0&&p.timeout<=60;
}

HoleConnectionSearchResult searchHoleConnection(HolePoint start,HolePoint initial_tangent,
        const std::vector<HolePoint> &requested_waypoints,const std::optional<HolePoint> &final_tangent,
        const HoleConnectionSearchParams &params,const HoleSegmentCheck &collision,
        std::chrono::steady_clock::time_point deadline) {
    HoleConnectionSearchResult result;
    result.check=holeCheck(false,"CONNECTION_SEARCH_EXHAUSTED",start);
    if(!validHoleConnectionSearchParams(params)||!collision||!holeFinite(start)||
       !holeFinite(initial_tangent)||holeNorm(initial_tangent)<1e-9||requested_waypoints.empty()||
       (final_tangent&&(!holeFinite(*final_tangent)||holeNorm(*final_tangent)<1e-9))) {
        result.check=holeCheck(false,"INVALID_CONNECTION_REQUEST",start);return result;
    }
    std::vector<HolePoint> waypoints;
    for(auto p:requested_waypoints) {
        if(!holeFinite(p)) {result.check=holeCheck(false,"INVALID_CONNECTION_REQUEST",p);return result;}
        const auto check=collision(p,p);
        if(!check.valid) {result.check=check;return result;}
        if(waypoints.empty()||holeNorm(p-waypoints.back())>1e-10) waypoints.push_back(p);
    }
    const auto first_check=collision(start,start);
    if(!first_check.valid) {result.check=first_check;return result;}
    while(waypoints.size()>1&&holeNorm(start-waypoints.front())<1e-10) waypoints.erase(waypoints.begin());
    if(waypoints.size()==1&&holeNorm(start-waypoints.front())<1e-10&&
       (!final_tangent||holeDirectionMatches(initial_tangent,*final_tangent,1e-5))) {
        result.points={start};result.check=holeCheck(true,"CONNECTION_VALID");return result;
    }
    // 留一小段准确切线，避免曲线采样后的首末弦方向偏差破坏零角度容差。
    constexpr double tangent_length=0.005;
    std::vector<HolePoint> prefix{start},suffix;
    const auto initial=start+initial_tangent*(tangent_length/holeNorm(initial_tangent));
    auto tangent_check=collision(start,initial);
    if(!tangent_check.valid) {result.check=tangent_check;return result;}
    prefix.push_back(initial);start=initial;
    if(final_tangent) {
        const auto end=waypoints.back();
        const auto before=end-*final_tangent*(tangent_length/holeNorm(*final_tangent));
        tangent_check=collision(before,end);
        if(!tangent_check.valid) {result.check=tangent_check;return result;}
        waypoints.back()=before;suffix={end};
    }
    deadline=std::min(deadline,std::chrono::steady_clock::now()+
        std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::duration<double>(params.timeout)));
    auto space=std::make_shared<ompl::base::DubinsStateSpace>(1/params.max_curvature,false);
    ompl::base::ScopedState<ompl::base::SE2StateSpace> from(space),to(space),sample(space);
    const auto heuristic=[&](HolePoint p,std::size_t phase) {
        double h=holeNorm(waypoints[phase]-p);
        for(std::size_t i=phase+1;i<waypoints.size();++i) h+=holeNorm(waypoints[i]-waypoints[i-1]);
        return h;
    };
    const auto key=[&](const State &s) {
        const int heading=static_cast<int>(std::llround((wrap(s.yaw)+pi)*params.heading_bins/(2*pi)))%params.heading_bins;
        return Key{std::llround(s.p.x/params.state_resolution),std::llround(s.p.y/params.state_resolution),heading,s.phase};
    };
    std::vector<State> states;
    std::unordered_map<Key,double,Hash> best;
    double solution_cost=std::numeric_limits<double>::infinity();
    int solution_parent=-1;
    std::vector<HolePoint> solution_edge;
    using QueueItem=std::pair<double,int>;
    std::priority_queue<QueueItem,std::vector<QueueItem>,std::greater<QueueItem>> queue;
    const auto push=[&](State state) {
        if(state.cost+heuristic(state.p,state.phase)>=solution_cost-1e-9) return;
        const auto k=key(state);const auto it=best.find(k);
        if(it!=best.end()&&it->second<=state.cost+1e-9) return;
        best[k]=state.cost;states.push_back(std::move(state));
        const int i=static_cast<int>(states.size())-1;
        queue.emplace(states[i].cost+heuristic(states[i].p,states[i].phase),i);
    };
    push({start,angle(initial_tangent),0,0,-1,{start}});
    const auto reconstruct=[&](int id,const std::vector<HolePoint> &last) {
        std::vector<int> chain;
        for(int i=id;i>=0;i=states[i].parent) chain.push_back(i);
        std::reverse(chain.begin(),chain.end());
        result.points.clear();
        const auto append=[&](const std::vector<HolePoint> &points) {
            for(auto p:points) if(result.points.empty()||holeNorm(result.points.back()-p)>1e-10)
                result.points.push_back(p);
        };
        append(prefix);
        for(int i:chain) append(states[i].edge);
        append(last);
    };
    // 采样同时限制弧长和转角，使固定直线连接处的折线切线可靠。
    const double spacing=std::min(params.sample_resolution,0.01/params.max_curvature);
    double frontier=heuristic(start,0);int frontier_id=0;
    while(!queue.empty()&&result.expansions<params.max_expansions) {
        if(queue.top().first>=solution_cost-1e-9) break;
        if(std::chrono::steady_clock::now()>=deadline) {
            result.check=holeCheck(false,"CONNECTION_SEARCH_TIMEOUT",states[frontier_id].p);break;
        }
        const int id=queue.top().second;queue.pop();
        const State current=states[id];
        if(best.at(key(current))<current.cost-1e-9) continue;
        ++result.expansions;
        const double h=heuristic(current.p,current.phase);
        if(h<frontier) {frontier=h;frontier_id=id;}
        const auto target=waypoints[current.phase];
        // 显式抵达每个必经点再推进阶段，禁止只靠栅格邻近宣称经过 A/D。
        if(result.expansions==1||result.expansions%12==0||holeNorm(target-current.p)<params.primitive_length*2) {
            std::vector<double> headings;
            if(current.phase+1==waypoints.size()&&final_tangent) headings.push_back(angle(*final_tangent));
            else {
                headings={angle(target-current.p),current.yaw};
                if(current.phase+1<waypoints.size()) headings.push_back(angle(waypoints[current.phase+1]-target));
                for(int k=0;k<16;++k) headings.push_back(2*pi*k/16);
            }
            struct Shot {double length,yaw;ompl::base::DubinsStateSpace::DubinsPath path;};
            std::vector<Shot> shots;
            from->setXY(current.p.x,current.p.y);from->setYaw(current.yaw);
            for(double yaw:headings) {
                to->setXY(target.x,target.y);to->setYaw(yaw);
                const auto path=space->dubins(from.get(),to.get());
                shots.push_back({path.length()/params.max_curvature,yaw,path});
            }
            std::stable_sort(shots.begin(),shots.end(),[](const auto &a,const auto &b){return a.length<b.length;});
            for(const auto &shot:shots) {
                if(std::chrono::steady_clock::now()>=deadline) break;
                const double remaining=current.phase+1<waypoints.size()?heuristic(target,current.phase+1):0;
                if(current.cost+shot.length+remaining>=solution_cost-1e-9) continue;
                const int count=std::max(1,static_cast<int>(std::ceil(shot.length/spacing)));
                std::vector<HolePoint> edge{current.p};bool valid=true;
                for(int j=1;j<=count;++j) {
                    if(j%128==0&&std::chrono::steady_clock::now()>=deadline) {valid=false;break;}
                    space->interpolate(from.get(),shot.path,static_cast<double>(j)/count,sample.get(),1/params.max_curvature);
                    const HolePoint p=j==count?target:HolePoint{sample->getX(),sample->getY()};
                    if(!collision(edge.back(),p).valid) {valid=false;break;}
                    edge.push_back(p);
                }
                if(!valid) continue;
                if(current.phase+1==waypoints.size()) {
                    // 终端连接只提供候选；继续比较队列中的更短路线，避免首条可行弧线造成绕路。
                    solution_cost=current.cost+shot.length;
                    solution_parent=id;solution_edge=std::move(edge);
                    break;
                }
                push({target,shot.yaw,current.cost+shot.length,current.phase+1,id,std::move(edge)});
            }
        }
        for(double curvature:{0.0,-params.max_curvature,params.max_curvature,
                               -params.max_curvature*0.5,params.max_curvature*0.5}) {
            const int count=static_cast<int>(std::ceil(params.primitive_length/spacing));
            std::vector<HolePoint> edge{current.p};bool valid=true;
            for(int j=1;j<=count;++j) {
                const double length=params.primitive_length*j/count;
                HolePoint p;
                if(std::abs(curvature)<1e-12) p=current.p+HolePoint{std::cos(current.yaw),std::sin(current.yaw)}*length;
                else p=current.p+HolePoint{(std::sin(current.yaw+curvature*length)-std::sin(current.yaw))/curvature,
                    (std::cos(current.yaw)-std::cos(current.yaw+curvature*length))/curvature};
                if(!collision(edge.back(),p).valid) {valid=false;break;}
                edge.push_back(p);
            }
            if(valid) push({edge.back(),wrap(current.yaw+curvature*params.primitive_length),
                current.cost+params.primitive_length,current.phase,id,std::move(edge)});
        }
    }
    if(solution_parent>=0) {
        reconstruct(solution_parent,solution_edge);
        for(auto p:suffix) if(holeNorm(result.points.back()-p)>1e-10) result.points.push_back(p);
        result.check=holeCheck(true,"CONNECTION_VALID");return result;
    }
    reconstruct(frontier_id,{});
    if(result.check.reason=="CONNECTION_SEARCH_EXHAUSTED") result.check.point=states[frontier_id].p;
    return result;
}
} // namespace nav_components
