// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nav_interfaces:srv/GetTemporaryMap.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
#include "nav_interfaces/srv/detail/get_temporary_map__struct.hpp"
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

void GetTemporaryMap_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::srv::GetTemporaryMap_Request(_init);
}

void GetTemporaryMap_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::srv::GetTemporaryMap_Request *>(message_memory);
  typed_message->~GetTemporaryMap_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetTemporaryMap_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetTemporaryMap_Request_message_members = {
  "nav_interfaces::srv",  // message namespace
  "GetTemporaryMap_Request",  // message name
  1,  // number of fields
  sizeof(nav_interfaces::srv::GetTemporaryMap_Request),
  false,  // has_any_key_member_
  GetTemporaryMap_Request_message_member_array,  // message members
  GetTemporaryMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetTemporaryMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetTemporaryMap_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetTemporaryMap_Request_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__GetTemporaryMap_Request__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap_Request__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Request>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, GetTemporaryMap_Request)() {
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_Request_message_type_support_handle;
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
// #include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__struct.hpp"
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

void GetTemporaryMap_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::srv::GetTemporaryMap_Response(_init);
}

void GetTemporaryMap_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::srv::GetTemporaryMap_Response *>(message_memory);
  typed_message->~GetTemporaryMap_Response();
}

size_t size_function__GetTemporaryMap_Response__indices(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetTemporaryMap_Response__indices(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetTemporaryMap_Response__indices(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetTemporaryMap_Response__indices(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint32_t *>(
    get_const_function__GetTemporaryMap_Response__indices(untyped_member, index));
  auto & value = *reinterpret_cast<uint32_t *>(untyped_value);
  value = item;
}

void assign_function__GetTemporaryMap_Response__indices(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint32_t *>(
    get_function__GetTemporaryMap_Response__indices(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint32_t *>(untyped_value);
  item = value;
}

void resize_function__GetTemporaryMap_Response__indices(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetTemporaryMap_Response__values(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetTemporaryMap_Response__values(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetTemporaryMap_Response__values(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetTemporaryMap_Response__values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__GetTemporaryMap_Response__values(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__GetTemporaryMap_Response__values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__GetTemporaryMap_Response__values(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

void resize_function__GetTemporaryMap_Response__values(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetTemporaryMap_Response_message_member_array[9] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, success),  // bytes offset in struct
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
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, reason),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "map_path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, map_path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "session_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, session_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "source_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, source_id),  // bytes offset in struct
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
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, map_revision),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "source_map",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_msgs::msg::OccupancyGrid>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, source_map),  // bytes offset in struct
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
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, indices),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetTemporaryMap_Response__indices,  // size() function pointer
    get_const_function__GetTemporaryMap_Response__indices,  // get_const(index) function pointer
    get_function__GetTemporaryMap_Response__indices,  // get(index) function pointer
    fetch_function__GetTemporaryMap_Response__indices,  // fetch(index, &value) function pointer
    assign_function__GetTemporaryMap_Response__indices,  // assign(index, value) function pointer
    resize_function__GetTemporaryMap_Response__indices  // resize(index) function pointer
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
    offsetof(nav_interfaces::srv::GetTemporaryMap_Response, values),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetTemporaryMap_Response__values,  // size() function pointer
    get_const_function__GetTemporaryMap_Response__values,  // get_const(index) function pointer
    get_function__GetTemporaryMap_Response__values,  // get(index) function pointer
    fetch_function__GetTemporaryMap_Response__values,  // fetch(index, &value) function pointer
    assign_function__GetTemporaryMap_Response__values,  // assign(index, value) function pointer
    resize_function__GetTemporaryMap_Response__values  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetTemporaryMap_Response_message_members = {
  "nav_interfaces::srv",  // message namespace
  "GetTemporaryMap_Response",  // message name
  9,  // number of fields
  sizeof(nav_interfaces::srv::GetTemporaryMap_Response),
  false,  // has_any_key_member_
  GetTemporaryMap_Response_message_member_array,  // message members
  GetTemporaryMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetTemporaryMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetTemporaryMap_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetTemporaryMap_Response_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__GetTemporaryMap_Response__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap_Response__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Response>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, GetTemporaryMap_Response)() {
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_Response_message_type_support_handle;
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
// #include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__struct.hpp"
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

void GetTemporaryMap_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nav_interfaces::srv::GetTemporaryMap_Event(_init);
}

void GetTemporaryMap_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nav_interfaces::srv::GetTemporaryMap_Event *>(message_memory);
  typed_message->~GetTemporaryMap_Event();
}

size_t size_function__GetTemporaryMap_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nav_interfaces::srv::GetTemporaryMap_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetTemporaryMap_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nav_interfaces::srv::GetTemporaryMap_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__GetTemporaryMap_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nav_interfaces::srv::GetTemporaryMap_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetTemporaryMap_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_interfaces::srv::GetTemporaryMap_Request *>(
    get_const_function__GetTemporaryMap_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<nav_interfaces::srv::GetTemporaryMap_Request *>(untyped_value);
  value = item;
}

void assign_function__GetTemporaryMap_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_interfaces::srv::GetTemporaryMap_Request *>(
    get_function__GetTemporaryMap_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_interfaces::srv::GetTemporaryMap_Request *>(untyped_value);
  item = value;
}

void resize_function__GetTemporaryMap_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nav_interfaces::srv::GetTemporaryMap_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetTemporaryMap_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nav_interfaces::srv::GetTemporaryMap_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetTemporaryMap_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nav_interfaces::srv::GetTemporaryMap_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__GetTemporaryMap_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nav_interfaces::srv::GetTemporaryMap_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetTemporaryMap_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nav_interfaces::srv::GetTemporaryMap_Response *>(
    get_const_function__GetTemporaryMap_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<nav_interfaces::srv::GetTemporaryMap_Response *>(untyped_value);
  value = item;
}

void assign_function__GetTemporaryMap_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nav_interfaces::srv::GetTemporaryMap_Response *>(
    get_function__GetTemporaryMap_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const nav_interfaces::srv::GetTemporaryMap_Response *>(untyped_value);
  item = value;
}

void resize_function__GetTemporaryMap_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nav_interfaces::srv::GetTemporaryMap_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetTemporaryMap_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetTemporaryMap_Event__request,  // size() function pointer
    get_const_function__GetTemporaryMap_Event__request,  // get_const(index) function pointer
    get_function__GetTemporaryMap_Event__request,  // get(index) function pointer
    fetch_function__GetTemporaryMap_Event__request,  // fetch(index, &value) function pointer
    assign_function__GetTemporaryMap_Event__request,  // assign(index, value) function pointer
    resize_function__GetTemporaryMap_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(nav_interfaces::srv::GetTemporaryMap_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetTemporaryMap_Event__response,  // size() function pointer
    get_const_function__GetTemporaryMap_Event__response,  // get_const(index) function pointer
    get_function__GetTemporaryMap_Event__response,  // get(index) function pointer
    fetch_function__GetTemporaryMap_Event__response,  // fetch(index, &value) function pointer
    assign_function__GetTemporaryMap_Event__response,  // assign(index, value) function pointer
    resize_function__GetTemporaryMap_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetTemporaryMap_Event_message_members = {
  "nav_interfaces::srv",  // message namespace
  "GetTemporaryMap_Event",  // message name
  3,  // number of fields
  sizeof(nav_interfaces::srv::GetTemporaryMap_Event),
  false,  // has_any_key_member_
  GetTemporaryMap_Event_message_member_array,  // message members
  GetTemporaryMap_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  GetTemporaryMap_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetTemporaryMap_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetTemporaryMap_Event_message_members,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__GetTemporaryMap_Event__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap_Event__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Event>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, GetTemporaryMap_Event)() {
  return &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_Event_message_type_support_handle;
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
// #include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__struct.hpp"
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
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetTemporaryMap_service_members = {
  "nav_interfaces::srv",  // service namespace
  "GetTemporaryMap",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<nav_interfaces::srv::GetTemporaryMap>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t GetTemporaryMap_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetTemporaryMap_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_interfaces::srv::GetTemporaryMap_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<nav_interfaces::srv::GetTemporaryMap>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<nav_interfaces::srv::GetTemporaryMap>,
  &nav_interfaces__srv__GetTemporaryMap__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace nav_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<nav_interfaces::srv::GetTemporaryMap>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::nav_interfaces::srv::rosidl_typesupport_introspection_cpp::GetTemporaryMap_service_type_support_handle;
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
        ::nav_interfaces::srv::GetTemporaryMap_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::nav_interfaces::srv::GetTemporaryMap_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::nav_interfaces::srv::GetTemporaryMap_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, GetTemporaryMap)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<nav_interfaces::srv::GetTemporaryMap>();
}

#ifdef __cplusplus
}
#endif
