// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:srv/GetTemporaryMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/get_temporary_map.h"


#ifndef NAV_INTERFACES__SRV__DETAIL__GET_TEMPORARY_MAP__STRUCT_H_
#define NAV_INTERFACES__SRV__DETAIL__GET_TEMPORARY_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetTemporaryMap in the package nav_interfaces.
typedef struct nav_interfaces__srv__GetTemporaryMap_Request
{
  uint8_t structure_needs_at_least_one_member;
} nav_interfaces__srv__GetTemporaryMap_Request;

// Struct for a sequence of nav_interfaces__srv__GetTemporaryMap_Request.
typedef struct nav_interfaces__srv__GetTemporaryMap_Request__Sequence
{
  nav_interfaces__srv__GetTemporaryMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__GetTemporaryMap_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'reason'
// Member 'map_path'
// Member 'session_id'
// Member 'source_id'
#include "rosidl_runtime_c/string.h"
// Member 'source_map'
#include "nav_msgs/msg/detail/occupancy_grid__struct.h"
// Member 'indices'
// Member 'values'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetTemporaryMap in the package nav_interfaces.
typedef struct nav_interfaces__srv__GetTemporaryMap_Response
{
  bool success;
  rosidl_runtime_c__String reason;
  rosidl_runtime_c__String map_path;
  rosidl_runtime_c__String session_id;
  rosidl_runtime_c__String source_id;
  uint64_t map_revision;
  nav_msgs__msg__OccupancyGrid source_map;
  rosidl_runtime_c__uint32__Sequence indices;
  rosidl_runtime_c__int8__Sequence values;
} nav_interfaces__srv__GetTemporaryMap_Response;

// Struct for a sequence of nav_interfaces__srv__GetTemporaryMap_Response.
typedef struct nav_interfaces__srv__GetTemporaryMap_Response__Sequence
{
  nav_interfaces__srv__GetTemporaryMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__GetTemporaryMap_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__srv__GetTemporaryMap_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__srv__GetTemporaryMap_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetTemporaryMap in the package nav_interfaces.
typedef struct nav_interfaces__srv__GetTemporaryMap_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__srv__GetTemporaryMap_Request__Sequence request;
  nav_interfaces__srv__GetTemporaryMap_Response__Sequence response;
} nav_interfaces__srv__GetTemporaryMap_Event;

// Struct for a sequence of nav_interfaces__srv__GetTemporaryMap_Event.
typedef struct nav_interfaces__srv__GetTemporaryMap_Event__Sequence
{
  nav_interfaces__srv__GetTemporaryMap_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__GetTemporaryMap_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__SRV__DETAIL__GET_TEMPORARY_MAP__STRUCT_H_
