// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/enemy_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__EnemyPose__init(robots_msgs__msg__EnemyPose * msg)
{
  if (!msg) {
    return false;
  }
  // enemy_dist
  // enemy_ori
  // enemy_num
  // enemy_x
  // enemy_y
  return true;
}

void
robots_msgs__msg__EnemyPose__fini(robots_msgs__msg__EnemyPose * msg)
{
  if (!msg) {
    return;
  }
  // enemy_dist
  // enemy_ori
  // enemy_num
  // enemy_x
  // enemy_y
}

bool
robots_msgs__msg__EnemyPose__are_equal(const robots_msgs__msg__EnemyPose * lhs, const robots_msgs__msg__EnemyPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enemy_dist
  if (lhs->enemy_dist != rhs->enemy_dist) {
    return false;
  }
  // enemy_ori
  if (lhs->enemy_ori != rhs->enemy_ori) {
    return false;
  }
  // enemy_num
  if (lhs->enemy_num != rhs->enemy_num) {
    return false;
  }
  // enemy_x
  if (lhs->enemy_x != rhs->enemy_x) {
    return false;
  }
  // enemy_y
  if (lhs->enemy_y != rhs->enemy_y) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__EnemyPose__copy(
  const robots_msgs__msg__EnemyPose * input,
  robots_msgs__msg__EnemyPose * output)
{
  if (!input || !output) {
    return false;
  }
  // enemy_dist
  output->enemy_dist = input->enemy_dist;
  // enemy_ori
  output->enemy_ori = input->enemy_ori;
  // enemy_num
  output->enemy_num = input->enemy_num;
  // enemy_x
  output->enemy_x = input->enemy_x;
  // enemy_y
  output->enemy_y = input->enemy_y;
  return true;
}

robots_msgs__msg__EnemyPose *
robots_msgs__msg__EnemyPose__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__EnemyPose * msg = (robots_msgs__msg__EnemyPose *)allocator.allocate(sizeof(robots_msgs__msg__EnemyPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__EnemyPose));
  bool success = robots_msgs__msg__EnemyPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__EnemyPose__destroy(robots_msgs__msg__EnemyPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__EnemyPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__EnemyPose__Sequence__init(robots_msgs__msg__EnemyPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__EnemyPose * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__EnemyPose)) {
      return false;
    }
    data = (robots_msgs__msg__EnemyPose *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__EnemyPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__EnemyPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__EnemyPose__fini(&data[i - 1]);
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
robots_msgs__msg__EnemyPose__Sequence__fini(robots_msgs__msg__EnemyPose__Sequence * array)
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
      robots_msgs__msg__EnemyPose__fini(&array->data[i]);
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

robots_msgs__msg__EnemyPose__Sequence *
robots_msgs__msg__EnemyPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__EnemyPose__Sequence * array = (robots_msgs__msg__EnemyPose__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__EnemyPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__EnemyPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__EnemyPose__Sequence__destroy(robots_msgs__msg__EnemyPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__EnemyPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__EnemyPose__Sequence__are_equal(const robots_msgs__msg__EnemyPose__Sequence * lhs, const robots_msgs__msg__EnemyPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__EnemyPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__EnemyPose__Sequence__copy(
  const robots_msgs__msg__EnemyPose__Sequence * input,
  robots_msgs__msg__EnemyPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__EnemyPose)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__EnemyPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__EnemyPose * data =
      (robots_msgs__msg__EnemyPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__EnemyPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__EnemyPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__EnemyPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
