// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:srv/GetHolePassageConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/get_hole_passage_config.h"


#ifndef NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__STRUCT_H_
#define NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetHolePassageConfig in the package nav_interfaces.
typedef struct nav_interfaces__srv__GetHolePassageConfig_Request
{
  uint8_t structure_needs_at_least_one_member;
} nav_interfaces__srv__GetHolePassageConfig_Request;

// Struct for a sequence of nav_interfaces__srv__GetHolePassageConfig_Request.
typedef struct nav_interfaces__srv__GetHolePassageConfig_Request__Sequence
{
  nav_interfaces__srv__GetHolePassageConfig_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__GetHolePassageConfig_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'reason'
// Member 'config_yaml'
// Member 'config_path'
// Member 'terrain_path'
// Member 'terrain_geometry'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetHolePassageConfig in the package nav_interfaces.
typedef struct nav_interfaces__srv__GetHolePassageConfig_Response
{
  bool success;
  bool manual_config_active;
  rosidl_runtime_c__String reason;
  rosidl_runtime_c__String config_yaml;
  rosidl_runtime_c__String config_path;
  rosidl_runtime_c__String terrain_path;
  rosidl_runtime_c__String terrain_geometry;
  uint64_t config_revision;
  uint64_t terrain_revision;
} nav_interfaces__srv__GetHolePassageConfig_Response;

// Struct for a sequence of nav_interfaces__srv__GetHolePassageConfig_Response.
typedef struct nav_interfaces__srv__GetHolePassageConfig_Response__Sequence
{
  nav_interfaces__srv__GetHolePassageConfig_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__GetHolePassageConfig_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__srv__GetHolePassageConfig_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__srv__GetHolePassageConfig_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetHolePassageConfig in the package nav_interfaces.
typedef struct nav_interfaces__srv__GetHolePassageConfig_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__srv__GetHolePassageConfig_Request__Sequence request;
  nav_interfaces__srv__GetHolePassageConfig_Response__Sequence response;
} nav_interfaces__srv__GetHolePassageConfig_Event;

// Struct for a sequence of nav_interfaces__srv__GetHolePassageConfig_Event.
typedef struct nav_interfaces__srv__GetHolePassageConfig_Event__Sequence
{
  nav_interfaces__srv__GetHolePassageConfig_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__GetHolePassageConfig_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__STRUCT_H_
