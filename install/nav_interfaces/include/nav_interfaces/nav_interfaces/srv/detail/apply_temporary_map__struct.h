// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/apply_temporary_map.h"


#ifndef NAV_INTERFACES__SRV__DETAIL__APPLY_TEMPORARY_MAP__STRUCT_H_
#define NAV_INTERFACES__SRV__DETAIL__APPLY_TEMPORARY_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'expected_session_id'
// Member 'expected_source_id'
#include "rosidl_runtime_c/string.h"
// Member 'indices'
// Member 'values'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/ApplyTemporaryMap in the package nav_interfaces.
typedef struct nav_interfaces__srv__ApplyTemporaryMap_Request
{
  rosidl_runtime_c__String expected_session_id;
  rosidl_runtime_c__String expected_source_id;
  uint64_t expected_map_revision;
  rosidl_runtime_c__uint32__Sequence indices;
  rosidl_runtime_c__int8__Sequence values;
} nav_interfaces__srv__ApplyTemporaryMap_Request;

// Struct for a sequence of nav_interfaces__srv__ApplyTemporaryMap_Request.
typedef struct nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence
{
  nav_interfaces__srv__ApplyTemporaryMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'reason'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ApplyTemporaryMap in the package nav_interfaces.
typedef struct nav_interfaces__srv__ApplyTemporaryMap_Response
{
  bool success;
  rosidl_runtime_c__String reason;
  uint64_t map_revision;
  bool replanning_triggered;
} nav_interfaces__srv__ApplyTemporaryMap_Response;

// Struct for a sequence of nav_interfaces__srv__ApplyTemporaryMap_Response.
typedef struct nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence
{
  nav_interfaces__srv__ApplyTemporaryMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__srv__ApplyTemporaryMap_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__srv__ApplyTemporaryMap_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ApplyTemporaryMap in the package nav_interfaces.
typedef struct nav_interfaces__srv__ApplyTemporaryMap_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence request;
  nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence response;
} nav_interfaces__srv__ApplyTemporaryMap_Event;

// Struct for a sequence of nav_interfaces__srv__ApplyTemporaryMap_Event.
typedef struct nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence
{
  nav_interfaces__srv__ApplyTemporaryMap_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__srv__ApplyTemporaryMap_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__SRV__DETAIL__APPLY_TEMPORARY_MAP__STRUCT_H_
