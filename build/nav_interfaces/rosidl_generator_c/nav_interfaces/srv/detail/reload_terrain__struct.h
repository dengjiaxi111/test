// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:srv/ReloadTerrain.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/reload_terrain.h"


#ifndef NAV_INTERFACES__SRV__DETAIL__RELOAD_TERRAIN__STRUCT_H_
#define NAV_INTERFACES__SRV__DETAIL__RELOAD_TERRAIN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'expected_path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ReloadTerrain in the package nav_interfaces.
typedef struct nav_interfaces__srv__ReloadTerrain_Request
{
  rosidl_runtime_c__String expected_path;
} nav_interfaces__srv__ReloadTerrain_Request;

// Struct for a sequence of nav_interfaces__srv__ReloadTerrain_Request.
typedef struct nav_interfaces__srv__ReloadTerrain_Request__Sequence
{
  nav_interfaces__srv__ReloadTerrain_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ReloadTerrain_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'reason'
// Member 'terrain_path'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ReloadTerrain in the package nav_interfaces.
typedef struct nav_interfaces__srv__ReloadTerrain_Response
{
  bool success;
  rosidl_runtime_c__String reason;
  rosidl_runtime_c__String terrain_path;
  uint64_t terrain_revision;
  bool replanning_triggered;
} nav_interfaces__srv__ReloadTerrain_Response;

// Struct for a sequence of nav_interfaces__srv__ReloadTerrain_Response.
typedef struct nav_interfaces__srv__ReloadTerrain_Response__Sequence
{
  nav_interfaces__srv__ReloadTerrain_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ReloadTerrain_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__srv__ReloadTerrain_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__srv__ReloadTerrain_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ReloadTerrain in the package nav_interfaces.
typedef struct nav_interfaces__srv__ReloadTerrain_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__srv__ReloadTerrain_Request__Sequence request;
  nav_interfaces__srv__ReloadTerrain_Response__Sequence response;
} nav_interfaces__srv__ReloadTerrain_Event;

// Struct for a sequence of nav_interfaces__srv__ReloadTerrain_Event.
typedef struct nav_interfaces__srv__ReloadTerrain_Event__Sequence
{
  nav_interfaces__srv__ReloadTerrain_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ReloadTerrain_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__SRV__DETAIL__RELOAD_TERRAIN__STRUCT_H_
