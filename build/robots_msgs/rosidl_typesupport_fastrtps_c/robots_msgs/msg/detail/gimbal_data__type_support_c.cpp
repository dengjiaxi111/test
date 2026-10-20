// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/gimbal_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/gimbal_data__struct.h"
#include "robots_msgs/msg/detail/gimbal_data__functions.h"
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


// forward declare type support functions


using _GimbalData__ros_msg_type = robots_msgs__msg__GimbalData;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__GimbalData(
  const robots_msgs__msg__GimbalData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gimbal_yaw
  {
    cdr << ros_message->gimbal_yaw;
  }

  // Field name: gimbal_pitch
  {
    cdr << ros_message->gimbal_pitch;
  }

  // Field name: yaw_va
  {
    cdr << ros_message->yaw_va;
  }

  // Field name: base_yaw
  {
    cdr << ros_message->base_yaw;
  }

  // Field name: self_team
  {
    cdr << ros_message->self_team;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__GimbalData(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs__msg__GimbalData * ros_message)
{
  // Field name: gimbal_yaw
  {
    cdr >> ros_message->gimbal_yaw;
  }

  // Field name: gimbal_pitch
  {
    cdr >> ros_message->gimbal_pitch;
  }

  // Field name: yaw_va
  {
    cdr >> ros_message->yaw_va;
  }

  // Field name: base_yaw
  {
    cdr >> ros_message->base_yaw;
  }

  // Field name: self_team
  {
    cdr >> ros_message->self_team;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__GimbalData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GimbalData__ros_msg_type * ros_message = static_cast<const _GimbalData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gimbal_yaw
  {
    size_t item_size = sizeof(ros_message->gimbal_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gimbal_pitch
  {
    size_t item_size = sizeof(ros_message->gimbal_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw_va
  {
    size_t item_size = sizeof(ros_message->yaw_va);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: base_yaw
  {
    size_t item_size = sizeof(ros_message->base_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: self_team
  {
    size_t item_size = sizeof(ros_message->self_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__GimbalData(
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

  // Field name: gimbal_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gimbal_pitch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw_va
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: base_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: self_team
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
    using DataType = robots_msgs__msg__GimbalData;
    is_plain =
      (
      offsetof(DataType, self_team) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__GimbalData(
  const robots_msgs__msg__GimbalData * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gimbal_yaw
  {
    cdr << ros_message->gimbal_yaw;
  }

  // Field name: gimbal_pitch
  {
    cdr << ros_message->gimbal_pitch;
  }

  // Field name: yaw_va
  {
    cdr << ros_message->yaw_va;
  }

  // Field name: base_yaw
  {
    cdr << ros_message->base_yaw;
  }

  // Field name: self_team
  {
    cdr << ros_message->self_team;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__GimbalData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GimbalData__ros_msg_type * ros_message = static_cast<const _GimbalData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gimbal_yaw
  {
    size_t item_size = sizeof(ros_message->gimbal_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gimbal_pitch
  {
    size_t item_size = sizeof(ros_message->gimbal_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw_va
  {
    size_t item_size = sizeof(ros_message->yaw_va);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: base_yaw
  {
    size_t item_size = sizeof(ros_message->base_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: self_team
  {
    size_t item_size = sizeof(ros_message->self_team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__GimbalData(
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
  // Field name: gimbal_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gimbal_pitch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw_va
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: base_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: self_team
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
    using DataType = robots_msgs__msg__GimbalData;
    is_plain =
      (
      offsetof(DataType, self_team) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GimbalData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robots_msgs__msg__GimbalData * ros_message = static_cast<const robots_msgs__msg__GimbalData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robots_msgs__msg__GimbalData(ros_message, cdr);
}

static bool _GimbalData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robots_msgs__msg__GimbalData * ros_message = static_cast<robots_msgs__msg__GimbalData *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robots_msgs__msg__GimbalData(cdr, ros_message);
}

static uint32_t _GimbalData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robots_msgs__msg__GimbalData(
      untyped_ros_message, 0));
}

static size_t _GimbalData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robots_msgs__msg__GimbalData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GimbalData = {
  "robots_msgs::msg",
  "GimbalData",
  _GimbalData__cdr_serialize,
  _GimbalData__cdr_deserialize,
  _GimbalData__get_serialized_size,
  _GimbalData__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GimbalData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GimbalData,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__GimbalData__get_type_hash,
  &robots_msgs__msg__GimbalData__get_type_description,
  &robots_msgs__msg__GimbalData__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, GimbalData)() {
  return &_GimbalData__type_support;
}

#if defined(__cplusplus)
}
#endif
