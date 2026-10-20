// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `traversal_uid`
// Member `hole_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `events`
#include "nav_interfaces/msg/detail/hole_event__functions.h"
// Member `straight_segments`
#include "nav_interfaces/msg/detail/hole_straight__functions.h"

bool
nav_interfaces__msg__HoleTraversal__init(nav_interfaces__msg__HoleTraversal * msg)
{
  if (!msg) {
    return false;
  }
  // traversal_uid
  if (!rosidl_runtime_c__String__init(&msg->traversal_uid)) {
    nav_interfaces__msg__HoleTraversal__fini(msg);
    return false;
  }
  // hole_id
  if (!rosidl_runtime_c__String__init(&msg->hole_id)) {
    nav_interfaces__msg__HoleTraversal__fini(msg);
    return false;
  }
  // entry_edge_id
  // exit_edge_id
  // centerline
  // validated
  // requirement_revision
  // events
  for (size_t i = 0; i < 6; ++i) {
    if (!nav_interfaces__msg__HoleEvent__init(&msg->events[i])) {
      nav_interfaces__msg__HoleTraversal__fini(msg);
      return false;
    }
  }
  // straight_segments
  if (!nav_interfaces__msg__HoleStraight__Sequence__init(&msg->straight_segments, 0)) {
    nav_interfaces__msg__HoleTraversal__fini(msg);
    return false;
  }
  // uphill_entry
  return true;
}

void
nav_interfaces__msg__HoleTraversal__fini(nav_interfaces__msg__HoleTraversal * msg)
{
  if (!msg) {
    return;
  }
  // traversal_uid
  rosidl_runtime_c__String__fini(&msg->traversal_uid);
  // hole_id
  rosidl_runtime_c__String__fini(&msg->hole_id);
  // entry_edge_id
  // exit_edge_id
  // centerline
  // validated
  // requirement_revision
  // events
  for (size_t i = 0; i < 6; ++i) {
    nav_interfaces__msg__HoleEvent__fini(&msg->events[i]);
  }
  // straight_segments
  nav_interfaces__msg__HoleStraight__Sequence__fini(&msg->straight_segments);
  // uphill_entry
}

bool
nav_interfaces__msg__HoleTraversal__are_equal(const nav_interfaces__msg__HoleTraversal * lhs, const nav_interfaces__msg__HoleTraversal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // traversal_uid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->traversal_uid), &(rhs->traversal_uid)))
  {
    return false;
  }
  // hole_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->hole_id), &(rhs->hole_id)))
  {
    return false;
  }
  // entry_edge_id
  if (lhs->entry_edge_id != rhs->entry_edge_id) {
    return false;
  }
  // exit_edge_id
  if (lhs->exit_edge_id != rhs->exit_edge_id) {
    return false;
  }
  // centerline
  if (lhs->centerline != rhs->centerline) {
    return false;
  }
  // validated
  if (lhs->validated != rhs->validated) {
    return false;
  }
  // requirement_revision
  if (lhs->requirement_revision != rhs->requirement_revision) {
    return false;
  }
  // events
  for (size_t i = 0; i < 6; ++i) {
    if (!nav_interfaces__msg__HoleEvent__are_equal(
        &(lhs->events[i]), &(rhs->events[i])))
    {
      return false;
    }
  }
  // straight_segments
  if (!nav_interfaces__msg__HoleStraight__Sequence__are_equal(
      &(lhs->straight_segments), &(rhs->straight_segments)))
  {
    return false;
  }
  // uphill_entry
  if (lhs->uphill_entry != rhs->uphill_entry) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleTraversal__copy(
  const nav_interfaces__msg__HoleTraversal * input,
  nav_interfaces__msg__HoleTraversal * output)
{
  if (!input || !output) {
    return false;
  }
  // traversal_uid
  if (!rosidl_runtime_c__String__copy(
      &(input->traversal_uid), &(output->traversal_uid)))
  {
    return false;
  }
  // hole_id
  if (!rosidl_runtime_c__String__copy(
      &(input->hole_id), &(output->hole_id)))
  {
    return false;
  }
  // entry_edge_id
  output->entry_edge_id = input->entry_edge_id;
  // exit_edge_id
  output->exit_edge_id = input->exit_edge_id;
  // centerline
  output->centerline = input->centerline;
  // validated
  output->validated = input->validated;
  // requirement_revision
  output->requirement_revision = input->requirement_revision;
  // events
  for (size_t i = 0; i < 6; ++i) {
    if (!nav_interfaces__msg__HoleEvent__copy(
        &(input->events[i]), &(output->events[i])))
    {
      return false;
    }
  }
  // straight_segments
  if (!nav_interfaces__msg__HoleStraight__Sequence__copy(
      &(input->straight_segments), &(output->straight_segments)))
  {
    return false;
  }
  // uphill_entry
  output->uphill_entry = input->uphill_entry;
  return true;
}

nav_interfaces__msg__HoleTraversal *
nav_interfaces__msg__HoleTraversal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleTraversal * msg = (nav_interfaces__msg__HoleTraversal *)allocator.allocate(sizeof(nav_interfaces__msg__HoleTraversal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleTraversal));
  bool success = nav_interfaces__msg__HoleTraversal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleTraversal__destroy(nav_interfaces__msg__HoleTraversal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleTraversal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleTraversal__Sequence__init(nav_interfaces__msg__HoleTraversal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleTraversal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleTraversal)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleTraversal *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleTraversal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleTraversal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleTraversal__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleTraversal__Sequence__fini(nav_interfaces__msg__HoleTraversal__Sequence * array)
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
      nav_interfaces__msg__HoleTraversal__fini(&array->data[i]);
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

nav_interfaces__msg__HoleTraversal__Sequence *
nav_interfaces__msg__HoleTraversal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleTraversal__Sequence * array = (nav_interfaces__msg__HoleTraversal__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleTraversal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleTraversal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleTraversal__Sequence__destroy(nav_interfaces__msg__HoleTraversal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleTraversal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleTraversal__Sequence__are_equal(const nav_interfaces__msg__HoleTraversal__Sequence * lhs, const nav_interfaces__msg__HoleTraversal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleTraversal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleTraversal__Sequence__copy(
  const nav_interfaces__msg__HoleTraversal__Sequence * input,
  nav_interfaces__msg__HoleTraversal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleTraversal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleTraversal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleTraversal * data =
      (nav_interfaces__msg__HoleTraversal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleTraversal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleTraversal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleTraversal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
