// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"
#include "nav_interfaces/msg/detail/hole_traversal__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nav_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HoleTraversal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::msg::HoleTraversal(_init);
}

void HoleTraversal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::msg::HoleTraversal *>(message_memory);
  typed_message->~HoleTraversal();
}

size_t size_function__HoleTraversal__events(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__HoleTraversal__events(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<nav_interfaces::msg::HoleEvent, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__HoleTraversal__events(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<nav_interfaces::msg::HoleEvent, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__HoleTraversal__events(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_interfaces::msg::HoleEvent *>(
    get_const_function__HoleTraversal__events(untyped_member, index));
  auto & value = *reinterpret_cast<nav_interfaces::msg::HoleEvent *>(untyped_value);
  value = item;
}

void assign_function__HoleTraversal__events(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_interfaces::msg::HoleEvent *>(
    get_function__HoleTraversal__events(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_interfaces::msg::HoleEvent *>(untyped_value);
  item = value;
}

size_t size_function__HoleTraversal__straight_segments(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nav_interfaces::msg::HoleStraight> *>(untyped_member);
  return member->size();
}

const void * get_const_function__HoleTraversal__straight_segments(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nav_interfaces::msg::HoleStraight> *>(untyped_member);
  return &member[index];
}

void * get_function__HoleTraversal__straight_segments(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nav_interfaces::msg::HoleStraight> *>(untyped_member);
  return &member[index];
}

void fetch_function__HoleTraversal__straight_segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_interfaces::msg::HoleStraight *>(
    get_const_function__HoleTraversal__straight_segments(untyped_member, index));
  auto & value = *reinterpret_cast<nav_interfaces::msg::HoleStraight *>(untyped_value);
  value = item;
}

void assign_function__HoleTraversal__straight_segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_interfaces::msg::HoleStraight *>(
    get_function__HoleTraversal__straight_segments(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_interfaces::msg::HoleStraight *>(untyped_value);
  item = value;
}

void resize_function__HoleTraversal__straight_segments(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nav_interfaces::msg::HoleStraight> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HoleTraversal_message_member_array[10] = {
  {
    "traversal_uid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, traversal_uid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hole_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, hole_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "entry_edge_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, entry_edge_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "exit_edge_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, exit_edge_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "centerline",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, centerline),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "validated",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, validated),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "requirement_revision",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, requirement_revision),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "events",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::msg::HoleEvent>(),  // members of sub message
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, events),  // bytes offset in struct
    nullptr,  // default value
    size_function__HoleTraversal__events,  // size() function pointer
    get_const_function__HoleTraversal__events,  // get_const(index) function pointer
    get_function__HoleTraversal__events,  // get(index) function pointer
    fetch_function__HoleTraversal__events,  // fetch(index, &value) function pointer
    assign_function__HoleTraversal__events,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "straight_segments",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::msg::HoleStraight>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, straight_segments),  // bytes offset in struct
    nullptr,  // default value
    size_function__HoleTraversal__straight_segments,  // size() function pointer
    get_const_function__HoleTraversal__straight_segments,  // get_const(index) function pointer
    get_function__HoleTraversal__straight_segments,  // get(index) function pointer
    fetch_function__HoleTraversal__straight_segments,  // fetch(index, &value) function pointer
    assign_function__HoleTraversal__straight_segments,  // assign(index, value) function pointer
    resize_function__HoleTraversal__straight_segments  // resize(index) function pointer
  },
  {
    "uphill_entry",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::msg::HoleTraversal, uphill_entry),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HoleTraversal_message_members = {
  "nav_interfaces::msg",  // message namespace
  "HoleTraversal",  // message name
  10,  // number of fields
  sizeof(nav_interfaces::msg::HoleTraversal),
  false,  // has_any_key_member_
  HoleTraversal_message_member_array,  // message members
  HoleTraversal_init_function,  // function to initialize message memory (memory has to be allocated)
  HoleTraversal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HoleTraversal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HoleTraversal_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleTraversal__get_type_hash,
  &nav_interfaces__msg__HoleTraversal__get_type_description,
  &nav_interfaces__msg__HoleTraversal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::msg::HoleTraversal>()
{
  return &::nav_interfaces::msg::rosidl_typesupport_introspection_cpp::HoleTraversal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, msg, HoleTraversal)() {
  return &::nav_interfaces::msg::rosidl_typesupport_introspection_cpp::HoleTraversal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
