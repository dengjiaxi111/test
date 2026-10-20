// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/robot_status.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/RobotStatus in the package robots_msgs.
/**
  * robot status
 */
typedef struct robots_msgs__msg__RobotStatus
{
  uint8_t robot_id;
  /// 本机器人位置 x 坐标，单位：m
  float x;
  /// 本机器人位置 y 坐标，单位：m
  float y;
  /// 本机器人测速模块的朝向，单位：度。正北为 0 度
  float angle;
  /// 机器人回血增益（百分比，值为 10 表示每秒恢复血量上限的 10%
  uint8_t recovery_buff;
  /// 机器人防御增益（百分比，值为 50 表示 50%防御增益
  uint8_t defence_buff;
  /// 机器人负防御增益（百分比，值为 30 表示-30%防御增益）
  uint8_t vulnerability_buff;
  /// 机器人攻击增益（百分比，值为 50 表示 50%攻击增益
  uint16_t attack_buff;
  /// 机器人剩余能量值反馈，以 16 进制标识机器人剩余能量值比例
  uint8_t remaining_energy;
  /// 17mm 弹丸允许发弹量
  uint16_t projectile_allowance_17mm;
  /// 己方堡垒
  uint8_t fort_area;
  /// 己方补血点
  uint8_t supply_blood_area;
  uint16_t local_exchange_projectile_allowance_17mm;
  uint8_t remote_exchange_projectile_times;
  uint8_t remote_exchange_health_times;
  uint8_t can_free_rebirth;
  uint8_t can_instant_rebirth;
  uint16_t rebirth_need_coin;
  uint8_t ttk_status;
  uint16_t projectile_allowance_17mm_remain;
  /// 云台手发的控制目标位置x坐标
  float target_position_x;
  /// 云台手发的控制目标位置y坐标
  float target_position_y;
} robots_msgs__msg__RobotStatus;

// Struct for a sequence of robots_msgs__msg__RobotStatus.
typedef struct robots_msgs__msg__RobotStatus__Sequence
{
  robots_msgs__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
