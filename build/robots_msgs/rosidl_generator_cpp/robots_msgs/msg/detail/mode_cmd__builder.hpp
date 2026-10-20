// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/mode_cmd.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/mode_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_ModeCmd_use_capacity
{
public:
  explicit Init_ModeCmd_use_capacity(::robots_msgs::msg::ModeCmd & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::ModeCmd use_capacity(::robots_msgs::msg::ModeCmd::_use_capacity_type arg)
  {
    msg_.use_capacity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::ModeCmd msg_;
};

class Init_ModeCmd_rebirth
{
public:
  explicit Init_ModeCmd_rebirth(::robots_msgs::msg::ModeCmd & msg)
  : msg_(msg)
  {}
  Init_ModeCmd_use_capacity rebirth(::robots_msgs::msg::ModeCmd::_rebirth_type arg)
  {
    msg_.rebirth = std::move(arg);
    return Init_ModeCmd_use_capacity(msg_);
  }

private:
  ::robots_msgs::msg::ModeCmd msg_;
};

class Init_ModeCmd_buy_bullet
{
public:
  explicit Init_ModeCmd_buy_bullet(::robots_msgs::msg::ModeCmd & msg)
  : msg_(msg)
  {}
  Init_ModeCmd_rebirth buy_bullet(::robots_msgs::msg::ModeCmd::_buy_bullet_type arg)
  {
    msg_.buy_bullet = std::move(arg);
    return Init_ModeCmd_rebirth(msg_);
  }

private:
  ::robots_msgs::msg::ModeCmd msg_;
};

class Init_ModeCmd_should_gimbal_patrol
{
public:
  explicit Init_ModeCmd_should_gimbal_patrol(::robots_msgs::msg::ModeCmd & msg)
  : msg_(msg)
  {}
  Init_ModeCmd_buy_bullet should_gimbal_patrol(::robots_msgs::msg::ModeCmd::_should_gimbal_patrol_type arg)
  {
    msg_.should_gimbal_patrol = std::move(arg);
    return Init_ModeCmd_buy_bullet(msg_);
  }

private:
  ::robots_msgs::msg::ModeCmd msg_;
};

class Init_ModeCmd_should_chassis_spin
{
public:
  Init_ModeCmd_should_chassis_spin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModeCmd_should_gimbal_patrol should_chassis_spin(::robots_msgs::msg::ModeCmd::_should_chassis_spin_type arg)
  {
    msg_.should_chassis_spin = std::move(arg);
    return Init_ModeCmd_should_gimbal_patrol(msg_);
  }

private:
  ::robots_msgs::msg::ModeCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::ModeCmd>()
{
  return robots_msgs::msg::builder::Init_ModeCmd_should_chassis_spin();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__BUILDER_HPP_
