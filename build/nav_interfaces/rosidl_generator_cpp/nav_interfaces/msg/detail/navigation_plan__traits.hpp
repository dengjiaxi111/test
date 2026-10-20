// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/navigation_plan.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/navigation_plan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'path'
#include "nav_msgs/msg/detail/path__traits.hpp"
// Member 'passages'
#include "nav_interfaces/msg/detail/hole_traversal__traits.hpp"
// Member 'speed_regions'
#include "nav_interfaces/msg/detail/hole_speed_region__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavigationPlan & msg,
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

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: constraints_enabled
  {
    out << "constraints_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.constraints_enabled, out);
    out << ", ";
  }

  // member: terrain_revision
  {
    out << "terrain_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_revision, out);
    out << ", ";
  }

  // member: parameter_revision
  {
    out << "parameter_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.parameter_revision, out);
    out << ", ";
  }

  // member: map_revision
  {
    out << "map_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.map_revision, out);
    out << ", ";
  }

  // member: path
  {
    out << "path: ";
    to_flow_style_yaml(msg.path, out);
    out << ", ";
  }

  // member: path_length
  {
    out << "path_length: ";
    rosidl_generator_traits::value_to_yaml(msg.path_length, out);
    out << ", ";
  }

  // member: passages
  {
    if (msg.passages.size() == 0) {
      out << "passages: []";
    } else {
      out << "passages: [";
      size_t pending_items = msg.passages.size();
      for (auto item : msg.passages) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speed_regions
  {
    if (msg.speed_regions.size() == 0) {
      out << "speed_regions: []";
    } else {
      out << "speed_regions: [";
      size_t pending_items = msg.speed_regions.size();
      for (auto item : msg.speed_regions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigationPlan & msg,
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

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
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

  // member: constraints_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "constraints_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.constraints_enabled, out);
    out << "\n";
  }

  // member: terrain_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "terrain_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_revision, out);
    out << "\n";
  }

  // member: parameter_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "parameter_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.parameter_revision, out);
    out << "\n";
  }

  // member: map_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.map_revision, out);
    out << "\n";
  }

  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path:\n";
    to_block_style_yaml(msg.path, out, indentation + 2);
  }

  // member: path_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_length: ";
    rosidl_generator_traits::value_to_yaml(msg.path_length, out);
    out << "\n";
  }

  // member: passages
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.passages.size() == 0) {
      out << "passages: []\n";
    } else {
      out << "passages:\n";
      for (auto item : msg.passages) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: speed_regions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.speed_regions.size() == 0) {
      out << "speed_regions: []\n";
    } else {
      out << "speed_regions:\n";
      for (auto item : msg.speed_regions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigationPlan & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::NavigationPlan & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::NavigationPlan & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::NavigationPlan>()
{
  return "nav_interfaces::msg::NavigationPlan";
}

template<>
inline const char * name<nav_interfaces::msg::NavigationPlan>()
{
  return "nav_interfaces/msg/NavigationPlan";
}

template<>
struct has_fixed_size<nav_interfaces::msg::NavigationPlan>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::msg::NavigationPlan>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::msg::NavigationPlan>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__TRAITS_HPP_
