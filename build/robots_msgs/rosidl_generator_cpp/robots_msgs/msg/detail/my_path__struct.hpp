// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/my_path.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MY_PATH__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__MY_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__MyPath __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__MyPath __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyPath_
{
  using Type = MyPath_<ContainerAllocator>;

  explicit MyPath_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->intention = 0;
      this->start_x = 0;
      this->start_y = 0;
      this->sender_id = 0;
    }
  }

  explicit MyPath_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->intention = 0;
      this->start_x = 0;
      this->start_y = 0;
      this->sender_id = 0;
    }
  }

  // field types and members
  using _intention_type =
    uint8_t;
  _intention_type intention;
  using _start_x_type =
    uint16_t;
  _start_x_type start_x;
  using _start_y_type =
    uint16_t;
  _start_y_type start_y;
  using _delta_x_type =
    std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>>;
  _delta_x_type delta_x;
  using _delta_y_type =
    std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>>;
  _delta_y_type delta_y;
  using _sender_id_type =
    uint16_t;
  _sender_id_type sender_id;

  // setters for named parameter idiom
  Type & set__intention(
    const uint8_t & _arg)
  {
    this->intention = _arg;
    return *this;
  }
  Type & set__start_x(
    const uint16_t & _arg)
  {
    this->start_x = _arg;
    return *this;
  }
  Type & set__start_y(
    const uint16_t & _arg)
  {
    this->start_y = _arg;
    return *this;
  }
  Type & set__delta_x(
    const std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>> & _arg)
  {
    this->delta_x = _arg;
    return *this;
  }
  Type & set__delta_y(
    const std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>> & _arg)
  {
    this->delta_y = _arg;
    return *this;
  }
  Type & set__sender_id(
    const uint16_t & _arg)
  {
    this->sender_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::MyPath_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::MyPath_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::MyPath_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::MyPath_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::MyPath_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::MyPath_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::MyPath_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::MyPath_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::MyPath_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::MyPath_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__MyPath
    std::shared_ptr<robots_msgs::msg::MyPath_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__MyPath
    std::shared_ptr<robots_msgs::msg::MyPath_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyPath_ & other) const
  {
    if (this->intention != other.intention) {
      return false;
    }
    if (this->start_x != other.start_x) {
      return false;
    }
    if (this->start_y != other.start_y) {
      return false;
    }
    if (this->delta_x != other.delta_x) {
      return false;
    }
    if (this->delta_y != other.delta_y) {
      return false;
    }
    if (this->sender_id != other.sender_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyPath_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyPath_

// alias to use template instance with default allocator
using MyPath =
  robots_msgs::msg::MyPath_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__MY_PATH__STRUCT_HPP_
