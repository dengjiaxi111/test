// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/ModeCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/mode_cmd.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__ModeCmd __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__ModeCmd __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModeCmd_
{
  using Type = ModeCmd_<ContainerAllocator>;

  explicit ModeCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->should_chassis_spin = 0;
      this->should_gimbal_patrol = 0;
      this->buy_bullet = 0;
      this->rebirth = 0;
      this->use_capacity = 0;
    }
  }

  explicit ModeCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->should_chassis_spin = 0;
      this->should_gimbal_patrol = 0;
      this->buy_bullet = 0;
      this->rebirth = 0;
      this->use_capacity = 0;
    }
  }

  // field types and members
  using _should_chassis_spin_type =
    uint8_t;
  _should_chassis_spin_type should_chassis_spin;
  using _should_gimbal_patrol_type =
    uint8_t;
  _should_gimbal_patrol_type should_gimbal_patrol;
  using _buy_bullet_type =
    uint8_t;
  _buy_bullet_type buy_bullet;
  using _rebirth_type =
    uint8_t;
  _rebirth_type rebirth;
  using _use_capacity_type =
    uint8_t;
  _use_capacity_type use_capacity;

  // setters for named parameter idiom
  Type & set__should_chassis_spin(
    const uint8_t & _arg)
  {
    this->should_chassis_spin = _arg;
    return *this;
  }
  Type & set__should_gimbal_patrol(
    const uint8_t & _arg)
  {
    this->should_gimbal_patrol = _arg;
    return *this;
  }
  Type & set__buy_bullet(
    const uint8_t & _arg)
  {
    this->buy_bullet = _arg;
    return *this;
  }
  Type & set__rebirth(
    const uint8_t & _arg)
  {
    this->rebirth = _arg;
    return *this;
  }
  Type & set__use_capacity(
    const uint8_t & _arg)
  {
    this->use_capacity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::ModeCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::ModeCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::ModeCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::ModeCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__ModeCmd
    std::shared_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__ModeCmd
    std::shared_ptr<robots_msgs::msg::ModeCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModeCmd_ & other) const
  {
    if (this->should_chassis_spin != other.should_chassis_spin) {
      return false;
    }
    if (this->should_gimbal_patrol != other.should_gimbal_patrol) {
      return false;
    }
    if (this->buy_bullet != other.buy_bullet) {
      return false;
    }
    if (this->rebirth != other.rebirth) {
      return false;
    }
    if (this->use_capacity != other.use_capacity) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModeCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModeCmd_

// alias to use template instance with default allocator
using ModeCmd =
  robots_msgs::msg::ModeCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__MODE_CMD__STRUCT_HPP_
