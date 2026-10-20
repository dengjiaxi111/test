// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_speed_region.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__TRAITS_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/msg/detail/hole_speed_region__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace nav_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HoleSpeedRegion & msg,
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

  // member: speed_limit
  {
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << ", ";
  }

  // member: kind
  {
    out << "kind: ";
    rosidl_generator_traits::value_to_yaml(msg.kind, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HoleSpeedRegion & msg,
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

  // member: speed_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << "\n";
  }

  // member: kind
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kind: ";
    rosidl_generator_traits::value_to_yaml(msg.kind, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HoleSpeedRegion & msg, bool use_flow_style = false)
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
  const nav_interfaces::msg::HoleSpeedRegion & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::msg::HoleSpeedRegion & msg)
{
  return nav_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::msg::HoleSpeedRegion>()
{
  return "nav_interfaces::msg::HoleSpeedRegion";
}

template<>
inline const char * name<nav_interfaces::msg::HoleSpeedRegion>()
{
  return "nav_interfaces/msg/HoleSpeedRegion";
}

template<>
struct has_fixed_size<nav_interfaces::msg::HoleSpeedRegion>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nav_interfaces::msg::HoleSpeedRegion>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nav_interfaces::msg::HoleSpeedRegion>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__TRAITS_HPP_
