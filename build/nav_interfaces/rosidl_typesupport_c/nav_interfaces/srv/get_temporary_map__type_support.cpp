// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from nav_interfaces:srv/GetTemporaryMap.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "nav_interfaces/srv/detail/get_temporary_map__struct.h"
#include "nav_interfaces/srv/detail/get_temporary_map__type_support.h"
#include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetTemporaryMap_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetTemporaryMap_Request_type_support_ids_t;

static const _GetTemporaryMap_Request_type_support_ids_t _GetTemporaryMap_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetTemporaryMap_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetTemporaryMap_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetTemporaryMap_Request_type_support_symbol_names_t _GetTemporaryMap_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, GetTemporaryMap_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, GetTemporaryMap_Request)),
  }
};

typedef struct _GetTemporaryMap_Request_type_support_data_t
{
  void * data[2];
} _GetTemporaryMap_Request_type_support_data_t;

static _GetTemporaryMap_Request_type_support_data_t _GetTemporaryMap_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetTemporaryMap_Request_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_GetTemporaryMap_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetTemporaryMap_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetTemporaryMap_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetTemporaryMap_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetTemporaryMap_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &nav_interfaces__srv__GetTemporaryMap_Request__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap_Request__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace nav_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, nav_interfaces, srv, GetTemporaryMap_Request)() {
  return &::nav_interfaces::srv::rosidl_typesupport_c::GetTemporaryMap_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__struct.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__type_support.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetTemporaryMap_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetTemporaryMap_Response_type_support_ids_t;

static const _GetTemporaryMap_Response_type_support_ids_t _GetTemporaryMap_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetTemporaryMap_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetTemporaryMap_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetTemporaryMap_Response_type_support_symbol_names_t _GetTemporaryMap_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, GetTemporaryMap_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, GetTemporaryMap_Response)),
  }
};

typedef struct _GetTemporaryMap_Response_type_support_data_t
{
  void * data[2];
} _GetTemporaryMap_Response_type_support_data_t;

static _GetTemporaryMap_Response_type_support_data_t _GetTemporaryMap_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetTemporaryMap_Response_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_GetTemporaryMap_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetTemporaryMap_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetTemporaryMap_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetTemporaryMap_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetTemporaryMap_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &nav_interfaces__srv__GetTemporaryMap_Response__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap_Response__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace nav_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, nav_interfaces, srv, GetTemporaryMap_Response)() {
  return &::nav_interfaces::srv::rosidl_typesupport_c::GetTemporaryMap_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__struct.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__type_support.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetTemporaryMap_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetTemporaryMap_Event_type_support_ids_t;

static const _GetTemporaryMap_Event_type_support_ids_t _GetTemporaryMap_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetTemporaryMap_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetTemporaryMap_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetTemporaryMap_Event_type_support_symbol_names_t _GetTemporaryMap_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, GetTemporaryMap_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, GetTemporaryMap_Event)),
  }
};

typedef struct _GetTemporaryMap_Event_type_support_data_t
{
  void * data[2];
} _GetTemporaryMap_Event_type_support_data_t;

static _GetTemporaryMap_Event_type_support_data_t _GetTemporaryMap_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetTemporaryMap_Event_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_GetTemporaryMap_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GetTemporaryMap_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GetTemporaryMap_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetTemporaryMap_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetTemporaryMap_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &nav_interfaces__srv__GetTemporaryMap_Event__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap_Event__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace nav_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, nav_interfaces, srv, GetTemporaryMap_Event)() {
  return &::nav_interfaces::srv::rosidl_typesupport_c::GetTemporaryMap_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "nav_interfaces/srv/detail/get_temporary_map__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _GetTemporaryMap_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetTemporaryMap_type_support_ids_t;

static const _GetTemporaryMap_type_support_ids_t _GetTemporaryMap_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetTemporaryMap_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetTemporaryMap_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetTemporaryMap_type_support_symbol_names_t _GetTemporaryMap_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, srv, GetTemporaryMap)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, srv, GetTemporaryMap)),
  }
};

typedef struct _GetTemporaryMap_type_support_data_t
{
  void * data[2];
} _GetTemporaryMap_type_support_data_t;

static _GetTemporaryMap_type_support_data_t _GetTemporaryMap_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetTemporaryMap_service_typesupport_map = {
  2,
  "nav_interfaces",
  &_GetTemporaryMap_service_typesupport_ids.typesupport_identifier[0],
  &_GetTemporaryMap_service_typesupport_symbol_names.symbol_name[0],
  &_GetTemporaryMap_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetTemporaryMap_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetTemporaryMap_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &GetTemporaryMap_Request_message_type_support_handle,
  &GetTemporaryMap_Response_message_type_support_handle,
  &GetTemporaryMap_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    nav_interfaces,
    srv,
    GetTemporaryMap
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    nav_interfaces,
    srv,
    GetTemporaryMap
  ),
  &nav_interfaces__srv__GetTemporaryMap__get_type_hash,
  &nav_interfaces__srv__GetTemporaryMap__get_type_description,
  &nav_interfaces__srv__GetTemporaryMap__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace nav_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, nav_interfaces, srv, GetTemporaryMap)() {
  return &::nav_interfaces::srv::rosidl_typesupport_c::GetTemporaryMap_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
