// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice
#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nav_interfaces/msg/detail/hole_traversal__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_nav_interfaces__msg__HoleTraversal(
  const nav_interfaces__msg__HoleTraversal * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_deserialize_nav_interfaces__msg__HoleTraversal(
  eprosima::fastcdr::Cdr &,
  nav_interfaces__msg__HoleTraversal * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_nav_interfaces__msg__HoleTraversal(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_nav_interfaces__msg__HoleTraversal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_key_nav_interfaces__msg__HoleTraversal(
  const nav_interfaces__msg__HoleTraversal * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_key_nav_interfaces__msg__HoleTraversal(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_key_nav_interfaces__msg__HoleTraversal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, msg, HoleTraversal)();

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
