// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/gimbal_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__GimbalData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3e, 0x75, 0xb1, 0x54, 0x64, 0xa9, 0x27, 0x83,
      0x93, 0x67, 0xed, 0x0a, 0x57, 0x1b, 0x33, 0x7d,
      0x22, 0xbd, 0x3c, 0x97, 0xc4, 0xaf, 0xd1, 0xa5,
      0xdd, 0xf3, 0xe9, 0xc7, 0x5e, 0xc0, 0x18, 0x84,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__GimbalData__TYPE_NAME[] = "robots_msgs/msg/GimbalData";

// Define type names, field names, and default values
static char robots_msgs__msg__GimbalData__FIELD_NAME__gimbal_yaw[] = "gimbal_yaw";
static char robots_msgs__msg__GimbalData__FIELD_NAME__gimbal_pitch[] = "gimbal_pitch";
static char robots_msgs__msg__GimbalData__FIELD_NAME__yaw_va[] = "yaw_va";
static char robots_msgs__msg__GimbalData__FIELD_NAME__base_yaw[] = "base_yaw";
static char robots_msgs__msg__GimbalData__FIELD_NAME__self_team[] = "self_team";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__GimbalData__FIELDS[] = {
  {
    {robots_msgs__msg__GimbalData__FIELD_NAME__gimbal_yaw, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbalData__FIELD_NAME__gimbal_pitch, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbalData__FIELD_NAME__yaw_va, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbalData__FIELD_NAME__base_yaw, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__GimbalData__FIELD_NAME__self_team, 9, 9},
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
robots_msgs__msg__GimbalData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__GimbalData__TYPE_NAME, 26, 26},
      {robots_msgs__msg__GimbalData__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# gimbal data\n"
  "float32 gimbal_yaw\n"
  "float32 gimbal_pitch\n"
  "float32 yaw_va\n"
  "float32 base_yaw\n"
  "uint8   self_team";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__GimbalData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__GimbalData__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 104, 104},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__GimbalData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__GimbalData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
