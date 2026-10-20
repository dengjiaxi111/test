#include "nav_components/hole_clearance.hpp"
#include "nav_components/layered_map_manager.hpp"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

using namespace nav_components;
namespace {
void check(bool result, const std::string &message) {
    if (!result) throw std::runtime_error(message);
}
std::string contents(const std::string &path) {
    std::ifstream in(path, std::ios::binary);
    std::ostringstream out; out << in.rdbuf(); return out.str();
}
TerrainRegion rectangle(double angle, bool clockwise = false, int pair = 0) {
    TerrainRegion r;
    r.type = "low_clearance"; r.frame_id = "map"; r.passable_edge_pair = pair;
    r.polygon = {{-1,-0.25},{1,-0.25},{1,0.25},{-1,0.25}};
    if (clockwise) std::reverse(r.polygon.begin(), r.polygon.end());
    if (pair == 1) std::rotate(r.polygon.begin(), r.polygon.begin()+1, r.polygon.end());
    for (auto &p : r.polygon) {
        const double x = p.x, y = p.y;
        p.x = std::cos(angle)*x-std::sin(angle)*y;
        p.y = std::sin(angle)*x+std::cos(angle)*y;
    }
    return r;
}
void geometryTests() {
    nav_msgs::msg::OccupancyGrid grid;
    grid.header.frame_id = "map";
    grid.info.width = grid.info.height = 80; grid.info.resolution = 0.05;
    grid.info.origin.position.x = grid.info.origin.position.y = -2;
    grid.info.origin.orientation.w = 1;
    grid.data.assign(6400,100);
    for (double angle : {0.0,0.3,1.1,1.5707963267948966,2.9})
        for (bool clockwise : {false,true}) for (int pair : {0,1}) {
            auto r = rectangle(angle,clockwise,pair);
            std::vector<int> selected;
            std::string error;
            check(holeClearCellIndices(grid,r,0.2,0.5,selected,&error),error);
            const auto &a=r.polygon[pair], &b=r.polygon[(pair+1)%4];
            const auto &c=r.polygon[(pair+2)%4], &d=r.polygon[(pair+3)%4];
            const double ex=(a.x+b.x)/2, ey=(a.y+b.y)/2;
            const double tx=((c.x+d.x)/2-ex)/0.5, ty=((c.y+d.y)/2-ey)/0.5;
            for (int y=0;y<80;++y) for (int x=0;x<80;++x) {
                const double dx=-2+(x+0.5)*grid.info.resolution-ex;
                const double dy=-2+(y+0.5)*grid.info.resolution-ey;
                const double s=dx*tx+dy*ty, lateral=-dx*ty+dy*tx;
                // Independent oracle in the hole's passage coordinates.
                const bool expected=s>=-0.2-1e-9 && s<=1.0+1e-9 && std::abs(lateral)<=1.0+1e-9;
                const bool actual=std::binary_search(selected.begin(),selected.end(),y*80+x);
                check(actual==expected,"rotated hole cleared beyond configured bounds or side edges");
            }
        }
    auto r=rectangle(0);
    std::vector<int> cells;
    std::string error;
    check(holeClearCellIndices(grid,r,0,0,cells,&error),error);
    const int unknown=cells.front(); grid.data[unknown]=-1;
    check(holeClearCellIndices(grid,r,0,0,cells,&error),error);
    check(std::find(cells.begin(),cells.end(),unknown)==cells.end(),"unknown cell cleared");
    grid.data[unknown]=100;
    auto rotated_grid=grid;
    rotated_grid.info.origin.orientation.z=std::sin(0.35);
    rotated_grid.info.origin.orientation.w=std::cos(0.35);
    rotated_grid.info.origin.position.x=std::cos(0.7)*-2-std::sin(0.7)*-2;
    rotated_grid.info.origin.position.y=std::sin(0.7)*-2+std::cos(0.7)*-2;
    std::vector<int> rotated_cells;
    check(holeClearCellIndices(rotated_grid,rectangle(0.7),0,0,rotated_cells,&error),error);
    check(holeClearCellIndices(grid,r,0,0,cells,&error),error);
    check(cells==rotated_cells,"map origin rotation changed raster selection");
    for (double bad : {-0.1,std::numeric_limits<double>::infinity(),std::numeric_limits<double>::quiet_NaN()})
        check(!holeClearCellIndices(grid,r,bad,0,cells,&error),"invalid distance accepted");
    auto invalid=r; invalid.passable_edge_pair=-1;
    check(!holeClearCellIndices(grid,invalid,0,0,cells,&error),"unconfirmed hole accepted");
    invalid=r; invalid.passable_edge_pair=1;
    check(!holeClearCellIndices(grid,invalid,0,0,cells,&error),"short side accepted");
    invalid=r; invalid.polygon[2].x+=0.4;
    check(!holeClearCellIndices(grid,invalid,0,0,cells,&error),"trapezoid accepted");
    invalid=r; std::swap(invalid.polygon[1],invalid.polygon[2]);
    check(!holeClearCellIndices(grid,invalid,0,0,cells,&error),"self intersection accepted");
    invalid=r; invalid.polygon[1]=invalid.polygon[0];
    check(!holeClearCellIndices(grid,invalid,0,0,cells,&error),"duplicate corner accepted");
    invalid=r; invalid.frame_id="odom";
    check(!holeClearCellIndices(grid,invalid,0,0,cells,&error),"frame mismatch accepted");
    for(auto &p:r.polygon) p.x+=1000;
    check(holeClearCellIndices(grid,r,0,0,cells,&error) && cells.empty(),"outside map handling");
}
}  // namespace

int main(int argc, char **argv) {
    try {
        check(argc==3,"expected map YAML and terrain YAML");
        geometryTests();
        auto terrain=std::make_shared<TerrainRegionMap>();
        std::string error;
        check(terrain->loadFromFile(argv[2],"map",&error),error);
        const auto map_document=YAML::LoadFile(argv[1]);
        const std::string image_path=std::string(argv[1]).substr(0,std::string(argv[1]).find_last_of('/')+1)+map_document["image"].as<std::string>();
        const auto original_pgm=contents(image_path);
        auto original=StaticMapLoader::load(argv[1]);
        check(original!=nullptr,"real map load");
        auto cleared=*original;
        std::size_t changed=0;
        check(clearHoleApproachAreas(cleared,*terrain,0.5,0.5,&changed,&error),error);
        check(changed>0,"real map had no cleared obstacles");
        std::vector<int> union_cells;
        for (const auto &hole:terrain->getRegions()) {
            if(hole.type!="low_clearance") continue;
            std::vector<int> cells;
            check(holeClearCellIndices(*original,hole,0.5,0.5,cells,&error),error);
            check(!cells.empty(),"real hole had no covered obstacle: "+hole.id);
            std::cout << hole.id << ": " << cells.size() << " occupied cells cleared\n";
            union_cells.insert(union_cells.end(),cells.begin(),cells.end());
        }
        std::sort(union_cells.begin(),union_cells.end());
        for(std::size_t i=0;i<cleared.data.size();++i) {
            const bool selected=std::binary_search(union_cells.begin(),union_cells.end(),static_cast<int>(i));
            check(cleared.data[i]==(selected?0:original->data[i]),"outside or unknown cell changed");
        }
        check(clearHoleApproachAreas(cleared,*terrain,0.5,0.5,&changed,&error) && changed==0,"clearing not idempotent");
        // Per-hole overrides, explicit opt-out, and atomic failure.
        const auto &hole=terrain->getRegions()[1];
        std::vector<int> interior;
        check(holeClearCellIndices(*original,hole,0,0,interior,&error),error);
        for(const auto &region:terrain->getRegions()) {
            auto raw=region.raw;
            if(region.type=="low_clearance") raw["traversal"]["static_clearance"]["enabled"]=false;
        }
        cleared=*original;
        check(clearHoleApproachAreas(cleared,*terrain,0.5,0.5,&changed,&error) && changed==0,"per-hole opt-out ignored");
        auto hole_raw=hole.raw;
        hole_raw["traversal"]["static_clearance"]["enabled"]=true;
        hole_raw["traversal"]["static_clearance"]["before_distance"]=0.0;
        hole_raw["traversal"]["static_clearance"]["after_distance"]=0.0;
        check(clearHoleApproachAreas(cleared,*terrain,0.5,0.5,&changed,&error) && changed==interior.size(),"per-hole distances ignored");
        auto other_raw=terrain->getRegions()[3].raw;
        other_raw["traversal"]["static_clearance"]["enabled"]=true;
        other_raw["traversal"]["static_clearance"]["before_distance"]=-1.0;
        cleared=*original;
        check(!clearHoleApproachAreas(cleared,*terrain,0.5,0.5,&changed,&error) && cleared.data==original->data,"failure partially modified map");
        check(terrain->loadFromFile(argv[2],"map",&error),error);
        rclcpp::init(argc,argv);
        auto node=std::make_shared<rclcpp::Node>("hole_clearance_test");
        auto buffer=std::make_shared<tf2_ros::Buffer>(node->get_clock());
        LayeredMapManager manager;
        manager.initialize(node.get(),buffer);
        manager.setEsdfEnabled(true);
        manager.setHoleClearance(terrain,true,0.5,0.5);
        InflationParams params;
        check(manager.loadStaticMap(argv[1],params),"manager map load");
        cleared=*original;
        check(clearHoleApproachAreas(cleared,*terrain,0.5,0.5,&changed,&error),error);
        check(manager.getStaticMap()->data==cleared.data,"startup clearing not applied");
        check(manager.getFusedMap()->data==cleared.data,"fused map built from uncleared map");
        const auto expected=CostmapInflater::inflate(std::make_shared<nav_msgs::msg::OccupancyGrid>(cleared),params);
        check(manager.getCostmap()->data==expected->data,"costmap not rebuilt from cleared obstacles");
        check(manager.getEsdf()!=nullptr,"ESDF missing");
        // Dynamic obstacle in a cleared cell must still block the fused map.
        const int index=union_cells.front();
        auto local=std::make_shared<nav_msgs::msg::OccupancyGrid>();
        local->header.frame_id="map"; local->info.width=local->info.height=1;
        local->info.resolution=original->info.resolution;
        local->info.origin.position.x=original->info.origin.position.x+(index%original->info.width)*original->info.resolution;
        local->info.origin.position.y=original->info.origin.position.y+(index/original->info.width)*original->info.resolution;
        local->info.origin.orientation.w=1; local->data={100};
        manager.updateDynamicLayer(local);
        check(manager.getStaticMap()->data[index]==0,"dynamic update restored static obstacle");
        check(manager.getFusedMap()->data[index]==100,"dynamic obstacle was cleared");
        check(manager.reloadTerrainClearance(argv[1],terrain,&error),error);
        check(manager.getStaticMap()->data==cleared.data,"terrain reload altered clearing extent");
        check(manager.getFusedMap()->data[index]==100,"terrain reload erased dynamic obstacle");
        const auto accepted_static=manager.getStaticMap();
        check(!manager.reloadTerrainClearance("/tmp/nav_nonexistent_phase_two_map.yaml",terrain,&error),"missing map reload accepted");
        check(manager.getStaticMap()==accepted_static,"failed terrain reload replaced map snapshot");
        auto disabled=YAML::LoadFile(argv[2]);
        for(auto region:disabled["regions"])if(region["type"].as<std::string>()=="low_clearance")
            region["traversal"]["static_clearance"]["enabled"]=false;
        const std::string disabled_file="/tmp/nav_phase_two_disabled_clearance.yaml";
        {std::ofstream file(disabled_file);file<<disabled;}
        auto disabled_terrain=std::make_shared<TerrainRegionMap>();
        check(disabled_terrain->loadFromFile(disabled_file,"map",&error),error);
        check(manager.reloadTerrainClearance(argv[1],disabled_terrain,&error),error);
        check(manager.getStaticMap()->data[index]==original->data[index],"reload did not restore original static obstacle");
        manager.updateDynamicLayer(local); // 此时动态障碍与旧静态障碍重叠。
        check(manager.reloadTerrainClearance(argv[1],terrain,&error),error);
        check(manager.getStaticMap()->data[index]==0 && manager.getFusedMap()->data[index]==100,
            "terrain reload erased dynamic obstacle overlapping old static occupancy");
        local->data={0}; manager.updateDynamicLayer(local);
        check(manager.getFusedMap()->data[index]==0,"dynamic obstacle removal restored original roof obstacle");
        // 人工笔迹位于清障之后；原图本来就是黑色时仍可明确重新封洞。
        const auto initial_snapshot=manager.temporaryMapSnapshot();
        check(initial_snapshot.source.data==original->data,"temporary API returned cleared rather than original map");
        check(manager.applyTemporaryEdits(initial_snapshot.source_id,initial_snapshot.revision,{static_cast<uint32_t>(index)},{100},&error),error);
        check(manager.getStaticMap()->data[index]==100 && manager.getFusedMap()->data[index]==100,
            "explicit black on original black failed to override hole clearing");
        check(manager.getEsdf()->getDistanceFast(index%original->info.width,index/original->info.width)<0.001,
            "temporary black missing from ESDF");
        check(manager.getCostmap()->data[index]>=50,"temporary black missing from costmap");
        auto state=manager.temporaryMapSnapshot();
        const auto accepted=manager.getStaticMap();
        check(!manager.applyTemporaryEdits(state.source_id,initial_snapshot.revision,{}, {},&error),"stale revision accepted");
        check(!manager.applyTemporaryEdits("wrong-map",state.revision,{}, {},&error),"wrong source accepted");
        check(!manager.applyTemporaryEdits(state.source_id,state.revision,{static_cast<uint32_t>(original->data.size())},{100},&error),"out of bounds accepted");
        check(!manager.applyTemporaryEdits(state.source_id,state.revision,{0,0},{0,100},&error),"duplicate overrides accepted");
        check(!manager.applyTemporaryEdits(state.source_id,state.revision,{0},{99},&error),"invalid override accepted");
        check(manager.getStaticMap()==accepted && manager.temporaryMapSnapshot().revision==state.revision,
            "failed apply changed map/version");
        check(manager.reloadTerrainClearance(argv[1],terrain,&error),error);
        check(manager.getStaticMap()->data[index]==100,"Terrain reload removed manual black");
        state=manager.temporaryMapSnapshot();
        local->data={100};manager.updateDynamicLayer(local);
        check(manager.applyTemporaryEdits(state.source_id,state.revision,{static_cast<uint32_t>(index)},{0},&error),error);
        check(manager.getStaticMap()->data[index]==0 && manager.getFusedMap()->data[index]==100,
            "manual white erased actual dynamic obstacle");
        local->data={0};manager.updateDynamicLayer(local);
        check(manager.getFusedMap()->data[index]==0,"white override did not survive dynamic layer update");
        state=manager.temporaryMapSnapshot();
        check(manager.applyTemporaryEdits(state.source_id,state.revision,{}, {},&error),error);
        check(manager.getStaticMap()->data==cleared.data,"clearing temporary edits failed to restore cleared base");
        check(manager.temporaryMapSnapshot().source.data==original->data,"temporary editing mutated original snapshot");
        LayeredMapManager restarted;restarted.initialize(node.get(),buffer);restarted.setHoleClearance(terrain,true,0.5,0.5);
        check(restarted.loadStaticMap(argv[1],params),"restart map load");
        check(restarted.temporaryMapSnapshot().indices.empty() && restarted.getStaticMap()->data==cleared.data,
            "temporary override survived new navigation instance");
        manager.setHoleClearance(terrain,false,0.5,0.5);
        check(manager.loadStaticMap(argv[1],params),"disabled map reload");
        check(manager.getStaticMap()->data==original->data,"disabled startup did not restore original map");
        check(contents(image_path)==original_pgm,"PGM contents changed");
        rclcpp::shutdown();
        std::cout << "Hole geometry, temporary static clearing, inflation/ESDF, dynamic obstacles and original PGM preservation passed\n";
        return 0;
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
        if(rclcpp::ok()) rclcpp::shutdown();
        return 1;
    }
}
