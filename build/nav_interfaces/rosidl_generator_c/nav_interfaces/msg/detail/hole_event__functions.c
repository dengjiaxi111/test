// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleEvent.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_event__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
nav_interfaces__msg__HoleEvent__init(nav_interfaces__msg__HoleEvent * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // range_status
  // s_path
  // point
  if (!geometry_msgs__msg__Point__init(&msg->point)) {
    nav_interfaces__msg__HoleEvent__fini(msg);
    return false;
  }
  // point_valid
  return true;
}

void
nav_interfaces__msg__HoleEvent__fini(nav_interfaces__msg__HoleEvent * msg)
{
  if (!msg) {
    return;
  }
  // type
  // range_status
  // s_path
  // point
  geometry_msgs__msg__Point__fini(&msg->point);
  // point_valid
}

bool
nav_interfaces__msg__HoleEvent__are_equal(const nav_interfaces__msg__HoleEvent * lhs, const nav_interfaces__msg__HoleEvent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // range_status
  if (lhs->range_status != rhs->range_status) {
    return false;
  }
  // s_path
  if (lhs->s_path != rhs->s_path) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // point_valid
  if (lhs->point_valid != rhs->point_valid) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleEvent__copy(
  const nav_interfaces__msg__HoleEvent * input,
  nav_interfaces__msg__HoleEvent * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // range_status
  output->range_status = input->range_status;
  // s_path
  output->s_path = input->s_path;
  // point
  if (!geometry_msgs__msg__Point__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // point_valid
  output->point_valid = input->point_valid;
  return true;
}

nav_interfaces__msg__HoleEvent *
nav_interfaces__msg__HoleEvent__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleEvent * msg = (nav_interfaces__msg__HoleEvent *)allocator.allocate(sizeof(nav_interfaces__msg__HoleEvent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleEvent));
  bool success = nav_interfaces__msg__HoleEvent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleEvent__destroy(nav_interfaces__msg__HoleEvent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleEvent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleEvent__Sequence__init(nav_interfaces__msg__HoleEvent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleEvent * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleEvent)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleEvent *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleEvent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleEvent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleEvent__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleEvent__Sequence__fini(nav_interfaces__msg__HoleEvent__Sequence * array)
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
      nav_interfaces__msg__HoleEvent__fini(&array->data[i]);
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

nav_interfaces__msg__HoleEvent__Sequence *
nav_interfaces__msg__HoleEvent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleEvent__Sequence * array = (nav_interfaces__msg__HoleEvent__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleEvent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleEvent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleEvent__Sequence__destroy(nav_interfaces__msg__HoleEvent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleEvent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleEvent__Sequence__are_equal(const nav_interfaces__msg__HoleEvent__Sequence * lhs, const nav_interfaces__msg__HoleEvent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleEvent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleEvent__Sequence__copy(
  const nav_interfaces__msg__HoleEvent__Sequence * input,
  nav_interfaces__msg__HoleEvent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleEvent)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleEvent);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleEvent * data =
      (nav_interfaces__msg__HoleEvent *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleEvent__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleEvent__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleEvent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
