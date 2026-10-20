// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/HoleStructureFeedback.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/hole_structure_feedback__functions.h"

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
// Member `cleared_traversal_uids`
#include "rosidl_runtime_c/string_functions.h"

bool
nav_interfaces__msg__HoleStructureFeedback__init(nav_interfaces__msg__HoleStructureFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nav_interfaces__msg__HoleStructureFeedback__fini(msg);
    return false;
  }
  // session_id
  if (!rosidl_runtime_c__String__init(&msg->session_id)) {
    nav_interfaces__msg__HoleStructureFeedback__fini(msg);
    return false;
  }
  // goal_id
  if (!rosidl_runtime_c__String__init(&msg->goal_id)) {
    nav_interfaces__msg__HoleStructureFeedback__fini(msg);
    return false;
  }
  // request_id
  // requirement_revision
  // target
  // status
  // whole_vehicle_clear
  // normal_clearance
  // moving_transition_supported
  // cleared_traversal_uids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->cleared_traversal_uids, 0)) {
    nav_interfaces__msg__HoleStructureFeedback__fini(msg);
    return false;
  }
  // simulated
  // action_stopped
  // retry_allowed
  // fault_code
  return true;
}

void
nav_interfaces__msg__HoleStructureFeedback__fini(nav_interfaces__msg__HoleStructureFeedback * msg)
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
  // status
  // whole_vehicle_clear
  // normal_clearance
  // moving_transition_supported
  // cleared_traversal_uids
  rosidl_runtime_c__String__Sequence__fini(&msg->cleared_traversal_uids);
  // simulated
  // action_stopped
  // retry_allowed
  // fault_code
}

bool
nav_interfaces__msg__HoleStructureFeedback__are_equal(const nav_interfaces__msg__HoleStructureFeedback * lhs, const nav_interfaces__msg__HoleStructureFeedback * rhs)
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
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // whole_vehicle_clear
  if (lhs->whole_vehicle_clear != rhs->whole_vehicle_clear) {
    return false;
  }
  // normal_clearance
  if (lhs->normal_clearance != rhs->normal_clearance) {
    return false;
  }
  // moving_transition_supported
  if (lhs->moving_transition_supported != rhs->moving_transition_supported) {
    return false;
  }
  // cleared_traversal_uids
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->cleared_traversal_uids), &(rhs->cleared_traversal_uids)))
  {
    return false;
  }
  // simulated
  if (lhs->simulated != rhs->simulated) {
    return false;
  }
  // action_stopped
  if (lhs->action_stopped != rhs->action_stopped) {
    return false;
  }
  // retry_allowed
  if (lhs->retry_allowed != rhs->retry_allowed) {
    return false;
  }
  // fault_code
  if (lhs->fault_code != rhs->fault_code) {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__HoleStructureFeedback__copy(
  const nav_interfaces__msg__HoleStructureFeedback * input,
  nav_interfaces__msg__HoleStructureFeedback * output)
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
  // status
  output->status = input->status;
  // whole_vehicle_clear
  output->whole_vehicle_clear = input->whole_vehicle_clear;
  // normal_clearance
  output->normal_clearance = input->normal_clearance;
  // moving_transition_supported
  output->moving_transition_supported = input->moving_transition_supported;
  // cleared_traversal_uids
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->cleared_traversal_uids), &(output->cleared_traversal_uids)))
  {
    return false;
  }
  // simulated
  output->simulated = input->simulated;
  // action_stopped
  output->action_stopped = input->action_stopped;
  // retry_allowed
  output->retry_allowed = input->retry_allowed;
  // fault_code
  output->fault_code = input->fault_code;
  return true;
}

nav_interfaces__msg__HoleStructureFeedback *
nav_interfaces__msg__HoleStructureFeedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStructureFeedback * msg = (nav_interfaces__msg__HoleStructureFeedback *)allocator.allocate(sizeof(nav_interfaces__msg__HoleStructureFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__HoleStructureFeedback));
  bool success = nav_interfaces__msg__HoleStructureFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__HoleStructureFeedback__destroy(nav_interfaces__msg__HoleStructureFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__HoleStructureFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__HoleStructureFeedback__Sequence__init(nav_interfaces__msg__HoleStructureFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStructureFeedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleStructureFeedback)) {
      return false;
    }
    data = (nav_interfaces__msg__HoleStructureFeedback *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__HoleStructureFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__HoleStructureFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__HoleStructureFeedback__fini(&data[i - 1]);
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
nav_interfaces__msg__HoleStructureFeedback__Sequence__fini(nav_interfaces__msg__HoleStructureFeedback__Sequence * array)
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
      nav_interfaces__msg__HoleStructureFeedback__fini(&array->data[i]);
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

nav_interfaces__msg__HoleStructureFeedback__Sequence *
nav_interfaces__msg__HoleStructureFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__HoleStructureFeedback__Sequence * array = (nav_interfaces__msg__HoleStructureFeedback__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__HoleStructureFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__HoleStructureFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__HoleStructureFeedback__Sequence__destroy(nav_interfaces__msg__HoleStructureFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__HoleStructureFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__HoleStructureFeedback__Sequence__are_equal(const nav_interfaces__msg__HoleStructureFeedback__Sequence * lhs, const nav_interfaces__msg__HoleStructureFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__HoleStructureFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__HoleStructureFeedback__Sequence__copy(
  const nav_interfaces__msg__HoleStructureFeedback__Sequence * input,
  nav_interfaces__msg__HoleStructureFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__HoleStructureFeedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__HoleStructureFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__HoleStructureFeedback * data =
      (nav_interfaces__msg__HoleStructureFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__HoleStructureFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__HoleStructureFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__HoleStructureFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
