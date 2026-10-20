// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/HoleTraversalEvent.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/hole_traversal_event__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__HoleTraversalEvent__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0xf1, 0xa7, 0x27, 0xc4, 0x4f, 0x80, 0x73,
      0x10, 0xae, 0xa1, 0x1d, 0xc8, 0xbe, 0xae, 0xab,
      0x9b, 0x3d, 0xdb, 0xef, 0x36, 0xa6, 0xe8, 0x3b,
      0x30, 0x2e, 0x90, 0x99, 0x20, 0x79, 0x33, 0x39,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char nav_interfaces__msg__HoleTraversalEvent__TYPE_NAME[] = "nav_interfaces/msg/HoleTraversalEvent";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__header[] = "header";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__session_id[] = "session_id";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__goal_id[] = "goal_id";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__plan_id[] = "plan_id";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__traversal_uid[] = "traversal_uid";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__sequence[] = "sequence";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__type[] = "type";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__event_arc[] = "event_arc";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__progress[] = "progress";
static char nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__attempt[] = "attempt";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__HoleTraversalEvent__FIELDS[] = {
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__session_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__goal_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__plan_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__traversal_uid, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__sequence, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__type, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__event_arc, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__progress, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalEvent__FIELD_NAME__attempt, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__msg__HoleTraversalEvent__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__msg__HoleTraversalEvent__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__HoleTraversalEvent__TYPE_NAME, 37, 37},
      {nav_interfaces__msg__HoleTraversalEvent__FIELDS, 10, 10},
    },
    {nav_interfaces__msg__HoleTraversalEvent__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe4\\xbe\\xa7\\xe5\\x8f\\x91\\xe5\\xb8\\x83 hole_traversal_event\\xef\\xbc\\x9a\\xe6\\x9f\\x90\\xe4\\xb8\\xaa\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe5\\xb7\\xb2\\xe8\\xa2\\xab\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe8\\xb0\\x83\\xe5\\xba\\xa6\\xe5\\x99\\xa8\\xe8\\xa7\\xa6\\xe5\\x8f\\x91\\xe7\\x9a\\x84\\xe9\\x80\\x9a\\xe7\\x9f\\xa5\\xe3\\x80\\x82\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe4\\xba\\xa4\\xe6\\x8e\\xa5\\xe6\\x96\\x87\\xe6\\xa1\\xa35.4\\xe3\\x80\\x817.3\\xef\\xbc\\x9b\\xe5\\x8c\\xba\\xe5\\x88\\xab\\xe4\\xba\\x8e\\xe4\\xbb\\x85\\xe6\\x8f\\x8f\\xe8\\xbf\\xb0\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe4\\xbd\\x8d\\xe7\\xbd\\xae\\xe7\\x9a\\x84HoleEvent\\xe3\\x80\\x82\n"
  "# \\xe6\\x8e\\xa5\\xe6\\x94\\xb6\\xe6\\x96\\xb9\\xe4\\xbb\\x8d\\xe9\\xa1\\xbb\\xe6\\x8c\\x89\\xe4\\xbc\\x9a\\xe8\\xaf\\x9d/\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1/\\xe9\\x80\\x9a\\xe8\\xa1\\x8c/\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe7\\xb1\\xbb\\xe5\\x9e\\x8b\\xe8\\xae\\xb0\\xe5\\xbd\\x95\\xe5\\x8e\\xbb\\xe9\\x87\\x8d\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe5\\x81\\x87\\xe8\\xae\\xbe\\xe5\\xa4\\x96\\xe9\\x83\\xa8\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe6\\x81\\xb0\\xe5\\xa5\\xbd\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe4\\xb8\\x80\\xe6\\xac\\xa1\\xe3\\x80\\x82\n"
  "\n"
  "# \\xe5\\x85\\xac\\xe5\\x85\\xb1\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe5\\xa4\\xb4\\xef\\xbc\\x9astamp\\xe4\\xb8\\xba\\xe5\\x8f\\x91\\xe9\\x80\\x81\\xe6\\x96\\xb9\\xe5\\xa1\\xab\\xe5\\x86\\x99\\xe7\\x9a\\x84ROS\\xe6\\x97\\xb6\\xe9\\x97\\xb4\\xef\\xbc\\x9bframe_id\\xe6\\xa0\\x87\\xe6\\xb3\\xa8\\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xe7\\xb3\\xbb\\xe3\\x80\\x82\\xe4\\xb8\\x8d\\xe4\\xbc\\x9a\\xe8\\x87\\xaa\\xe5\\x8a\\xa8\\xe5\\xa1\\xab\\xe6\\x97\\xb6\\xe9\\x97\\xb4\\xe6\\x88\\x96\\xe8\\xbd\\xac\\xe6\\x8d\\xa2\\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xe3\\x80\\x82\n"
  "std_msgs/Header header\n"
  "\n"
  "# \\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe8\\xbf\\x90\\xe8\\xa1\\x8c\\xe7\\x9a\\x84\\xe8\\xba\\xab\\xe4\\xbb\\xbd\\xef\\xbc\\x8c\\xe7\\xa8\\x8b\\xe5\\xba\\x8f\\xe8\\x87\\xaa\\xe5\\x8a\\xa8\\xe7\\x94\\x9f\\xe6\\x88\\x90\\xef\\xbc\\x9b\\xe9\\x87\\x8d\\xe5\\x90\\xaf\\xe6\\x97\\xb6\\xe6\\x9b\\xb4\\xe6\\x8d\\xa2\\xef\\xbc\\x8c\\xe5\\x90\\x8c\\xe6\\xac\\xa1\\xe8\\xbf\\x90\\xe8\\xa1\\x8c\\xe7\\x9a\\x84\\xe9\\x87\\x8d\\xe8\\xa7\\x84\\xe5\\x88\\x92\\xe4\\xb8\\x8d\\xe6\\x9b\\xb4\\xe6\\x8d\\xa2\\xe3\\x80\\x82\\xe7\\x94\\xa8\\xe4\\xba\\x8e\\xe6\\x8b\\x92\\xe7\\xbb\\x9d\\xe6\\x97\\xa7\\xe4\\xbc\\x9a\\xe8\\xaf\\x9d\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe3\\x80\\x82\n"
  "string session_id\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1\\xe7\\x9a\\x84\\xe8\\xba\\xab\\xe4\\xbb\\xbd\\xef\\xbc\\x9b\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe4\\xb8\\xaa\\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xe7\\x9a\\x84\\xe9\\x87\\x8d\\xe8\\xa7\\x84\\xe5\\x88\\x92\\xe4\\xbf\\x9d\\xe6\\x8c\\x81\\xe4\\xb8\\x8d\\xe5\\x8f\\x98\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe7\\x82\\xb9\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xe3\\x80\\x82\n"
  "string goal_id\n"
  "\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xef\\xbc\\x9b\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe4\\xbc\\x9a\\xe8\\xaf\\x9d\\xe5\\x86\\x85\\xe6\\x8e\\xa5\\xe7\\xba\\xb3\\xe6\\x96\\xb0\\xe7\\x89\\x88\\xe6\\x9c\\xac/\\xe5\\xa4\\xb1\\xe6\\x95\\x88\\xe7\\xad\\x89\\xe4\\xbc\\x9a\\xe6\\x9b\\xb4\\xe6\\x96\\xb0\\xe3\\x80\\x82\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe5\\x8d\\x95\\xe5\\x87\\xad\\xe6\\x8d\\xa2\\xe7\\x89\\x88\\xe9\\x87\\x8d\\xe5\\xa4\\x8d\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe5\\xb7\\xb2\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe3\\x80\\x82\n"
  "uint64 plan_id\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe8\\xa7\\xa6\\xe5\\x8f\\x91\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe5\\xb1\\x9e\\xe4\\xba\\x8e\\xe5\\x93\\xaa\\xe4\\xb8\\x80\\xe6\\xac\\xa1\\xe5\\x85\\xb7\\xe4\\xbd\\x93\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xef\\xbc\\x8c\\xe4\\xb8\\x8e\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe4\\xb8\\xad\\xe7\\x9a\\x84\\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe8\\xae\\xb0\\xe5\\xbd\\x95\\xe5\\x8c\\xb9\\xe9\\x85\\x8d\\xe3\\x80\\x82\n"
  "string traversal_uid\n"
  "\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe6\\x8e\\xa7\\xe5\\x88\\xb6\\xe5\\x99\\xa8\\xe5\\xae\\x9e\\xe4\\xbe\\x8b\\xe5\\x86\\x85\\xe9\\x80\\x92\\xe5\\xa2\\x9e\\xe7\\x9a\\x84\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe5\\xba\\x8f\\xe5\\x8f\\xb7\\xef\\xbc\\x8c\\xe4\\xbe\\xbf\\xe4\\xba\\x8e\\xe6\\x8e\\x92\\xe6\\x9f\\xa5\\xe9\\xa1\\xba\\xe5\\xba\\x8f\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe5\\x8d\\x95\\xe7\\x8b\\xac\\xe4\\xbd\\x9c\\xe4\\xb8\\xba\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe5\\x8e\\xbb\\xe9\\x87\\x8d\\xe9\\x94\\xae\\xe3\\x80\\x82\n"
  "uint64 sequence\n"
  "\n"
  "# \\xe5\\xb7\\xb2\\xe8\\xa7\\xa6\\xe5\\x8f\\x91\\xe7\\x9a\\x84\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe7\\xb1\\xbb\\xe5\\x9e\\x8b\\xef\\xbc\\x9a0 A\\xef\\xbc\\x8c1 S\\xef\\xbc\\x8c2 E\\xef\\xbc\\x8c3 X\\xef\\xbc\\x8c4 T\\xef\\xbc\\x8c5 D\\xe3\\x80\\x82\\xe9\\x80\\x9a\\xe7\\x9f\\xa5\\xe6\\x9c\\xac\\xe8\\xba\\xab\\xe4\\xb8\\x8d\\xe6\\x9b\\xbf\\xe4\\xbb\\xa3\\xe7\\x9c\\x9f\\xe5\\xae\\x9e\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe5\\x8f\\x8d\\xe9\\xa6\\x88\\xe3\\x80\\x82\n"
  "uint8 type\n"
  "\n"
  "# \\xe8\\xaf\\xa5\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe5\\x9c\\xa8\\xe8\\xa7\\xa6\\xe5\\x8f\\x91\\xe6\\x97\\xb6\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe4\\xb8\\x8a\\xe7\\x9a\\x84\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xe4\\xbd\\x8d\\xe7\\xbd\\xae\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xe3\\x80\\x82\n"
  "float64 event_arc\n"
  "\n"
  "# \\xe5\\xa4\\x84\\xe7\\x90\\x86\\xe8\\xaf\\xa5\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe6\\x97\\xb6\\xe5\\x8f\\x82\\xe8\\x80\\x83\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe5\\x8f\\xaf\\xe9\\x9d\\xa0\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe8\\xbf\\x9b\\xe5\\xba\\xa6\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xef\\xbc\\x8c\\xe5\\x8f\\xaf\\xe7\\x95\\xa5\\xe5\\xa4\\xa7\\xe4\\xba\\x8eevent_arc\\xe3\\x80\\x82\n"
  "float64 progress\n"
  "\n"
  "\n"
  "# \\xe6\\x89\\x80\\xe5\\xb1\\x9e\\xe5\\xb0\\x9d\\xe8\\xaf\\x95\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xef\\xbc\\x9b\\xe5\\x8e\\x86\\xe5\\x8f\\xb2\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe4\\xb8\\x8d\\xe5\\x9b\\xa0\\xe5\\x80\\x92\\xe9\\x80\\x80\\xe5\\x88\\xa0\\xe9\\x99\\xa4\\xe3\\x80\\x82\n"
  "uint32 attempt";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__HoleTraversalEvent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__HoleTraversalEvent__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 698, 698},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__HoleTraversalEvent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__HoleTraversalEvent__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
