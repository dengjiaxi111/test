// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice

#include "robots_msgs/msg/detail/my_path__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robots_msgs
const rosidl_type_hash_t *
robots_msgs__msg__MyPath__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4f, 0xd3, 0x35, 0xe6, 0x43, 0xc7, 0xe3, 0x6a,
      0x07, 0x6c, 0xc1, 0x1c, 0x10, 0x3d, 0xb9, 0x5c,
      0xbc, 0x10, 0x1e, 0xc6, 0xc6, 0xdc, 0x39, 0x03,
      0x7d, 0xaa, 0xc4, 0x75, 0x23, 0x5b, 0x71, 0x66,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robots_msgs__msg__MyPath__TYPE_NAME[] = "robots_msgs/msg/MyPath";

// Define type names, field names, and default values
static char robots_msgs__msg__MyPath__FIELD_NAME__intention[] = "intention";
static char robots_msgs__msg__MyPath__FIELD_NAME__start_x[] = "start_x";
static char robots_msgs__msg__MyPath__FIELD_NAME__start_y[] = "start_y";
static char robots_msgs__msg__MyPath__FIELD_NAME__delta_x[] = "delta_x";
static char robots_msgs__msg__MyPath__FIELD_NAME__delta_y[] = "delta_y";
static char robots_msgs__msg__MyPath__FIELD_NAME__sender_id[] = "sender_id";

static rosidl_runtime_c__type_description__Field robots_msgs__msg__MyPath__FIELDS[] = {
  {
    {robots_msgs__msg__MyPath__FIELD_NAME__intention, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__MyPath__FIELD_NAME__start_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__MyPath__FIELD_NAME__start_y, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__MyPath__FIELD_NAME__delta_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__MyPath__FIELD_NAME__delta_y, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robots_msgs__msg__MyPath__FIELD_NAME__sender_id, 9, 9},
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
robots_msgs__msg__MyPath__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robots_msgs__msg__MyPath__TYPE_NAME, 22, 22},
      {robots_msgs__msg__MyPath__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 intention\n"
  "uint16 start_x\n"
  "uint16 start_y\n"
  "int8[] delta_x\n"
  "int8[] delta_y\n"
  "uint16 sender_id";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robots_msgs__msg__MyPath__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robots_msgs__msg__MyPath__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 92, 92},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robots_msgs__msg__MyPath__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robots_msgs__msg__MyPath__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
