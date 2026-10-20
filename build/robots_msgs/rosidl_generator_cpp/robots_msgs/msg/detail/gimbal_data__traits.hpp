// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimbal_data.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/gimbal_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GimbalData & msg,
  std::ostream & out)
{
  out << "{";
  // member: gimbal_yaw
  {
    out << "gimbal_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_yaw, out);
    out << ", ";
  }

  // member: gimbal_pitch
  {
    out << "gimbal_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_pitch, out);
    out << ", ";
  }

  // member: yaw_va
  {
    out << "yaw_va: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_va, out);
    out << ", ";
  }

  // member: base_yaw
  {
    out << "base_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.base_yaw, out);
    out << ", ";
  }

  // member: self_team
  {
    out << "self_team: ";
    rosidl_generator_traits::value_to_yaml(msg.self_team, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GimbalData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gimbal_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gimbal_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_yaw, out);
    out << "\n";
  }

  // member: gimbal_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gimbal_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_pitch, out);
    out << "\n";
  }

  // member: yaw_va
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_va: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_va, out);
    out << "\n";
  }

  // member: base_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "base_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.base_yaw, out);
    out << "\n";
  }

  // member: self_team
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "self_team: ";
    rosidl_generator_traits::value_to_yaml(msg.self_team, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GimbalData & msg, bool use_flow_style = false)
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

}  // namespace robots_msgs

namespace rosidl_generator_traits
{

[[deprecated("use robots_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robots_msgs::msg::GimbalData & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::GimbalData & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::GimbalData>()
{
  return "robots_msgs::msg::GimbalData";
}

template<>
inline const char * name<robots_msgs::msg::GimbalData>()
{
  return "robots_msgs/msg/GimbalData";
}

template<>
struct has_fixed_size<robots_msgs::msg::GimbalData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::GimbalData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::GimbalData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__TRAITS_HPP_
