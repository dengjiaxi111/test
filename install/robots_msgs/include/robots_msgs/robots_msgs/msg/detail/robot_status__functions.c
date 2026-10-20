// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__RobotStatus__init(robots_msgs__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // x
  // y
  // angle
  // recovery_buff
  // defence_buff
  // vulnerability_buff
  // attack_buff
  // remaining_energy
  // projectile_allowance_17mm
  // fort_area
  // supply_blood_area
  // local_exchange_projectile_allowance_17mm
  // remote_exchange_projectile_times
  // remote_exchange_health_times
  // can_free_rebirth
  // can_instant_rebirth
  // rebirth_need_coin
  // ttk_status
  // projectile_allowance_17mm_remain
  // target_position_x
  // target_position_y
  return true;
}

void
robots_msgs__msg__RobotStatus__fini(robots_msgs__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // x
  // y
  // angle
  // recovery_buff
  // defence_buff
  // vulnerability_buff
  // attack_buff
  // remaining_energy
  // projectile_allowance_17mm
  // fort_area
  // supply_blood_area
  // local_exchange_projectile_allowance_17mm
  // remote_exchange_projectile_times
  // remote_exchange_health_times
  // can_free_rebirth
  // can_instant_rebirth
  // rebirth_need_coin
  // ttk_status
  // projectile_allowance_17mm_remain
  // target_position_x
  // target_position_y
}

bool
robots_msgs__msg__RobotStatus__are_equal(const robots_msgs__msg__RobotStatus * lhs, const robots_msgs__msg__RobotStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // recovery_buff
  if (lhs->recovery_buff != rhs->recovery_buff) {
    return false;
  }
  // defence_buff
  if (lhs->defence_buff != rhs->defence_buff) {
    return false;
  }
  // vulnerability_buff
  if (lhs->vulnerability_buff != rhs->vulnerability_buff) {
    return false;
  }
  // attack_buff
  if (lhs->attack_buff != rhs->attack_buff) {
    return false;
  }
  // remaining_energy
  if (lhs->remaining_energy != rhs->remaining_energy) {
    return false;
  }
  // projectile_allowance_17mm
  if (lhs->projectile_allowance_17mm != rhs->projectile_allowance_17mm) {
    return false;
  }
  // fort_area
  if (lhs->fort_area != rhs->fort_area) {
    return false;
  }
  // supply_blood_area
  if (lhs->supply_blood_area != rhs->supply_blood_area) {
    return false;
  }
  // local_exchange_projectile_allowance_17mm
  if (lhs->local_exchange_projectile_allowance_17mm != rhs->local_exchange_projectile_allowance_17mm) {
    return false;
  }
  // remote_exchange_projectile_times
  if (lhs->remote_exchange_projectile_times != rhs->remote_exchange_projectile_times) {
    return false;
  }
  // remote_exchange_health_times
  if (lhs->remote_exchange_health_times != rhs->remote_exchange_health_times) {
    return false;
  }
  // can_free_rebirth
  if (lhs->can_free_rebirth != rhs->can_free_rebirth) {
    return false;
  }
  // can_instant_rebirth
  if (lhs->can_instant_rebirth != rhs->can_instant_rebirth) {
    return false;
  }
  // rebirth_need_coin
  if (lhs->rebirth_need_coin != rhs->rebirth_need_coin) {
    return false;
  }
  // ttk_status
  if (lhs->ttk_status != rhs->ttk_status) {
    return false;
  }
  // projectile_allowance_17mm_remain
  if (lhs->projectile_allowance_17mm_remain != rhs->projectile_allowance_17mm_remain) {
    return false;
  }
  // target_position_x
  if (lhs->target_position_x != rhs->target_position_x) {
    return false;
  }
  // target_position_y
  if (lhs->target_position_y != rhs->target_position_y) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__RobotStatus__copy(
  const robots_msgs__msg__RobotStatus * input,
  robots_msgs__msg__RobotStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // angle
  output->angle = input->angle;
  // recovery_buff
  output->recovery_buff = input->recovery_buff;
  // defence_buff
  output->defence_buff = input->defence_buff;
  // vulnerability_buff
  output->vulnerability_buff = input->vulnerability_buff;
  // attack_buff
  output->attack_buff = input->attack_buff;
  // remaining_energy
  output->remaining_energy = input->remaining_energy;
  // projectile_allowance_17mm
  output->projectile_allowance_17mm = input->projectile_allowance_17mm;
  // fort_area
  output->fort_area = input->fort_area;
  // supply_blood_area
  output->supply_blood_area = input->supply_blood_area;
  // local_exchange_projectile_allowance_17mm
  output->local_exchange_projectile_allowance_17mm = input->local_exchange_projectile_allowance_17mm;
  // remote_exchange_projectile_times
  output->remote_exchange_projectile_times = input->remote_exchange_projectile_times;
  // remote_exchange_health_times
  output->remote_exchange_health_times = input->remote_exchange_health_times;
  // can_free_rebirth
  output->can_free_rebirth = input->can_free_rebirth;
  // can_instant_rebirth
  output->can_instant_rebirth = input->can_instant_rebirth;
  // rebirth_need_coin
  output->rebirth_need_coin = input->rebirth_need_coin;
  // ttk_status
  output->ttk_status = input->ttk_status;
  // projectile_allowance_17mm_remain
  output->projectile_allowance_17mm_remain = input->projectile_allowance_17mm_remain;
  // target_position_x
  output->target_position_x = input->target_position_x;
  // target_position_y
  output->target_position_y = input->target_position_y;
  return true;
}

robots_msgs__msg__RobotStatus *
robots_msgs__msg__RobotStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__RobotStatus * msg = (robots_msgs__msg__RobotStatus *)allocator.allocate(sizeof(robots_msgs__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__RobotStatus));
  bool success = robots_msgs__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__RobotStatus__destroy(robots_msgs__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__RobotStatus__Sequence__init(robots_msgs__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__RobotStatus * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__RobotStatus)) {
      return false;
    }
    data = (robots_msgs__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__RobotStatus__fini(&data[i - 1]);
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
robots_msgs__msg__RobotStatus__Sequence__fini(robots_msgs__msg__RobotStatus__Sequence * array)
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
      robots_msgs__msg__RobotStatus__fini(&array->data[i]);
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

robots_msgs__msg__RobotStatus__Sequence *
robots_msgs__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__RobotStatus__Sequence * array = (robots_msgs__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__RobotStatus__Sequence__destroy(robots_msgs__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__RobotStatus__Sequence__are_equal(const robots_msgs__msg__RobotStatus__Sequence * lhs, const robots_msgs__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__RobotStatus__Sequence__copy(
  const robots_msgs__msg__RobotStatus__Sequence * input,
  robots_msgs__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__RobotStatus)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__RobotStatus * data =
      (robots_msgs__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
