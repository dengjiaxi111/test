// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/enemy_pose.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/EnemyPose in the package robots_msgs.
/**
  * enemy pose
 */
typedef struct robots_msgs__msg__EnemyPose
{
  float enemy_dist;
  float enemy_ori;
  int8_t enemy_num;
  float enemy_x;
  float enemy_y;
} robots_msgs__msg__EnemyPose;

// Struct for a sequence of robots_msgs__msg__EnemyPose.
typedef struct robots_msgs__msg__EnemyPose__Sequence
{
  robots_msgs__msg__EnemyPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__EnemyPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__STRUCT_H_
