// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/mode_cmd.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ModeCmd in the package robots_msgs.
typedef struct robots_msgs__msg__ModeCmd
{
  uint8_t should_chassis_spin;
  uint8_t should_gimbal_patrol;
  uint8_t buy_bullet;
  uint8_t rebirth;
  uint8_t use_capacity;
} robots_msgs__msg__ModeCmd;

// Struct for a sequence of robots_msgs__msg__ModeCmd.
typedef struct robots_msgs__msg__ModeCmd__Sequence
{
  robots_msgs__msg__ModeCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__ModeCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__STRUCT_H_
