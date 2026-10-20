// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_traversal__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nav_interfaces/msg/detail/hole_traversal__struct.h"
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"
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

#include "nav_interfaces/msg/detail/hole_event__functions.h"  // events
#include "nav_interfaces/msg/detail/hole_straight__functions.h"  // straight_segments
#include "rosidl_runtime_c/string.h"  // hole_id, traversal_uid
#include "rosidl_runtime_c/string_functions.h"  // hole_id, traversal_uid

// forward declare type support functions

bool cdr_serialize_nav_interfaces__msg__HoleEvent(
  const nav_interfaces__msg__HoleEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_nav_interfaces__msg__HoleEvent(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__msg__HoleEvent * ros_message);

size_t get_serialized_size_nav_interfaces__msg__HoleEvent(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav_interfaces__msg__HoleEvent(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_nav_interfaces__msg__HoleEvent(
  const nav_interfaces__msg__HoleEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_nav_interfaces__msg__HoleEvent(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_nav_interfaces__msg__HoleEvent(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, msg, HoleEvent)();

bool cdr_serialize_nav_interfaces__msg__HoleStraight(
  const nav_interfaces__msg__HoleStraight * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_nav_interfaces__msg__HoleStraight(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__msg__HoleStraight * ros_message);

size_t get_serialized_size_nav_interfaces__msg__HoleStraight(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav_interfaces__msg__HoleStraight(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_nav_interfaces__msg__HoleStraight(
  const nav_interfaces__msg__HoleStraight * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_nav_interfaces__msg__HoleStraight(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_nav_interfaces__msg__HoleStraight(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, msg, HoleStraight)();


using _HoleTraversal__ros_msg_type = nav_interfaces__msg__HoleTraversal;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_nav_interfaces__msg__HoleTraversal(
  const nav_interfaces__msg__HoleTraversal * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: traversal_uid
  {
    const rosidl_runtime_c__String * str = &ros_message->traversal_uid;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: hole_id
  {
    const rosidl_runtime_c__String * str = &ros_message->hole_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: entry_edge_id
  {
    cdr << ros_message->entry_edge_id;
  }

  // Field name: exit_edge_id
  {
    cdr << ros_message->exit_edge_id;
  }

  // Field name: centerline
  {
    cdr << (ros_message->centerline ? true : false);
  }

  // Field name: validated
  {
    cdr << (ros_message->validated ? true : false);
  }

  // Field name: requirement_revision
  {
    cdr << ros_message->requirement_revision;
  }

  // Field name: events
  {
    size_t size = 6;
    auto array_ptr = ros_message->events;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_nav_interfaces__msg__HoleEvent(
        &array_ptr[i], cdr);
    }
  }

  // Field name: straight_segments
  {
    size_t size = ros_message->straight_segments.size;
    auto array_ptr = ros_message->straight_segments.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_nav_interfaces__msg__HoleStraight(
        &array_ptr[i], cdr);
    }
  }

  // Field name: uphill_entry
  {
    cdr << (ros_message->uphill_entry ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_deserialize_nav_interfaces__msg__HoleTraversal(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__msg__HoleTraversal * ros_message)
{
  // Field name: traversal_uid
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->traversal_uid.data) {
      rosidl_runtime_c__String__init(&ros_message->traversal_uid);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->traversal_uid,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'traversal_uid'\n");
      return false;
    }
  }

  // Field name: hole_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->hole_id.data) {
      rosidl_runtime_c__String__init(&ros_message->hole_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->hole_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'hole_id'\n");
      return false;
    }
  }

  // Field name: entry_edge_id
  {
    cdr >> ros_message->entry_edge_id;
  }

  // Field name: exit_edge_id
  {
    cdr >> ros_message->exit_edge_id;
  }

  // Field name: centerline
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->centerline = tmp ? true : false;
  }

  // Field name: validated
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->validated = tmp ? true : false;
  }

  // Field name: requirement_revision
  {
    cdr >> ros_message->requirement_revision;
  }

  // Field name: events
  {
    size_t size = 6;
    auto array_ptr = ros_message->events;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_nav_interfaces__msg__HoleEvent(cdr, &array_ptr[i]);
    }
  }

  // Field name: straight_segments
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->straight_segments.data) {
      nav_interfaces__msg__HoleStraight__Sequence__fini(&ros_message->straight_segments);
    }
    if (!nav_interfaces__msg__HoleStraight__Sequence__init(&ros_message->straight_segments, size)) {
      fprintf(stderr, "failed to create array for field 'straight_segments'");
      return false;
    }
    auto array_ptr = ros_message->straight_segments.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_nav_interfaces__msg__HoleStraight(cdr, &array_ptr[i]);
    }
  }

  // Field name: uphill_entry
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->uphill_entry = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_nav_interfaces__msg__HoleTraversal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HoleTraversal__ros_msg_type * ros_message = static_cast<const _HoleTraversal__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: traversal_uid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->traversal_uid.size + 1);

  // Field name: hole_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->hole_id.size + 1);

  // Field name: entry_edge_id
  {
    size_t item_size = sizeof(ros_message->entry_edge_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: exit_edge_id
  {
    size_t item_size = sizeof(ros_message->exit_edge_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: centerline
  {
    size_t item_size = sizeof(ros_message->centerline);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: validated
  {
    size_t item_size = sizeof(ros_message->validated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: requirement_revision
  {
    size_t item_size = sizeof(ros_message->requirement_revision);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: events
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->events;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_interfaces__msg__HoleEvent(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: straight_segments
  {
    size_t array_size = ros_message->straight_segments.size;
    auto array_ptr = ros_message->straight_segments.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_interfaces__msg__HoleStraight(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: uphill_entry
  {
    size_t item_size = sizeof(ros_message->uphill_entry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_nav_interfaces__msg__HoleTraversal(
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

  // Field name: traversal_uid
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: hole_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: entry_edge_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: exit_edge_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: centerline
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: validated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: requirement_revision
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: events
  {
    size_t array_size = 6;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_interfaces__msg__HoleEvent(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: straight_segments
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_interfaces__msg__HoleStraight(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: uphill_entry
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
    using DataType = nav_interfaces__msg__HoleTraversal;
    is_plain =
      (
      offsetof(DataType, uphill_entry) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_key_nav_interfaces__msg__HoleTraversal(
  const nav_interfaces__msg__HoleTraversal * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: traversal_uid
  {
    const rosidl_runtime_c__String * str = &ros_message->traversal_uid;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: hole_id
  {
    const rosidl_runtime_c__String * str = &ros_message->hole_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: entry_edge_id
  {
    cdr << ros_message->entry_edge_id;
  }

  // Field name: exit_edge_id
  {
    cdr << ros_message->exit_edge_id;
  }

  // Field name: centerline
  {
    cdr << (ros_message->centerline ? true : false);
  }

  // Field name: validated
  {
    cdr << (ros_message->validated ? true : false);
  }

  // Field name: requirement_revision
  {
    cdr << ros_message->requirement_revision;
  }

  // Field name: events
  {
    size_t size = 6;
    auto array_ptr = ros_message->events;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_nav_interfaces__msg__HoleEvent(
        &array_ptr[i], cdr);
    }
  }

  // Field name: straight_segments
  {
    size_t size = ros_message->straight_segments.size;
    auto array_ptr = ros_message->straight_segments.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_nav_interfaces__msg__HoleStraight(
        &array_ptr[i], cdr);
    }
  }

  // Field name: uphill_entry
  {
    cdr << (ros_message->uphill_entry ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_key_nav_interfaces__msg__HoleTraversal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HoleTraversal__ros_msg_type * ros_message = static_cast<const _HoleTraversal__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: traversal_uid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->traversal_uid.size + 1);

  // Field name: hole_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->hole_id.size + 1);

  // Field name: entry_edge_id
  {
    size_t item_size = sizeof(ros_message->entry_edge_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: exit_edge_id
  {
    size_t item_size = sizeof(ros_message->exit_edge_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: centerline
  {
    size_t item_size = sizeof(ros_message->centerline);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: validated
  {
    size_t item_size = sizeof(ros_message->validated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: requirement_revision
  {
    size_t item_size = sizeof(ros_message->requirement_revision);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: events
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->events;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_nav_interfaces__msg__HoleEvent(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: straight_segments
  {
    size_t array_size = ros_message->straight_segments.size;
    auto array_ptr = ros_message->straight_segments.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_nav_interfaces__msg__HoleStraight(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: uphill_entry
  {
    size_t item_size = sizeof(ros_message->uphill_entry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_key_nav_interfaces__msg__HoleTraversal(
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
  // Field name: traversal_uid
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: hole_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: entry_edge_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: exit_edge_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: centerline
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: validated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: requirement_revision
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: events
  {
    size_t array_size = 6;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_interfaces__msg__HoleEvent(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: straight_segments
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_interfaces__msg__HoleStraight(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: uphill_entry
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
    using DataType = nav_interfaces__msg__HoleTraversal;
    is_plain =
      (
      offsetof(DataType, uphill_entry) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _HoleTraversal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const nav_interfaces__msg__HoleTraversal * ros_message = static_cast<const nav_interfaces__msg__HoleTraversal *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_nav_interfaces__msg__HoleTraversal(ros_message, cdr);
}

static bool _HoleTraversal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  nav_interfaces__msg__HoleTraversal * ros_message = static_cast<nav_interfaces__msg__HoleTraversal *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_nav_interfaces__msg__HoleTraversal(cdr, ros_message);
}

static uint32_t _HoleTraversal__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nav_interfaces__msg__HoleTraversal(
      untyped_ros_message, 0));
}

static size_t _HoleTraversal__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nav_interfaces__msg__HoleTraversal(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HoleTraversal = {
  "nav_interfaces::msg",
  "HoleTraversal",
  _HoleTraversal__cdr_serialize,
  _HoleTraversal__cdr_deserialize,
  _HoleTraversal__get_serialized_size,
  _HoleTraversal__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _HoleTraversal__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HoleTraversal,
  get_message_typesupport_handle_function,
  &nav_interfaces__msg__HoleTraversal__get_type_hash,
  &nav_interfaces__msg__HoleTraversal__get_type_description,
  &nav_interfaces__msg__HoleTraversal__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, msg, HoleTraversal)() {
  return &_HoleTraversal__type_support;
}

#if defined(__cplusplus)
}
#endif
