// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/mode_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__ModeCmd__init(robots_msgs__msg__ModeCmd * msg)
{
  if (!msg) {
    return false;
  }
  // should_chassis_spin
  // should_gimbal_patrol
  // buy_bullet
  // rebirth
  // use_capacity
  return true;
}

void
robots_msgs__msg__ModeCmd__fini(robots_msgs__msg__ModeCmd * msg)
{
  if (!msg) {
    return;
  }
  // should_chassis_spin
  // should_gimbal_patrol
  // buy_bullet
  // rebirth
  // use_capacity
}

bool
robots_msgs__msg__ModeCmd__are_equal(const robots_msgs__msg__ModeCmd * lhs, const robots_msgs__msg__ModeCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // should_chassis_spin
  if (lhs->should_chassis_spin != rhs->should_chassis_spin) {
    return false;
  }
  // should_gimbal_patrol
  if (lhs->should_gimbal_patrol != rhs->should_gimbal_patrol) {
    return false;
  }
  // buy_bullet
  if (lhs->buy_bullet != rhs->buy_bullet) {
    return false;
  }
  // rebirth
  if (lhs->rebirth != rhs->rebirth) {
    return false;
  }
  // use_capacity
  if (lhs->use_capacity != rhs->use_capacity) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__ModeCmd__copy(
  const robots_msgs__msg__ModeCmd * input,
  robots_msgs__msg__ModeCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // should_chassis_spin
  output->should_chassis_spin = input->should_chassis_spin;
  // should_gimbal_patrol
  output->should_gimbal_patrol = input->should_gimbal_patrol;
  // buy_bullet
  output->buy_bullet = input->buy_bullet;
  // rebirth
  output->rebirth = input->rebirth;
  // use_capacity
  output->use_capacity = input->use_capacity;
  return true;
}

robots_msgs__msg__ModeCmd *
robots_msgs__msg__ModeCmd__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__ModeCmd * msg = (robots_msgs__msg__ModeCmd *)allocator.allocate(sizeof(robots_msgs__msg__ModeCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__ModeCmd));
  bool success = robots_msgs__msg__ModeCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__ModeCmd__destroy(robots_msgs__msg__ModeCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__ModeCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__ModeCmd__Sequence__init(robots_msgs__msg__ModeCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__ModeCmd * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__ModeCmd)) {
      return false;
    }
    data = (robots_msgs__msg__ModeCmd *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__ModeCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__ModeCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__ModeCmd__fini(&data[i - 1]);
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
robots_msgs__msg__ModeCmd__Sequence__fini(robots_msgs__msg__ModeCmd__Sequence * array)
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
      robots_msgs__msg__ModeCmd__fini(&array->data[i]);
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

robots_msgs__msg__ModeCmd__Sequence *
robots_msgs__msg__ModeCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__ModeCmd__Sequence * array = (robots_msgs__msg__ModeCmd__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__ModeCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__ModeCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__ModeCmd__Sequence__destroy(robots_msgs__msg__ModeCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__ModeCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__ModeCmd__Sequence__are_equal(const robots_msgs__msg__ModeCmd__Sequence * lhs, const robots_msgs__msg__ModeCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__ModeCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__ModeCmd__Sequence__copy(
  const robots_msgs__msg__ModeCmd__Sequence * input,
  robots_msgs__msg__ModeCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__ModeCmd)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__ModeCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__ModeCmd * data =
      (robots_msgs__msg__ModeCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__ModeCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__ModeCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__ModeCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
