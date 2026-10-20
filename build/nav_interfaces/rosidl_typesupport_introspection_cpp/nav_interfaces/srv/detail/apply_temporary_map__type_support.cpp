// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
#include "nav_interfaces/srv/detail/apply_temporary_map__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ApplyTemporaryMap_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::srv::ApplyTemporaryMap_Request(_init);
}

void ApplyTemporaryMap_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::srv::ApplyTemporaryMap_Request *>(message_memory);
  typed_message->~ApplyTemporaryMap_Request();
}

size_t size_function__ApplyTemporaryMap_Request__indices(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ApplyTemporaryMap_Request__indices(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__ApplyTemporaryMap_Request__indices(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__ApplyTemporaryMap_Request__indices(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint32_t *>(
    get_const_function__ApplyTemporaryMap_Request__indices(untyped_member, index));
  auto & value = *reinterpret_cast<uint32_t *>(untyped_value);
  value = item;
}

void assign_function__ApplyTemporaryMap_Request__indices(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint32_t *>(
    get_function__ApplyTemporaryMap_Request__indices(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint32_t *>(untyped_value);
  item = value;
}

void resize_function__ApplyTemporaryMap_Request__indices(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ApplyTemporaryMap_Request__values(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ApplyTemporaryMap_Request__values(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__ApplyTemporaryMap_Request__values(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__ApplyTemporaryMap_Request__values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__ApplyTemporaryMap_Request__values(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__ApplyTemporaryMap_Request__values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__ApplyTemporaryMap_Request__values(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

void resize_function__ApplyTemporaryMap_Request__values(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ApplyTemporaryMap_Request_message_member_array[5] = {
  {
    "expected_session_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Request, expected_session_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "expected_source_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Request, expected_source_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "expected_map_revision",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Request, expected_map_revision),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "indices",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Request, indices),  // bytes offset in struct
    nullptr,  // default value
    size_function__ApplyTemporaryMap_Request__indices,  // size() function pointer
    get_const_function__ApplyTemporaryMap_Request__indices,  // get_const(index) function pointer
    get_function__ApplyTemporaryMap_Request__indices,  // get(index) function pointer
    fetch_function__ApplyTemporaryMap_Request__indices,  // fetch(index, &value) function pointer
    assign_function__ApplyTemporaryMap_Request__indices,  // assign(index, value) function pointer
    resize_function__ApplyTemporaryMap_Request__indices  // resize(index) function pointer
  },
  {
    "values",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Request, values),  // bytes offset in struct
    nullptr,  // default value
    size_function__ApplyTemporaryMap_Request__values,  // size() function pointer
    get_const_function__ApplyTemporaryMap_Request__values,  // get_const(index) function pointer
    get_function__ApplyTemporaryMap_Request__values,  // get(index) function pointer
    fetch_function__ApplyTemporaryMap_Request__values,  // fetch(index, &value) function pointer
    assign_function__ApplyTemporaryMap_Request__values,  // assign(index, value) function pointer
    resize_function__ApplyTemporaryMap_Request__values  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ApplyTemporaryMap_Request_message_members = {
  "nav_interfaces::srv",  // message namespace
  "ApplyTemporaryMap_Request",  // message name
  5,  // number of fields
  sizeof(nav_interfaces::srv::ApplyTemporaryMap_Request),
  false,  // has_any_key_member_
  ApplyTemporaryMap_Request_message_member_array,  // message members
  ApplyTemporaryMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ApplyTemporaryMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ApplyTemporaryMap_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ApplyTemporaryMap_Request_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Request>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ApplyTemporaryMap_Request)() {
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ApplyTemporaryMap_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::srv::ApplyTemporaryMap_Response(_init);
}

void ApplyTemporaryMap_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::srv::ApplyTemporaryMap_Response *>(message_memory);
  typed_message->~ApplyTemporaryMap_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ApplyTemporaryMap_Response_message_member_array[4] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "reason",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Response, reason),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "map_revision",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Response, map_revision),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "replanning_triggered",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Response, replanning_triggered),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ApplyTemporaryMap_Response_message_members = {
  "nav_interfaces::srv",  // message namespace
  "ApplyTemporaryMap_Response",  // message name
  4,  // number of fields
  sizeof(nav_interfaces::srv::ApplyTemporaryMap_Response),
  false,  // has_any_key_member_
  ApplyTemporaryMap_Response_message_member_array,  // message members
  ApplyTemporaryMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ApplyTemporaryMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ApplyTemporaryMap_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ApplyTemporaryMap_Response_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Response>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ApplyTemporaryMap_Response)() {
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ApplyTemporaryMap_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::srv::ApplyTemporaryMap_Event(_init);
}

void ApplyTemporaryMap_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::srv::ApplyTemporaryMap_Event *>(message_memory);
  typed_message->~ApplyTemporaryMap_Event();
}

size_t size_function__ApplyTemporaryMap_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nav_interfaces::srv::ApplyTemporaryMap_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ApplyTemporaryMap_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nav_interfaces::srv::ApplyTemporaryMap_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__ApplyTemporaryMap_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nav_interfaces::srv::ApplyTemporaryMap_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__ApplyTemporaryMap_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_interfaces::srv::ApplyTemporaryMap_Request *>(
    get_const_function__ApplyTemporaryMap_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<nav_interfaces::srv::ApplyTemporaryMap_Request *>(untyped_value);
  value = item;
}

void assign_function__ApplyTemporaryMap_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_interfaces::srv::ApplyTemporaryMap_Request *>(
    get_function__ApplyTemporaryMap_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_interfaces::srv::ApplyTemporaryMap_Request *>(untyped_value);
  item = value;
}

void resize_function__ApplyTemporaryMap_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nav_interfaces::srv::ApplyTemporaryMap_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ApplyTemporaryMap_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nav_interfaces::srv::ApplyTemporaryMap_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ApplyTemporaryMap_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nav_interfaces::srv::ApplyTemporaryMap_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__ApplyTemporaryMap_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nav_interfaces::srv::ApplyTemporaryMap_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__ApplyTemporaryMap_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_interfaces::srv::ApplyTemporaryMap_Response *>(
    get_const_function__ApplyTemporaryMap_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<nav_interfaces::srv::ApplyTemporaryMap_Response *>(untyped_value);
  value = item;
}

void assign_function__ApplyTemporaryMap_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_interfaces::srv::ApplyTemporaryMap_Response *>(
    get_function__ApplyTemporaryMap_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_interfaces::srv::ApplyTemporaryMap_Response *>(untyped_value);
  item = value;
}

void resize_function__ApplyTemporaryMap_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nav_interfaces::srv::ApplyTemporaryMap_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ApplyTemporaryMap_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__ApplyTemporaryMap_Event__request,  // size() function pointer
    get_const_function__ApplyTemporaryMap_Event__request,  // get_const(index) function pointer
    get_function__ApplyTemporaryMap_Event__request,  // get(index) function pointer
    fetch_function__ApplyTemporaryMap_Event__request,  // fetch(index, &value) function pointer
    assign_function__ApplyTemporaryMap_Event__request,  // assign(index, value) function pointer
    resize_function__ApplyTemporaryMap_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(nav_interfaces::srv::ApplyTemporaryMap_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__ApplyTemporaryMap_Event__response,  // size() function pointer
    get_const_function__ApplyTemporaryMap_Event__response,  // get_const(index) function pointer
    get_function__ApplyTemporaryMap_Event__response,  // get(index) function pointer
    fetch_function__ApplyTemporaryMap_Event__response,  // fetch(index, &value) function pointer
    assign_function__ApplyTemporaryMap_Event__response,  // assign(index, value) function pointer
    resize_function__ApplyTemporaryMap_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ApplyTemporaryMap_Event_message_members = {
  "nav_interfaces::srv",  // message namespace
  "ApplyTemporaryMap_Event",  // message name
  3,  // number of fields
  sizeof(nav_interfaces::srv::ApplyTemporaryMap_Event),
  false,  // has_any_key_member_
  ApplyTemporaryMap_Event_message_member_array,  // message members
  ApplyTemporaryMap_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ApplyTemporaryMap_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ApplyTemporaryMap_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ApplyTemporaryMap_Event_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Event>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ApplyTemporaryMap_Event)() {
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ApplyTemporaryMap_service_members = {
  "nav_interfaces::srv",  // service namespace
  "ApplyTemporaryMap",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t ApplyTemporaryMap_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ApplyTemporaryMap_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<nav_interfaces::srv::ApplyTemporaryMap>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<nav_interfaces::srv::ApplyTemporaryMap>,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::ApplyTemporaryMap_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::nav_interfaces::srv::ApplyTemporaryMap_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::nav_interfaces::srv::ApplyTemporaryMap_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::nav_interfaces::srv::ApplyTemporaryMap_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ApplyTemporaryMap)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<nav_interfaces::srv::ApplyTemporaryMap>();
}

#ifdef __cplusplus
}
#endif
