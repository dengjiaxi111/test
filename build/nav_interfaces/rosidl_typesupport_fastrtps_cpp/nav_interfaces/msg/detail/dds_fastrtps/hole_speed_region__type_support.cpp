// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_speed_region__rosidl_typesupport_fastrtps_cpp.hpp"
#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"
#include "nav_interfaces/msg/detail/hole_speed_region__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace nav_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
cdr_serialize(
  const nav_interfaces::msg::HoleSpeedRegion & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: s_begin
  cdr << ros_message.s_begin;

  // Member: s_end
  cdr << ros_message.s_end;

  // Member: speed_limit
  cdr << ros_message.speed_limit;

  // Member: kind
  cdr << ros_message.kind;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces::msg::HoleSpeedRegion & ros_message)
{
  // Member: s_begin
  cdr >> ros_message.s_begin;

  // Member: s_end
  cdr >> ros_message.s_end;

  // Member: speed_limit
  cdr >> ros_message.speed_limit;

  // Member: kind
  cdr >> ros_message.kind;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
get_serialized_size(
  const nav_interfaces::msg::HoleSpeedRegion & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: s_begin
  {
    size_t item_size = sizeof(ros_message.s_begin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: s_end
  {
    size_t item_size = sizeof(ros_message.s_end);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_limit
  {
    size_t item_size = sizeof(ros_message.speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: kind
  {
    size_t item_size = sizeof(ros_message.kind);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
max_serialized_size_HoleSpeedRegion(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: s_begin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: s_end
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: speed_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: kind
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = nav_interfaces::msg::HoleSpeedRegion;
    is_plain =
      (
      offsetof(DataType, kind) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
cdr_serialize_key(
  const nav_interfaces::msg::HoleSpeedRegion & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: s_begin
  cdr << ros_message.s_begin;

  // Member: s_end
  cdr << ros_message.s_end;

  // Member: speed_limit
  cdr << ros_message.speed_limit;

  // Member: kind
  cdr << ros_message.kind;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
get_serialized_size_key(
  const nav_interfaces::msg::HoleSpeedRegion & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: s_begin
  {
    size_t item_size = sizeof(ros_message.s_begin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: s_end
  {
    size_t item_size = sizeof(ros_message.s_end);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_limit
  {
    size_t item_size = sizeof(ros_message.speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: kind
  {
    size_t item_size = sizeof(ros_message.kind);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav_interfaces
max_serialized_size_key_HoleSpeedRegion(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: s_begin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: s_end
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: speed_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: kind
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = nav_interfaces::msg::HoleSpeedRegion;
    is_plain =
      (
      offsetof(DataType, kind) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _HoleSpeedRegion__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const nav_interfaces::msg::HoleSpeedRegion *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HoleSpeedRegion__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nav_interfaces::msg::HoleSpeedRegion *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HoleSpeedRegion__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nav_interfaces::msg::HoleSpeedRegion *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HoleSpeedRegion__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HoleSpeedRegion(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HoleSpeedRegion__callbacks = {
  "nav_interfaces::msg",
  "HoleSpeedRegion",
  _HoleSpeedRegion__cdr_serialize,
  _HoleSpeedRegion__cdr_deserialize,
  _HoleSpeedRegion__get_serialized_size,
  _HoleSpeedRegion__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _HoleSpeedRegion__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HoleSpeedRegion__callbacks,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleSpeedRegion__get_type_hash,
  &nav_interfaces__msg__HoleSpeedRegion__get_type_description,
  &nav_interfaces__msg__HoleSpeedRegion__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace nav_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nav_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::msg::HoleSpeedRegion>()
{
  return &nav_interfaces::msg::typesupport_fastrtps_cpp::_HoleSpeedRegion__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav_interfaces, msg, HoleSpeedRegion)() {
  return &nav_interfaces::msg::typesupport_fastrtps_cpp::_HoleSpeedRegion__handle;
}

#ifdef __cplusplus
}
#endif
