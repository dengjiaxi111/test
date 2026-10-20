// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/mode_cmd.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/mode_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModeCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: should_chassis_spin
  {
    out << "should_chassis_spin: ";
    rosidl_generator_traits::value_to_yaml(msg.should_chassis_spin, out);
    out << ", ";
  }

  // member: should_gimbal_patrol
  {
    out << "should_gimbal_patrol: ";
    rosidl_generator_traits::value_to_yaml(msg.should_gimbal_patrol, out);
    out << ", ";
  }

  // member: buy_bullet
  {
    out << "buy_bullet: ";
    rosidl_generator_traits::value_to_yaml(msg.buy_bullet, out);
    out << ", ";
  }

  // member: rebirth
  {
    out << "rebirth: ";
    rosidl_generator_traits::value_to_yaml(msg.rebirth, out);
    out << ", ";
  }

  // member: use_capacity
  {
    out << "use_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.use_capacity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModeCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: should_chassis_spin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "should_chassis_spin: ";
    rosidl_generator_traits::value_to_yaml(msg.should_chassis_spin, out);
    out << "\n";
  }

  // member: should_gimbal_patrol
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "should_gimbal_patrol: ";
    rosidl_generator_traits::value_to_yaml(msg.should_gimbal_patrol, out);
    out << "\n";
  }

  // member: buy_bullet
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buy_bullet: ";
    rosidl_generator_traits::value_to_yaml(msg.buy_bullet, out);
    out << "\n";
  }

  // member: rebirth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rebirth: ";
    rosidl_generator_traits::value_to_yaml(msg.rebirth, out);
    out << "\n";
  }

  // member: use_capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.use_capacity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModeCmd & msg, bool use_flow_style = false)
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
  const robots_msgs::msg::ModeCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::ModeCmd & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::ModeCmd>()
{
  return "robots_msgs::msg::ModeCmd";
}

template<>
inline const char * name<robots_msgs::msg::ModeCmd>()
{
  return "robots_msgs/msg/ModeCmd";
}

template<>
struct has_fixed_size<robots_msgs::msg::ModeCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::ModeCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::ModeCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__TRAITS_HPP_
