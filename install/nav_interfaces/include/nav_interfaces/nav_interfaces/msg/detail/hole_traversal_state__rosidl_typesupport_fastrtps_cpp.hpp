// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "nav_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "nav_interfaces/msg/detail/hole_traversal_state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace nav_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
cdr_serialize(
  const nav_interfaces::msg::HoleTraversalState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces::msg::HoleTraversalState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
get_serialized_size(
  const nav_interfaces::msg::HoleTraversalState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
max_serialized_size_HoleTraversalState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
cdr_serialize_key(
  const nav_interfaces::msg::HoleTraversalState & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
get_serialized_size_key(
  const nav_interfaces::msg::HoleTraversalState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
max_serialized_size_key_HoleTraversalState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace nav_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav_interfaces, msg, HoleTraversalState)();

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
