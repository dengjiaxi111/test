// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nav_interfaces/msg/detail/navigation_plan__rosidl_typesupport_introspection_c.h"
#include "nav_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nav_interfaces/msg/detail/navigation_plan__functions.h"
#include "nav_interfaces/msg/detail/navigation_plan__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `session_id`
// Member `goal_id`
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"
// Member `path`
#include "nav_msgs/msg/path.h"
// Member `path`
#include "nav_msgs/msg/detail/path__rosidl_typesupport_introspection_c.h"
// Member `passages`
#include "nav_interfaces/msg/hole_traversal.h"
// Member `passages`
#include "nav_interfaces/msg/detail/hole_traversal__rosidl_typesupport_introspection_c.h"
// Member `speed_regions`
#include "nav_interfaces/msg/hole_speed_region.h"
// Member `speed_regions`
#include "nav_interfaces/msg/detail/hole_speed_region__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nav_interfaces__msg__NavigationPlan__init(message_memory);
}

void nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_fini_function(void * message_memory)
{
  nav_interfaces__msg__NavigationPlan__fini(message_memory);
}

size_t nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__size_function__NavigationPlan__passages(
  const void * untyped_member)
{
  const nav_interfaces__msg__HoleTraversal__Sequence * member =
    (const nav_interfaces__msg__HoleTraversal__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_const_function__NavigationPlan__passages(
  const void * untyped_member, size_t index)
{
  const nav_interfaces__msg__HoleTraversal__Sequence * member =
    (const nav_interfaces__msg__HoleTraversal__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_function__NavigationPlan__passages(
  void * untyped_member, size_t index)
{
  nav_interfaces__msg__HoleTraversal__Sequence * member =
    (nav_interfaces__msg__HoleTraversal__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__fetch_function__NavigationPlan__passages(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_interfaces__msg__HoleTraversal * item =
    ((const nav_interfaces__msg__HoleTraversal *)
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_const_function__NavigationPlan__passages(untyped_member, index));
  nav_interfaces__msg__HoleTraversal * value =
    (nav_interfaces__msg__HoleTraversal *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__assign_function__NavigationPlan__passages(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_interfaces__msg__HoleTraversal * item =
    ((nav_interfaces__msg__HoleTraversal *)
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_function__NavigationPlan__passages(untyped_member, index));
  const nav_interfaces__msg__HoleTraversal * value =
    (const nav_interfaces__msg__HoleTraversal *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__resize_function__NavigationPlan__passages(
  void * untyped_member, size_t size)
{
  nav_interfaces__msg__HoleTraversal__Sequence * member =
    (nav_interfaces__msg__HoleTraversal__Sequence *)(untyped_member);
  nav_interfaces__msg__HoleTraversal__Sequence__fini(member);
  return nav_interfaces__msg__HoleTraversal__Sequence__init(member, size);
}

size_t nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__size_function__NavigationPlan__speed_regions(
  const void * untyped_member)
{
  const nav_interfaces__msg__HoleSpeedRegion__Sequence * member =
    (const nav_interfaces__msg__HoleSpeedRegion__Sequence *)(untyped_member);
  return member->size;
}

const void * nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_const_function__NavigationPlan__speed_regions(
  const void * untyped_member, size_t index)
{
  const nav_interfaces__msg__HoleSpeedRegion__Sequence * member =
    (const nav_interfaces__msg__HoleSpeedRegion__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_function__NavigationPlan__speed_regions(
  void * untyped_member, size_t index)
{
  nav_interfaces__msg__HoleSpeedRegion__Sequence * member =
    (nav_interfaces__msg__HoleSpeedRegion__Sequence *)(untyped_member);
  return &member->data[index];
}

void nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__fetch_function__NavigationPlan__speed_regions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nav_interfaces__msg__HoleSpeedRegion * item =
    ((const nav_interfaces__msg__HoleSpeedRegion *)
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_const_function__NavigationPlan__speed_regions(untyped_member, index));
  nav_interfaces__msg__HoleSpeedRegion * value =
    (nav_interfaces__msg__HoleSpeedRegion *)(untyped_value);
  *value = *item;
}

void nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__assign_function__NavigationPlan__speed_regions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nav_interfaces__msg__HoleSpeedRegion * item =
    ((nav_interfaces__msg__HoleSpeedRegion *)
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_function__NavigationPlan__speed_regions(untyped_member, index));
  const nav_interfaces__msg__HoleSpeedRegion * value =
    (const nav_interfaces__msg__HoleSpeedRegion *)(untyped_value);
  *item = *value;
}

bool nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__resize_function__NavigationPlan__speed_regions(
  void * untyped_member, size_t size)
{
  nav_interfaces__msg__HoleSpeedRegion__Sequence * member =
    (nav_interfaces__msg__HoleSpeedRegion__Sequence *)(untyped_member);
  nav_interfaces__msg__HoleSpeedRegion__Sequence__fini(member);
  return nav_interfaces__msg__HoleSpeedRegion__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_member_array[14] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, header),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__NavigationPlan, session_id),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__NavigationPlan, goal_id),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__NavigationPlan, plan_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, status),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__NavigationPlan, reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "constraints_enabled",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, constraints_enabled),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "terrain_revision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, terrain_revision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "parameter_revision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, parameter_revision),  // bytes offset in struct
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
    offsetof(nav_interfaces__msg__NavigationPlan, map_revision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, path_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "passages",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, passages),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__size_function__NavigationPlan__passages,  // size() function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_const_function__NavigationPlan__passages,  // get_const(index) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_function__NavigationPlan__passages,  // get(index) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__fetch_function__NavigationPlan__passages,  // fetch(index, &value) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__assign_function__NavigationPlan__passages,  // assign(index, value) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__resize_function__NavigationPlan__passages  // resize(index) function pointer
  },
  {
    "speed_regions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces__msg__NavigationPlan, speed_regions),  // bytes offset in struct
    NULL,  // default value
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__size_function__NavigationPlan__speed_regions,  // size() function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_const_function__NavigationPlan__speed_regions,  // get_const(index) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__get_function__NavigationPlan__speed_regions,  // get(index) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__fetch_function__NavigationPlan__speed_regions,  // fetch(index, &value) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__assign_function__NavigationPlan__speed_regions,  // assign(index, value) function pointer
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__resize_function__NavigationPlan__speed_regions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_members = {
  "nav_interfaces__msg",  // message namespace
  "NavigationPlan",  // message name
  14,  // number of fields
  sizeof(nav_interfaces__msg__NavigationPlan),
  false,  // has_any_key_member_
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_member_array,  // message members
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_init_function,  // function to initialize message memory (memory has to be allocated)
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_type_support_handle = {
  0,
  &nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__NavigationPlan__get_type_hash,
  &nav_interfaces__msg__NavigationPlan__get_type_description,
  &nav_interfaces__msg__NavigationPlan__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, NavigationPlan)() {
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Path)();
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleTraversal)();
  nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_member_array[13].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, HoleSpeedRegion)();
  if (!nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_type_support_handle.typesupport_identifier) {
    nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nav_interfaces__msg__NavigationPlan__rosidl_typesupport_introspection_c__NavigationPlan_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
