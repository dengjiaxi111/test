// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:srv/GetHolePassageConfig.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/srv/detail/get_hole_passage_config__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__GetHolePassageConfig__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x33, 0xfa, 0xcd, 0x61, 0xbe, 0xba, 0xa9, 0xb9,
      0x3b, 0xcd, 0x50, 0xdd, 0x79, 0x03, 0x1b, 0xdb,
      0x31, 0xef, 0x4f, 0x8e, 0xb1, 0xc3, 0xf8, 0x61,
      0x16, 0x09, 0xab, 0x2a, 0x68, 0x1a, 0xf4, 0x43,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__GetHolePassageConfig_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0x4a, 0xf3, 0xbd, 0x00, 0xfa, 0x97, 0x45,
      0x30, 0x54, 0x32, 0x31, 0xf0, 0xd0, 0x21, 0x23,
      0xbe, 0xd1, 0x85, 0x0a, 0xa0, 0x95, 0x60, 0xd7,
      0xb8, 0x5e, 0x71, 0x35, 0x34, 0xa8, 0x90, 0x55,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__GetHolePassageConfig_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf3, 0x32, 0x32, 0x74, 0x6d, 0x33, 0x89, 0xce,
      0xd3, 0x4d, 0xc3, 0x7a, 0x01, 0xef, 0xa3, 0x41,
      0x8f, 0x17, 0x07, 0xf2, 0x04, 0xe2, 0xb8, 0xe4,
      0x05, 0x4b, 0xef, 0xa2, 0x15, 0x40, 0x31, 0x62,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__GetHolePassageConfig_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0e, 0x8e, 0x1f, 0x31, 0x55, 0x00, 0x32, 0x92,
      0xa7, 0x2d, 0xf7, 0x9a, 0x73, 0x92, 0x95, 0xad,
      0xd5, 0x0c, 0x3c, 0x2f, 0x04, 0x1a, 0xa2, 0x02,
      0x53, 0x63, 0x32, 0xbb, 0x81, 0x9e, 0x5a, 0x9d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

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

static char nav_interfaces__srv__GetHolePassageConfig__TYPE_NAME[] = "nav_interfaces/srv/GetHolePassageConfig";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char nav_interfaces__srv__GetHolePassageConfig_Event__TYPE_NAME[] = "nav_interfaces/srv/GetHolePassageConfig_Event";
static char nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME[] = "nav_interfaces/srv/GetHolePassageConfig_Request";
static char nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME[] = "nav_interfaces/srv/GetHolePassageConfig_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char nav_interfaces__srv__GetHolePassageConfig__FIELD_NAME__request_message[] = "request_message";
static char nav_interfaces__srv__GetHolePassageConfig__FIELD_NAME__response_message[] = "response_message";
static char nav_interfaces__srv__GetHolePassageConfig__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__GetHolePassageConfig__FIELDS[] = {
  {
    {nav_interfaces__srv__GetHolePassageConfig__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__GetHolePassageConfig_Event__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__srv__GetHolePassageConfig__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Event__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__GetHolePassageConfig__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__GetHolePassageConfig__TYPE_NAME, 39, 39},
      {nav_interfaces__srv__GetHolePassageConfig__FIELDS, 3, 3},
    },
    {nav_interfaces__srv__GetHolePassageConfig__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav_interfaces__srv__GetHolePassageConfig_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__srv__GetHolePassageConfig_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = nav_interfaces__srv__GetHolePassageConfig_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__GetHolePassageConfig_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__GetHolePassageConfig_Request__FIELDS[] = {
  {
    {nav_interfaces__srv__GetHolePassageConfig_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
nav_interfaces__srv__GetHolePassageConfig_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME, 47, 47},
      {nav_interfaces__srv__GetHolePassageConfig_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__success[] = "success";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__manual_config_active[] = "manual_config_active";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__reason[] = "reason";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__config_yaml[] = "config_yaml";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__config_path[] = "config_path";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__terrain_path[] = "terrain_path";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__terrain_geometry[] = "terrain_geometry";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__config_revision[] = "config_revision";
static char nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__terrain_revision[] = "terrain_revision";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__GetHolePassageConfig_Response__FIELDS[] = {
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__manual_config_active, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__reason, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__config_yaml, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__config_path, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__terrain_path, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__terrain_geometry, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__config_revision, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__FIELD_NAME__terrain_revision, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__GetHolePassageConfig_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME, 48, 48},
      {nav_interfaces__srv__GetHolePassageConfig_Response__FIELDS, 9, 9},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__GetHolePassageConfig_Event__FIELD_NAME__info[] = "info";
static char nav_interfaces__srv__GetHolePassageConfig_Event__FIELD_NAME__request[] = "request";
static char nav_interfaces__srv__GetHolePassageConfig_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__GetHolePassageConfig_Event__FIELDS[] = {
  {
    {nav_interfaces__srv__GetHolePassageConfig_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__srv__GetHolePassageConfig_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__GetHolePassageConfig_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__GetHolePassageConfig_Event__TYPE_NAME, 45, 45},
      {nav_interfaces__srv__GetHolePassageConfig_Event__FIELDS, 3, 3},
    },
    {nav_interfaces__srv__GetHolePassageConfig_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav_interfaces__srv__GetHolePassageConfig_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__srv__GetHolePassageConfig_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "bool success\n"
  "bool manual_config_active\n"
  "string reason\n"
  "string config_yaml\n"
  "string config_path\n"
  "string terrain_path\n"
  "string terrain_geometry\n"
  "uint64 config_revision\n"
  "uint64 terrain_revision";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__GetHolePassageConfig__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__GetHolePassageConfig__TYPE_NAME, 39, 39},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 186, 186},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__GetHolePassageConfig_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__GetHolePassageConfig_Request__TYPE_NAME, 47, 47},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__GetHolePassageConfig_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__GetHolePassageConfig_Response__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__GetHolePassageConfig_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__GetHolePassageConfig_Event__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__GetHolePassageConfig__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__GetHolePassageConfig__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav_interfaces__srv__GetHolePassageConfig_Event__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__srv__GetHolePassageConfig_Request__get_individual_type_description_source(NULL);
    sources[4] = *nav_interfaces__srv__GetHolePassageConfig_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__GetHolePassageConfig_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__GetHolePassageConfig_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__GetHolePassageConfig_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__GetHolePassageConfig_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__GetHolePassageConfig_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__GetHolePassageConfig_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav_interfaces__srv__GetHolePassageConfig_Request__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__srv__GetHolePassageConfig_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
