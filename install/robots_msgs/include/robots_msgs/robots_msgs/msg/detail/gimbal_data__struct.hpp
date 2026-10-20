// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/GimbalData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimbal_data.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__GimbalData __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__GimbalData __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GimbalData_
{
  using Type = GimbalData_<ContainerAllocator>;

  explicit GimbalData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gimbal_yaw = 0.0f;
      this->gimbal_pitch = 0.0f;
      this->yaw_va = 0.0f;
      this->base_yaw = 0.0f;
      this->self_team = 0;
    }
  }

  explicit GimbalData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gimbal_yaw = 0.0f;
      this->gimbal_pitch = 0.0f;
      this->yaw_va = 0.0f;
      this->base_yaw = 0.0f;
      this->self_team = 0;
    }
  }

  // field types and members
  using _gimbal_yaw_type =
    float;
  _gimbal_yaw_type gimbal_yaw;
  using _gimbal_pitch_type =
    float;
  _gimbal_pitch_type gimbal_pitch;
  using _yaw_va_type =
    float;
  _yaw_va_type yaw_va;
  using _base_yaw_type =
    float;
  _base_yaw_type base_yaw;
  using _self_team_type =
    uint8_t;
  _self_team_type self_team;

  // setters for named parameter idiom
  Type & set__gimbal_yaw(
    const float & _arg)
  {
    this->gimbal_yaw = _arg;
    return *this;
  }
  Type & set__gimbal_pitch(
    const float & _arg)
  {
    this->gimbal_pitch = _arg;
    return *this;
  }
  Type & set__yaw_va(
    const float & _arg)
  {
    this->yaw_va = _arg;
    return *this;
  }
  Type & set__base_yaw(
    const float & _arg)
  {
    this->base_yaw = _arg;
    return *this;
  }
  Type & set__self_team(
    const uint8_t & _arg)
  {
    this->self_team = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::GimbalData_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::GimbalData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::GimbalData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::GimbalData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__GimbalData
    std::shared_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__GimbalData
    std::shared_ptr<robots_msgs::msg::GimbalData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GimbalData_ & other) const
  {
    if (this->gimbal_yaw != other.gimbal_yaw) {
      return false;
    }
    if (this->gimbal_pitch != other.gimbal_pitch) {
      return false;
    }
    if (this->yaw_va != other.yaw_va) {
      return false;
    }
    if (this->base_yaw != other.base_yaw) {
      return false;
    }
    if (this->self_team != other.self_team) {
      return false;
    }
    return true;
  }
  bool operator!=(const GimbalData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GimbalData_

// alias to use template instance with default allocator
using GimbalData =
  robots_msgs::msg::GimbalData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMBAL_DATA__STRUCT_HPP_
