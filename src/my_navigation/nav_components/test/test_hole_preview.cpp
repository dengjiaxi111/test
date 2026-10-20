#include "nav_components/hole_geometry_previewer.hpp"
#include <nav_core/hole_geometry_markers.hpp>
#include <iostream>
#include <thread>
using namespace nav_components;
void require(bool result,const std::string &message) {if(!result) throw std::runtime_error(message);}
void waitFor(const std::shared_ptr<rclcpp::Node> &node,const std::shared_ptr<rclcpp::Node> &peer,
             const std::function<bool()> &predicate) {
    const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(3);
    while(std::chrono::steady_clock::now()<end) {
        rclcpp::spin_some(node);rclcpp::spin_some(peer);
        if(predicate()) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    throw std::runtime_error("preview ROS event timed out");
}
int main(int argc,char **argv) {
 try {
    require(argc==3,"expected terrain and nav params paths");
    auto terrain=std::make_shared<TerrainRegionMap>();std::string error;
    require(terrain->loadFromFile(argv[1],"map",&error),error);
    auto config=nav_core::readHolePreviewConfiguration(YAML::LoadFile(argv[2]));
    rclcpp::init(argc,argv);
    auto node=std::make_shared<rclcpp::Node>("hole_preview_test");
    auto peer=std::make_shared<rclcpp::Node>("hole_preview_peer");
    std::vector<visualization_msgs::msg::MarkerArray> messages;
    auto subscription=peer->create_subscription<visualization_msgs::msg::MarkerArray>("hole_geometry_markers",rclcpp::QoS(1).transient_local().reliable(),
        [&](visualization_msgs::msg::MarkerArray::ConstSharedPtr m){messages.push_back(*m);});
    auto clicked=peer->create_publisher<geometry_msgs::msg::PointStamped>("/clicked_point",10);
    HoleGeometryPreviewer previewer;previewer.initialize(node.get(),terrain);
    require(previewer.previews().size()==4,"four actual holes not previewed");
    for(const auto &preview:previewer.previews()) {
        require(preview.valid,preview.reason);
        require(preview.directions.size()==2,"missing reverse candidate");
        const auto &d=preview.directions[0];
        require(nav_core::holeNorm(d.A-(d.E-d.tangent*config.distances.prepare_distance))<1e-8,"actual map A formula");
        std::cout<<preview.id<<" width="<<preview.opening_width<<" depth="<<preview.depth<<" angle="<<preview.max_rectangle_error_deg<<"\n";
    }
    waitFor(node,peer,[&](){return !messages.empty()&&clicked->get_subscription_count()>0;});
    const auto initial=previewer.previews().front();const auto d=initial.directions[0];
    geometry_msgs::msg::PointStamped point;point.header.frame_id="map";
    point.point.x=d.X.x+d.tangent.x*2;point.point.y=d.X.y+d.tangent.y*2;
    clicked->publish(point);
    waitFor(node,peer,[&](){return previewer.previews().front().start_revision>0;});
    require(previewer.previews().front().directions[0].entry_edge_id==d.exit_edge_id,"ROS Publish Point did not reverse preferred direction");
    const auto before=previewer.previews().front();
    auto result=node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.prepare_distance",2.0)});
    require(result.successful,result.reason);
    waitFor(node,peer,[&](){return previewer.previews().front().parameter_revision>before.parameter_revision;});
    const auto after=previewer.previews().front();
    require(nav_core::holeNorm(after.directions[0].S-before.directions[0].S)<1e-9,"live prepare update moved S");
    require(nav_core::holeNorm(after.directions[0].A-before.directions[0].A)>0.49,"live prepare update did not move A");
    result=node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.entry_straight_length",3.0)});
    require(!result.successful,"invalid parameter ordering accepted");
    require(node->get_parameter("hole_planner.approach.entry_straight_length").as_double()==0.8,"rejected parameter committed");
    // Equal distances must generate merged marker labels from the same data.
    result=node->set_parameters_atomically({rclcpp::Parameter("hole_planner.approach.prepare_distance",0.8),
        rclcpp::Parameter("hole_planner.departure.departure_distance",0.5)});
    require(result.successful,result.reason);
    waitFor(node,peer,[&](){return previewer.previews().front().parameter_revision>after.parameter_revision;});
    const auto equal=previewer.previews().front();
    auto markers=nav_core::holeGeometryMarkers(equal);
    bool merged_a=false,merged_d=false,axis=false,fixed=false,corridor=false,arrow=false;
    for(const auto &m:markers.markers) {
        merged_a|=m.text.find("A=S")!=std::string::npos;
        merged_d|=m.text.find("T=D")!=std::string::npos;
        axis|=m.ns.find("centerline")!=std::string::npos;
        fixed|=m.ns.find("fixed_straight")!=std::string::npos;
        corridor|=m.ns.find("geometric_corridor")!=std::string::npos;
        arrow|=m.type==visualization_msgs::msg::Marker::ARROW;
    }
    require(merged_a&&merged_d&&axis&&fixed&&corridor&&arrow,"missing waypoint labels or preview markers");
    const auto revision=equal.parameter_revision;
    result=node->set_parameters_atomically({rclcpp::Parameter("hole_planner.publish_debug_markers",false)});
    require(result.successful,result.reason);
    waitFor(node,peer,[&](){return previewer.previews().front().parameter_revision>revision&&messages.back().markers.size()==1;});
    require(messages.back().markers.front().action==visualization_msgs::msg::Marker::DELETEALL,"disabled preview left stale markers");
    rclcpp::shutdown();
    std::cout<<"Actual holes, ROS debug start, live parameters and marker consistency passed\n";return 0;
 } catch(const std::exception &e) {std::cerr<<e.what()<<'\n';if(rclcpp::ok()) rclcpp::shutdown();return 1;}
}
