// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/game_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__GameStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0x0b, 0xf7, 0x98, 0x0d, 0x4c, 0x5d, 0xe0,
      0x7b, 0xff, 0x75, 0xb1, 0x53, 0x0f, 0x23, 0xba,
      0x3c, 0x9f, 0x8d, 0xfb, 0x06, 0xdd, 0x3c, 0x1c,
      0x38, 0x83, 0x8b, 0x77, 0x32, 0xc0, 0x80, 0x6f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__GameStatus__TYPE_NAME[] = "robots_msgs/msg/GameStatus";

// Define type names, field names, and default values
static char robots_msgs__msg__GameStatus__FIELD_NAME__game_type[] = "game_type";
static char robots_msgs__msg__GameStatus__FIELD_NAME__game_progress[] = "game_progress";
static char robots_msgs__msg__GameStatus__FIELD_NAME__stage_remain_time[] = "stage_remain_time";
static char robots_msgs__msg__GameStatus__FIELD_NAME__my_hp[] = "my_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__my_outpost_hp[] = "my_outpost_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__my_base_hp[] = "my_base_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__our_hero_x[] = "our_hero_x";
static char robots_msgs__msg__GameStatus__FIELD_NAME__our_hero_y[] = "our_hero_y";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_1_robot_hp[] = "enemy_1_robot_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_2_robot_hp[] = "enemy_2_robot_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_3_robot_hp[] = "enemy_3_robot_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_4_robot_hp[] = "enemy_4_robot_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_5_robot_hp[] = "enemy_5_robot_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_7_robot_hp[] = "enemy_7_robot_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_outpost_hp[] = "enemy_outpost_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__enemy_base_hp[] = "enemy_base_hp";
static char robots_msgs__msg__GameStatus__FIELD_NAME__external_supply_area_occupied[] = "external_supply_area_occupied";
static char robots_msgs__msg__GameStatus__FIELD_NAME__inner_supply_area_occupied[] = "inner_supply_area_occupied";
static char robots_msgs__msg__GameStatus__FIELD_NAME__supply_area_occupied[] = "supply_area_occupied";
static char robots_msgs__msg__GameStatus__FIELD_NAME__our_small_buff_activated[] = "our_small_buff_activated";
static char robots_msgs__msg__GameStatus__FIELD_NAME__our_big_buff_activated[] = "our_big_buff_activated";
static char robots_msgs__msg__GameStatus__FIELD_NAME__our_fortress_status[] = "our_fortress_status";
static char robots_msgs__msg__GameStatus__FIELD_NAME__remaining_gold_coin[] = "remaining_gold_coin";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__GameStatus__FIELDS[] = {
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__game_type, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__game_progress, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__stage_remain_time, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__my_hp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__my_outpost_hp, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__my_base_hp, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__our_hero_x, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__our_hero_y, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_1_robot_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_2_robot_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_3_robot_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_4_robot_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_5_robot_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_7_robot_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_outpost_hp, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__enemy_base_hp, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__external_supply_area_occupied, 29, 29},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__inner_supply_area_occupied, 26, 26},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__supply_area_occupied, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__our_small_buff_activated, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__our_big_buff_activated, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__our_fortress_status, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GameStatus__FIELD_NAME__remaining_gold_coin, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robots_msgs__msg__GameStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__GameStatus__TYPE_NAME, 26, 26},
      {robots_msgs__msg__GameStatus__FIELDS, 23, 23},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#game status\n"
  "uint8  game_type\n"
  "uint8  game_progress\n"
  "uint16 stage_remain_time             # \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe9\\x98\\xb6\\xe6\\xae\\xb5\\xe5\\x89\\xa9\\xe4\\xbd\\x99\\xe6\\x97\\xb6\\xe9\\x97\\xb4 \n"
  "\n"
  "uint16 my_hp\n"
  "uint16 my_outpost_hp\n"
  "uint16 my_base_hp\n"
  "\n"
  "float32 our_hero_x\n"
  "float32 our_hero_y\n"
  "\n"
  "uint16 enemy_1_robot_hp\n"
  "uint16 enemy_2_robot_hp\n"
  "uint16 enemy_3_robot_hp\n"
  "uint16 enemy_4_robot_hp\n"
  "uint16 enemy_5_robot_hp\n"
  "uint16 enemy_7_robot_hp\n"
  "uint16 enemy_outpost_hp\n"
  "uint16 enemy_base_hp\n"
  "\n"
  "uint8  external_supply_area_occupied # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe8\\xa1\\xa5\\xe7\\xbb\\x99\\xe7\\xab\\x99\\xe5\\x89\\x8d\\xe8\\xa1\\xa5\\xe8\\xa1\\x80\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe5\\x8d\\xa0\\xe9\\xa2\\x86\\xe7\\x8a\\xb6\\xe6\\x80\\x81\n"
  "uint8  inner_supply_area_occupied    # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe8\\xa1\\xa5\\xe7\\xbb\\x99\\xe7\\xab\\x99\\xe5\\x86\\x85\\xe9\\x83\\xa8\\xe8\\xa1\\xa5\\xe8\\xa1\\x80\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe5\\x8d\\xa0\\xe9\\xa2\\x86\\xe7\\x8a\\xb6\\xe6\\x80\\x81\n"
  "uint8  supply_area_occupied          # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe8\\xa1\\xa5\\xe7\\xbb\\x99\\xe5\\x8c\\xba\\xe7\\x9a\\x84\\xe5\\x8d\\xa0\\xe9\\xa2\\x86\\xe7\\x8a\\xb6\\xe6\\x80\\x81\n"
  "uint8  our_small_buff_activated      # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe5\\xb0\\x8f\\xe7\\xac\\xa6\\xe6\\xbf\\x80\\xe6\\xb4\\xbb\\xe7\\x8a\\xb6\\xe6\\x80\\x81\n"
  "uint8  our_big_buff_activated        # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe5\\xa4\\xa7\\xe7\\xac\\xa6\\xe6\\xbf\\x80\\xe6\\xb4\\xbb\\xe7\\x8a\\xb6\\xe6\\x80\\x81\n"
  "uint8 our_fortress_status            # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe5\\xa0\\xa1\\xe5\\x9e\\x92\\xe5\\x8d\\xa0\\xe9\\xa2\\x86\\xe7\\x8a\\xb6\\xe6\\x80\\x81\n"
  "\n"
  "uint16 remaining_gold_coin";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__GameStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__GameStatus__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 713, 713},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__GameStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__GameStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
