// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice
#ifndef ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/game_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__GameStatus(
  const robots_msgs__msg__GameStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__GameStatus(
  eprosima::fastcdr::Cdr &,
  robots_msgs__msg__GameStatus * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__GameStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__GameStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__GameStatus(
  const robots_msgs__msg__GameStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__GameStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__GameStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, GameStatus)();

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
