// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_structure_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `session_id`
// Member `goal_id`
// Member `traversal_uids`
#include "rosidl_runtime_c/string_functions.h"

bool
nav_interfaces__msg__HoleStructureRequest__init(nav_interfaces__msg__HoleStructureRequest * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nav_interfaces__msg__HoleStructureRequest__fini(msg);
    return false;
  }
  // session_id
  if (!rosidl_runtime_c__String__init(&msg->session_id)) {
    nav_interfaces__msg__HoleStructureRequest__fini(msg);
    return false;
  }
  // goal_id
  if (!rosidl_runtime_c__String__init(&msg->goal_id)) {
    nav_interfaces__msg__HoleStructureRequest__fini(msg);
    return false;
  }
  // request_id
  // requirement_revision
  // target
  // traversal_uids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->traversal_uids, 0)) {
    nav_interfaces__msg__HoleStructureRequest__fini(msg);
    return false;
  }
  // cancel_motion
  return true;
}

void
nav_interfaces__msg__HoleStructureRequest__fini(nav_interfaces__msg__HoleStructureRequest * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // session_id
  rosidl_runtime_c__String__fini(&msg->session_id);
  // goal_id
  rosidl_runtime_c__String__fini(&msg->goal_id);
  // request_id
  // requirement_revision
  // target
  // traversal_uids
  rosidl_runtime_c__String__Sequence__fini(&msg->traversal_uids);
  // cancel_motion
}

bool
nav_interfaces__msg__HoleStructureRequest__are_equal(const nav_interfaces__msg__HoleStructureRequest * lhs, const nav_interfaces__msg__HoleStructureRequest * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // session_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->session_id), &(rhs->session_id)))
  {
    return false;
  }
  // goal_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // request_id
  if (lhs->request_id != rhs->request_id) {
    return false;
  }
  // requirement_revision
  if (lhs->requirement_revision != rhs->requirement_revision) {
    return false;
  }
  // target
  if (lhs->target != rhs->target) {
    return false;
  }
  // traversal_uids
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->traversal_uids), &(rhs->traversal_uids)))
  {
    return false;
  }
  // cancel_motion
  if (lhs->cancel_motion != rhs->cancel_motion) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleStructureRequest__copy(
  const nav_interfaces__msg__HoleStructureRequest * input,
  nav_interfaces__msg__HoleStructureRequest * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // session_id
  if (!rosidl_runtime_c__String__copy(
      &(input->session_id), &(output->session_id)))
  {
    return false;
  }
  // goal_id
  if (!rosidl_runtime_c__String__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // request_id
  output->request_id = input->request_id;
  // requirement_revision
  output->requirement_revision = input->requirement_revision;
  // target
  output->target = input->target;
  // traversal_uids
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->traversal_uids), &(output->traversal_uids)))
  {
    return false;
  }
  // cancel_motion
  output->cancel_motion = input->cancel_motion;
  return true;
}

nav_interfaces__msg__HoleStructureRequest *
nav_interfaces__msg__HoleStructureRequest__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStructureRequest * msg = (nav_interfaces__msg__HoleStructureRequest *)allocator.allocate(sizeof(nav_interfaces__msg__HoleStructureRequest), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleStructureRequest));
  bool success = nav_interfaces__msg__HoleStructureRequest__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleStructureRequest__destroy(nav_interfaces__msg__HoleStructureRequest * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleStructureRequest__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleStructureRequest__Sequence__init(nav_interfaces__msg__HoleStructureRequest__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStructureRequest * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleStructureRequest)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleStructureRequest *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleStructureRequest), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleStructureRequest__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleStructureRequest__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleStructureRequest__Sequence__fini(nav_interfaces__msg__HoleStructureRequest__Sequence * array)
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
      nav_interfaces__msg__HoleStructureRequest__fini(&array->data[i]);
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

nav_interfaces__msg__HoleStructureRequest__Sequence *
nav_interfaces__msg__HoleStructureRequest__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStructureRequest__Sequence * array = (nav_interfaces__msg__HoleStructureRequest__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleStructureRequest__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleStructureRequest__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleStructureRequest__Sequence__destroy(nav_interfaces__msg__HoleStructureRequest__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleStructureRequest__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleStructureRequest__Sequence__are_equal(const nav_interfaces__msg__HoleStructureRequest__Sequence * lhs, const nav_interfaces__msg__HoleStructureRequest__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleStructureRequest__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleStructureRequest__Sequence__copy(
  const nav_interfaces__msg__HoleStructureRequest__Sequence * input,
  nav_interfaces__msg__HoleStructureRequest__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleStructureRequest)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleStructureRequest);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleStructureRequest * data =
      (nav_interfaces__msg__HoleStructureRequest *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleStructureRequest__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleStructureRequest__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleStructureRequest__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
