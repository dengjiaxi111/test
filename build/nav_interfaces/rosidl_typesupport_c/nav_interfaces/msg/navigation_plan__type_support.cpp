// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "nav_interfaces/msg/detail/navigation_plan__struct.h"
#include "nav_interfaces/msg/detail/navigation_plan__type_support.h"
#include "nav_interfaces/msg/detail/navigation_plan__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace nav_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _NavigationPlan_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _NavigationPlan_type_support_ids_t;

static const _NavigationPlan_type_support_ids_t _NavigationPlan_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _NavigationPlan_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _NavigationPlan_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _NavigationPlan_type_support_symbol_names_t _NavigationPlan_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_interfaces, msg, NavigationPlan)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_interfaces, msg, NavigationPlan)),
  }
};

typedef struct _NavigationPlan_type_support_data_t
{
  void * data[2];
} _NavigationPlan_type_support_data_t;

static _NavigationPlan_type_support_data_t _NavigationPlan_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _NavigationPlan_message_typesupport_map = {
  2,
  "nav_interfaces",
  &_NavigationPlan_message_typesupport_ids.typesupport_identifier[0],
  &_NavigationPlan_message_typesupport_symbol_names.symbol_name[0],
  &_NavigationPlan_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t NavigationPlan_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_NavigationPlan_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &nav_interfaces__msg__NavigationPlan__get_type_hash,
  &nav_interfaces__msg__NavigationPlan__get_type_description,
  &nav_interfaces__msg__NavigationPlan__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace nav_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, nav_interfaces, msg, NavigationPlan)() {
  return &::nav_interfaces::msg::rosidl_typesupport_c::NavigationPlan_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
