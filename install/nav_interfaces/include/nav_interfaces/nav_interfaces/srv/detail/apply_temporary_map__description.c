// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice

#include "nav_interfaces/srv/detail/apply_temporary_map__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ApplyTemporaryMap__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe2, 0x37, 0x2b, 0xd5, 0x10, 0xa7, 0x1a, 0xfb,
      0xb4, 0x6c, 0xf6, 0x36, 0x39, 0x5a, 0xfe, 0x47,
      0xf3, 0x0d, 0xa0, 0xc6, 0xed, 0xd3, 0xc9, 0x99,
      0x22, 0x58, 0xed, 0x29, 0xa5, 0xed, 0x77, 0xb0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8a, 0x2c, 0xb4, 0xae, 0xb2, 0xe8, 0x06, 0x94,
      0xc1, 0x63, 0x5a, 0xa0, 0x66, 0x41, 0x3d, 0x36,
      0x3d, 0xb3, 0x39, 0xed, 0xe2, 0x97, 0x10, 0x25,
      0x62, 0xc4, 0xc7, 0x15, 0x2e, 0x10, 0xc0, 0x90,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc5, 0x0e, 0xad, 0x45, 0x03, 0xaa, 0x3f, 0x01,
      0xf8, 0x08, 0xed, 0x52, 0xeb, 0xd2, 0xc8, 0x9e,
      0x3b, 0x45, 0xd4, 0xa1, 0x88, 0x0b, 0x9f, 0xbd,
      0xb0, 0x9d, 0x27, 0xfc, 0xd2, 0x8a, 0x62, 0x83,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_nav_interfaces
const rosidl_type_hash_t *
nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x16, 0x2a, 0x4b, 0x11, 0xb2, 0x5e, 0xbc, 0xb8,
      0xed, 0x2b, 0xa2, 0x0d, 0x94, 0x7d, 0x13, 0xf3,
      0xf8, 0x59, 0x55, 0x27, 0x18, 0xcb, 0xd4, 0x51,
      0xb7, 0x00, 0x1e, 0xcd, 0xeb, 0x34, 0xa2, 0xc4,
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

static char nav_interfaces__srv__ApplyTemporaryMap__TYPE_NAME[] = "nav_interfaces/srv/ApplyTemporaryMap";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char nav_interfaces__srv__ApplyTemporaryMap_Event__TYPE_NAME[] = "nav_interfaces/srv/ApplyTemporaryMap_Event";
static char nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME[] = "nav_interfaces/srv/ApplyTemporaryMap_Request";
static char nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME[] = "nav_interfaces/srv/ApplyTemporaryMap_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char nav_interfaces__srv__ApplyTemporaryMap__FIELD_NAME__request_message[] = "request_message";
static char nav_interfaces__srv__ApplyTemporaryMap__FIELD_NAME__response_message[] = "response_message";
static char nav_interfaces__srv__ApplyTemporaryMap__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ApplyTemporaryMap__FIELDS[] = {
  {
    {nav_interfaces__srv__ApplyTemporaryMap__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {nav_interfaces__srv__ApplyTemporaryMap_Event__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__srv__ApplyTemporaryMap__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Event__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ApplyTemporaryMap__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ApplyTemporaryMap__TYPE_NAME, 36, 36},
      {nav_interfaces__srv__ApplyTemporaryMap__FIELDS, 3, 3},
    },
    {nav_interfaces__srv__ApplyTemporaryMap__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__expected_session_id[] = "expected_session_id";
static char nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__expected_source_id[] = "expected_source_id";
static char nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__expected_map_revision[] = "expected_map_revision";
static char nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__indices[] = "indices";
static char nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__values[] = "values";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ApplyTemporaryMap_Request__FIELDS[] = {
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__expected_session_id, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__expected_source_id, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__expected_map_revision, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__indices, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__FIELD_NAME__values, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME, 44, 44},
      {nav_interfaces__srv__ApplyTemporaryMap_Request__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__success[] = "success";
static char nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__reason[] = "reason";
static char nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__map_revision[] = "map_revision";
static char nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__replanning_triggered[] = "replanning_triggered";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ApplyTemporaryMap_Response__FIELDS[] = {
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__reason, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__map_revision, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__FIELD_NAME__replanning_triggered, 20, 20},
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
nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME, 45, 45},
      {nav_interfaces__srv__ApplyTemporaryMap_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char nav_interfaces__srv__ApplyTemporaryMap_Event__FIELD_NAME__info[] = "info";
static char nav_interfaces__srv__ApplyTemporaryMap_Event__FIELD_NAME__request[] = "request";
static char nav_interfaces__srv__ApplyTemporaryMap_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field nav_interfaces__srv__ApplyTemporaryMap_Event__FIELDS[] = {
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription nav_interfaces__srv__ApplyTemporaryMap_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {nav_interfaces__srv__ApplyTemporaryMap_Event__TYPE_NAME, 42, 42},
      {nav_interfaces__srv__ApplyTemporaryMap_Event__FIELDS, 3, 3},
    },
    {nav_interfaces__srv__ApplyTemporaryMap_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe5\\xae\\x8c\\xe6\\x95\\xb4\\xe6\\x9b\\xbf\\xe6\\x8d\\xa2\\xe6\\x9c\\xac\\xe6\\xac\\xa1\\xe5\\xaf\\xbc\\xe8\\x88\\xaa\\xe7\\x9a\\x84\\xe4\\xba\\xba\\xe5\\xb7\\xa5\\xe7\\xac\\x94\\xe8\\xbf\\xb9\\xef\\xbc\\x9b\\xe7\\xa9\\xba\\xe6\\x95\\xb0\\xe7\\xbb\\x84\\xe8\\xa1\\xa8\\xe7\\xa4\\xba\\xe6\\xb8\\x85\\xe9\\x99\\xa4\\xe5\\x85\\xa8\\xe9\\x83\\xa8\\xe4\\xb8\\xb4\\xe6\\x97\\xb6\\xe4\\xbf\\xae\\xe6\\x94\\xb9\\xe3\\x80\\x82\\xe7\\xbb\\x9d\\xe4\\xb8\\x8d\\xe5\\x86\\x99\\xe5\\x85\\xa5\\xe6\\x96\\x87\\xe4\\xbb\\xb6\\xe3\\x80\\x82\n"
  "string expected_session_id\n"
  "string expected_source_id\n"
  "uint64 expected_map_revision\n"
  "uint32[] indices\n"
  "int8[] values\n"
  "---\n"
  "bool success\n"
  "string reason\n"
  "uint64 map_revision\n"
  "bool replanning_triggered";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ApplyTemporaryMap__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ApplyTemporaryMap__TYPE_NAME, 36, 36},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 228, 228},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ApplyTemporaryMap_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ApplyTemporaryMap_Request__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ApplyTemporaryMap_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ApplyTemporaryMap_Response__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
nav_interfaces__srv__ApplyTemporaryMap_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {nav_interfaces__srv__ApplyTemporaryMap_Event__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ApplyTemporaryMap__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ApplyTemporaryMap__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav_interfaces__srv__ApplyTemporaryMap_Event__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__srv__ApplyTemporaryMap_Request__get_individual_type_description_source(NULL);
    sources[4] = *nav_interfaces__srv__ApplyTemporaryMap_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ApplyTemporaryMap_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ApplyTemporaryMap_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ApplyTemporaryMap_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ApplyTemporaryMap_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
nav_interfaces__srv__ApplyTemporaryMap_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *nav_interfaces__srv__ApplyTemporaryMap_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *nav_interfaces__srv__ApplyTemporaryMap_Request__get_individual_type_description_source(NULL);
    sources[3] = *nav_interfaces__srv__ApplyTemporaryMap_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
