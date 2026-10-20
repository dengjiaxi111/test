// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/game_status.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/game_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GameStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: game_type
  {
    out << "game_type: ";
    rosidl_generator_traits::value_to_yaml(msg.game_type, out);
    out << ", ";
  }

  // member: game_progress
  {
    out << "game_progress: ";
    rosidl_generator_traits::value_to_yaml(msg.game_progress, out);
    out << ", ";
  }

  // member: stage_remain_time
  {
    out << "stage_remain_time: ";
    rosidl_generator_traits::value_to_yaml(msg.stage_remain_time, out);
    out << ", ";
  }

  // member: my_hp
  {
    out << "my_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.my_hp, out);
    out << ", ";
  }

  // member: my_outpost_hp
  {
    out << "my_outpost_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.my_outpost_hp, out);
    out << ", ";
  }

  // member: my_base_hp
  {
    out << "my_base_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.my_base_hp, out);
    out << ", ";
  }

  // member: our_hero_x
  {
    out << "our_hero_x: ";
    rosidl_generator_traits::value_to_yaml(msg.our_hero_x, out);
    out << ", ";
  }

  // member: our_hero_y
  {
    out << "our_hero_y: ";
    rosidl_generator_traits::value_to_yaml(msg.our_hero_y, out);
    out << ", ";
  }

  // member: enemy_1_robot_hp
  {
    out << "enemy_1_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_1_robot_hp, out);
    out << ", ";
  }

  // member: enemy_2_robot_hp
  {
    out << "enemy_2_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_2_robot_hp, out);
    out << ", ";
  }

  // member: enemy_3_robot_hp
  {
    out << "enemy_3_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_3_robot_hp, out);
    out << ", ";
  }

  // member: enemy_4_robot_hp
  {
    out << "enemy_4_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_4_robot_hp, out);
    out << ", ";
  }

  // member: enemy_5_robot_hp
  {
    out << "enemy_5_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_5_robot_hp, out);
    out << ", ";
  }

  // member: enemy_7_robot_hp
  {
    out << "enemy_7_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_7_robot_hp, out);
    out << ", ";
  }

  // member: enemy_outpost_hp
  {
    out << "enemy_outpost_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_outpost_hp, out);
    out << ", ";
  }

  // member: enemy_base_hp
  {
    out << "enemy_base_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_base_hp, out);
    out << ", ";
  }

  // member: external_supply_area_occupied
  {
    out << "external_supply_area_occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.external_supply_area_occupied, out);
    out << ", ";
  }

  // member: inner_supply_area_occupied
  {
    out << "inner_supply_area_occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.inner_supply_area_occupied, out);
    out << ", ";
  }

  // member: supply_area_occupied
  {
    out << "supply_area_occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_area_occupied, out);
    out << ", ";
  }

  // member: our_small_buff_activated
  {
    out << "our_small_buff_activated: ";
    rosidl_generator_traits::value_to_yaml(msg.our_small_buff_activated, out);
    out << ", ";
  }

  // member: our_big_buff_activated
  {
    out << "our_big_buff_activated: ";
    rosidl_generator_traits::value_to_yaml(msg.our_big_buff_activated, out);
    out << ", ";
  }

  // member: our_fortress_status
  {
    out << "our_fortress_status: ";
    rosidl_generator_traits::value_to_yaml(msg.our_fortress_status, out);
    out << ", ";
  }

  // member: remaining_gold_coin
  {
    out << "remaining_gold_coin: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_gold_coin, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GameStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: game_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "game_type: ";
    rosidl_generator_traits::value_to_yaml(msg.game_type, out);
    out << "\n";
  }

  // member: game_progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "game_progress: ";
    rosidl_generator_traits::value_to_yaml(msg.game_progress, out);
    out << "\n";
  }

  // member: stage_remain_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stage_remain_time: ";
    rosidl_generator_traits::value_to_yaml(msg.stage_remain_time, out);
    out << "\n";
  }

  // member: my_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.my_hp, out);
    out << "\n";
  }

  // member: my_outpost_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_outpost_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.my_outpost_hp, out);
    out << "\n";
  }

  // member: my_base_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_base_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.my_base_hp, out);
    out << "\n";
  }

  // member: our_hero_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "our_hero_x: ";
    rosidl_generator_traits::value_to_yaml(msg.our_hero_x, out);
    out << "\n";
  }

  // member: our_hero_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "our_hero_y: ";
    rosidl_generator_traits::value_to_yaml(msg.our_hero_y, out);
    out << "\n";
  }

  // member: enemy_1_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_1_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_1_robot_hp, out);
    out << "\n";
  }

  // member: enemy_2_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_2_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_2_robot_hp, out);
    out << "\n";
  }

  // member: enemy_3_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_3_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_3_robot_hp, out);
    out << "\n";
  }

  // member: enemy_4_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_4_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_4_robot_hp, out);
    out << "\n";
  }

  // member: enemy_5_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_5_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_5_robot_hp, out);
    out << "\n";
  }

  // member: enemy_7_robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_7_robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_7_robot_hp, out);
    out << "\n";
  }

  // member: enemy_outpost_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_outpost_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_outpost_hp, out);
    out << "\n";
  }

  // member: enemy_base_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_base_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_base_hp, out);
    out << "\n";
  }

  // member: external_supply_area_occupied
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "external_supply_area_occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.external_supply_area_occupied, out);
    out << "\n";
  }

  // member: inner_supply_area_occupied
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inner_supply_area_occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.inner_supply_area_occupied, out);
    out << "\n";
  }

  // member: supply_area_occupied
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "supply_area_occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.supply_area_occupied, out);
    out << "\n";
  }

  // member: our_small_buff_activated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "our_small_buff_activated: ";
    rosidl_generator_traits::value_to_yaml(msg.our_small_buff_activated, out);
    out << "\n";
  }

  // member: our_big_buff_activated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "our_big_buff_activated: ";
    rosidl_generator_traits::value_to_yaml(msg.our_big_buff_activated, out);
    out << "\n";
  }

  // member: our_fortress_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "our_fortress_status: ";
    rosidl_generator_traits::value_to_yaml(msg.our_fortress_status, out);
    out << "\n";
  }

  // member: remaining_gold_coin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining_gold_coin: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_gold_coin, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GameStatus & msg, bool use_flow_style = false)
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
  const robots_msgs::msg::GameStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::GameStatus & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::GameStatus>()
{
  return "robots_msgs::msg::GameStatus";
}

template<>
inline const char * name<robots_msgs::msg::GameStatus>()
{
  return "robots_msgs/msg/GameStatus";
}

template<>
struct has_fixed_size<robots_msgs::msg::GameStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robots_msgs::msg::GameStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robots_msgs::msg::GameStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__TRAITS_HPP_
