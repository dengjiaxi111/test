#pragma once
#include <nav_core/controller_base.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <robots_msgs/msg/chassis_odom.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/LinearMath/Transform.h>
#include <map>
#include <mutex>
#include "nav_components/omni_model.hpp"

extern "C" { struct omni_nmpc_solver_capsule; }

namespace nav_components {
// Four-dimensional odom-frame double integrator; angular control belongs elsewhere.
class NMPC : public nav_core::ControllerBase {
public:
    NMPC() = default;
    ~NMPC() override;
    void initialize(rclcpp::Node* node) override;
    void setMap(nav_core::MapInterface::Ptr map) override { map_=map; }
    void setPath(const nav_msgs::msg::Path& path) override;
    nav_core::ControlResult computeVelocity(const geometry_msgs::msg::PoseStamped& pose,
                                             geometry_msgs::msg::Twist& command) override;
    void setTolerance(double xy, double) override { tolerance_=xy; }
    void reset() override;
private:
    struct Config {
        double max_velocity=2, max_acceleration=4, cruise=2;
        double lateral_acceleration=1.5, curvature_epsilon=0.08, curvature_window=1.5;
        double q_position=3, q_velocity=0.1, r_acceleration=0.01, q_contour=25;
        double q_obstacle=70, safe_distance=0.5, terminal_scale=2, near_scale=3;
        double capacitor_safe=0, capacitor_low=0, protect_scale=1, low_scale=1, voltage_filter=1;
    } config_;
    struct Reference { omni::State x; omni::Vec tangent; };
    std::map<std::string, double Config::*> numericParameters() const;
    static bool validConfig(const Config& c);
    std::vector<Reference> reference(const std::vector<omni::Vec>& points, omni::Vec position);
    bool solve(const omni::State& x0, const std::vector<Reference>& refs,
               const tf2::Transform& odom_to_map, double elapsed, double acceleration,
               omni::Vec& result);
    bool predictionSafe(const tf2::Transform& odom_to_map) const;
    nav_core::ControlResult stop(geometry_msgs::msg::Twist& command);
    void publishObservation(const omni::State& state, omni::Vec measured, bool valid,
                            omni::Vec command);
    rclcpp::Node* node_=nullptr;
    omni_nmpc_solver_capsule* capsule_=nullptr;
    bool solver_created_=false, warm_=false;
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    std::unique_ptr<tf2_ros::TransformListener> tf_listener_;
    std::unique_ptr<omni::VelocityObserver> observer_;
    std::string odom_frame_, map_frame_, fake_frame_;
    double alpha_=0.8, feedback_timeout_=0.15, pose_timeout_=0.2, filter_alpha_=1;
    double tolerance_=0.1, stop_speed_=0.05, last_time_=0, voltage_=0;
    bool have_voltage_=false, have_feedback_=false, have_lio_=false;
    omni::Vec feedback_{0,0}, last_sent_{0,0};
    double feedback_stamp_=-1, feedback_received_=-1, lio_received_=-1;
    nav_msgs::msg::Odometry lio_;
    nav_msgs::msg::Path path_;
    size_t nearest_=0;
    std::array<omni::Vec, omni::N> controls_{};
    std::array<omni::State, omni::N+1> predicted_{};
    tf2::Transform last_odom_to_map_;
    bool have_transform_=false;
    std::mutex mutex_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr feedback_sub_, lio_sub_;
    rclcpp::Subscription<robots_msgs::msg::ChassisOdom>::SharedPtr capacitor_sub_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr predicted_pub_;
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr measured_pub_, fused_pub_, command_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameters_callback_;
};
} // namespace nav_components
