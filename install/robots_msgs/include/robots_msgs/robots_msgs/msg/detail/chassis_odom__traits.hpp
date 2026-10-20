// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/chassis_odom.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/chassis_odom__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ChassisOdom & msg,
  std::ostream & out)
{
  out << "{";
  // member: speed_x
  {
    out << "speed_x: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_x, out);
    out << ", ";
  }

  // member: speed_y
  {
    out << "speed_y: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_y, out);
    out << ", ";
  }

  // member: speed_w
  {
    out << "speed_w: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_w, out);
    out << ", ";
  }

  // member: gimbal_angle
  {
    out << "gimbal_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_angle, out);
    out << ", ";
  }

  // member: capacitor_voltage
  {
    out << "capacitor_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.capacitor_voltage, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChassisOdom & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: speed_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_x: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_x, out);
    out << "\n";
  }

  // member: speed_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_y: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_y, out);
    out << "\n";
  }

  // member: speed_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_w: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_w, out);
    out << "\n";
  }

  // member: gimbal_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gimbal_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_angle, out);
    out << "\n";
  }

  // member: capacitor_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "capacitor_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.capacitor_voltage, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChassisOdom & msg, bool use_flow_style = false)
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
  const robots_msgs::msg::ChassisOdom & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::ChassisOdom & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::ChassisOdom>()
{
  return "robots_msgs::msg::ChassisOdom";
}

template<>
inline const char * name<robots_msgs::msg::ChassisOdom>()
{
  return "robots_msgs/msg/ChassisOdom";
}

template<>
struct has_fixed_size<robots_msgs::msg::ChassisOdom>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::ChassisOdom>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::ChassisOdom>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__TRAITS_HPP_
