// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robots_msgs/msg/detail/gimb_cmd_fram__rosidl_typesupport_introspection_c.h"
#include "robots_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__functions.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robots_msgs__msg__GimbCmdFram__init(message_memory);
}

void robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_fini_function(void * message_memory)
{
  robots_msgs__msg__GimbCmdFram__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_member_array[5] = {
  {
    "center_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__GimbCmdFram, center_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "armor_pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__GimbCmdFram, armor_pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "armor_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__GimbCmdFram, armor_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "spin_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__GimbCmdFram, spin_flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shot_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__GimbCmdFram, shot_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_members = {
  "robots_msgs__msg",  // message namespace
  "GimbCmdFram",  // message name
  5,  // number of fields
  sizeof(robots_msgs__msg__GimbCmdFram),
  false,  // has_any_key_member_
  robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_member_array,  // message members
  robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_init_function,  // function to initialize message memory (memory has to be allocated)
  robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_type_support_handle = {
  0,
  &robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_members,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__GimbCmdFram__get_type_hash,
  &robots_msgs__msg__GimbCmdFram__get_type_description,
  &robots_msgs__msg__GimbCmdFram__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robots_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robots_msgs, msg, GimbCmdFram)() {
  if (!robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_type_support_handle.typesupport_identifier) {
    robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robots_msgs__msg__GimbCmdFram__rosidl_typesupport_introspection_c__GimbCmdFram_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
