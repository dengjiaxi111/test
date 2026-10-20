// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_request.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_structure_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleStructureRequest & msg,
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

  // member: cancel_motion
  {
    out << "cancel_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.cancel_motion, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleStructureRequest & msg,
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

  // member: cancel_motion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cancel_motion: ";
    rosidl_generator_traits::value_to_yaml(msg.cancel_motion, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleStructureRequest & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleStructureRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleStructureRequest & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleStructureRequest>()
{
  return "nav_interfaces::msg::HoleStructureRequest";
}

template<>
inline const char * name<nav_interfaces::msg::HoleStructureRequest>()
{
  return "nav_interfaces/msg/HoleStructureRequest";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleStructureRequest>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleStructureRequest>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::msg::HoleStructureRequest>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__TRAITS_HPP_
