// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:srv/ApplyHolePassageConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/apply_hole_passage_config.h"


#ifndef NAV_INTERFACES__SRV__DETAIL__APPLY_HOLE_PASSAGE_CONFIG__STRUCT_H_
#define NAV_INTERFACES__SRV__DETAIL__APPLY_HOLE_PASSAGE_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'config_yaml'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ApplyHolePassageConfig in the package nav_interfaces.
typedef struct nav_interfaces__srv__ApplyHolePassageConfig_Request
{
  rosidl_runtime_c__String config_yaml;
  uint64_t expected_config_revision;
  uint64_t expected_terrain_revision;
} nav_interfaces__srv__ApplyHolePassageConfig_Request;

// Struct for a sequence of nav_interfaces__srv__ApplyHolePassageConfig_Request.
typedef struct nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence
{
  nav_interfaces__srv__ApplyHolePassageConfig_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'reason'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ApplyHolePassageConfig in the package nav_interfaces.
typedef struct nav_interfaces__srv__ApplyHolePassageConfig_Response
{
  bool success;
  rosidl_runtime_c__String reason;
  uint64_t config_revision;
  uint64_t terrain_revision;
  bool replanning_triggered;
} nav_interfaces__srv__ApplyHolePassageConfig_Response;

// Struct for a sequence of nav_interfaces__srv__ApplyHolePassageConfig_Response.
typedef struct nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence
{
  nav_interfaces__srv__ApplyHolePassageConfig_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__srv__ApplyHolePassageConfig_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__srv__ApplyHolePassageConfig_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ApplyHolePassageConfig in the package nav_interfaces.
typedef struct nav_interfaces__srv__ApplyHolePassageConfig_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence request;
  nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence response;
} nav_interfaces__srv__ApplyHolePassageConfig_Event;

// Struct for a sequence of nav_interfaces__srv__ApplyHolePassageConfig_Event.
typedef struct nav_interfaces__srv__ApplyHolePassageConfig_Event__Sequence
{
  nav_interfaces__srv__ApplyHolePassageConfig_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ApplyHolePassageConfig_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__SRV__DETAIL__APPLY_HOLE_PASSAGE_CONFIG__STRUCT_H_
