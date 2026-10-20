// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/enemy_pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__EnemyPose__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcf, 0x89, 0xee, 0x7f, 0x45, 0x14, 0x34, 0x9d,
      0xae, 0xfc, 0x9d, 0x9b, 0xd0, 0xde, 0xff, 0xdb,
      0x6f, 0x57, 0xdd, 0xe4, 0xa2, 0x7a, 0x3c, 0x46,
      0xe1, 0xa0, 0xf0, 0x18, 0xd2, 0xcf, 0x9b, 0x77,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__EnemyPose__TYPE_NAME[] = "robots_msgs/msg/EnemyPose";

// Define type names, field names, and default values
static char robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_dist[] = "enemy_dist";
static char robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_ori[] = "enemy_ori";
static char robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_num[] = "enemy_num";
static char robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_x[] = "enemy_x";
static char robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_y[] = "enemy_y";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__EnemyPose__FIELDS[] = {
  {
    {robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_dist, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_ori, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_num, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__EnemyPose__FIELD_NAME__enemy_y, 7, 7},
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
robots_msgs__msg__EnemyPose__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__EnemyPose__TYPE_NAME, 25, 25},
      {robots_msgs__msg__EnemyPose__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# enemy pose\n"
  "float32 enemy_dist\n"
  "float32 enemy_ori\n"
  "int8    enemy_num\n"
  "\n"
  "float32 enemy_x\n"
  "float32 enemy_y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__EnemyPose__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__EnemyPose__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 101, 101},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__EnemyPose__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__EnemyPose__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
