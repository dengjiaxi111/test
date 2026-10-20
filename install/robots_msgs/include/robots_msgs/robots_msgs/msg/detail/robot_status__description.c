// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/robot_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__RobotStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xba, 0xa5, 0x16, 0x31, 0x54, 0xa4, 0x14, 0xb3,
      0xb1, 0x5b, 0xff, 0x2a, 0x6f, 0xe5, 0xe4, 0x13,
      0x1e, 0xae, 0x0e, 0x68, 0x93, 0xc2, 0x87, 0x09,
      0x6c, 0x5d, 0xf1, 0xe8, 0x95, 0x1d, 0xb6, 0x00,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__RobotStatus__TYPE_NAME[] = "robots_msgs/msg/RobotStatus";

// Define type names, field names, and default values
static char robots_msgs__msg__RobotStatus__FIELD_NAME__robot_id[] = "robot_id";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__x[] = "x";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__y[] = "y";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__angle[] = "angle";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__recovery_buff[] = "recovery_buff";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__defence_buff[] = "defence_buff";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__vulnerability_buff[] = "vulnerability_buff";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__attack_buff[] = "attack_buff";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__remaining_energy[] = "remaining_energy";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__projectile_allowance_17mm[] = "projectile_allowance_17mm";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__fort_area[] = "fort_area";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__supply_blood_area[] = "supply_blood_area";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__local_exchange_projectile_allowance_17mm[] = "local_exchange_projectile_allowance_17mm";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__remote_exchange_projectile_times[] = "remote_exchange_projectile_times";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__remote_exchange_health_times[] = "remote_exchange_health_times";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__can_free_rebirth[] = "can_free_rebirth";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__can_instant_rebirth[] = "can_instant_rebirth";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__rebirth_need_coin[] = "rebirth_need_coin";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__ttk_status[] = "ttk_status";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__projectile_allowance_17mm_remain[] = "projectile_allowance_17mm_remain";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__target_position_x[] = "target_position_x";
static char robots_msgs__msg__RobotStatus__FIELD_NAME__target_position_y[] = "target_position_y";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__RobotStatus__FIELDS[] = {
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__angle, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__recovery_buff, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__defence_buff, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__vulnerability_buff, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__attack_buff, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__remaining_energy, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__projectile_allowance_17mm, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__fort_area, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__supply_blood_area, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__local_exchange_projectile_allowance_17mm, 40, 40},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__remote_exchange_projectile_times, 32, 32},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__remote_exchange_health_times, 28, 28},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__can_free_rebirth, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__can_instant_rebirth, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__rebirth_need_coin, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__ttk_status, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__projectile_allowance_17mm_remain, 32, 32},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__target_position_x, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__RobotStatus__FIELD_NAME__target_position_y, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robots_msgs__msg__RobotStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__RobotStatus__TYPE_NAME, 27, 27},
      {robots_msgs__msg__RobotStatus__FIELDS, 22, 22},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#robot status\n"
  "uint8  robot_id\n"
  "\n"
  "float32 x     # \\xe6\\x9c\\xac\\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe4\\xbd\\x8d\\xe7\\xbd\\xae x \\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8d\\xef\\xbc\\x9am\n"
  "float32 y     # \\xe6\\x9c\\xac\\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe4\\xbd\\x8d\\xe7\\xbd\\xae y \\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8d\\xef\\xbc\\x9am\n"
  "float32 angle # \\xe6\\x9c\\xac\\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe6\\xb5\\x8b\\xe9\\x80\\x9f\\xe6\\xa8\\xa1\\xe5\\x9d\\x97\\xe7\\x9a\\x84\\xe6\\x9c\\x9d\\xe5\\x90\\x91\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8d\\xef\\xbc\\x9a\\xe5\\xba\\xa6\\xe3\\x80\\x82\\xe6\\xad\\xa3\\xe5\\x8c\\x97\\xe4\\xb8\\xba 0 \\xe5\\xba\\xa6\n"
  "\n"
  "uint8  recovery_buff      # \\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe5\\x9b\\x9e\\xe8\\xa1\\x80\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\\xef\\xbc\\x88\\xe7\\x99\\xbe\\xe5\\x88\\x86\\xe6\\xaf\\x94\\xef\\xbc\\x8c\\xe5\\x80\\xbc\\xe4\\xb8\\xba 10 \\xe8\\xa1\\xa8\\xe7\\xa4\\xba\\xe6\\xaf\\x8f\\xe7\\xa7\\x92\\xe6\\x81\\xa2\\xe5\\xa4\\x8d\\xe8\\xa1\\x80\\xe9\\x87\\x8f\\xe4\\xb8\\x8a\\xe9\\x99\\x90\\xe7\\x9a\\x84 10%\n"
  "uint8  defence_buff       # \\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe9\\x98\\xb2\\xe5\\xbe\\xa1\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\\xef\\xbc\\x88\\xe7\\x99\\xbe\\xe5\\x88\\x86\\xe6\\xaf\\x94\\xef\\xbc\\x8c\\xe5\\x80\\xbc\\xe4\\xb8\\xba 50 \\xe8\\xa1\\xa8\\xe7\\xa4\\xba 50%\\xe9\\x98\\xb2\\xe5\\xbe\\xa1\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\n"
  "uint8  vulnerability_buff # \\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe8\\xb4\\x9f\\xe9\\x98\\xb2\\xe5\\xbe\\xa1\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\\xef\\xbc\\x88\\xe7\\x99\\xbe\\xe5\\x88\\x86\\xe6\\xaf\\x94\\xef\\xbc\\x8c\\xe5\\x80\\xbc\\xe4\\xb8\\xba 30 \\xe8\\xa1\\xa8\\xe7\\xa4\\xba-30%\\xe9\\x98\\xb2\\xe5\\xbe\\xa1\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\\xef\\xbc\\x89\n"
  "uint16 attack_buff         # \\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe6\\x94\\xbb\\xe5\\x87\\xbb\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\\xef\\xbc\\x88\\xe7\\x99\\xbe\\xe5\\x88\\x86\\xe6\\xaf\\x94\\xef\\xbc\\x8c\\xe5\\x80\\xbc\\xe4\\xb8\\xba 50 \\xe8\\xa1\\xa8\\xe7\\xa4\\xba 50%\\xe6\\x94\\xbb\\xe5\\x87\\xbb\\xe5\\xa2\\x9e\\xe7\\x9b\\x8a\n"
  "\n"
  "uint8 remaining_energy #\\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe5\\x89\\xa9\\xe4\\xbd\\x99\\xe8\\x83\\xbd\\xe9\\x87\\x8f\\xe5\\x80\\xbc\\xe5\\x8f\\x8d\\xe9\\xa6\\x88\\xef\\xbc\\x8c\\xe4\\xbb\\xa5 16 \\xe8\\xbf\\x9b\\xe5\\x88\\xb6\\xe6\\xa0\\x87\\xe8\\xaf\\x86\\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe5\\x89\\xa9\\xe4\\xbd\\x99\\xe8\\x83\\xbd\\xe9\\x87\\x8f\\xe5\\x80\\xbc\\xe6\\xaf\\x94\\xe4\\xbe\\x8b\n"
  "uint16 projectile_allowance_17mm # 17mm \\xe5\\xbc\\xb9\\xe4\\xb8\\xb8\\xe5\\x85\\x81\\xe8\\xae\\xb8\\xe5\\x8f\\x91\\xe5\\xbc\\xb9\\xe9\\x87\\x8f\n"
  "\n"
  "uint8  fort_area # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe5\\xa0\\xa1\\xe5\\x9e\\x92\n"
  "uint8  supply_blood_area  # \\xe5\\xb7\\xb1\\xe6\\x96\\xb9\\xe8\\xa1\\xa5\\xe8\\xa1\\x80\\xe7\\x82\\xb9\n"
  "\n"
  "uint16 local_exchange_projectile_allowance_17mm\n"
  "uint8 remote_exchange_projectile_times\n"
  "uint8 remote_exchange_health_times\n"
  "\n"
  "uint8  can_free_rebirth\n"
  "uint8  can_instant_rebirth\n"
  "uint16 rebirth_need_coin\n"
  "\n"
  "uint8  ttk_status\n"
  "uint16 projectile_allowance_17mm_remain\n"
  "\n"
  "float32  target_position_x # \\xe4\\xba\\x91\\xe5\\x8f\\xb0\\xe6\\x89\\x8b\\xe5\\x8f\\x91\\xe7\\x9a\\x84\\xe6\\x8e\\xa7\\xe5\\x88\\xb6\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xe4\\xbd\\x8d\\xe7\\xbd\\xaex\\xe5\\x9d\\x90\\xe6\\xa0\\x87\n"
  "float32  target_position_y # \\xe4\\xba\\x91\\xe5\\x8f\\xb0\\xe6\\x89\\x8b\\xe5\\x8f\\x91\\xe7\\x9a\\x84\\xe6\\x8e\\xa7\\xe5\\x88\\xb6\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xe4\\xbd\\x8d\\xe7\\xbd\\xaey\\xe5\\x9d\\x90\\xe6\\xa0\\x87";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__RobotStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__RobotStatus__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 886, 886},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__RobotStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__RobotStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
