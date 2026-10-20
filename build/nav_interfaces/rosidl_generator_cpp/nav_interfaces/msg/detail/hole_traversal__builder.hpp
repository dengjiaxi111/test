// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_traversal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleTraversal_uphill_entry
{
public:
  explicit Init_HoleTraversal_uphill_entry(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleTraversal uphill_entry(::nav_interfaces::msg::HoleTraversal::_uphill_entry_type arg)
  {
    msg_.uphill_entry = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_straight_segments
{
public:
  explicit Init_HoleTraversal_straight_segments(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_uphill_entry straight_segments(::nav_interfaces::msg::HoleTraversal::_straight_segments_type arg)
  {
    msg_.straight_segments = std::move(arg);
    return Init_HoleTraversal_uphill_entry(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_events
{
public:
  explicit Init_HoleTraversal_events(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_straight_segments events(::nav_interfaces::msg::HoleTraversal::_events_type arg)
  {
    msg_.events = std::move(arg);
    return Init_HoleTraversal_straight_segments(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_requirement_revision
{
public:
  explicit Init_HoleTraversal_requirement_revision(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_events requirement_revision(::nav_interfaces::msg::HoleTraversal::_requirement_revision_type arg)
  {
    msg_.requirement_revision = std::move(arg);
    return Init_HoleTraversal_events(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_validated
{
public:
  explicit Init_HoleTraversal_validated(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_requirement_revision validated(::nav_interfaces::msg::HoleTraversal::_validated_type arg)
  {
    msg_.validated = std::move(arg);
    return Init_HoleTraversal_requirement_revision(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_centerline
{
public:
  explicit Init_HoleTraversal_centerline(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_validated centerline(::nav_interfaces::msg::HoleTraversal::_centerline_type arg)
  {
    msg_.centerline = std::move(arg);
    return Init_HoleTraversal_validated(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_exit_edge_id
{
public:
  explicit Init_HoleTraversal_exit_edge_id(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_centerline exit_edge_id(::nav_interfaces::msg::HoleTraversal::_exit_edge_id_type arg)
  {
    msg_.exit_edge_id = std::move(arg);
    return Init_HoleTraversal_centerline(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_entry_edge_id
{
public:
  explicit Init_HoleTraversal_entry_edge_id(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_exit_edge_id entry_edge_id(::nav_interfaces::msg::HoleTraversal::_entry_edge_id_type arg)
  {
    msg_.entry_edge_id = std::move(arg);
    return Init_HoleTraversal_exit_edge_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_hole_id
{
public:
  explicit Init_HoleTraversal_hole_id(::nav_interfaces::msg::HoleTraversal & msg)
  : msg_(msg)
  {}
  Init_HoleTraversal_entry_edge_id hole_id(::nav_interfaces::msg::HoleTraversal::_hole_id_type arg)
  {
    msg_.hole_id = std::move(arg);
    return Init_HoleTraversal_entry_edge_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

class Init_HoleTraversal_traversal_uid
{
public:
  Init_HoleTraversal_traversal_uid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleTraversal_hole_id traversal_uid(::nav_interfaces::msg::HoleTraversal::_traversal_uid_type arg)
  {
    msg_.traversal_uid = std::move(arg);
    return Init_HoleTraversal_hole_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleTraversal>()
{
  return nav_interfaces::msg::builder::Init_HoleTraversal_traversal_uid();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__BUILDER_HPP_
