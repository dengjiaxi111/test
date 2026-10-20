// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/srv/detail/apply_temporary_map__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nav_interfaces/srv/detail/apply_temporary_map__struct.h"
#include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // indices, values
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // indices, values
#include "rosidl_runtime_c/string.h"  // expected_session_id, expected_source_id
#include "rosidl_runtime_c/string_functions.h"  // expected_session_id, expected_source_id

// forward declare type support functions


using _ApplyTemporaryMap_Request__ros_msg_type = nav_interfaces__srv__ApplyTemporaryMap_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: expected_session_id
  {
    const rosidl_runtime_c__String * str = &ros_message->expected_session_id;
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

  // Field name: expected_source_id
  {
    const rosidl_runtime_c__String * str = &ros_message->expected_source_id;
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

  // Field name: expected_map_revision
  {
    cdr << ros_message->expected_map_revision;
  }

  // Field name: indices
  {
    size_t size = ros_message->indices.size;
    auto array_ptr = ros_message->indices.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: values
  {
    size_t size = ros_message->values.size;
    auto array_ptr = ros_message->values.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Request(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message)
{
  // Field name: expected_session_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->expected_session_id.data) {
      rosidl_runtime_c__String__init(&ros_message->expected_session_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->expected_session_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'expected_session_id'\n");
      return false;
    }
  }

  // Field name: expected_source_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->expected_source_id.data) {
      rosidl_runtime_c__String__init(&ros_message->expected_source_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->expected_source_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'expected_source_id'\n");
      return false;
    }
  }

  // Field name: expected_map_revision
  {
    cdr >> ros_message->expected_map_revision;
  }

  // Field name: indices
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

    if (ros_message->indices.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->indices);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->indices, size)) {
      fprintf(stderr, "failed to create array for field 'indices'");
      return false;
    }
    auto array_ptr = ros_message->indices.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: values
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

    if (ros_message->values.data) {
      rosidl_runtime_c__int8__Sequence__fini(&ros_message->values);
    }
    if (!rosidl_runtime_c__int8__Sequence__init(&ros_message->values, size)) {
      fprintf(stderr, "failed to create array for field 'values'");
      return false;
    }
    auto array_ptr = ros_message->values.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ApplyTemporaryMap_Request__ros_msg_type * ros_message = static_cast<const _ApplyTemporaryMap_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: expected_session_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->expected_session_id.size + 1);

  // Field name: expected_source_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->expected_source_id.size + 1);

  // Field name: expected_map_revision
  {
    size_t item_size = sizeof(ros_message->expected_map_revision);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: indices
  {
    size_t array_size = ros_message->indices.size;
    auto array_ptr = ros_message->indices.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: values
  {
    size_t array_size = ros_message->values.size;
    auto array_ptr = ros_message->values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
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

  // Field name: expected_session_id
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

  // Field name: expected_source_id
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

  // Field name: expected_map_revision
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: indices
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = nav_interfaces__srv__ApplyTemporaryMap_Request;
    is_plain =
      (
      offsetof(DataType, values) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: expected_session_id
  {
    const rosidl_runtime_c__String * str = &ros_message->expected_session_id;
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

  // Field name: expected_source_id
  {
    const rosidl_runtime_c__String * str = &ros_message->expected_source_id;
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

  // Field name: expected_map_revision
  {
    cdr << ros_message->expected_map_revision;
  }

  // Field name: indices
  {
    size_t size = ros_message->indices.size;
    auto array_ptr = ros_message->indices.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: values
  {
    size_t size = ros_message->values.size;
    auto array_ptr = ros_message->values.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ApplyTemporaryMap_Request__ros_msg_type * ros_message = static_cast<const _ApplyTemporaryMap_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: expected_session_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->expected_session_id.size + 1);

  // Field name: expected_source_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->expected_source_id.size + 1);

  // Field name: expected_map_revision
  {
    size_t item_size = sizeof(ros_message->expected_map_revision);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: indices
  {
    size_t array_size = ros_message->indices.size;
    auto array_ptr = ros_message->indices.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: values
  {
    size_t array_size = ros_message->values.size;
    auto array_ptr = ros_message->values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
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
  // Field name: expected_session_id
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

  // Field name: expected_source_id
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

  // Field name: expected_map_revision
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: indices
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = nav_interfaces__srv__ApplyTemporaryMap_Request;
    is_plain =
      (
      offsetof(DataType, values) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ApplyTemporaryMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message = static_cast<const nav_interfaces__srv__ApplyTemporaryMap_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Request(ros_message, cdr);
}

static bool _ApplyTemporaryMap_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message = static_cast<nav_interfaces__srv__ApplyTemporaryMap_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Request(cdr, ros_message);
}

static uint32_t _ApplyTemporaryMap_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
      untyped_ros_message, 0));
}

static size_t _ApplyTemporaryMap_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ApplyTemporaryMap_Request = {
  "nav_interfaces::srv",
  "ApplyTemporaryMap_Request",
  _ApplyTemporaryMap_Request__cdr_serialize,
  _ApplyTemporaryMap_Request__cdr_deserialize,
  _ApplyTemporaryMap_Request__get_serialized_size,
  _ApplyTemporaryMap_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ApplyTemporaryMap_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ApplyTemporaryMap_Request,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Request)() {
  return &_ApplyTemporaryMap_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // reason
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // reason

// forward declare type support functions


using _ApplyTemporaryMap_Response__ros_msg_type = nav_interfaces__srv__ApplyTemporaryMap_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: reason
  {
    const rosidl_runtime_c__String * str = &ros_message->reason;
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

  // Field name: map_revision
  {
    cdr << ros_message->map_revision;
  }

  // Field name: replanning_triggered
  {
    cdr << (ros_message->replanning_triggered ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Response(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message)
{
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: reason
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->reason.data) {
      rosidl_runtime_c__String__init(&ros_message->reason);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->reason,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'reason'\n");
      return false;
    }
  }

  // Field name: map_revision
  {
    cdr >> ros_message->map_revision;
  }

  // Field name: replanning_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->replanning_triggered = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ApplyTemporaryMap_Response__ros_msg_type * ros_message = static_cast<const _ApplyTemporaryMap_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->reason.size + 1);

  // Field name: map_revision
  {
    size_t item_size = sizeof(ros_message->map_revision);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: replanning_triggered
  {
    size_t item_size = sizeof(ros_message->replanning_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
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

  // Field name: success
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: reason
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

  // Field name: map_revision
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: replanning_triggered
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
    using DataType = nav_interfaces__srv__ApplyTemporaryMap_Response;
    is_plain =
      (
      offsetof(DataType, replanning_triggered) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: reason
  {
    const rosidl_runtime_c__String * str = &ros_message->reason;
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

  // Field name: map_revision
  {
    cdr << ros_message->map_revision;
  }

  // Field name: replanning_triggered
  {
    cdr << (ros_message->replanning_triggered ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ApplyTemporaryMap_Response__ros_msg_type * ros_message = static_cast<const _ApplyTemporaryMap_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->reason.size + 1);

  // Field name: map_revision
  {
    size_t item_size = sizeof(ros_message->map_revision);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: replanning_triggered
  {
    size_t item_size = sizeof(ros_message->replanning_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
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
  // Field name: success
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: reason
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

  // Field name: map_revision
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: replanning_triggered
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
    using DataType = nav_interfaces__srv__ApplyTemporaryMap_Response;
    is_plain =
      (
      offsetof(DataType, replanning_triggered) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ApplyTemporaryMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message = static_cast<const nav_interfaces__srv__ApplyTemporaryMap_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Response(ros_message, cdr);
}

static bool _ApplyTemporaryMap_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message = static_cast<nav_interfaces__srv__ApplyTemporaryMap_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Response(cdr, ros_message);
}

static uint32_t _ApplyTemporaryMap_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
      untyped_ros_message, 0));
}

static size_t _ApplyTemporaryMap_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ApplyTemporaryMap_Response = {
  "nav_interfaces::srv",
  "ApplyTemporaryMap_Response",
  _ApplyTemporaryMap_Response__cdr_serialize,
  _ApplyTemporaryMap_Response__cdr_deserialize,
  _ApplyTemporaryMap_Response__get_serialized_size,
  _ApplyTemporaryMap_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ApplyTemporaryMap_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ApplyTemporaryMap_Response,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Response)() {
  return &_ApplyTemporaryMap_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__struct.h"
// already included above
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Request(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message);

size_t get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const nav_interfaces__srv__ApplyTemporaryMap_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Request)();

bool cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Response(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message);

size_t get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const nav_interfaces__srv__ApplyTemporaryMap_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nav_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _ApplyTemporaryMap_Event__ros_msg_type = nav_interfaces__srv__ApplyTemporaryMap_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Event(
  const nav_interfaces__srv__ApplyTemporaryMap_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Event(
  eprosima::fastcdr::Cdr & cdr,
  nav_interfaces__srv__ApplyTemporaryMap_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
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

    if (ros_message->request.data) {
      nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(&ros_message->request);
    }
    if (!nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
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

    if (ros_message->response.data) {
      nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(&ros_message->response);
    }
    if (!nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ApplyTemporaryMap_Event__ros_msg_type * ros_message = static_cast<const _ApplyTemporaryMap_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Event(
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

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = nav_interfaces__srv__ApplyTemporaryMap_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
bool cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Event(
  const nav_interfaces__srv__ApplyTemporaryMap_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ApplyTemporaryMap_Event__ros_msg_type * ros_message = static_cast<const _ApplyTemporaryMap_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nav_interfaces
size_t max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Event(
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
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_nav_interfaces__srv__ApplyTemporaryMap_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = nav_interfaces__srv__ApplyTemporaryMap_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ApplyTemporaryMap_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const nav_interfaces__srv__ApplyTemporaryMap_Event * ros_message = static_cast<const nav_interfaces__srv__ApplyTemporaryMap_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_nav_interfaces__srv__ApplyTemporaryMap_Event(ros_message, cdr);
}

static bool _ApplyTemporaryMap_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  nav_interfaces__srv__ApplyTemporaryMap_Event * ros_message = static_cast<nav_interfaces__srv__ApplyTemporaryMap_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_nav_interfaces__srv__ApplyTemporaryMap_Event(cdr, ros_message);
}

static uint32_t _ApplyTemporaryMap_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Event(
      untyped_ros_message, 0));
}

static size_t _ApplyTemporaryMap_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nav_interfaces__srv__ApplyTemporaryMap_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ApplyTemporaryMap_Event = {
  "nav_interfaces::srv",
  "ApplyTemporaryMap_Event",
  _ApplyTemporaryMap_Event__cdr_serialize,
  _ApplyTemporaryMap_Event__cdr_deserialize,
  _ApplyTemporaryMap_Event__get_serialized_size,
  _ApplyTemporaryMap_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ApplyTemporaryMap_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ApplyTemporaryMap_Event,
  get_message_typesupport_handle_function,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Event)() {
  return &_ApplyTemporaryMap_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "nav_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nav_interfaces/srv/apply_temporary_map.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ApplyTemporaryMap__callbacks = {
  "nav_interfaces::srv",
  "ApplyTemporaryMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap_Response)(),
};

static rosidl_service_type_support_t ApplyTemporaryMap__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ApplyTemporaryMap__callbacks,
  get_service_typesupport_handle_function,
  &_ApplyTemporaryMap_Request__type_support,
  &_ApplyTemporaryMap_Response__type_support,
  &_ApplyTemporaryMap_Event__type_support,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    nav_interfaces,
    srv,
    ApplyTemporaryMap
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    nav_interfaces,
    srv,
    ApplyTemporaryMap
  ),
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_hash,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_description,
  &nav_interfaces__srv__ApplyTemporaryMap__get_type_description_sources,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, ApplyTemporaryMap)() {
  return &ApplyTemporaryMap__handle;
}

#if defined(__cplusplus)
}
#endif
