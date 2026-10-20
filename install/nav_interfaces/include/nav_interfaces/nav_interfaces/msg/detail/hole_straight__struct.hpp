// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleStraight.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_straight.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_interfaces__msg__HoleStraight __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleStraight __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleStraight_
{
  using Type = HoleStraight_<ContainerAllocator>;

  explicit HoleStraight_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : direction(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->s_begin = 0.0;
      this->s_end = 0.0;
      this->remaining = false;
    }
  }

  explicit HoleStraight_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : direction(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->s_begin = 0.0;
      this->s_end = 0.0;
      this->remaining = false;
    }
  }

  // field types and members
  using _s_begin_type =
    double;
  _s_begin_type s_begin;
  using _s_end_type =
    double;
  _s_end_type s_end;
  using _direction_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _direction_type direction;
  using _remaining_type =
    bool;
  _remaining_type remaining;

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
  Type & set__direction(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__remaining(
    const bool & _arg)
  {
    this->remaining = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleStraight_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleStraight_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleStraight_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleStraight_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleStraight
    std::shared_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleStraight
    std::shared_ptr<nav_interfaces::msg::HoleStraight_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleStraight_ & other) const
  {
    if (this->s_begin != other.s_begin) {
      return false;
    }
    if (this->s_end != other.s_end) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->remaining != other.remaining) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleStraight_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleStraight_

// alias to use template instance with default allocator
using HoleStraight =
  nav_interfaces::msg::HoleStraight_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__STRUCT_HPP_
