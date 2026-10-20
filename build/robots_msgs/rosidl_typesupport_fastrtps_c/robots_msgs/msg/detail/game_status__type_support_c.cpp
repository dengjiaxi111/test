// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/game_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robots_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robots_msgs/msg/detail/game_status__struct.h"
#include "robots_msgs/msg/detail/game_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GameStatus__ros_msg_type = robots_msgs__msg__GameStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_robots_msgs__msg__GameStatus(
  const robots_msgs__msg__GameStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: game_type
  {
    cdr << ros_message->game_type;
  }

  // Field name: game_progress
  {
    cdr << ros_message->game_progress;
  }

  // Field name: stage_remain_time
  {
    cdr << ros_message->stage_remain_time;
  }

  // Field name: my_hp
  {
    cdr << ros_message->my_hp;
  }

  // Field name: my_outpost_hp
  {
    cdr << ros_message->my_outpost_hp;
  }

  // Field name: my_base_hp
  {
    cdr << ros_message->my_base_hp;
  }

  // Field name: our_hero_x
  {
    cdr << ros_message->our_hero_x;
  }

  // Field name: our_hero_y
  {
    cdr << ros_message->our_hero_y;
  }

  // Field name: enemy_1_robot_hp
  {
    cdr << ros_message->enemy_1_robot_hp;
  }

  // Field name: enemy_2_robot_hp
  {
    cdr << ros_message->enemy_2_robot_hp;
  }

  // Field name: enemy_3_robot_hp
  {
    cdr << ros_message->enemy_3_robot_hp;
  }

  // Field name: enemy_4_robot_hp
  {
    cdr << ros_message->enemy_4_robot_hp;
  }

  // Field name: enemy_5_robot_hp
  {
    cdr << ros_message->enemy_5_robot_hp;
  }

  // Field name: enemy_7_robot_hp
  {
    cdr << ros_message->enemy_7_robot_hp;
  }

  // Field name: enemy_outpost_hp
  {
    cdr << ros_message->enemy_outpost_hp;
  }

  // Field name: enemy_base_hp
  {
    cdr << ros_message->enemy_base_hp;
  }

  // Field name: external_supply_area_occupied
  {
    cdr << ros_message->external_supply_area_occupied;
  }

  // Field name: inner_supply_area_occupied
  {
    cdr << ros_message->inner_supply_area_occupied;
  }

  // Field name: supply_area_occupied
  {
    cdr << ros_message->supply_area_occupied;
  }

  // Field name: our_small_buff_activated
  {
    cdr << ros_message->our_small_buff_activated;
  }

  // Field name: our_big_buff_activated
  {
    cdr << ros_message->our_big_buff_activated;
  }

  // Field name: our_fortress_status
  {
    cdr << ros_message->our_fortress_status;
  }

  // Field name: remaining_gold_coin
  {
    cdr << ros_message->remaining_gold_coin;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_deserialize_robots_msgs__msg__GameStatus(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs__msg__GameStatus * ros_message)
{
  // Field name: game_type
  {
    cdr >> ros_message->game_type;
  }

  // Field name: game_progress
  {
    cdr >> ros_message->game_progress;
  }

  // Field name: stage_remain_time
  {
    cdr >> ros_message->stage_remain_time;
  }

  // Field name: my_hp
  {
    cdr >> ros_message->my_hp;
  }

  // Field name: my_outpost_hp
  {
    cdr >> ros_message->my_outpost_hp;
  }

  // Field name: my_base_hp
  {
    cdr >> ros_message->my_base_hp;
  }

  // Field name: our_hero_x
  {
    cdr >> ros_message->our_hero_x;
  }

  // Field name: our_hero_y
  {
    cdr >> ros_message->our_hero_y;
  }

  // Field name: enemy_1_robot_hp
  {
    cdr >> ros_message->enemy_1_robot_hp;
  }

  // Field name: enemy_2_robot_hp
  {
    cdr >> ros_message->enemy_2_robot_hp;
  }

  // Field name: enemy_3_robot_hp
  {
    cdr >> ros_message->enemy_3_robot_hp;
  }

  // Field name: enemy_4_robot_hp
  {
    cdr >> ros_message->enemy_4_robot_hp;
  }

  // Field name: enemy_5_robot_hp
  {
    cdr >> ros_message->enemy_5_robot_hp;
  }

  // Field name: enemy_7_robot_hp
  {
    cdr >> ros_message->enemy_7_robot_hp;
  }

  // Field name: enemy_outpost_hp
  {
    cdr >> ros_message->enemy_outpost_hp;
  }

  // Field name: enemy_base_hp
  {
    cdr >> ros_message->enemy_base_hp;
  }

  // Field name: external_supply_area_occupied
  {
    cdr >> ros_message->external_supply_area_occupied;
  }

  // Field name: inner_supply_area_occupied
  {
    cdr >> ros_message->inner_supply_area_occupied;
  }

  // Field name: supply_area_occupied
  {
    cdr >> ros_message->supply_area_occupied;
  }

  // Field name: our_small_buff_activated
  {
    cdr >> ros_message->our_small_buff_activated;
  }

  // Field name: our_big_buff_activated
  {
    cdr >> ros_message->our_big_buff_activated;
  }

  // Field name: our_fortress_status
  {
    cdr >> ros_message->our_fortress_status;
  }

  // Field name: remaining_gold_coin
  {
    cdr >> ros_message->remaining_gold_coin;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_robots_msgs__msg__GameStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GameStatus__ros_msg_type * ros_message = static_cast<const _GameStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: game_type
  {
    size_t item_size = sizeof(ros_message->game_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: game_progress
  {
    size_t item_size = sizeof(ros_message->game_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: stage_remain_time
  {
    size_t item_size = sizeof(ros_message->stage_remain_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: my_hp
  {
    size_t item_size = sizeof(ros_message->my_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: my_outpost_hp
  {
    size_t item_size = sizeof(ros_message->my_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: my_base_hp
  {
    size_t item_size = sizeof(ros_message->my_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_hero_x
  {
    size_t item_size = sizeof(ros_message->our_hero_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_hero_y
  {
    size_t item_size = sizeof(ros_message->our_hero_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_1_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_2_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_3_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_4_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_5_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_7_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_outpost_hp
  {
    size_t item_size = sizeof(ros_message->enemy_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_base_hp
  {
    size_t item_size = sizeof(ros_message->enemy_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: external_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message->external_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: inner_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message->inner_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: supply_area_occupied
  {
    size_t item_size = sizeof(ros_message->supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_small_buff_activated
  {
    size_t item_size = sizeof(ros_message->our_small_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_big_buff_activated
  {
    size_t item_size = sizeof(ros_message->our_big_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_fortress_status
  {
    size_t item_size = sizeof(ros_message->our_fortress_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: remaining_gold_coin
  {
    size_t item_size = sizeof(ros_message->remaining_gold_coin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_robots_msgs__msg__GameStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: game_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: game_progress
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: stage_remain_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: my_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: my_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: my_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: our_hero_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: our_hero_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_1_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_2_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_3_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_4_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_5_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_7_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: external_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: inner_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: our_small_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: our_big_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: our_fortress_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: remaining_gold_coin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robots_msgs__msg__GameStatus;
    is_plain =
      (
      offsetof(DataType, remaining_gold_coin) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
bool cdr_serialize_key_robots_msgs__msg__GameStatus(
  const robots_msgs__msg__GameStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: game_type
  {
    cdr << ros_message->game_type;
  }

  // Field name: game_progress
  {
    cdr << ros_message->game_progress;
  }

  // Field name: stage_remain_time
  {
    cdr << ros_message->stage_remain_time;
  }

  // Field name: my_hp
  {
    cdr << ros_message->my_hp;
  }

  // Field name: my_outpost_hp
  {
    cdr << ros_message->my_outpost_hp;
  }

  // Field name: my_base_hp
  {
    cdr << ros_message->my_base_hp;
  }

  // Field name: our_hero_x
  {
    cdr << ros_message->our_hero_x;
  }

  // Field name: our_hero_y
  {
    cdr << ros_message->our_hero_y;
  }

  // Field name: enemy_1_robot_hp
  {
    cdr << ros_message->enemy_1_robot_hp;
  }

  // Field name: enemy_2_robot_hp
  {
    cdr << ros_message->enemy_2_robot_hp;
  }

  // Field name: enemy_3_robot_hp
  {
    cdr << ros_message->enemy_3_robot_hp;
  }

  // Field name: enemy_4_robot_hp
  {
    cdr << ros_message->enemy_4_robot_hp;
  }

  // Field name: enemy_5_robot_hp
  {
    cdr << ros_message->enemy_5_robot_hp;
  }

  // Field name: enemy_7_robot_hp
  {
    cdr << ros_message->enemy_7_robot_hp;
  }

  // Field name: enemy_outpost_hp
  {
    cdr << ros_message->enemy_outpost_hp;
  }

  // Field name: enemy_base_hp
  {
    cdr << ros_message->enemy_base_hp;
  }

  // Field name: external_supply_area_occupied
  {
    cdr << ros_message->external_supply_area_occupied;
  }

  // Field name: inner_supply_area_occupied
  {
    cdr << ros_message->inner_supply_area_occupied;
  }

  // Field name: supply_area_occupied
  {
    cdr << ros_message->supply_area_occupied;
  }

  // Field name: our_small_buff_activated
  {
    cdr << ros_message->our_small_buff_activated;
  }

  // Field name: our_big_buff_activated
  {
    cdr << ros_message->our_big_buff_activated;
  }

  // Field name: our_fortress_status
  {
    cdr << ros_message->our_fortress_status;
  }

  // Field name: remaining_gold_coin
  {
    cdr << ros_message->remaining_gold_coin;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t get_serialized_size_key_robots_msgs__msg__GameStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GameStatus__ros_msg_type * ros_message = static_cast<const _GameStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: game_type
  {
    size_t item_size = sizeof(ros_message->game_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: game_progress
  {
    size_t item_size = sizeof(ros_message->game_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: stage_remain_time
  {
    size_t item_size = sizeof(ros_message->stage_remain_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: my_hp
  {
    size_t item_size = sizeof(ros_message->my_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: my_outpost_hp
  {
    size_t item_size = sizeof(ros_message->my_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: my_base_hp
  {
    size_t item_size = sizeof(ros_message->my_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_hero_x
  {
    size_t item_size = sizeof(ros_message->our_hero_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_hero_y
  {
    size_t item_size = sizeof(ros_message->our_hero_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_1_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_2_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_3_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_4_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_5_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_7_robot_hp
  {
    size_t item_size = sizeof(ros_message->enemy_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_outpost_hp
  {
    size_t item_size = sizeof(ros_message->enemy_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enemy_base_hp
  {
    size_t item_size = sizeof(ros_message->enemy_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: external_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message->external_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: inner_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message->inner_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: supply_area_occupied
  {
    size_t item_size = sizeof(ros_message->supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_small_buff_activated
  {
    size_t item_size = sizeof(ros_message->our_small_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_big_buff_activated
  {
    size_t item_size = sizeof(ros_message->our_big_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: our_fortress_status
  {
    size_t item_size = sizeof(ros_message->our_fortress_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: remaining_gold_coin
  {
    size_t item_size = sizeof(ros_message->remaining_gold_coin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robots_msgs
size_t max_serialized_size_key_robots_msgs__msg__GameStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: game_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: game_progress
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: stage_remain_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: my_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: my_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: my_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: our_hero_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: our_hero_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enemy_1_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_2_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_3_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_4_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_5_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_7_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: enemy_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: external_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: inner_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: our_small_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: our_big_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: our_fortress_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: remaining_gold_coin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robots_msgs__msg__GameStatus;
    is_plain =
      (
      offsetof(DataType, remaining_gold_coin) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GameStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robots_msgs__msg__GameStatus * ros_message = static_cast<const robots_msgs__msg__GameStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robots_msgs__msg__GameStatus(ros_message, cdr);
}

static bool _GameStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robots_msgs__msg__GameStatus * ros_message = static_cast<robots_msgs__msg__GameStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robots_msgs__msg__GameStatus(cdr, ros_message);
}

static uint32_t _GameStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robots_msgs__msg__GameStatus(
      untyped_ros_message, 0));
}

static size_t _GameStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robots_msgs__msg__GameStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GameStatus = {
  "robots_msgs::msg",
  "GameStatus",
  _GameStatus__cdr_serialize,
  _GameStatus__cdr_deserialize,
  _GameStatus__get_serialized_size,
  _GameStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GameStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GameStatus,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__GameStatus__get_type_hash,
  &robots_msgs__msg__GameStatus__get_type_description,
  &robots_msgs__msg__GameStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robots_msgs, msg, GameStatus)() {
  return &_GameStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
