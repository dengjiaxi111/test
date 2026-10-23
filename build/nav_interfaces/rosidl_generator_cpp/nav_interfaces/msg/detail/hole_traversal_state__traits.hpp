// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_state.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_traversal_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleTraversalState & msg,
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

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: decision
  {
    out << "decision: ";
    rosidl_generator_traits::value_to_yaml(msg.decision, out);
    out << ", ";
  }

  // member: s_progress
  {
    out << "s_progress: ";
    rosidl_generator_traits::value_to_yaml(msg.s_progress, out);
    out << ", ";
  }

  // member: speed_limit
  {
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: traversal_uids
  {
    if (msg.traversal_uids.size() == 0) {
      out << "traversal_uids: []";
    } else {
      out << "traversal_uids: [";
      size_t pending_items = msg.traversal_uids.size();
      for (auto item : msg.traversal_uids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: phases
  {
    if (msg.phases.size() == 0) {
      out << "phases: []";
    } else {
      out << "phases: [";
      size_t pending_items = msg.phases.size();
      for (auto item : msg.phases) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: preparing_required
  {
    if (msg.preparing_required.size() == 0) {
      out << "preparing_required: []";
    } else {
      out << "preparing_required: [";
      size_t pending_items = msg.preparing_required.size();
      for (auto item : msg.preparing_required) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: attempt
  {
    out << "attempt: ";
    rosidl_generator_traits::value_to_yaml(msg.attempt, out);
    out << ", ";
  }

  // member: recovery_phase
  {
    out << "recovery_phase: ";
    rosidl_generator_traits::value_to_yaml(msg.recovery_phase, out);
    out << ", ";
  }

  // member: hold_gimbal_heading
  {
    out << "hold_gimbal_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.hold_gimbal_heading, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleTraversalState & msg,
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

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: decision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "decision: ";
    rosidl_generator_traits::value_to_yaml(msg.decision, out);
    out << "\n";
  }

  // member: s_progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_progress: ";
    rosidl_generator_traits::value_to_yaml(msg.s_progress, out);
    out << "\n";
  }

  // member: speed_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }

  // member: traversal_uids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.traversal_uids.size() == 0) {
      out << "traversal_uids: []\n";
    } else {
      out << "traversal_uids:\n";
      for (auto item : msg.traversal_uids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: phases
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.phases.size() == 0) {
      out << "phases: []\n";
    } else {
      out << "phases:\n";
      for (auto item : msg.phases) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: preparing_required
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.preparing_required.size() == 0) {
      out << "preparing_required: []\n";
    } else {
      out << "preparing_required:\n";
      for (auto item : msg.preparing_required) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: recovery_phase
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "recovery_phase: ";
    rosidl_generator_traits::value_to_yaml(msg.recovery_phase, out);
    out << "\n";
  }

  // member: hold_gimbal_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hold_gimbal_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.hold_gimbal_heading, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleTraversalState & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleTraversalState & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleTraversalState & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleTraversalState>()
{
  return "nav_interfaces::msg::HoleTraversalState";
}

template<>
inline const char * name<nav_interfaces::msg::HoleTraversalState>()
{
  return "nav_interfaces/msg/HoleTraversalState";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleTraversalState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleTraversalState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::msg::HoleTraversalState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__TRAITS_HPP_
