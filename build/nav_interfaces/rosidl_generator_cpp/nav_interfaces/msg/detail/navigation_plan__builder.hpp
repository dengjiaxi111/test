// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/navigation_plan.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__BUILDER_HPP_
#define NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/msg/detail/navigation_plan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavigationPlan_speed_regions
{
public:
  explicit Init_NavigationPlan_speed_regions(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::msg::NavigationPlan speed_regions(::nav_interfaces::msg::NavigationPlan::_speed_regions_type arg)
  {
    msg_.speed_regions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_passages
{
public:
  explicit Init_NavigationPlan_passages(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_speed_regions passages(::nav_interfaces::msg::NavigationPlan::_passages_type arg)
  {
    msg_.passages = std::move(arg);
    return Init_NavigationPlan_speed_regions(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_path_length
{
public:
  explicit Init_NavigationPlan_path_length(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_passages path_length(::nav_interfaces::msg::NavigationPlan::_path_length_type arg)
  {
    msg_.path_length = std::move(arg);
    return Init_NavigationPlan_passages(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_path
{
public:
  explicit Init_NavigationPlan_path(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_path_length path(::nav_interfaces::msg::NavigationPlan::_path_type arg)
  {
    msg_.path = std::move(arg);
    return Init_NavigationPlan_path_length(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_map_revision
{
public:
  explicit Init_NavigationPlan_map_revision(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_path map_revision(::nav_interfaces::msg::NavigationPlan::_map_revision_type arg)
  {
    msg_.map_revision = std::move(arg);
    return Init_NavigationPlan_path(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_parameter_revision
{
public:
  explicit Init_NavigationPlan_parameter_revision(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_map_revision parameter_revision(::nav_interfaces::msg::NavigationPlan::_parameter_revision_type arg)
  {
    msg_.parameter_revision = std::move(arg);
    return Init_NavigationPlan_map_revision(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_terrain_revision
{
public:
  explicit Init_NavigationPlan_terrain_revision(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_parameter_revision terrain_revision(::nav_interfaces::msg::NavigationPlan::_terrain_revision_type arg)
  {
    msg_.terrain_revision = std::move(arg);
    return Init_NavigationPlan_parameter_revision(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_constraints_enabled
{
public:
  explicit Init_NavigationPlan_constraints_enabled(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_terrain_revision constraints_enabled(::nav_interfaces::msg::NavigationPlan::_constraints_enabled_type arg)
  {
    msg_.constraints_enabled = std::move(arg);
    return Init_NavigationPlan_terrain_revision(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_reason
{
public:
  explicit Init_NavigationPlan_reason(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_constraints_enabled reason(::nav_interfaces::msg::NavigationPlan::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_NavigationPlan_constraints_enabled(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_status
{
public:
  explicit Init_NavigationPlan_status(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_reason status(::nav_interfaces::msg::NavigationPlan::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigationPlan_reason(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_plan_id
{
public:
  explicit Init_NavigationPlan_plan_id(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_status plan_id(::nav_interfaces::msg::NavigationPlan::_plan_id_type arg)
  {
    msg_.plan_id = std::move(arg);
    return Init_NavigationPlan_status(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_goal_id
{
public:
  explicit Init_NavigationPlan_goal_id(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_plan_id goal_id(::nav_interfaces::msg::NavigationPlan::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigationPlan_plan_id(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_session_id
{
public:
  explicit Init_NavigationPlan_session_id(::nav_interfaces::msg::NavigationPlan & msg)
  : msg_(msg)
  {}
  Init_NavigationPlan_goal_id session_id(::nav_interfaces::msg::NavigationPlan::_session_id_type arg)
  {
    msg_.session_id = std::move(arg);
    return Init_NavigationPlan_goal_id(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

class Init_NavigationPlan_header
{
public:
  Init_NavigationPlan_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationPlan_session_id header(::nav_interfaces::msg::NavigationPlan::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NavigationPlan_session_id(msg_);
  }

private:
  ::nav_interfaces::msg::NavigationPlan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::msg::NavigationPlan>()
{
  return nav_interfaces::msg::builder::Init_NavigationPlan_header();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__BUILDER_HPP_
