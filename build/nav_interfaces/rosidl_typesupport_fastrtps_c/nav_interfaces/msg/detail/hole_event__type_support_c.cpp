// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from nav_interfaces:msg/HoleEvent.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_event__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nav_interfaces/msg/detail/hole_event__struct.h"
#include "nav_interfaces/msg/detail/hole_event__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point__functions.h"  // point

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
bool cdr_serialize_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
bool cdr_deserialize_geometry_msgs__msg__Point(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Point * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
bool cdr_serialize_key_geometry_msgs__msg__Point(
  const geometry_msgs__msg__Point * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t get_serialized_size_key_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t max_serialized_size_key_geometry_msgs__msg__Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();


using _HoleEvent__ros_msg_type = nav_interfaces__msg__HoleEvent;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_nav_interfaces__msg__HoleEvent(
  const nav_interfaces__msg__HoleEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: range_status
  {
    cdr << ros_message->range_status;
  }

  // Field name: s_path
  {
    cdr << ros_message->s_path;
  }

  // Field name: point
  {
    cdr_serialize_geometry_msgs__msg__Point(
      &ros_message->point, cdr);
  }

  // Field name: point_valid
  {
    cdr << (ros_message->point_valid ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_deserialize_nav_interfaces__msg__HoleEvent(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__msg__HoleEvent * ros_message)
{
  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: range_status
  {
    cdr >> ros_message->range_status;
  }

  // Field name: s_path
  {
    cdr >> ros_message->s_path;
  }

  // Field name: point
  {
    cdr_deserialize_geometry_msgs__msg__Point(cdr, &ros_message->point);
  }

  // Field name: point_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->point_valid = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_nav_interfaces__msg__HoleEvent(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HoleEvent__ros_msg_type * ros_message = static_cast<const _HoleEvent__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: range_status
  {
    size_t item_size = sizeof(ros_message->range_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: s_path
  {
    size_t item_size = sizeof(ros_message->s_path);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: point
  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->point), current_alignment);

  // Field name: point_valid
  {
    size_t item_size = sizeof(ros_message->point_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_nav_interfaces__msg__HoleEvent(
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

  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: range_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: s_path
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: point_valid
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
    using DataType = nav_interfaces__msg__HoleEvent;
    is_plain =
      (
      offsetof(DataType, point_valid) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_key_nav_interfaces__msg__HoleEvent(
  const nav_interfaces__msg__HoleEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: range_status
  {
    cdr << ros_message->range_status;
  }

  // Field name: s_path
  {
    cdr << ros_message->s_path;
  }

  // Field name: point
  {
    cdr_serialize_key_geometry_msgs__msg__Point(
      &ros_message->point, cdr);
  }

  // Field name: point_valid
  {
    cdr << (ros_message->point_valid ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_key_nav_interfaces__msg__HoleEvent(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HoleEvent__ros_msg_type * ros_message = static_cast<const _HoleEvent__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: range_status
  {
    size_t item_size = sizeof(ros_message->range_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: s_path
  {
    size_t item_size = sizeof(ros_message->s_path);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: point
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Point(
    &(ros_message->point), current_alignment);

  // Field name: point_valid
  {
    size_t item_size = sizeof(ros_message->point_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_key_nav_interfaces__msg__HoleEvent(
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
  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: range_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: s_path
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: point_valid
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
    using DataType = nav_interfaces__msg__HoleEvent;
    is_plain =
      (
      offsetof(DataType, point_valid) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _HoleEvent__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const nav_interfaces__msg__HoleEvent * ros_message = static_cast<const nav_interfaces__msg__HoleEvent *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_nav_interfaces__msg__HoleEvent(ros_message, cdr);
}

static bool _HoleEvent__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  nav_interfaces__msg__HoleEvent * ros_message = static_cast<nav_interfaces__msg__HoleEvent *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_nav_interfaces__msg__HoleEvent(cdr, ros_message);
}

static uint32_t _HoleEvent__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nav_interfaces__msg__HoleEvent(
      untyped_ros_message, 0));
}

static size_t _HoleEvent__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nav_interfaces__msg__HoleEvent(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HoleEvent = {
  "nav_interfaces::msg",
  "HoleEvent",
  _HoleEvent__cdr_serialize,
  _HoleEvent__cdr_deserialize,
  _HoleEvent__get_serialized_size,
  _HoleEvent__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _HoleEvent__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HoleEvent,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleEvent__get_type_hash,
  &nav_interfaces__msg__HoleEvent__get_type_description,
  &nav_interfaces__msg__HoleEvent__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, msg, HoleEvent)() {
  return &_HoleEvent__type_support;
}

#if defined(__cplusplus)
}
#endif
