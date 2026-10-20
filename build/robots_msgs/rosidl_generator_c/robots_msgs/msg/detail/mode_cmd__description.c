// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/mode_cmd__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__ModeCmd__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x09, 0x60, 0xa8, 0x5c, 0x3d, 0xc7, 0x56, 0xbd,
      0x11, 0xa6, 0xfd, 0xb9, 0x8c, 0x91, 0x0f, 0x1b,
      0x5d, 0x33, 0xe8, 0x1d, 0xcc, 0x39, 0x76, 0x82,
      0x1a, 0x36, 0x79, 0xc4, 0x24, 0x12, 0xa2, 0x96,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__ModeCmd__TYPE_NAME[] = "robots_msgs/msg/ModeCmd";

// Define type names, field names, and default values
static char robots_msgs__msg__ModeCmd__FIELD_NAME__should_chassis_spin[] = "should_chassis_spin";
static char robots_msgs__msg__ModeCmd__FIELD_NAME__should_gimbal_patrol[] = "should_gimbal_patrol";
static char robots_msgs__msg__ModeCmd__FIELD_NAME__buy_bullet[] = "buy_bullet";
static char robots_msgs__msg__ModeCmd__FIELD_NAME__rebirth[] = "rebirth";
static char robots_msgs__msg__ModeCmd__FIELD_NAME__use_capacity[] = "use_capacity";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__ModeCmd__FIELDS[] = {
  {
    {robots_msgs__msg__ModeCmd__FIELD_NAME__should_chassis_spin, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ModeCmd__FIELD_NAME__should_gimbal_patrol, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ModeCmd__FIELD_NAME__buy_bullet, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ModeCmd__FIELD_NAME__rebirth, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ModeCmd__FIELD_NAME__use_capacity, 12, 12},
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
robots_msgs__msg__ModeCmd__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__ModeCmd__TYPE_NAME, 23, 23},
      {robots_msgs__msg__ModeCmd__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 should_chassis_spin\n"
  "uint8 should_gimbal_patrol\n"
  "uint8 buy_bullet\n"
  "uint8 rebirth\n"
  "uint8 use_capacity";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__ModeCmd__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__ModeCmd__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 103, 103},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__ModeCmd__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__ModeCmd__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
