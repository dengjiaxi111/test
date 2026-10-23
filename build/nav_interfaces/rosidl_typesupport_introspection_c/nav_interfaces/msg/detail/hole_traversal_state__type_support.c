// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nav_interfaces/msg/detail/hole_traversal_state__rosidl_typesupport_introspection_c.h"
#include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nav_interfaces/msg/detail/hole_traversal_state__functions.h"
#include "nav_interfaces/msg/detail/hole_traversal_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `session_id`
// Member `goal_id`
// Member `reason`
// Member `traversal_uids`
#include "rosidl_runtime_c/string_functions.h"
// Member `phases`
// Member `preparing_required`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__msg__HoleTraversalState__init(message_memory);
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_fini_function(void * message_memory)
{
  nav_interfaces__msg__HoleTraversalState__fini(message_memory);
}

size_t nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__size_function__HoleTraversalState__traversal_uids(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__traversal_uids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__traversal_uids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__fetch_function__HoleTraversalState__traversal_uids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__traversal_uids(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__assign_function__HoleTraversalState__traversal_uids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__traversal_uids(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__resize_function__HoleTraversalState__traversal_uids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__size_function__HoleTraversalState__phases(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__phases(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__phases(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__fetch_function__HoleTraversalState__phases(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__phases(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__assign_function__HoleTraversalState__phases(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__phases(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__resize_function__HoleTraversalState__phases(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__size_function__HoleTraversalState__preparing_required(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__preparing_required(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__preparing_required(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__fetch_function__HoleTraversalState__preparing_required(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__preparing_required(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__assign_function__HoleTraversalState__preparing_required(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__preparing_required(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__resize_function__HoleTraversalState__preparing_required(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_member_array[15] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "session_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, session_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "plan_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, plan_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "decision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, decision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "s_progress",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, s_progress),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_limit",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, speed_limit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "traversal_uids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, traversal_uids),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__size_function__HoleTraversalState__traversal_uids,  // size() function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__traversal_uids,  // get_const(index) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__traversal_uids,  // get(index) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__fetch_function__HoleTraversalState__traversal_uids,  // fetch(index, &value) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__assign_function__HoleTraversalState__traversal_uids,  // assign(index, value) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__resize_function__HoleTraversalState__traversal_uids  // resize(index) function pointer
  },
  {
    "phases",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, phases),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__size_function__HoleTraversalState__phases,  // size() function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__phases,  // get_const(index) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__phases,  // get(index) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__fetch_function__HoleTraversalState__phases,  // fetch(index, &value) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__assign_function__HoleTraversalState__phases,  // assign(index, value) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__resize_function__HoleTraversalState__phases  // resize(index) function pointer
  },
  {
    "preparing_required",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, preparing_required),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__size_function__HoleTraversalState__preparing_required,  // size() function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_const_function__HoleTraversalState__preparing_required,  // get_const(index) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__get_function__HoleTraversalState__preparing_required,  // get(index) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__fetch_function__HoleTraversalState__preparing_required,  // fetch(index, &value) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__assign_function__HoleTraversalState__preparing_required,  // assign(index, value) function pointer
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__resize_function__HoleTraversalState__preparing_required  // resize(index) function pointer
  },
  {
    "attempt",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, attempt),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "recovery_phase",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, recovery_phase),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hold_gimbal_heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleTraversalState, hold_gimbal_heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_members = {
  "nav_interfaces__msg",  // message namespace
  "HoleTraversalState",  // message name
  15,  // number of fields
  sizeof(nav_interfaces__msg__HoleTraversalState),
  false,  // has_any_key_member_
  nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_member_array,  // message members
  nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_type_support_handle = {
  0,
  &nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleTraversalState__get_type_hash,
  &nav_interfaces__msg__HoleTraversalState__get_type_description,
  &nav_interfaces__msg__HoleTraversalState__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleTraversalState)() {
  nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__msg__HoleTraversalState__rosidl_typesupport_introspection_c__HoleTraversalState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
