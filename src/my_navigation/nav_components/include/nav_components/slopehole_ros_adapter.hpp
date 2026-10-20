#pragma once
#include "nav_components/slopehole_controller.hpp"
#include "nav_components/hole_execution_config.hpp"
#include "nav_components/hole_plan_adapter.hpp"
#include "nav_components/simple_planner.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/float64.hpp>
#include <functional>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <nav_interfaces/msg/navigation_plan.hpp>
#include <nav_interfaces/msg/hole_structure_request.hpp>
#include <nav_interfaces/msg/hole_structure_feedback.hpp>
#include <nav_interfaces/msg/hole_traversal_state.hpp>
#include <nav_interfaces/msg/hole_traversal_event.hpp>
namespace nav_components {
class SlopeHoleRosAdapter {
public:
    explicit SlopeHoleRosAdapter(rclcpp::Node* node);
    bool enabled() const {return config_.enabled;}
    bool beginGoal();
    bool acceptPath(SimplePlanner& planner,const nav_msgs::msg::Path& path,
        const geometry_msgs::msg::PoseStamped& pose,std::string& error);
    nav_core::hole_exec::Output tick(const geometry_msgs::msg::PoseStamped& pose,double measured_speed);
    nav_core::hole_exec::MotionConstraints constraints() const;
    bool gate(const geometry_msgs::msg::Twist& cmd,bool recovery=false) const;
    bool canRecover() const;
    double measuredSpeed() const;
    void recordCommand(double speed){last_command_speed_=speed;}
    bool specialRecovery() const {return retreat_phase_!=0;}
    void prepareRetreat(const geometry_msgs::msg::PoseStamped&,const std::function<bool(double,double)>&);
    int updateRetreat(const geometry_msgs::msg::PoseStamped&,double,const std::function<bool(double,double)>&,geometry_msgs::msg::Twist&);
    void publishExecution();
    void invalidate(const std::string& reason);
    void closeGoal(nav_core::hole_exec::PlanStatus status=nav_core::hole_exec::PlanStatus::CANCELLED);
    void motionFailed();
    void pathBlocked();
    void confirmPathContinuation(){continuation_verified_=true;}
    void blockCurrentHole(SimplePlanner& planner);
    void applyBlocks(SimplePlanner& planner);
private:
    nav_core::hole_exec::Input input(const geometry_msgs::msg::PoseStamped&,double) const;
    void publishPlan();
    rclcpp::Node* node_;
    std::unique_ptr<tf2_ros::Buffer> chassis_tf_;
    std::unique_ptr<tf2_ros::TransformListener> chassis_listener_;
    nav_core::hole_exec::Config config_;
    SlopeHoleController core_;
    nav_core::hole_exec::StructureFeedback feedback_;
    double measured_speed_=0,speed_received_=-1,speed_stamp_=-1;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr speed_sub_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr rotation_sub_;
    double rotation_stamp_=-1,rotation_received_=-1,chassis_rate_=0,gimbal_rate_=0,alignment_stable_=-1;
    std::string aligning_uid_;
    std::set<std::string> aligned_passages_;
    nav_core::hole_exec::Output output_;
    std::string session_,goal_;
    double last_command_speed_=0,retreat_started_=0,retreat_progress_time_=0,retreat_best_=0,retreat_stable_=-1,retreat_arc_=0;
    int retreat_phase_=0;
    nav_core::hole_exec::Point retreat_target_,retreat_direction_;
    std::string retreat_uid_;
    std::map<std::string,int> traversal_retries_;
    std::map<std::string,double> alignment_targets_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr alignment_pub_;
    std::uint64_t goal_sequence_=0,plan_sequence_=0,uid_sequence_=0;
    double updated_=-1;
    std::map<std::string,double> blocked_;
    int replans_=0;
    bool continuation_verified_=false;
    rclcpp::Publisher<nav_interfaces::msg::NavigationPlan>::SharedPtr plan_pub_;
    rclcpp::Publisher<nav_interfaces::msg::HoleStructureRequest>::SharedPtr request_pub_;
    rclcpp::Publisher<nav_interfaces::msg::HoleTraversalState>::SharedPtr state_pub_;
    rclcpp::Publisher<nav_interfaces::msg::HoleTraversalEvent>::SharedPtr event_pub_;
    rclcpp::Subscription<nav_interfaces::msg::HoleStructureFeedback>::SharedPtr feedback_sub_;
};
}
