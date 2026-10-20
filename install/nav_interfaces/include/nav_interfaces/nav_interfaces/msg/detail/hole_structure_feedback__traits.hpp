// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleStructureFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_feedback.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_structure_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleStructureFeedback & msg,
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

  // member: request_id
  {
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << ", ";
  }

  // member: requirement_revision
  {
    out << "requirement_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.requirement_revision, out);
    out << ", ";
  }

  // member: target
  {
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: whole_vehicle_clear
  {
    out << "whole_vehicle_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.whole_vehicle_clear, out);
    out << ", ";
  }

  // member: normal_clearance
  {
    out << "normal_clearance: ";
    rosidl_generator_traits::value_to_yaml(msg.normal_clearance, out);
    out << ", ";
  }

  // member: moving_transition_supported
  {
    out << "moving_transition_supported: ";
    rosidl_generator_traits::value_to_yaml(msg.moving_transition_supported, out);
    out << ", ";
  }

  // member: cleared_traversal_uids
  {
    if (msg.cleared_traversal_uids.size() == 0) {
      out << "cleared_traversal_uids: []";
    } else {
      out << "cleared_traversal_uids: [";
      size_t pending_items = msg.cleared_traversal_uids.size();
      for (auto item : msg.cleared_traversal_uids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: simulated
  {
    out << "simulated: ";
    rosidl_generator_traits::value_to_yaml(msg.simulated, out);
    out << ", ";
  }

  // member: action_stopped
  {
    out << "action_stopped: ";
    rosidl_generator_traits::value_to_yaml(msg.action_stopped, out);
    out << ", ";
  }

  // member: retry_allowed
  {
    out << "retry_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.retry_allowed, out);
    out << ", ";
  }

  // member: fault_code
  {
    out << "fault_code: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleStructureFeedback & msg,
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

  // member: request_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << "\n";
  }

  // member: requirement_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "requirement_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.requirement_revision, out);
    out << "\n";
  }

  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: whole_vehicle_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "whole_vehicle_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.whole_vehicle_clear, out);
    out << "\n";
  }

  // member: normal_clearance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "normal_clearance: ";
    rosidl_generator_traits::value_to_yaml(msg.normal_clearance, out);
    out << "\n";
  }

  // member: moving_transition_supported
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "moving_transition_supported: ";
    rosidl_generator_traits::value_to_yaml(msg.moving_transition_supported, out);
    out << "\n";
  }

  // member: cleared_traversal_uids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cleared_traversal_uids.size() == 0) {
      out << "cleared_traversal_uids: []\n";
    } else {
      out << "cleared_traversal_uids:\n";
      for (auto item : msg.cleared_traversal_uids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: simulated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "simulated: ";
    rosidl_generator_traits::value_to_yaml(msg.simulated, out);
    out << "\n";
  }

  // member: action_stopped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_stopped: ";
    rosidl_generator_traits::value_to_yaml(msg.action_stopped, out);
    out << "\n";
  }

  // member: retry_allowed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "retry_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.retry_allowed, out);
    out << "\n";
  }

  // member: fault_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_code: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleStructureFeedback & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleStructureFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleStructureFeedback & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleStructureFeedback>()
{
  return "nav_interfaces::msg::HoleStructureFeedback";
}

template<>
inline const char * name<nav_interfaces::msg::HoleStructureFeedback>()
{
  return "nav_interfaces/msg/HoleStructureFeedback";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleStructureFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleStructureFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::msg::HoleStructureFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__TRAITS_HPP_
