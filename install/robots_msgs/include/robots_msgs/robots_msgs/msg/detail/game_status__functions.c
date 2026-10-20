// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/game_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robots_msgs__msg__GameStatus__init(robots_msgs__msg__GameStatus * msg)
{
  if (!msg) {
    return false;
  }
  // game_type
  // game_progress
  // stage_remain_time
  // my_hp
  // my_outpost_hp
  // my_base_hp
  // our_hero_x
  // our_hero_y
  // enemy_1_robot_hp
  // enemy_2_robot_hp
  // enemy_3_robot_hp
  // enemy_4_robot_hp
  // enemy_5_robot_hp
  // enemy_7_robot_hp
  // enemy_outpost_hp
  // enemy_base_hp
  // external_supply_area_occupied
  // inner_supply_area_occupied
  // supply_area_occupied
  // our_small_buff_activated
  // our_big_buff_activated
  // our_fortress_status
  // remaining_gold_coin
  return true;
}

void
robots_msgs__msg__GameStatus__fini(robots_msgs__msg__GameStatus * msg)
{
  if (!msg) {
    return;
  }
  // game_type
  // game_progress
  // stage_remain_time
  // my_hp
  // my_outpost_hp
  // my_base_hp
  // our_hero_x
  // our_hero_y
  // enemy_1_robot_hp
  // enemy_2_robot_hp
  // enemy_3_robot_hp
  // enemy_4_robot_hp
  // enemy_5_robot_hp
  // enemy_7_robot_hp
  // enemy_outpost_hp
  // enemy_base_hp
  // external_supply_area_occupied
  // inner_supply_area_occupied
  // supply_area_occupied
  // our_small_buff_activated
  // our_big_buff_activated
  // our_fortress_status
  // remaining_gold_coin
}

bool
robots_msgs__msg__GameStatus__are_equal(const robots_msgs__msg__GameStatus * lhs, const robots_msgs__msg__GameStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // game_type
  if (lhs->game_type != rhs->game_type) {
    return false;
  }
  // game_progress
  if (lhs->game_progress != rhs->game_progress) {
    return false;
  }
  // stage_remain_time
  if (lhs->stage_remain_time != rhs->stage_remain_time) {
    return false;
  }
  // my_hp
  if (lhs->my_hp != rhs->my_hp) {
    return false;
  }
  // my_outpost_hp
  if (lhs->my_outpost_hp != rhs->my_outpost_hp) {
    return false;
  }
  // my_base_hp
  if (lhs->my_base_hp != rhs->my_base_hp) {
    return false;
  }
  // our_hero_x
  if (lhs->our_hero_x != rhs->our_hero_x) {
    return false;
  }
  // our_hero_y
  if (lhs->our_hero_y != rhs->our_hero_y) {
    return false;
  }
  // enemy_1_robot_hp
  if (lhs->enemy_1_robot_hp != rhs->enemy_1_robot_hp) {
    return false;
  }
  // enemy_2_robot_hp
  if (lhs->enemy_2_robot_hp != rhs->enemy_2_robot_hp) {
    return false;
  }
  // enemy_3_robot_hp
  if (lhs->enemy_3_robot_hp != rhs->enemy_3_robot_hp) {
    return false;
  }
  // enemy_4_robot_hp
  if (lhs->enemy_4_robot_hp != rhs->enemy_4_robot_hp) {
    return false;
  }
  // enemy_5_robot_hp
  if (lhs->enemy_5_robot_hp != rhs->enemy_5_robot_hp) {
    return false;
  }
  // enemy_7_robot_hp
  if (lhs->enemy_7_robot_hp != rhs->enemy_7_robot_hp) {
    return false;
  }
  // enemy_outpost_hp
  if (lhs->enemy_outpost_hp != rhs->enemy_outpost_hp) {
    return false;
  }
  // enemy_base_hp
  if (lhs->enemy_base_hp != rhs->enemy_base_hp) {
    return false;
  }
  // external_supply_area_occupied
  if (lhs->external_supply_area_occupied != rhs->external_supply_area_occupied) {
    return false;
  }
  // inner_supply_area_occupied
  if (lhs->inner_supply_area_occupied != rhs->inner_supply_area_occupied) {
    return false;
  }
  // supply_area_occupied
  if (lhs->supply_area_occupied != rhs->supply_area_occupied) {
    return false;
  }
  // our_small_buff_activated
  if (lhs->our_small_buff_activated != rhs->our_small_buff_activated) {
    return false;
  }
  // our_big_buff_activated
  if (lhs->our_big_buff_activated != rhs->our_big_buff_activated) {
    return false;
  }
  // our_fortress_status
  if (lhs->our_fortress_status != rhs->our_fortress_status) {
    return false;
  }
  // remaining_gold_coin
  if (lhs->remaining_gold_coin != rhs->remaining_gold_coin) {
    return false;
  }
  return true;
}

bool
robots_msgs__msg__GameStatus__copy(
  const robots_msgs__msg__GameStatus * input,
  robots_msgs__msg__GameStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // game_type
  output->game_type = input->game_type;
  // game_progress
  output->game_progress = input->game_progress;
  // stage_remain_time
  output->stage_remain_time = input->stage_remain_time;
  // my_hp
  output->my_hp = input->my_hp;
  // my_outpost_hp
  output->my_outpost_hp = input->my_outpost_hp;
  // my_base_hp
  output->my_base_hp = input->my_base_hp;
  // our_hero_x
  output->our_hero_x = input->our_hero_x;
  // our_hero_y
  output->our_hero_y = input->our_hero_y;
  // enemy_1_robot_hp
  output->enemy_1_robot_hp = input->enemy_1_robot_hp;
  // enemy_2_robot_hp
  output->enemy_2_robot_hp = input->enemy_2_robot_hp;
  // enemy_3_robot_hp
  output->enemy_3_robot_hp = input->enemy_3_robot_hp;
  // enemy_4_robot_hp
  output->enemy_4_robot_hp = input->enemy_4_robot_hp;
  // enemy_5_robot_hp
  output->enemy_5_robot_hp = input->enemy_5_robot_hp;
  // enemy_7_robot_hp
  output->enemy_7_robot_hp = input->enemy_7_robot_hp;
  // enemy_outpost_hp
  output->enemy_outpost_hp = input->enemy_outpost_hp;
  // enemy_base_hp
  output->enemy_base_hp = input->enemy_base_hp;
  // external_supply_area_occupied
  output->external_supply_area_occupied = input->external_supply_area_occupied;
  // inner_supply_area_occupied
  output->inner_supply_area_occupied = input->inner_supply_area_occupied;
  // supply_area_occupied
  output->supply_area_occupied = input->supply_area_occupied;
  // our_small_buff_activated
  output->our_small_buff_activated = input->our_small_buff_activated;
  // our_big_buff_activated
  output->our_big_buff_activated = input->our_big_buff_activated;
  // our_fortress_status
  output->our_fortress_status = input->our_fortress_status;
  // remaining_gold_coin
  output->remaining_gold_coin = input->remaining_gold_coin;
  return true;
}

robots_msgs__msg__GameStatus *
robots_msgs__msg__GameStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GameStatus * msg = (robots_msgs__msg__GameStatus *)allocator.allocate(sizeof(robots_msgs__msg__GameStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robots_msgs__msg__GameStatus));
  bool success = robots_msgs__msg__GameStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robots_msgs__msg__GameStatus__destroy(robots_msgs__msg__GameStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robots_msgs__msg__GameStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robots_msgs__msg__GameStatus__Sequence__init(robots_msgs__msg__GameStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GameStatus * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(robots_msgs__msg__GameStatus)) {
      return false;
    }
    data = (robots_msgs__msg__GameStatus *)allocator.zero_allocate(size, sizeof(robots_msgs__msg__GameStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robots_msgs__msg__GameStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robots_msgs__msg__GameStatus__fini(&data[i - 1]);
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
robots_msgs__msg__GameStatus__Sequence__fini(robots_msgs__msg__GameStatus__Sequence * array)
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
      robots_msgs__msg__GameStatus__fini(&array->data[i]);
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

robots_msgs__msg__GameStatus__Sequence *
robots_msgs__msg__GameStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robots_msgs__msg__GameStatus__Sequence * array = (robots_msgs__msg__GameStatus__Sequence *)allocator.allocate(sizeof(robots_msgs__msg__GameStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robots_msgs__msg__GameStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robots_msgs__msg__GameStatus__Sequence__destroy(robots_msgs__msg__GameStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robots_msgs__msg__GameStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robots_msgs__msg__GameStatus__Sequence__are_equal(const robots_msgs__msg__GameStatus__Sequence * lhs, const robots_msgs__msg__GameStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robots_msgs__msg__GameStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robots_msgs__msg__GameStatus__Sequence__copy(
  const robots_msgs__msg__GameStatus__Sequence * input,
  robots_msgs__msg__GameStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(robots_msgs__msg__GameStatus)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(robots_msgs__msg__GameStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robots_msgs__msg__GameStatus * data =
      (robots_msgs__msg__GameStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robots_msgs__msg__GameStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robots_msgs__msg__GameStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robots_msgs__msg__GameStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
