// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/gimb_cmd_fram__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robots_msgs/msg/detail/gimb_cmd_fram__functions.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.hpp"

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
  const robots_msgs::msg::GimbCmdFram & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: center_yaw
  cdr << ros_message.center_yaw;

  // Member: armor_pitch
  cdr << ros_message.armor_pitch;

  // Member: armor_yaw
  cdr << ros_message.armor_yaw;

  // Member: spin_flag
  cdr << ros_message.spin_flag;

  // Member: shot_mode
  cdr << ros_message.shot_mode;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs::msg::GimbCmdFram & ros_message)
{
  // Member: center_yaw
  cdr >> ros_message.center_yaw;

  // Member: armor_pitch
  cdr >> ros_message.armor_pitch;

  // Member: armor_yaw
  cdr >> ros_message.armor_yaw;

  // Member: spin_flag
  cdr >> ros_message.spin_flag;

  // Member: shot_mode
  cdr >> ros_message.shot_mode;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size(
  const robots_msgs::msg::GimbCmdFram & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: center_yaw
  {
    size_t item_size = sizeof(ros_message.center_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: armor_pitch
  {
    size_t item_size = sizeof(ros_message.armor_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: armor_yaw
  {
    size_t item_size = sizeof(ros_message.armor_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: spin_flag
  {
    size_t item_size = sizeof(ros_message.spin_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: shot_mode
  {
    size_t item_size = sizeof(ros_message.shot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_GimbCmdFram(
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

  // Member: center_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: armor_pitch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: armor_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: spin_flag
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: shot_mode
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
    using DataType = robots_msgs::msg::GimbCmdFram;
    is_plain =
      (
      offsetof(DataType, shot_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_serialize_key(
  const robots_msgs::msg::GimbCmdFram & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: center_yaw
  cdr << ros_message.center_yaw;

  // Member: armor_pitch
  cdr << ros_message.armor_pitch;

  // Member: armor_yaw
  cdr << ros_message.armor_yaw;

  // Member: spin_flag
  cdr << ros_message.spin_flag;

  // Member: shot_mode
  cdr << ros_message.shot_mode;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size_key(
  const robots_msgs::msg::GimbCmdFram & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: center_yaw
  {
    size_t item_size = sizeof(ros_message.center_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: armor_pitch
  {
    size_t item_size = sizeof(ros_message.armor_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: armor_yaw
  {
    size_t item_size = sizeof(ros_message.armor_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: spin_flag
  {
    size_t item_size = sizeof(ros_message.spin_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: shot_mode
  {
    size_t item_size = sizeof(ros_message.shot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_key_GimbCmdFram(
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

  // Member: center_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: armor_pitch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: armor_yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: spin_flag
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: shot_mode
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
    using DataType = robots_msgs::msg::GimbCmdFram;
    is_plain =
      (
      offsetof(DataType, shot_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _GimbCmdFram__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robots_msgs::msg::GimbCmdFram *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GimbCmdFram__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robots_msgs::msg::GimbCmdFram *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GimbCmdFram__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robots_msgs::msg::GimbCmdFram *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GimbCmdFram__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GimbCmdFram(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GimbCmdFram__callbacks = {
  "robots_msgs::msg",
  "GimbCmdFram",
  _GimbCmdFram__cdr_serialize,
  _GimbCmdFram__cdr_deserialize,
  _GimbCmdFram__get_serialized_size,
  _GimbCmdFram__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GimbCmdFram__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GimbCmdFram__callbacks,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__GimbCmdFram__get_type_hash,
  &robots_msgs__msg__GimbCmdFram__get_type_description,
  &robots_msgs__msg__GimbCmdFram__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robots_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robots_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<robots_msgs::msg::GimbCmdFram>()
{
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_GimbCmdFram__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robots_msgs, msg, GimbCmdFram)() {
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_GimbCmdFram__handle;
}

#ifdef __cplusplus
}
#endif
