// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:srv/ReloadTerrain.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/srv/detail/reload_terrain__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ReloadTerrain__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0b, 0x7f, 0x0e, 0x4a, 0xef, 0xee, 0x00, 0x5b,
      0xb5, 0xa3, 0xdf, 0xbb, 0x0d, 0xad, 0x68, 0x4f,
      0xaf, 0xca, 0xc8, 0xdd, 0x93, 0x75, 0x50, 0xf8,
      0xb8, 0xe1, 0x88, 0x6a, 0xad, 0x72, 0x25, 0x37,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ReloadTerrain_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x74, 0xab, 0x1e, 0x9f, 0x0d, 0x39, 0x6f, 0xbb,
      0x42, 0xb0, 0xe5, 0x72, 0xf5, 0x3a, 0x10, 0x2d,
      0xf6, 0x2f, 0x51, 0x3d, 0xd5, 0x4c, 0xf9, 0x39,
      0x10, 0xd9, 0x33, 0x33, 0x9e, 0xc3, 0x53, 0x3d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ReloadTerrain_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1e, 0x85, 0xd5, 0x90, 0xa9, 0x87, 0x0b, 0x40,
      0x2a, 0x03, 0x8a, 0xb2, 0x06, 0xf4, 0x6b, 0x39,
      0x29, 0x83, 0x55, 0xba, 0xb2, 0x64, 0x34, 0x82,
      0xad, 0x33, 0x92, 0xf4, 0x4d, 0xa4, 0xae, 0x71,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ReloadTerrain_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb1, 0x6e, 0xc5, 0x5e, 0x7c, 0xb8, 0x74, 0x14,
      0x33, 0xeb, 0x20, 0xbc, 0x8d, 0x24, 0xe5, 0xfa,
      0x60, 0xd6, 0x0c, 0xf2, 0x4c, 0xc1, 0x0e, 0x92,
      0xff, 0x55, 0xa0, 0xf1, 0xa3, 0x21, 0x9f, 0x73,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char nav_interfaces__srv__ReloadTerrain__TYPE_NAME[] = "nav_interfaces/srv/ReloadTerrain";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char nav_interfaces__srv__ReloadTerrain_Event__TYPE_NAME[] = "nav_interfaces/srv/ReloadTerrain_Event";
static char nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME[] = "nav_interfaces/srv/ReloadTerrain_Request";
static char nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME[] = "nav_interfaces/srv/ReloadTerrain_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char nav_interfaces__srv__ReloadTerrain__FIELD_NAME__request_message[] = "request_message";
static char nav_interfaces__srv__ReloadTerrain__FIELD_NAME__response_message[] = "response_message";
static char nav_interfaces__srv__ReloadTerrain__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ReloadTerrain__FIELDS[] = {
  {
    {nav_interfaces__srv__ReloadTerrain__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__ReloadTerrain_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__srv__ReloadTerrain__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ReloadTerrain__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ReloadTerrain__TYPE_NAME, 32, 32},
      {nav_interfaces__srv__ReloadTerrain__FIELDS, 3, 3},
    },
    {nav_interfaces__srv__ReloadTerrain__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav_interfaces__srv__ReloadTerrain_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__srv__ReloadTerrain_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = nav_interfaces__srv__ReloadTerrain_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__ReloadTerrain_Request__FIELD_NAME__expected_path[] = "expected_path";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ReloadTerrain_Request__FIELDS[] = {
  {
    {nav_interfaces__srv__ReloadTerrain_Request__FIELD_NAME__expected_path, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ReloadTerrain_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME, 40, 40},
      {nav_interfaces__srv__ReloadTerrain_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__success[] = "success";
static char nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__reason[] = "reason";
static char nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__terrain_path[] = "terrain_path";
static char nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__terrain_revision[] = "terrain_revision";
static char nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__replanning_triggered[] = "replanning_triggered";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ReloadTerrain_Response__FIELDS[] = {
  {
    {nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__reason, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__terrain_path, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__terrain_revision, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Response__FIELD_NAME__replanning_triggered, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ReloadTerrain_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME, 41, 41},
      {nav_interfaces__srv__ReloadTerrain_Response__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__ReloadTerrain_Event__FIELD_NAME__info[] = "info";
static char nav_interfaces__srv__ReloadTerrain_Event__FIELD_NAME__request[] = "request";
static char nav_interfaces__srv__ReloadTerrain_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ReloadTerrain_Event__FIELDS[] = {
  {
    {nav_interfaces__srv__ReloadTerrain_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__srv__ReloadTerrain_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ReloadTerrain_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ReloadTerrain_Event__TYPE_NAME, 38, 38},
      {nav_interfaces__srv__ReloadTerrain_Event__FIELDS, 3, 3},
    },
    {nav_interfaces__srv__ReloadTerrain_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav_interfaces__srv__ReloadTerrain_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__srv__ReloadTerrain_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe7\\xbc\\x96\\xe8\\xbe\\x91\\xe5\\x99\\xa8\\xe4\\xbf\\x9d\\xe5\\xad\\x98\\xe6\\x96\\x87\\xe4\\xbb\\xb6\\xe7\\x9a\\x84\\xe7\\xbb\\x9d\\xe5\\xaf\\xb9\\xe8\\xb7\\xaf\\xe5\\xbe\\x84\\xef\\xbc\\x9b\\xe5\\xbf\\x85\\xe9\\xa1\\xbb\\xe4\\xb8\\x8e\\xe5\\xaf\\xbc\\xe8\\x88\\xaa terrain_file \\xe6\\x8c\\x87\\xe5\\x90\\x91\\xe5\\x90\\x8c\\xe4\\xb8\\x80\\xe6\\x96\\x87\\xe4\\xbb\\xb6\\xe3\\x80\\x82\n"
  "string expected_path\n"
  "---\n"
  "bool success\n"
  "string reason\n"
  "string terrain_path\n"
  "uint64 terrain_revision\n"
  "bool replanning_triggered";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ReloadTerrain__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ReloadTerrain__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 164, 164},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ReloadTerrain_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ReloadTerrain_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ReloadTerrain_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ReloadTerrain_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ReloadTerrain_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ReloadTerrain_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ReloadTerrain__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ReloadTerrain__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav_interfaces__srv__ReloadTerrain_Event__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__srv__ReloadTerrain_Request__get_individual_type_description_source(NULL);
    sources[4] = *nav_interfaces__srv__ReloadTerrain_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ReloadTerrain_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ReloadTerrain_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ReloadTerrain_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ReloadTerrain_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ReloadTerrain_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ReloadTerrain_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav_interfaces__srv__ReloadTerrain_Request__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__srv__ReloadTerrain_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
