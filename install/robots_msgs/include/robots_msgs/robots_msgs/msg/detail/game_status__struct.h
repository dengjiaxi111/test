// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/game_status.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/GameStatus in the package robots_msgs.
/**
  * game status
 */
typedef struct robots_msgs__msg__GameStatus
{
  uint8_t game_type;
  uint8_t game_progress;
  /// 当前阶段剩余时间
  uint16_t stage_remain_time;
  uint16_t my_hp;
  uint16_t my_outpost_hp;
  uint16_t my_base_hp;
  float our_hero_x;
  float our_hero_y;
  uint16_t enemy_1_robot_hp;
  uint16_t enemy_2_robot_hp;
  uint16_t enemy_3_robot_hp;
  uint16_t enemy_4_robot_hp;
  uint16_t enemy_5_robot_hp;
  uint16_t enemy_7_robot_hp;
  uint16_t enemy_outpost_hp;
  uint16_t enemy_base_hp;
  /// 己方补给站前补血点的占领状态
  uint8_t external_supply_area_occupied;
  /// 己方补给站内部补血点的占领状态
  uint8_t inner_supply_area_occupied;
  /// 己方补给区的占领状态
  uint8_t supply_area_occupied;
  /// 己方小符激活状态
  uint8_t our_small_buff_activated;
  /// 己方大符激活状态
  uint8_t our_big_buff_activated;
  /// 己方堡垒占领状态
  uint8_t our_fortress_status;
  uint16_t remaining_gold_coin;
} robots_msgs__msg__GameStatus;

// Struct for a sequence of robots_msgs__msg__GameStatus.
typedef struct robots_msgs__msg__GameStatus__Sequence
{
  robots_msgs__msg__GameStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__GameStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__STRUCT_H_
