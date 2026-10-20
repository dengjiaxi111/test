// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:action/Navigate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/action/navigate.h"


#ifndef NAV_INTERFACES__ACTION__DETAIL__NAVIGATE__STRUCT_H_
#define NAV_INTERFACES__ACTION__DETAIL__NAVIGATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_Goal
{
  /// === Goal ===
  geometry_msgs__msg__PoseStamped goal_pose;
} nav_interfaces__action__Navigate_Goal;

// Struct for a sequence of nav_interfaces__action__Navigate_Goal.
typedef struct nav_interfaces__action__Navigate_Goal__Sequence
{
  nav_interfaces__action__Navigate_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_Result
{
  bool success;
  rosidl_runtime_c__String message;
  float total_time;
} nav_interfaces__action__Navigate_Result;

// Struct for a sequence of nav_interfaces__action__Navigate_Result.
typedef struct nav_interfaces__action__Navigate_Result__Sequence
{
  nav_interfaces__action__Navigate_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_Feedback
{
  geometry_msgs__msg__PoseStamped current_pose;
  float distance_remaining;
  /// 0=IDLE,1=PLANNING,2=CONTROLLING,3=ESCAPING,4=RECOVERY,5=SUCCEEDED,6=FAILED
  uint8_t state;
  uint8_t recovery_count;
} nav_interfaces__action__Navigate_Feedback;

// Struct for a sequence of nav_interfaces__action__Navigate_Feedback.
typedef struct nav_interfaces__action__Navigate_Feedback__Sequence
{
  nav_interfaces__action__Navigate_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "nav_interfaces/action/detail/navigate__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  nav_interfaces__action__Navigate_Goal goal;
} nav_interfaces__action__Navigate_SendGoal_Request;

// Struct for a sequence of nav_interfaces__action__Navigate_SendGoal_Request.
typedef struct nav_interfaces__action__Navigate_SendGoal_Request__Sequence
{
  nav_interfaces__action__Navigate_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} nav_interfaces__action__Navigate_SendGoal_Response;

// Struct for a sequence of nav_interfaces__action__Navigate_SendGoal_Response.
typedef struct nav_interfaces__action__Navigate_SendGoal_Response__Sequence
{
  nav_interfaces__action__Navigate_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__action__Navigate_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__action__Navigate_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__action__Navigate_SendGoal_Request__Sequence request;
  nav_interfaces__action__Navigate_SendGoal_Response__Sequence response;
} nav_interfaces__action__Navigate_SendGoal_Event;

// Struct for a sequence of nav_interfaces__action__Navigate_SendGoal_Event.
typedef struct nav_interfaces__action__Navigate_SendGoal_Event__Sequence
{
  nav_interfaces__action__Navigate_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} nav_interfaces__action__Navigate_GetResult_Request;

// Struct for a sequence of nav_interfaces__action__Navigate_GetResult_Request.
typedef struct nav_interfaces__action__Navigate_GetResult_Request__Sequence
{
  nav_interfaces__action__Navigate_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "nav_interfaces/action/detail/navigate__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_GetResult_Response
{
  int8_t status;
  nav_interfaces__action__Navigate_Result result;
} nav_interfaces__action__Navigate_GetResult_Response;

// Struct for a sequence of nav_interfaces__action__Navigate_GetResult_Response.
typedef struct nav_interfaces__action__Navigate_GetResult_Response__Sequence
{
  nav_interfaces__action__Navigate_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  nav_interfaces__action__Navigate_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  nav_interfaces__action__Navigate_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  nav_interfaces__action__Navigate_GetResult_Request__Sequence request;
  nav_interfaces__action__Navigate_GetResult_Response__Sequence response;
} nav_interfaces__action__Navigate_GetResult_Event;

// Struct for a sequence of nav_interfaces__action__Navigate_GetResult_Event.
typedef struct nav_interfaces__action__Navigate_GetResult_Event__Sequence
{
  nav_interfaces__action__Navigate_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "nav_interfaces/action/detail/navigate__struct.h"

/// Struct defined in action/Navigate in the package nav_interfaces.
typedef struct nav_interfaces__action__Navigate_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  nav_interfaces__action__Navigate_Feedback feedback;
} nav_interfaces__action__Navigate_FeedbackMessage;

// Struct for a sequence of nav_interfaces__action__Navigate_FeedbackMessage.
typedef struct nav_interfaces__action__Navigate_FeedbackMessage__Sequence
{
  nav_interfaces__action__Navigate_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__action__Navigate_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__ACTION__DETAIL__NAVIGATE__STRUCT_H_
