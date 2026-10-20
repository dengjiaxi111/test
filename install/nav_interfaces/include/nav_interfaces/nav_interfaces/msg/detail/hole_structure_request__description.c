// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/hole_structure_request__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__HoleStructureRequest__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0xd5, 0x25, 0xd3, 0x3b, 0x49, 0xe4, 0xcd,
      0x2c, 0x35, 0x34, 0x0f, 0x00, 0x25, 0xae, 0x6c,
      0xb4, 0x63, 0x34, 0xa8, 0xbd, 0xba, 0xe9, 0xd2,
      0x08, 0x9d, 0xba, 0x96, 0x54, 0x4a, 0x42, 0x20,
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

static char nav_interfaces__msg__HoleStructureRequest__TYPE_NAME[] = "nav_interfaces/msg/HoleStructureRequest";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__header[] = "header";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__session_id[] = "session_id";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__goal_id[] = "goal_id";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__request_id[] = "request_id";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__requirement_revision[] = "requirement_revision";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__target[] = "target";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__traversal_uids[] = "traversal_uids";
static char nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__cancel_motion[] = "cancel_motion";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__HoleStructureRequest__FIELDS[] = {
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__session_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__goal_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__request_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__requirement_revision, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__target, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__traversal_uids, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStructureRequest__FIELD_NAME__cancel_motion, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__msg__HoleStructureRequest__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
nav_interfaces__msg__HoleStructureRequest__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__HoleStructureRequest__TYPE_NAME, 39, 39},
      {nav_interfaces__msg__HoleStructureRequest__FIELDS, 8, 8},
    },
    {nav_interfaces__msg__HoleStructureRequest__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
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
  "# \\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe4\\xbe\\xa7\\xe5\\x8f\\x91\\xe5\\xbe\\x80 hole_structure/request \\xe7\\x9a\\x84\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xef\\xbc\\x8c\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe6\\x8e\\xa7\\xe5\\x88\\xb6\\xe4\\xbe\\xa7\\xe6\\x8e\\xa5\\xe6\\x94\\xb6\\xe5\\xb9\\xb6\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe3\\x80\\x82\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe4\\xba\\xa4\\xe6\\x8e\\xa5\\xe6\\x96\\x87\\xe6\\xa1\\xa35.4\\xe3\\x80\\x817.3\\xe3\\x80\\x818\\xef\\xbc\\x9a\\xe8\\xaf\\xb7\\xe6\\xb1\\x82\\xe8\\xba\\xab\\xe4\\xbb\\xbd\\xe3\\x80\\x81\\xe4\\xbf\\xae\\xe8\\xae\\xa2\\xe3\\x80\\x81\\xe5\\x90\\x8c\\xe5\\xbd\\xa2\\xe6\\x80\\x81\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe5\\xa4\\x8d\\xe7\\x94\\xa8\\xe5\\x8f\\x8a\\xe5\\xa4\\x9a\\xe6\\xb4\\x9e\\xe9\\x9c\\x80\\xe6\\xb1\\x82\\xe3\\x80\\x82\n"
  "# \\xe7\\xbb\\x84\\xe7\\xbb\\x87\\xe6\\x96\\xb9\\xe5\\xbc\\x8f\\xe5\\x8f\\x82\\xe8\\x80\\x83\\xe6\\x97\\xa7stair_mode\\xef\\xbc\\x8c\\xe4\\xbd\\x86\\xe6\\x9c\\xac\\xe6\\x96\\x87\\xe4\\xbb\\xb6\\xe7\\x9a\\x84\\xe6\\x95\\xb0\\xe5\\xad\\x97\\xe5\\x90\\xab\\xe4\\xb9\\x89\\xe4\\xb8\\x8d\\xe5\\xa4\\x8d\\xe7\\x94\\xa8\\xe5\\x8f\\xb0\\xe9\\x98\\xb6\\xe6\\xa8\\xa1\\xe5\\xbc\\x8f\\xe5\\x80\\xbc\\xe3\\x80\\x82\n"
  "# LOW/NORMAL/KEEP\\xe5\\x85\\xb7\\xe4\\xbd\\x93\\xe6\\x80\\x8e\\xe6\\xa0\\xb7\\xe6\\x98\\xa0\\xe5\\xb0\\x84\\xe4\\xb8\\xba\\xe7\\x9c\\x9f\\xe5\\xae\\x9e\\xe4\\xb8\\x8b\\xe4\\xbd\\x8d\\xe6\\x9c\\xba\\xe6\\x8c\\x87\\xe4\\xbb\\xa4\\xef\\xbc\\x8c\\xe5\\xb0\\x9a\\xe9\\x9c\\x80\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe4\\xbe\\xa7\\xe5\\xae\\x9e\\xe7\\x8e\\xb0\\xe3\\x80\\x82\n"
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
  "# \\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe8\\xaf\\xb7\\xe6\\xb1\\x82\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xef\\xbc\\x9b\\xe6\\x96\\xb0\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe6\\x8d\\xa2\\xe5\\x8f\\xb7\\xef\\xbc\\x8c\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe4\\xb8\\xaa\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe7\\x9a\\x84\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe9\\x87\\x8d\\xe5\\x8f\\x91\\xe6\\xb2\\xbf\\xe7\\x94\\xa8\\xe5\\x8e\\x9f\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xe3\\x80\\x82\\xe5\\x8f\\x8d\\xe9\\xa6\\x88\\xe5\\xbf\\x85\\xe9\\xa1\\xbb\\xe5\\x9b\\x9e\\xe5\\xa1\\xab\\xe5\\x8c\\xb9\\xe9\\x85\\x8d\\xe3\\x80\\x82\n"
  "uint64 request_id\n"
  "\n"
  "# \\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe7\\x9a\\x84\\xe4\\xbf\\xae\\xe8\\xae\\xa2\\xe8\\xba\\xab\\xe4\\xbb\\xbd\\xef\\xbc\\x9b\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe5\\x8f\\x98\\xe5\\x8c\\x96\\xe5\\x90\\x8e\\xe6\\x97\\xa7\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xe5\\x8f\\x8d\\xe9\\xa6\\x88\\xe4\\xb8\\x8d\\xe5\\x8f\\xaf\\xe6\\x8e\\x88\\xe6\\x9d\\x83\\xe6\\x96\\xb0\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe3\\x80\\x82\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xe7\\xbb\\x84\\xe5\\x90\\x88\\xe7\\xae\\x97\\xe6\\xb3\\x95\\xe4\\xbb\\x8d\\xe5\\xbe\\x85\\xe5\\xae\\x8c\\xe5\\x96\\x84\\xe3\\x80\\x82\n"
  "uint64 requirement_revision\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f0\\xef\\xbc\\x9a\\xe4\\xbf\\x9d\\xe6\\x8c\\x81\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe9\\x80\\x82\\xe7\\x94\\xa8\\xe5\\xbd\\xa2\\xe6\\x80\\x81\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe7\\xad\\x89\\xe4\\xba\\x8e\\xe6\\xad\\xa3\\xe5\\xb8\\xb8\\xe5\\xa7\\xbf\\xe6\\x80\\x81\\xef\\xbc\\x9b\\xe4\\xb8\\xad\\xe9\\x97\\xb4\\xe4\\xbd\\x8d\\xe7\\xbd\\xae\\xe5\\xa6\\x82\\xe4\\xbd\\x95\\xe5\\xae\\x89\\xe5\\x85\\xa8\\xe4\\xbf\\x9d\\xe6\\x8c\\x81\\xe9\\xa1\\xbb\\xe7\\x94\\xb1\\xe7\\x9c\\x9f\\xe5\\xae\\x9e\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe4\\xbe\\xa7\\xe5\\xae\\x9a\\xe4\\xb9\\x89\\xe3\\x80\\x82\n"
  "uint8 KEEP=0\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f1\\xef\\xbc\\x9a\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe4\\xbd\\x8e\\xe5\\xa7\\xbf\\xe6\\x80\\x81\\xef\\xbc\\x9b\\xe5\\x85\\xb7\\xe4\\xbd\\x93\\xe8\\x85\\xbf\\xe9\\x95\\xbf/\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe5\\x99\\xa8\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xe7\\x94\\xb1\\xe7\\x9c\\x9f\\xe5\\xae\\x9e\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe6\\x8e\\xa5\\xe5\\x8f\\xa3\\xe5\\xae\\x9a\\xe4\\xb9\\x89\\xe3\\x80\\x82\n"
  "uint8 LOW=1\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f2\\xef\\xbc\\x9a\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe6\\xad\\xa3\\xe5\\xb8\\xb8\\xe5\\xa7\\xbf\\xe6\\x80\\x81\\xef\\xbc\\x9b\\xe4\\xb8\\x8eKEEP\\xe4\\xb8\\x8d\\xe5\\x90\\x8c\\xef\\xbc\\x8c\\xe5\\xba\\x94\\xe5\\x9c\\xa8\\xe9\\x87\\x8a\\xe6\\x94\\xbe\\xe5\\x92\\x8c\\xe5\\x87\\x80\\xe7\\xa9\\xba\\xe6\\x9d\\xa1\\xe4\\xbb\\xb6\\xe6\\x88\\x90\\xe7\\xab\\x8b\\xe5\\x90\\x8e\\xe8\\xaf\\xb7\\xe6\\xb1\\x82\\xe3\\x80\\x82\n"
  "uint8 NORMAL=2\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe5\\xae\\x9e\\xe9\\x99\\x85\\xe7\\x9b\\xae\\xe6\\xa0\\x87\\xef\\xbc\\x8c\\xe5\\xa1\\xabKEEP/LOW/NORMAL\\xef\\xbc\\x9b\\xe4\\xb8\\x8a\\xe9\\x9d\\xa2\\xe7\\x9a\\x84\\xe5\\xb8\\xb8\\xe9\\x87\\x8f\\xe4\\xb8\\x8d\\xe4\\xbc\\x9a\\xe8\\x87\\xaa\\xe5\\x8a\\xa8\\xe8\\xb5\\x8b\\xe7\\xbb\\x99\\xe5\\xae\\x83\\xef\\xbc\\x8c\\xe9\\xa1\\xbb\\xe5\\x8f\\x91\\xe9\\x80\\x81\\xe4\\xbb\\xa3\\xe7\\xa0\\x81\\xe6\\x98\\xbe\\xe5\\xbc\\x8f\\xe5\\xa1\\xab\\xe5\\x86\\x99\\xe3\\x80\\x82\n"
  "uint8 target\n"
  "\n"
  "# \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe5\\x85\\xb1\\xe5\\x90\\x8c\\xe9\\x9c\\x80\\xe8\\xa6\\x81\\xe8\\xaf\\xa5\\xe5\\xa7\\xbf\\xe6\\x80\\x81\\xe7\\x9a\\x84\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe7\\xbc\\x96\\xe5\\x8f\\xb7\\xe5\\x88\\x97\\xe8\\xa1\\xa8\\xef\\xbc\\x9b\\xe8\\xbf\\x9e\\xe7\\xbb\\xad\\xe4\\xb8\\xa4\\xe6\\xb4\\x9e\\xe5\\x8f\\xaf\\xe5\\x90\\x8c\\xe6\\x97\\xb6\\xe5\\xad\\x98\\xe5\\x9c\\xa8\\xef\\xbc\\x8c\\xe5\\x90\\x8c\\xe5\\xbd\\xa2\\xe6\\x80\\x81\\xe5\\x8f\\xaf\\xe5\\xa4\\x8d\\xe7\\x94\\xa8\\xe5\\x8a\\xa8\\xe4\\xbd\\x9c\\xe3\\x80\\x82\n"
  "string[] traversal_uids\n"
  "\n"
  "# \\xe5\\x8f\\x96\\xe6\\xb6\\x88\\xe7\\x9a\\x84\\xe6\\x98\\xaf\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe5\\x8f\\x98\\xe5\\xbd\\xa2\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe5\\xba\\x95\\xe7\\x9b\\x98\\xe8\\xbf\\x90\\xe5\\x8a\\xa8\\xef\\xbc\\x9b\\xe8\\x8d\\x89\\xe7\\xa8\\xbf\\xe7\\x94\\xa8true\\xe9\\x85\\x8dKEEP\\xe6\\x8c\\x89session/goal\\xe5\\x81\\x9c\\xe6\\xad\\xa2\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe5\\x8f\\x98\\xe5\\xbd\\xa2\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x87\\xaa\\xe5\\x8a\\xa8\\xe6\\x8a\\xac\\xe9\\xab\\x98\\xe3\\x80\\x82request_id=0\\xe4\\xb8\\xba\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1\\xe7\\xba\\xa7\\xe5\\x8f\\x96\\xe6\\xb6\\x88\\xe7\\xba\\xa6\\xe5\\xae\\x9a\\xef\\xbc\\x8c\\xe7\\x9c\\x9f\\xe5\\xae\\x9e\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe4\\xbe\\xa7\\xe5\\xb0\\x9a\\xe9\\x9c\\x80\\xe5\\xae\\x9e\\xe7\\x8e\\xb0\\xe3\\x80\\x82\n"
  "bool cancel_motion\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__HoleStructureRequest__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__HoleStructureRequest__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 898, 898},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__HoleStructureRequest__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__HoleStructureRequest__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
