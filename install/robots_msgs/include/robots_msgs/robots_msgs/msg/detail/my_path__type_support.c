// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robots_msgs/msg/detail/my_path__rosidl_typesupport_introspection_c.h"
#include "robots_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robots_msgs/msg/detail/my_path__functions.h"
#include "robots_msgs/msg/detail/my_path__struct.h"


// Include directives for member types
// Member `delta_x`
// Member `delta_y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robots_msgs__msg__MyPath__init(message_memory);
}

void robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_fini_function(void * message_memory)
{
  robots_msgs__msg__MyPath__fini(message_memory);
}

size_t robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__size_function__MyPath__delta_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return member->size;
}

const void * robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_const_function__MyPath__delta_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_function__MyPath__delta_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__fetch_function__MyPath__delta_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_const_function__MyPath__delta_x(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__assign_function__MyPath__delta_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_function__MyPath__delta_x(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

bool robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__resize_function__MyPath__delta_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  rosidl_runtime_c__int8__Sequence__fini(member);
  return rosidl_runtime_c__int8__Sequence__init(member, size);
}

size_t robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__size_function__MyPath__delta_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return member->size;
}

const void * robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_const_function__MyPath__delta_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_function__MyPath__delta_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__fetch_function__MyPath__delta_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_const_function__MyPath__delta_y(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__assign_function__MyPath__delta_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_function__MyPath__delta_y(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

bool robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__resize_function__MyPath__delta_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  rosidl_runtime_c__int8__Sequence__fini(member);
  return rosidl_runtime_c__int8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_member_array[6] = {
  {
    "intention",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__MyPath, intention),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__MyPath, start_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__MyPath, start_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__MyPath, delta_x),  // bytes offset in struct
    NULL,  // default value
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__size_function__MyPath__delta_x,  // size() function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_const_function__MyPath__delta_x,  // get_const(index) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_function__MyPath__delta_x,  // get(index) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__fetch_function__MyPath__delta_x,  // fetch(index, &value) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__assign_function__MyPath__delta_x,  // assign(index, value) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__resize_function__MyPath__delta_x  // resize(index) function pointer
  },
  {
    "delta_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__MyPath, delta_y),  // bytes offset in struct
    NULL,  // default value
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__size_function__MyPath__delta_y,  // size() function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_const_function__MyPath__delta_y,  // get_const(index) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__get_function__MyPath__delta_y,  // get(index) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__fetch_function__MyPath__delta_y,  // fetch(index, &value) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__assign_function__MyPath__delta_y,  // assign(index, value) function pointer
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__resize_function__MyPath__delta_y  // resize(index) function pointer
  },
  {
    "sender_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs__msg__MyPath, sender_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_members = {
  "robots_msgs__msg",  // message namespace
  "MyPath",  // message name
  6,  // number of fields
  sizeof(robots_msgs__msg__MyPath),
  false,  // has_any_key_member_
  robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_member_array,  // message members
  robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_init_function,  // function to initialize message memory (memory has to be allocated)
  robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_type_support_handle = {
  0,
  &robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_members,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__MyPath__get_type_hash,
  &robots_msgs__msg__MyPath__get_type_description,
  &robots_msgs__msg__MyPath__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robots_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robots_msgs, msg, MyPath)() {
  if (!robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_type_support_handle.typesupport_identifier) {
    robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robots_msgs__msg__MyPath__rosidl_typesupport_introspection_c__MyPath_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
