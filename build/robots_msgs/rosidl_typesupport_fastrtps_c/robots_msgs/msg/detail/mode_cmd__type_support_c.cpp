// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/mode_cmd__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/mode_cmd__struct.h"
#include "robots_msgs/msg/detail/mode_cmd__functions.h"
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


using _ModeCmd__ros_msg_type = robots_msgs__msg__ModeCmd;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__ModeCmd(
  const robots_msgs__msg__ModeCmd * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: should_chassis_spin
  {
    cdr << ros_message->should_chassis_spin;
  }

  // Field name: should_gimbal_patrol
  {
    cdr << ros_message->should_gimbal_patrol;
  }

  // Field name: buy_bullet
  {
    cdr << ros_message->buy_bullet;
  }

  // Field name: rebirth
  {
    cdr << ros_message->rebirth;
  }

  // Field name: use_capacity
  {
    cdr << ros_message->use_capacity;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__ModeCmd(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs__msg__ModeCmd * ros_message)
{
  // Field name: should_chassis_spin
  {
    cdr >> ros_message->should_chassis_spin;
  }

  // Field name: should_gimbal_patrol
  {
    cdr >> ros_message->should_gimbal_patrol;
  }

  // Field name: buy_bullet
  {
    cdr >> ros_message->buy_bullet;
  }

  // Field name: rebirth
  {
    cdr >> ros_message->rebirth;
  }

  // Field name: use_capacity
  {
    cdr >> ros_message->use_capacity;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__ModeCmd(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ModeCmd__ros_msg_type * ros_message = static_cast<const _ModeCmd__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: should_chassis_spin
  {
    size_t item_size = sizeof(ros_message->should_chassis_spin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: should_gimbal_patrol
  {
    size_t item_size = sizeof(ros_message->should_gimbal_patrol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: buy_bullet
  {
    size_t item_size = sizeof(ros_message->buy_bullet);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rebirth
  {
    size_t item_size = sizeof(ros_message->rebirth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: use_capacity
  {
    size_t item_size = sizeof(ros_message->use_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__ModeCmd(
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

  // Field name: should_chassis_spin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: should_gimbal_patrol
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: buy_bullet
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: rebirth
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: use_capacity
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
    using DataType = robots_msgs__msg__ModeCmd;
    is_plain =
      (
      offsetof(DataType, use_capacity) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__ModeCmd(
  const robots_msgs__msg__ModeCmd * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: should_chassis_spin
  {
    cdr << ros_message->should_chassis_spin;
  }

  // Field name: should_gimbal_patrol
  {
    cdr << ros_message->should_gimbal_patrol;
  }

  // Field name: buy_bullet
  {
    cdr << ros_message->buy_bullet;
  }

  // Field name: rebirth
  {
    cdr << ros_message->rebirth;
  }

  // Field name: use_capacity
  {
    cdr << ros_message->use_capacity;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__ModeCmd(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ModeCmd__ros_msg_type * ros_message = static_cast<const _ModeCmd__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: should_chassis_spin
  {
    size_t item_size = sizeof(ros_message->should_chassis_spin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: should_gimbal_patrol
  {
    size_t item_size = sizeof(ros_message->should_gimbal_patrol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: buy_bullet
  {
    size_t item_size = sizeof(ros_message->buy_bullet);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rebirth
  {
    size_t item_size = sizeof(ros_message->rebirth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: use_capacity
  {
    size_t item_size = sizeof(ros_message->use_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__ModeCmd(
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
  // Field name: should_chassis_spin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: should_gimbal_patrol
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: buy_bullet
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: rebirth
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: use_capacity
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
    using DataType = robots_msgs__msg__ModeCmd;
    is_plain =
      (
      offsetof(DataType, use_capacity) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ModeCmd__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robots_msgs__msg__ModeCmd * ros_message = static_cast<const robots_msgs__msg__ModeCmd *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robots_msgs__msg__ModeCmd(ros_message, cdr);
}

static bool _ModeCmd__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robots_msgs__msg__ModeCmd * ros_message = static_cast<robots_msgs__msg__ModeCmd *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robots_msgs__msg__ModeCmd(cdr, ros_message);
}

static uint32_t _ModeCmd__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robots_msgs__msg__ModeCmd(
      untyped_ros_message, 0));
}

static size_t _ModeCmd__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robots_msgs__msg__ModeCmd(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ModeCmd = {
  "robots_msgs::msg",
  "ModeCmd",
  _ModeCmd__cdr_serialize,
  _ModeCmd__cdr_deserialize,
  _ModeCmd__get_serialized_size,
  _ModeCmd__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ModeCmd__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ModeCmd,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__ModeCmd__get_type_hash,
  &robots_msgs__msg__ModeCmd__get_type_description,
  &robots_msgs__msg__ModeCmd__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, ModeCmd)() {
  return &_ModeCmd__type_support;
}

#if defined(__cplusplus)
}
#endif
