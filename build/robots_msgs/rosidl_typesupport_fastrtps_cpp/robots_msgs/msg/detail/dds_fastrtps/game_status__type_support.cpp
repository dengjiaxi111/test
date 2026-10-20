// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice
#include "robots_msgs/msg/detail/game_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robots_msgs/msg/detail/game_status__functions.h"
#include "robots_msgs/msg/detail/game_status__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace robots_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_serialize(
  const robots_msgs::msg::GameStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: game_type
  cdr << ros_message.game_type;

  // Member: game_progress
  cdr << ros_message.game_progress;

  // Member: stage_remain_time
  cdr << ros_message.stage_remain_time;

  // Member: my_hp
  cdr << ros_message.my_hp;

  // Member: my_outpost_hp
  cdr << ros_message.my_outpost_hp;

  // Member: my_base_hp
  cdr << ros_message.my_base_hp;

  // Member: our_hero_x
  cdr << ros_message.our_hero_x;

  // Member: our_hero_y
  cdr << ros_message.our_hero_y;

  // Member: enemy_1_robot_hp
  cdr << ros_message.enemy_1_robot_hp;

  // Member: enemy_2_robot_hp
  cdr << ros_message.enemy_2_robot_hp;

  // Member: enemy_3_robot_hp
  cdr << ros_message.enemy_3_robot_hp;

  // Member: enemy_4_robot_hp
  cdr << ros_message.enemy_4_robot_hp;

  // Member: enemy_5_robot_hp
  cdr << ros_message.enemy_5_robot_hp;

  // Member: enemy_7_robot_hp
  cdr << ros_message.enemy_7_robot_hp;

  // Member: enemy_outpost_hp
  cdr << ros_message.enemy_outpost_hp;

  // Member: enemy_base_hp
  cdr << ros_message.enemy_base_hp;

  // Member: external_supply_area_occupied
  cdr << ros_message.external_supply_area_occupied;

  // Member: inner_supply_area_occupied
  cdr << ros_message.inner_supply_area_occupied;

  // Member: supply_area_occupied
  cdr << ros_message.supply_area_occupied;

  // Member: our_small_buff_activated
  cdr << ros_message.our_small_buff_activated;

  // Member: our_big_buff_activated
  cdr << ros_message.our_big_buff_activated;

  // Member: our_fortress_status
  cdr << ros_message.our_fortress_status;

  // Member: remaining_gold_coin
  cdr << ros_message.remaining_gold_coin;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robots_msgs::msg::GameStatus & ros_message)
{
  // Member: game_type
  cdr >> ros_message.game_type;

  // Member: game_progress
  cdr >> ros_message.game_progress;

  // Member: stage_remain_time
  cdr >> ros_message.stage_remain_time;

  // Member: my_hp
  cdr >> ros_message.my_hp;

  // Member: my_outpost_hp
  cdr >> ros_message.my_outpost_hp;

  // Member: my_base_hp
  cdr >> ros_message.my_base_hp;

  // Member: our_hero_x
  cdr >> ros_message.our_hero_x;

  // Member: our_hero_y
  cdr >> ros_message.our_hero_y;

  // Member: enemy_1_robot_hp
  cdr >> ros_message.enemy_1_robot_hp;

  // Member: enemy_2_robot_hp
  cdr >> ros_message.enemy_2_robot_hp;

  // Member: enemy_3_robot_hp
  cdr >> ros_message.enemy_3_robot_hp;

  // Member: enemy_4_robot_hp
  cdr >> ros_message.enemy_4_robot_hp;

  // Member: enemy_5_robot_hp
  cdr >> ros_message.enemy_5_robot_hp;

  // Member: enemy_7_robot_hp
  cdr >> ros_message.enemy_7_robot_hp;

  // Member: enemy_outpost_hp
  cdr >> ros_message.enemy_outpost_hp;

  // Member: enemy_base_hp
  cdr >> ros_message.enemy_base_hp;

  // Member: external_supply_area_occupied
  cdr >> ros_message.external_supply_area_occupied;

  // Member: inner_supply_area_occupied
  cdr >> ros_message.inner_supply_area_occupied;

  // Member: supply_area_occupied
  cdr >> ros_message.supply_area_occupied;

  // Member: our_small_buff_activated
  cdr >> ros_message.our_small_buff_activated;

  // Member: our_big_buff_activated
  cdr >> ros_message.our_big_buff_activated;

  // Member: our_fortress_status
  cdr >> ros_message.our_fortress_status;

  // Member: remaining_gold_coin
  cdr >> ros_message.remaining_gold_coin;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size(
  const robots_msgs::msg::GameStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: game_type
  {
    size_t item_size = sizeof(ros_message.game_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: game_progress
  {
    size_t item_size = sizeof(ros_message.game_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: stage_remain_time
  {
    size_t item_size = sizeof(ros_message.stage_remain_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: my_hp
  {
    size_t item_size = sizeof(ros_message.my_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: my_outpost_hp
  {
    size_t item_size = sizeof(ros_message.my_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: my_base_hp
  {
    size_t item_size = sizeof(ros_message.my_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_hero_x
  {
    size_t item_size = sizeof(ros_message.our_hero_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_hero_y
  {
    size_t item_size = sizeof(ros_message.our_hero_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_5_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_outpost_hp
  {
    size_t item_size = sizeof(ros_message.enemy_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_base_hp
  {
    size_t item_size = sizeof(ros_message.enemy_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: external_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message.external_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: inner_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message.inner_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: supply_area_occupied
  {
    size_t item_size = sizeof(ros_message.supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_small_buff_activated
  {
    size_t item_size = sizeof(ros_message.our_small_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_big_buff_activated
  {
    size_t item_size = sizeof(ros_message.our_big_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_fortress_status
  {
    size_t item_size = sizeof(ros_message.our_fortress_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: remaining_gold_coin
  {
    size_t item_size = sizeof(ros_message.remaining_gold_coin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_GameStatus(
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

  // Member: game_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: game_progress
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: stage_remain_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: my_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: my_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: my_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: our_hero_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: our_hero_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: enemy_1_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_2_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_3_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_4_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_5_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_7_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: enemy_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: external_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: inner_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: our_small_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: our_big_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: our_fortress_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: remaining_gold_coin
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
    using DataType = robots_msgs::msg::GameStatus;
    is_plain =
      (
      offsetof(DataType, remaining_gold_coin) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
cdr_serialize_key(
  const robots_msgs::msg::GameStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: game_type
  cdr << ros_message.game_type;

  // Member: game_progress
  cdr << ros_message.game_progress;

  // Member: stage_remain_time
  cdr << ros_message.stage_remain_time;

  // Member: my_hp
  cdr << ros_message.my_hp;

  // Member: my_outpost_hp
  cdr << ros_message.my_outpost_hp;

  // Member: my_base_hp
  cdr << ros_message.my_base_hp;

  // Member: our_hero_x
  cdr << ros_message.our_hero_x;

  // Member: our_hero_y
  cdr << ros_message.our_hero_y;

  // Member: enemy_1_robot_hp
  cdr << ros_message.enemy_1_robot_hp;

  // Member: enemy_2_robot_hp
  cdr << ros_message.enemy_2_robot_hp;

  // Member: enemy_3_robot_hp
  cdr << ros_message.enemy_3_robot_hp;

  // Member: enemy_4_robot_hp
  cdr << ros_message.enemy_4_robot_hp;

  // Member: enemy_5_robot_hp
  cdr << ros_message.enemy_5_robot_hp;

  // Member: enemy_7_robot_hp
  cdr << ros_message.enemy_7_robot_hp;

  // Member: enemy_outpost_hp
  cdr << ros_message.enemy_outpost_hp;

  // Member: enemy_base_hp
  cdr << ros_message.enemy_base_hp;

  // Member: external_supply_area_occupied
  cdr << ros_message.external_supply_area_occupied;

  // Member: inner_supply_area_occupied
  cdr << ros_message.inner_supply_area_occupied;

  // Member: supply_area_occupied
  cdr << ros_message.supply_area_occupied;

  // Member: our_small_buff_activated
  cdr << ros_message.our_small_buff_activated;

  // Member: our_big_buff_activated
  cdr << ros_message.our_big_buff_activated;

  // Member: our_fortress_status
  cdr << ros_message.our_fortress_status;

  // Member: remaining_gold_coin
  cdr << ros_message.remaining_gold_coin;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
get_serialized_size_key(
  const robots_msgs::msg::GameStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: game_type
  {
    size_t item_size = sizeof(ros_message.game_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: game_progress
  {
    size_t item_size = sizeof(ros_message.game_progress);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: stage_remain_time
  {
    size_t item_size = sizeof(ros_message.stage_remain_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: my_hp
  {
    size_t item_size = sizeof(ros_message.my_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: my_outpost_hp
  {
    size_t item_size = sizeof(ros_message.my_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: my_base_hp
  {
    size_t item_size = sizeof(ros_message.my_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_hero_x
  {
    size_t item_size = sizeof(ros_message.our_hero_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_hero_y
  {
    size_t item_size = sizeof(ros_message.our_hero_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_5_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.enemy_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_outpost_hp
  {
    size_t item_size = sizeof(ros_message.enemy_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: enemy_base_hp
  {
    size_t item_size = sizeof(ros_message.enemy_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: external_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message.external_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: inner_supply_area_occupied
  {
    size_t item_size = sizeof(ros_message.inner_supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: supply_area_occupied
  {
    size_t item_size = sizeof(ros_message.supply_area_occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_small_buff_activated
  {
    size_t item_size = sizeof(ros_message.our_small_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_big_buff_activated
  {
    size_t item_size = sizeof(ros_message.our_big_buff_activated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: our_fortress_status
  {
    size_t item_size = sizeof(ros_message.our_fortress_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: remaining_gold_coin
  {
    size_t item_size = sizeof(ros_message.remaining_gold_coin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robots_msgs
max_serialized_size_key_GameStatus(
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

  // Member: game_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: game_progress
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stage_remain_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: my_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: my_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: my_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: our_hero_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: our_hero_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: enemy_1_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_2_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_3_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_4_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_5_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_7_robot_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_outpost_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: enemy_base_hp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: external_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: inner_supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: supply_area_occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: our_small_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: our_big_buff_activated
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: our_fortress_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: remaining_gold_coin
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
    using DataType = robots_msgs::msg::GameStatus;
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
  auto typed_message =
    static_cast<const robots_msgs::msg::GameStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GameStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robots_msgs::msg::GameStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GameStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robots_msgs::msg::GameStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GameStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GameStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GameStatus__callbacks = {
  "robots_msgs::msg",
  "GameStatus",
  _GameStatus__cdr_serialize,
  _GameStatus__cdr_deserialize,
  _GameStatus__get_serialized_size,
  _GameStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GameStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GameStatus__callbacks,
  get_message_typesupport_handle_function,
  &robots_msgs__msg__GameStatus__get_type_hash,
  &robots_msgs__msg__GameStatus__get_type_description,
  &robots_msgs__msg__GameStatus__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robots_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robots_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<robots_msgs::msg::GameStatus>()
{
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_GameStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robots_msgs, msg, GameStatus)() {
  return &robots_msgs::msg::typesupport_fastrtps_cpp::_GameStatus__handle;
}

#ifdef __cplusplus
}
#endif
