// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleStructureFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_feedback.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_structure_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleStructureFeedback_fault_code
{
public:
  explicit Init_HoleStructureFeedback_fault_code(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleStructureFeedback fault_code(::nav_interfaces::msg::HoleStructureFeedback::_fault_code_type arg)
  {
    msg_.fault_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_retry_allowed
{
public:
  explicit Init_HoleStructureFeedback_retry_allowed(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_fault_code retry_allowed(::nav_interfaces::msg::HoleStructureFeedback::_retry_allowed_type arg)
  {
    msg_.retry_allowed = std::move(arg);
    return Init_HoleStructureFeedback_fault_code(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_action_stopped
{
public:
  explicit Init_HoleStructureFeedback_action_stopped(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_retry_allowed action_stopped(::nav_interfaces::msg::HoleStructureFeedback::_action_stopped_type arg)
  {
    msg_.action_stopped = std::move(arg);
    return Init_HoleStructureFeedback_retry_allowed(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_simulated
{
public:
  explicit Init_HoleStructureFeedback_simulated(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_action_stopped simulated(::nav_interfaces::msg::HoleStructureFeedback::_simulated_type arg)
  {
    msg_.simulated = std::move(arg);
    return Init_HoleStructureFeedback_action_stopped(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_cleared_traversal_uids
{
public:
  explicit Init_HoleStructureFeedback_cleared_traversal_uids(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_simulated cleared_traversal_uids(::nav_interfaces::msg::HoleStructureFeedback::_cleared_traversal_uids_type arg)
  {
    msg_.cleared_traversal_uids = std::move(arg);
    return Init_HoleStructureFeedback_simulated(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_moving_transition_supported
{
public:
  explicit Init_HoleStructureFeedback_moving_transition_supported(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_cleared_traversal_uids moving_transition_supported(::nav_interfaces::msg::HoleStructureFeedback::_moving_transition_supported_type arg)
  {
    msg_.moving_transition_supported = std::move(arg);
    return Init_HoleStructureFeedback_cleared_traversal_uids(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_normal_clearance
{
public:
  explicit Init_HoleStructureFeedback_normal_clearance(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_moving_transition_supported normal_clearance(::nav_interfaces::msg::HoleStructureFeedback::_normal_clearance_type arg)
  {
    msg_.normal_clearance = std::move(arg);
    return Init_HoleStructureFeedback_moving_transition_supported(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_whole_vehicle_clear
{
public:
  explicit Init_HoleStructureFeedback_whole_vehicle_clear(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_normal_clearance whole_vehicle_clear(::nav_interfaces::msg::HoleStructureFeedback::_whole_vehicle_clear_type arg)
  {
    msg_.whole_vehicle_clear = std::move(arg);
    return Init_HoleStructureFeedback_normal_clearance(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_status
{
public:
  explicit Init_HoleStructureFeedback_status(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_whole_vehicle_clear status(::nav_interfaces::msg::HoleStructureFeedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_HoleStructureFeedback_whole_vehicle_clear(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_target
{
public:
  explicit Init_HoleStructureFeedback_target(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_status target(::nav_interfaces::msg::HoleStructureFeedback::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_HoleStructureFeedback_status(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_requirement_revision
{
public:
  explicit Init_HoleStructureFeedback_requirement_revision(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_target requirement_revision(::nav_interfaces::msg::HoleStructureFeedback::_requirement_revision_type arg)
  {
    msg_.requirement_revision = std::move(arg);
    return Init_HoleStructureFeedback_target(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_request_id
{
public:
  explicit Init_HoleStructureFeedback_request_id(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_requirement_revision request_id(::nav_interfaces::msg::HoleStructureFeedback::_request_id_type arg)
  {
    msg_.request_id = std::move(arg);
    return Init_HoleStructureFeedback_requirement_revision(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_goal_id
{
public:
  explicit Init_HoleStructureFeedback_goal_id(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_request_id goal_id(::nav_interfaces::msg::HoleStructureFeedback::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HoleStructureFeedback_request_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_session_id
{
public:
  explicit Init_HoleStructureFeedback_session_id(::nav_interfaces::msg::HoleStructureFeedback & msg)
  : msg_(msg)
  {}
  Init_HoleStructureFeedback_goal_id session_id(::nav_interfaces::msg::HoleStructureFeedback::_session_id_type arg)
  {
    msg_.session_id = std::move(arg);
    return Init_HoleStructureFeedback_goal_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

class Init_HoleStructureFeedback_header
{
public:
  Init_HoleStructureFeedback_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleStructureFeedback_session_id header(::nav_interfaces::msg::HoleStructureFeedback::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HoleStructureFeedback_session_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleStructureFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleStructureFeedback>()
{
  return nav_interfaces::msg::builder::Init_HoleStructureFeedback_header();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__BUILDER_HPP_
