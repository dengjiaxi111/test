// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nav_interfaces/msg/detail/hole_traversal__rosidl_typesupport_introspection_c.h"
#include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"
#include "nav_interfaces/msg/detail/hole_traversal__struct.h"


// Include directives for member types
// Member `traversal_uid`
// Member `hole_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `events`
#include "nav_interfaces/msg/hole_event.h"
// Member `events`
#include "nav_interfaces/msg/detail/hole_event__rosidl_typesupport_introspection_c.h"
// Member `straight_segments`
#include "nav_interfaces/msg/hole_straight.h"
// Member `straight_segments`
#include "nav_interfaces/msg/detail/hole_straight__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__msg__HoleTraversal__init(message_memory);
}

void nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_fini_function(void * message_memory)
{
  nav_interfaces__msg__HoleTraversal__fini(message_memory);
}

size_t nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__size_function__HoleTraversal__events(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_const_function__HoleTraversal__events(
  const void * untyped_member, size_t index)
{
  const nav_interfaces__msg__HoleEvent * member =
    (const nav_interfaces__msg__HoleEvent *)(untyped_member);
  return &member[index];
}

void * nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_function__HoleTraversal__events(
  void * untyped_member, size_t index)
{
  nav_interfaces__msg__HoleEvent * member =
    (nav_interfaces__msg__HoleEvent *)(untyped_member);
  return &member[index];
}

void nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__fetch_function__HoleTraversal__events(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_interfaces__msg__HoleEvent * item =
    ((const nav_interfaces__msg__HoleEvent *)
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_const_function__HoleTraversal__events(untyped_member, index));
  nav_interfaces__msg__HoleEvent * value =
    (nav_interfaces__msg__HoleEvent *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__assign_function__HoleTraversal__events(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_interfaces__msg__HoleEvent * item =
    ((nav_interfaces__msg__HoleEvent *)
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_function__HoleTraversal__events(untyped_member, index));
  const nav_interfaces__msg__HoleEvent * value =
    (const nav_interfaces__msg__HoleEvent *)(untyped_value);
  *item = *value;
}

size_t nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__size_function__HoleTraversal__straight_segments(
  const void * untyped_member)
{
  const nav_interfaces__msg__HoleStraight__Sequence * member =
    (const nav_interfaces__msg__HoleStraight__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_const_function__HoleTraversal__straight_segments(
  const void * untyped_member, size_t index)
{
  const nav_interfaces__msg__HoleStraight__Sequence * member =
    (const nav_interfaces__msg__HoleStraight__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_function__HoleTraversal__straight_segments(
  void * untyped_member, size_t index)
{
  nav_interfaces__msg__HoleStraight__Sequence * member =
    (nav_interfaces__msg__HoleStraight__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__fetch_function__HoleTraversal__straight_segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_interfaces__msg__HoleStraight * item =
    ((const nav_interfaces__msg__HoleStraight *)
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_const_function__HoleTraversal__straight_segments(untyped_member, index));
  nav_interfaces__msg__HoleStraight * value =
    (nav_interfaces__msg__HoleStraight *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__assign_function__HoleTraversal__straight_segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_interfaces__msg__HoleStraight * item =
    ((nav_interfaces__msg__HoleStraight *)
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_function__HoleTraversal__straight_segments(untyped_member, index));
  const nav_interfaces__msg__HoleStraight * value =
    (const nav_interfaces__msg__HoleStraight *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__resize_function__HoleTraversal__straight_segments(
  void * untyped_member, size_t size)
{
  nav_interfaces__msg__HoleStraight__Sequence * member =
    (nav_interfaces__msg__HoleStraight__Sequence *)(untyped_member);
  nav_interfaces__msg__HoleStraight__Sequence__fini(member);
  return nav_interfaces__msg__HoleStraight__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_member_array[10] = {
  {
    "traversal_uid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, traversal_uid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hole_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, hole_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "entry_edge_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, entry_edge_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "exit_edge_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, exit_edge_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "centerline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, centerline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "validated",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, validated),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "requirement_revision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, requirement_revision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "events",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, events),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__size_function__HoleTraversal__events,  // size() function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_const_function__HoleTraversal__events,  // get_const(index) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_function__HoleTraversal__events,  // get(index) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__fetch_function__HoleTraversal__events,  // fetch(index, &value) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__assign_function__HoleTraversal__events,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "straight_segments",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, straight_segments),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__size_function__HoleTraversal__straight_segments,  // size() function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_const_function__HoleTraversal__straight_segments,  // get_const(index) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__get_function__HoleTraversal__straight_segments,  // get(index) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__fetch_function__HoleTraversal__straight_segments,  // fetch(index, &value) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__assign_function__HoleTraversal__straight_segments,  // assign(index, value) function pointer
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__resize_function__HoleTraversal__straight_segments  // resize(index) function pointer
  },
  {
    "uphill_entry",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversal, uphill_entry),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_members = {
  "nav_interfaces__msg",  // message namespace
  "HoleTraversal",  // message name
  10,  // number of fields
  sizeof(nav_interfaces__msg__HoleTraversal),
  false,  // has_any_key_member_
  nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_member_array,  // message members
  nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_type_support_handle = {
  0,
  &nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleTraversal__get_type_hash,
  &nav_interfaces__msg__HoleTraversal__get_type_description,
  &nav_interfaces__msg__HoleTraversal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleTraversal)() {
  nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleEvent)();
  nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleStraight)();
  if (!nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__msg__HoleTraversal__rosidl_typesupport_introspection_c__HoleTraversal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
