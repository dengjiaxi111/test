// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_event.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_event__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: range_status
  {
    out << "range_status: ";
    rosidl_generator_traits::value_to_yaml(msg.range_status, out);
    out << ", ";
  }

  // member: s_path
  {
    out << "s_path: ";
    rosidl_generator_traits::value_to_yaml(msg.s_path, out);
    out << ", ";
  }

  // member: point
  {
    out << "point: ";
    to_flow_style_yaml(msg.point, out);
    out << ", ";
  }

  // member: point_valid
  {
    out << "point_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.point_valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: range_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_status: ";
    rosidl_generator_traits::value_to_yaml(msg.range_status, out);
    out << "\n";
  }

  // member: s_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_path: ";
    rosidl_generator_traits::value_to_yaml(msg.s_path, out);
    out << "\n";
  }

  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point:\n";
    to_block_style_yaml(msg.point, out, indentation + 2);
  }

  // member: point_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.point_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleEvent & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleEvent & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleEvent>()
{
  return "nav_interfaces::msg::HoleEvent";
}

template<>
inline const char * name<nav_interfaces::msg::HoleEvent>()
{
  return "nav_interfaces/msg/HoleEvent";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleEvent>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleEvent>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<nav_interfaces::msg::HoleEvent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__TRAITS_HPP_
