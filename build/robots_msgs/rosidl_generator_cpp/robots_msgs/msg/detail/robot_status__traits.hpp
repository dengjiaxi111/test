// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/robot_status.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: recovery_buff
  {
    out << "recovery_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.recovery_buff, out);
    out << ", ";
  }

  // member: defence_buff
  {
    out << "defence_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.defence_buff, out);
    out << ", ";
  }

  // member: vulnerability_buff
  {
    out << "vulnerability_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.vulnerability_buff, out);
    out << ", ";
  }

  // member: attack_buff
  {
    out << "attack_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.attack_buff, out);
    out << ", ";
  }

  // member: remaining_energy
  {
    out << "remaining_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_energy, out);
    out << ", ";
  }

  // member: projectile_allowance_17mm
  {
    out << "projectile_allowance_17mm: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_allowance_17mm, out);
    out << ", ";
  }

  // member: fort_area
  {
    out << "fort_area: ";
    rosidl_generator_traits::value_to_yaml(msg.fort_area, out);
    out << ", ";
  }

  // member: supply_blood_area
  {
    out << "supply_blood_area: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_blood_area, out);
    out << ", ";
  }

  // member: local_exchange_projectile_allowance_17mm
  {
    out << "local_exchange_projectile_allowance_17mm: ";
    rosidl_generator_traits::value_to_yaml(msg.local_exchange_projectile_allowance_17mm, out);
    out << ", ";
  }

  // member: remote_exchange_projectile_times
  {
    out << "remote_exchange_projectile_times: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_exchange_projectile_times, out);
    out << ", ";
  }

  // member: remote_exchange_health_times
  {
    out << "remote_exchange_health_times: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_exchange_health_times, out);
    out << ", ";
  }

  // member: can_free_rebirth
  {
    out << "can_free_rebirth: ";
    rosidl_generator_traits::value_to_yaml(msg.can_free_rebirth, out);
    out << ", ";
  }

  // member: can_instant_rebirth
  {
    out << "can_instant_rebirth: ";
    rosidl_generator_traits::value_to_yaml(msg.can_instant_rebirth, out);
    out << ", ";
  }

  // member: rebirth_need_coin
  {
    out << "rebirth_need_coin: ";
    rosidl_generator_traits::value_to_yaml(msg.rebirth_need_coin, out);
    out << ", ";
  }

  // member: ttk_status
  {
    out << "ttk_status: ";
    rosidl_generator_traits::value_to_yaml(msg.ttk_status, out);
    out << ", ";
  }

  // member: projectile_allowance_17mm_remain
  {
    out << "projectile_allowance_17mm_remain: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_allowance_17mm_remain, out);
    out << ", ";
  }

  // member: target_position_x
  {
    out << "target_position_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position_x, out);
    out << ", ";
  }

  // member: target_position_y
  {
    out << "target_position_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }

  // member: recovery_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "recovery_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.recovery_buff, out);
    out << "\n";
  }

  // member: defence_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "defence_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.defence_buff, out);
    out << "\n";
  }

  // member: vulnerability_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vulnerability_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.vulnerability_buff, out);
    out << "\n";
  }

  // member: attack_buff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attack_buff: ";
    rosidl_generator_traits::value_to_yaml(msg.attack_buff, out);
    out << "\n";
  }

  // member: remaining_energy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_energy, out);
    out << "\n";
  }

  // member: projectile_allowance_17mm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "projectile_allowance_17mm: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_allowance_17mm, out);
    out << "\n";
  }

  // member: fort_area
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fort_area: ";
    rosidl_generator_traits::value_to_yaml(msg.fort_area, out);
    out << "\n";
  }

  // member: supply_blood_area
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "supply_blood_area: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_blood_area, out);
    out << "\n";
  }

  // member: local_exchange_projectile_allowance_17mm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_exchange_projectile_allowance_17mm: ";
    rosidl_generator_traits::value_to_yaml(msg.local_exchange_projectile_allowance_17mm, out);
    out << "\n";
  }

  // member: remote_exchange_projectile_times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remote_exchange_projectile_times: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_exchange_projectile_times, out);
    out << "\n";
  }

  // member: remote_exchange_health_times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remote_exchange_health_times: ";
    rosidl_generator_traits::value_to_yaml(msg.remote_exchange_health_times, out);
    out << "\n";
  }

  // member: can_free_rebirth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_free_rebirth: ";
    rosidl_generator_traits::value_to_yaml(msg.can_free_rebirth, out);
    out << "\n";
  }

  // member: can_instant_rebirth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_instant_rebirth: ";
    rosidl_generator_traits::value_to_yaml(msg.can_instant_rebirth, out);
    out << "\n";
  }

  // member: rebirth_need_coin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rebirth_need_coin: ";
    rosidl_generator_traits::value_to_yaml(msg.rebirth_need_coin, out);
    out << "\n";
  }

  // member: ttk_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ttk_status: ";
    rosidl_generator_traits::value_to_yaml(msg.ttk_status, out);
    out << "\n";
  }

  // member: projectile_allowance_17mm_remain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "projectile_allowance_17mm_remain: ";
    rosidl_generator_traits::value_to_yaml(msg.projectile_allowance_17mm_remain, out);
    out << "\n";
  }

  // member: target_position_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_position_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position_x, out);
    out << "\n";
  }

  // member: target_position_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_position_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
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
  const robots_msgs::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::RobotStatus & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::RobotStatus>()
{
  return "robots_msgs::msg::RobotStatus";
}

template<>
inline const char * name<robots_msgs::msg::RobotStatus>()
{
  return "robots_msgs/msg/RobotStatus";
}

template<>
struct has_fixed_size<robots_msgs::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
