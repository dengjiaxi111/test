// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimb_cmd_fram.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GimbCmdFram & msg,
  std::ostream & out)
{
  out << "{";
  // member: center_yaw
  {
    out << "center_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.center_yaw, out);
    out << ", ";
  }

  // member: armor_pitch
  {
    out << "armor_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.armor_pitch, out);
    out << ", ";
  }

  // member: armor_yaw
  {
    out << "armor_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.armor_yaw, out);
    out << ", ";
  }

  // member: spin_flag
  {
    out << "spin_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.spin_flag, out);
    out << ", ";
  }

  // member: shot_mode
  {
    out << "shot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.shot_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GimbCmdFram & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: center_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.center_yaw, out);
    out << "\n";
  }

  // member: armor_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "armor_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.armor_pitch, out);
    out << "\n";
  }

  // member: armor_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "armor_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.armor_yaw, out);
    out << "\n";
  }

  // member: spin_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spin_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.spin_flag, out);
    out << "\n";
  }

  // member: shot_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.shot_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GimbCmdFram & msg, bool use_flow_style = false)
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
  const robots_msgs::msg::GimbCmdFram & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::GimbCmdFram & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::GimbCmdFram>()
{
  return "robots_msgs::msg::GimbCmdFram";
}

template<>
inline const char * name<robots_msgs::msg::GimbCmdFram>()
{
  return "robots_msgs/msg/GimbCmdFram";
}

template<>
struct has_fixed_size<robots_msgs::msg::GimbCmdFram>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::GimbCmdFram>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::GimbCmdFram>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__TRAITS_HPP_
