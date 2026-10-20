// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/chassis_odom__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__ChassisOdom__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xba, 0x6e, 0xc7, 0xa7, 0x36, 0x5c, 0x55, 0x64,
      0x96, 0xf2, 0xf5, 0xa5, 0xfd, 0xf8, 0x58, 0x1f,
      0x05, 0x9a, 0x38, 0x28, 0x15, 0xdf, 0xe1, 0xf1,
      0xa2, 0xe5, 0xf3, 0x50, 0x22, 0xd0, 0xbd, 0xbb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__ChassisOdom__TYPE_NAME[] = "robots_msgs/msg/ChassisOdom";

// Define type names, field names, and default values
static char robots_msgs__msg__ChassisOdom__FIELD_NAME__speed_x[] = "speed_x";
static char robots_msgs__msg__ChassisOdom__FIELD_NAME__speed_y[] = "speed_y";
static char robots_msgs__msg__ChassisOdom__FIELD_NAME__speed_w[] = "speed_w";
static char robots_msgs__msg__ChassisOdom__FIELD_NAME__gimbal_angle[] = "gimbal_angle";
static char robots_msgs__msg__ChassisOdom__FIELD_NAME__capacitor_voltage[] = "capacitor_voltage";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__ChassisOdom__FIELDS[] = {
  {
    {robots_msgs__msg__ChassisOdom__FIELD_NAME__speed_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ChassisOdom__FIELD_NAME__speed_y, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ChassisOdom__FIELD_NAME__speed_w, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ChassisOdom__FIELD_NAME__gimbal_angle, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__ChassisOdom__FIELD_NAME__capacitor_voltage, 17, 17},
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
robots_msgs__msg__ChassisOdom__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__ChassisOdom__TYPE_NAME, 27, 27},
      {robots_msgs__msg__ChassisOdom__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 speed_x\n"
  "float32 speed_y\n"
  "float32 speed_w\n"
  "float32 gimbal_angle\n"
  "float32 capacitor_voltage";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__ChassisOdom__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__ChassisOdom__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 95, 95},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__ChassisOdom__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__ChassisOdom__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
