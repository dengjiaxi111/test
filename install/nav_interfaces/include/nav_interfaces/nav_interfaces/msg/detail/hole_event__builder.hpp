// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_event.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleEvent_point_valid
{
public:
  explicit Init_HoleEvent_point_valid(::nav_interfaces::msg::HoleEvent & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleEvent point_valid(::nav_interfaces::msg::HoleEvent::_point_valid_type arg)
  {
    msg_.point_valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleEvent msg_;
};

class Init_HoleEvent_point
{
public:
  explicit Init_HoleEvent_point(::nav_interfaces::msg::HoleEvent & msg)
  : msg_(msg)
  {}
  Init_HoleEvent_point_valid point(::nav_interfaces::msg::HoleEvent::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_HoleEvent_point_valid(msg_);
  }

private:
  ::nav_interfaces::msg::HoleEvent msg_;
};

class Init_HoleEvent_s_path
{
public:
  explicit Init_HoleEvent_s_path(::nav_interfaces::msg::HoleEvent & msg)
  : msg_(msg)
  {}
  Init_HoleEvent_point s_path(::nav_interfaces::msg::HoleEvent::_s_path_type arg)
  {
    msg_.s_path = std::move(arg);
    return Init_HoleEvent_point(msg_);
  }

private:
  ::nav_interfaces::msg::HoleEvent msg_;
};

class Init_HoleEvent_range_status
{
public:
  explicit Init_HoleEvent_range_status(::nav_interfaces::msg::HoleEvent & msg)
  : msg_(msg)
  {}
  Init_HoleEvent_s_path range_status(::nav_interfaces::msg::HoleEvent::_range_status_type arg)
  {
    msg_.range_status = std::move(arg);
    return Init_HoleEvent_s_path(msg_);
  }

private:
  ::nav_interfaces::msg::HoleEvent msg_;
};

class Init_HoleEvent_type
{
public:
  Init_HoleEvent_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleEvent_range_status type(::nav_interfaces::msg::HoleEvent::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_HoleEvent_range_status(msg_);
  }

private:
  ::nav_interfaces::msg::HoleEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleEvent>()
{
  return nav_interfaces::msg::builder::Init_HoleEvent_type();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__BUILDER_HPP_
