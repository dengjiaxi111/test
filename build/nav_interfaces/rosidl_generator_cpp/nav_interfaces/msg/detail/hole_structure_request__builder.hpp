// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_request.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_structure_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleStructureRequest_cancel_motion
{
public:
  explicit Init_HoleStructureRequest_cancel_motion(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleStructureRequest cancel_motion(::nav_interfaces::msg::HoleStructureRequest::_cancel_motion_type arg)
  {
    msg_.cancel_motion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_traversal_uids
{
public:
  explicit Init_HoleStructureRequest_traversal_uids(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  Init_HoleStructureRequest_cancel_motion traversal_uids(::nav_interfaces::msg::HoleStructureRequest::_traversal_uids_type arg)
  {
    msg_.traversal_uids = std::move(arg);
    return Init_HoleStructureRequest_cancel_motion(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_target
{
public:
  explicit Init_HoleStructureRequest_target(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  Init_HoleStructureRequest_traversal_uids target(::nav_interfaces::msg::HoleStructureRequest::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_HoleStructureRequest_traversal_uids(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_requirement_revision
{
public:
  explicit Init_HoleStructureRequest_requirement_revision(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  Init_HoleStructureRequest_target requirement_revision(::nav_interfaces::msg::HoleStructureRequest::_requirement_revision_type arg)
  {
    msg_.requirement_revision = std::move(arg);
    return Init_HoleStructureRequest_target(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_request_id
{
public:
  explicit Init_HoleStructureRequest_request_id(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  Init_HoleStructureRequest_requirement_revision request_id(::nav_interfaces::msg::HoleStructureRequest::_request_id_type arg)
  {
    msg_.request_id = std::move(arg);
    return Init_HoleStructureRequest_requirement_revision(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_goal_id
{
public:
  explicit Init_HoleStructureRequest_goal_id(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  Init_HoleStructureRequest_request_id goal_id(::nav_interfaces::msg::HoleStructureRequest::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HoleStructureRequest_request_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_session_id
{
public:
  explicit Init_HoleStructureRequest_session_id(::nav_interfaces::msg::HoleStructureRequest & msg)
  : msg_(msg)
  {}
  Init_HoleStructureRequest_goal_id session_id(::nav_interfaces::msg::HoleStructureRequest::_session_id_type arg)
  {
    msg_.session_id = std::move(arg);
    return Init_HoleStructureRequest_goal_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

class Init_HoleStructureRequest_header
{
public:
  Init_HoleStructureRequest_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleStructureRequest_session_id header(::nav_interfaces::msg::HoleStructureRequest::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HoleStructureRequest_session_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleStructureRequest>()
{
  return nav_interfaces::msg::builder::Init_HoleStructureRequest_header();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__BUILDER_HPP_
