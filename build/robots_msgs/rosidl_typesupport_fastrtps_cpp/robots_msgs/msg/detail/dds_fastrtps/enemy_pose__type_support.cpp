// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/enemy_pose__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robots_msgs/msg/detail/enemy_pose__functions.h"
#include "robots_msgs/msg/detail/enemy_pose__struct.hpp"

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

namespace robots_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_serialize(
  const robots_msgs::msg::EnemyPose & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enemy_dist
  cdr << ros_message.enemy_dist;

  // Member: enemy_ori
  cdr << ros_message.enemy_ori;

  // Member: enemy_num
  cdr << ros_message.enemy_num;

  // Member: enemy_x
  cdr << ros_message.enemy_x;

  // Member: enemy_y
  cdr << ros_message.enemy_y;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs::msg::EnemyPose & ros_message)
{
  // Member: enemy_dist
  cdr >> ros_message.enemy_dist;

  // Member: enemy_ori
  cdr >> ros_message.enemy_ori;

  // Member: enemy_num
  cdr >> ros_message.enemy_num;

  // Member: enemy_x
  cdr >> ros_message.enemy_x;

  // Member: enemy_y
  cdr >> ros_message.enemy_y;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size(
  const robots_msgs::msg::EnemyPose & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enemy_dist
  {
    size_t item_size = sizeof(ros_message.enemy_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_ori
  {
    size_t item_size = sizeof(ros_message.enemy_ori);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_num
  {
    size_t item_size = sizeof(ros_message.enemy_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_x
  {
    size_t item_size = sizeof(ros_message.enemy_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_y
  {
    size_t item_size = sizeof(ros_message.enemy_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_EnemyPose(
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

  // Member: enemy_dist
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: enemy_ori
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: enemy_num
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: enemy_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: enemy_y
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
    using DataType = robots_msgs::msg::EnemyPose;
    is_plain =
      (
      offsetof(DataType, enemy_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_serialize_key(
  const robots_msgs::msg::EnemyPose & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: enemy_dist
  cdr << ros_message.enemy_dist;

  // Member: enemy_ori
  cdr << ros_message.enemy_ori;

  // Member: enemy_num
  cdr << ros_message.enemy_num;

  // Member: enemy_x
  cdr << ros_message.enemy_x;

  // Member: enemy_y
  cdr << ros_message.enemy_y;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size_key(
  const robots_msgs::msg::EnemyPose & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: enemy_dist
  {
    size_t item_size = sizeof(ros_message.enemy_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_ori
  {
    size_t item_size = sizeof(ros_message.enemy_ori);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_num
  {
    size_t item_size = sizeof(ros_message.enemy_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_x
  {
    size_t item_size = sizeof(ros_message.enemy_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_y
  {
    size_t item_size = sizeof(ros_message.enemy_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_key_EnemyPose(
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

  // Member: enemy_dist
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: enemy_ori
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: enemy_num
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enemy_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: enemy_y
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
    using DataType = robots_msgs::msg::EnemyPose;
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
  auto typed_message =
    static_cast<const robots_msgs::msg::EnemyPose *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _EnemyPose__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robots_msgs::msg::EnemyPose *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _EnemyPose__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robots_msgs::msg::EnemyPose *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _EnemyPose__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_EnemyPose(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _EnemyPose__callbacks = {
  "robots_msgs::msg",
  "EnemyPose",
  _EnemyPose__cdr_serialize,
  _EnemyPose__cdr_deserialize,
  _EnemyPose__get_serialized_size,
  _EnemyPose__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _EnemyPose__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_EnemyPose__callbacks,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__EnemyPose__get_type_hash,
  &robots_msgs__msg__EnemyPose__get_type_description,
  &robots_msgs__msg__EnemyPose__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robots_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robots_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<robots_msgs::msg::EnemyPose>()
{
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_EnemyPose__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robots_msgs, msg, EnemyPose)() {
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_EnemyPose__handle;
}

#ifdef __cplusplus
}
#endif
