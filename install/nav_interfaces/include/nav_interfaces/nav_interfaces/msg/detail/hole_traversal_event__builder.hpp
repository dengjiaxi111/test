// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleTraversalEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_event.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_traversal_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleTraversalEvent_attempt
{
public:
  explicit Init_HoleTraversalEvent_attempt(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleTraversalEvent attempt(::nav_interfaces::msg::HoleTraversalEvent::_attempt_type arg)
  {
    msg_.attempt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_progress
{
public:
  explicit Init_HoleTraversalEvent_progress(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_attempt progress(::nav_interfaces::msg::HoleTraversalEvent::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return Init_HoleTraversalEvent_attempt(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_event_arc
{
public:
  explicit Init_HoleTraversalEvent_event_arc(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_progress event_arc(::nav_interfaces::msg::HoleTraversalEvent::_event_arc_type arg)
  {
    msg_.event_arc = std::move(arg);
    return Init_HoleTraversalEvent_progress(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_type
{
public:
  explicit Init_HoleTraversalEvent_type(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_event_arc type(::nav_interfaces::msg::HoleTraversalEvent::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_HoleTraversalEvent_event_arc(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_sequence
{
public:
  explicit Init_HoleTraversalEvent_sequence(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_type sequence(::nav_interfaces::msg::HoleTraversalEvent::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return Init_HoleTraversalEvent_type(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_traversal_uid
{
public:
  explicit Init_HoleTraversalEvent_traversal_uid(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_sequence traversal_uid(::nav_interfaces::msg::HoleTraversalEvent::_traversal_uid_type arg)
  {
    msg_.traversal_uid = std::move(arg);
    return Init_HoleTraversalEvent_sequence(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_plan_id
{
public:
  explicit Init_HoleTraversalEvent_plan_id(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_traversal_uid plan_id(::nav_interfaces::msg::HoleTraversalEvent::_plan_id_type arg)
  {
    msg_.plan_id = std::move(arg);
    return Init_HoleTraversalEvent_traversal_uid(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_goal_id
{
public:
  explicit Init_HoleTraversalEvent_goal_id(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_plan_id goal_id(::nav_interfaces::msg::HoleTraversalEvent::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HoleTraversalEvent_plan_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_session_id
{
public:
  explicit Init_HoleTraversalEvent_session_id(::nav_interfaces::msg::HoleTraversalEvent & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalEvent_goal_id session_id(::nav_interfaces::msg::HoleTraversalEvent::_session_id_type arg)
  {
    msg_.session_id = std::move(arg);
    return Init_HoleTraversalEvent_goal_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

class Init_HoleTraversalEvent_header
{
public:
  Init_HoleTraversalEvent_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleTraversalEvent_session_id header(::nav_interfaces::msg::HoleTraversalEvent::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HoleTraversalEvent_session_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleTraversalEvent>()
{
  return nav_interfaces::msg::builder::Init_HoleTraversalEvent_header();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__BUILDER_HPP_
