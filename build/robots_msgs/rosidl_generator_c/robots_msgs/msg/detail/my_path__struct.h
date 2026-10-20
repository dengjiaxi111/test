// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/my_path.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MY_PATH__STRUCT_H_
#define ROBOTS_MSGS__MSG__DETAIL__MY_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'delta_x'
// Member 'delta_y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MyPath in the package robots_msgs.
typedef struct robots_msgs__msg__MyPath
{
  uint8_t intention;
  uint16_t start_x;
  uint16_t start_y;
  rosidl_runtime_c__int8__Sequence delta_x;
  rosidl_runtime_c__int8__Sequence delta_y;
  uint16_t sender_id;
} robots_msgs__msg__MyPath;

// Struct for a sequence of robots_msgs__msg__MyPath.
typedef struct robots_msgs__msg__MyPath__Sequence
{
  robots_msgs__msg__MyPath * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robots_msgs__msg__MyPath__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__MY_PATH__STRUCT_H_
