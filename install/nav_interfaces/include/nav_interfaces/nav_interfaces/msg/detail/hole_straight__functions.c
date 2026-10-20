// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleStraight.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_straight__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `direction`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
nav_interfaces__msg__HoleStraight__init(nav_interfaces__msg__HoleStraight * msg)
{
  if (!msg) {
    return false;
  }
  // s_begin
  // s_end
  // direction
  if (!geometry_msgs__msg__Vector3__init(&msg->direction)) {
    nav_interfaces__msg__HoleStraight__fini(msg);
    return false;
  }
  // remaining
  return true;
}

void
nav_interfaces__msg__HoleStraight__fini(nav_interfaces__msg__HoleStraight * msg)
{
  if (!msg) {
    return;
  }
  // s_begin
  // s_end
  // direction
  geometry_msgs__msg__Vector3__fini(&msg->direction);
  // remaining
}

bool
nav_interfaces__msg__HoleStraight__are_equal(const nav_interfaces__msg__HoleStraight * lhs, const nav_interfaces__msg__HoleStraight * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // s_begin
  if (lhs->s_begin != rhs->s_begin) {
    return false;
  }
  // s_end
  if (lhs->s_end != rhs->s_end) {
    return false;
  }
  // direction
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  // remaining
  if (lhs->remaining != rhs->remaining) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleStraight__copy(
  const nav_interfaces__msg__HoleStraight * input,
  nav_interfaces__msg__HoleStraight * output)
{
  if (!input || !output) {
    return false;
  }
  // s_begin
  output->s_begin = input->s_begin;
  // s_end
  output->s_end = input->s_end;
  // direction
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  // remaining
  output->remaining = input->remaining;
  return true;
}

nav_interfaces__msg__HoleStraight *
nav_interfaces__msg__HoleStraight__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStraight * msg = (nav_interfaces__msg__HoleStraight *)allocator.allocate(sizeof(nav_interfaces__msg__HoleStraight), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleStraight));
  bool success = nav_interfaces__msg__HoleStraight__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleStraight__destroy(nav_interfaces__msg__HoleStraight * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleStraight__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleStraight__Sequence__init(nav_interfaces__msg__HoleStraight__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStraight * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleStraight)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleStraight *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleStraight), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleStraight__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleStraight__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleStraight__Sequence__fini(nav_interfaces__msg__HoleStraight__Sequence * array)
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
      nav_interfaces__msg__HoleStraight__fini(&array->data[i]);
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

nav_interfaces__msg__HoleStraight__Sequence *
nav_interfaces__msg__HoleStraight__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStraight__Sequence * array = (nav_interfaces__msg__HoleStraight__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleStraight__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleStraight__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleStraight__Sequence__destroy(nav_interfaces__msg__HoleStraight__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleStraight__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleStraight__Sequence__are_equal(const nav_interfaces__msg__HoleStraight__Sequence * lhs, const nav_interfaces__msg__HoleStraight__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleStraight__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleStraight__Sequence__copy(
  const nav_interfaces__msg__HoleStraight__Sequence * input,
  nav_interfaces__msg__HoleStraight__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleStraight)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleStraight);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleStraight * data =
      (nav_interfaces__msg__HoleStraight *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleStraight__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleStraight__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleStraight__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
