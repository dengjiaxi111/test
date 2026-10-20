// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/chassis_odom.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/chassis_odom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_ChassisOdom_capacitor_voltage
{
public:
  explicit Init_ChassisOdom_capacitor_voltage(::robots_msgs::msg::ChassisOdom & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::ChassisOdom capacitor_voltage(::robots_msgs::msg::ChassisOdom::_capacitor_voltage_type arg)
  {
    msg_.capacitor_voltage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::ChassisOdom msg_;
};

class Init_ChassisOdom_gimbal_angle
{
public:
  explicit Init_ChassisOdom_gimbal_angle(::robots_msgs::msg::ChassisOdom & msg)
  : msg_(msg)
  {}
  Init_ChassisOdom_capacitor_voltage gimbal_angle(::robots_msgs::msg::ChassisOdom::_gimbal_angle_type arg)
  {
    msg_.gimbal_angle = std::move(arg);
    return Init_ChassisOdom_capacitor_voltage(msg_);
  }

private:
  ::robots_msgs::msg::ChassisOdom msg_;
};

class Init_ChassisOdom_speed_w
{
public:
  explicit Init_ChassisOdom_speed_w(::robots_msgs::msg::ChassisOdom & msg)
  : msg_(msg)
  {}
  Init_ChassisOdom_gimbal_angle speed_w(::robots_msgs::msg::ChassisOdom::_speed_w_type arg)
  {
    msg_.speed_w = std::move(arg);
    return Init_ChassisOdom_gimbal_angle(msg_);
  }

private:
  ::robots_msgs::msg::ChassisOdom msg_;
};

class Init_ChassisOdom_speed_y
{
public:
  explicit Init_ChassisOdom_speed_y(::robots_msgs::msg::ChassisOdom & msg)
  : msg_(msg)
  {}
  Init_ChassisOdom_speed_w speed_y(::robots_msgs::msg::ChassisOdom::_speed_y_type arg)
  {
    msg_.speed_y = std::move(arg);
    return Init_ChassisOdom_speed_w(msg_);
  }

private:
  ::robots_msgs::msg::ChassisOdom msg_;
};

class Init_ChassisOdom_speed_x
{
public:
  Init_ChassisOdom_speed_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChassisOdom_speed_y speed_x(::robots_msgs::msg::ChassisOdom::_speed_x_type arg)
  {
    msg_.speed_x = std::move(arg);
    return Init_ChassisOdom_speed_y(msg_);
  }

private:
  ::robots_msgs::msg::ChassisOdom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::ChassisOdom>()
{
  return robots_msgs::msg::builder::Init_ChassisOdom_speed_x();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__BUILDER_HPP_
