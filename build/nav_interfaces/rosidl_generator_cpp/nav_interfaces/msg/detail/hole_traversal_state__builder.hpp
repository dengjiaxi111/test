// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_state.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/hole_traversal_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_HoleTraversalState_hold_gimbal_heading
{
public:
  explicit Init_HoleTraversalState_hold_gimbal_heading(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::HoleTraversalState hold_gimbal_heading(::nav_interfaces::msg::HoleTraversalState::_hold_gimbal_heading_type arg)
  {
    msg_.hold_gimbal_heading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_recovery_phase
{
public:
  explicit Init_HoleTraversalState_recovery_phase(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_hold_gimbal_heading recovery_phase(::nav_interfaces::msg::HoleTraversalState::_recovery_phase_type arg)
  {
    msg_.recovery_phase = std::move(arg);
    return Init_HoleTraversalState_hold_gimbal_heading(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_attempt
{
public:
  explicit Init_HoleTraversalState_attempt(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_recovery_phase attempt(::nav_interfaces::msg::HoleTraversalState::_attempt_type arg)
  {
    msg_.attempt = std::move(arg);
    return Init_HoleTraversalState_recovery_phase(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_preparing_required
{
public:
  explicit Init_HoleTraversalState_preparing_required(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_attempt preparing_required(::nav_interfaces::msg::HoleTraversalState::_preparing_required_type arg)
  {
    msg_.preparing_required = std::move(arg);
    return Init_HoleTraversalState_attempt(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_phases
{
public:
  explicit Init_HoleTraversalState_phases(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_preparing_required phases(::nav_interfaces::msg::HoleTraversalState::_phases_type arg)
  {
    msg_.phases = std::move(arg);
    return Init_HoleTraversalState_preparing_required(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_traversal_uids
{
public:
  explicit Init_HoleTraversalState_traversal_uids(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_phases traversal_uids(::nav_interfaces::msg::HoleTraversalState::_traversal_uids_type arg)
  {
    msg_.traversal_uids = std::move(arg);
    return Init_HoleTraversalState_phases(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_reason
{
public:
  explicit Init_HoleTraversalState_reason(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_traversal_uids reason(::nav_interfaces::msg::HoleTraversalState::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_HoleTraversalState_traversal_uids(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_speed_limit
{
public:
  explicit Init_HoleTraversalState_speed_limit(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_reason speed_limit(::nav_interfaces::msg::HoleTraversalState::_speed_limit_type arg)
  {
    msg_.speed_limit = std::move(arg);
    return Init_HoleTraversalState_reason(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_s_progress
{
public:
  explicit Init_HoleTraversalState_s_progress(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_speed_limit s_progress(::nav_interfaces::msg::HoleTraversalState::_s_progress_type arg)
  {
    msg_.s_progress = std::move(arg);
    return Init_HoleTraversalState_speed_limit(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_decision
{
public:
  explicit Init_HoleTraversalState_decision(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_s_progress decision(::nav_interfaces::msg::HoleTraversalState::_decision_type arg)
  {
    msg_.decision = std::move(arg);
    return Init_HoleTraversalState_s_progress(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_state
{
public:
  explicit Init_HoleTraversalState_state(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_decision state(::nav_interfaces::msg::HoleTraversalState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_HoleTraversalState_decision(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_plan_id
{
public:
  explicit Init_HoleTraversalState_plan_id(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_state plan_id(::nav_interfaces::msg::HoleTraversalState::_plan_id_type arg)
  {
    msg_.plan_id = std::move(arg);
    return Init_HoleTraversalState_state(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_goal_id
{
public:
  explicit Init_HoleTraversalState_goal_id(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_plan_id goal_id(::nav_interfaces::msg::HoleTraversalState::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HoleTraversalState_plan_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_session_id
{
public:
  explicit Init_HoleTraversalState_session_id(::nav_interfaces::msg::HoleTraversalState & msg)
  : msg_(msg)
  {}
  Init_HoleTraversalState_goal_id session_id(::nav_interfaces::msg::HoleTraversalState::_session_id_type arg)
  {
    msg_.session_id = std::move(arg);
    return Init_HoleTraversalState_goal_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

class Init_HoleTraversalState_header
{
public:
  Init_HoleTraversalState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HoleTraversalState_session_id header(::nav_interfaces::msg::HoleTraversalState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HoleTraversalState_session_id(msg_);
  }

private:
  ::nav_interfaces::msg::HoleTraversalState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::HoleTraversalState>()
{
  return nav_interfaces::msg::builder::Init_HoleTraversalState_header();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__BUILDER_HPP_
