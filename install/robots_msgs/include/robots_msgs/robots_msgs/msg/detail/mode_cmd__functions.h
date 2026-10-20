// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/mode_cmd.h"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__FUNCTIONS_H_
#define ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "robots_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "robots_msgs/msg/detail/mode_cmd__struct.h"

/// Initialize msg/ModeCmd message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robots_msgs__msg__ModeCmd
 * )) before or use
 * robots_msgs__msg__ModeCmd__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
bool
robots_msgs__msg__ModeCmd__init(robots_msgs__msg__ModeCmd * msg);

/// Finalize msg/ModeCmd message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
void
robots_msgs__msg__ModeCmd__fini(robots_msgs__msg__ModeCmd * msg);

/// Create msg/ModeCmd message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robots_msgs__msg__ModeCmd__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
robots_msgs__msg__ModeCmd *
robots_msgs__msg__ModeCmd__create(void);

/// Destroy msg/ModeCmd message.
/**
 * It calls
 * robots_msgs__msg__ModeCmd__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
void
robots_msgs__msg__ModeCmd__destroy(robots_msgs__msg__ModeCmd * msg);

/// Check for msg/ModeCmd message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
bool
robots_msgs__msg__ModeCmd__are_equal(const robots_msgs__msg__ModeCmd * lhs, const robots_msgs__msg__ModeCmd * rhs);

/// Copy a msg/ModeCmd message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
bool
robots_msgs__msg__ModeCmd__copy(
  const robots_msgs__msg__ModeCmd * input,
  robots_msgs__msg__ModeCmd * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__ModeCmd__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_runtime_c__type_description__TypeDescription *
robots_msgs__msg__ModeCmd__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__ModeCmd__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__ModeCmd__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ModeCmd messages.
/**
 * It allocates the memory for the number of elements and calls
 * robots_msgs__msg__ModeCmd__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
bool
robots_msgs__msg__ModeCmd__Sequence__init(robots_msgs__msg__ModeCmd__Sequence * array, size_t size);

/// Finalize array of msg/ModeCmd messages.
/**
 * It calls
 * robots_msgs__msg__ModeCmd__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
void
robots_msgs__msg__ModeCmd__Sequence__fini(robots_msgs__msg__ModeCmd__Sequence * array);

/// Create array of msg/ModeCmd messages.
/**
 * It allocates the memory for the array and calls
 * robots_msgs__msg__ModeCmd__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
robots_msgs__msg__ModeCmd__Sequence *
robots_msgs__msg__ModeCmd__Sequence__create(size_t size);

/// Destroy array of msg/ModeCmd messages.
/**
 * It calls
 * robots_msgs__msg__ModeCmd__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
void
robots_msgs__msg__ModeCmd__Sequence__destroy(robots_msgs__msg__ModeCmd__Sequence * array);

/// Check for msg/ModeCmd message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
bool
robots_msgs__msg__ModeCmd__Sequence__are_equal(const robots_msgs__msg__ModeCmd__Sequence * lhs, const robots_msgs__msg__ModeCmd__Sequence * rhs);

/// Copy an array of msg/ModeCmd messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
bool
robots_msgs__msg__ModeCmd__Sequence__copy(
  const robots_msgs__msg__ModeCmd__Sequence * input,
  robots_msgs__msg__ModeCmd__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__FUNCTIONS_H_
