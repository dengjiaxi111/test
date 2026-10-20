// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/enemy_pose__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/enemy_pose__struct.h"
#include "robots_msgs/msg/detail/enemy_pose__functions.h"
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


using _EnemyPose__ros_msg_type = robots_msgs__msg__EnemyPose;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__EnemyPose(
  const robots_msgs__msg__EnemyPose * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: enemy_dist
  {
    cdr << ros_message->enemy_dist;
  }

  // Field name: enemy_ori
  {
    cdr << ros_message->enemy_ori;
  }

  // Field name: enemy_num
  {
    cdr << ros_message->enemy_num;
  }

  // Field name: enemy_x
  {
    cdr << ros_message->enemy_x;
  }

  // Field name: enemy_y
  {
    cdr << ros_message->enemy_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__EnemyPose(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs__msg__EnemyPose * ros_message)
{
  // Field name: enemy_dist
  {
    cdr >> ros_message->enemy_dist;
  }

  // Field name: enemy_ori
  {
    cdr >> ros_message->enemy_ori;
  }

  // Field name: enemy_num
  {
    cdr >> ros_message->enemy_num;
  }

  // Field name: enemy_x
  {
    cdr >> ros_message->enemy_x;
  }

  // Field name: enemy_y
  {
    cdr >> ros_message->enemy_y;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__EnemyPose(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EnemyPose__ros_msg_type * ros_message = static_cast<const _EnemyPose__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: enemy_dist
  {
    size_t item_size = sizeof(ros_message->enemy_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_ori
  {
    size_t item_size = sizeof(ros_message->enemy_ori);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_num
  {
    size_t item_size = sizeof(ros_message->enemy_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_x
  {
    size_t item_size = sizeof(ros_message->enemy_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_y
  {
    size_t item_size = sizeof(ros_message->enemy_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__EnemyPose(
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

  // Field name: enemy_dist
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_ori
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_num
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: enemy_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robots_msgs__msg__EnemyPose;
    is_plain =
      (
      offsetof(DataType, enemy_y) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__EnemyPose(
  const robots_msgs__msg__EnemyPose * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: enemy_dist
  {
    cdr << ros_message->enemy_dist;
  }

  // Field name: enemy_ori
  {
    cdr << ros_message->enemy_ori;
  }

  // Field name: enemy_num
  {
    cdr << ros_message->enemy_num;
  }

  // Field name: enemy_x
  {
    cdr << ros_message->enemy_x;
  }

  // Field name: enemy_y
  {
    cdr << ros_message->enemy_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__EnemyPose(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EnemyPose__ros_msg_type * ros_message = static_cast<const _EnemyPose__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: enemy_dist
  {
    size_t item_size = sizeof(ros_message->enemy_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_ori
  {
    size_t item_size = sizeof(ros_message->enemy_ori);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_num
  {
    size_t item_size = sizeof(ros_message->enemy_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_x
  {
    size_t item_size = sizeof(ros_message->enemy_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_y
  {
    size_t item_size = sizeof(ros_message->enemy_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__EnemyPose(
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
  // Field name: enemy_dist
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_ori
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_num
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: enemy_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robots_msgs__msg__EnemyPose;
    is_plain =
      (
      offsetof(DataType, enemy_y) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _EnemyPose__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robots_msgs__msg__EnemyPose * ros_message = static_cast<const robots_msgs__msg__EnemyPose *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robots_msgs__msg__EnemyPose(ros_message, cdr);
}

static bool _EnemyPose__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robots_msgs__msg__EnemyPose * ros_message = static_cast<robots_msgs__msg__EnemyPose *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robots_msgs__msg__EnemyPose(cdr, ros_message);
}

static uint32_t _EnemyPose__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robots_msgs__msg__EnemyPose(
      untyped_ros_message, 0));
}

static size_t _EnemyPose__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robots_msgs__msg__EnemyPose(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_EnemyPose = {
  "robots_msgs::msg",
  "EnemyPose",
  _EnemyPose__cdr_serialize,
  _EnemyPose__cdr_deserialize,
  _EnemyPose__get_serialized_size,
  _EnemyPose__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _EnemyPose__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EnemyPose,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__EnemyPose__get_type_hash,
  &robots_msgs__msg__EnemyPose__get_type_description,
  &robots_msgs__msg__EnemyPose__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, EnemyPose)() {
  return &_EnemyPose__type_support;
}

#if defined(__cplusplus)
}
#endif
