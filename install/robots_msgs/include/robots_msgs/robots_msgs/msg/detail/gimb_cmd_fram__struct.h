// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimb_cmd_fram.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/GimbCmdFram in the package robots_msgs.
typedef struct robots_msgs__msg__GimbCmdFram
{
  float center_yaw;
  float armor_pitch;
  float armor_yaw;
  uint8_t spin_flag;
  uint8_t shot_mode;
} robots_msgs__msg__GimbCmdFram;

// Struct for a sequence of robots_msgs__msg__GimbCmdFram.
typedef struct robots_msgs__msg__GimbCmdFram__Sequence
{
  robots_msgs__msg__GimbCmdFram * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__GimbCmdFram__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__STRUCT_H_
