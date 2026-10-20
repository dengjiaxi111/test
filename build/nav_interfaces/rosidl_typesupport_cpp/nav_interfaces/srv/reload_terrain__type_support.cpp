// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from nav_interfaces:srv/ReloadTerrain.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "nav_interfaces/srv/detail/reload_terrain__functions.h"
#include "nav_interfaces/srv/detail/reload_terrain__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ReloadTerrain_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ReloadTerrain_Request_type_support_ids_t;

static const _ReloadTerrain_Request_type_support_ids_t _ReloadTerrain_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ReloadTerrain_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ReloadTerrain_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ReloadTerrain_Request_type_support_symbol_names_t _ReloadTerrain_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav_interfaces, srv, ReloadTerrain_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ReloadTerrain_Request)),
  }
};

typedef struct _ReloadTerrain_Request_type_support_data_t
{
  void * data[2];
} _ReloadTerrain_Request_type_support_data_t;

static _ReloadTerrain_Request_type_support_data_t _ReloadTerrain_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ReloadTerrain_Request_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_ReloadTerrain_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ReloadTerrain_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ReloadTerrain_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ReloadTerrain_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ReloadTerrain_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &nav_interfaces__srv__ReloadTerrain_Request__get_type_hash,
  &nav_interfaces__srv__ReloadTerrain_Request__get_type_description,
  &nav_interfaces__srv__ReloadTerrain_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Request>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_cpp::ReloadTerrain_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nav_interfaces, srv, ReloadTerrain_Request)() {
  return get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nav_interfaces/srv/detail/reload_terrain__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/reload_terrain__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ReloadTerrain_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ReloadTerrain_Response_type_support_ids_t;

static const _ReloadTerrain_Response_type_support_ids_t _ReloadTerrain_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ReloadTerrain_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ReloadTerrain_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ReloadTerrain_Response_type_support_symbol_names_t _ReloadTerrain_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav_interfaces, srv, ReloadTerrain_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ReloadTerrain_Response)),
  }
};

typedef struct _ReloadTerrain_Response_type_support_data_t
{
  void * data[2];
} _ReloadTerrain_Response_type_support_data_t;

static _ReloadTerrain_Response_type_support_data_t _ReloadTerrain_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ReloadTerrain_Response_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_ReloadTerrain_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ReloadTerrain_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ReloadTerrain_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ReloadTerrain_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ReloadTerrain_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &nav_interfaces__srv__ReloadTerrain_Response__get_type_hash,
  &nav_interfaces__srv__ReloadTerrain_Response__get_type_description,
  &nav_interfaces__srv__ReloadTerrain_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Response>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_cpp::ReloadTerrain_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nav_interfaces, srv, ReloadTerrain_Response)() {
  return get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nav_interfaces/srv/detail/reload_terrain__functions.h"
// already included above
// #include "nav_interfaces/srv/detail/reload_terrain__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ReloadTerrain_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ReloadTerrain_Event_type_support_ids_t;

static const _ReloadTerrain_Event_type_support_ids_t _ReloadTerrain_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ReloadTerrain_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ReloadTerrain_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ReloadTerrain_Event_type_support_symbol_names_t _ReloadTerrain_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav_interfaces, srv, ReloadTerrain_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ReloadTerrain_Event)),
  }
};

typedef struct _ReloadTerrain_Event_type_support_data_t
{
  void * data[2];
} _ReloadTerrain_Event_type_support_data_t;

static _ReloadTerrain_Event_type_support_data_t _ReloadTerrain_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ReloadTerrain_Event_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_ReloadTerrain_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ReloadTerrain_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ReloadTerrain_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ReloadTerrain_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ReloadTerrain_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &nav_interfaces__srv__ReloadTerrain_Event__get_type_hash,
  &nav_interfaces__srv__ReloadTerrain_Event__get_type_description,
  &nav_interfaces__srv__ReloadTerrain_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Event>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_cpp::ReloadTerrain_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nav_interfaces, srv, ReloadTerrain_Event)() {
  return get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "nav_interfaces/srv/detail/reload_terrain__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ReloadTerrain_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ReloadTerrain_type_support_ids_t;

static const _ReloadTerrain_type_support_ids_t _ReloadTerrain_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ReloadTerrain_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ReloadTerrain_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ReloadTerrain_type_support_symbol_names_t _ReloadTerrain_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nav_interfaces, srv, ReloadTerrain)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nav_interfaces, srv, ReloadTerrain)),
  }
};

typedef struct _ReloadTerrain_type_support_data_t
{
  void * data[2];
} _ReloadTerrain_type_support_data_t;

static _ReloadTerrain_type_support_data_t _ReloadTerrain_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ReloadTerrain_service_typesupport_map = {
  2,
  "nav_interfaces",
  &_ReloadTerrain_service_typesupport_ids.typesupport_identifier[0],
  &_ReloadTerrain_service_typesupport_symbol_names.symbol_name[0],
  &_ReloadTerrain_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ReloadTerrain_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ReloadTerrain_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<nav_interfaces::srv::ReloadTerrain_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<nav_interfaces::srv::ReloadTerrain>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<nav_interfaces::srv::ReloadTerrain>,
  &nav_interfaces__srv__ReloadTerrain__get_type_hash,
  &nav_interfaces__srv__ReloadTerrain__get_type_description,
  &nav_interfaces__srv__ReloadTerrain__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<nav_interfaces::srv::ReloadTerrain>()
{
  return &::nav_interfaces::srv::rosidl_typesupport_cpp::ReloadTerrain_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, nav_interfaces, srv, ReloadTerrain)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<nav_interfaces::srv::ReloadTerrain>();
}

#ifdef __cplusplus
}
#endif
