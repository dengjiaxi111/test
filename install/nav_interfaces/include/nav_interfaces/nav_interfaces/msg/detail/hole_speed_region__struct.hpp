// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_speed_region.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__nav_interfaces__msg__HoleSpeedRegion __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleSpeedRegion __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleSpeedRegion_
{
  using Type = HoleSpeedRegion_<ContainerAllocator>;

  explicit HoleSpeedRegion_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->s_begin = 0.0;
      this->s_end = 0.0;
      this->speed_limit = 0.0;
      this->kind = 0;
    }
  }

  explicit HoleSpeedRegion_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->s_begin = 0.0;
      this->s_end = 0.0;
      this->speed_limit = 0.0;
      this->kind = 0;
    }
  }

  // field types and members
  using _s_begin_type =
    double;
  _s_begin_type s_begin;
  using _s_end_type =
    double;
  _s_end_type s_end;
  using _speed_limit_type =
    double;
  _speed_limit_type speed_limit;
  using _kind_type =
    uint8_t;
  _kind_type kind;

  // setters for named parameter idiom
  Type & set__s_begin(
    const double & _arg)
  {
    this->s_begin = _arg;
    return *this;
  }
  Type & set__s_end(
    const double & _arg)
  {
    this->s_end = _arg;
    return *this;
  }
  Type & set__speed_limit(
    const double & _arg)
  {
    this->speed_limit = _arg;
    return *this;
  }
  Type & set__kind(
    const uint8_t & _arg)
  {
    this->kind = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleSpeedRegion
    std::shared_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleSpeedRegion
    std::shared_ptr<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleSpeedRegion_ & other) const
  {
    if (this->s_begin != other.s_begin) {
      return false;
    }
    if (this->s_end != other.s_end) {
      return false;
    }
    if (this->speed_limit != other.speed_limit) {
      return false;
    }
    if (this->kind != other.kind) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleSpeedRegion_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleSpeedRegion_

// alias to use template instance with default allocator
using HoleSpeedRegion =
  nav_interfaces::msg::HoleSpeedRegion_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__STRUCT_HPP_
