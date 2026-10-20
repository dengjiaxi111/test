// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/my_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `delta_x`
// Member `delta_y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robots_msgs__msg__MyPath__init(robots_msgs__msg__MyPath * msg)
{
  if (!msg) {
    return false;
  }
  // intention
  // start_x
  // start_y
  // delta_x
  if (!rosidl_runtime_c__int8__Sequence__init(&msg->delta_x, 0)) {
    robots_msgs__msg__MyPath__fini(msg);
    return false;
  }
  // delta_y
  if (!rosidl_runtime_c__int8__Sequence__init(&msg->delta_y, 0)) {
    robots_msgs__msg__MyPath__fini(msg);
    return false;
  }
  // sender_id
  return true;
}

void
robots_msgs__msg__MyPath__fini(robots_msgs__msg__MyPath * msg)
{
  if (!msg) {
    return;
  }
  // intention
  // start_x
  // start_y
  // delta_x
  rosidl_runtime_c__int8__Sequence__fini(&msg->delta_x);
  // delta_y
  rosidl_runtime_c__int8__Sequence__fini(&msg->delta_y);
  // sender_id
}

bool
robots_msgs__msg__MyPath__are_equal(const robots_msgs__msg__MyPath * lhs, const robots_msgs__msg__MyPath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // intention
  if (lhs->intention != rhs->intention) {
    return false;
  }
  // start_x
  if (lhs->start_x != rhs->start_x) {
    return false;
  }
  // start_y
  if (lhs->start_y != rhs->start_y) {
    return false;
  }
  // delta_x
  if (!rosidl_runtime_c__int8__Sequence__are_equal(
      &(lhs->delta_x), &(rhs->delta_x)))
  {
    return false;
  }
  // delta_y
  if (!rosidl_runtime_c__int8__Sequence__are_equal(
      &(lhs->delta_y), &(rhs->delta_y)))
  {
    return false;
  }
  // sender_id
  if (lhs->sender_id != rhs->sender_id) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__MyPath__copy(
  const robots_msgs__msg__MyPath * input,
  robots_msgs__msg__MyPath * output)
{
  if (!input || !output) {
    return false;
  }
  // intention
  output->intention = input->intention;
  // start_x
  output->start_x = input->start_x;
  // start_y
  output->start_y = input->start_y;
  // delta_x
  if (!rosidl_runtime_c__int8__Sequence__copy(
      &(input->delta_x), &(output->delta_x)))
  {
    return false;
  }
  // delta_y
  if (!rosidl_runtime_c__int8__Sequence__copy(
      &(input->delta_y), &(output->delta_y)))
  {
    return false;
  }
  // sender_id
  output->sender_id = input->sender_id;
  return true;
}

robots_msgs__msg__MyPath *
robots_msgs__msg__MyPath__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__MyPath * msg = (robots_msgs__msg__MyPath *)allocator.allocate(sizeof(robots_msgs__msg__MyPath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__MyPath));
  bool success = robots_msgs__msg__MyPath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__MyPath__destroy(robots_msgs__msg__MyPath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__MyPath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__MyPath__Sequence__init(robots_msgs__msg__MyPath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__MyPath * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__MyPath)) {
      return false;
    }
    data = (robots_msgs__msg__MyPath *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__MyPath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__MyPath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__MyPath__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robots_msgs__msg__MyPath__Sequence__fini(robots_msgs__msg__MyPath__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robots_msgs__msg__MyPath__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robots_msgs__msg__MyPath__Sequence *
robots_msgs__msg__MyPath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__MyPath__Sequence * array = (robots_msgs__msg__MyPath__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__MyPath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__MyPath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__MyPath__Sequence__destroy(robots_msgs__msg__MyPath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__MyPath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__MyPath__Sequence__are_equal(const robots_msgs__msg__MyPath__Sequence * lhs, const robots_msgs__msg__MyPath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__MyPath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__MyPath__Sequence__copy(
  const robots_msgs__msg__MyPath__Sequence * input,
  robots_msgs__msg__MyPath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__MyPath)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__MyPath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__MyPath * data =
      (robots_msgs__msg__MyPath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__MyPath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__MyPath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__MyPath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
