// Isolated ROS + real acados integration. Never starts nav_server or serial.
#include "nav_components/nmpc.hpp"
#include "nav_components/esdf_map.hpp"
#include <tf2_ros/static_transform_broadcaster.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <stdexcept>
using namespace std::chrono_literals;
using nav_core::ControlResult;
void require(bool value,const char* reason) { if(!value) throw std::runtime_error(reason); }
void exercise(double alpha, bool rotated) {
    rclcpp::NodeOptions options;
    options.parameter_overrides({rclcpp::Parameter("nmpc.odom_feedback_alpha",alpha),
        rclcpp::Parameter("map_frame",rotated ? "map" : "odom"),
        rclcpp::Parameter("nmpc.esdf_weight",0.0)});
    auto node=std::make_shared<rclcpp::Node>("test_omni",options);
    auto peer=std::make_shared<rclcpp::Node>("test_omni_peer");
    nav_components::NMPC controller;
    controller.initialize(node.get());
    auto lio=peer->create_publisher<nav_msgs::msg::Odometry>("/Odometry",10);
    auto feedback=peer->create_publisher<nav_msgs::msg::Odometry>("/Odometry/fake",10);
    std::vector<geometry_msgs::msg::TwistStamped> fused;
    auto sub=peer->create_subscription<geometry_msgs::msg::TwistStamped>("nmpc/fused_velocity",10,
        [&](geometry_msgs::msg::TwistStamped::ConstSharedPtr msg){fused.push_back(*msg);});
    tf2_ros::StaticTransformBroadcaster tf(peer);
    if(rotated) {
        geometry_msgs::msg::TransformStamped t;
        t.header.stamp=peer->now(); t.header.frame_id="map"; t.child_frame_id="odom";
        t.transform.translation.x=5;
        t.transform.rotation.z=std::sqrt(0.5); t.transform.rotation.w=std::sqrt(0.5);
        tf.sendTransform(t);
    }
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node); executor.add_node(peer);
    auto pump=[&](){for(int i=0;i<4;++i) {executor.spin_some(); std::this_thread::sleep_for(1ms);}};
    auto sample=[&](double vx, bool send_feedback) {
        nav_msgs::msg::Odometry msg;
        msg.header.stamp=peer->now(); msg.header.frame_id="odom"; msg.child_frame_id="base_link";
        msg.pose.pose.orientation.w=1;
        lio->publish(msg); pump();
        if(send_feedback) {
            msg.header.stamp=peer->now(); msg.child_frame_id="base_link_fake";
            msg.twist.twist.linear.x=vx; feedback->publish(msg); pump();
        }
    };
    nav_msgs::msg::Path path;
    path.header.frame_id=rotated ? "map" : "odom";
    for(int i=0;i<=50;++i) {
        geometry_msgs::msg::PoseStamped p;
        p.header=path.header; p.pose.orientation.w=1;
        p.pose.position.x=rotated ? 5 : i*0.05;
        p.pose.position.y=rotated ? i*0.05 : 0;
        path.poses.push_back(p);
    }
    controller.setPath(path);
    geometry_msgs::msg::PoseStamped pose; pose.pose.orientation.w=1;
    geometry_msgs::msg::Twist command;
    require(controller.computeVelocity(pose,command)==ControlResult::FAILED,"requires initial LIO");
    for(int i=0;i<25;++i) {sample(0,alpha>0); pump();}
    bool moved=false;
    std::vector<double> compute_times;
    for(int i=0;i<12;++i) {
        sample(0,alpha>0);
        const auto start=std::chrono::steady_clock::now();
        controller.computeVelocity(pose,command);
        compute_times.push_back(std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-start).count());
        moved=moved || command.linear.x>0.001;
        require(std::abs(command.linear.y)<1e-4,"map rotation changed world travel direction");
        require(command.angular.z==0,"angular output must remain zero");
        std::this_thread::sleep_for(10ms);
    }
    require(moved,"controller never generated a feasible nonzero command");
    double total=0, maximum=0;
    for(double t:compute_times) {total+=t; maximum=std::max(maximum,t);}
    std::cout<<"computeVelocity alpha="<<alpha<<" mean="<<total/compute_times.size()<<"ms max="<<maximum<<"ms\n";
    if(rotated) {
        // Wall in MAP x=5.4; odom +x points along map +y. Its repulsion must
        // point along odom +y (map -x), exercising both query and gradient frames.
        auto grid=std::make_shared<nav_msgs::msg::OccupancyGrid>();
        grid->info.width=300; grid->info.height=300; grid->info.resolution=0.05;
        grid->info.origin.position.x=-5; grid->info.origin.position.y=-5;
        grid->data.assign(90000,0);
        for(int y=0;y<300;++y) grid->data[y*300+208]=100;
        auto esdf=std::make_shared<nav_components::EsdfMap>();
        esdf->buildFromOccupancy(grid);
        controller.setMap(esdf);
        require(node->set_parameter(rclcpp::Parameter("nmpc.esdf_weight",70.0)).successful,"ESDF weight update");
        controller.setPath(path);
        bool repelled=false;
        for(int i=0;i<5;++i) {
            sample(0,true); controller.computeVelocity(pose,command);
            repelled=repelled || command.linear.y>1e-5;
        }
        require(repelled,"ESDF gradient not rotated into odom correctly");
        controller.setMap(nullptr);
        node->set_parameter(rclcpp::Parameter("nmpc.esdf_weight",0.0));
    }
    require(!node->set_parameter(rclcpp::Parameter("nmpc.odom_feedback_alpha",1-alpha)).successful,
            "alpha must require restart");
    controller.reset();
    sample(0.5,true);
    controller.computeVelocity(pose,command); pump();
    require(!fused.empty() && std::abs(fused.back().twist.linear.x-0.5)<1e-5,"initialization ignored measured velocity");
    sample(0,true);
    controller.computeVelocity(pose,command); pump();
    if(alpha==1) require(std::abs(fused.back().twist.linear.x)<1e-6,"alpha=1 did not use measurement");
    if(alpha==0) require(fused.back().twist.linear.x>0.4,"alpha=0 was overwritten by measurement");
    std::this_thread::sleep_for(170ms);
    sample(0,false);
    auto status=controller.computeVelocity(pose,command);
    if(alpha>0) require(status==ControlResult::FAILED && command.linear.x==0,"stale feedback must stop");
    // A timing gap also stops alpha=0; after reinitialization it runs without feedback.
    if(alpha==0) {sample(0,false); require(controller.computeVelocity(pose,command)==ControlResult::RUNNING,"alpha=0 needs no feedback");}
    controller.reset();
    sample(3,true);
    controller.computeVelocity(pose,command);
    require(std::hypot(command.linear.x,command.linear.y)<=2.000001,"overspeed protection failed");
    require(node->set_parameter(rclcpp::Parameter("nmpc.max_linear_vel",0.2)).successful,"limit update failed");
    sample(3,true);
    controller.computeVelocity(pose,command);
    require(std::hypot(command.linear.x,command.linear.y)<=0.200001,"sudden lower limit not respected");
    require(!node->set_parameter(rclcpp::Parameter("nmpc.max_linear_vel",-1.0)).successful,"invalid limit accepted");
    // A one-point goal has zero reference velocity and does not wait for yaw.
    controller.reset();
    path.poses.resize(1); controller.setPath(path); sample(0,true);
    require(controller.computeVelocity(pose,command)==ControlResult::SUCCEEDED,"stationary goal did not complete");
    controller.reset();
    std::this_thread::sleep_for(220ms);
    require(controller.computeVelocity(pose,command)==ControlResult::FAILED,"stale pose must stop");
    std::cout<<"ROS controller alpha="<<alpha<<" rotated="<<rotated<<" passed\n";
}
int main(int argc,char** argv) {
    rclcpp::init(argc,argv);
    try {exercise(0,false); exercise(0.8,true); exercise(1,false);}
    catch(const std::exception& e) {std::cerr<<e.what()<<"\n"; rclcpp::shutdown(); return 1;}
    rclcpp::shutdown();
}
