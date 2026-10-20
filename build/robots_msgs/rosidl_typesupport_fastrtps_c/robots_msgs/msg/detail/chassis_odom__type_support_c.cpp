// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/chassis_odom__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/chassis_odom__struct.h"
#include "robots_msgs/msg/detail/chassis_odom__functions.h"
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


using _ChassisOdom__ros_msg_type = robots_msgs__msg__ChassisOdom;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__ChassisOdom(
  const robots_msgs__msg__ChassisOdom * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: speed_x
  {
    cdr << ros_message->speed_x;
  }

  // Field name: speed_y
  {
    cdr << ros_message->speed_y;
  }

  // Field name: speed_w
  {
    cdr << ros_message->speed_w;
  }

  // Field name: gimbal_angle
  {
    cdr << ros_message->gimbal_angle;
  }

  // Field name: capacitor_voltage
  {
    cdr << ros_message->capacitor_voltage;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__ChassisOdom(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs__msg__ChassisOdom * ros_message)
{
  // Field name: speed_x
  {
    cdr >> ros_message->speed_x;
  }

  // Field name: speed_y
  {
    cdr >> ros_message->speed_y;
  }

  // Field name: speed_w
  {
    cdr >> ros_message->speed_w;
  }

  // Field name: gimbal_angle
  {
    cdr >> ros_message->gimbal_angle;
  }

  // Field name: capacitor_voltage
  {
    cdr >> ros_message->capacitor_voltage;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__ChassisOdom(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ChassisOdom__ros_msg_type * ros_message = static_cast<const _ChassisOdom__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: speed_x
  {
    size_t item_size = sizeof(ros_message->speed_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_y
  {
    size_t item_size = sizeof(ros_message->speed_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_w
  {
    size_t item_size = sizeof(ros_message->speed_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gimbal_angle
  {
    size_t item_size = sizeof(ros_message->gimbal_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: capacitor_voltage
  {
    size_t item_size = sizeof(ros_message->capacitor_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__ChassisOdom(
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

  // Field name: speed_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed_w
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gimbal_angle
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: capacitor_voltage
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
    using DataType = robots_msgs__msg__ChassisOdom;
    is_plain =
      (
      offsetof(DataType, capacitor_voltage) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__ChassisOdom(
  const robots_msgs__msg__ChassisOdom * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: speed_x
  {
    cdr << ros_message->speed_x;
  }

  // Field name: speed_y
  {
    cdr << ros_message->speed_y;
  }

  // Field name: speed_w
  {
    cdr << ros_message->speed_w;
  }

  // Field name: gimbal_angle
  {
    cdr << ros_message->gimbal_angle;
  }

  // Field name: capacitor_voltage
  {
    cdr << ros_message->capacitor_voltage;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__ChassisOdom(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ChassisOdom__ros_msg_type * ros_message = static_cast<const _ChassisOdom__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: speed_x
  {
    size_t item_size = sizeof(ros_message->speed_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_y
  {
    size_t item_size = sizeof(ros_message->speed_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_w
  {
    size_t item_size = sizeof(ros_message->speed_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gimbal_angle
  {
    size_t item_size = sizeof(ros_message->gimbal_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: capacitor_voltage
  {
    size_t item_size = sizeof(ros_message->capacitor_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__ChassisOdom(
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
  // Field name: speed_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed_w
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gimbal_angle
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: capacitor_voltage
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
    using DataType = robots_msgs__msg__ChassisOdom;
    is_plain =
      (
      offsetof(DataType, capacitor_voltage) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ChassisOdom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robots_msgs__msg__ChassisOdom * ros_message = static_cast<const robots_msgs__msg__ChassisOdom *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robots_msgs__msg__ChassisOdom(ros_message, cdr);
}

static bool _ChassisOdom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robots_msgs__msg__ChassisOdom * ros_message = static_cast<robots_msgs__msg__ChassisOdom *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robots_msgs__msg__ChassisOdom(cdr, ros_message);
}

static uint32_t _ChassisOdom__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robots_msgs__msg__ChassisOdom(
      untyped_ros_message, 0));
}

static size_t _ChassisOdom__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robots_msgs__msg__ChassisOdom(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ChassisOdom = {
  "robots_msgs::msg",
  "ChassisOdom",
  _ChassisOdom__cdr_serialize,
  _ChassisOdom__cdr_deserialize,
  _ChassisOdom__get_serialized_size,
  _ChassisOdom__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ChassisOdom__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ChassisOdom,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__ChassisOdom__get_type_hash,
  &robots_msgs__msg__ChassisOdom__get_type_description,
  &robots_msgs__msg__ChassisOdom__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, ChassisOdom)() {
  return &_ChassisOdom__type_support;
}

#if defined(__cplusplus)
}
#endif
