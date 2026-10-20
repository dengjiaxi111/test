// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/msg/detail/navigation_plan__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__msg__NavigationPlan__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8f, 0xc9, 0xd5, 0xc9, 0x41, 0x06, 0x30, 0x09,
      0x7a, 0xee, 0x7e, 0x25, 0xef, 0xd0, 0xc9, 0x94,
      0x60, 0xbf, 0x56, 0x93, 0x41, 0xd4, 0x5e, 0x58,
      0xd6, 0x0e, 0xf8, 0x43, 0xde, 0x31, 0xfb, 0x77,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
#include "nav_msgs/msg/detail/path__functions.h"
#include "nav_interfaces/msg/detail/hole_event__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "nav_interfaces/msg/detail/hole_straight__functions.h"
#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Pose__EXPECTED_HASH = {1, {
    0xd5, 0x01, 0x95, 0x4e, 0x94, 0x76, 0xce, 0xa2,
    0x99, 0x69, 0x84, 0xe8, 0x12, 0x05, 0x4b, 0x68,
    0x02, 0x6a, 0xe0, 0xbf, 0xae, 0x78, 0x9d, 0x9a,
    0x10, 0xb2, 0x3d, 0xaf, 0x35, 0xcc, 0x90, 0xfa,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__PoseStamped__EXPECTED_HASH = {1, {
    0x10, 0xf3, 0x78, 0x6d, 0x7d, 0x40, 0xfd, 0x2b,
    0x54, 0x36, 0x78, 0x35, 0x61, 0x4b, 0xff, 0x85,
    0xd4, 0xad, 0x3b, 0x5d, 0xab, 0x62, 0xbf, 0x8b,
    0xca, 0x0c, 0xc2, 0x32, 0xd7, 0x3b, 0x4c, 0xd8,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
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
static const rosidl_type_hash_t nav_interfaces__msg__HoleSpeedRegion__EXPECTED_HASH = {1, {
    0x8a, 0x70, 0x03, 0xe3, 0x70, 0x6c, 0x6a, 0x11,
    0x88, 0x2d, 0x65, 0x86, 0x0d, 0x02, 0xbe, 0xdd,
    0x7c, 0xe5, 0xc8, 0x42, 0x05, 0xdb, 0xf0, 0x3f,
    0xf1, 0x54, 0xe4, 0x28, 0x07, 0x85, 0xc2, 0x69,
  }};
static const rosidl_type_hash_t nav_interfaces__msg__HoleStraight__EXPECTED_HASH = {1, {
    0xd5, 0x7d, 0x24, 0x69, 0xe4, 0xa3, 0x23, 0xf3,
    0x8f, 0xe1, 0x7c, 0xc4, 0x78, 0x60, 0xef, 0xc9,
    0x9d, 0x3d, 0xa8, 0x12, 0x28, 0x09, 0x6a, 0x32,
    0xe6, 0xab, 0x56, 0x92, 0x79, 0xb2, 0x33, 0xcc,
  }};
static const rosidl_type_hash_t nav_interfaces__msg__HoleTraversal__EXPECTED_HASH = {1, {
    0x93, 0x7b, 0x9d, 0x61, 0xbb, 0xab, 0x5b, 0xf0,
    0x1e, 0x37, 0x0f, 0xad, 0x60, 0x48, 0x25, 0x38,
    0x2e, 0xde, 0x0c, 0xab, 0x72, 0xa4, 0x58, 0xad,
    0x9e, 0xa0, 0x42, 0xba, 0x5f, 0xb6, 0x10, 0x1e,
  }};
static const rosidl_type_hash_t nav_msgs__msg__Path__EXPECTED_HASH = {1, {
    0x19, 0x57, 0xa5, 0xbb, 0x3c, 0xee, 0x5d, 0xa6,
    0x5c, 0x4e, 0x52, 0xe5, 0x2b, 0x65, 0xa9, 0x3d,
    0xf2, 0x27, 0xef, 0xce, 0x4c, 0x20, 0xf8, 0x45,
    0x8b, 0x36, 0xe7, 0x30, 0x66, 0xca, 0x33, 0x4b,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char nav_interfaces__msg__NavigationPlan__TYPE_NAME[] = "nav_interfaces/msg/NavigationPlan";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__PoseStamped__TYPE_NAME[] = "geometry_msgs/msg/PoseStamped";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char nav_interfaces__msg__HoleEvent__TYPE_NAME[] = "nav_interfaces/msg/HoleEvent";
static char nav_interfaces__msg__HoleSpeedRegion__TYPE_NAME[] = "nav_interfaces/msg/HoleSpeedRegion";
static char nav_interfaces__msg__HoleStraight__TYPE_NAME[] = "nav_interfaces/msg/HoleStraight";
static char nav_interfaces__msg__HoleTraversal__TYPE_NAME[] = "nav_interfaces/msg/HoleTraversal";
static char nav_msgs__msg__Path__TYPE_NAME[] = "nav_msgs/msg/Path";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__header[] = "header";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__session_id[] = "session_id";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__goal_id[] = "goal_id";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__plan_id[] = "plan_id";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__status[] = "status";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__reason[] = "reason";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__constraints_enabled[] = "constraints_enabled";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__terrain_revision[] = "terrain_revision";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__parameter_revision[] = "parameter_revision";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__map_revision[] = "map_revision";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__path[] = "path";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__path_length[] = "path_length";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__passages[] = "passages";
static char nav_interfaces__msg__NavigationPlan__FIELD_NAME__speed_regions[] = "speed_regions";

static rosidl_runtime_c__type_description__Field nav_interfaces__msg__NavigationPlan__FIELDS[] = {
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__session_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__goal_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__plan_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__reason, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__constraints_enabled, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__terrain_revision, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__parameter_revision, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__map_revision, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__path, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_msgs__msg__Path__TYPE_NAME, 17, 17},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__path_length, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__passages, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {nav_interfaces__msg__HoleTraversal__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__NavigationPlan__FIELD_NAME__speed_regions, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {nav_interfaces__msg__HoleSpeedRegion__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__msg__NavigationPlan__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
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
    {nav_interfaces__msg__HoleSpeedRegion__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleStraight__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__msg__HoleTraversal__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {nav_msgs__msg__Path__TYPE_NAME, 17, 17},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__msg__NavigationPlan__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__msg__NavigationPlan__TYPE_NAME, 33, 33},
      {nav_interfaces__msg__NavigationPlan__FIELDS, 14, 14},
    },
    {nav_interfaces__msg__NavigationPlan__REFERENCED_TYPE_DESCRIPTIONS, 12, 12},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__PoseStamped__EXPECTED_HASH, geometry_msgs__msg__PoseStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__PoseStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_interfaces__msg__HoleEvent__EXPECTED_HASH, nav_interfaces__msg__HoleEvent__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = nav_interfaces__msg__HoleEvent__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_interfaces__msg__HoleSpeedRegion__EXPECTED_HASH, nav_interfaces__msg__HoleSpeedRegion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = nav_interfaces__msg__HoleSpeedRegion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_interfaces__msg__HoleStraight__EXPECTED_HASH, nav_interfaces__msg__HoleStraight__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = nav_interfaces__msg__HoleStraight__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_interfaces__msg__HoleTraversal__EXPECTED_HASH, nav_interfaces__msg__HoleTraversal__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[9].fields = nav_interfaces__msg__HoleTraversal__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&nav_msgs__msg__Path__EXPECTED_HASH, nav_msgs__msg__Path__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[10].fields = nav_msgs__msg__Path__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[11].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xef\\xbc\\x9b\\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe4\\xbe\\xa7\\xe5\\x8f\\x91\\xe5\\xb8\\x83\\xe5\\x88\\xb0 navigation_plan\\xef\\xbc\\x8c\\xe4\\xbe\\x9b\\xe6\\x89\\xa7\\xe8\\xa1\\x8c/\\xe8\\xa7\\x82\\xe5\\xaf\\x9f\\xe6\\x96\\xb9\\xe8\\xaf\\xbb\\xe5\\x8f\\x96\\xe3\\x80\\x82\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe4\\xba\\xa4\\xe6\\x8e\\xa5\\xe6\\x96\\x87\\xe6\\xa1\\xa35.1\\xef\\xbc\\x9b\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe3\\x80\\x81\\xe9\\x80\\x90\\xe6\\xb4\\x9e\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe5\\x92\\x8c\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xe4\\xb8\\x80\\xe8\\xb5\\xb7\\xe5\\x8f\\x91\\xe9\\x80\\x81\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe6\\xb7\\xb7\\xe7\\x94\\xa8\\xe4\\xb8\\x8d\\xe5\\x90\\x8c\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe7\\x9a\\x84\\xe6\\x95\\xb0\\xe6\\x8d\\xae\\xe3\\x80\\x82\n"
  "# speed_regions \\xe6\\x98\\xaf\\xe4\\xb8\\xba\\xe5\\x88\\x86\\xe6\\xae\\xb5\\xe9\\x99\\x90\\xe9\\x80\\x9f\\xe8\\xa1\\xa5\\xe5\\x85\\x85\\xe7\\x9a\\x84\\xe8\\xae\\xbe\\xe8\\xae\\xa1\\xe3\\x80\\x82\\xe6\\xad\\xa4\\xe6\\x96\\x87\\xe4\\xbb\\xb6\\xe4\\xbb\\x8d\\xe6\\x98\\xaf\\xe5\\xae\\xa1\\xe9\\x98\\x85\\xe7\\xa8\\xbf\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe8\\xa7\\x86\\xe4\\xb8\\xba\\xe5\\xae\\x9e\\xe8\\xbd\\xa6\\xe5\\xb7\\xb2\\xe6\\x8e\\xa5\\xe9\\x80\\x9a\\xe3\\x80\\x82\n"
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
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f0\\xef\\xbc\\x9a\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe6\\x9c\\x89\\xe6\\x95\\x88\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe3\\x80\\x82\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe7\\xbb\\x99status\\xe8\\x87\\xaa\\xe5\\x8a\\xa8\\xe8\\xb5\\x8b\\xe5\\x80\\xbc\\xe3\\x80\\x82\n"
  "uint8 ACTIVE=0\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f1\\xef\\xbc\\x9a\\xe6\\x97\\xa7\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe5\\xb7\\xb2\\xe5\\xa4\\xb1\\xe6\\x95\\x88\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe5\\x8f\\xaf\\xe7\\xbb\\xa7\\xe7\\xbb\\xad\\xe6\\x89\\xa7\\xe8\\xa1\\x8c\\xe3\\x80\\x82\n"
  "uint8 INVALIDATED=1\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f2\\xef\\xbc\\x9a\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1\\xe5\\xb7\\xb2\\xe5\\x8f\\x96\\xe6\\xb6\\x88\\xe3\\x80\\x82\n"
  "uint8 CANCELLED=2\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f3\\xef\\xbc\\x9a\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1\\xe5\\xb7\\xb2\\xe7\\xbb\\x93\\xe6\\x9d\\x9f\\xe4\\xb8\\xba\\xe6\\x88\\x90\\xe5\\x8a\\x9f\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe5\\x8d\\x95\\xe5\\x87\\xad\\xe6\\xad\\xa4\\xe5\\x80\\xbc\\xe8\\xa7\\xa3\\xe9\\x99\\xa4\\xe6\\xb4\\x9e\\xe5\\x86\\x85\\xe7\\xbb\\x93\\xe6\\x9e\\x84\\xe8\\xa6\\x81\\xe6\\xb1\\x82\\xe3\\x80\\x82\n"
  "uint8 COMPLETED=3\n"
  "\n"
  "# \\xe5\\xb8\\xb8\\xe9\\x87\\x8f4\\xef\\xbc\\x9a\\xe4\\xbb\\xbb\\xe5\\x8a\\xa1\\xe5\\xa4\\xb1\\xe8\\xb4\\xa5\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe6\\x84\\x8f\\xe5\\x91\\xb3\\xe7\\x9d\\x80\\xe5\\x8f\\xaf\\xe4\\xbb\\xa5\\xe8\\x87\\xaa\\xe5\\x8a\\xa8\\xe6\\x8a\\xac\\xe9\\xab\\x98\\xe5\\xa7\\xbf\\xe6\\x80\\x81\\xe3\\x80\\x82\n"
  "uint8 FAILED=4\n"
  "\n"
  "# \\xe5\\xae\\x9e\\xe9\\x99\\x85\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe7\\x8a\\xb6\\xe6\\x80\\x81\\xef\\xbc\\x8c\\xe4\\xbd\\xbf\\xe7\\x94\\xa8\\xe4\\xb8\\x8a\\xe9\\x9d\\xa2\\xe7\\x9a\\x840\\xe2\\x80\\x944\\xef\\xbc\\x9bACTIVE\\xe4\\xb8\\x94passages\\xe4\\xb8\\xba\\xe7\\xa9\\xba\\xe8\\xa1\\xa8\\xe7\\xa4\\xba\\xe6\\x9c\\x89\\xe6\\x95\\x88\\xe6\\x97\\xa0\\xe6\\xb4\\x9e\\xe8\\xb7\\xaf\\xe7\\xba\\xbf\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe7\\xad\\x89\\xe4\\xba\\x8e\\xe5\\xa4\\xb1\\xe6\\x95\\x88\\xe3\\x80\\x82\n"
  "uint8 status\n"
  "\n"
  "# \\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe7\\x8a\\xb6\\xe6\\x80\\x81\\xe5\\x8e\\x9f\\xe5\\x9b\\xa0\\xe8\\xaf\\xb4\\xe6\\x98\\x8e\\xef\\xbc\\x8c\\xe4\\xbe\\x8b\\xe5\\xa6\\x82\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe5\\x8f\\x97\\xe9\\x98\\xbb\\xef\\xbc\\x9b\\xe8\\xbf\\x99\\xe6\\x98\\xaf\\xe8\\xaf\\xb4\\xe6\\x98\\x8e\\xe6\\x96\\x87\\xe5\\xad\\x97\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe5\\xba\\x94\\xe4\\xbe\\x9d\\xe8\\xb5\\x96\\xe8\\xa7\\xa3\\xe6\\x9e\\x90\\xe6\\x96\\x87\\xe6\\x9c\\xac\\xe4\\xbd\\x9c\\xe4\\xb8\\xba\\xe7\\xa8\\xb3\\xe5\\xae\\x9a\\xe5\\x8d\\x8f\\xe8\\xae\\xae\\xe3\\x80\\x82\n"
  "string reason\n"
  "\n"
  "# \\xe8\\xaf\\xa5\\xe8\\xae\\xa1\\xe5\\x88\\x92\\xe6\\x98\\xaf\\xe5\\x90\\xa6\\xe5\\xa3\\xb0\\xe6\\x98\\x8e\\xe5\\x90\\xaf\\xe7\\x94\\xa8\\xe8\\xbf\\x87\\xe6\\xb4\\x9e\\xe8\\xa7\\x84\\xe5\\x88\\x92/\\xe6\\xa0\\xa1\\xe9\\xaa\\x8c\\xe7\\xba\\xa6\\xe6\\x9d\\x9f\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe7\\xad\\x89\\xe5\\x90\\x8c\\xe4\\xba\\x8e\\xe6\\x9c\\xba\\xe6\\x9e\\x84\\xe5\\xb7\\xb2\\xe5\\x87\\x86\\xe5\\xa4\\x87\\xe5\\xae\\x8c\\xe6\\x88\\x90\\xe3\\x80\\x82\n"
  "bool constraints_enabled\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe9\\x87\\x87\\xe7\\x94\\xa8\\xe7\\x9a\\x84\\xe5\\x9c\\xb0\\xe5\\xbd\\xa2\\xe5\\x87\\xa0\\xe4\\xbd\\x95\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xef\\xbc\\x8c\\xe4\\xbe\\x8b\\xe5\\xa6\\x82\\xe6\\xb4\\x9e\\xe5\\x8f\\xa3\\xe5\\x87\\xa0\\xe4\\xbd\\x95\\xe6\\x9b\\xb4\\xe6\\x96\\xb0\\xe5\\x90\\x8e\\xe6\\x94\\xb9\\xe5\\x8f\\x98\\xe3\\x80\\x82\n"
  "uint64 terrain_revision\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe9\\x87\\x87\\xe7\\x94\\xa8\\xe7\\x9a\\x84\\xe8\\xa7\\x84\\xe5\\x88\\x92\\xe9\\x85\\x8d\\xe7\\xbd\\xae\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xef\\xbc\\x9b\\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe6\\x9d\\xa5\\xe8\\x87\\xaa\\xe6\\x89\\x80\\xe9\\x80\\x89\\xe8\\xa7\\x84\\xe5\\x88\\x92\\xe5\\xbf\\xab\\xe7\\x85\\xa7\\xe7\\x9a\\x84configuration_revision\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe4\\xbb\\xa3\\xe8\\xa1\\xa8\\xe6\\x89\\x80\\xe6\\x9c\\x89\\xe5\\x8f\\x82\\xe6\\x95\\xb0\\xe5\\x9d\\x87\\xe5\\xb7\\xb2\\xe7\\xba\\xb3\\xe5\\x85\\xa5\\xe3\\x80\\x82\n"
  "uint64 parameter_revision\n"
  "\n"
  "# \\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe6\\xa0\\xa1\\xe9\\xaa\\x8c\\xe9\\x87\\x87\\xe7\\x94\\xa8\\xe7\\x9a\\x84\\xe5\\x9c\\xb0\\xe5\\x9b\\xbe\\xe5\\xbf\\xab\\xe7\\x85\\xa7\\xe8\\xba\\xab\\xe4\\xbb\\xbd\\xef\\xbc\\x9b\\xe8\\x8d\\x89\\xe7\\xa8\\xbf\\xe4\\xb8\\xba\\xe5\\x9c\\xb0\\xe5\\x9b\\xbe\\xe6\\x91\\x98\\xe8\\xa6\\x81\\xef\\xbc\\x8c\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe6\\x97\\xb6\\xe9\\x97\\xb4\\xe6\\x88\\xb3\\xe6\\x88\\x96\\xe9\\x80\\x92\\xe5\\xa2\\x9e\\xe6\\x9b\\xb4\\xe6\\x96\\xb0\\xe6\\xac\\xa1\\xe6\\x95\\xb0\\xe3\\x80\\x82\n"
  "uint64 map_revision\n"
  "\n"
  "# \\xe6\\xad\\xa3\\xe5\\xbc\\x8f\\xe6\\x8e\\xa5\\xe7\\xba\\xb3\\xe7\\x9a\\x84\\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xef\\xbc\\x8c\\xe4\\xbd\\x8d\\xe5\\xa7\\xbf\\xe7\\x82\\xb9\\xe4\\xb8\\x8eheader\\xe5\\xa3\\xb0\\xe6\\x98\\x8e\\xe7\\x9a\\x84\\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xe7\\xb3\\xbb\\xe4\\xb8\\x80\\xe8\\x87\\xb4\\xef\\xbc\\x9b\\xe4\\xba\\x8b\\xe4\\xbb\\xb6\\xe5\\xbc\\xa7\\xe9\\x95\\xbf\\xe5\\x9d\\x87\\xe7\\x9b\\xb8\\xe5\\xaf\\xb9\\xe6\\xad\\xa4\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe3\\x80\\x82\n"
  "nav_msgs/Path path\n"
  "\n"
  "# \\xe8\\xaf\\xa5\\xe6\\x9c\\x80\\xe7\\xbb\\x88\\xe6\\x8a\\x98\\xe7\\xba\\xbf\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xe7\\x9a\\x84\\xe4\\xba\\x8c\\xe7\\xbb\\xb4\\xe7\\xb4\\xaf\\xe8\\xae\\xa1\\xe9\\x95\\xbf\\xe5\\xba\\xa6\\xef\\xbc\\x8c\\xe5\\x8d\\x95\\xe4\\xbd\\x8dm\\xef\\xbc\\x9b\\xe4\\xb8\\x8d\\xe6\\x98\\xaf\\xe6\\x9c\\xba\\xe5\\x99\\xa8\\xe4\\xba\\xba\\xe5\\xb7\\xb2\\xe8\\xa1\\x8c\\xe9\\xa9\\xb6\\xe8\\xb7\\x9d\\xe7\\xa6\\xbb\\xe3\\x80\\x82\n"
  "float64 path_length\n"
  "\n"
  "# \\xe8\\xaf\\xa5\\xe7\\x89\\x88\\xe6\\x9c\\xac\\xe7\\x9a\\x84\\xe9\\x80\\x9a\\xe8\\xa1\\x8c\\xe8\\xae\\xb0\\xe5\\xbd\\x95\\xe5\\x88\\x97\\xe8\\xa1\\xa8\\xef\\xbc\\x8c\\xe6\\x95\\xb0\\xe6\\x8d\\xae\\xe4\\xb8\\x8epath\\xe5\\xba\\x94\\xe6\\x9d\\xa5\\xe8\\x87\\xaa\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe6\\x8e\\xa5\\xe7\\xba\\xb3\\xe5\\xbf\\xab\\xe7\\x85\\xa7\\xef\\xbc\\x9b\\xe7\\xa9\\xba\\xe5\\x88\\x97\\xe8\\xa1\\xa8\\xe5\\x8f\\xaf\\xe4\\xbb\\xa5\\xe6\\x98\\xaf\\xe5\\x90\\x88\\xe6\\xb3\\x95\\xe7\\xbb\\x95\\xe8\\xa1\\x8c\\xe3\\x80\\x82\n"
  "HoleTraversal[] passages\n"
  "\n"
  "# \\xe6\\xb2\\xbf\\xe5\\xbd\\x93\\xe5\\x89\\x8dpath\\xe5\\xae\\x9a\\xe4\\xb9\\x89\\xe7\\x9a\\x84\\xe9\\x99\\x90\\xe9\\x80\\x9f\\xe5\\x8c\\xba\\xe9\\x97\\xb4\\xe5\\x88\\x97\\xe8\\xa1\\xa8\\xef\\xbc\\x8c\\xe5\\x8f\\xaf\\xe5\\x90\\x8c\\xe6\\x97\\xb6\\xe5\\x90\\xab\\xe5\\x9d\\xa1\\xe9\\x9d\\xa2\\xe5\\x8f\\x8a\\xe5\\x9d\\xa1\\xe9\\xa1\\xb6\\xe5\\x90\\x8e\\xe5\\x8f\\x97\\xe9\\x99\\x90\\xe5\\x8c\\xba\\xe3\\x80\\x82\n"
  "HoleSpeedRegion[] speed_regions\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__msg__NavigationPlan__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__msg__NavigationPlan__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1232, 1232},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__msg__NavigationPlan__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[13];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 13, 13};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__msg__NavigationPlan__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__PoseStamped__get_individual_type_description_source(NULL);
    sources[5] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[6] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[7] = *nav_interfaces__msg__HoleEvent__get_individual_type_description_source(NULL);
    sources[8] = *nav_interfaces__msg__HoleSpeedRegion__get_individual_type_description_source(NULL);
    sources[9] = *nav_interfaces__msg__HoleStraight__get_individual_type_description_source(NULL);
    sources[10] = *nav_interfaces__msg__HoleTraversal__get_individual_type_description_source(NULL);
    sources[11] = *nav_msgs__msg__Path__get_individual_type_description_source(NULL);
    sources[12] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
