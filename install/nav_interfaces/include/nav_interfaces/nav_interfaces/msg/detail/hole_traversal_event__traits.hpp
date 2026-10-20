// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleTraversalEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_event.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_traversal_event__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleTraversalEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: session_id
  {
    out << "session_id: ";
    rosidl_generator_traits::value_to_yaml(msg.session_id, out);
    out << ", ";
  }

  // member: goal_id
  {
    out << "goal_id: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: plan_id
  {
    out << "plan_id: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_id, out);
    out << ", ";
  }

  // member: traversal_uid
  {
    out << "traversal_uid: ";
    rosidl_generator_traits::value_to_yaml(msg.traversal_uid, out);
    out << ", ";
  }

  // member: sequence
  {
    out << "sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: event_arc
  {
    out << "event_arc: ";
    rosidl_generator_traits::value_to_yaml(msg.event_arc, out);
    out << ", ";
  }

  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << ", ";
  }

  // member: attempt
  {
    out << "attempt: ";
    rosidl_generator_traits::value_to_yaml(msg.attempt, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleTraversalEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: session_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "session_id: ";
    rosidl_generator_traits::value_to_yaml(msg.session_id, out);
    out << "\n";
  }

  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_id, out);
    out << "\n";
  }

  // member: plan_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plan_id: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_id, out);
    out << "\n";
  }

  // member: traversal_uid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "traversal_uid: ";
    rosidl_generator_traits::value_to_yaml(msg.traversal_uid, out);
    out << "\n";
  }

  // member: sequence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: event_arc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "event_arc: ";
    rosidl_generator_traits::value_to_yaml(msg.event_arc, out);
    out << "\n";
  }

  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }

  // member: attempt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attempt: ";
    rosidl_generator_traits::value_to_yaml(msg.attempt, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleTraversalEvent & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace nav_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nav_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nav_interfaces::msg::HoleTraversalEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleTraversalEvent & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleTraversalEvent>()
{
  return "nav_interfaces::msg::HoleTraversalEvent";
}

template<>
inline const char * name<nav_interfaces::msg::HoleTraversalEvent>()
{
  return "nav_interfaces/msg/HoleTraversalEvent";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleTraversalEvent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleTraversalEvent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::msg::HoleTraversalEvent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__TRAITS_HPP_
