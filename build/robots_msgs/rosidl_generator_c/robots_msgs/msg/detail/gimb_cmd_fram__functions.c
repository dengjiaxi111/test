// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/gimb_cmd_fram__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__GimbCmdFram__init(robots_msgs__msg__GimbCmdFram * msg)
{
  if (!msg) {
    return false;
  }
  // center_yaw
  // armor_pitch
  // armor_yaw
  // spin_flag
  // shot_mode
  return true;
}

void
robots_msgs__msg__GimbCmdFram__fini(robots_msgs__msg__GimbCmdFram * msg)
{
  if (!msg) {
    return;
  }
  // center_yaw
  // armor_pitch
  // armor_yaw
  // spin_flag
  // shot_mode
}

bool
robots_msgs__msg__GimbCmdFram__are_equal(const robots_msgs__msg__GimbCmdFram * lhs, const robots_msgs__msg__GimbCmdFram * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // center_yaw
  if (lhs->center_yaw != rhs->center_yaw) {
    return false;
  }
  // armor_pitch
  if (lhs->armor_pitch != rhs->armor_pitch) {
    return false;
  }
  // armor_yaw
  if (lhs->armor_yaw != rhs->armor_yaw) {
    return false;
  }
  // spin_flag
  if (lhs->spin_flag != rhs->spin_flag) {
    return false;
  }
  // shot_mode
  if (lhs->shot_mode != rhs->shot_mode) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__GimbCmdFram__copy(
  const robots_msgs__msg__GimbCmdFram * input,
  robots_msgs__msg__GimbCmdFram * output)
{
  if (!input || !output) {
    return false;
  }
  // center_yaw
  output->center_yaw = input->center_yaw;
  // armor_pitch
  output->armor_pitch = input->armor_pitch;
  // armor_yaw
  output->armor_yaw = input->armor_yaw;
  // spin_flag
  output->spin_flag = input->spin_flag;
  // shot_mode
  output->shot_mode = input->shot_mode;
  return true;
}

robots_msgs__msg__GimbCmdFram *
robots_msgs__msg__GimbCmdFram__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GimbCmdFram * msg = (robots_msgs__msg__GimbCmdFram *)allocator.allocate(sizeof(robots_msgs__msg__GimbCmdFram), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__GimbCmdFram));
  bool success = robots_msgs__msg__GimbCmdFram__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__GimbCmdFram__destroy(robots_msgs__msg__GimbCmdFram * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__GimbCmdFram__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__GimbCmdFram__Sequence__init(robots_msgs__msg__GimbCmdFram__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GimbCmdFram * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__GimbCmdFram)) {
      return false;
    }
    data = (robots_msgs__msg__GimbCmdFram *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__GimbCmdFram), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__GimbCmdFram__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__GimbCmdFram__fini(&data[i - 1]);
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
robots_msgs__msg__GimbCmdFram__Sequence__fini(robots_msgs__msg__GimbCmdFram__Sequence * array)
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
      robots_msgs__msg__GimbCmdFram__fini(&array->data[i]);
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

robots_msgs__msg__GimbCmdFram__Sequence *
robots_msgs__msg__GimbCmdFram__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GimbCmdFram__Sequence * array = (robots_msgs__msg__GimbCmdFram__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__GimbCmdFram__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__GimbCmdFram__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__GimbCmdFram__Sequence__destroy(robots_msgs__msg__GimbCmdFram__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__GimbCmdFram__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__GimbCmdFram__Sequence__are_equal(const robots_msgs__msg__GimbCmdFram__Sequence * lhs, const robots_msgs__msg__GimbCmdFram__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__GimbCmdFram__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__GimbCmdFram__Sequence__copy(
  const robots_msgs__msg__GimbCmdFram__Sequence * input,
  robots_msgs__msg__GimbCmdFram__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__GimbCmdFram)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__GimbCmdFram);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__GimbCmdFram * data =
      (robots_msgs__msg__GimbCmdFram *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__GimbCmdFram__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__GimbCmdFram__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__GimbCmdFram__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
