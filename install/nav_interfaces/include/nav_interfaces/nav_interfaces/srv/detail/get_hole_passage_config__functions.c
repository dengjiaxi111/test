// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:srv/GetHolePassageConfig.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/srv/detail/get_hole_passage_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
nav_interfaces__srv__GetHolePassageConfig_Request__init(nav_interfaces__srv__GetHolePassageConfig_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
nav_interfaces__srv__GetHolePassageConfig_Request__fini(nav_interfaces__srv__GetHolePassageConfig_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
nav_interfaces__srv__GetHolePassageConfig_Request__are_equal(const nav_interfaces__srv__GetHolePassageConfig_Request * lhs, const nav_interfaces__srv__GetHolePassageConfig_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
nav_interfaces__srv__GetHolePassageConfig_Request__copy(
  const nav_interfaces__srv__GetHolePassageConfig_Request * input,
  nav_interfaces__srv__GetHolePassageConfig_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

nav_interfaces__srv__GetHolePassageConfig_Request *
nav_interfaces__srv__GetHolePassageConfig_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Request * msg = (nav_interfaces__srv__GetHolePassageConfig_Request *)allocator.allocate(sizeof(nav_interfaces__srv__GetHolePassageConfig_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__srv__GetHolePassageConfig_Request));
  bool success = nav_interfaces__srv__GetHolePassageConfig_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__srv__GetHolePassageConfig_Request__destroy(nav_interfaces__srv__GetHolePassageConfig_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__srv__GetHolePassageConfig_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__init(nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__srv__GetHolePassageConfig_Request)) {
      return false;
    }
    data = (nav_interfaces__srv__GetHolePassageConfig_Request *)allocator.zero_allocate(size, sizeof(nav_interfaces__srv__GetHolePassageConfig_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__srv__GetHolePassageConfig_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__srv__GetHolePassageConfig_Request__fini(&data[i - 1]);
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
nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__fini(nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * array)
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
      nav_interfaces__srv__GetHolePassageConfig_Request__fini(&array->data[i]);
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

nav_interfaces__srv__GetHolePassageConfig_Request__Sequence *
nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * array = (nav_interfaces__srv__GetHolePassageConfig_Request__Sequence *)allocator.allocate(sizeof(nav_interfaces__srv__GetHolePassageConfig_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__destroy(nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__are_equal(const nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * lhs, const nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__srv__GetHolePassageConfig_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__copy(
  const nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * input,
  nav_interfaces__srv__GetHolePassageConfig_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__srv__GetHolePassageConfig_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__srv__GetHolePassageConfig_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__srv__GetHolePassageConfig_Request * data =
      (nav_interfaces__srv__GetHolePassageConfig_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__srv__GetHolePassageConfig_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__srv__GetHolePassageConfig_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__srv__GetHolePassageConfig_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `reason`
// Member `config_yaml`
// Member `config_path`
// Member `terrain_path`
// Member `terrain_geometry`
#include "rosidl_runtime_c/string_functions.h"

bool
nav_interfaces__srv__GetHolePassageConfig_Response__init(nav_interfaces__srv__GetHolePassageConfig_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // manual_config_active
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    nav_interfaces__srv__GetHolePassageConfig_Response__fini(msg);
    return false;
  }
  // config_yaml
  if (!rosidl_runtime_c__String__init(&msg->config_yaml)) {
    nav_interfaces__srv__GetHolePassageConfig_Response__fini(msg);
    return false;
  }
  // config_path
  if (!rosidl_runtime_c__String__init(&msg->config_path)) {
    nav_interfaces__srv__GetHolePassageConfig_Response__fini(msg);
    return false;
  }
  // terrain_path
  if (!rosidl_runtime_c__String__init(&msg->terrain_path)) {
    nav_interfaces__srv__GetHolePassageConfig_Response__fini(msg);
    return false;
  }
  // terrain_geometry
  if (!rosidl_runtime_c__String__init(&msg->terrain_geometry)) {
    nav_interfaces__srv__GetHolePassageConfig_Response__fini(msg);
    return false;
  }
  // config_revision
  // terrain_revision
  return true;
}

void
nav_interfaces__srv__GetHolePassageConfig_Response__fini(nav_interfaces__srv__GetHolePassageConfig_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // manual_config_active
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // config_yaml
  rosidl_runtime_c__String__fini(&msg->config_yaml);
  // config_path
  rosidl_runtime_c__String__fini(&msg->config_path);
  // terrain_path
  rosidl_runtime_c__String__fini(&msg->terrain_path);
  // terrain_geometry
  rosidl_runtime_c__String__fini(&msg->terrain_geometry);
  // config_revision
  // terrain_revision
}

bool
nav_interfaces__srv__GetHolePassageConfig_Response__are_equal(const nav_interfaces__srv__GetHolePassageConfig_Response * lhs, const nav_interfaces__srv__GetHolePassageConfig_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // manual_config_active
  if (lhs->manual_config_active != rhs->manual_config_active) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // config_yaml
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->config_yaml), &(rhs->config_yaml)))
  {
    return false;
  }
  // config_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->config_path), &(rhs->config_path)))
  {
    return false;
  }
  // terrain_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->terrain_path), &(rhs->terrain_path)))
  {
    return false;
  }
  // terrain_geometry
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->terrain_geometry), &(rhs->terrain_geometry)))
  {
    return false;
  }
  // config_revision
  if (lhs->config_revision != rhs->config_revision) {
    return false;
  }
  // terrain_revision
  if (lhs->terrain_revision != rhs->terrain_revision) {
    return false;
  }
  return true;
}

bool
nav_interfaces__srv__GetHolePassageConfig_Response__copy(
  const nav_interfaces__srv__GetHolePassageConfig_Response * input,
  nav_interfaces__srv__GetHolePassageConfig_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // manual_config_active
  output->manual_config_active = input->manual_config_active;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // config_yaml
  if (!rosidl_runtime_c__String__copy(
      &(input->config_yaml), &(output->config_yaml)))
  {
    return false;
  }
  // config_path
  if (!rosidl_runtime_c__String__copy(
      &(input->config_path), &(output->config_path)))
  {
    return false;
  }
  // terrain_path
  if (!rosidl_runtime_c__String__copy(
      &(input->terrain_path), &(output->terrain_path)))
  {
    return false;
  }
  // terrain_geometry
  if (!rosidl_runtime_c__String__copy(
      &(input->terrain_geometry), &(output->terrain_geometry)))
  {
    return false;
  }
  // config_revision
  output->config_revision = input->config_revision;
  // terrain_revision
  output->terrain_revision = input->terrain_revision;
  return true;
}

nav_interfaces__srv__GetHolePassageConfig_Response *
nav_interfaces__srv__GetHolePassageConfig_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Response * msg = (nav_interfaces__srv__GetHolePassageConfig_Response *)allocator.allocate(sizeof(nav_interfaces__srv__GetHolePassageConfig_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__srv__GetHolePassageConfig_Response));
  bool success = nav_interfaces__srv__GetHolePassageConfig_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__srv__GetHolePassageConfig_Response__destroy(nav_interfaces__srv__GetHolePassageConfig_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__srv__GetHolePassageConfig_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__init(nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__srv__GetHolePassageConfig_Response)) {
      return false;
    }
    data = (nav_interfaces__srv__GetHolePassageConfig_Response *)allocator.zero_allocate(size, sizeof(nav_interfaces__srv__GetHolePassageConfig_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__srv__GetHolePassageConfig_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__srv__GetHolePassageConfig_Response__fini(&data[i - 1]);
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
nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__fini(nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * array)
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
      nav_interfaces__srv__GetHolePassageConfig_Response__fini(&array->data[i]);
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

nav_interfaces__srv__GetHolePassageConfig_Response__Sequence *
nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * array = (nav_interfaces__srv__GetHolePassageConfig_Response__Sequence *)allocator.allocate(sizeof(nav_interfaces__srv__GetHolePassageConfig_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__destroy(nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__are_equal(const nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * lhs, const nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__srv__GetHolePassageConfig_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__copy(
  const nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * input,
  nav_interfaces__srv__GetHolePassageConfig_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__srv__GetHolePassageConfig_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__srv__GetHolePassageConfig_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__srv__GetHolePassageConfig_Response * data =
      (nav_interfaces__srv__GetHolePassageConfig_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__srv__GetHolePassageConfig_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__srv__GetHolePassageConfig_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__srv__GetHolePassageConfig_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "nav_interfaces/srv/detail/get_hole_passage_config__functions.h"

bool
nav_interfaces__srv__GetHolePassageConfig_Event__init(nav_interfaces__srv__GetHolePassageConfig_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    nav_interfaces__srv__GetHolePassageConfig_Event__fini(msg);
    return false;
  }
  // request
  if (!nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__init(&msg->request, 0)) {
    nav_interfaces__srv__GetHolePassageConfig_Event__fini(msg);
    return false;
  }
  // response
  if (!nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__init(&msg->response, 0)) {
    nav_interfaces__srv__GetHolePassageConfig_Event__fini(msg);
    return false;
  }
  return true;
}

void
nav_interfaces__srv__GetHolePassageConfig_Event__fini(nav_interfaces__srv__GetHolePassageConfig_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__fini(&msg->request);
  // response
  nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__fini(&msg->response);
}

bool
nav_interfaces__srv__GetHolePassageConfig_Event__are_equal(const nav_interfaces__srv__GetHolePassageConfig_Event * lhs, const nav_interfaces__srv__GetHolePassageConfig_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
nav_interfaces__srv__GetHolePassageConfig_Event__copy(
  const nav_interfaces__srv__GetHolePassageConfig_Event * input,
  nav_interfaces__srv__GetHolePassageConfig_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

nav_interfaces__srv__GetHolePassageConfig_Event *
nav_interfaces__srv__GetHolePassageConfig_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Event * msg = (nav_interfaces__srv__GetHolePassageConfig_Event *)allocator.allocate(sizeof(nav_interfaces__srv__GetHolePassageConfig_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__srv__GetHolePassageConfig_Event));
  bool success = nav_interfaces__srv__GetHolePassageConfig_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__srv__GetHolePassageConfig_Event__destroy(nav_interfaces__srv__GetHolePassageConfig_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__srv__GetHolePassageConfig_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__init(nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__srv__GetHolePassageConfig_Event)) {
      return false;
    }
    data = (nav_interfaces__srv__GetHolePassageConfig_Event *)allocator.zero_allocate(size, sizeof(nav_interfaces__srv__GetHolePassageConfig_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__srv__GetHolePassageConfig_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__srv__GetHolePassageConfig_Event__fini(&data[i - 1]);
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
nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__fini(nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * array)
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
      nav_interfaces__srv__GetHolePassageConfig_Event__fini(&array->data[i]);
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

nav_interfaces__srv__GetHolePassageConfig_Event__Sequence *
nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * array = (nav_interfaces__srv__GetHolePassageConfig_Event__Sequence *)allocator.allocate(sizeof(nav_interfaces__srv__GetHolePassageConfig_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__destroy(nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__are_equal(const nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * lhs, const nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__srv__GetHolePassageConfig_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__srv__GetHolePassageConfig_Event__Sequence__copy(
  const nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * input,
  nav_interfaces__srv__GetHolePassageConfig_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__srv__GetHolePassageConfig_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__srv__GetHolePassageConfig_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__srv__GetHolePassageConfig_Event * data =
      (nav_interfaces__srv__GetHolePassageConfig_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__srv__GetHolePassageConfig_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__srv__GetHolePassageConfig_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__srv__GetHolePassageConfig_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
