// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/HoleStraight.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/hole_straight__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__HoleStraight__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd5, 0x7d, 0x24, 0x69, 0xe4, 0xa3, 0x23, 0xf3,
      0x8f, 0xe1, 0x7c, 0xc4, 0x78, 0x60, 0xef, 0xc9,
      0x9d, 0x3d, 0xa8, 0x12, 0x28, 0x09, 0x6a, 0x32,
      0xe6, 0xab, 0x56, 0x92, 0x79, 0xb2, 0x33, 0xcc,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/vector3__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
#endif

static char nav_interfaces__msg__HoleStraight__TYPE_NAME[] = "nav_interfaces/msg/HoleStraight";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";

// Define type names, field names, and default values
static char nav_interfaces__msg__HoleStraight__FIELD_NAME__s_begin[] = "s_begin";
static char nav_interfaces__msg__HoleStraight__FIELD_NAME__s_end[] = "s_end";
static char nav_interfaces__msg__HoleStraight__FIELD_NAME__direction[] = "direction";
static char nav_interfaces__msg__HoleStraight__FIELD_NAME__remaining[] = "remaining";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__HoleStraight__FIELDS[] = {
  {
    {nav_interfaces__msg__HoleStraight__FIELD_NAME__s_begin, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStraight__FIELD_NAME__s_end, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStraight__FIELD_NAME__direction, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStraight__FIELD_NAME__remaining, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__msg__HoleStraight__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__msg__HoleStraight__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__HoleStraight__TYPE_NAME, 31, 31},
      {nav_interfaces__msg__HoleStraight__FIELDS, 4, 4},
    },
    {nav_interfaces__msg__HoleStraight__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe4\\xb8\\x8a\\xe9\\x9c\\x80\\xe8\\xa6\\x81\\xe4\\xbf\\x9d\\xe6\\x8c\\x81\\xe7\\x9b\\xb4\\xe7\\xba\\xbf\\xe7\\x9a\\x84\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xef\\xbc\\x9b\\xe5\\xb5\\x8c\\xe5\\xa5\\x97\\xe5\\x9c\\xa8 HoleTraversal.straight_segments\\xe3\\x80\\x82\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe4\\xba\\xa4\\xe6\\x8e\\xa5\\xe6\\x96\\x87\\xe6\\xa1\\xa35.2\\xef\\xbc\\x9a\\xe4\\xb8\\xa5\\xe6\\xa0\\xbc\\xe6\\xa8\\xa1\\xe5\\xbc\\x8fS\\xe2\\x80\\x94T\\xef\\xbc\\x9bfree\\xe6\\xa8\\xa1\\xe5\\xbc\\x8fS\\xe2\\x80\\x94E\\xe5\\x92\\x8cX\\xe2\\x80\\x94T\\xe3\\x80\\x82\n"
  "# \\xe6\\x96\\xb9\\xe5\\x90\\x91\\xe6\\x98\\xaf\\xe5\\x9c\\xb0\\xe5\\x9b\\xbe\\xe4\\xb8\\xad\\xe7\\x9a\\x84\\xe8\\xbf\\x90\\xe5\\x8a\\xa8\\xe5\\x88\\x87\\xe7\\xba\\xbf\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe6\\x9c\\xba\\xe8\\xba\\xabyaw\\xe5\\xaf\\xb9\\xe5\\x87\\x86\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe3\\x80\\x82\n"
  "\n"
  "# \\xe7\\x9b\\xb4\\xe7\\xba\\xbf\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xe8\\xb5\\xb7\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe7\\xb4\\xaf\\xe8\\xae\\xa1\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xef\\xbc\\x8c\\xe7\\x9b\\xb8\\xe5\\xaf\\xb9\\xe5\\xbd\\x93\\xe5\\x89\\x8dNavigationPlan.path\\xe8\\xb5\\xb7\\xe7\\x82\\xb9\\xe3\\x80\\x82\n"
  "float64 s_begin\n"
  "\n"
  "# \\xe7\\x9b\\xb4\\xe7\\xba\\xbf\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xe7\\xbb\\x88\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe7\\xb4\\xaf\\xe8\\xae\\xa1\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xef\\xbc\\x8c\\xe5\\xba\\x94\\xe4\\xb8\\x8d\\xe5\\xb0\\x8f\\xe4\\xba\\x8es_begin\\xe3\\x80\\x82\n"
  "float64 s_end\n"
  "\n"
  "# \\xe5\\x9c\\xb0\\xe5\\x9b\\xbe\\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xe7\\xb3\\xbb\\xe7\\x9a\\x84\\xe8\\xbf\\x90\\xe5\\x8a\\xa8\\xe6\\x96\\xb9\\xe5\\x90\\x91\\xe5\\x90\\x91\\xe9\\x87\\x8f\\xef\\xbc\\x8c\\xe8\\x8d\\x89\\xe7\\xa8\\xbf\\xe4\\xbd\\xbf\\xe7\\x94\\xa8\\xe4\\xba\\x8c\\xe7\\xbb\\xb4\\xe5\\x88\\x87\\xe5\\x90\\x91x/y\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe6\\x9c\\xba\\xe8\\xba\\xab\\xe6\\x9c\\x9d\\xe5\\x90\\x91\\xe8\\xa7\\x92\\xef\\xbc\\x8c\\xe4\\xb9\\x9f\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe9\\x80\\x9f\\xe5\\xba\\xa6\\xe5\\xa4\\xa7\\xe5\\xb0\\x8f\\xe3\\x80\\x82\n"
  "geometry_msgs/Vector3 direction\n"
  "\n"
  "# true\\xe8\\xa1\\xa8\\xe7\\xa4\\xba\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe5\\x8f\\xaa\\xe8\\x83\\xbd\\xe5\\xa3\\xb0\\xe6\\x98\\x8e\\xe5\\x89\\xa9\\xe4\\xbd\\x99\\xe7\\x9b\\xb4\\xe7\\xba\\xbf\\xe7\\x89\\x87\\xe6\\xae\\xb5\\xef\\xbc\\x9bfalse\\xe5\\xa3\\xb0\\xe6\\x98\\x8e\\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe7\\xad\\x89\\xe4\\xba\\x8e\\xe8\\xaf\\xa5\\xe6\\xae\\xb5\\xe5\\xb7\\xb2\\xe7\\xbb\\x8f\\xe8\\xb5\\xb0\\xe5\\xae\\x8c\\xe3\\x80\\x82\n"
  "bool remaining\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__HoleStraight__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__HoleStraight__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 368, 368},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__HoleStraight__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__HoleStraight__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
