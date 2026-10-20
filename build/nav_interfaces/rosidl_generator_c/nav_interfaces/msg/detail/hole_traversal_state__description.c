// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/hole_traversal_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__HoleTraversalState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5a, 0x50, 0x89, 0x77, 0xab, 0x5f, 0xb3, 0xe7,
      0xa1, 0x5c, 0x26, 0x06, 0xcf, 0x0a, 0x0a, 0x9e,
      0x97, 0x42, 0x83, 0xf9, 0x02, 0x9d, 0x31, 0x0f,
      0x12, 0x2d, 0xb8, 0x65, 0x69, 0xdf, 0x9f, 0x5a,
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

static char nav_interfaces__msg__HoleTraversalState__TYPE_NAME[] = "nav_interfaces/msg/HoleTraversalState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__header[] = "header";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__session_id[] = "session_id";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__goal_id[] = "goal_id";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__plan_id[] = "plan_id";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__state[] = "state";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__decision[] = "decision";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__s_progress[] = "s_progress";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__speed_limit[] = "speed_limit";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__reason[] = "reason";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__traversal_uids[] = "traversal_uids";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__phases[] = "phases";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__preparing_required[] = "preparing_required";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__attempt[] = "attempt";
static char nav_interfaces__msg__HoleTraversalState__FIELD_NAME__recovery_phase[] = "recovery_phase";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__HoleTraversalState__FIELDS[] = {
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__session_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__goal_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__plan_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__decision, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__s_progress, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__speed_limit, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__reason, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__traversal_uids, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__phases, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__preparing_required, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__attempt, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversalState__FIELD_NAME__recovery_phase, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__msg__HoleTraversalState__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
nav_interfaces__msg__HoleTraversalState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__HoleTraversalState__TYPE_NAME, 37, 37},
      {nav_interfaces__msg__HoleTraversalState__FIELDS, 14, 14},
    },
    {nav_interfaces__msg__HoleTraversalState__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
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
  "# \\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe4\\xbe\\xa7\\xe5\\x8f\\x91\\xe5\\xb8\\x83 hole_traversal_state\\xef\\xbc\\x9a\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe4\\xba\\x94\\xe6\\x80\\x81\\xe3\\x80\\x81\\xe5\\x86\\xb3\\xe7\\xad\\x96\\xe3\\x80\\x81\\xe8\\xbf\\x9b\\xe5\\xba\\xa6\\xe5\\x92\\x8c\\xe9\\x80\\x90\\xe6\\xb4\\x9e\\xe9\\x98\\xb6\\xe6\\xae\\xb5\\xe3\\x80\\x82\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe4\\xba\\xa4\\xe6\\x8e\\xa5\\xe6\\x96\\x87\\xe6\\xa1\\xa35.4\\xe3\\x80\\x817.1\\xe3\\x80\\x82\\xe7\\x94\\xa8\\xe4\\xba\\x8e\\xe8\\xa7\\x82\\xe5\\xaf\\x9f\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xef\\xbc\\x9b\\xe6\\x9c\\xac\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe7\\x8b\\xac\\xe7\\xab\\x8b\\xe7\\x9a\\x84\\xe8\\xbf\\x90\\xe5\\x8a\\xa8\\xe8\\xae\\xb8\\xe5\\x8f\\xaf\\xe5\\x8d\\x8f\\xe8\\xae\\xae\\xe3\\x80\\x82\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe4\\xbf\\xa1\\xe6\\x81\\xaf\\xe5\\x8f\\xaa\\xe5\\x8c\\x85\\xe5\\x90\\xab\\xe9\\x9c\\x80\\xe6\\xb1\\x82\\xe6\\xa0\\x87\\xe8\\xae\\xb0\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe8\\xa1\\xa8\\xe8\\xbe\\xbe\\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe4\\xb8\\xad/\\xe5\\xb0\\xb1\\xe7\\xbb\\xaa/\\xe6\\x95\\x85\\xe9\\x9a\\x9c\\xef\\xbc\\x9b\\xe6\\xad\\xa4\\xe4\\xb8\\xba\\xe8\\x8d\\x89\\xe7\\xa8\\xbf\\xe7\\xbc\\xba\\xe5\\x8f\\xa3\\xe3\\x80\\x82\n"
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
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe4\\xba\\x94\\xe6\\x80\\x81\\xe7\\xbc\\x96\\xe7\\xa0\\x81\\xef\\xbc\\x9a0 NORMAL\\xef\\xbc\\x8c1 PREPARE\\xef\\xbc\\x8c2 TRAVERSE\\xef\\xbc\\x8c3 RESTORE\\xef\\xbc\\x8c4 HOLD\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe9\\xa1\\xb6\\xe5\\xb1\\x82\\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe7\\x8a\\xb6\\xe6\\x80\\x81\\xe3\\x80\\x82\n"
  "uint8 state\n"
  "\n"
  "# \\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe5\\x86\\xb3\\xe7\\xad\\x96\\xe7\\xbc\\x96\\xe7\\xa0\\x81\\xef\\xbc\\x9a0 CONTINUE\\xef\\xbc\\x8c1 STOP\\xef\\xbc\\x8c2 REPLAN\\xef\\xbc\\x8c3 RECOVERY\\xef\\xbc\\x8c4 FAILURE\\xef\\xbc\\x9bHOLD\\xe7\\x8a\\xb6\\xe6\\x80\\x81\\xe5\\x8f\\xaf\\xe8\\xbe\\x93\\xe5\\x87\\xba\\xe4\\xb8\\x8d\\xe5\\x90\\x8c\\xe5\\x86\\xb3\\xe7\\xad\\x96\\xe3\\x80\\x82\n"
  "uint8 decision\n"
  "\n"
  "# \\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe5\\x8f\\x82\\xe8\\x80\\x83\\xe7\\x82\\xb9\\xe5\\x9c\\xa8\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe4\\xb8\\x8a\\xe7\\x9a\\x84\\xe5\\x8f\\xaf\\xe9\\x9d\\xa0\\xe7\\xb4\\xaf\\xe8\\xae\\xa1\\xe8\\xbf\\x9b\\xe5\\xba\\xa6\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe6\\x80\\xbb\\xe9\\x87\\x8c\\xe7\\xa8\\x8b\\xe3\\x80\\x82\n"
  "float64 s_progress\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe5\\x91\\xa8\\xe6\\x9c\\x9f\\xe5\\x85\\x81\\xe8\\xae\\xb8\\xe7\\x9a\\x84\\xe5\\xb9\\xb3\\xe7\\xa7\\xbb\\xe9\\x80\\x9f\\xe5\\xba\\xa6\\xe6\\xa8\\xa1\\xe9\\x95\\xbf\\xe4\\xb8\\x8a\\xe9\\x99\\x90\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm/s\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe5\\x8d\\x95\\xe5\\x87\\xad\\xe8\\xa7\\x82\\xe5\\xaf\\x9f\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe7\\xbb\\x95\\xe8\\xbf\\x87\\xe8\\xbf\\x90\\xe5\\x8a\\xa8\\xe8\\xae\\xb8\\xe5\\x8f\\xaf\\xe3\\x80\\x82\n"
  "float64 speed_limit\n"
  "\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe7\\x8a\\xb6\\xe6\\x80\\x81/\\xe5\\x86\\xb3\\xe7\\xad\\x96\\xe6\\x88\\x96\\xe6\\x9a\\x82\\xe5\\x81\\x9c\\xe5\\x8e\\x9f\\xe5\\x9b\\xa0\\xe7\\x9a\\x84\\xe8\\xaf\\xb4\\xe6\\x98\\x8e\\xe6\\x96\\x87\\xe5\\xad\\x97\\xef\\xbc\\x9b\\xe8\\x8d\\x89\\xe7\\xa8\\xbf\\xe9\\x83\\xa8\\xe5\\x88\\x86\\xe5\\x88\\x86\\xe6\\x94\\xaf\\xe4\\xbb\\x8d\\xe6\\xaf\\x94\\xe8\\xbe\\x83\\xe5\\xad\\x97\\xe7\\xac\\xa6\\xe4\\xb8\\xb2\\xef\\xbc\\x8c\\xe5\\xb0\\x9a\\xe9\\x9d\\x9e\\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe6\\x95\\x85\\xe9\\x9a\\x9c\\xe7\\xa0\\x81\\xe5\\x8d\\x8f\\xe8\\xae\\xae\\xe3\\x80\\x82\n"
  "string reason\n"
  "\n"
  "# \\xe6\\xa0\\xb8\\xe5\\xbf\\x83\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe4\\xbf\\x9d\\xe7\\x95\\x99\\xe7\\x9a\\x84\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xe5\\x88\\x97\\xe8\\xa1\\xa8\\xef\\xbc\\x8c\\xe5\\x8f\\xaf\\xe8\\x83\\xbd\\xe5\\x8c\\x85\\xe5\\x90\\xab\\xe5\\xb7\\xb2\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xe8\\xae\\xb0\\xe5\\xbd\\x95\\xef\\xbc\\x9b\\xe9\\xa1\\xba\\xe5\\xba\\x8f\\xe4\\xb8\\x8e\\xe4\\xb8\\x8b\\xe9\\x9d\\xa2\\xe4\\xb8\\xa4\\xe4\\xb8\\xaa\\xe6\\x95\\xb0\\xe7\\xbb\\x84\\xe5\\xbf\\x85\\xe9\\xa1\\xbb\\xe4\\xb8\\x80\\xe4\\xb8\\x80\\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe3\\x80\\x82\n"
  "string[] traversal_uids\n"
  "\n"
  "# \\xe9\\x80\\x90\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe7\\xa9\\xba\\xe9\\x97\\xb4\\xe9\\x98\\xb6\\xe6\\xae\\xb5\\xef\\xbc\\x9a0 PENDING\\xef\\xbc\\x8c1 ENTRY_STRAIGHT\\xef\\xbc\\x8c2 IN_HOLE\\xef\\xbc\\x8c3 EXIT_STRAIGHT\\xef\\xbc\\x8c4 DEPARTING\\xef\\xbc\\x8c5 COMPLETE\\xe3\\x80\\x82\\xe5\\x88\\xb0D\\xe5\\x8f\\xaf\\xe5\\x85\\x88\\xe6\\xa0\\x87\\xe8\\xae\\xb0COMPLETE\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe5\\x8d\\x95\\xe5\\x87\\xad\\xe6\\xad\\xa4\\xe5\\x80\\xbc\\xe8\\xaf\\x81\\xe6\\x98\\x8e\\xe5\\x8d\\xa0\\xe7\\x94\\xa8\\xe5\\xb7\\xb2\\xe9\\x87\\x8a\\xe6\\x94\\xbe\\xe3\\x80\\x82\n"
  "uint8[] phases\n"
  "\n"
  "# \\xe9\\x80\\x90\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe7\\x9a\\x84\\xe7\\xbb\\x93\\xe6\\x9e\\x84\\xe9\\x9c\\x80\\xe6\\xb1\\x82\\xe6\\xa0\\x87\\xe8\\xae\\xb0\\xef\\xbc\\x8c\\xe5\\xae\\x9e\\xe9\\x99\\x85\\xe6\\x9d\\xa5\\xe8\\x87\\xaaVisit.demand\\xef\\xbc\\x9btrue\\xe4\\xb8\\x8d\\xe4\\xbb\\xa3\\xe8\\xa1\\xa8\\xe6\\xad\\xa3\\xe5\\x9c\\xa8\\xe5\\x8f\\x98\\xe5\\xbd\\xa2\\xef\\xbc\\x8c\\xe4\\xb9\\x9f\\xe4\\xb8\\x8d\\xe8\\xaf\\x81\\xe6\\x98\\x8e\\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xef\\xbc\\x8c\\xe8\\xbf\\x9b\\xe5\\x85\\xa5\\xe6\\xb4\\x9e\\xe5\\x86\\x85\\xe5\\x90\\x8e\\xe4\\xbb\\x8d\\xe5\\x8f\\xaf\\xe4\\xb8\\xbatrue\\xe3\\x80\\x82\n"
  "bool[] preparing_required\n"
  "\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe5\\xb0\\x9d\\xe8\\xaf\\x95\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xef\\xbc\\x8c0\\xe4\\xb8\\xba\\xe9\\xa6\\x96\\xe6\\xac\\xa1\\xef\\xbc\\x8c1/2\\xe4\\xb8\\xba\\xe4\\xb8\\xa4\\xe6\\xac\\xa1\\xe9\\x87\\x8d\\xe8\\xaf\\x95\\xe3\\x80\\x82\n"
  "uint32 attempt\n"
  "# \\xe4\\xb8\\x93\\xe7\\x94\\xa8\\xe6\\x81\\xa2\\xe5\\xa4\\x8d\\xe9\\x98\\xb6\\xe6\\xae\\xb5\\xef\\xbc\\x9a0\\xe6\\x97\\xa0\\xef\\xbc\\x8c1\\xe5\\x81\\x9c\\xe7\\xa8\\xb3\\xef\\xbc\\x8c2\\xe6\\xa0\\xa1\\xe9\\xaa\\x8c\\xef\\xbc\\x8c3\\xe9\\x80\\x80\\xe8\\xae\\xa9\\xef\\xbc\\x8c4\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xe5\\x81\\x9c\\xe7\\xa8\\xb3\\xef\\xbc\\x8c5\\xe9\\x87\\x8d\\xe5\\x85\\xa5\\xe6\\xa3\\x80\\xe6\\x9f\\xa5\\xe3\\x80\\x82\n"
  "uint8 recovery_phase";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__HoleTraversalState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__HoleTraversalState__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1115, 1115},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__HoleTraversalState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__HoleTraversalState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
