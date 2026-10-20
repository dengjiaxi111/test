// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/mode_cmd__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robots_msgs/msg/detail/mode_cmd__functions.h"
#include "robots_msgs/msg/detail/mode_cmd__struct.hpp"

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
  const robots_msgs::msg::ModeCmd & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: should_chassis_spin
  cdr << ros_message.should_chassis_spin;

  // Member: should_gimbal_patrol
  cdr << ros_message.should_gimbal_patrol;

  // Member: buy_bullet
  cdr << ros_message.buy_bullet;

  // Member: rebirth
  cdr << ros_message.rebirth;

  // Member: use_capacity
  cdr << ros_message.use_capacity;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs::msg::ModeCmd & ros_message)
{
  // Member: should_chassis_spin
  cdr >> ros_message.should_chassis_spin;

  // Member: should_gimbal_patrol
  cdr >> ros_message.should_gimbal_patrol;

  // Member: buy_bullet
  cdr >> ros_message.buy_bullet;

  // Member: rebirth
  cdr >> ros_message.rebirth;

  // Member: use_capacity
  cdr >> ros_message.use_capacity;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size(
  const robots_msgs::msg::ModeCmd & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: should_chassis_spin
  {
    size_t item_size = sizeof(ros_message.should_chassis_spin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: should_gimbal_patrol
  {
    size_t item_size = sizeof(ros_message.should_gimbal_patrol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: buy_bullet
  {
    size_t item_size = sizeof(ros_message.buy_bullet);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rebirth
  {
    size_t item_size = sizeof(ros_message.rebirth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: use_capacity
  {
    size_t item_size = sizeof(ros_message.use_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_ModeCmd(
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

  // Member: should_chassis_spin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: should_gimbal_patrol
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: buy_bullet
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rebirth
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: use_capacity
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
    using DataType = robots_msgs::msg::ModeCmd;
    is_plain =
      (
      offsetof(DataType, use_capacity) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_serialize_key(
  const robots_msgs::msg::ModeCmd & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: should_chassis_spin
  cdr << ros_message.should_chassis_spin;

  // Member: should_gimbal_patrol
  cdr << ros_message.should_gimbal_patrol;

  // Member: buy_bullet
  cdr << ros_message.buy_bullet;

  // Member: rebirth
  cdr << ros_message.rebirth;

  // Member: use_capacity
  cdr << ros_message.use_capacity;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size_key(
  const robots_msgs::msg::ModeCmd & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: should_chassis_spin
  {
    size_t item_size = sizeof(ros_message.should_chassis_spin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: should_gimbal_patrol
  {
    size_t item_size = sizeof(ros_message.should_gimbal_patrol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: buy_bullet
  {
    size_t item_size = sizeof(ros_message.buy_bullet);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rebirth
  {
    size_t item_size = sizeof(ros_message.rebirth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: use_capacity
  {
    size_t item_size = sizeof(ros_message.use_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_key_ModeCmd(
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

  // Member: should_chassis_spin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: should_gimbal_patrol
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: buy_bullet
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rebirth
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: use_capacity
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
    using DataType = robots_msgs::msg::ModeCmd;
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
  auto typed_message =
    static_cast<const robots_msgs::msg::ModeCmd *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ModeCmd__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robots_msgs::msg::ModeCmd *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ModeCmd__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robots_msgs::msg::ModeCmd *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ModeCmd__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ModeCmd(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ModeCmd__callbacks = {
  "robots_msgs::msg",
  "ModeCmd",
  _ModeCmd__cdr_serialize,
  _ModeCmd__cdr_deserialize,
  _ModeCmd__get_serialized_size,
  _ModeCmd__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ModeCmd__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ModeCmd__callbacks,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__ModeCmd__get_type_hash,
  &robots_msgs__msg__ModeCmd__get_type_description,
  &robots_msgs__msg__ModeCmd__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robots_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robots_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<robots_msgs::msg::ModeCmd>()
{
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_ModeCmd__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robots_msgs, msg, ModeCmd)() {
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_ModeCmd__handle;
}

#ifdef __cplusplus
}
#endif
