// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
nav_interfaces__msg__HoleSpeedRegion__init(nav_interfaces__msg__HoleSpeedRegion * msg)
{
  if (!msg) {
    return false;
  }
  // s_begin
  // s_end
  // speed_limit
  // kind
  return true;
}

void
nav_interfaces__msg__HoleSpeedRegion__fini(nav_interfaces__msg__HoleSpeedRegion * msg)
{
  if (!msg) {
    return;
  }
  // s_begin
  // s_end
  // speed_limit
  // kind
}

bool
nav_interfaces__msg__HoleSpeedRegion__are_equal(const nav_interfaces__msg__HoleSpeedRegion * lhs, const nav_interfaces__msg__HoleSpeedRegion * rhs)
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
  // speed_limit
  if (lhs->speed_limit != rhs->speed_limit) {
    return false;
  }
  // kind
  if (lhs->kind != rhs->kind) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleSpeedRegion__copy(
  const nav_interfaces__msg__HoleSpeedRegion * input,
  nav_interfaces__msg__HoleSpeedRegion * output)
{
  if (!input || !output) {
    return false;
  }
  // s_begin
  output->s_begin = input->s_begin;
  // s_end
  output->s_end = input->s_end;
  // speed_limit
  output->speed_limit = input->speed_limit;
  // kind
  output->kind = input->kind;
  return true;
}

nav_interfaces__msg__HoleSpeedRegion *
nav_interfaces__msg__HoleSpeedRegion__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleSpeedRegion * msg = (nav_interfaces__msg__HoleSpeedRegion *)allocator.allocate(sizeof(nav_interfaces__msg__HoleSpeedRegion), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleSpeedRegion));
  bool success = nav_interfaces__msg__HoleSpeedRegion__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleSpeedRegion__destroy(nav_interfaces__msg__HoleSpeedRegion * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleSpeedRegion__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleSpeedRegion__Sequence__init(nav_interfaces__msg__HoleSpeedRegion__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleSpeedRegion * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleSpeedRegion)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleSpeedRegion *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleSpeedRegion), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleSpeedRegion__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleSpeedRegion__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleSpeedRegion__Sequence__fini(nav_interfaces__msg__HoleSpeedRegion__Sequence * array)
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
      nav_interfaces__msg__HoleSpeedRegion__fini(&array->data[i]);
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

nav_interfaces__msg__HoleSpeedRegion__Sequence *
nav_interfaces__msg__HoleSpeedRegion__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleSpeedRegion__Sequence * array = (nav_interfaces__msg__HoleSpeedRegion__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleSpeedRegion__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleSpeedRegion__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleSpeedRegion__Sequence__destroy(nav_interfaces__msg__HoleSpeedRegion__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleSpeedRegion__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleSpeedRegion__Sequence__are_equal(const nav_interfaces__msg__HoleSpeedRegion__Sequence * lhs, const nav_interfaces__msg__HoleSpeedRegion__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleSpeedRegion__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleSpeedRegion__Sequence__copy(
  const nav_interfaces__msg__HoleSpeedRegion__Sequence * input,
  nav_interfaces__msg__HoleSpeedRegion__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleSpeedRegion)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleSpeedRegion);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleSpeedRegion * data =
      (nav_interfaces__msg__HoleSpeedRegion *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleSpeedRegion__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleSpeedRegion__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleSpeedRegion__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
