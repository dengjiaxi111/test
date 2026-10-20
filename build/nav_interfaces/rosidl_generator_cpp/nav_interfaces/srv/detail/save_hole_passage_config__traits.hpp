// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_interfaces:srv/SaveHolePassageConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/save_hole_passage_config.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__SAVE_HOLE_PASSAGE_CONFIG__TRAITS_HPP_
#define NAV_INTERFACES__SRV__DETAIL__SAVE_HOLE_PASSAGE_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nav_interfaces/srv/detail/save_hole_passage_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveHolePassageConfig_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: expected_config_revision
  {
    out << "expected_config_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.expected_config_revision, out);
    out << ", ";
  }

  // member: expected_terrain_revision
  {
    out << "expected_terrain_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.expected_terrain_revision, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveHolePassageConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: expected_config_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "expected_config_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.expected_config_revision, out);
    out << "\n";
  }

  // member: expected_terrain_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "expected_terrain_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.expected_terrain_revision, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveHolePassageConfig_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nav_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nav_interfaces::srv::SaveHolePassageConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::srv::SaveHolePassageConfig_Request & msg)
{
  return nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::srv::SaveHolePassageConfig_Request>()
{
  return "nav_interfaces::srv::SaveHolePassageConfig_Request";
}

template<>
inline const char * name<nav_interfaces::srv::SaveHolePassageConfig_Request>()
{
  return "nav_interfaces/srv/SaveHolePassageConfig_Request";
}

template<>
struct has_fixed_size<nav_interfaces::srv::SaveHolePassageConfig_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nav_interfaces::srv::SaveHolePassageConfig_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveHolePassageConfig_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: config_path
  {
    out << "config_path: ";
    rosidl_generator_traits::value_to_yaml(msg.config_path, out);
    out << ", ";
  }

  // member: config_revision
  {
    out << "config_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.config_revision, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveHolePassageConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }

  // member: config_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "config_path: ";
    rosidl_generator_traits::value_to_yaml(msg.config_path, out);
    out << "\n";
  }

  // member: config_revision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "config_revision: ";
    rosidl_generator_traits::value_to_yaml(msg.config_revision, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveHolePassageConfig_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nav_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nav_interfaces::srv::SaveHolePassageConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::srv::SaveHolePassageConfig_Response & msg)
{
  return nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::srv::SaveHolePassageConfig_Response>()
{
  return "nav_interfaces::srv::SaveHolePassageConfig_Response";
}

template<>
inline const char * name<nav_interfaces::srv::SaveHolePassageConfig_Response>()
{
  return "nav_interfaces/srv/SaveHolePassageConfig_Response";
}

template<>
struct has_fixed_size<nav_interfaces::srv::SaveHolePassageConfig_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_interfaces::srv::SaveHolePassageConfig_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace nav_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveHolePassageConfig_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveHolePassageConfig_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveHolePassageConfig_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace nav_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nav_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nav_interfaces::srv::SaveHolePassageConfig_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  nav_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nav_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nav_interfaces::srv::SaveHolePassageConfig_Event & msg)
{
  return nav_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nav_interfaces::srv::SaveHolePassageConfig_Event>()
{
  return "nav_interfaces::srv::SaveHolePassageConfig_Event";
}

template<>
inline const char * name<nav_interfaces::srv::SaveHolePassageConfig_Event>()
{
  return "nav_interfaces/srv/SaveHolePassageConfig_Event";
}

template<>
struct has_fixed_size<nav_interfaces::srv::SaveHolePassageConfig_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Event>
  : std::integral_constant<bool, has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Request>::value && has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<nav_interfaces::srv::SaveHolePassageConfig_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nav_interfaces::srv::SaveHolePassageConfig>()
{
  return "nav_interfaces::srv::SaveHolePassageConfig";
}

template<>
inline const char * name<nav_interfaces::srv::SaveHolePassageConfig>()
{
  return "nav_interfaces/srv/SaveHolePassageConfig";
}

template<>
struct has_fixed_size<nav_interfaces::srv::SaveHolePassageConfig>
  : std::integral_constant<
    bool,
    has_fixed_size<nav_interfaces::srv::SaveHolePassageConfig_Request>::value &&
    has_fixed_size<nav_interfaces::srv::SaveHolePassageConfig_Response>::value
  >
{
};

template<>
struct has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig>
  : std::integral_constant<
    bool,
    has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Request>::value &&
    has_bounded_size<nav_interfaces::srv::SaveHolePassageConfig_Response>::value
  >
{
};

template<>
struct is_service<nav_interfaces::srv::SaveHolePassageConfig>
  : std::true_type
{
};

template<>
struct is_service_request<nav_interfaces::srv::SaveHolePassageConfig_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nav_interfaces::srv::SaveHolePassageConfig_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAV_INTERFACES__SRV__DETAIL__SAVE_HOLE_PASSAGE_CONFIG__TRAITS_HPP_
