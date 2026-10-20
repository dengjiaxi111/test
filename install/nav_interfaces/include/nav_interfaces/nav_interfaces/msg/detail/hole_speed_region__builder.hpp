// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_speed_region.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_speed_region__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleSpeedRegion_kind
{
public:
  explicit Init_HoleSpeedRegion_kind(::nav_interfaces::msg::HoleSpeedRegion & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleSpeedRegion kind(::nav_interfaces::msg::HoleSpeedRegion::_kind_type arg)
  {
    msg_.kind = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleSpeedRegion msg_;
};

class Init_HoleSpeedRegion_speed_limit
{
public:
  explicit Init_HoleSpeedRegion_speed_limit(::nav_interfaces::msg::HoleSpeedRegion & msg)
  : msg_(msg)
  {}
  Init_HoleSpeedRegion_kind speed_limit(::nav_interfaces::msg::HoleSpeedRegion::_speed_limit_type arg)
  {
    msg_.speed_limit = std::move(arg);
    return Init_HoleSpeedRegion_kind(msg_);
  }

private:
  ::nav_interfaces::msg::HoleSpeedRegion msg_;
};

class Init_HoleSpeedRegion_s_end
{
public:
  explicit Init_HoleSpeedRegion_s_end(::nav_interfaces::msg::HoleSpeedRegion & msg)
  : msg_(msg)
  {}
  Init_HoleSpeedRegion_speed_limit s_end(::nav_interfaces::msg::HoleSpeedRegion::_s_end_type arg)
  {
    msg_.s_end = std::move(arg);
    return Init_HoleSpeedRegion_speed_limit(msg_);
  }

private:
  ::nav_interfaces::msg::HoleSpeedRegion msg_;
};

class Init_HoleSpeedRegion_s_begin
{
public:
  Init_HoleSpeedRegion_s_begin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleSpeedRegion_s_end s_begin(::nav_interfaces::msg::HoleSpeedRegion::_s_begin_type arg)
  {
    msg_.s_begin = std::move(arg);
    return Init_HoleSpeedRegion_s_end(msg_);
  }

private:
  ::nav_interfaces::msg::HoleSpeedRegion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleSpeedRegion>()
{
  return nav_interfaces::msg::builder::Init_HoleSpeedRegion_s_begin();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__BUILDER_HPP_
