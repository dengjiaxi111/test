// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/hole_traversal__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__HoleTraversal__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x93, 0x7b, 0x9d, 0x61, 0xbb, 0xab, 0x5b, 0xf0,
      0x1e, 0x37, 0x0f, 0xad, 0x60, 0x48, 0x25, 0x38,
      0x2e, 0xde, 0x0c, 0xab, 0x72, 0xa4, 0x58, 0xad,
      0x9e, 0xa0, 0x42, 0xba, 0x5f, 0xb6, 0x10, 0x1e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "nav_interfaces/msg/detail/hole_event__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "nav_interfaces/msg/detail/hole_straight__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
static const rosidl_type_hash_t nav_interfaces__msg__HoleEvent__EXPECTED_HASH = {1, {
    0xe6, 0x4a, 0x53, 0xb4, 0x5c, 0x15, 0xf6, 0xcc,
    0x94, 0xd3, 0xe2, 0x15, 0x2d, 0x3d, 0xd6, 0x9d,
    0xbe, 0x1d, 0x8e, 0x7d, 0xee, 0x6e, 0x97, 0x45,
    0xc9, 0x74, 0x45, 0x81, 0x27, 0xbf, 0x13, 0xad,
  }};
static const rosidl_type_hash_t nav_interfaces__msg__HoleStraight__EXPECTED_HASH = {1, {
    0xd5, 0x7d, 0x24, 0x69, 0xe4, 0xa3, 0x23, 0xf3,
    0x8f, 0xe1, 0x7c, 0xc4, 0x78, 0x60, 0xef, 0xc9,
    0x9d, 0x3d, 0xa8, 0x12, 0x28, 0x09, 0x6a, 0x32,
    0xe6, 0xab, 0x56, 0x92, 0x79, 0xb2, 0x33, 0xcc,
  }};
#endif

static char nav_interfaces__msg__HoleTraversal__TYPE_NAME[] = "nav_interfaces/msg/HoleTraversal";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char nav_interfaces__msg__HoleEvent__TYPE_NAME[] = "nav_interfaces/msg/HoleEvent";
static char nav_interfaces__msg__HoleStraight__TYPE_NAME[] = "nav_interfaces/msg/HoleStraight";

// Define type names, field names, and default values
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__traversal_uid[] = "traversal_uid";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__hole_id[] = "hole_id";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__entry_edge_id[] = "entry_edge_id";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__exit_edge_id[] = "exit_edge_id";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__centerline[] = "centerline";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__validated[] = "validated";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__requirement_revision[] = "requirement_revision";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__events[] = "events";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__straight_segments[] = "straight_segments";
static char nav_interfaces__msg__HoleTraversal__FIELD_NAME__uphill_entry[] = "uphill_entry";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__HoleTraversal__FIELDS[] = {
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__traversal_uid, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__hole_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__entry_edge_id, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__exit_edge_id, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__centerline, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__validated, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__requirement_revision, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__events, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      6,
      0,
      {nav_interfaces__msg__HoleEvent__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__straight_segments, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {nav_interfaces__msg__HoleStraight__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__FIELD_NAME__uphill_entry, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__msg__HoleTraversal__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleEvent__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStraight__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__msg__HoleTraversal__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__HoleTraversal__TYPE_NAME, 32, 32},
      {nav_interfaces__msg__HoleTraversal__FIELDS, 10, 10},
    },
    {nav_interfaces__msg__HoleTraversal__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_interfaces__msg__HoleEvent__EXPECTED_HASH, nav_interfaces__msg__HoleEvent__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__msg__HoleEvent__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_interfaces__msg__HoleStraight__EXPECTED_HASH, nav_interfaces__msg__HoleStraight__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = nav_interfaces__msg__HoleStraight__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe4\\xb8\\x80\\xe6\\xac\\xa1\\xe5\\x85\\xb7\\xe4\\xbd\\x93\\xe7\\xa9\\xbf\\xe6\\xb4\\x9e\\xe7\\x9a\\x84\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe8\\xae\\xb0\\xe5\\xbd\\x95\\xef\\xbc\\x9b\\xe5\\xb5\\x8c\\xe5\\xa5\\x97\\xe5\\x9c\\xa8 NavigationPlan.passages \\xe5\\x86\\x85\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe5\\x8d\\x95\\xe7\\x8b\\xac\\xe5\\x8f\\x91\\xe5\\xb8\\x83\\xe3\\x80\\x82\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe4\\xba\\xa4\\xe6\\x8e\\xa5\\xe6\\x96\\x87\\xe6\\xa1\\xa35.2\\xe3\\x80\\x82\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe4\\xb8\\xaa\\xe7\\x89\\xa9\\xe7\\x90\\x86\\xe6\\xb4\\x9e\\xe5\\x86\\x8d\\xe6\\xac\\xa1\\xe7\\xa9\\xbf\\xe8\\xb6\\x8a\\xef\\xbc\\x8c\\xe5\\xba\\x94\\xe6\\x9c\\x89\\xe5\\x8f\\xa6\\xe4\\xb8\\x80\\xe6\\x9d\\xa1\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe8\\xae\\xb0\\xe5\\xbd\\x95\\xe3\\x80\\x82\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe8\\x8d\\x89\\xe7\\xa8\\xbf\\xe5\\xb0\\x9a\\xe6\\x9c\\xaa\\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe5\\xaf\\xbc\\xe5\\x87\\xba\\xe6\\x96\\x87\\xe6\\xa1\\xa3\\xe5\\x88\\x97\\xe5\\x87\\xba\\xe7\\x9a\\x84\\xe9\\xa1\\xba\\xe5\\xba\\x8f\\xe3\\x80\\x81\\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe6\\x80\\xa7\\xe3\\x80\\x81\\xe7\\xbb\\x86\\xe5\\x88\\x86\\xe6\\xa0\\xa1\\xe9\\xaa\\x8c\\xe7\\xbb\\x93\\xe6\\x9e\\x9c\\xe5\\x92\\x8c\\xe5\\xae\\xb9\\xe5\\xb7\\xae\\xe7\\xad\\x89\\xe4\\xbf\\xa1\\xe6\\x81\\xaf\\xe3\\x80\\x82\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1\\xe4\\xb8\\xad\\xe8\\xbf\\x99\\xe4\\xb8\\x80\\xe6\\xac\\xa1\\xe5\\x85\\xb7\\xe4\\xbd\\x93\\xe7\\xa9\\xbf\\xe8\\xb6\\x8a\\xe7\\x9a\\x84\\xe7\\xa8\\xb3\\xe5\\xae\\x9a\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xef\\xbc\\x9b\\xe5\\x90\\x8c\\xe6\\xac\\xa1\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe9\\x87\\x8d\\xe8\\xa7\\x84\\xe5\\x88\\x92\\xe5\\x8c\\xb9\\xe9\\x85\\x8d\\xe4\\xbf\\x9d\\xe7\\x95\\x99\\xef\\xbc\\x8c\\xe5\\x86\\x8d\\xe7\\xa9\\xbf\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe4\\xb8\\xaa\\xe6\\xb4\\x9e\\xe5\\xba\\x94\\xe5\\x8f\\xa6\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xe3\\x80\\x82\n"
  "string traversal_uid\n"
  "\n"
  "# \\xe5\\x9c\\xb0\\xe5\\xbd\\xa2\\xe9\\x85\\x8d\\xe7\\xbd\\xae\\xe4\\xb8\\xad\\xe7\\x9a\\x84\\xe7\\x89\\xa9\\xe7\\x90\\x86\\xe6\\xb4\\x9e\\xe5\\x8f\\xa3\\xe5\\x8c\\xba\\xe5\\x9f\\x9fID\\xef\\xbc\\x9b\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe4\\xb8\\xaa\\xe6\\xb4\\x9e\\xe5\\x8f\\xaf\\xe5\\x85\\xb3\\xe8\\x81\\x94\\xe4\\xb8\\x8d\\xe5\\x90\\x8c\\xe6\\xac\\xa1\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe5\\x8d\\x95\\xe7\\x8b\\xac\\xe7\\x94\\xa8\\xe6\\x9d\\xa5\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe5\\x8e\\xbb\\xe9\\x87\\x8d\\xe3\\x80\\x82\n"
  "string hole_id\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe9\\x80\\x89\\xe4\\xb8\\xad\\xe7\\x9a\\x84\\xe6\\xb4\\x9e\\xe5\\x8f\\xa3\\xe5\\xa4\\x9a\\xe8\\xbe\\xb9\\xe5\\xbd\\xa2\\xe5\\x85\\xa5\\xe5\\x8f\\xa3\\xe8\\xbe\\xb9\\xe7\\xb4\\xa2\\xe5\\xbc\\x95\\xef\\xbc\\x8c\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xe8\\xa7\\x84\\xe5\\x88\\x99\\xe6\\x9d\\xa5\\xe8\\x87\\xaa\\xe8\\xa7\\x84\\xe5\\x88\\x92\\xe5\\x99\\xa8\\xe3\\x80\\x82\n"
  "int32 entry_edge_id\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe9\\x80\\x89\\xe4\\xb8\\xad\\xe7\\x9a\\x84\\xe6\\xb4\\x9e\\xe5\\x8f\\xa3\\xe5\\xa4\\x9a\\xe8\\xbe\\xb9\\xe5\\xbd\\xa2\\xe5\\x87\\xba\\xe5\\x8f\\xa3\\xe8\\xbe\\xb9\\xe7\\xb4\\xa2\\xe5\\xbc\\x95\\xef\\xbc\\x8c\\xe4\\xb8\\x8e\\xe5\\x85\\xa5\\xe5\\x8f\\xa3\\xe5\\x85\\xb1\\xe5\\x90\\x8c\\xe7\\xa1\\xae\\xe5\\xae\\x9a\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe6\\x96\\xb9\\xe5\\x90\\x91\\xe3\\x80\\x82\n"
  "int32 exit_edge_id\n"
  "\n"
  "# true\\xe4\\xb8\\xba\\xe4\\xb8\\xa5\\xe6\\xa0\\xbc\\xe4\\xb8\\xad\\xe5\\xbf\\x83\\xe7\\xba\\xbf\\xe6\\xa8\\xa1\\xe5\\xbc\\x8f\\xef\\xbc\\x8cfalse\\xe4\\xb8\\xbafree\\xef\\xbc\\x9b\\xe9\\xbb\\x98\\xe8\\xae\\xa4\\xe5\\x8f\\xaa\\xe6\\x8e\\xa5\\xe7\\xba\\xb3\\xe4\\xb8\\xa5\\xe6\\xa0\\xbc\\xe6\\xa8\\xa1\\xe5\\xbc\\x8f\\xef\\xbc\\x8c\\xe9\\x99\\xa4\\xe9\\x9d\\x9e\\xe9\\x85\\x8d\\xe7\\xbd\\xae\\xe6\\x98\\xbe\\xe5\\xbc\\x8f\\xe5\\x85\\x81\\xe8\\xae\\xb8free\\xe3\\x80\\x82\n"
  "bool centerline\n"
  "\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe5\\x80\\x99\\xe9\\x80\\x89\\xe6\\xa0\\xa1\\xe9\\xaa\\x8c\\xe6\\x98\\xaf\\xe5\\x90\\xa6\\xe9\\x80\\x9a\\xe8\\xbf\\x87\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe6\\x9b\\xbf\\xe4\\xbb\\xa3\\xe6\\x96\\x87\\xe6\\xa1\\xa3\\xe5\\x85\\xa8\\xe9\\x83\\xa8\\xe7\\xbb\\x86\\xe5\\x88\\x86\\xe4\\xbf\\x9d\\xe8\\xaf\\x81\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe8\\xa1\\xa8\\xe7\\xa4\\xba\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe5\\xb7\\xb2\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xe3\\x80\\x82\n"
  "bool validated\n"
  "\n"
  "# \\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe7\\x9a\\x84\\xe4\\xbf\\xae\\xe8\\xae\\xa2\\xe8\\xba\\xab\\xe4\\xbb\\xbd\\xef\\xbc\\x9b\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe5\\x8f\\x98\\xe5\\x8c\\x96\\xe5\\x90\\x8e\\xe6\\x97\\xa7\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xe5\\x8f\\x8d\\xe9\\xa6\\x88\\xe4\\xb8\\x8d\\xe5\\x8f\\xaf\\xe6\\x8e\\x88\\xe6\\x9d\\x83\\xe6\\x96\\xb0\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe3\\x80\\x82\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xe7\\xbb\\x84\\xe5\\x90\\x88\\xe7\\xae\\x97\\xe6\\xb3\\x95\\xe4\\xbb\\x8d\\xe5\\xbe\\x85\\xe5\\xae\\x8c\\xe5\\x96\\x84\\xe3\\x80\\x82\n"
  "uint64 requirement_revision\n"
  "\n"
  "# \\xe5\\x9b\\xba\\xe5\\xae\\x9a\\xe5\\x85\\xad\\xe9\\xa1\\xb9\\xef\\xbc\\x8c\\xe5\\xad\\x98\\xe5\\x82\\xa8\\xe9\\xa1\\xba\\xe5\\xba\\x8fA/S/E/X/T/D\\xef\\xbc\\x9b\\xe6\\xad\\xa4\\xe6\\x95\\xb0\\xe7\\xbb\\x84\\xe9\\xa1\\xba\\xe5\\xba\\x8f\\xe4\\xb8\\x8d\\xe4\\xbb\\xa3\\xe8\\xa1\\xa8\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe7\\x9a\\x84\\xe5\\xae\\x9e\\xe9\\x99\\x85\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xe9\\xa1\\xba\\xe5\\xba\\x8f\\xef\\xbc\\x8cA\\xe5\\x8f\\xaf\\xe8\\x83\\xbd\\xe6\\x99\\x9a\\xe4\\xba\\x8eS\\xe3\\x80\\x82\n"
  "HoleEvent[6] events\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe4\\xb8\\xad\\xe6\\x9c\\x89\\xe6\\x95\\x88\\xe7\\x9a\\x84\\xe5\\x9b\\xba\\xe5\\xae\\x9a\\xe7\\x9b\\xb4\\xe7\\xba\\xbf\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xef\\xbc\\x8c\\xe5\\x8c\\xba\\xe5\\x88\\x86\\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe6\\xae\\xb5\\xe5\\x92\\x8c\\xe5\\x89\\xa9\\xe4\\xbd\\x99\\xe6\\xae\\xb5\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe7\\x94\\xb1\\xe6\\x81\\xa2\\xe5\\xa4\\x8d\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe4\\xbb\\xbb\\xe6\\x84\\x8f\\xe7\\xa0\\xb4\\xe5\\x9d\\x8f\\xe3\\x80\\x82\n"
  "HoleStraight[] straight_segments\n"
  "\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe5\\x85\\xa5\\xe5\\x8f\\xa3\\xe6\\x96\\xb9\\xe5\\x90\\x91\\xe4\\xb8\\x8e\\xe5\\x85\\xb3\\xe8\\x81\\x94\\xe5\\x9d\\xa1\\xe4\\xb8\\x8a\\xe5\\x9d\\xa1\\xe6\\x96\\xb9\\xe5\\x90\\x91\\xe4\\xb8\\x80\\xe8\\x87\\xb4\\xef\\xbc\\x9b\\xe9\\xa6\\x96\\xe7\\x89\\x88\\xe5\\x8f\\xaa\\xe5\\x85\\x81\\xe8\\xae\\xb8\\xe6\\xad\\xa4\\xe7\\xb1\\xbb\\xe5\\xa4\\xb1\\xe8\\xb4\\xa5\\xe5\\x90\\x8e\\xe9\\x80\\x80\\xe8\\xae\\xa9\\xe3\\x80\\x82\n"
  "bool uphill_entry";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__HoleTraversal__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__HoleTraversal__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 738, 738},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__HoleTraversal__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__HoleTraversal__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__msg__HoleEvent__get_individual_type_description_source(NULL);
    sources[4] = *nav_interfaces__msg__HoleStraight__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
