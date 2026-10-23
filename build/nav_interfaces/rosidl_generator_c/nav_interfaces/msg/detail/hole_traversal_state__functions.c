// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_traversal_state__functions.h"

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
// Member `reason`
// Member `traversal_uids`
#include "rosidl_runtime_c/string_functions.h"
// Member `phases`
// Member `preparing_required`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
nav_interfaces__msg__HoleTraversalState__init(nav_interfaces__msg__HoleTraversalState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // session_id
  if (!rosidl_runtime_c__String__init(&msg->session_id)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // goal_id
  if (!rosidl_runtime_c__String__init(&msg->goal_id)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // plan_id
  // state
  // decision
  // s_progress
  // speed_limit
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // traversal_uids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->traversal_uids, 0)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // phases
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->phases, 0)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // preparing_required
  if (!rosidl_runtime_c__boolean__Sequence__init(&msg->preparing_required, 0)) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
    return false;
  }
  // attempt
  // recovery_phase
  // hold_gimbal_heading
  return true;
}

void
nav_interfaces__msg__HoleTraversalState__fini(nav_interfaces__msg__HoleTraversalState * msg)
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
  // plan_id
  // state
  // decision
  // s_progress
  // speed_limit
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // traversal_uids
  rosidl_runtime_c__String__Sequence__fini(&msg->traversal_uids);
  // phases
  rosidl_runtime_c__uint8__Sequence__fini(&msg->phases);
  // preparing_required
  rosidl_runtime_c__boolean__Sequence__fini(&msg->preparing_required);
  // attempt
  // recovery_phase
  // hold_gimbal_heading
}

bool
nav_interfaces__msg__HoleTraversalState__are_equal(const nav_interfaces__msg__HoleTraversalState * lhs, const nav_interfaces__msg__HoleTraversalState * rhs)
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
  // plan_id
  if (lhs->plan_id != rhs->plan_id) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // decision
  if (lhs->decision != rhs->decision) {
    return false;
  }
  // s_progress
  if (lhs->s_progress != rhs->s_progress) {
    return false;
  }
  // speed_limit
  if (lhs->speed_limit != rhs->speed_limit) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // traversal_uids
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->traversal_uids), &(rhs->traversal_uids)))
  {
    return false;
  }
  // phases
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->phases), &(rhs->phases)))
  {
    return false;
  }
  // preparing_required
  if (!rosidl_runtime_c__boolean__Sequence__are_equal(
      &(lhs->preparing_required), &(rhs->preparing_required)))
  {
    return false;
  }
  // attempt
  if (lhs->attempt != rhs->attempt) {
    return false;
  }
  // recovery_phase
  if (lhs->recovery_phase != rhs->recovery_phase) {
    return false;
  }
  // hold_gimbal_heading
  if (lhs->hold_gimbal_heading != rhs->hold_gimbal_heading) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleTraversalState__copy(
  const nav_interfaces__msg__HoleTraversalState * input,
  nav_interfaces__msg__HoleTraversalState * output)
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
  // plan_id
  output->plan_id = input->plan_id;
  // state
  output->state = input->state;
  // decision
  output->decision = input->decision;
  // s_progress
  output->s_progress = input->s_progress;
  // speed_limit
  output->speed_limit = input->speed_limit;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // traversal_uids
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->traversal_uids), &(output->traversal_uids)))
  {
    return false;
  }
  // phases
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->phases), &(output->phases)))
  {
    return false;
  }
  // preparing_required
  if (!rosidl_runtime_c__boolean__Sequence__copy(
      &(input->preparing_required), &(output->preparing_required)))
  {
    return false;
  }
  // attempt
  output->attempt = input->attempt;
  // recovery_phase
  output->recovery_phase = input->recovery_phase;
  // hold_gimbal_heading
  output->hold_gimbal_heading = input->hold_gimbal_heading;
  return true;
}

nav_interfaces__msg__HoleTraversalState *
nav_interfaces__msg__HoleTraversalState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleTraversalState * msg = (nav_interfaces__msg__HoleTraversalState *)allocator.allocate(sizeof(nav_interfaces__msg__HoleTraversalState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleTraversalState));
  bool success = nav_interfaces__msg__HoleTraversalState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleTraversalState__destroy(nav_interfaces__msg__HoleTraversalState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleTraversalState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleTraversalState__Sequence__init(nav_interfaces__msg__HoleTraversalState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleTraversalState * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleTraversalState)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleTraversalState *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleTraversalState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleTraversalState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleTraversalState__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleTraversalState__Sequence__fini(nav_interfaces__msg__HoleTraversalState__Sequence * array)
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
      nav_interfaces__msg__HoleTraversalState__fini(&array->data[i]);
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

nav_interfaces__msg__HoleTraversalState__Sequence *
nav_interfaces__msg__HoleTraversalState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleTraversalState__Sequence * array = (nav_interfaces__msg__HoleTraversalState__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleTraversalState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleTraversalState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleTraversalState__Sequence__destroy(nav_interfaces__msg__HoleTraversalState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleTraversalState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleTraversalState__Sequence__are_equal(const nav_interfaces__msg__HoleTraversalState__Sequence * lhs, const nav_interfaces__msg__HoleTraversalState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleTraversalState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleTraversalState__Sequence__copy(
  const nav_interfaces__msg__HoleTraversalState__Sequence * input,
  nav_interfaces__msg__HoleTraversalState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleTraversalState)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleTraversalState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleTraversalState * data =
      (nav_interfaces__msg__HoleTraversalState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleTraversalState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleTraversalState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleTraversalState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
