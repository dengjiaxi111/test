// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/gimbal_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__GimbalData__init(robots_msgs__msg__GimbalData * msg)
{
  if (!msg) {
    return false;
  }
  // gimbal_yaw
  // gimbal_pitch
  // yaw_va
  // base_yaw
  // self_team
  return true;
}

void
robots_msgs__msg__GimbalData__fini(robots_msgs__msg__GimbalData * msg)
{
  if (!msg) {
    return;
  }
  // gimbal_yaw
  // gimbal_pitch
  // yaw_va
  // base_yaw
  // self_team
}

bool
robots_msgs__msg__GimbalData__are_equal(const robots_msgs__msg__GimbalData * lhs, const robots_msgs__msg__GimbalData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gimbal_yaw
  if (lhs->gimbal_yaw != rhs->gimbal_yaw) {
    return false;
  }
  // gimbal_pitch
  if (lhs->gimbal_pitch != rhs->gimbal_pitch) {
    return false;
  }
  // yaw_va
  if (lhs->yaw_va != rhs->yaw_va) {
    return false;
  }
  // base_yaw
  if (lhs->base_yaw != rhs->base_yaw) {
    return false;
  }
  // self_team
  if (lhs->self_team != rhs->self_team) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__GimbalData__copy(
  const robots_msgs__msg__GimbalData * input,
  robots_msgs__msg__GimbalData * output)
{
  if (!input || !output) {
    return false;
  }
  // gimbal_yaw
  output->gimbal_yaw = input->gimbal_yaw;
  // gimbal_pitch
  output->gimbal_pitch = input->gimbal_pitch;
  // yaw_va
  output->yaw_va = input->yaw_va;
  // base_yaw
  output->base_yaw = input->base_yaw;
  // self_team
  output->self_team = input->self_team;
  return true;
}

robots_msgs__msg__GimbalData *
robots_msgs__msg__GimbalData__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GimbalData * msg = (robots_msgs__msg__GimbalData *)allocator.allocate(sizeof(robots_msgs__msg__GimbalData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__GimbalData));
  bool success = robots_msgs__msg__GimbalData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__GimbalData__destroy(robots_msgs__msg__GimbalData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__GimbalData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__GimbalData__Sequence__init(robots_msgs__msg__GimbalData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GimbalData * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__GimbalData)) {
      return false;
    }
    data = (robots_msgs__msg__GimbalData *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__GimbalData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__GimbalData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__GimbalData__fini(&data[i - 1]);
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
robots_msgs__msg__GimbalData__Sequence__fini(robots_msgs__msg__GimbalData__Sequence * array)
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
      robots_msgs__msg__GimbalData__fini(&array->data[i]);
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

robots_msgs__msg__GimbalData__Sequence *
robots_msgs__msg__GimbalData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GimbalData__Sequence * array = (robots_msgs__msg__GimbalData__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__GimbalData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__GimbalData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__GimbalData__Sequence__destroy(robots_msgs__msg__GimbalData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__GimbalData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__GimbalData__Sequence__are_equal(const robots_msgs__msg__GimbalData__Sequence * lhs, const robots_msgs__msg__GimbalData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__GimbalData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__GimbalData__Sequence__copy(
  const robots_msgs__msg__GimbalData__Sequence * input,
  robots_msgs__msg__GimbalData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__GimbalData)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__GimbalData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__GimbalData * data =
      (robots_msgs__msg__GimbalData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__GimbalData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__GimbalData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__GimbalData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
