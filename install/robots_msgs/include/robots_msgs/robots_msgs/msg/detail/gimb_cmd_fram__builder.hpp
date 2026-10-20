// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimb_cmd_fram.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_GimbCmdFram_shot_mode
{
public:
  explicit Init_GimbCmdFram_shot_mode(::robots_msgs::msg::GimbCmdFram & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::GimbCmdFram shot_mode(::robots_msgs::msg::GimbCmdFram::_shot_mode_type arg)
  {
    msg_.shot_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::GimbCmdFram msg_;
};

class Init_GimbCmdFram_spin_flag
{
public:
  explicit Init_GimbCmdFram_spin_flag(::robots_msgs::msg::GimbCmdFram & msg)
  : msg_(msg)
  {}
  Init_GimbCmdFram_shot_mode spin_flag(::robots_msgs::msg::GimbCmdFram::_spin_flag_type arg)
  {
    msg_.spin_flag = std::move(arg);
    return Init_GimbCmdFram_shot_mode(msg_);
  }

private:
  ::robots_msgs::msg::GimbCmdFram msg_;
};

class Init_GimbCmdFram_armor_yaw
{
public:
  explicit Init_GimbCmdFram_armor_yaw(::robots_msgs::msg::GimbCmdFram & msg)
  : msg_(msg)
  {}
  Init_GimbCmdFram_spin_flag armor_yaw(::robots_msgs::msg::GimbCmdFram::_armor_yaw_type arg)
  {
    msg_.armor_yaw = std::move(arg);
    return Init_GimbCmdFram_spin_flag(msg_);
  }

private:
  ::robots_msgs::msg::GimbCmdFram msg_;
};

class Init_GimbCmdFram_armor_pitch
{
public:
  explicit Init_GimbCmdFram_armor_pitch(::robots_msgs::msg::GimbCmdFram & msg)
  : msg_(msg)
  {}
  Init_GimbCmdFram_armor_yaw armor_pitch(::robots_msgs::msg::GimbCmdFram::_armor_pitch_type arg)
  {
    msg_.armor_pitch = std::move(arg);
    return Init_GimbCmdFram_armor_yaw(msg_);
  }

private:
  ::robots_msgs::msg::GimbCmdFram msg_;
};

class Init_GimbCmdFram_center_yaw
{
public:
  Init_GimbCmdFram_center_yaw()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbCmdFram_armor_pitch center_yaw(::robots_msgs::msg::GimbCmdFram::_center_yaw_type arg)
  {
    msg_.center_yaw = std::move(arg);
    return Init_GimbCmdFram_armor_pitch(msg_);
  }

private:
  ::robots_msgs::msg::GimbCmdFram msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::GimbCmdFram>()
{
  return robots_msgs::msg::builder::Init_GimbCmdFram_center_yaw();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__BUILDER_HPP_
