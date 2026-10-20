// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleStraight.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_straight.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_straight__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleStraight & msg,
  std::ostream & out)
{
  out << "{";
  // member: s_begin
  {
    out << "s_begin: ";
    rosidl_generator_traits::value_to_yaml(msg.s_begin, out);
    out << ", ";
  }

  // member: s_end
  {
    out << "s_end: ";
    rosidl_generator_traits::value_to_yaml(msg.s_end, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    to_flow_style_yaml(msg.direction, out);
    out << ", ";
  }

  // member: remaining
  {
    out << "remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleStraight & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: s_begin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_begin: ";
    rosidl_generator_traits::value_to_yaml(msg.s_begin, out);
    out << "\n";
  }

  // member: s_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "s_end: ";
    rosidl_generator_traits::value_to_yaml(msg.s_end, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction:\n";
    to_block_style_yaml(msg.direction, out, indentation + 2);
  }

  // member: remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleStraight & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleStraight & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleStraight & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleStraight>()
{
  return "nav_interfaces::msg::HoleStraight";
}

template<>
inline const char * name<nav_interfaces::msg::HoleStraight>()
{
  return "nav_interfaces/msg/HoleStraight";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleStraight>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleStraight>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<nav_interfaces::msg::HoleStraight>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__TRAITS_HPP_
