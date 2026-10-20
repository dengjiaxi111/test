#include "nav_components/hole_passage_planner.hpp"
#include "nav_components/layered_map_manager.hpp"
#include "nav_components/simple_planner.hpp"
#include "nav_components/esdf_map.hpp"
#include "nav_components/planner/normal_navigation_segment.hpp"
#include <nav_core/hole_passage_config.hpp>
#include <tf2_ros/buffer.h>
#include <fstream>
#include <iostream>

using namespace nav_core;
using namespace nav_components;
static void require(bool ok,const std::string &why) {if(!ok) throw std::runtime_error(why);}
static nav_msgs::msg::Path message(const std::vector<HolePoint> &points) {
    nav_msgs::msg::Path path;path.header.frame_id="map";
    for(auto p:points) {geometry_msgs::msg::PoseStamped pose;pose.header=path.header;
        pose.pose.position.x=p.x;pose.pose.position.y=p.y;pose.pose.orientation.w=1;path.poses.push_back(pose);}
    return path;
}
static std::vector<HolePoint> points(const nav_msgs::msg::Path &path) {
    std::vector<HolePoint> result;
    for(const auto &p:path.poses) result.push_back({p.pose.position.x,p.pose.position.y});
    return result;
}
static nav_msgs::msg::OccupancyGrid grid() {
    nav_msgs::msg::OccupancyGrid m;m.header.frame_id="map";m.info.width=m.info.height=200;
    m.info.resolution=0.05;m.info.origin.position.x=m.info.origin.position.y=-5;m.info.origin.orientation.w=1;
    m.data.assign(40000,0);return m;
}
static void occupy(nav_msgs::msg::OccupancyGrid &m,HolePoint p,int value=100) {
    const int x=std::floor((p.x-m.info.origin.position.x)/m.info.resolution);
    const int y=std::floor((p.y-m.info.origin.position.y)/m.info.resolution);
    m.data[y*m.info.width+x]=value;
}
static double curvature(const std::vector<HolePoint> &p) {
    double maximum=0;
    for(std::size_t i=1;i+1<p.size();++i) {
        const auto a=p[i]-p[i-1],b=p[i+1]-p[i];
        const double denominator=holeNorm(a)*holeNorm(b)*holeNorm(p[i+1]-p[i-1]);
        if(denominator>1e-15) maximum=std::max(maximum,2*std::abs(holeCross(a,b))/denominator);
    }
    return maximum;
}
static void searchTests() {
    auto map=grid();HoleConnectionSearchParams params;params.timeout=2;
    // 小障碍只需局部绕行，首个可行终端圆弧不能覆盖更短的连接候选。
    const HoleSegmentCheck small_obstacle=[](HolePoint a,HolePoint b) {
        const HolePoint center{2,0},v=b-a;
        const double length_squared=holeDot(v,v);
        const double t=length_squared>0?std::clamp(holeDot(center-a,v)/length_squared,0.0,1.0):0;
        return holeCheck(holeNorm(a+v*t-center)>0.25,"TEST_OBSTACLE");
    };
    const auto short_detour=searchHoleConnection({0,0},{1,0},{{4,0}},std::nullopt,params,small_obstacle,
        std::chrono::steady_clock::now()+std::chrono::seconds(3));
    const auto witness=searchHoleConnection({0,0},{1,0},{{2,0.6},{4,0}},std::nullopt,params,small_obstacle,
        std::chrono::steady_clock::now()+std::chrono::seconds(3));
    require(short_detour.check.valid&&witness.check.valid,"small obstacle connection failed");
    const double detour_length=HolePathPolyline(short_detour.points).arc.back();
    const double witness_length=HolePathPolyline(witness.points).arc.back();
    std::cout<<"Small obstacle detour: length="<<detour_length<<" witness="<<witness_length<<std::endl;
    require(detour_length<=witness_length+0.1,"first feasible terminal shot selected an unnecessary long detour");
    require(curvature(short_detour.points)<1.02,"shorter connection exceeded curvature bound");
    for(std::size_t i=1;i<short_detour.points.size();++i)
        require(small_obstacle(short_detour.points[i-1],short_detour.points[i]).valid,"shorter connection crossed obstacle");
    auto budget_params=params;budget_params.max_expansions=1;
    const auto budgeted=searchHoleConnection({0,0},{1,0},{{4,0}},std::nullopt,budget_params,small_obstacle,
        std::chrono::steady_clock::now()+std::chrono::seconds(3));
    require(budgeted.check.valid&&holeNorm(budgeted.points.front())<1e-8&&
        holeNorm(budgeted.points.back()-HolePoint{4,0})<1e-8,"search budget discarded a valid complete route");
    // 直线路径被墙阻断，方向搜索必须在墙端绕行，仍准确经过必经点。
    for(double y=-1;y<=1;y+=0.025) occupy(map,{0,y});
    const auto collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,99,a,b);};
    const auto result=searchHoleConnection({-2,0},{1,0},{{1.5,0},{3,0}},HolePoint{1,0},params,collision,
        std::chrono::steady_clock::now()+std::chrono::seconds(3));
    require(result.check.valid,"direction search detour failed: "+result.check.reason);
    require(std::any_of(result.points.begin(),result.points.end(),[](auto p){return holeNorm(p-HolePoint{1.5,0})<1e-8;}),"mandatory point missed");
    for(std::size_t i=1;i<result.points.size();++i) require(collision(result.points[i-1],result.points[i]).valid,"detour collision");
    require(curvature(result.points)<1.02,"motion primitive curvature exceeded");
    params.max_expansions=1;
    const auto limited=searchHoleConnection({-2,0},{1,0},{{3,0}},HolePoint{1,0},params,collision,
        std::chrono::steady_clock::now()+std::chrono::seconds(1));
    require(!limited.check.valid&&!limited.points.empty(),"search budget did not preserve failed frontier");
    std::cout<<"Directional search wall detour: expansions="<<result.expansions<<" curvature="<<curvature(result.points)<<'\n';
}
static void optimizationTests() {
    auto map=grid();HoleConnectionSearchParams search;search.timeout=2;
    HoleConnectionOptimizationParams optimization;
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,99,a,b);};
    const HoleHullCheck hull=[&](const std::vector<HolePoint> &p){return checkHoleMapHull(map,99,p);};
    const auto run=[&](HolePoint start,HolePoint tangent,const std::vector<HolePoint> &targets,
            std::optional<HolePoint> end=std::nullopt) {
        return optimizeHoleConnection(start,tangent,targets,end,optimization,search,map,collision,hull,{},
            std::chrono::steady_clock::now()+std::chrono::seconds(3));
    };
    const auto short_exit=run({0,0},{0,1},{{0,0.2},{1.2,0.25}});
    require(short_exit.check.valid,"short continuous exit failed: "+short_exit.check.reason);
    const auto legacy=searchHoleConnection({0,0},{0,1},{{0,0.2},{1.2,0.25}},std::nullopt,search,collision,
        std::chrono::steady_clock::now()+std::chrono::seconds(3));
    require(legacy.check.valid,"legacy exit comparison failed");
    require(short_exit.length<HolePathPolyline(legacy.points).arc.back()*0.8,"soft curvature did not shorten sideways exit");
    require(short_exit.maximum_curvature>1,"soft connection still enforces 1m radius");
    require(std::any_of(short_exit.points.begin(),short_exit.points.end(),[](auto p){return holeNorm(p-HolePoint{0,0.2})<1e-7;}),"optimized mandatory point missed");
    require(holeDirectionMatches(short_exit.points[1]-short_exit.points[0],{0,1},1e-5),"optimized initial tangent lost");
    for(std::size_t i=1;i<short_exit.points.size();++i) {
        require(collision(short_exit.points[i-1],short_exit.points[i]).valid,"optimized output collision");
        require(holeNorm(short_exit.points[i]-short_exit.points[i-1])<=search.sample_resolution+1e-8,"adaptive output spacing exceeded");
    }
    std::cout<<"Continuous sideways exit: optimized="<<short_exit.length<<" legacy="<<HolePathPolyline(legacy.points).arc.back()
        <<" max_k="<<short_exit.maximum_curvature<<" time_ms="<<short_exit.elapsed_ms<<std::endl;
    optimization.enforce_max_curvature=true;
    const auto hard=run({0,0},{1,0},{{3,0}},HolePoint{1,0});
    require(hard.check.valid&&hard.maximum_curvature<=1.00001,"optional hard curvature check failed");
    const auto hard_turn=run({0,0},{0,1},{{3,3}},HolePoint{1,0});
    require(hard_turn.check.valid&&hard_turn.maximum_curvature<=1.00001,"hard curved connection failed: "+hard_turn.check.reason);
    optimization.enforce_max_curvature=false;
    const auto coincident=run({0,0},{1,0},{{0,0},{0,0}});
    require(coincident.check.valid&&coincident.points.size()==1,"coincident constraint failed");
    // The curve bows through an occupied cell although its endpoint chord is free.
    occupy(map,{0,0.75});std::vector<HolePoint> sampled;double k=0;
    const std::vector<HoleBezierSpan> bows{HoleBezierSpan{{HolePoint{-1,0},HolePoint{-1,1},HolePoint{1,1},HolePoint{1,0}}}};
    require(!validateHoleCurve(bows,hull,0.025,std::nullopt,std::chrono::steady_clock::now()+std::chrono::seconds(2),sampled,k).valid,
        "continuous hull validator missed bow collision");
    const std::vector<HoleBezierSpan> cusp{HoleBezierSpan{{HolePoint{0,0},HolePoint{1,0},HolePoint{-1,0},HolePoint{0,0}}}};
    map=grid();require(!validateHoleCurve(cusp,hull,0.025,std::nullopt,std::chrono::steady_clock::now()+std::chrono::seconds(2),sampled,k).valid,
        "cusp accepted as regular curve");
    occupy(map,{0,0},-1);
    const auto unknown=run({0,0},{1,0},{{1,0}});
    require(!unknown.check.valid&&unknown.check.reason=="UNKNOWN_CELL","unknown start cell accepted");map=grid();
    require(!run({0,0},{1,0},{{6,0}}).check.valid,"out-of-map target accepted");
    require(!validateHoleCurve(short_exit.spans,hull,0.025,std::nullopt,std::chrono::steady_clock::now(),sampled,k).valid,"expired curve budget ignored");
    for(double y=-1;y<=1;y+=0.025) occupy(map,{0,y});
    EsdfMap esdf;esdf.buildFromOccupancy(std::make_shared<nav_msgs::msg::OccupancyGrid>(map),99);
    const HoleDistanceQuery distance=[&](double x,double y,double *,double *){return esdf.getDistanceInterp(x,y);};
    const auto detour=optimizeHoleConnection({-2,0},{1,0},{{2,0}},HolePoint{1,0},optimization,search,map,collision,hull,distance,
        std::chrono::steady_clock::now()+std::chrono::seconds(3));
    require(detour.check.valid&&detour.expansions>0,"optimized grid wall detour failed: "+detour.check.reason);
    for(std::size_t i=1;i<detour.points.size();++i) require(collision(detour.points[i-1],detour.points[i]).valid,"optimized wall collision");
    std::cout<<"Optimized wall detour: length="<<detour.length<<" expanded="<<detour.expansions<<std::endl;
}
static void optimizedRouteTests() {
    const std::string fixture="/tmp/nav_hole_stage_four_terrain.yaml";
    {std::ofstream f(fixture);f<<"regions:\n- id: optimized_hole\n  type: low_clearance\n  geometry:\n    polygon: [[-2,0],[2,0],[2,1],[-2,1]]\n  traversal: {passable_edges: [0,2]}\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;require(terrain->loadFromFile(fixture,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_stage_four_routes",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.global.enabled",false),
        rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.2),
        rclcpp::Parameter("hole_planner.departure.departure_distance",0.4),
        rclcpp::Parameter("hole_planner.search.connection_timeout",1.0)}));
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain);auto map=grid();
    nav_msgs::msg::Path route;bool constrained=false;
    const auto run=[&](const std::vector<HolePoint> &p) {
        const auto result=planner.planRoute(message(p),p.front(),p.back(),map,99,route,constrained);
        require(result.valid&&constrained,"optimized integrated route: "+result.reason);
        require(planner.validatePath(route,map,99).valid,"optimized final independent validator rejected");
        require(planner.routeAttempts().back().optimized,"optimization route diagnostic missing");
        require(holeNorm(points(route).front()-p.front())<1e-8&&holeNorm(points(route).back()-p.back())<1e-8,"optimized endpoints drifted");
    };
    run({{-2,-1.6},{0,0},{0,1},{1.2,1.45}});
    auto attempt=planner.routeAttempts().back();const auto published=points(route);
    for(auto q:{attempt.A,attempt.passage.S,attempt.passage.E,attempt.passage.X,attempt.passage.T,attempt.D})
        require(std::any_of(published.begin(),published.end(),[&](auto p){return holeNorm(p-q)<1e-7;}),"optimized strict waypoint missed");
    std::cout<<"Optimized centerline complete route: length="<<attempt.path_length<<" max_k="<<attempt.maximum_curvature<<std::endl;
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","free")}).successful,"optimized free switch");
    run({{0.6,-2},{0.6,0},{0.6,1},{1.5,1.5}});
    require(std::abs(planner.pathPassages().front().E.x-0.6)<1e-7,"optimized free forced centerline");
    run({{0.6,-2},{0.6,0},{0.6,0.1},{0.65,0.9},{0.65,1},{0.65,3}});
    require(std::abs(planner.pathPassages().front().X.x-0.65)<1e-7,"optimized free lost exit point");
    const auto revision=planner.configurationRevision();
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.optimization.length_weight",-1.0)}).successful,"negative optimization weight accepted");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.optimization.control_spacing",0.0)}).successful,"zero control spacing accepted");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.optimization.curvature_weight",0.03)}).successful,"optimization update rejected");
    planner.refreshConfiguration();require(planner.configurationRevision()>revision&&planner.routeAttempts().empty(),"optimization cache stale");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.approach.prepare_distance",0.8),rclcpp::Parameter("hole_planner.departure.departure_distance",0.2),
        rclcpp::Parameter("hole_planner.validation.tangent_tolerance_deg",0.0)}).successful,"merged mandatory distances rejected");
    run({{0,-2},{0,3}});
    occupy(map,{0,0.5});
    const auto blocked=planner.planRoute(message({{0,-2},{0,3}}),{0,-2},{0,3},map,99,route,constrained);
    require(!blocked.valid&&!constrained&&route.poses.empty(),"optimized dynamic passage obstacle ignored");
}
static void routeTests() {
    const std::string fixture="/tmp/nav_hole_stage_three_terrain.yaml";
    {std::ofstream f(fixture);f<<"regions:\n- id: test_hole\n  type: low_clearance\n  geometry:\n    polygon: [[-2,0],[2,0],[2,1],[-2,1]]\n  traversal: {passable_edges: [0,2], bidirectional: true}\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(fixture,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_stage_three_routes",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.global.enabled",false),
        rclcpp::Parameter("hole_planner.optimization.enabled",false),
        rclcpp::Parameter("hole_planner.search.connection_timeout",1.0)}));
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain);
    auto map=grid();nav_msgs::msg::Path route;bool constrained=false;
    auto run=[&](HolePoint start,HolePoint goal,const nav_msgs::msg::Path &seed,std::optional<HolePoint> velocity=std::nullopt) {
        const auto check=planner.planRoute(seed,start,goal,map,99,route,constrained,velocity);
        require(check.valid&&constrained,"route failed: "+check.reason);
        require(planner.validatePath(route,map,99).valid,"generated route failed independent validator");
        const auto p=points(route);
        require(holeNorm(p.front()-start)<1e-8&&holeNorm(p.back()-goal)<1e-8,"actual request endpoints shifted");
        require(curvature(p)<1.02,"route seed curvature exceeded");
        const auto &a=planner.routeAttempts().back();require(a.check.valid,"selected attempt missing");
        if(a.passage.mode==HolePassageMode::Centerline) {
            const auto index=[&](HolePoint q) {
                const auto it=std::find_if(p.begin(),p.end(),[&](auto v){return holeNorm(v-q)<1e-8;});
                require(it!=p.end(),"strict mandatory point missed");return it-p.begin();
            };
            require(index(a.A)<=index(a.passage.S)&&index(a.passage.S)<=index(a.passage.E)&&
                index(a.passage.E)<index(a.passage.X)&&index(a.passage.X)<=index(a.passage.T)&&
                index(a.passage.T)<=index(a.D),"strict points out of order");
        }
        std::cout<<"Route "<<(a.passage.mode==HolePassageMode::Centerline?"centerline":"free")
            <<" start="<<start.x<<','<<start.y<<" prepare="<<a.prepare_distance
            <<" length="<<HolePathPolyline(p).arc.back()<<" curvature="<<curvature(p)<<'\n';
    };
    for(double side:{-3.0,3.0}) run({side,-0.15},{-side,2.0},message({{side,-0.15},{0,0},{0,1},{-side,2.0}}));
    run({-3,1.15},{3,-1.0},message({{-3,1.15},{0,1},{0,0},{3,-1.0}}));
    // 普通路线没有穿洞时，两种模式都不能仅因洞口距离近而启动搜索。
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.search.max_expansions",1)}).successful,"limit bypass search budget");
    for (const auto &seed : {message({{-3,-2},{-3,3}}), message({{-1,-0.35},{1,-0.35}}),
                            message({{-3,-2},{-3,2},{3,2}})}) {
        const auto endpoints=points(seed);
        const auto result=planner.planRoute(seed,endpoints.front(),endpoints.back(),map,99,route,constrained);
        require(result.valid&&!constrained&&result.reason=="PATH_VALID_NO_PASSAGE","ordinary centerline route forced through nearest hole");
        require(route.poses.empty()&&planner.routeAttempts().empty()&&planner.pathPassages().empty(),"ordinary route performed hole connection search");
    }
    const auto empty_seed=planner.planRoute(message({}),{0,-2},{0,3},map,99,route,constrained);
    require(!empty_seed.valid&&empty_seed.reason=="ASTAR_SEED_REQUIRED"&&planner.routeAttempts().empty(),"empty A* seed searched nearest hole");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.search.max_expansions",20000)}).successful,"restore search budget");
    map=grid();occupy(map,{0,-1.5});
    run({-2,-2},{2,3},message({{-2,-2},{0,0},{0,1},{2,3}}));
    require(std::abs(planner.routeAttempts().back().prepare_distance-1.5)>1e-8,"blocked A not searched");
    require(std::any_of(planner.routeAttempts().begin(),planner.routeAttempts().end(),[](const auto &a) {
        return a.check.reason.find("PREPARE_POINT_UNREACHABLE")!=std::string::npos;
    }),"rejected preparation candidate reason missing");
    require(holeNorm(planner.routeAttempts().back().passage.S-HolePoint{0,-0.8})<1e-8,"prepare search moved S");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.search_prepare_distance",false)}).successful,"disable prepare search");
    occupy(map,{0,2.5});
    auto failed=planner.planRoute(message({{-2,-2},{0,0},{0,1},{2,3}}),{-2,-2},{2,3},map,99,route,constrained);
    require(!failed.valid&&!constrained&&route.poses.empty(),"blocked A silently bypassed");
    map=grid();occupy(map,{0,-0.4});
    failed=planner.planRoute(message({{0,-2},{0,3}}),{0,-2},{0,3},map,99,route,constrained);
    require(!failed.valid&&failed.reason.find("STRAIGHT_SEGMENT_BLOCKED")!=std::string::npos,"blocked fixed straight accepted");
    map=grid();occupy(map,{0,0.5});
    failed=planner.planRoute(message({{0,-2},{0,3}}),{0,-2},{0,3},map,99,route,constrained);
    require(!failed.valid&&failed.reason.find("PASSAGE_BLOCKED")!=std::string::npos,"dynamic obstacle ignored");
    map=grid();
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","free")}).successful,"free switch");
    const auto offset=message({{0.6,-2},{0.6,0},{0.6,1},{0.6,3}});
    run({0.6,-2},{0.6,3},offset);
    require(std::abs(planner.pathPassages().front().E.x-0.6)<1e-8,"free forced centerline");
    occupy(map,{0.6,-0.4});
    run({0.6,-2},{0.6,3},offset);
    require(holeNorm(planner.pathPassages().front().E-HolePoint{0.6,0})>1e-5||
        holeNorm(planner.pathPassages().front().u_in-HolePoint{0,1})>1e-5,"free candidate was not adjusted");
    map=grid();
    run({-2,-1.5},{2,2},message({{-2,-1.5},{0.4,0},{0.4,1},{2,2}}));
    run({0.6,-2},{0.65,3},message({{0.6,-2},{0.6,0},{0.6,0.1},{0.65,0.9},{0.65,1},{0.65,3}}));
    require(holeNorm(planner.pathPassages().front().E-HolePoint{0.6,0})<1e-8&&
        holeNorm(planner.pathPassages().front().X-HolePoint{0.65,1})<1e-8&&
        holeDirectionMatches(planner.pathPassages().front().u_in,{0,1},1e-5),"free inside curve was replaced unnecessarily");
    const auto bypass=message({{-3,-2},{-3,3}});
    const auto bypass_check=planner.planRoute(bypass,{-3,-2},{-3,3},map,99,route,constrained);
    require(bypass_check.valid&&!constrained,"free bypass gained passage constraints");
    const auto partial=planner.planRoute(message({{0,0.5},{0,3}}),{0,0.5},{0,3},map,99,route,constrained);
    require(!partial.valid&&partial.reason.find("PARTIAL_PASSAGE")!=std::string::npos,"partial passage claimed complete");
    const auto multiple=planner.planRoute(message({{0,-2},{0,3},{0,-2}}),{0,-2},{0,-2},map,99,route,constrained);
    require(!multiple.valid&&multiple.reason.find("MULTIPLE_PASSAGES")!=std::string::npos,"multiple passages claimed complete");
    const auto revision=planner.configurationRevision();
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.search.heading_bins",0)}).successful,"invalid heading bins accepted");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.search.heading_bins",static_cast<int64_t>(4294967368))}).successful,"overflowed heading bins accepted");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.prepare_distance_step",0.0)}).successful,"zero prepare step accepted");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.free.edge_step",-1.0)}).successful,"invalid free step accepted");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.max_curvature",0.8)}).successful,"search update rejected");
    planner.refreshConfiguration();require(planner.configurationRevision()>revision&&planner.routeAttempts().empty(),"search cache not invalidated");
    bool active=true;planner.setExecutionActivePredicate([&](){return active;});
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.search.max_expansions",100)}).successful,"search changed during navigation");
    active=false;
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.approach.prepare_distance",0.0),rclcpp::Parameter("hole_planner.approach.entry_straight_length",0.0),
        rclcpp::Parameter("hole_planner.departure.departure_distance",0.0),rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.0)}).successful,"zero distance rejected");
    run({0,-2},{0,3},message({{0,-2},{0,3}}));
    // 已在运动时约束路径起始切线，车体 yaw 不参与搜索。
    run({0,-2},{0,3},message({{0,-2},{0,3}}),HolePoint{0.2,0});
    const auto moving=HolePathPolyline(points(route));
    require(holeDirectionMatches(moving.tangent(0,true),{1,0},3),"initial velocity direction ignored");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.validation.tangent_tolerance_deg",0.0)}).successful,"zero tangent tolerance rejected");
    run({-3,-0.15},{3,2},message({{-3,-0.15},{0,0},{0,1},{3,2}}));
    std::cout<<"Strict/free generation, preparation search, failures, parameters and movement passed\n";
}
static void rotatedAndOverrideTests() {
    for(int degree:{15,45,87,135,221,315}) {
        const double a=degree*3.14159265358979323846/180;
        const auto rotate=[&](HolePoint p){return HolePoint{p.x*std::cos(a)-p.y*std::sin(a),p.x*std::sin(a)+p.y*std::cos(a)};};
        const std::string fixture="/tmp/nav_hole_stage_three_rotated.yaml";
        {std::ofstream f(fixture);f.precision(17);
            f<<"regions:\n- id: rotated\n  type: low_clearance\n  geometry:\n    polygon:\n";
            for(auto p:std::vector<HolePoint>{{-2,0},{2,0},{2,1},{-2,1}}) {
                const auto q=rotate(p);f<<"    - ["<<q.x<<", "<<q.y<<"]\n";
            }
            f<<"  traversal: {passable_edges: [0,2], bidirectional: false, prepare_distance: 1.2, entry_straight_length: 0.6, exit_straight_length: 0.3, departure_distance: 0.7}\n";
        }
        auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
        require(terrain->loadFromFile(fixture,"map",&error),error);
        auto node=std::make_shared<rclcpp::Node>("hole_rotated_"+std::to_string(degree),rclcpp::NodeOptions().parameter_overrides({
            rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
            rclcpp::Parameter("hole_planner.global.enabled",false),
            rclcpp::Parameter("hole_planner.search.connection_timeout",1.0)}));
        HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain);
        const auto start=rotate({1,-1.5}),goal=rotate({-1,2});auto map=grid();nav_msgs::msg::Path route;bool constrained=false;
        const auto result=planner.planRoute(message({start,rotate({0,0}),rotate({0,1}),goal}),start,goal,map,99,route,constrained);
        require(result.valid&&constrained,"rotated generation: "+result.reason);
        const auto &attempt=planner.routeAttempts().back();
        require(attempt.passage.entry_edge==0&&std::abs(attempt.prepare_distance-1.2)<1e-8,"single hole overrides or one-way ignored");
        require(std::abs(holeNorm(attempt.passage.E-attempt.passage.S)-0.6)<1e-8&&
            std::abs(holeNorm(attempt.passage.T-attempt.passage.X)-0.3)<1e-8,"rotated overridden lengths changed");
    }
    std::cout<<"Rotated, single-hole distances and one-way seeds passed\n";
}
static void actualMapTests(const std::string &map_file,const std::string &terrain_file) {
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(terrain_file,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_stage_three_actual",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline")}));
    auto tf=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    auto manager=std::make_shared<LayeredMapManager>();manager->initialize(node.get(),tf);
    manager->setHoleClearance(terrain,true,0.5,0.5);InflationParams inflation;
    inflation.inflation_radius=0.8;inflation.inscribed_radius=0.2;inflation.cost_scaling=1.8;
    require(manager->loadStaticMap(map_file,inflation),"actual map load failed");
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain);
    const auto map=manager->getCostmap();planner.buildCandidates(message({{0,0},{1,1}}),*map,99);
    const auto candidates=planner.candidates();require(candidates.size()==8,"actual directions missing");
    SimplePlanner integrated;integrated.initialize(node.get());integrated.setTerrainRegionMap(terrain);integrated.setMap(manager);
    for(const auto &c:candidates) {
        const auto start=c.E-c.u_in*1.5,goal=c.X+c.u_out*0.8;
        nav_msgs::msg::Path route;bool constrained=false;
        const auto result=planner.planRoute(message({start,goal}),start,goal,*map,99,route,constrained);
        require(result.valid&&constrained,c.hole_id+" actual generation: "+result.reason);
        require(planner.pathPassages().size()==1&&planner.pathPassages().front().hole_id==c.hole_id,"actual hole selection changed");
        require(planner.validatePath(route,*map,99).valid,"actual generated trajectory invalid");
        const auto endpoints=message({start,goal});
        require(integrated.plan(endpoints.poses.front(),endpoints.poses.back(),route),"actual SimplePlanner seed failed");
        require(planner.validatePath(route,*map,99).valid,"global smoothing damaged fixed straight");
        const auto expected=points(route);
        require(holeNorm(expected.front()-start)<1e-8&&holeNorm(expected.back()-goal)<1e-8,"integrated endpoints drifted");
        std::cout<<"Actual "<<c.hole_id<<" "<<c.entry_edge<<"->"<<c.exit_edge<<" points="<<route.poses.size()<<'\n';
    }
}
static void ordinaryPlannerTests() {
    const std::string terrain_file="/tmp/nav_hole_ordinary_terrain.yaml",pgm="/tmp/nav_hole_ordinary.pgm",yaml="/tmp/nav_hole_ordinary.yaml";
    {std::ofstream f(terrain_file);f<<"regions:\n- id: nearby_hole\n  type: low_clearance\n  geometry:\n    polygon: [[-2,0],[2,0],[2,1],[-2,1]]\n  traversal: {passable_edges: [0,2]}\n";}
    {std::ofstream f(pgm,std::ios::binary);f<<"P5\n200 200\n255\n";const std::string pixels(40000,static_cast<char>(254));f.write(pixels.data(),pixels.size());}
    {std::ofstream f(yaml);f<<"image: "<<pgm<<"\nresolution: 0.05\norigin: [-5,-5,0]\nnegate: 0\noccupied_thresh: 0.65\nfree_thresh: 0.25\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(terrain_file,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_ordinary_planner",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.search.max_expansions",1)}));
    auto tf=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    auto manager=std::make_shared<LayeredMapManager>();manager->initialize(node.get(),tf);
    require(manager->loadStaticMap(yaml,InflationParams()),"ordinary map load failed");
    SimplePlanner planner;planner.initialize(node.get());planner.setTerrainRegionMap(terrain);planner.setMap(manager);
    for (const auto &request : {message({{-3,-2},{-3,3}}),message({{-1,-0.35},{1,-0.35}})}) {
        nav_msgs::msg::Path enabled,baseline;
        require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.enabled",true)}).successful,"ordinary enable failed");
        require(planner.plan(request.poses.front(),request.poses.back(),enabled),"ordinary route failed with nearby hole");
        require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.enabled",false)}).successful,"ordinary baseline disable failed");
        require(planner.plan(request.poses.front(),request.poses.back(),baseline),"ordinary baseline failed");
        require(enabled.poses.size()==baseline.poses.size(),"ordinary smoothing changed when hole planning enabled");
        const auto a=points(enabled),b=points(baseline);
        for(std::size_t i=0;i<a.size();++i) require(holeNorm(a[i]-b[i])<1e-8,"ordinary route diverted toward nearby hole");
    }
    std::cout<<"Ordinary routes retain A* and smoothing with centerline enabled and minimal hole search budget\n";
}
// 使用实际导航参数、膨胀地图和 ESDF，检查交给控制器的完整路线。
static void actualMultiHoleTests(const std::string &map_file,const std::string &terrain_file,const std::string &params_file,bool cache_only=false) {
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(terrain_file,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("nav_server",rclcpp::NodeOptions().arguments({
        "--ros-args","--params-file",params_file}));
    auto tf=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    auto manager=std::make_shared<LayeredMapManager>();manager->initialize(node.get(),tf);
    manager->setHoleClearance(terrain,true,0.5,0.5);InflationParams inflation;
    inflation.inflation_radius=0.8;inflation.inscribed_radius=0.2;inflation.cost_scaling=1.8;
    require(manager->loadStaticMap(map_file,inflation),"actual multi-hole map load failed");
    HolePassagePlanner validator;validator.initialize(node.get());validator.setTerrain(terrain);
    SimplePlanner integrated;integrated.initialize(node.get());integrated.setTerrainRegionMap(terrain);integrated.setMap(manager);
    const std::vector<std::vector<HolePoint>> requests{
        {{2,-4.306},{-4.6935,-2.6}},
        {{-4.6935,-2.6},{2,-4.306}},
        {{4.694,6.0},{-2,7.604}},
        {{-2,7.604},{4.694,6.0}},
        {{6.82189,-1.35343},{-6.72366,1.21869}},
        {{-6.72366,1.21869},{6.82189,-1.35343}}};
    const std::vector<std::vector<std::string>> expected{
        {"hole_B1","hole_A1"},{"hole_A1","hole_B1"},{"hole_A2","hole_B2"},{"hole_B2","hole_A2"},
        {"hole_A2","hole_B2"},{"hole_B2","hole_A2"}};
    if(!cache_only)for(std::size_t i=0;i<requests.size();++i) {
        integrated.clearCache();const auto endpoints=message(requests[i]);nav_msgs::msg::Path route;
        const auto begin=std::chrono::steady_clock::now();
        require(integrated.plan(endpoints.poses.front(),endpoints.poses.back(),route),"actual multi-hole request "+std::to_string(i)+" failed");
        const auto check=validator.validatePath(route,*manager->getCostmap(),99);
        require(check.valid,"actual multi-hole final route: "+check.reason);
        require(validator.pathPassages().size()==2,"actual route did not cross both holes");
        if(i<4)for(std::size_t h=0;h<2;++h)require(validator.pathPassages()[h].hole_id==expected[i][h],"actual hole sequence changed");
        const auto p=points(route);
        require(holeNorm(p.front()-requests[i].front())<1e-8&&holeNorm(p.back()-requests[i].back())<1e-8,"actual multi-hole endpoints shifted");
        require(HolePathPolyline(p).arc.back()<(i<4?12.0:30.0),"actual multi-hole route retained a long bypass");
        std::ofstream output("/tmp/nav_actual_multi_"+std::to_string(i)+".csv");
        for(auto q:p)output<<q.x<<','<<q.y<<'\n';
        std::cout<<"Actual multi-hole request="<<i<<" length="<<HolePathPolyline(p).arc.back()<<" ms="
            <<std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-begin).count()<<" holes="
            <<validator.pathPassages()[0].hole_id<<","<<validator.pathPassages()[1].hole_id<<std::endl;
    }
    if(cache_only) {
        // 每次仅清除整条路径缓存，隔离洞间连接缓存的耗时和命中统计。
        auto &measured=integrated;
        const auto endpoints=message(requests[2]);nav_msgs::msg::Path route;
        for(const std::string mode:{"off","on_cold","on_warm","off_again"}) {
            if(mode!="on_warm")require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.cache.enabled",mode=="on_cold")}).successful,"actual cache toggle failed");
            measured.clearCache();
            const auto begin=std::chrono::steady_clock::now();
            require(measured.plan(endpoints.poses.front(),endpoints.poses.back(),route),"actual cache request failed: "+mode);
            require(validator.validatePath(route,*manager->getCostmap(),99).valid,"actual cache final route invalid");
            const auto &stats=measured.holeStatistics();
            if(mode=="on_warm")require(stats.cache_hits>0,"actual warm curve cache missed");
            else require(stats.cache_hits==0&&stats.optimized_edges>0,"actual cold/off request reused a curve");
            std::cout<<"Actual cache mode="<<mode<<" ms="<<std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-begin).count()
                     <<" length="<<HolePathPolyline(points(route)).arc.back()<<" hits="<<stats.cache_hits<<" optimized="<<stats.optimized_edges<<std::endl;
        }
    }
}
static void globalRouteTests() {
    const std::string fixture="/tmp/nav_hole_stage_five.yaml";
    const auto terrainFor=[&](const std::vector<double> &entries,bool one_way=false) {
        {std::ofstream f(fixture);f<<"regions:\n";
            for(std::size_t i=0;i<entries.size();++i) {
                const auto y=entries[i];
                f<<"- id: hole_"<<i<<"\n  type: low_clearance\n  geometry:\n    polygon: [[-0.8,"<<y<<"],[0.8,"<<y
                 <<"],[0.8,"<<y+0.3<<"],[-0.8,"<<y+0.3<<"]]\n  traversal: {passable_edges: [0,2], bidirectional: "
                 <<(one_way?"false":"true")<<"}\n";
            }
        }
        auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
        require(terrain->loadFromFile(fixture,"map",&error),error);return terrain;
    };
    auto node=std::make_shared<rclcpp::Node>("hole_stage_five_routes",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.approach.search_prepare_distance",false),
        rclcpp::Parameter("hole_planner.free.max_candidates",16),
        rclcpp::Parameter("hole_planner.search.connection_timeout",0.5)}));
    HolePassagePlanner planner;planner.initialize(node.get());
    auto map=grid();nav_msgs::msg::Path route;bool constrained=false;
    const auto run=[&](const std::vector<HolePoint> &seed,std::size_t count) {
        const auto begin=std::chrono::steady_clock::now();
        const auto result=planner.planRoute(message(seed),seed.front(),seed.back(),map,99,route,constrained);
        require(result.valid&&constrained,"stage five route: "+result.reason);
        require(planner.validatePath(route,map,99).valid,"stage five final validator");
        require(planner.pathPassages().size()==count,"stage five selected incorrect passage count");
        require(holeNorm(points(route).front()-seed.front())<1e-8&&holeNorm(points(route).back()-seed.back())<1e-8,"stage five endpoints shifted");
        std::cout<<"Global route: count="<<count<<" length="<<HolePathPolyline(points(route)).arc.back()<<" ms="
                 <<std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-begin).count()<<std::endl;
    };
    const auto walls=[&](const std::vector<double> &entries) {
        map=grid();
        for(double y:entries)for(double x=-4.975;x<5;x+=0.05)
            if(std::abs(x)>0.75)for(double depth=0.025;depth<0.3;depth+=0.05)occupy(map,{x,y+depth});
    };
    for(const auto entries:{std::vector<double>{0,1.3},std::vector<double>{0,2},std::vector<double>{-1,0.5,2}}) {
        planner.setTerrain(terrainFor(entries));walls(entries);
        for(const std::string mode:{"centerline","free"}) {
            require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode",mode)}).successful,"global mode update");
            run({{0,-3},{0,3.7}},entries.size());
            run({{0,3.7},{0,-3}},entries.size());
            run({{0.3,-3},{0.3,0},{0.3,2.3},{0.3,3.7}},entries.size());
        }
    }
    planner.setTerrain(terrainFor({0}));walls({0});
    for(const std::string mode:{"centerline","free"}) {
        require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode",mode)}).successful,"partial mode update");
        run({{0,0.1},{0,2}},1);require(!planner.pathPassages().front().entry_complete,"inside start marked complete entry");
        run({{0,-2},{0,0.2}},1);require(!planner.pathPassages().front().exit_complete,"inside goal marked complete exit");
        run({{0,0.1},{0,0.2}},1);
        run({{0,-0.2},{0,0.5}},1);
        require(!planner.pathPassages().front().entry_straight_complete&&!planner.pathPassages().front().exit_straight_complete,
            "short endpoint straight marked fully complete");
        require(std::abs(planner.pathPassages().front().entry_straight_remaining-0.2)<1e-8,"remaining entry length incorrect");
    }
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline")}).successful,"strict restore");
    auto result=planner.planRoute(message({{0.3,0.1},{0,2}}),{0.3,0.1},{0,2},map,99,route,constrained);
    require(!result.valid&&route.poses.empty(),"strict off-axis inside start corrected diagonally");
    planner.setTerrain(terrainFor({0},true));walls({0});
    result=planner.planRoute(message({{0,0.2},{0,-2}}),{0,0.2},{0,-2},map,99,route,constrained);
    require(!result.valid,"one-way inside reverse accepted");
    planner.setTerrain(terrainFor({0}));walls({0});
    run({{0,-2},{0,2}},1);
    map=grid();occupy(map,{0,0.225});
    result=planner.planRoute(message({{0,0.1},{0,-1},{2,1},{0,2}}),{0,0.1},{0,2},map,99,route,constrained);
    require(!result.valid,"inside replan reversed committed passage direction");
    planner.setTerrain(terrainFor({0}));walls({0});
    run({{0,-2},{0,0},{0,0.3},{1.5,1.2}},1);
    for(double y:{0.5,0.65}) {
        run({{0,y},{1.5,1.2}},0);
        const auto path=HolePathPolyline(points(route));
        require(holeNorm(path.at(0.8-y)-HolePoint{0,0.8})<1e-7,"exit replan abandoned remaining straight");
    }
    planner.setTerrain(terrainFor({0}));map=grid();
    require(planner.planRoute(message({{0,0.1}}),{0,0.1},{0,0.1},map,99,route,constrained).valid&&route.poses.size()==1,
        "stationary inside request failed");
    planner.setTerrain(terrainFor({0}));map=grid();occupy(map,{0,0.1});
    run({{0,-2},{0,2}},0);require(planner.routeAttempts().empty(),"bypass emitted a hole passage attempt");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","free")}).successful,"free obstacle switch");
    walls({0});occupy(map,{0,0.1});run({{0,-2},{0,2}},1);
    require(!checkHoleMapSegment(map,99,{0,0},{0,0.3}).valid,"free obstacle fixture did not block the centerline");
    planner.setTerrain(terrainFor({0,2}));walls({0,2});
    for(double x=-0.725;x<0.75;x+=0.05)occupy(map,{x,2.125});
    result=planner.planRoute(message({{0,-2},{0,3.5}}),{0,-2},{0,3.5},map,99,route,constrained);
    require(!result.valid&&route.poses.empty(),"dynamic second-hole blockage ignored");
    {
        auto integrated_node=std::make_shared<rclcpp::Node>("hole_stage_five_cache",rclcpp::NodeOptions().parameter_overrides({
            rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
            rclcpp::Parameter("hole_planner.approach.search_prepare_distance",false)}));
        auto tf=std::make_shared<tf2_ros::Buffer>(integrated_node->get_clock());
        auto manager=std::make_shared<LayeredMapManager>();manager->initialize(integrated_node.get(),tf);
        InflationParams inflation;inflation.inflation_radius=inflation.inscribed_radius=0;manager->setInflationParams(inflation);
        walls({0,2});manager->setStaticMap(std::make_shared<nav_msgs::msg::OccupancyGrid>(map));
        SimplePlanner integrated;integrated.initialize(integrated_node.get());integrated.setTerrainRegionMap(terrainFor({0,2}));integrated.setMap(manager);
        auto request=message({{0,-2},{0,3.5}});
        require(integrated.plan(request.poses.front(),request.poses.back(),route),"integrated multi-hole request failed");
        request.poses.front().pose.position.y=0.1;
        require(integrated.plan(request.poses.front(),request.poses.back(),route),"inside cache pruning failed");
        require(points(route).front().y>-0.8,"inside pruning returned to preparation point");
        integrated.clearCache();
        require(integrated.plan(request.poses.front(),request.poses.back(),route),"fresh inside multi-hole replan failed");
        require(std::abs(points(route).front().y-0.1)<1e-8,"fresh inside request starts behind robot");
        for(double x=-0.725;x<0.75;x+=0.05)occupy(map,{x,2.125});
        manager->setStaticMap(std::make_shared<nav_msgs::msg::OccupancyGrid>(map));
        require(!integrated.plan(request.poses.front(),request.poses.back(),route),"cached second-hole dynamic obstacle ignored");
    }
    {
        {std::ofstream f(fixture);f<<"regions:\n- id: north\n  type: low_clearance\n  geometry:\n    polygon: [[-0.8,-2],[0.8,-2],[0.8,-1.7],[-0.8,-1.7]]\n  traversal: {passable_edges: [0,2]}\n"
            <<"- id: east\n  type: low_clearance\n  geometry:\n    polygon: [[1,1.2],[1.3,1.2],[1.3,2.8],[1,2.8]]\n  traversal: {passable_edges: [1,3]}\n";}
        auto terrain=std::make_shared<TerrainRegionMap>();std::string error;require(terrain->loadFromFile(fixture,"map",&error),error);
        planner.setTerrain(terrain);walls({-2});
        for(double y=-4.975;y<5;y+=0.05)if(y<1.25||y>2.75)
            for(double x=1.025;x<1.3;x+=0.05)occupy(map,{x,y});
        require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline"),
            rclcpp::Parameter("hole_planner.approach.prepare_distance",0.4),rclcpp::Parameter("hole_planner.approach.entry_straight_length",0.2),
            rclcpp::Parameter("hole_planner.departure.departure_distance",0.4),rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.2)}).successful,"nonparallel distances");
        run({{0.2,-3.5},{0,-2},{0,-1.7},{1,2},{1.3,2},{3,2}},2);
        run({{3,2},{1.3,2},{1,2},{0,-1.7},{0,-2},{0.2,-3.5}},2);
        require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","free")}).successful,"nonparallel free");
        run({{0.2,-3.5},{0,-2},{0,-1.7},{1,2},{1.3,2},{3,2}},2);
    }
    planner.setTerrain(terrainFor({0,2}));
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.approach.prepare_distance",1.5),rclcpp::Parameter("hole_planner.approach.entry_straight_length",0.8),
        rclcpp::Parameter("hole_planner.departure.departure_distance",0.8),rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.5),
        rclcpp::Parameter("hole_planner.approach.search_prepare_distance",true)}).successful,"shared prepare search update");
    walls({0,2});occupy(map,{0,-1.5});
    run({{0.3,-3},{0,0},{0,0.3},{0,2},{0,2.3},{0.3,3.7}},2);
    require(std::none_of(planner.routeAttempts().begin(),planner.routeAttempts().end(),[](const auto &a){
        return holeNorm(a.A-HolePoint{0,-1.5})<1e-8;
    }),"shared blocked preparation distance not searched");
    // 过洞缓存开关独立于普通路线缓存；非重叠双洞用于检查真实洞间连接复用。
    {
        auto cache_node=std::make_shared<rclcpp::Node>("hole_phase_one_cache",rclcpp::NodeOptions().parameter_overrides({
            rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
            rclcpp::Parameter("hole_planner.global.planning_policy","responsive"),
            rclcpp::Parameter("hole_planner.global.improvement_timeout",0.0),
            rclcpp::Parameter("hole_planner.approach.search_prepare_distance",false),
            rclcpp::Parameter("hole_planner.approach.prepare_distance",0.4),
            rclcpp::Parameter("hole_planner.approach.entry_straight_length",0.2),
            rclcpp::Parameter("hole_planner.departure.departure_distance",0.4),
            rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.2)}));
        auto tf=std::make_shared<tf2_ros::Buffer>(cache_node->get_clock());
        auto manager=std::make_shared<LayeredMapManager>();manager->initialize(cache_node.get(),tf);
        InflationParams inflation;inflation.inflation_radius=inflation.inscribed_radius=0;manager->setInflationParams(inflation);
        walls({0,3});manager->setStaticMap(std::make_shared<nav_msgs::msg::OccupancyGrid>(map));
        SimplePlanner integrated;integrated.initialize(cache_node.get());integrated.setTerrainRegionMap(terrainFor({0,3}));integrated.setMap(manager);
        const auto request=message({{0.3,-2},{0.3,4.5}});
        const auto solve=[&]() {
            require(integrated.plan(request.poses.front(),request.poses.back(),route),"phase one cache route failed");
            require(integrated.validatePath(route),"phase one cached route invalid");
        };
        solve();solve();
        require(integrated.holeStatistics().optimized_edges>0&&integrated.holeStatistics().cache_hits==0,
            "disabled hole cache reused a whole path or connection");
        require(cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.cache.enabled",true)}).successful,"enable cache rejected");
        solve(); // 修改开关后的首次请求，缓存应为空。
        integrated.clearCache();solve(); // 清除整条路径，独立验证洞间缓存。
        require(integrated.holeStatistics().cache_hits>0,"between-hole cache did not hit");
        solve();require(integrated.holeStatistics().stop_reason=="WHOLE_PATH_CACHE","enabled whole hole cache was not reused");
        require(cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.global.curvature_weight",0.003)}).successful,"cache parameter update failed");
        solve();require(integrated.holeStatistics().cache_hits==0&&integrated.holeStatistics().optimized_edges>0,"parameter change reused stale curve cache");
        integrated.clearCache();occupy(map,{0,1.5});
        manager->setStaticMap(std::make_shared<nav_msgs::msg::OccupancyGrid>(map));
        const bool replanned=integrated.plan(request.poses.front(),request.poses.back(),route);
        require(integrated.holeStatistics().cache_rejected>0,"dynamic obstacle did not invalidate curve cache");
        if(replanned)require(integrated.validatePath(route),"dynamic cache returned a colliding route");
        require(cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.cache.enabled",false)}).successful,"disable cache rejected");
        walls({0,3});manager->setStaticMap(std::make_shared<nav_msgs::msg::OccupancyGrid>(map));solve();solve();
        require(integrated.holeStatistics().cache_hits==0&&integrated.holeStatistics().optimized_edges>0,"runtime disable retained hole cache");
        require(cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.cache.enabled",true)}).successful,"cache re-enable failed");
        solve();integrated.setHoleExecutionActivePredicate([](){return true;});
        require(cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.cache.enabled",false)}).successful,"active cache switch rejected");
        integrated.setHoleExecutionActivePredicate({});
        auto partial=request;partial.poses.front().pose.position.x=0;partial.poses.front().pose.position.y=0.1;
        require(integrated.plan(partial.poses.front(),partial.poses.back(),route),"cache toggle lost inside commitment");
        require(holeNorm(points(route).front()-HolePoint{0,0.1})<1e-8,"cache toggle returned to entry preparation");
        auto ordinary=message({{-3,-3},{-3,-2}});
        require(integrated.plan(ordinary.poses.front(),ordinary.poses.back(),route),"ordinary request failed with hole cache disabled");
        require(integrated.plan(ordinary.poses.front(),ordinary.poses.back(),route)&&
            integrated.holeStatistics().stop_reason=="WHOLE_PATH_CACHE","hole cache switch disabled ordinary cache");
        require(!cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.global.planning_policy","bad")}).successful,"invalid policy accepted");
        require(!cache_node->set_parameters_atomically({rclcpp::Parameter("hole_planner.cache.max_entries",0)}).successful,"invalid cache capacity accepted");
        std::cout<<"Cache on/off, ordinary reuse, dynamic curve invalidation and responsive planning passed\n";
    }
    const auto revision=planner.configurationRevision();
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.global.max_nodes",0)}).successful,"invalid graph budget accepted");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.global.curvature_weight",0.003)}).successful,"global cost update");
    planner.refreshConfiguration();require(planner.configurationRevision()>revision,"global configuration did not invalidate cache");
    walls({0,2});
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.search.planning_timeout",0.01),
        rclcpp::Parameter("hole_planner.global.max_expansions",1)}).successful,"global timeout update");
    run({{0,-2},{0,3.5}},2);
    require(!planner.validatePath(route,map,99,false,std::chrono::steady_clock::now()).valid,"expired final validation budget ignored");
    result=planner.planRoute(message({{0.3,-2},{0.3,3.5}}),{0.3,-2},{0.3,3.5},map,99,route,constrained);
    require(!result.valid&&route.poses.empty(),"search deadline published a partial/unvalidated route");
    std::cout<<"Multi-hole, overlap, partial endpoints, bypass, dynamic obstacles and graph budgets passed\n";
}
static void phaseTwoRangeTests(const std::string &map_file,const std::string &terrain_file,const std::string &params_file,bool manual=false) {
    auto root=YAML::LoadFile(terrain_file);
    const auto manual_config=manual?readHolePassageConfig(YAML::LoadFile(
        (std::filesystem::path(terrain_file).parent_path()/"hole_passages.yaml").string())):YAML::Node();
    int range_index=0;
    for(auto region:root["regions"]) {
        if(region["type"].as<std::string>()!="low_clearance")continue;
        const int edge=region["traversal"]["passable_edges"][0].as<int>();
        nav_core::writeHoleStraightRange(region["traversal"],HoleStraightRange{edge,{.25+.02*range_index,.45-.02*range_index}});
        region["traversal"]["departure_distance"]=.5;
        if(manual) {
            overlayHolePassage(region["traversal"],holePassageEntry(manual_config,region["id"].as<std::string>()));
            region["traversal"]["prepare_path_distance"]=.2;
        }
        ++range_index;
    }
    const std::string filename="/tmp/nav_phase_two_ranges.yaml";
    {std::ofstream file(filename);file<<root;}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(filename,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("nav_server",rclcpp::NodeOptions().arguments({"--ros-args","--params-file",params_file}));
    auto tf=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    auto manager=std::make_shared<LayeredMapManager>();manager->initialize(node.get(),tf);
    manager->setHoleClearance(terrain,true,.5,.5);InflationParams inflation;
    inflation.inflation_radius=.8;inflation.inscribed_radius=.2;inflation.cost_scaling=1.8;
    require(manager->loadStaticMap(map_file,inflation),"range real map load failed");
    SimplePlanner planner;planner.initialize(node.get());planner.setTerrainRegionMap(terrain);planner.setMap(manager);
    HolePassagePlanner validator;validator.initialize(node.get());validator.setTerrain(terrain);
    const auto same=planner.validateTerrainUpdate(terrain);require(same.valid,same.reason);
    const std::vector<HolePoint> endpoints{{4.694,6},{-2,7.604}};
    for(int reverse:{0,1}) {
        planner.clearCache();nav_msgs::msg::Path route;
        const auto request=message({endpoints[reverse],endpoints[1-reverse]});
        require(planner.plan(request.poses.front(),request.poses.back(),route),"map range multi-hole planning failed");
        const auto check=validator.validatePath(route,*manager->getCostmap(),99);
        require(check.valid,check.reason);require(validator.pathPassages().size()==2,"map range did not cross two holes");
        for(const auto &c:validator.pathPassages()) {
            const auto region=std::find_if(terrain->getRegions().begin(),terrain->getRegions().end(),[&](const auto &r){return r.id==c.hole_id;});
            const auto d=resolveHoleDistances(region->raw["traversal"],readHolePreviewConfiguration(YAML::LoadFile(params_file))).forEntry(c.entry_edge);
            require(std::abs(holeNorm(c.E-c.S)-d.entry_straight_length)<1e-7,"entry side length mismatch");
            require(std::abs(holeNorm(c.T-c.X)-d.exit_straight_length)<1e-7,"exit side length mismatch");
            if(manual) {
                require(d.manual_range,"global override disabled manual range");
                const auto &events=validator.preparationEvents();
                const auto a=std::find_if(events.begin(),events.end(),[&](const auto &event){return event.hole_id==c.hole_id;});
                require(a!=events.end()&&std::abs(a->preparation_arc-c.entry_arc+.2)<1e-8,"actual map A distance mismatch");
                const auto &departures=validator.departureEvents();
                const auto exit=std::find_if(departures.begin(),departures.end(),[&](const auto &event){return event.hole_id==c.hole_id;});
                require(exit!=departures.end()&&exit->point_valid&&holeNorm(exit->point-c.T)<1e-6,"actual map D differs from T");
                const HolePathPolyline line(points(route));
                for(auto p:line.slice(c.entry_arc-d.entry_straight_length,c.exit_arc+d.exit_straight_length))
                    require(std::abs(holeCross(c.u_in,p-c.E))<1e-6,"actual final path bent inside manual range");
            }
            auto edited=YAML::Clone(root);
            for(auto r:edited["regions"])if(r["id"].as<std::string>()==c.hole_id)
                r["traversal"]["straight_range"]["sides"][0]["extension_length"]=
                    r["traversal"]["straight_range"]["sides"][0]["extension_length"].as<double>()+.01;
            {std::ofstream file(filename+".changed");file<<edited;}
            auto next=std::make_shared<TerrainRegionMap>();require(next->loadFromFile(filename+".changed","map",&error),error);
            require(!planner.validateTerrainUpdate(next,(c.S+c.E)*.5).valid,"active entry range change accepted");
            require(!planner.validateTerrainUpdate(next,(c.X+c.T)*.5).valid,"active exit range change accepted");
            require(planner.validateTerrainUpdate(next,HolePoint{4,4}).valid,"outside reload rejected");
            require(planner.validateTerrainUpdate(terrain,(c.S+c.E)*.5).valid,"unchanged active range rejected");
        }
        std::cout<<"Phase two final multi-hole direction="<<reverse<<" validated, ms="<<planner.holeStatistics().total_ms<<" length="<<HolePathPolyline(points(route)).arc.back()<<std::endl;
    }
    // 损坏文件读取失败时旧对象和旧快照必须保持。
    {std::ofstream file(filename+".bad");file<<"regions: [broken]";}
    require(!terrain->loadFromFile(filename+".bad","map",&error),"malformed reload accepted");
    require(terrain->getRegions().size()==root["regions"].size(),"failed reload lost old snapshot");
}

static void manualRangeTests() {
    const std::string fixture="/tmp/nav_manual_event_terrain.yaml";
    {std::ofstream f(fixture);f<<"regions:\n- id: hole_0\n  type: low_clearance\n  geometry:\n    polygon: [[-.8,0],[.8,0],[.8,.3],[-.8,.3]]\n  traversal: {passable_edges: [0,2]}\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(fixture,"map",&error),error);
    auto config=emptyHolePassageConfig();YAML::Node entry;
    entry["id"]="hole_0";entry["passable_edges"]=std::vector<int>{0,2};entry["prepare_path_distance"]=.2;
    writeHoleStraightRange(entry,HoleStraightRange{0,{.8,.1}});config["holes"].push_back(entry);
    auto adopted=terrain->withHolePassageConfig(config);
    auto node=std::make_shared<rclcpp::Node>("hole_manual_ranges",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.use_global_distances",true),
        rclcpp::Parameter("hole_planner.departure.planning_policy","legacy_constrained"),
        rclcpp::Parameter("hole_planner.global.planning_policy","responsive"),
        rclcpp::Parameter("hole_planner.global.improvement_timeout",0.0)}));
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(adopted);
    auto map=grid();nav_msgs::msg::Path route;bool constrained=false;
    const auto solve=[&](HolePoint start,HolePoint goal) {
        const auto result=planner.planRoute(message({start,{0,.15},goal}),start,goal,map,99,route,constrained);
        require(result.valid&&constrained,"manual route failed: "+result.reason);
        require(planner.validatePath(route,map,99).valid,"manual final route failed");
        require(planner.pathPassages().size()==1&&planner.preparationEvents().size()==1,"manual events missing");
    };
    solve({-1,-2},{.8,.8});
    auto c=planner.pathPassages().front();auto event=planner.preparationEvents().front();
    require(event.point_valid&&event.status=="on_path"&&event.ready_required_at=="E","A state/deadline wrong");
    require(std::abs(event.preparation_arc-c.entry_arc+.2)<1e-8,"A not measured along path");
    require(holeNorm(c.E-c.S)>.79&&holeNorm(event.point-c.S)>.59,"A was merged with S");
    require(holeNorm(planner.departureEvents().front().point-c.T)<1e-6,"manual D was not T");
    const auto equivalent=readHolePassageConfig(YAML::Load(emitHolePassageConfig(config)));
    const auto unchanged=planner.validateTerrainUpdate(terrain->withHolePassageConfig(equivalent),(c.S+c.E)*.5);
    require(unchanged.valid,"unchanged serialized active range rejected: "+unchanged.reason);
    auto bowed=route;
    for(auto &p:bowed.poses)if(p.pose.position.y<-.2&&p.pose.position.y>-.6) {p.pose.position.x+=.00001;break;}
    require(!planner.validatePath(bowed,map,99).valid,"tiny manual-range bend accepted");
    config["holes"][0]["prepare_path_distance"]=1.5;
    planner.setTerrain(terrain->withHolePassageConfig(config));solve({-1,-2},{.8,.8});
    event=planner.preparationEvents().front();c=planner.pathPassages().front();
    require(event.point_valid&&std::abs(event.preparation_arc-c.entry_arc+1.5)<1e-8,"curved A arc wrong");
    require(std::abs(event.point.x)>.01,"curved A still on fictitious axis");
    const HolePathPolyline line(points(route));
    require(holeNorm(event.point-line.at(event.preparation_arc))<1e-8,"A absent from final path");
    require(planner.validatePath(message(line.slice(c.exit_arc+.05,line.arc.back())),map,99).valid,"manual prune failed");
    require(planner.departureEvents().size()==1&&std::abs(planner.departureEvents().front().departure_arc-.05)<1e-6,
        "manual D=T lost after exit pruning");
    solve({0,-.1},{.8,.8});event=planner.preparationEvents().front();
    require(event.status=="before_path"&&!event.point_valid&&event.preparation_required_at_start,"negative A clamped to start");
    solve({0,.1},{.8,.8});event=planner.preparationEvents().front();
    require(event.status=="entry_not_on_path"&&!event.point_valid,"inside start invented entrance A");
    solve({0,2},{0,-2});c=planner.pathPassages().front();
    require(c.entry_edge==2&&std::abs(holeNorm(c.S-c.E)-.1)<1e-8&&std::abs(holeNorm(c.T-c.X)-.8)<1e-8,
        "reverse changed physical range");
    const std::string saved="/tmp/nav_manual_config_roundtrip.yaml",link=saved+".link";
    saveHolePassageConfig(saved,config);std::filesystem::remove(link);std::filesystem::create_symlink(saved,link);
    config["holes"][0]["prepare_path_distance"]=.3;saveHolePassageConfig(link,config);
    require(std::filesystem::is_symlink(link)&&YAML::LoadFile(saved)["holes"][0]["prepare_path_distance"].as<double>()==.3,
        "atomic save lost symlink or data");
    auto invalid=YAML::Clone(config);invalid["holes"][0]["prepare_path_distance"]=-1;
    bool rejected=false;try{saveHolePassageConfig(saved,invalid);}catch(const std::exception &){rejected=true;}
    require(rejected&&YAML::LoadFile(saved)["holes"][0]["prepare_path_distance"].as<double>()==.3,"bad config changed saved file");
    auto second=YAML::Clone(config["holes"][0]);second["id"]="hole_1";config["holes"].push_back(second);
    {std::ofstream f(fixture);f<<"regions:\n";
        for(int i=0;i<2;++i) {const double y=.5*i;
            f<<"- id: hole_"<<i<<"\n  type: low_clearance\n  geometry:\n    polygon: [[-.8,"<<y<<"],[.8,"<<y<<"],[.8,"<<y+.3<<"],[-.8,"<<y+.3<<"]]\n  traversal: {passable_edges: [0,2]}\n";
        }
    }
    require(terrain->loadFromFile(fixture,"map",&error),error);planner.setTerrain(terrain->withHolePassageConfig(config));
    for(int reverse:{0,1}) {
        const HolePoint start{0,reverse?2.0:-2.0},goal{0,reverse?-2.0:2.0};
        const auto check=planner.planRoute(message({start,goal}),start,goal,map,99,route,constrained);
        require(check.valid&&constrained&&planner.validatePath(route,map,99).valid,"manual shared range failed: "+check.reason);
        require(planner.pathPassages().size()==2&&planner.preparationEvents().size()==2&&planner.departureEvents().size()==2,
            "manual shared ranges lost per-hole events");
    }
    std::cout<<"Manual range: exact fixed line, reverse sides, curved/negative/inside A, E deadline, D=T pruning and atomic save passed"<<std::endl;
}

static void phaseThreeTests() {
    auto map=grid();PathSmoother smoother;
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,99,a,b);};
    const HoleHullCheck hull=[&](const auto &p){return checkHoleMapHull(map,99,p);};
    for(auto goal:std::vector<HolePoint>{{1.2,.05},{.2,.01},{.3,-.5}}) {
        const auto tail=planNormalNavigationSegment({0,0},{0,1},goal,smoother,map,99,collision,hull,.01,20000,
            std::chrono::steady_clock::now()+std::chrono::seconds(1));
        require(tail.check.valid,"normal tail failed: "+tail.check.reason);
        require(holeNorm(tail.points.front())<1e-8&&holeNorm(tail.points.back()-goal)<1e-8,"normal endpoint moved");
        require(holeDirectionMatches(tail.points[1]-tail.points[0],{0,1},3),"normal start tangent lost");
        require(tail.length<holeNorm(goal)*2+.5,"normal tail unnecessarily long");
    }
    const std::string fixture="/tmp/nav_phase_three.yaml";
    {std::ofstream f(fixture);f<<"regions:\n- id: hole_0\n  type: low_clearance\n  geometry:\n    polygon: [[-.8,0],[.8,0],[.8,.3],[-.8,.3]]\n  traversal: {passable_edges: [0,2]}\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;require(terrain->loadFromFile(fixture,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_phase_three",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.departure.planning_policy","normal_navigation"),
        rclcpp::Parameter("hole_planner.global.planning_policy","responsive"),
        rclcpp::Parameter("hole_planner.global.improvement_timeout",0.0),
        rclcpp::Parameter("hole_planner.approach.search_prepare_distance",false),
        rclcpp::Parameter("hole_planner.approach.prepare_distance",.4),
        rclcpp::Parameter("hole_planner.approach.entry_straight_length",.2),
        rclcpp::Parameter("hole_planner.departure.exit_straight_length",.1),
        rclcpp::Parameter("hole_planner.departure.departure_distance",.8)}));
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain);
    // 墙面强制穿洞；旧轴线 D 被障碍占据，新策略仍应沿普通末段离开。
    for(double x=-4.95;x<4.95;x+=.025)if(std::abs(x)>.8)occupy(map,{x,.15});
    occupy(map,{0,1.1});
    nav_msgs::msg::Path route;bool constrained=false;
    const auto solve=[&](HolePoint goal,bool global=true) {
        require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.global.enabled",global)}).successful,"global update failed");
        const auto result=planner.planRoute(message({{0,-2},{0,.15},goal}),{0,-2},goal,map,99,route,constrained);
        require(result.valid&&constrained,"normal route failed: "+result.reason);
        require(planner.validatePath(route,map,99).valid,"normal final path invalid");
        require(planner.pathPassages().size()==1,"normal route missed hole");
        const auto &event=planner.departureEvents().front();
        require(event.kind=="path_arc_event"&&event.planning_policy=="normal_navigation","D kind incorrect");
        require(std::abs(event.departure_arc-event.exit_arc-.8)<1e-8,"D not based on final arc");
        require(event.terrain_revision==planner.terrainRevision()&&event.configuration_revision==planner.configurationRevision(),"event version stale");
    };
    solve({1.2,.45});
    auto old=route;
    require(planner.departureEvents().front().point_valid,"curved D event absent");
    const HolePathPolyline path(points(route));
    require(holeNorm(planner.departureEvents().front().point-path.at(planner.departureEvents().front().departure_arc))<1e-8,"D off path");
    require(std::abs(planner.departureEvents().front().point.x)>.05,"D still old axis waypoint");
    const double start_arc=planner.pathPassages().front().exit_arc+.05;
    require(planner.validatePath(message(path.slice(start_arc,path.arc.back())),map,99).valid,"remaining exit path invalid");
    require(planner.departureEvents().size()==1&&std::abs(planner.departureEvents().front().departure_arc-(.8-.05))<1e-8,
        "D lost after pruning past X");
    solve({.2,.45});require(planner.departureEvents().front().status=="beyond_path"&&!planner.departureEvents().front().point_valid,
        "D clamped to short goal");
    solve({1.2,.45},false);
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","free")}).successful,"free update failed");
    solve({1.2,.45},false);
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline"),
        rclcpp::Parameter("hole_planner.departure.planning_policy","legacy_constrained")}).successful,"legacy update failed");
    const auto legacy=planner.planRoute(message({{0,-2},{0,.15},{1.2,.45}}),{0,-2},{1.2,.45},map,99,route,constrained);
    require(!legacy.valid,"legacy ignored blocked mandatory D");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.departure.planning_policy","wrong")}).successful,"invalid policy accepted");
    occupy(map,{0,1.1},0);
    auto legacy_check=planner.planRoute(message({{0,-2},{0,2}}),{0,-2},{0,2},map,99,route,constrained);
    require(legacy_check.valid&&constrained&&planner.validatePath(route,map,99).valid,"legacy straight route regressed");
    require(planner.departureEvents().size()==1&&planner.departureEvents().front().kind=="axis_waypoint"&&
        planner.departureEvents().front().point_valid,"legacy actual D event lost");
    occupy(map,{0,1.1});

    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.global.enabled",true),
        rclcpp::Parameter("hole_planner.departure.planning_policy","normal_navigation")}).successful,"normal reset failed");
    // 同轴固定段重叠，第二洞 A 已在共享直线内；不能回退到 A 或延伸到旧 D。
    {std::ofstream f(fixture);f<<"regions:\n";
        for(int i=0;i<2;++i){double y=.5*i;
            f<<"- id: hole_"<<i<<"\n  type: low_clearance\n  geometry:\n    polygon: [[-.8,"<<y<<"],[.8,"<<y<<"],[.8,"<<y+.3<<"],[-.8,"<<y+.3<<"]]\n  traversal: {passable_edges: [0,2]}\n";}}
    terrain=std::make_shared<TerrainRegionMap>();require(terrain->loadFromFile(fixture,"map",&error),error);planner.setTerrain(terrain);
    auto check=planner.planRoute(message({{0,-2},{0,.6},{.8,1.1}}),{0,-2},{.8,1.1},map,99,route,constrained);
    require(check.valid&&constrained,"new shared route failed: "+check.reason);
    require(planner.validatePath(route,map,99).valid&&planner.pathPassages().size()==2&&planner.departureEvents().size()==2,
        "new shared route/event count incorrect");
    check=planner.planRoute(message({{0,.1},{0,.6},{.8,1.1}}),{0,.1},{.8,1.1},map,99,route,constrained);
    require(check.valid&&constrained&&planner.validatePath(route,map,99).valid,"new inside-start route failed: "+check.reason);
    check=planner.planRoute(message({{0,-2},{0,.15}}),{0,-2},{0,.15},map,99,route,constrained);
    require(check.valid&&constrained&&planner.validatePath(route,map,99).valid,"new inside-goal route failed: "+check.reason);
    require(planner.departureEvents().size()==1&&planner.departureEvents().front().status=="exit_not_reached"&&
        !planner.departureEvents().front().point_valid,"inside goal reported complete departure");
    std::cout<<"Phase three: ordinary tails, fixed passages, curved/beyond-path/pruned D, free, single and legacy passed"<<std::endl;
}

static void feasibleApproachTests() {
    auto map=grid();HoleConnectionOptimizationParams optimization;HoleConnectionSearchParams search;
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,99,a,b);};
    const HoleHullCheck hull=[&](const auto &p){return checkHoleMapHull(map,99,p);};
    const auto solve=[&](const HoleHullCheck &check,const std::vector<HolePoint> &targets) {
        return planFeasibleHoleApproach({-1,-1},targets,std::nullopt,HolePoint{0,1},optimization,
            search,map,collision,check,{},std::chrono::steady_clock::now()+std::chrono::seconds(1));
    };
    auto smooth=solve(hull,{{1,1}});
    require(smooth.check.valid&&smooth.check.reason=="FEASIBLE_APPROACH_CONTINUOUS"&&!smooth.spans.empty(),
        "open approach did not retain whole-connection spline optimization");
    require(holeDirectionMatches(smooth.points.back()-smooth.points[smooth.points.size()-2],{0,1},3),"preferred S tangent not aligned");
    std::vector<HolePoint> checked;double observed=0;
    require(validateHoleCurve(smooth.spans,hull,search.sample_resolution,std::nullopt,
        std::chrono::steady_clock::now()+std::chrono::seconds(1),checked,observed).valid,"reversed spline/cache spans invalid");
    auto forward=planFeasibleHoleApproach({-1,-1},{{1,1}},HolePoint{1,0},HolePoint{0,1},optimization,
        search,map,collision,hull,{},std::chrono::steady_clock::now()+std::chrono::seconds(1));
    require(forward.check.valid&&!forward.spans.empty(),"hole-to-hole forward spline missing");
    require(holeDirectionMatches(forward.points[1]-forward.points[0],{1,0},3)&&
        holeDirectionMatches(forward.points.back()-forward.points[forward.points.size()-2],{0,1},3),
        "hole-to-hole boundary tangents changed");
    // 模拟窄角：折线合法，但任何圆滑曲线均不能被连续凸包检查证明合法。
    const HoleHullCheck reject_curves=[](const auto &p){return holeCheck(false,"TEST_BLOCKED_ROUNDING",p.front());};
    auto fallback=solve(reject_curves,{{1,1}});
    require(fallback.check.valid&&fallback.retained_corners>0&&fallback.rounded_corners==0,"valid baseline lost on smoothing failure");
    require(!fallback.smoothing_failure.empty()&&fallback.spans.empty(),"failed spline did not downgrade cleanly");
    auto mandatory=solve(reject_curves,{{-1,1},{1,1}});
    require(mandatory.check.valid,"mandatory approach failed");
    require(std::any_of(mandatory.points.begin(),mandatory.points.end(),[](auto p){return holeNorm(p-HolePoint{-1,1})<1e-9;}),"legacy mandatory point skipped");
    auto smoothed_mandatory=solve(hull,{{-1,1},{1,1}});
    require(smoothed_mandatory.check.valid&&std::any_of(smoothed_mandatory.points.begin(),smoothed_mandatory.points.end(),
        [](auto p){return holeNorm(p-HolePoint{-1,1})<1e-7;}),"whole spline skipped mandatory waypoint");
    optimization.approach_smoothing_timeout=1e-9;
    auto timed_out=solve(hull,{{1,1}});
    require(timed_out.check.valid&&timed_out.spans.empty()&&timed_out.smoothing_failure.find("TIMEOUT")!=std::string::npos,
        "spline timeout lost feasible fallback");
    optimization.approach_smoothing_timeout=0;
    auto local_only=solve(hull,{{1,1}});
    require(local_only.check.valid&&local_only.spans.empty()&&local_only.rounded_corners>0&&local_only.smoothing_failure.empty(),
        "zero smoothing budget did not retain local fallback");
    optimization.approach_smoothing_timeout=.2;
    for(const auto *result:{&smooth,&forward,&fallback,&mandatory,&smoothed_mandatory,&timed_out,&local_only}) {
        require(holeNorm(result->points.front()-HolePoint{-1,-1})<1e-9&&holeNorm(result->points.back()-HolePoint{1,1})<1e-9,"approach endpoint moved");
        for(std::size_t i=1;i<result->points.size();++i) {
            require(holeNorm(result->points[i]-result->points[i-1])<=search.sample_resolution*1.001,"approach undersampled");
            require(collision(result->points[i-1],result->points[i]).valid,"approach segment collision");
        }
    }
    // 禁止穿墙，即使有折线后备也必须拒绝真正不可达的目标。
    for(double y=-4.975;y<5;y+=.025)occupy(map,{0,y});
    search.max_expansions=5000;
    require(!solve(hull,{{1,1}}).check.valid,"feasibility policy accepted blocked route");
    map=grid();
    const std::string filename="/tmp/nav_feasible_approach_terrain.yaml";
    {std::ofstream f(filename);f<<"regions:\n- id: hole_0\n  type: low_clearance\n  geometry:\n    polygon: [[-.8,0],[.8,0],[.8,.3],[-.8,.3]]\n  traversal: {passable_edges: [0,2]}\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(filename,"map",&error),error);
    auto config=emptyHolePassageConfig();YAML::Node entry;entry["id"]="hole_0";
    entry["passable_edges"]=std::vector<int>{0,2};entry["prepare_path_distance"]=.2;
    writeHoleStraightRange(entry,HoleStraightRange{0,{.8,.1}});config["holes"].push_back(entry);
    auto node=std::make_shared<rclcpp::Node>("feasible_approach_test",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline")}));
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain->withHolePassageConfig(config));
    const auto corner=message({{-1,-.8},{0,-.8},{0,0},{0,.3},{0,.4},{1,.4}});
    require(!planner.validatePath(corner,map,99).valid,"old configuration default no longer continuous");
    auto revision=planner.configurationRevision();
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.approach_policy","feasibility_first")}).successful,"policy update rejected");
    require(planner.validatePath(corner,map,99).valid,"allowed external corner rejected");
    require(planner.configurationRevision()>revision,"policy did not invalidate configuration/cache revision");
    revision=planner.configurationRevision();
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.smoothing_timeout",.15)}).successful,
        "smoothing budget update rejected");
    planner.refreshConfiguration();require(planner.configurationRevision()>revision,"smoothing budget did not invalidate cache revision");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.smoothing_timeout",-.1)}).successful,
        "negative smoothing budget accepted");
    auto bent=corner;bent.poses.insert(bent.poses.begin()+3,message({{.01,.15}}).poses.front());
    require(!planner.validatePath(bent,map,99).valid,"bent fixed S-T accepted");
    const HolePathPolyline polyline(points(corner));
    require(planner.validatePath(message(polyline.slice(1.4,polyline.arc.back())),map,99).valid,"partial fixed range corner rejected");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.enforce_max_curvature",true)}).successful,"hard curvature update failed");
    require(!planner.validatePath(corner,map,99).valid,"external corner bypassed hard curvature policy");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.approach_policy","wrong")}).successful,"invalid policy accepted");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.connection.enforce_max_curvature",false),
        rclcpp::Parameter("hole_planner.global.enabled",false)}).successful,"single-hole policy update failed");
    nav_msgs::msg::Path single;bool constrained=false;
    auto single_check=planner.planRoute(message({{-1,-.8},{0,.15},{1,.8}}),{-1,-.8},{1,.8},map,99,single,constrained);
    require(single_check.valid&&constrained&&planner.validatePath(single,map,99).valid,"single-hole feasible approach failed: "+single_check.reason);
    require(!planner.routeAttempts().empty()&&planner.routeAttempts().back().approach_method.find("FEASIBLE_APPROACH")==0,
        "single-hole approach did not use feasibility policy");
    // S=E、T=X 时重复接缝不能把允许的外侧折角再次判为失败，洞内仍须严格直行。
    writeHoleStraightRange(config["holes"][0],HoleStraightRange{0,{0,0}});
    planner.setTerrain(terrain->withHolePassageConfig(config));
    require(planner.validatePath(message({{-1,-1},{0,0},{0,.3},{1,1.3}}),map,99).valid,
        "zero extension external corner rejected");
    std::cout<<"Feasible approach: smooth preference, fallback, mandatory points, collision, exact S-T, partial range and policy gates passed"<<std::endl;
}

static void feasibleApproachActualTests(const std::string &map_file,const std::string &terrain_file,const std::string &params_file) {
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(terrain_file,"map",&error),error);
    terrain=terrain->withHolePassageConfig(readHolePassageConfig(YAML::LoadFile(
        (std::filesystem::path(terrain_file).parent_path()/"hole_passages.yaml").string())));
    auto node=std::make_shared<rclcpp::Node>("nav_server",rclcpp::NodeOptions().arguments({"--ros-args","--params-file",params_file}));
    auto tf=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    auto manager=std::make_shared<LayeredMapManager>();manager->initialize(node.get(),tf);
    manager->setHoleClearance(terrain,true,.5,.5);InflationParams inflation;
    inflation.inflation_radius=.8;inflation.inscribed_radius=.2;inflation.cost_scaling=1.8;
    require(manager->loadStaticMap(map_file,inflation),"feasible real map load failed");
    SimplePlanner planner;planner.initialize(node.get());planner.setTerrainRegionMap(terrain);planner.setMap(manager);
    HolePassagePlanner validator;validator.initialize(node.get());validator.setTerrain(terrain);
    struct Request {HolePoint start,goal;int holes;};
    const std::vector<Request> requests{{{1.67238,-5.43273},{-5.51016,-5.02066},1},
        {{4.694,6},{-2,7.604},2},{{-2,7.604},{4.694,6},2},
        {{7.19051,-1.46586},{-6.45515,-.423561},2}};
    for(std::size_t i=0;i<requests.size();++i) {
        const auto &request=requests[i];planner.clearCache();nav_msgs::msg::Path route;
        const auto seed=message({request.start,request.goal});
        require(planner.plan(seed.poses.front(),seed.poses.back(),route),"feasible actual request failed: "+std::to_string(i));
        const auto check=validator.validatePath(route,*manager->getCostmap(),99);
        require(check.valid,"independent final route check: "+check.reason);
        require(validator.pathPassages().size()==static_cast<std::size_t>(request.holes),"unexpected number of holes");
        const HolePathPolyline path(points(route));
        std::cout<<"Feasible actual request="<<i<<" ms="<<planner.holeStatistics().total_ms<<" holes=";
        for(const auto &c:validator.pathPassages()) {
            std::cout<<c.hole_id<<" ";
            for(auto p:path.slice(c.entry_arc-holeNorm(c.E-c.S),c.exit_arc+holeNorm(c.T-c.X)))
                require(std::abs(holeCross(c.u_in,p-c.E))<1e-6,"manual fixed straight range changed");
        }
        std::cout<<" length="<<path.arc.back()<<std::endl;
        {std::ofstream out("/tmp/nav_feasible_approach_route_"+std::to_string(i)+".csv");
            for(auto p:points(route))out<<p.x<<","<<p.y<<"\n";}
    }
}

int main(int argc,char **argv) {
    try {
        if(argc>1&&std::string(argv[1])=="--feasible-approach") {
            require(argc==5,"expected map, terrain and parameters");rclcpp::init(argc,argv);
            feasibleApproachTests();feasibleApproachActualTests(argv[2],argv[3],argv[4]);rclcpp::shutdown();return 0;
        }
        if(argc>1&&std::string(argv[1])=="--manual-core") {
            rclcpp::init(argc,argv);manualRangeTests();rclcpp::shutdown();return 0;
        }
        if(argc>1&&std::string(argv[1])=="--manual-range") {
            require(argc==5,"expected map, terrain and parameters");rclcpp::init(argc,argv);
            manualRangeTests();phaseTwoRangeTests(argv[2],argv[3],argv[4],true);rclcpp::shutdown();return 0;
        }
        if(argc>1&&std::string(argv[1])=="--phase-three") {rclcpp::init(argc,argv);phaseThreeTests();rclcpp::shutdown();return 0;}
        if(argc>1 && std::string(argv[1])=="--phase-two-range") {
            require(argc==5,"expected map, terrain and parameters");rclcpp::init(argc,argv);
            phaseTwoRangeTests(argv[2],argv[3],argv[4]);rclcpp::shutdown();return 0;
        }
        if(argc>1&&(std::string(argv[1])=="--actual-multi"||std::string(argv[1])=="--phase-one-cache")) {
            require(argc==5,"expected map, terrain and parameters");const bool cache_only=std::string(argv[1])=="--phase-one-cache";
            rclcpp::init(argc,argv);actualMultiHoleTests(argv[2],argv[3],argv[4],cache_only);rclcpp::shutdown();return 0;
        }
        if(std::getenv("NAV_HOLE_OPTIMIZATION_ONLY")){rclcpp::init(argc,argv);optimizationTests();rclcpp::shutdown();return 0;}
        if(std::getenv("NAV_HOLE_GLOBAL_ONLY")) {rclcpp::init(argc,argv);globalRouteTests();rclcpp::shutdown();return 0;}
        require(argc==3,"expected actual map and terrain");searchTests();rclcpp::init(argc,argv);optimizationTests();
        routeTests();optimizedRouteTests();rotatedAndOverrideTests();ordinaryPlannerTests();globalRouteTests();actualMapTests(argv[1],argv[2]);rclcpp::shutdown();return 0;
    } catch(const std::exception &e) {std::cerr<<e.what()<<'\n';if(rclcpp::ok()) rclcpp::shutdown();return 1;}
}
