// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/GimbCmdFram.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/gimb_cmd_fram.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__GimbCmdFram __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__GimbCmdFram __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GimbCmdFram_
{
  using Type = GimbCmdFram_<ContainerAllocator>;

  explicit GimbCmdFram_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->center_yaw = 0.0f;
      this->armor_pitch = 0.0f;
      this->armor_yaw = 0.0f;
      this->spin_flag = 0;
      this->shot_mode = 0;
    }
  }

  explicit GimbCmdFram_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->center_yaw = 0.0f;
      this->armor_pitch = 0.0f;
      this->armor_yaw = 0.0f;
      this->spin_flag = 0;
      this->shot_mode = 0;
    }
  }

  // field types and members
  using _center_yaw_type =
    float;
  _center_yaw_type center_yaw;
  using _armor_pitch_type =
    float;
  _armor_pitch_type armor_pitch;
  using _armor_yaw_type =
    float;
  _armor_yaw_type armor_yaw;
  using _spin_flag_type =
    uint8_t;
  _spin_flag_type spin_flag;
  using _shot_mode_type =
    uint8_t;
  _shot_mode_type shot_mode;

  // setters for named parameter idiom
  Type & set__center_yaw(
    const float & _arg)
  {
    this->center_yaw = _arg;
    return *this;
  }
  Type & set__armor_pitch(
    const float & _arg)
  {
    this->armor_pitch = _arg;
    return *this;
  }
  Type & set__armor_yaw(
    const float & _arg)
  {
    this->armor_yaw = _arg;
    return *this;
  }
  Type & set__spin_flag(
    const uint8_t & _arg)
  {
    this->spin_flag = _arg;
    return *this;
  }
  Type & set__shot_mode(
    const uint8_t & _arg)
  {
    this->shot_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::GimbCmdFram_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::GimbCmdFram_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::GimbCmdFram_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::GimbCmdFram_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__GimbCmdFram
    std::shared_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__GimbCmdFram
    std::shared_ptr<robots_msgs::msg::GimbCmdFram_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GimbCmdFram_ & other) const
  {
    if (this->center_yaw != other.center_yaw) {
      return false;
    }
    if (this->armor_pitch != other.armor_pitch) {
      return false;
    }
    if (this->armor_yaw != other.armor_yaw) {
      return false;
    }
    if (this->spin_flag != other.spin_flag) {
      return false;
    }
    if (this->shot_mode != other.shot_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const GimbCmdFram_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GimbCmdFram_

// alias to use template instance with default allocator
using GimbCmdFram =
  robots_msgs::msg::GimbCmdFram_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__GIMB_CMD_FRAM__STRUCT_HPP_
