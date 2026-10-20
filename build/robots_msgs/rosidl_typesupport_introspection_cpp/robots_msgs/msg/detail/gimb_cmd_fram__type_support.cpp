// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__functions.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robots_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GimbCmdFram_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robots_msgs::msg::GimbCmdFram(_init);
}

void GimbCmdFram_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robots_msgs::msg::GimbCmdFram *>(message_memory);
  typed_message->~GimbCmdFram();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GimbCmdFram_message_member_array[5] = {
  {
    "center_yaw",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs::msg::GimbCmdFram, center_yaw),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "armor_pitch",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs::msg::GimbCmdFram, armor_pitch),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "armor_yaw",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs::msg::GimbCmdFram, armor_yaw),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "spin_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs::msg::GimbCmdFram, spin_flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "shot_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robots_msgs::msg::GimbCmdFram, shot_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GimbCmdFram_message_members = {
  "robots_msgs::msg",  // message namespace
  "GimbCmdFram",  // message name
  5,  // number of fields
  sizeof(robots_msgs::msg::GimbCmdFram),
  false,  // has_any_key_member_
  GimbCmdFram_message_member_array,  // message members
  GimbCmdFram_init_function,  // function to initialize message memory (memory has to be allocated)
  GimbCmdFram_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GimbCmdFram_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GimbCmdFram_message_members,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__GimbCmdFram__get_type_hash,
  &robots_msgs__msg__GimbCmdFram__get_type_description,
  &robots_msgs__msg__GimbCmdFram__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace robots_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robots_msgs::msg::GimbCmdFram>()
{
  return &::robots_msgs::msg::rosidl_typesupport_introspection_cpp::GimbCmdFram_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robots_msgs, msg, GimbCmdFram)() {
  return &::robots_msgs::msg::rosidl_typesupport_introspection_cpp::GimbCmdFram_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
