// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/chassis_odom.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ChassisOdom in the package robots_msgs.
typedef struct robots_msgs__msg__ChassisOdom
{
  float speed_x;
  float speed_y;
  float speed_w;
  float gimbal_angle;
  float capacitor_voltage;
} robots_msgs__msg__ChassisOdom;

// Struct for a sequence of robots_msgs__msg__ChassisOdom.
typedef struct robots_msgs__msg__ChassisOdom__Sequence
{
  robots_msgs__msg__ChassisOdom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__ChassisOdom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__STRUCT_H_
