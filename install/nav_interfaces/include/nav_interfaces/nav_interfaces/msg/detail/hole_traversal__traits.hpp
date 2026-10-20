// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_traversal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'events'
#include "nav_interfaces/msg/detail/hole_event__traits.hpp"
// Member 'straight_segments'
#include "nav_interfaces/msg/detail/hole_straight__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleTraversal & msg,
  std::ostream & out)
{
  out << "{";
  // member: traversal_uid
  {
    out << "traversal_uid: ";
    rosidl_generator_traits::value_to_yaml(msg.traversal_uid, out);
    out << ", ";
  }

  // member: hole_id
  {
    out << "hole_id: ";
    rosidl_generator_traits::value_to_yaml(msg.hole_id, out);
    out << ", ";
  }

  // member: entry_edge_id
  {
    out << "entry_edge_id: ";
    rosidl_generator_traits::value_to_yaml(msg.entry_edge_id, out);
    out << ", ";
  }

  // member: exit_edge_id
  {
    out << "exit_edge_id: ";
    rosidl_generator_traits::value_to_yaml(msg.exit_edge_id, out);
    out << ", ";
  }

  // member: centerline
  {
    out << "centerline: ";
    rosidl_generator_traits::value_to_yaml(msg.centerline, out);
    out << ", ";
  }

  // member: validated
  {
    out << "validated: ";
    rosidl_generator_traits::value_to_yaml(msg.validated, out);
    out << ", ";
  }

  // member: requirement_revision
  {
    out << "requirement_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.requirement_revision, out);
    out << ", ";
  }

  // member: events
  {
    if (msg.events.size() == 0) {
      out << "events: []";
    } else {
      out << "events: [";
      size_t pending_items = msg.events.size();
      for (auto item : msg.events) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: straight_segments
  {
    if (msg.straight_segments.size() == 0) {
      out << "straight_segments: []";
    } else {
      out << "straight_segments: [";
      size_t pending_items = msg.straight_segments.size();
      for (auto item : msg.straight_segments) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uphill_entry
  {
    out << "uphill_entry: ";
    rosidl_generator_traits::value_to_yaml(msg.uphill_entry, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleTraversal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: traversal_uid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "traversal_uid: ";
    rosidl_generator_traits::value_to_yaml(msg.traversal_uid, out);
    out << "\n";
  }

  // member: hole_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hole_id: ";
    rosidl_generator_traits::value_to_yaml(msg.hole_id, out);
    out << "\n";
  }

  // member: entry_edge_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entry_edge_id: ";
    rosidl_generator_traits::value_to_yaml(msg.entry_edge_id, out);
    out << "\n";
  }

  // member: exit_edge_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "exit_edge_id: ";
    rosidl_generator_traits::value_to_yaml(msg.exit_edge_id, out);
    out << "\n";
  }

  // member: centerline
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "centerline: ";
    rosidl_generator_traits::value_to_yaml(msg.centerline, out);
    out << "\n";
  }

  // member: validated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "validated: ";
    rosidl_generator_traits::value_to_yaml(msg.validated, out);
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

  // member: events
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.events.size() == 0) {
      out << "events: []\n";
    } else {
      out << "events:\n";
      for (auto item : msg.events) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: straight_segments
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.straight_segments.size() == 0) {
      out << "straight_segments: []\n";
    } else {
      out << "straight_segments:\n";
      for (auto item : msg.straight_segments) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: uphill_entry
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uphill_entry: ";
    rosidl_generator_traits::value_to_yaml(msg.uphill_entry, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleTraversal & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleTraversal & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleTraversal & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleTraversal>()
{
  return "nav_interfaces::msg::HoleTraversal";
}

template<>
inline const char * name<nav_interfaces::msg::HoleTraversal>()
{
  return "nav_interfaces/msg/HoleTraversal";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleTraversal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleTraversal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::msg::HoleTraversal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__TRAITS_HPP_
