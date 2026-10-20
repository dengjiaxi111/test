// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/enemy_pose.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/enemy_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EnemyPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: enemy_dist
  {
    out << "enemy_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_dist, out);
    out << ", ";
  }

  // member: enemy_ori
  {
    out << "enemy_ori: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_ori, out);
    out << ", ";
  }

  // member: enemy_num
  {
    out << "enemy_num: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_num, out);
    out << ", ";
  }

  // member: enemy_x
  {
    out << "enemy_x: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_x, out);
    out << ", ";
  }

  // member: enemy_y
  {
    out << "enemy_y: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EnemyPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enemy_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_dist, out);
    out << "\n";
  }

  // member: enemy_ori
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_ori: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_ori, out);
    out << "\n";
  }

  // member: enemy_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_num: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_num, out);
    out << "\n";
  }

  // member: enemy_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_x: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_x, out);
    out << "\n";
  }

  // member: enemy_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_y: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EnemyPose & msg, bool use_flow_style = false)
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
  const robots_msgs::msg::EnemyPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::EnemyPose & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::EnemyPose>()
{
  return "robots_msgs::msg::EnemyPose";
}

template<>
inline const char * name<robots_msgs::msg::EnemyPose>()
{
  return "robots_msgs/msg/EnemyPose";
}

template<>
struct has_fixed_size<robots_msgs::msg::EnemyPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::EnemyPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::EnemyPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__TRAITS_HPP_
