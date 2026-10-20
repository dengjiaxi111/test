// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__HoleSpeedRegion__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8a, 0x70, 0x03, 0xe3, 0x70, 0x6c, 0x6a, 0x11,
      0x88, 0x2d, 0x65, 0x86, 0x0d, 0x02, 0xbe, 0xdd,
      0x7c, 0xe5, 0xc8, 0x42, 0x05, 0xdb, 0xf0, 0x3f,
      0xf1, 0x54, 0xe4, 0x28, 0x07, 0x85, 0xc2, 0x69,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char nav_interfaces__msg__HoleSpeedRegion__TYPE_NAME[] = "nav_interfaces/msg/HoleSpeedRegion";

// Define type names, field names, and default values
static char nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__s_begin[] = "s_begin";
static char nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__s_end[] = "s_end";
static char nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__speed_limit[] = "speed_limit";
static char nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__kind[] = "kind";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__HoleSpeedRegion__FIELDS[] = {
  {
    {nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__s_begin, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__s_end, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__speed_limit, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleSpeedRegion__FIELD_NAME__kind, 4, 4},
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
nav_interfaces__msg__HoleSpeedRegion__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__HoleSpeedRegion__TYPE_NAME, 34, 34},
      {nav_interfaces__msg__HoleSpeedRegion__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe4\\xb8\\x8a\\xe7\\x9a\\x84\\xe5\\x88\\x86\\xe6\\xae\\xb5\\xe9\\x80\\x9f\\xe5\\xba\\xa6\\xe4\\xb8\\x8a\\xe9\\x99\\x90\\xef\\xbc\\x9b\\xe5\\xb5\\x8c\\xe5\\xa5\\x97\\xe5\\x9c\\xa8 NavigationPlan.speed_regions\\xe3\\x80\\x82\n"
  "# \\xe4\\xb8\\xba\\xe4\\xb8\\x8a\\xe4\\xb8\\x8b\\xe5\\x9d\\xa1\\xe5\\x8f\\x8a\\xe5\\x9d\\xa1\\xe9\\xa1\\xb6\\xe5\\x90\\x8e\\xe9\\x99\\x90\\xe9\\x80\\x9f\\xe8\\xa1\\xa5\\xe5\\x85\\x85\\xe7\\x9a\\x84\\xe7\\xbb\\x93\\xe6\\x9e\\x84\\xef\\xbc\\x9b\\xe5\\xae\\x83\\xe6\\x8f\\x8f\\xe8\\xbf\\xb0\\xe9\\x99\\x90\\xe5\\x88\\xb6\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\xb4\\x9f\\xe8\\xb4\\xa3\\xe7\\x94\\x9f\\xe6\\x88\\x90\\xe5\\x8a\\xa0\\xe5\\x87\\x8f\\xe9\\x80\\x9f\\xe6\\x8c\\x87\\xe4\\xbb\\xa4\\xe3\\x80\\x82\n"
  "# \\xe4\\xb8\\x8d\\xe6\\x94\\xb9\\xe5\\x8f\\x98A/S/E/X/T/D\\xe5\\x87\\xa0\\xe4\\xbd\\x95\\xef\\xbc\\x9b\\xe5\\x85\\xb7\\xe4\\xbd\\x93\\xe4\\xb8\\x8a\\xe9\\x99\\x90\\xe7\\x94\\xb1\\xe9\\x85\\x8d\\xe7\\xbd\\xae\\xe5\\x92\\x8c\\xe6\\x8e\\xa7\\xe5\\x88\\xb6\\xe5\\x99\\xa8\\xe5\\x85\\xb1\\xe5\\x90\\x8c\\xe5\\xa4\\x84\\xe7\\x90\\x86\\xe3\\x80\\x82\n"
  "\n"
  "# \\xe9\\x99\\x90\\xe9\\x80\\x9f\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xe8\\xb5\\xb7\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe7\\xb4\\xaf\\xe8\\xae\\xa1\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xe3\\x80\\x82\n"
  "float64 s_begin\n"
  "\n"
  "# \\xe9\\x99\\x90\\xe9\\x80\\x9f\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xe7\\xbb\\x88\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe7\\xb4\\xaf\\xe8\\xae\\xa1\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xef\\xbc\\x9b\\xe6\\x8c\\x89\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe8\\xa7\\xa3\\xe9\\x87\\x8a\\xe3\\x80\\x82\n"
  "float64 s_end\n"
  "\n"
  "# \\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xe5\\xb9\\xb3\\xe7\\xa7\\xbb\\xe9\\x80\\x9f\\xe5\\xba\\xa6\\xe6\\xa8\\xa1\\xe9\\x95\\xbf\\xe4\\xb8\\x8a\\xe9\\x99\\x90\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm/s\\xef\\xbc\\x9b\\xe5\\x85\\x81\\xe8\\xae\\xb8\\xe6\\x9b\\xb4\\xe6\\x85\\xa2\\xe6\\x88\\x96\\xe5\\x81\\x9c\\xe8\\xbd\\xa6\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe5\\xbc\\xba\\xe5\\x88\\xb6\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xe9\\x80\\x9f\\xe5\\xba\\xa6\\xe3\\x80\\x82\n"
  "float64 speed_limit\n"
  "\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8dC++\\xe7\\xbc\\x96\\xe7\\xa0\\x81\\xef\\xbc\\x9a0\\xe5\\xb9\\xb3\\xe5\\x9c\\xb0FLAT\\xef\\xbc\\x8c1\\xe4\\xb8\\x8a\\xe5\\x9d\\xa1UPHILL\\xef\\xbc\\x8c2\\xe4\\xb8\\x8b\\xe5\\x9d\\xa1DOWNHILL\\xef\\xbc\\x8c3\\xe5\\x8f\\x97\\xe9\\x99\\x90RESTRICTED\\xef\\xbc\\x9b\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe5\\xb0\\x9a\\xe6\\x9c\\xaa\\xe5\\xa3\\xb0\\xe6\\x98\\x8e\\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe5\\x91\\xbd\\xe5\\x90\\x8d\\xe5\\xb8\\xb8\\xe9\\x87\\x8f\\xe3\\x80\\x82\n"
  "uint8 kind\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__HoleSpeedRegion__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__HoleSpeedRegion__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 344, 344},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__HoleSpeedRegion__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__HoleSpeedRegion__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
