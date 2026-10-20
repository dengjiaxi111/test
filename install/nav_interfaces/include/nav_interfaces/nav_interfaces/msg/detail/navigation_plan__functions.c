// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/msg/detail/navigation_plan__functions.h"

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
#include "rosidl_runtime_c/string_functions.h"
// Member `path`
#include "nav_msgs/msg/detail/path__functions.h"
// Member `passages`
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"
// Member `speed_regions`
#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"

bool
nav_interfaces__msg__NavigationPlan__init(nav_interfaces__msg__NavigationPlan * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  // session_id
  if (!rosidl_runtime_c__String__init(&msg->session_id)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  // goal_id
  if (!rosidl_runtime_c__String__init(&msg->goal_id)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  // plan_id
  // status
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  // constraints_enabled
  // terrain_revision
  // parameter_revision
  // map_revision
  // path
  if (!nav_msgs__msg__Path__init(&msg->path)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  // path_length
  // passages
  if (!nav_interfaces__msg__HoleTraversal__Sequence__init(&msg->passages, 0)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  // speed_regions
  if (!nav_interfaces__msg__HoleSpeedRegion__Sequence__init(&msg->speed_regions, 0)) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
    return false;
  }
  return true;
}

void
nav_interfaces__msg__NavigationPlan__fini(nav_interfaces__msg__NavigationPlan * msg)
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
  // status
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // constraints_enabled
  // terrain_revision
  // parameter_revision
  // map_revision
  // path
  nav_msgs__msg__Path__fini(&msg->path);
  // path_length
  // passages
  nav_interfaces__msg__HoleTraversal__Sequence__fini(&msg->passages);
  // speed_regions
  nav_interfaces__msg__HoleSpeedRegion__Sequence__fini(&msg->speed_regions);
}

bool
nav_interfaces__msg__NavigationPlan__are_equal(const nav_interfaces__msg__NavigationPlan * lhs, const nav_interfaces__msg__NavigationPlan * rhs)
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
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // constraints_enabled
  if (lhs->constraints_enabled != rhs->constraints_enabled) {
    return false;
  }
  // terrain_revision
  if (lhs->terrain_revision != rhs->terrain_revision) {
    return false;
  }
  // parameter_revision
  if (lhs->parameter_revision != rhs->parameter_revision) {
    return false;
  }
  // map_revision
  if (lhs->map_revision != rhs->map_revision) {
    return false;
  }
  // path
  if (!nav_msgs__msg__Path__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  // path_length
  if (lhs->path_length != rhs->path_length) {
    return false;
  }
  // passages
  if (!nav_interfaces__msg__HoleTraversal__Sequence__are_equal(
      &(lhs->passages), &(rhs->passages)))
  {
    return false;
  }
  // speed_regions
  if (!nav_interfaces__msg__HoleSpeedRegion__Sequence__are_equal(
      &(lhs->speed_regions), &(rhs->speed_regions)))
  {
    return false;
  }
  return true;
}

bool
nav_interfaces__msg__NavigationPlan__copy(
  const nav_interfaces__msg__NavigationPlan * input,
  nav_interfaces__msg__NavigationPlan * output)
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
  // status
  output->status = input->status;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // constraints_enabled
  output->constraints_enabled = input->constraints_enabled;
  // terrain_revision
  output->terrain_revision = input->terrain_revision;
  // parameter_revision
  output->parameter_revision = input->parameter_revision;
  // map_revision
  output->map_revision = input->map_revision;
  // path
  if (!nav_msgs__msg__Path__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  // path_length
  output->path_length = input->path_length;
  // passages
  if (!nav_interfaces__msg__HoleTraversal__Sequence__copy(
      &(input->passages), &(output->passages)))
  {
    return false;
  }
  // speed_regions
  if (!nav_interfaces__msg__HoleSpeedRegion__Sequence__copy(
      &(input->speed_regions), &(output->speed_regions)))
  {
    return false;
  }
  return true;
}

nav_interfaces__msg__NavigationPlan *
nav_interfaces__msg__NavigationPlan__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__NavigationPlan * msg = (nav_interfaces__msg__NavigationPlan *)allocator.allocate(sizeof(nav_interfaces__msg__NavigationPlan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__msg__NavigationPlan));
  bool success = nav_interfaces__msg__NavigationPlan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__msg__NavigationPlan__destroy(nav_interfaces__msg__NavigationPlan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__msg__NavigationPlan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__msg__NavigationPlan__Sequence__init(nav_interfaces__msg__NavigationPlan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__NavigationPlan * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__msg__NavigationPlan)) {
      return false;
    }
    data = (nav_interfaces__msg__NavigationPlan *)allocator.zero_allocate(size, sizeof(nav_interfaces__msg__NavigationPlan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__msg__NavigationPlan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__msg__NavigationPlan__fini(&data[i - 1]);
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
nav_interfaces__msg__NavigationPlan__Sequence__fini(nav_interfaces__msg__NavigationPlan__Sequence * array)
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
      nav_interfaces__msg__NavigationPlan__fini(&array->data[i]);
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

nav_interfaces__msg__NavigationPlan__Sequence *
nav_interfaces__msg__NavigationPlan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__msg__NavigationPlan__Sequence * array = (nav_interfaces__msg__NavigationPlan__Sequence *)allocator.allocate(sizeof(nav_interfaces__msg__NavigationPlan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__msg__NavigationPlan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__msg__NavigationPlan__Sequence__destroy(nav_interfaces__msg__NavigationPlan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__msg__NavigationPlan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__msg__NavigationPlan__Sequence__are_equal(const nav_interfaces__msg__NavigationPlan__Sequence * lhs, const nav_interfaces__msg__NavigationPlan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__msg__NavigationPlan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__msg__NavigationPlan__Sequence__copy(
  const nav_interfaces__msg__NavigationPlan__Sequence * input,
  nav_interfaces__msg__NavigationPlan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__msg__NavigationPlan)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__msg__NavigationPlan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__msg__NavigationPlan * data =
      (nav_interfaces__msg__NavigationPlan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__msg__NavigationPlan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__msg__NavigationPlan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__msg__NavigationPlan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
