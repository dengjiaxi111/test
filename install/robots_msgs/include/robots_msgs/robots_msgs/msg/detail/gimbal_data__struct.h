// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimbal_data.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/GimbalData in the package robots_msgs.
/**
  * gimbal data
 */
typedef struct robots_msgs__msg__GimbalData
{
  float gimbal_yaw;
  float gimbal_pitch;
  float yaw_va;
  float base_yaw;
  uint8_t self_team;
} robots_msgs__msg__GimbalData;

// Struct for a sequence of robots_msgs__msg__GimbalData.
typedef struct robots_msgs__msg__GimbalData__Sequence
{
  robots_msgs__msg__GimbalData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__GimbalData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__STRUCT_H_
