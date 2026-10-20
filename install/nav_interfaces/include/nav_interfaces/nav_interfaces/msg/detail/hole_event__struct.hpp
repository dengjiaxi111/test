// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_event.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_interfaces__msg__HoleEvent __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleEvent __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleEvent_
{
  using Type = HoleEvent_<ContainerAllocator>;

  explicit HoleEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->range_status = 0;
      this->s_path = 0.0;
      this->point_valid = false;
    }
  }

  explicit HoleEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->range_status = 0;
      this->s_path = 0.0;
      this->point_valid = false;
    }
  }

  // field types and members
  using _type_type =
    uint8_t;
  _type_type type;
  using _range_status_type =
    uint8_t;
  _range_status_type range_status;
  using _s_path_type =
    double;
  _s_path_type s_path;
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;
  using _point_valid_type =
    bool;
  _point_valid_type point_valid;

  // setters for named parameter idiom
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__range_status(
    const uint8_t & _arg)
  {
    this->range_status = _arg;
    return *this;
  }
  Type & set__s_path(
    const double & _arg)
  {
    this->s_path = _arg;
    return *this;
  }
  Type & set__point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__point_valid(
    const bool & _arg)
  {
    this->point_valid = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t A =
    0u;
  static constexpr uint8_t S =
    1u;
  static constexpr uint8_t E =
    2u;
  static constexpr uint8_t X =
    3u;
  static constexpr uint8_t T =
    4u;
  static constexpr uint8_t D =
    5u;
  static constexpr uint8_t ON_PATH =
    0u;
  static constexpr uint8_t BEFORE_PATH =
    1u;
  static constexpr uint8_t AFTER_PATH =
    2u;
  static constexpr uint8_t UNKNOWN =
    3u;

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleEvent
    std::shared_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleEvent
    std::shared_ptr<nav_interfaces::msg::HoleEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleEvent_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->range_status != other.range_status) {
      return false;
    }
    if (this->s_path != other.s_path) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->point_valid != other.point_valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleEvent_

// alias to use template instance with default allocator
using HoleEvent =
  nav_interfaces::msg::HoleEvent_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::A;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::S;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::E;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::X;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::T;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::D;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::ON_PATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::BEFORE_PATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::AFTER_PATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleEvent_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__STRUCT_HPP_
