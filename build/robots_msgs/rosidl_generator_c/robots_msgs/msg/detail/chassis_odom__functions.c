// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/chassis_odom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__ChassisOdom__init(robots_msgs__msg__ChassisOdom * msg)
{
  if (!msg) {
    return false;
  }
  // speed_x
  // speed_y
  // speed_w
  // gimbal_angle
  // capacitor_voltage
  return true;
}

void
robots_msgs__msg__ChassisOdom__fini(robots_msgs__msg__ChassisOdom * msg)
{
  if (!msg) {
    return;
  }
  // speed_x
  // speed_y
  // speed_w
  // gimbal_angle
  // capacitor_voltage
}

bool
robots_msgs__msg__ChassisOdom__are_equal(const robots_msgs__msg__ChassisOdom * lhs, const robots_msgs__msg__ChassisOdom * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // speed_x
  if (lhs->speed_x != rhs->speed_x) {
    return false;
  }
  // speed_y
  if (lhs->speed_y != rhs->speed_y) {
    return false;
  }
  // speed_w
  if (lhs->speed_w != rhs->speed_w) {
    return false;
  }
  // gimbal_angle
  if (lhs->gimbal_angle != rhs->gimbal_angle) {
    return false;
  }
  // capacitor_voltage
  if (lhs->capacitor_voltage != rhs->capacitor_voltage) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__ChassisOdom__copy(
  const robots_msgs__msg__ChassisOdom * input,
  robots_msgs__msg__ChassisOdom * output)
{
  if (!input || !output) {
    return false;
  }
  // speed_x
  output->speed_x = input->speed_x;
  // speed_y
  output->speed_y = input->speed_y;
  // speed_w
  output->speed_w = input->speed_w;
  // gimbal_angle
  output->gimbal_angle = input->gimbal_angle;
  // capacitor_voltage
  output->capacitor_voltage = input->capacitor_voltage;
  return true;
}

robots_msgs__msg__ChassisOdom *
robots_msgs__msg__ChassisOdom__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__ChassisOdom * msg = (robots_msgs__msg__ChassisOdom *)allocator.allocate(sizeof(robots_msgs__msg__ChassisOdom), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__ChassisOdom));
  bool success = robots_msgs__msg__ChassisOdom__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__ChassisOdom__destroy(robots_msgs__msg__ChassisOdom * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__ChassisOdom__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__ChassisOdom__Sequence__init(robots_msgs__msg__ChassisOdom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__ChassisOdom * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__ChassisOdom)) {
      return false;
    }
    data = (robots_msgs__msg__ChassisOdom *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__ChassisOdom), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__ChassisOdom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__ChassisOdom__fini(&data[i - 1]);
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
robots_msgs__msg__ChassisOdom__Sequence__fini(robots_msgs__msg__ChassisOdom__Sequence * array)
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
      robots_msgs__msg__ChassisOdom__fini(&array->data[i]);
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

robots_msgs__msg__ChassisOdom__Sequence *
robots_msgs__msg__ChassisOdom__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__ChassisOdom__Sequence * array = (robots_msgs__msg__ChassisOdom__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__ChassisOdom__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__ChassisOdom__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__ChassisOdom__Sequence__destroy(robots_msgs__msg__ChassisOdom__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__ChassisOdom__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__ChassisOdom__Sequence__are_equal(const robots_msgs__msg__ChassisOdom__Sequence * lhs, const robots_msgs__msg__ChassisOdom__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__ChassisOdom__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__ChassisOdom__Sequence__copy(
  const robots_msgs__msg__ChassisOdom__Sequence * input,
  robots_msgs__msg__ChassisOdom__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__ChassisOdom)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__ChassisOdom);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__ChassisOdom * data =
      (robots_msgs__msg__ChassisOdom *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__ChassisOdom__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__ChassisOdom__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__ChassisOdom__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
