#pragma once
#include <nav_core/recovery_base.hpp>
#include "nav_components/omni_motion.hpp"
#include <chrono>
#include <stdexcept>

namespace nav_components {
class TranslationRecovery : public nav_core::RecoveryBase {
public:
    using Safety = std::function<bool(const geometry_msgs::msg::PoseStamped&,double,double)>;
    TranslationRecovery(std::string name,double heading,double distance,double speed,
                        double timeout,double progress,double progress_timeout,Safety safety)
      : name_(std::move(name)),heading_(heading),distance_(distance),speed_(speed),
        timeout_(timeout),progress_(progress),progress_timeout_(progress_timeout),safety_(std::move(safety)) {
        if(!std::isfinite(heading) || !std::isfinite(distance) || distance<=0 ||
           !std::isfinite(speed) || speed<=0 || !std::isfinite(timeout) || timeout<=0 ||
           !std::isfinite(progress) || progress<0 || !std::isfinite(progress_timeout) || progress_timeout<=0)
            throw std::invalid_argument("Invalid translation recovery parameters");
    }
    void initialize(rclcpp::Node* node,nav_core::VelPublisher publisher) override {
        node_=node; publisher_=std::move(publisher);
    }
    void start(const geometry_msgs::msg::PoseStamped& pose) override {
        const double direction=tf2::getYaw(pose.pose.orientation)+heading_;
        target_x_=pose.pose.position.x+distance_*std::cos(direction);
        target_y_=pose.pose.position.y+distance_*std::sin(direction);
        frame_=pose.header.frame_id;
        start_=last_progress_=std::chrono::steady_clock::now();
        best_remaining_=distance_; status_=nav_core::RecoveryStatus::RUNNING;
    }
    nav_core::RecoveryStatus update(const geometry_msgs::msg::PoseStamped& pose) override {
        if(status_!=nav_core::RecoveryStatus::RUNNING) return status_;
        const auto now=std::chrono::steady_clock::now();
        const double remaining=std::hypot(target_x_-pose.pose.position.x,target_y_-pose.pose.position.y);
        if(pose.header.frame_id!=frame_ || !std::isfinite(remaining) ||
           std::chrono::duration<double>(now-start_).count()>timeout_)
            return finish(nav_core::RecoveryStatus::FAILED);
        if(remaining<=0.03) return finish(nav_core::RecoveryStatus::SUCCEEDED);
        if(best_remaining_-remaining>=progress_) {best_remaining_=remaining; last_progress_=now;}
        if(std::chrono::duration<double>(now-last_progress_).count()>progress_timeout_ ||
           !safety_ || !safety_(pose,target_x_,target_y_)) return finish(nav_core::RecoveryStatus::FAILED);
        publisher_(omni_motion::toward(pose,target_x_,target_y_,speed_,0.02));
        return status_;
    }
    void cancel() override {finish(nav_core::RecoveryStatus::IDLE);}
    const char* name() const override {return name_.c_str();}
private:
    nav_core::RecoveryStatus finish(nav_core::RecoveryStatus state) {
        if(publisher_) publisher_(geometry_msgs::msg::Twist());
        status_=state; return state;
    }
    std::string name_,frame_;
    double heading_,distance_,speed_,timeout_,progress_,progress_timeout_,target_x_=0,target_y_=0,best_remaining_=0;
    Safety safety_;
    rclcpp::Node* node_=nullptr;
    nav_core::VelPublisher publisher_;
    nav_core::RecoveryStatus status_=nav_core::RecoveryStatus::IDLE;
    std::chrono::steady_clock::time_point start_,last_progress_;
};
} // namespace nav_components
