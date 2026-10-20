// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nav_interfaces/msg/detail/hole_structure_request__rosidl_typesupport_introspection_c.h"
#include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nav_interfaces/msg/detail/hole_structure_request__functions.h"
#include "nav_interfaces/msg/detail/hole_structure_request__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `session_id`
// Member `goal_id`
// Member `traversal_uids`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__msg__HoleStructureRequest__init(message_memory);
}

void nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_fini_function(void * message_memory)
{
  nav_interfaces__msg__HoleStructureRequest__fini(message_memory);
}

size_t nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__size_function__HoleStructureRequest__traversal_uids(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__get_const_function__HoleStructureRequest__traversal_uids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__get_function__HoleStructureRequest__traversal_uids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__fetch_function__HoleStructureRequest__traversal_uids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__get_const_function__HoleStructureRequest__traversal_uids(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__assign_function__HoleStructureRequest__traversal_uids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__get_function__HoleStructureRequest__traversal_uids(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__resize_function__HoleStructureRequest__traversal_uids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleStructureRequest, header),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__HoleStructureRequest, session_id),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__HoleStructureRequest, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleStructureRequest, request_id),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__HoleStructureRequest, requirement_revision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleStructureRequest, target),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__HoleStructureRequest, traversal_uids),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__size_function__HoleStructureRequest__traversal_uids,  // size() function pointer
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__get_const_function__HoleStructureRequest__traversal_uids,  // get_const(index) function pointer
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__get_function__HoleStructureRequest__traversal_uids,  // get(index) function pointer
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__fetch_function__HoleStructureRequest__traversal_uids,  // fetch(index, &value) function pointer
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__assign_function__HoleStructureRequest__traversal_uids,  // assign(index, value) function pointer
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__resize_function__HoleStructureRequest__traversal_uids  // resize(index) function pointer
  },
  {
    "cancel_motion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__HoleStructureRequest, cancel_motion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_members = {
  "nav_interfaces__msg",  // message namespace
  "HoleStructureRequest",  // message name
  8,  // number of fields
  sizeof(nav_interfaces__msg__HoleStructureRequest),
  false,  // has_any_key_member_
  nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_member_array,  // message members
  nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_type_support_handle = {
  0,
  &nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleStructureRequest__get_type_hash,
  &nav_interfaces__msg__HoleStructureRequest__get_type_description,
  &nav_interfaces__msg__HoleStructureRequest__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleStructureRequest)() {
  nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__msg__HoleStructureRequest__rosidl_typesupport_introspection_c__HoleStructureRequest_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
