// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice
#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__GimbCmdFram(
  const robots_msgs__msg__GimbCmdFram * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__GimbCmdFram(
  eprosima::fastcdr::Cdr &,
  robots_msgs__msg__GimbCmdFram * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__GimbCmdFram(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__GimbCmdFram(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__GimbCmdFram(
  const robots_msgs__msg__GimbCmdFram * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__GimbCmdFram(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__GimbCmdFram(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, GimbCmdFram)();

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
