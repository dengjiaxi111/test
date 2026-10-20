// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/enemy_pose.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__EnemyPose __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__EnemyPose __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EnemyPose_
{
  using Type = EnemyPose_<ContainerAllocator>;

  explicit EnemyPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enemy_dist = 0.0f;
      this->enemy_ori = 0.0f;
      this->enemy_num = 0;
      this->enemy_x = 0.0f;
      this->enemy_y = 0.0f;
    }
  }

  explicit EnemyPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enemy_dist = 0.0f;
      this->enemy_ori = 0.0f;
      this->enemy_num = 0;
      this->enemy_x = 0.0f;
      this->enemy_y = 0.0f;
    }
  }

  // field types and members
  using _enemy_dist_type =
    float;
  _enemy_dist_type enemy_dist;
  using _enemy_ori_type =
    float;
  _enemy_ori_type enemy_ori;
  using _enemy_num_type =
    int8_t;
  _enemy_num_type enemy_num;
  using _enemy_x_type =
    float;
  _enemy_x_type enemy_x;
  using _enemy_y_type =
    float;
  _enemy_y_type enemy_y;

  // setters for named parameter idiom
  Type & set__enemy_dist(
    const float & _arg)
  {
    this->enemy_dist = _arg;
    return *this;
  }
  Type & set__enemy_ori(
    const float & _arg)
  {
    this->enemy_ori = _arg;
    return *this;
  }
  Type & set__enemy_num(
    const int8_t & _arg)
  {
    this->enemy_num = _arg;
    return *this;
  }
  Type & set__enemy_x(
    const float & _arg)
  {
    this->enemy_x = _arg;
    return *this;
  }
  Type & set__enemy_y(
    const float & _arg)
  {
    this->enemy_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::EnemyPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::EnemyPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::EnemyPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::EnemyPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__EnemyPose
    std::shared_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__EnemyPose
    std::shared_ptr<robots_msgs::msg::EnemyPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EnemyPose_ & other) const
  {
    if (this->enemy_dist != other.enemy_dist) {
      return false;
    }
    if (this->enemy_ori != other.enemy_ori) {
      return false;
    }
    if (this->enemy_num != other.enemy_num) {
      return false;
    }
    if (this->enemy_x != other.enemy_x) {
      return false;
    }
    if (this->enemy_y != other.enemy_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const EnemyPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EnemyPose_

// alias to use template instance with default allocator
using EnemyPose =
  robots_msgs::msg::EnemyPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__STRUCT_HPP_
