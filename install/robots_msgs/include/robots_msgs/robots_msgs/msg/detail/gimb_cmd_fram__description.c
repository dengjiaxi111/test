// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/gimb_cmd_fram__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__GimbCmdFram__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x67, 0x98, 0xf2, 0x9b, 0x94, 0xf1, 0xe5, 0x4d,
      0xb6, 0x17, 0x54, 0xb7, 0x08, 0xf1, 0xb2, 0x9c,
      0x85, 0x7b, 0x4b, 0x77, 0x5e, 0xa2, 0x92, 0x7e,
      0x2b, 0x83, 0x45, 0x48, 0xa4, 0xd9, 0xe7, 0x5b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__GimbCmdFram__TYPE_NAME[] = "robots_msgs/msg/GimbCmdFram";

// Define type names, field names, and default values
static char robots_msgs__msg__GimbCmdFram__FIELD_NAME__center_yaw[] = "center_yaw";
static char robots_msgs__msg__GimbCmdFram__FIELD_NAME__armor_pitch[] = "armor_pitch";
static char robots_msgs__msg__GimbCmdFram__FIELD_NAME__armor_yaw[] = "armor_yaw";
static char robots_msgs__msg__GimbCmdFram__FIELD_NAME__spin_flag[] = "spin_flag";
static char robots_msgs__msg__GimbCmdFram__FIELD_NAME__shot_mode[] = "shot_mode";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__GimbCmdFram__FIELDS[] = {
  {
    {robots_msgs__msg__GimbCmdFram__FIELD_NAME__center_yaw, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbCmdFram__FIELD_NAME__armor_pitch, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbCmdFram__FIELD_NAME__armor_yaw, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbCmdFram__FIELD_NAME__spin_flag, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbCmdFram__FIELD_NAME__shot_mode, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robots_msgs__msg__GimbCmdFram__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__GimbCmdFram__TYPE_NAME, 27, 27},
      {robots_msgs__msg__GimbCmdFram__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32  center_yaw\n"
  "float32  armor_pitch\\t\n"
  "float32  armor_yaw\n"
  "uint8\\t spin_flag      \n"
  "uint8    shot_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__GimbCmdFram__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__GimbCmdFram__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 103, 103},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__GimbCmdFram__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__GimbCmdFram__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
