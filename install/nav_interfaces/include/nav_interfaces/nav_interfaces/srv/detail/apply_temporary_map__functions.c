// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice
#include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `expected_session_id`
// Member `expected_source_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `indices`
// Member `values`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
nav_interfaces__srv__ApplyTemporaryMap_Request__init(nav_interfaces__srv__ApplyTemporaryMap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // expected_session_id
  if (!rosidl_runtime_c__String__init(&msg->expected_session_id)) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__fini(msg);
    return false;
  }
  // expected_source_id
  if (!rosidl_runtime_c__String__init(&msg->expected_source_id)) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__fini(msg);
    return false;
  }
  // expected_map_revision
  // indices
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->indices, 0)) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__fini(msg);
    return false;
  }
  // values
  if (!rosidl_runtime_c__int8__Sequence__init(&msg->values, 0)) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__fini(msg);
    return false;
  }
  return true;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Request__fini(nav_interfaces__srv__ApplyTemporaryMap_Request * msg)
{
  if (!msg) {
    return;
  }
  // expected_session_id
  rosidl_runtime_c__String__fini(&msg->expected_session_id);
  // expected_source_id
  rosidl_runtime_c__String__fini(&msg->expected_source_id);
  // expected_map_revision
  // indices
  rosidl_runtime_c__uint32__Sequence__fini(&msg->indices);
  // values
  rosidl_runtime_c__int8__Sequence__fini(&msg->values);
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Request__are_equal(const nav_interfaces__srv__ApplyTemporaryMap_Request * lhs, const nav_interfaces__srv__ApplyTemporaryMap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // expected_session_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->expected_session_id), &(rhs->expected_session_id)))
  {
    return false;
  }
  // expected_source_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->expected_source_id), &(rhs->expected_source_id)))
  {
    return false;
  }
  // expected_map_revision
  if (lhs->expected_map_revision != rhs->expected_map_revision) {
    return false;
  }
  // indices
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->indices), &(rhs->indices)))
  {
    return false;
  }
  // values
  if (!rosidl_runtime_c__int8__Sequence__are_equal(
      &(lhs->values), &(rhs->values)))
  {
    return false;
  }
  return true;
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Request__copy(
  const nav_interfaces__srv__ApplyTemporaryMap_Request * input,
  nav_interfaces__srv__ApplyTemporaryMap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // expected_session_id
  if (!rosidl_runtime_c__String__copy(
      &(input->expected_session_id), &(output->expected_session_id)))
  {
    return false;
  }
  // expected_source_id
  if (!rosidl_runtime_c__String__copy(
      &(input->expected_source_id), &(output->expected_source_id)))
  {
    return false;
  }
  // expected_map_revision
  output->expected_map_revision = input->expected_map_revision;
  // indices
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->indices), &(output->indices)))
  {
    return false;
  }
  // values
  if (!rosidl_runtime_c__int8__Sequence__copy(
      &(input->values), &(output->values)))
  {
    return false;
  }
  return true;
}

nav_interfaces__srv__ApplyTemporaryMap_Request *
nav_interfaces__srv__ApplyTemporaryMap_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Request * msg = (nav_interfaces__srv__ApplyTemporaryMap_Request *)allocator.allocate(sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request));
  bool success = nav_interfaces__srv__ApplyTemporaryMap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Request__destroy(nav_interfaces__srv__ApplyTemporaryMap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request)) {
      return false;
    }
    data = (nav_interfaces__srv__ApplyTemporaryMap_Request *)allocator.zero_allocate(size, sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__srv__ApplyTemporaryMap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__srv__ApplyTemporaryMap_Request__fini(&data[i - 1]);
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
nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * array)
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
      nav_interfaces__srv__ApplyTemporaryMap_Request__fini(&array->data[i]);
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

nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence *
nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * array = (nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence *)allocator.allocate(sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__destroy(nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__are_equal(const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * lhs, const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__srv__ApplyTemporaryMap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__copy(
  const nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * input,
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__srv__ApplyTemporaryMap_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__srv__ApplyTemporaryMap_Request * data =
      (nav_interfaces__srv__ApplyTemporaryMap_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__srv__ApplyTemporaryMap_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__srv__ApplyTemporaryMap_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__srv__ApplyTemporaryMap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `reason`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
nav_interfaces__srv__ApplyTemporaryMap_Response__init(nav_interfaces__srv__ApplyTemporaryMap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    nav_interfaces__srv__ApplyTemporaryMap_Response__fini(msg);
    return false;
  }
  // map_revision
  // replanning_triggered
  return true;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Response__fini(nav_interfaces__srv__ApplyTemporaryMap_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // map_revision
  // replanning_triggered
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Response__are_equal(const nav_interfaces__srv__ApplyTemporaryMap_Response * lhs, const nav_interfaces__srv__ApplyTemporaryMap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // map_revision
  if (lhs->map_revision != rhs->map_revision) {
    return false;
  }
  // replanning_triggered
  if (lhs->replanning_triggered != rhs->replanning_triggered) {
    return false;
  }
  return true;
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Response__copy(
  const nav_interfaces__srv__ApplyTemporaryMap_Response * input,
  nav_interfaces__srv__ApplyTemporaryMap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // map_revision
  output->map_revision = input->map_revision;
  // replanning_triggered
  output->replanning_triggered = input->replanning_triggered;
  return true;
}

nav_interfaces__srv__ApplyTemporaryMap_Response *
nav_interfaces__srv__ApplyTemporaryMap_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Response * msg = (nav_interfaces__srv__ApplyTemporaryMap_Response *)allocator.allocate(sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response));
  bool success = nav_interfaces__srv__ApplyTemporaryMap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Response__destroy(nav_interfaces__srv__ApplyTemporaryMap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__srv__ApplyTemporaryMap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response)) {
      return false;
    }
    data = (nav_interfaces__srv__ApplyTemporaryMap_Response *)allocator.zero_allocate(size, sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__srv__ApplyTemporaryMap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__srv__ApplyTemporaryMap_Response__fini(&data[i - 1]);
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
nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * array)
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
      nav_interfaces__srv__ApplyTemporaryMap_Response__fini(&array->data[i]);
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

nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence *
nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * array = (nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence *)allocator.allocate(sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__destroy(nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__are_equal(const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * lhs, const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__srv__ApplyTemporaryMap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__copy(
  const nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * input,
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__srv__ApplyTemporaryMap_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__srv__ApplyTemporaryMap_Response * data =
      (nav_interfaces__srv__ApplyTemporaryMap_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__srv__ApplyTemporaryMap_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__srv__ApplyTemporaryMap_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__srv__ApplyTemporaryMap_Response__copy(
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
// #include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"

bool
nav_interfaces__srv__ApplyTemporaryMap_Event__init(nav_interfaces__srv__ApplyTemporaryMap_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    nav_interfaces__srv__ApplyTemporaryMap_Event__fini(msg);
    return false;
  }
  // request
  if (!nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(&msg->request, 0)) {
    nav_interfaces__srv__ApplyTemporaryMap_Event__fini(msg);
    return false;
  }
  // response
  if (!nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(&msg->response, 0)) {
    nav_interfaces__srv__ApplyTemporaryMap_Event__fini(msg);
    return false;
  }
  return true;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Event__fini(nav_interfaces__srv__ApplyTemporaryMap_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(&msg->request);
  // response
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(&msg->response);
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Event__are_equal(const nav_interfaces__srv__ApplyTemporaryMap_Event * lhs, const nav_interfaces__srv__ApplyTemporaryMap_Event * rhs)
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
  if (!nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Event__copy(
  const nav_interfaces__srv__ApplyTemporaryMap_Event * input,
  nav_interfaces__srv__ApplyTemporaryMap_Event * output)
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
  if (!nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

nav_interfaces__srv__ApplyTemporaryMap_Event *
nav_interfaces__srv__ApplyTemporaryMap_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Event * msg = (nav_interfaces__srv__ApplyTemporaryMap_Event *)allocator.allocate(sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event));
  bool success = nav_interfaces__srv__ApplyTemporaryMap_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Event__destroy(nav_interfaces__srv__ApplyTemporaryMap_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nav_interfaces__srv__ApplyTemporaryMap_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__init(nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event)) {
      return false;
    }
    data = (nav_interfaces__srv__ApplyTemporaryMap_Event *)allocator.zero_allocate(size, sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nav_interfaces__srv__ApplyTemporaryMap_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nav_interfaces__srv__ApplyTemporaryMap_Event__fini(&data[i - 1]);
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
nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__fini(nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * array)
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
      nav_interfaces__srv__ApplyTemporaryMap_Event__fini(&array->data[i]);
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

nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence *
nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * array = (nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence *)allocator.allocate(sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__destroy(nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__are_equal(const nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * lhs, const nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nav_interfaces__srv__ApplyTemporaryMap_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence__copy(
  const nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * input,
  nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(nav_interfaces__srv__ApplyTemporaryMap_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nav_interfaces__srv__ApplyTemporaryMap_Event * data =
      (nav_interfaces__srv__ApplyTemporaryMap_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nav_interfaces__srv__ApplyTemporaryMap_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nav_interfaces__srv__ApplyTemporaryMap_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nav_interfaces__srv__ApplyTemporaryMap_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
