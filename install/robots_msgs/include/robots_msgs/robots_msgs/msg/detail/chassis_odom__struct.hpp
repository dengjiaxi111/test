// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/ChassisOdom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/chassis_odom.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__ChassisOdom __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__ChassisOdom __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ChassisOdom_
{
  using Type = ChassisOdom_<ContainerAllocator>;

  explicit ChassisOdom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_x = 0.0f;
      this->speed_y = 0.0f;
      this->speed_w = 0.0f;
      this->gimbal_angle = 0.0f;
      this->capacitor_voltage = 0.0f;
    }
  }

  explicit ChassisOdom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_x = 0.0f;
      this->speed_y = 0.0f;
      this->speed_w = 0.0f;
      this->gimbal_angle = 0.0f;
      this->capacitor_voltage = 0.0f;
    }
  }

  // field types and members
  using _speed_x_type =
    float;
  _speed_x_type speed_x;
  using _speed_y_type =
    float;
  _speed_y_type speed_y;
  using _speed_w_type =
    float;
  _speed_w_type speed_w;
  using _gimbal_angle_type =
    float;
  _gimbal_angle_type gimbal_angle;
  using _capacitor_voltage_type =
    float;
  _capacitor_voltage_type capacitor_voltage;

  // setters for named parameter idiom
  Type & set__speed_x(
    const float & _arg)
  {
    this->speed_x = _arg;
    return *this;
  }
  Type & set__speed_y(
    const float & _arg)
  {
    this->speed_y = _arg;
    return *this;
  }
  Type & set__speed_w(
    const float & _arg)
  {
    this->speed_w = _arg;
    return *this;
  }
  Type & set__gimbal_angle(
    const float & _arg)
  {
    this->gimbal_angle = _arg;
    return *this;
  }
  Type & set__capacitor_voltage(
    const float & _arg)
  {
    this->capacitor_voltage = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::ChassisOdom_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::ChassisOdom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::ChassisOdom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::ChassisOdom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__ChassisOdom
    std::shared_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__ChassisOdom
    std::shared_ptr<robots_msgs::msg::ChassisOdom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChassisOdom_ & other) const
  {
    if (this->speed_x != other.speed_x) {
      return false;
    }
    if (this->speed_y != other.speed_y) {
      return false;
    }
    if (this->speed_w != other.speed_w) {
      return false;
    }
    if (this->gimbal_angle != other.gimbal_angle) {
      return false;
    }
    if (this->capacitor_voltage != other.capacitor_voltage) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChassisOdom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChassisOdom_

// alias to use template instance with default allocator
using ChassisOdom =
  robots_msgs::msg::ChassisOdom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__CHASSIS_ODOM__STRUCT_HPP_
