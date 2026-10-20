#include "nav_components/hole_passage_planner.hpp"
#include "nav_components/simple_planner.hpp"
#include "nav_components/layered_map_manager.hpp"
#include <tf2_ros/buffer.h>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>

using namespace nav_core;
using namespace nav_components;
static void require(bool ok,const std::string &why) {if(!ok) throw std::runtime_error(why);}
static void expectFailure(const HolePassageCheck &c,const std::string &reason) {
    require(!c.valid && c.reason.find(reason)!=std::string::npos,"expected "+reason+", got "+c.reason);
}
static nav_msgs::msg::OccupancyGrid grid() {
    nav_msgs::msg::OccupancyGrid map;map.header.frame_id="map";
    map.info.width=120;map.info.height=100;map.info.resolution=0.1;
    map.info.origin.position.x=-5;map.info.origin.position.y=-5;map.info.origin.orientation.w=1;
    map.data.assign(12000,0);return map;
}
static nav_msgs::msg::Path message(const std::vector<HolePoint> &points) {
    nav_msgs::msg::Path path;path.header.frame_id="map";
    for(auto p:points) {geometry_msgs::msg::PoseStamped pose;pose.header=path.header;
        pose.pose.position.x=p.x;pose.pose.position.y=p.y;pose.pose.orientation.w=1;path.poses.push_back(pose);}
    return path;
}
static void setCell(nav_msgs::msg::OccupancyGrid &map,HolePoint point,int8_t value) {
    const int x=static_cast<int>(std::floor((point.x-map.info.origin.position.x)/map.info.resolution));
    const int y=static_cast<int>(std::floor((point.y-map.info.origin.position.y)/map.info.resolution));
    map.data[y*map.info.width+x]=value;
}
static HolePassageCheck validate(const HoleGeometryPreview &g,HoleTraversalDistances d,
        std::vector<HolePoint> points,HolePassageMode mode,const nav_msgs::msg::OccupancyGrid &map,
        HolePassageValidationParams params={}) {
    HolePathPolyline path(points);const auto crosses=holePathCrossings(g,path);
    require(crosses.size()==1,"expected one passage");
    return validateHolePathPassage(g,d,params,path,crosses[0],mode,
        [&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,99,a,b);});
}
static void geometryTests() {
    const HoleGeometryInput input{"hole","map",{{-2,0},{2,0},{2,1},{-2,1}},0,true,true};
    const HoleTraversalDistances d{1.5,0.8,0.5,0.8};
    const auto g=buildHoleGeometry(input,{},d);require(g.valid,g.reason);
    auto map=grid();
    const HoleSegmentCheck collision=[&](HolePoint a,HolePoint b){return checkHoleMapSegment(map,99,a,b);};
    for(const auto &direction:g.directions) {
        auto c=centerlineHoleCandidate(g,direction);
        require(validateHoleCandidate(g,d,{},c,collision).valid,"centerline direction rejected");
        const std::vector<HolePoint> p{direction.A,direction.S,direction.E,direction.X,direction.T,direction.D};
        require(validate(g,d,p,HolePassageMode::Centerline,map).valid,"strict path rejected");
    }
    const std::vector<HolePoint> shifted{{0.6,-2},{0.6,0},{0.6,1},{0.6,2}};
    require(validate(g,d,shifted,HolePassageMode::Free,map).valid,"free offset rejected");
    const std::vector<HolePoint> curved{{0.6,-2},{0.6,0},{0.6,0.1},{0.8,0.5},{0.6,0.9},{0.6,1},{0.6,2}};
    require(validate(g,d,curved,HolePassageMode::Free,map).valid,"legal free inside curve rejected");
    expectFailure(validate(g,d,shifted,HolePassageMode::Centerline,map),"CENTERLINE_MISMATCH");
    expectFailure(validate(g,d,{{0,-0.2},{0,0},{0,1},{0,2}},HolePassageMode::Free,map),"INSUFFICIENT_STRAIGHT_LENGTH");
    expectFailure(validate(g,d,{{0,-2},{0,0},{0,1},{0,1.1}},HolePassageMode::Free,map),"INSUFFICIENT_STRAIGHT_LENGTH");
    expectFailure(validate(g,d,{{-1,-2},{0,-0.8},{0,0},{0,1},{0,2}},HolePassageMode::Free,map),"CONNECTION_TANGENT");
    expectFailure(validate(g,d,{{-1,-2},{0,0},{0,1},{0,2}},HolePassageMode::Free,map),"STRAIGHT_PATH");
    expectFailure(validate(g,d,{{-3,0.5},{0,0.5},{3,0.5}},HolePassageMode::Free,map),"INVALID_PASSAGE_EDGES");
    expectFailure(validate(g,d,{{-3,-1},{-2,0},{0,0.5},{2,1},{3,2}},HolePassageMode::Free,map),"INVALID_ENTRY_EXIT");
    expectFailure(validate(g,d,{{0,0.5},{0,2}},HolePassageMode::Free,map),"PARTIAL_PASSAGE");
    auto one_way=input;one_way.bidirectional=false;const auto single=buildHoleGeometry(one_way,{},d);
    expectFailure(validate(single,d,{{0,2},{0,1},{0,0},{0,-2}},HolePassageMode::Free,map),"INVALID_PASSAGE_EDGES");
    HolePassageValidationParams margin;margin.side_margin=0.3;
    expectFailure(validate(g,d,{{1.9,-2},{1.9,0},{1.9,1},{1.9,2}},HolePassageMode::Free,map,margin),"SIDE_MARGIN");
    const HoleTraversalDistances zero{0,0,0,0};
    require(validate(g,zero,shifted,HolePassageMode::Free,map).valid,"zero straight length rejected");
    HolePathPolyline repeat({{0,-2},{0,2},{1,2},{1,-2}});
    require(holePathCrossings(g,repeat).size()==2,"multiple passages not detected");
    HolePathPolyline bypass({{-3,-2},{-3,2}});
    require(holePathCrossings(g,bypass).empty(),"bypass generated passage");
    HolePathPolyline grazing({{-3,0},{3,0}});
    require(holePathCrossings(g,grazing).empty(),"boundary grazing generated passage");
    // 两个稀疏采样点均在洞外，仍须准确识别进出边及弧长。
    HolePathPolyline sparse({{0,-2},{0,2}});const auto c=holePathCrossings(g,sparse).front();
    require(std::abs(c.entry_arc-2)<1e-9&&std::abs(c.exit_arc-3)<1e-9,"sparse crossing arcs wrong");
    auto candidate=freeHoleCandidate(g,d,sparse,c);candidate.T.y-=0.1;
    expectFailure(validateHoleCandidate(g,d,{},candidate,collision),"STRAIGHT_LENGTH");
    // 候选直线独立查障：原始自主路径不会自动被当作符合直线的最终路径。
    candidate=centerlineHoleCandidate(g,g.directions[0]);
    auto adjusted=freeHoleCandidate(g,d,sparse,c);
    adjusted.E.x=adjusted.X.x=0.7;adjusted.S.x=adjusted.T.x=0.7;
    adjusted.inside={adjusted.E,adjusted.X};
    require(validateHoleCandidate(g,d,{},adjusted,collision).valid,"adjusted entry and exit candidate rejected");
    setCell(map,{0,-0.45},100);
    expectFailure(validateHoleCandidate(g,d,{},candidate,collision),"STRAIGHT_SEGMENT_BLOCKED");
    setCell(map,{0,-0.45},0);setCell(map,{0,0.55},100);
    expectFailure(validateHoleCandidate(g,d,{},candidate,collision),"PASSAGE_BLOCKED");
    map=grid();
    for(int angle=0;angle<360;++angle) {
        const double rad=angle*3.14159265358979323846/180;
        const auto rotate=[&](HolePoint p){return HolePoint{std::cos(rad)*p.x-std::sin(rad)*p.y,
            std::sin(rad)*p.x+std::cos(rad)*p.y};};
        auto rotated=input;for(auto &p:rotated.polygon)p=rotate(p);
        if(angle%2) std::reverse(rotated.polygon.begin(),rotated.polygon.end());
        const auto geo=buildHoleGeometry(rotated,{},d);require(geo.valid,geo.reason);
        for(const auto &direction:geo.directions) {
            require(validateHoleCandidate(geo,d,{},centerlineHoleCandidate(geo,direction),collision).valid,"rotated candidate rejected");
            std::vector<HolePoint> points;
            for(auto p:std::vector<HolePoint>{{0.4,-2},{0.4,0},{0.4,1},{0.4,2}})points.push_back(rotate(p));
            require(validate(geo,d,points,HolePassageMode::Free,map).valid,"rotated free passage rejected");
        }
    }
    std::cout<<"Geometry: both modes, directions, sparse crossings, seams, 360 rotations passed\n";
}
static void collisionTests() {
    auto map=grid();
    // 单个障碍位于两个路径端点之间，包含角点接触、沿栅格线、未知及越界。
    setCell(map,{0.01,0.01},100);
    expectFailure(checkHoleMapSegment(map,99,{-1,-1},{1,1}),"OCCUPIED");
    expectFailure(checkHoleMapSegment(map,99,{-1,0.01},{1,0.01}),"OCCUPIED");
    setCell(map,{0.01,0.01},-1);
    expectFailure(checkHoleMapSegment(map,99,{-1,0.01},{1,0.01}),"UNKNOWN");
    expectFailure(checkHoleMapSegment(map,99,{-5.01,0},{0,0}),"OUT_OF_MAP");
    expectFailure(checkHoleMapSegment(map,99,{NAN,0},{0,0}),"INVALID_MAP");
    map.info.origin.orientation.z=0.1;
    expectFailure(checkHoleMapSegment(map,99,{0,0},{1,0}),"INVALID_MAP");
    // 用独立的线段/栅格闭矩形相交判定核对 supercover，避免采样式测试漏掉小交集。
    auto small=grid();small.info.width=8;small.info.height=8;small.info.resolution=1;
    small.info.origin.position.x=0;small.info.origin.position.y=0;small.data.assign(64,0);
    std::mt19937 gen(7);std::uniform_real_distribution<double> random(0.01,7.99);
    for(int n=0;n<400;++n) {
        const HolePoint a{random(gen),random(gen)},b{random(gen),random(gen)};
        const int cell=n%64,x=cell%8,y=cell/8;
        small.data[cell]=100;
        double lo=0,hi=1;
        bool hit=true;
        for(auto axis : {std::array<double,3>{a.x,b.x-a.x,static_cast<double>(x)},
                         std::array<double,3>{a.y,b.y-a.y,static_cast<double>(y)}}) {
            if(std::abs(axis[1])<1e-14) {if(axis[0]<axis[2]||axis[0]>axis[2]+1)hit=false;}
            else {double first=(axis[2]-axis[0])/axis[1],last=(axis[2]+1-axis[0])/axis[1];
                if(first>last)std::swap(first,last);lo=std::max(lo,first);hi=std::min(hi,last);}
        }
        hit=hit&&lo<=hi;
        require(checkHoleMapSegment(small,99,a,b).valid==!hit,"continuous grid traversal disagrees with rectangle intersection");
        small.data[cell]=0;
    }
    std::cout<<"Collision: grid supercover vs 400 independent rectangle intersections passed\n";
}
static void rosTests(const std::string &real_terrain) {
    const std::string fixture="/tmp/nav_hole_stage_two_terrain.yaml";
    {std::ofstream f(fixture);f<<"regions:\n- id: test_hole\n  type: low_clearance\n  frame_id: map\n  geometry:\n    polygon: [[-2, 0], [2, 0], [2, 1], [-2, 1]]\n  traversal: {passable_edges: [0, 2], bidirectional: true}\n";}
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(fixture,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_passage_test");
    HolePassagePlanner planner;planner.initialize(node.get());planner.setTerrain(terrain);
    auto peer=std::make_shared<rclcpp::Node>("hole_passage_markers_peer");
    visualization_msgs::msg::MarkerArray received;bool have_message=false;
    auto subscription=peer->create_subscription<visualization_msgs::msg::MarkerArray>(
        "hole_passage_markers",rclcpp::QoS(1).transient_local().reliable(),
        [&](visualization_msgs::msg::MarkerArray::ConstSharedPtr m){received=*m;have_message=true;});
    const auto waitMarkers=[&](const std::function<bool()> &ready) {
        const auto until=std::chrono::steady_clock::now()+std::chrono::seconds(3);
        while(std::chrono::steady_clock::now()<until) {
            rclcpp::spin_some(node);rclcpp::spin_some(peer);
            if(have_message&&ready()) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        throw std::runtime_error("candidate markers timed out");
    };
    auto map=grid();const auto path=message({{0.6,-2},{0.6,0},{0.6,1},{0.6,2}});
    require(planner.validatePath(path,map,99).valid,"disabled planner changed behavior");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","typo")}).successful,"invalid mode accepted");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.validation.waypoint_tolerance",-1.0)}).successful,"invalid tolerance accepted");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.enabled",true)}).successful,"enable rejected");
    planner.buildCandidates(path,map,99);
    require(planner.candidates().size()==1&&planner.candidates()[0].check.valid,"free candidate not generated");
    require(planner.validatePath(path,map,99).valid,"free ROS passage rejected");
    require(planner.pathPassages().size()==1,"path passage not retained");
    waitMarkers([&](){return received.markers.size()>=5;});
    bool candidate_label=false,path_label=false;
    for(const auto &m:received.markers) {
        candidate_label|=m.text.find("candidate only: CANDIDATE_VALID")!=std::string::npos;
        path_label|=m.text.find("path: PATH_PASSAGE_VALID")!=std::string::npos;
    }
    require(candidate_label&&path_label,"candidates confused with validated final path");
    const auto revision=planner.configurationRevision();
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline")}).successful,"mode switch rejected");
    expectFailure(planner.validatePath(path,map,99),"CENTERLINE_MISMATCH");
    require(planner.configurationRevision()>revision&&planner.candidates().empty(),"mode switch left candidate cache");
    planner.buildCandidates(path,map,99);require(planner.candidates().size()==2,"strict bidirectional candidates missing");
    // 最新融合图模拟动态障碍，已通过的候选必须在重新校验时拒绝。
    const auto centered=message({{0,-2},{0,0},{0,1},{0,2}});
    require(planner.validatePath(centered,map,99).valid,"strict centered path rejected");
    bool active=true;planner.setExecutionActivePredicate([&](){return active;});
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","free")}).successful,
        "mode changed during traversal");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.prepare_distance",1.7)}).successful,
        "normal navigation rejected live distance update");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.entry_straight_length",2.0)}).successful,
        "active navigation accepted invalid distance ordering");
    active=false;
    setCell(map,{0,0.55},100);expectFailure(planner.validatePath(centered,map,99),"OCCUPIED");
    map=grid();
    planner.buildCandidates(message({{-3,-2},{-3,2}}),map,99);
    require(planner.validatePath(message({{-3,-2},{-3,2}}),map,99).valid&&planner.pathPassages().empty(),"bypass not retained");
    const auto malformed=message({{0,-2},{NAN,0},{0,2}});
    expectFailure(planner.validatePath(malformed,map,99),"INVALID_PATH");
    const std::string overrides="/tmp/nav_hole_stage_two_overrides.yaml";
    {std::ofstream f(overrides);f<<"regions:\n- id: override_hole\n  type: low_clearance\n  geometry:\n    polygon: [[-2,0],[2,0],[2,1],[-2,1]]\n  traversal: {passable_edges: [0,2], prepare_distance: 0.5, entry_straight_length: 0.2, exit_straight_length: 0.1, departure_distance: 0.3}\n";}
    auto single=std::make_shared<TerrainRegionMap>();require(single->loadFromFile(overrides,"map",&error),error);
    planner.setTerrain(single);
    planner.buildCandidates(centered,map,99);
    require(planner.candidates().size()==2,"override candidates missing");
    require(std::abs(holeNorm(planner.candidates()[0].S-planner.candidates()[0].E)-0.2)<1e-9,"single hole distances ignored");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.use_global_distances",true),
        rclcpp::Parameter("hole_planner.approach.prepare_distance",1.8),rclcpp::Parameter("hole_planner.approach.entry_straight_length",0.9),
        rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.6),rclcpp::Parameter("hole_planner.departure.departure_distance",1.0)}).successful,
        "global distance update rejected");
    planner.buildCandidates(centered,map,99);
    require(std::abs(holeNorm(planner.candidates()[0].S-planner.candidates()[0].E)-0.9)<1e-9,"terrain override masked global S distance");
    require(std::abs(holeNorm(planner.candidates()[0].T-planner.candidates()[0].X)-0.6)<1e-9,"terrain override masked global T distance");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.use_global_distances",false),
        rclcpp::Parameter("hole_planner.approach.prepare_distance",1.7),rclcpp::Parameter("hole_planner.approach.entry_straight_length",0.8),
        rclcpp::Parameter("hole_planner.departure.exit_straight_length",0.5),rclcpp::Parameter("hole_planner.departure.departure_distance",0.8)}).successful,
        "restore per-hole distances rejected");
    require(!node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.entry_straight_length",2.0)}).successful,"invalid distances accepted");
    // 真实地形上的四洞，每洞两方向候选均使用真实清障/膨胀图复测（下方地图管理器）。
    auto actual=std::make_shared<TerrainRegionMap>();require(actual->loadFromFile(real_terrain,"map",&error),error);
    planner.setTerrain(actual);
    planner.buildCandidates(centered,map,99);
    require(planner.candidates().size()==8,"four actual holes must produce eight candidates");
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.publish_debug_markers",false)}).successful,"marker disable failed");
    planner.refreshConfiguration();
    waitMarkers([&](){return received.markers.size()==1&&received.markers.front().action==visualization_msgs::msg::Marker::DELETEALL;});
    std::cout<<"ROS parameters, cache invalidation, bypass and dynamic obstacle passed\n";
}
static void integrationTests(const std::string &map_file,const std::string &terrain_file) {
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(terrain_file,"map",&error),error);
    auto node=std::make_shared<rclcpp::Node>("hole_stage_two_integration");
    auto tf=std::make_shared<tf2_ros::Buffer>(node->get_clock());
    auto manager=std::make_shared<LayeredMapManager>();manager->initialize(node.get(),tf);
    manager->setHoleClearance(terrain,true,0.5,0.5);
    InflationParams inflation;require(manager->loadStaticMap(map_file,inflation),"actual map load failed");
    HolePassagePlanner check;check.initialize(node.get());check.setTerrain(terrain);
    require(node->set_parameters_atomically({rclcpp::Parameter("hole_planner.enabled",true),rclcpp::Parameter("hole_planner.mode","centerline")}).successful,"actual enable failed");
    auto costmap=manager->getCostmap();require(static_cast<bool>(costmap),"actual costmap missing");
    check.buildCandidates(message({{0,0},{1,1}}),*costmap,99);
    require(check.candidates().size()==8,"actual eight directions missing");
    for(const auto &c:check.candidates()) {
        require(c.check.valid,c.hole_id+" actual candidate: "+c.check.reason);
        require(check.validatePath(message({c.S,c.E,c.X,c.T}),*costmap,99).valid,c.hole_id+" actual path rejected");
    }
    std::cout<<"Four actual holes: eight strict directions pass fused costmap checks\n";
    // SimplePlanner 接入验收：普通允许偏移、严格拒绝偏移、开关关闭恢复旧路径。
    const std::string fixture="/tmp/nav_hole_stage_two_terrain.yaml";
    auto synthetic=std::make_shared<TerrainRegionMap>();require(synthetic->loadFromFile(fixture,"map",&error),error);
    const std::string pgm="/tmp/nav_hole_stage_two_map.pgm",yaml="/tmp/nav_hole_stage_two_map.yaml";
    {std::ofstream f(pgm,std::ios::binary);f<<"P5\n120 100\n255\n";std::string pixels(12000,static_cast<char>(254));f.write(pixels.data(),pixels.size());}
    {std::ofstream f(yaml);f<<"image: "<<pgm<<"\nresolution: 0.1\norigin: [-5,-5,0]\nnegate: 0\noccupied_thresh: 0.65\nfree_thresh: 0.25\n";}
    auto pnode=std::make_shared<rclcpp::Node>("hole_simple_planner_test",rclcpp::NodeOptions().parameter_overrides({
        rclcpp::Parameter("planner.enable_smooth",false),rclcpp::Parameter("hole_planner.enabled",true)}));
    auto ptf=std::make_shared<tf2_ros::Buffer>(pnode->get_clock());
    auto pmap=std::make_shared<LayeredMapManager>();pmap->initialize(pnode.get(),ptf);
    require(pmap->loadStaticMap(yaml,inflation),"synthetic map failed");
    SimplePlanner planner;planner.initialize(pnode.get());planner.setTerrainRegionMap(synthetic);planner.setMap(pmap);
    auto start=message({{0.65,-2.05}}).poses.front(),goal=message({{0.65,2.05}}).poses.front();
    nav_msgs::msg::Path path;
    require(planner.plan(start,goal,path),"free integrated straight plan failed");
    require(pnode->set_parameters_atomically({rclcpp::Parameter("hole_planner.mode","centerline")}).successful,"integrated switch failed");
    require(!planner.validatePath(path),"strict accepted cached offset path");
    require(planner.plan(start,goal,path),"strict did not generate constrained replacement for offset seed");
    require(planner.validatePath(path),"strict generated path invalid");
    require(pnode->set_parameters_atomically({rclcpp::Parameter("hole_planner.enabled",false)}).successful,"integrated disable failed");
    require(planner.plan(start,goal,path),"disable did not restore ordinary planning");
    require(pnode->set_parameters_atomically({rclcpp::Parameter("hole_planner.enabled",true),
        rclcpp::Parameter("hole_planner.mode","free")}).successful,"re-enable failed");
    require(planner.plan(start,goal,path),"free replan failed");
    auto local=std::make_shared<nav_msgs::msg::OccupancyGrid>();
    local->header.frame_id="map";local->info.width=local->info.height=1;
    local->info.resolution=0.1;local->info.origin.position.x=0.6;
    local->info.origin.position.y=0.5;local->info.origin.orientation.w=1;local->data={100};
    pmap->updateDynamicLayer(local);
    require(!planner.validatePath(path),"fused dynamic obstacle inside cleared passage was ignored");
    require(planner.validatePath(path)==false,"repeated check lost dynamic obstacle");
    local->data={0};pmap->updateDynamicLayer(local);
    require(planner.validatePath(path),"dynamic obstacle removal did not restore passage");
    std::cout<<"SimplePlanner mode gate, cache/raw fallback and dynamic fusion passed\n";
}
int main(int argc,char **argv) {
    try {
        require(argc==3,"expected actual map and terrain paths");
        geometryTests();collisionTests();rclcpp::init(argc,argv);
        rosTests(argv[2]);integrationTests(argv[1],argv[2]);rclcpp::shutdown();return 0;
    } catch(const std::exception &e) {std::cerr<<e.what()<<'\n';if(rclcpp::ok())rclcpp::shutdown();return 1;}
}
