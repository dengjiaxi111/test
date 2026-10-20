// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleStraight.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_straight.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_straight__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleStraight_remaining
{
public:
  explicit Init_HoleStraight_remaining(::nav_interfaces::msg::HoleStraight & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleStraight remaining(::nav_interfaces::msg::HoleStraight::_remaining_type arg)
  {
    msg_.remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStraight msg_;
};

class Init_HoleStraight_direction
{
public:
  explicit Init_HoleStraight_direction(::nav_interfaces::msg::HoleStraight & msg)
  : msg_(msg)
  {}
  Init_HoleStraight_remaining direction(::nav_interfaces::msg::HoleStraight::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_HoleStraight_remaining(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStraight msg_;
};

class Init_HoleStraight_s_end
{
public:
  explicit Init_HoleStraight_s_end(::nav_interfaces::msg::HoleStraight & msg)
  : msg_(msg)
  {}
  Init_HoleStraight_direction s_end(::nav_interfaces::msg::HoleStraight::_s_end_type arg)
  {
    msg_.s_end = std::move(arg);
    return Init_HoleStraight_direction(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStraight msg_;
};

class Init_HoleStraight_s_begin
{
public:
  Init_HoleStraight_s_begin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleStraight_s_end s_begin(::nav_interfaces::msg::HoleStraight::_s_begin_type arg)
  {
    msg_.s_begin = std::move(arg);
    return Init_HoleStraight_s_end(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStraight msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleStraight>()
{
  return nav_interfaces::msg::builder::Init_HoleStraight_s_begin();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__BUILDER_HPP_
