#include <nav_core/hole_geometry_yaml.hpp>
#include <nav_core/hole_passage.hpp>
#include <iostream>
#include <stdexcept>
using namespace nav_core;
void require(bool result,const std::string &reason) {if(!result) throw std::runtime_error(reason);}
void near(HolePoint a,HolePoint b,const std::string &reason) {require(holeNorm(a-b)<1e-8,reason);}
HoleGeometryInput rect(double angle,bool clockwise=false,int pair=0) {
    HoleGeometryInput r;r.id="test";r.passable_edge_pair=pair;
    r.polygon={{-1,-0.25},{1,-0.25},{1,0.25},{-1,0.25}};
    if(clockwise) std::reverse(r.polygon.begin(),r.polygon.end());
    if(pair==1) std::rotate(r.polygon.begin(),r.polygon.begin()+1,r.polygon.end());
    for(auto &p:r.polygon) {const auto q=p;p={std::cos(angle)*q.x-std::sin(angle)*q.y,std::sin(angle)*q.x+std::cos(angle)*q.y};}
    return r;
}
int main() {
 try {
    for(int k=0;k<360;++k) for(bool clockwise:{false,true}) for(int pair:{0,1}) {
        auto input=rect(k*3.141592653589793/180,clockwise,pair);
        auto preview=buildHoleGeometry(input);
        require(preview.valid,preview.reason);
        require(preview.long_edge_pair==pair,"long edge pair incorrect");
        require(std::abs(preview.opening_width-2)<1e-8&&std::abs(preview.depth-0.5)<1e-8,"dimensions reversed");
        const auto d=preview.directions[0];
        near(d.E,preview.directions[1].X,"reverse exit does not match entry");
        near(d.X,preview.directions[1].E,"reverse entry does not match exit");
        near(d.E,(input.polygon[pair]+input.polygon[(pair+1)%4])*0.5,"entry midpoint wrong");
        require(std::abs(holeDot(d.tangent,input.polygon[(pair+3)%4]-input.polygon[(pair+2)%4]))<1e-8,"axis not perpendicular to exit");
        require(std::abs(d.min_left_width-1)<1e-8&&std::abs(d.min_right_width-1)<1e-8,"side widths wrong");
        auto p=d.E-d.tangent*2;
        preview=buildHoleGeometry(input,{}, {},&p);
        require(preview.directions.front().entry_edge_id==pair&&preview.directions.front().start_in_entry_half_plane,"entry outside half plane");
        p=d.X+d.tangent*2;
        preview=buildHoleGeometry(input,{}, {},&p);
        require(preview.directions.front().entry_edge_id==pair+2,"opposite start did not swap entry");
        p=(d.E+d.X)*0.5;
        preview=buildHoleGeometry(input,{}, {},&p);
        require(preview.start_inside&&preview.directions.front().entry_edge_id==pair,"tie or inside branch unstable");
        auto distances=HoleTraversalDistances{};distances.prepare_distance+=1;
        auto changed=buildHoleGeometry(input,{},distances).directions[0];
        near(changed.A,d.A-d.tangent,"prepare distance did not move A");
        near(changed.S,d.S,"prepare moved S");near(changed.E,d.E,"prepare moved E");near(changed.X,d.X,"prepare moved X");near(changed.T,d.T,"prepare moved T");near(changed.D,d.D,"prepare moved D");
        distances={};distances.entry_straight_length+=0.2;
        changed=buildHoleGeometry(input,{},distances).directions[0];
        near(changed.S,d.S-d.tangent*0.2,"entry did not move S");near(changed.A,d.A,"entry moved A");near(changed.T,d.T,"entry moved T");
        distances={};distances.exit_straight_length+=0.1;
        changed=buildHoleGeometry(input,{},distances).directions[0];near(changed.T,d.T+d.tangent*0.1,"exit did not move T");near(changed.D,d.D,"exit moved D");
        distances={};distances.departure_distance+=0.1;
        changed=buildHoleGeometry(input,{},distances).directions[0];near(changed.D,d.D+d.tangent*0.1,"departure did not move D");near(changed.T,d.T,"departure moved T");
        distances={};distances.prepare_distance=distances.entry_straight_length;distances.departure_distance=distances.exit_straight_length;
        changed=buildHoleGeometry(input,{},distances).directions[0];near(changed.A,changed.S,"A=S data mismatch");near(changed.D,changed.T,"D=T data mismatch");
    }
    auto r=rect(0);
    auto p=HolePoint{10,-1};auto preview=buildHoleGeometry(r,{}, {},&p);
    const double expected=std::hypot(9.0,0.75);
    require(std::abs(preview.directions.front().start_distance-expected)<1e-9,"used infinite entry line distance");
    r.polygon.push_back(r.polygon.front());require(buildHoleGeometry(r).valid,"closed polygon rejected");
    r=rect(0);r.polygon[2].x+=0.005;preview=buildHoleGeometry(r);require(preview.valid&&preview.max_rectangle_error_deg>0,"small drag error not diagnosed");
    r=rect(0);r.polygon[2].x+=0.4;require(!buildHoleGeometry(r).valid,"trapezoid accepted");
    r=rect(0);std::swap(r.polygon[1],r.polygon[2]);require(!buildHoleGeometry(r).valid,"self intersection accepted");
    r=rect(0);r.polygon[1]=r.polygon[0];require(!buildHoleGeometry(r).valid,"duplicate vertices accepted");
    r=rect(0);r.polygon[1].x=std::numeric_limits<double>::infinity();require(!buildHoleGeometry(r).valid,"nonfinite accepted");
    r=rect(0);r.passable_edge_pair=-1;require(!buildHoleGeometry(r).valid,"missing manual edges accepted");
    r=rect(0);r.passable_edge_pair=1;require(!buildHoleGeometry(r).valid,"short edge authorized");
    r=rect(0);r.polygon={{0,0},{1,0},{1,1},{0,1}};r.passable_edge_pair=-1;
    require(buildHoleGeometry(r).reason.find("AMBIGUOUS")!=std::string::npos,"square ambiguity not diagnosed");
    r.passable_edge_pair=1;preview=buildHoleGeometry(r);require(preview.valid&&!preview.warning.empty(),"manual square direction rejected");
    r=rect(0);r.bidirectional=false;require(buildHoleGeometry(r).directions.size()==1,"one way config ignored");
    r=rect(0);r.enabled=false;require(!buildHoleGeometry(r).valid,"disabled hole accepted");
    r=rect(0);r.frame_id="odom";require(!buildHoleGeometry(r).valid,"frame mismatch accepted");
    r=rect(0);HoleTraversalDistances distances;distances.prepare_distance=0;require(!buildHoleGeometry(r,{},distances).valid,"distance order accepted");
    // 两物理侧不对称，正反向必须共享 S—T 世界区间。
    auto traversal=YAML::Load("passable_edges: [0, 2]\nbidirectional: true\n");
    writeHoleStraightRange(traversal,HoleStraightRange{0,{.7,.2}});
    HolePreviewConfiguration config;
    const auto mapped=resolveHoleDistances(traversal,config);
    preview=buildHoleGeometry(rect(.63),{},mapped);require(preview.valid,preview.reason);
    const auto f=preview.directions[0],b=preview.directions[1];
    near(f.S,b.T,"physical side a changed on reverse");near(f.T,b.S,"physical side b changed on reverse");
    require(std::abs(holeNorm(f.E-f.S)-.7)<1e-8 && std::abs(holeNorm(b.E-b.S)-.2)<1e-8,"side lengths did not swap");
    const HoleSegmentCheck clear=[](HolePoint,HolePoint){return holeCheck(true,"OK");};
    for(const auto &dir:preview.directions) {
        const auto candidate=centerlineHoleCandidate(preview,dir);
        require(validateHoleCandidate(preview,mapped,{},candidate,clear).valid,"directional candidate validation rejected");
        const HolePathPolyline path({dir.A,dir.S,dir.E,dir.X,dir.T,dir.D});
        const auto crossings=holePathCrossings(preview,path);
        require(crossings.size()==1 && validateHolePathPassage(preview,mapped,{},path,crossings.front(),HolePassageMode::Centerline,clear).valid,"directional final validation rejected");
        for(const auto &points:std::vector<std::vector<HolePoint>>{
            {(dir.E+dir.X)*.5,dir.X,dir.T,dir.D},
            {dir.A,dir.S,dir.E,(dir.E+dir.X)*.5},
            {dir.E+(dir.X-dir.E)*.25,dir.E+(dir.X-dir.E)*.75}}) {
            const HolePathPolyline partial(points);
            const auto crossing=holePathCrossings(preview,partial);
            require(crossing.size()==1 && validateHolePathPassage(preview,mapped,{},partial,crossing.front(),HolePassageMode::Centerline,clear,nullptr,true).valid,
                "directional remaining passage rejected");
        }
    }
    auto skew=rect(0);skew.polygon[2].y+=.005;
    require(!buildHoleGeometry(skew,{},mapped).valid,"map range accepted disagreeing passable normals");
    auto obsolete=YAML::Clone(traversal);obsolete["entry_straight_length"]=99;
    require(buildHoleGeometry(rect(0),{},resolveHoleDistances(obsolete,config)).valid,"ignored legacy S overrode physical range");
    config.use_global_distances=true;
    require(resolveHoleDistances(traversal,config).range_edge==-1,"global override ignored");
    for(const std::string invalid:{
        "schema_version: 2, binding: passable_edges, sides: []",
        "schema_version: 1, binding: passable_edges, sides: [{edge_id: 0, extension_length: 0.2}]",
        "schema_version: 1, binding: passable_edges, sides: [{edge_id: 0, extension_length: 0.2}, {edge_id: 0, extension_length: 0.3}]",
        "schema_version: 1, binding: passable_edges, sides: [{edge_id: 1, extension_length: 0.2}, {edge_id: 2, extension_length: -0.3}]"}) {
        auto broken=YAML::Clone(traversal);broken["straight_range"]=YAML::Load("{"+invalid+"}");
        bool rejected=false;try{resolveHoleDistances(broken,config);}catch(const std::exception &){rejected=true;}
        require(rejected,"invalid range silently fell back");
    }
    auto conflict=mapped;conflict.departure_distance=.3;
    require(!buildHoleGeometry(rect(0),{},conflict).valid,"reverse D conflict accepted");
    auto one_way=rect(0);one_way.bidirectional=false;
    require(buildHoleGeometry(one_way,{},conflict).valid,"one way checked forbidden reverse distance");
    std::cout<<"Hole rotation, bidirectional axes, finite segment selection, independent waypoints, geometry diagnostics passed\n";
    return 0;
 } catch(const std::exception &e) {std::cerr<<e.what()<<'\n';return 1;}
}
