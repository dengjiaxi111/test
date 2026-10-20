// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nav_interfaces/srv/detail/apply_temporary_map__rosidl_typesupport_introspection_c.h"
#include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
#include "nav_interfaces/srv/detail/apply_temporary_map__struct.h"


// Include directives for member types
// Member `expected_session_id`
// Member `expected_source_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `indices`
// Member `values`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__srv__ApplyTemporaryMap_Request__init(message_memory);
}

void nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_fini_function(void * message_memory)
{
  nav_interfaces__srv__ApplyTemporaryMap_Request__fini(message_memory);
}

size_t nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Request__indices(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Request__indices(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Request__indices(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Request__indices(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Request__indices(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Request__indices(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Request__indices(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Request__indices(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

size_t nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Request__values(
  const void * untyped_member)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Request__values(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Request__values(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Request__values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Request__values(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Request__values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Request__values(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Request__values(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  rosidl_runtime_c__int8__Sequence__fini(member);
  return rosidl_runtime_c__int8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_member_array[5] = {
  {
    "expected_session_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Request, expected_session_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "expected_source_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Request, expected_source_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "expected_map_revision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Request, expected_map_revision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "indices",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Request, indices),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Request__indices,  // size() function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Request__indices,  // get_const(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Request__indices,  // get(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Request__indices,  // fetch(index, &value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Request__indices,  // assign(index, value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Request__indices  // resize(index) function pointer
  },
  {
    "values",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Request, values),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Request__values,  // size() function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Request__values,  // get_const(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Request__values,  // get(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Request__values,  // fetch(index, &value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Request__values,  // assign(index, value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Request__values  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_members = {
  "nav_interfaces__srv",  // message namespace
  "ApplyTemporaryMap_Request",  // message name
  5,  // number of fields
  sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request),
  false,  // has_any_key_member_
  nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_member_array,  // message members
  nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_type_support_handle = {
  0,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Request)() {
  if (!nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.h"


// Include directives for member types
// Member `reason`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__srv__ApplyTemporaryMap_Response__init(message_memory);
}

void nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_fini_function(void * message_memory)
{
  nav_interfaces__srv__ApplyTemporaryMap_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_member_array[4] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Response, success),  // bytes offset in struct
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
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Response, reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "map_revision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Response, map_revision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "replanning_triggered",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Response, replanning_triggered),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_members = {
  "nav_interfaces__srv",  // message namespace
  "ApplyTemporaryMap_Response",  // message name
  4,  // number of fields
  sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response),
  false,  // has_any_key_member_
  nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_member_array,  // message members
  nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle = {
  0,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Response)() {
  if (!nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "nav_interfaces/srv/apply_temporary_map.h"
// Member `request`
// Member `response`
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__srv__ApplyTemporaryMap_Event__init(message_memory);
}

void nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_fini_function(void * message_memory)
{
  nav_interfaces__srv__ApplyTemporaryMap_Event__fini(message_memory);
}

size_t nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Event__request(
  const void * untyped_member)
{
  const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * member =
    (const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Event__request(
  const void * untyped_member, size_t index)
{
  const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * member =
    (const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Event__request(
  void * untyped_member, size_t index)
{
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * member =
    (nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_interfaces__srv__ApplyTemporaryMap_Request * item =
    ((const nav_interfaces__srv__ApplyTemporaryMap_Request *)
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Event__request(untyped_member, index));
  nav_interfaces__srv__ApplyTemporaryMap_Request * value =
    (nav_interfaces__srv__ApplyTemporaryMap_Request *)(untyped_value);
  *value = *item;
}

void nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_interfaces__srv__ApplyTemporaryMap_Request * item =
    ((nav_interfaces__srv__ApplyTemporaryMap_Request *)
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Event__request(untyped_member, index));
  const nav_interfaces__srv__ApplyTemporaryMap_Request * value =
    (const nav_interfaces__srv__ApplyTemporaryMap_Request *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Event__request(
  void * untyped_member, size_t size)
{
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * member =
    (nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence *)(untyped_member);
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(member);
  return nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(member, size);
}

size_t nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Event__response(
  const void * untyped_member)
{
  const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * member =
    (const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Event__response(
  const void * untyped_member, size_t index)
{
  const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * member =
    (const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Event__response(
  void * untyped_member, size_t index)
{
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * member =
    (nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_interfaces__srv__ApplyTemporaryMap_Response * item =
    ((const nav_interfaces__srv__ApplyTemporaryMap_Response *)
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Event__response(untyped_member, index));
  nav_interfaces__srv__ApplyTemporaryMap_Response * value =
    (nav_interfaces__srv__ApplyTemporaryMap_Response *)(untyped_value);
  *value = *item;
}

void nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_interfaces__srv__ApplyTemporaryMap_Response * item =
    ((nav_interfaces__srv__ApplyTemporaryMap_Response *)
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Event__response(untyped_member, index));
  const nav_interfaces__srv__ApplyTemporaryMap_Response * value =
    (const nav_interfaces__srv__ApplyTemporaryMap_Response *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Event__response(
  void * untyped_member, size_t size)
{
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * member =
    (nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence *)(untyped_member);
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(member);
  return nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Event, request),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Event__request,  // size() function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Event__request,  // get_const(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Event__request,  // get(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Event__request,  // fetch(index, &value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Event__request,  // assign(index, value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(nav_interfaces__srv__ApplyTemporaryMap_Event, response),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__size_function__ApplyTemporaryMap_Event__response,  // size() function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_const_function__ApplyTemporaryMap_Event__response,  // get_const(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__get_function__ApplyTemporaryMap_Event__response,  // get(index) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__fetch_function__ApplyTemporaryMap_Event__response,  // fetch(index, &value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__assign_function__ApplyTemporaryMap_Event__response,  // assign(index, value) function pointer
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__resize_function__ApplyTemporaryMap_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_members = {
  "nav_interfaces__srv",  // message namespace
  "ApplyTemporaryMap_Event",  // message name
  3,  // number of fields
  sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event),
  false,  // has_any_key_member_
  nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_member_array,  // message members
  nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_type_support_handle = {
  0,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Event)() {
  nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Request)();
  nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Response)();
  if (!nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_members = {
  "nav_interfaces__srv",  // service namespace
  "ApplyTemporaryMap",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_type_support_handle,
  NULL,  // response message
  // nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle
  NULL  // event_message
  // nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle
};


static rosidl_service_type_support_t nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_type_support_handle = {
  0,
  &nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_members,
  get_service_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Request_message_type_support_handle,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Response_message_type_support_handle,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__rosidl_typesupport_introspection_c__ApplyTemporaryMap_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    nav_interfaces,
    srv,
    ApplyTemporaryMap
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    nav_interfaces,
    srv,
    ApplyTemporaryMap
  ),
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap)(void) {
  if (!nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_type_support_handle.typesupport_identifier) {
    nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, ApplyTemporaryMap_Event)()->data;
  }

  return &nav_interfaces__srv__detail__apply_temporary_map__rosidl_typesupport_introspection_c__ApplyTemporaryMap_service_type_support_handle;
}
