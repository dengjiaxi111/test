// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/my_path.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MY_PATH__TRAITS_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__MY_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robots_msgs/msg/detail/my_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robots_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MyPath & msg,
  std::ostream & out)
{
  out << "{";
  // member: intention
  {
    out << "intention: ";
    rosidl_generator_traits::value_to_yaml(msg.intention, out);
    out << ", ";
  }

  // member: start_x
  {
    out << "start_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_x, out);
    out << ", ";
  }

  // member: start_y
  {
    out << "start_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_y, out);
    out << ", ";
  }

  // member: delta_x
  {
    if (msg.delta_x.size() == 0) {
      out << "delta_x: []";
    } else {
      out << "delta_x: [";
      size_t pending_items = msg.delta_x.size();
      for (auto item : msg.delta_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: delta_y
  {
    if (msg.delta_y.size() == 0) {
      out << "delta_y: []";
    } else {
      out << "delta_y: [";
      size_t pending_items = msg.delta_y.size();
      for (auto item : msg.delta_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: sender_id
  {
    out << "sender_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sender_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: intention
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intention: ";
    rosidl_generator_traits::value_to_yaml(msg.intention, out);
    out << "\n";
  }

  // member: start_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_x: ";
    rosidl_generator_traits::value_to_yaml(msg.start_x, out);
    out << "\n";
  }

  // member: start_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_y: ";
    rosidl_generator_traits::value_to_yaml(msg.start_y, out);
    out << "\n";
  }

  // member: delta_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.delta_x.size() == 0) {
      out << "delta_x: []\n";
    } else {
      out << "delta_x:\n";
      for (auto item : msg.delta_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: delta_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.delta_y.size() == 0) {
      out << "delta_y: []\n";
    } else {
      out << "delta_y:\n";
      for (auto item : msg.delta_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: sender_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sender_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sender_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyPath & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robots_msgs

namespace rosidl_generator_traits
{

[[deprecated("use robots_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robots_msgs::msg::MyPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  robots_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robots_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robots_msgs::msg::MyPath & msg)
{
  return robots_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robots_msgs::msg::MyPath>()
{
  return "robots_msgs::msg::MyPath";
}

template<>
inline const char * name<robots_msgs::msg::MyPath>()
{
  return "robots_msgs/msg/MyPath";
}

template<>
struct has_fixed_size<robots_msgs::msg::MyPath>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robots_msgs::msg::MyPath>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robots_msgs::msg::MyPath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTS_MSGS__MSG__DETAIL__MY_PATH__TRAITS_HPP_
