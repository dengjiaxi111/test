// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimbal_data.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/gimbal_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_GimbalData_self_team
{
public:
  explicit Init_GimbalData_self_team(::robots_msgs::msg::GimbalData & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::GimbalData self_team(::robots_msgs::msg::GimbalData::_self_team_type arg)
  {
    msg_.self_team = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::GimbalData msg_;
};

class Init_GimbalData_base_yaw
{
public:
  explicit Init_GimbalData_base_yaw(::robots_msgs::msg::GimbalData & msg)
  : msg_(msg)
  {}
  Init_GimbalData_self_team base_yaw(::robots_msgs::msg::GimbalData::_base_yaw_type arg)
  {
    msg_.base_yaw = std::move(arg);
    return Init_GimbalData_self_team(msg_);
  }

private:
  ::robots_msgs::msg::GimbalData msg_;
};

class Init_GimbalData_yaw_va
{
public:
  explicit Init_GimbalData_yaw_va(::robots_msgs::msg::GimbalData & msg)
  : msg_(msg)
  {}
  Init_GimbalData_base_yaw yaw_va(::robots_msgs::msg::GimbalData::_yaw_va_type arg)
  {
    msg_.yaw_va = std::move(arg);
    return Init_GimbalData_base_yaw(msg_);
  }

private:
  ::robots_msgs::msg::GimbalData msg_;
};

class Init_GimbalData_gimbal_pitch
{
public:
  explicit Init_GimbalData_gimbal_pitch(::robots_msgs::msg::GimbalData & msg)
  : msg_(msg)
  {}
  Init_GimbalData_yaw_va gimbal_pitch(::robots_msgs::msg::GimbalData::_gimbal_pitch_type arg)
  {
    msg_.gimbal_pitch = std::move(arg);
    return Init_GimbalData_yaw_va(msg_);
  }

private:
  ::robots_msgs::msg::GimbalData msg_;
};

class Init_GimbalData_gimbal_yaw
{
public:
  Init_GimbalData_gimbal_yaw()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalData_gimbal_pitch gimbal_yaw(::robots_msgs::msg::GimbalData::_gimbal_yaw_type arg)
  {
    msg_.gimbal_yaw = std::move(arg);
    return Init_GimbalData_gimbal_pitch(msg_);
  }

private:
  ::robots_msgs::msg::GimbalData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::GimbalData>()
{
  return robots_msgs::msg::builder::Init_GimbalData_gimbal_yaw();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__BUILDER_HPP_
