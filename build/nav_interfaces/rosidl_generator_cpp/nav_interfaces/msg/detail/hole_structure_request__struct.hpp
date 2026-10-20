// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_request.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_interfaces__msg__HoleStructureRequest __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleStructureRequest __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleStructureRequest_
{
  using Type = HoleStructureRequest_<ContainerAllocator>;

  explicit HoleStructureRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->request_id = 0ull;
      this->requirement_revision = 0ull;
      this->target = 0;
      this->cancel_motion = false;
    }
  }

  explicit HoleStructureRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    session_id(_alloc),
    goal_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->request_id = 0ull;
      this->requirement_revision = 0ull;
      this->target = 0;
      this->cancel_motion = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _session_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _session_id_type session_id;
  using _goal_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _goal_id_type goal_id;
  using _request_id_type =
    uint64_t;
  _request_id_type request_id;
  using _requirement_revision_type =
    uint64_t;
  _requirement_revision_type requirement_revision;
  using _target_type =
    uint8_t;
  _target_type target;
  using _traversal_uids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _traversal_uids_type traversal_uids;
  using _cancel_motion_type =
    bool;
  _cancel_motion_type cancel_motion;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__session_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->session_id = _arg;
    return *this;
  }
  Type & set__goal_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__request_id(
    const uint64_t & _arg)
  {
    this->request_id = _arg;
    return *this;
  }
  Type & set__requirement_revision(
    const uint64_t & _arg)
  {
    this->requirement_revision = _arg;
    return *this;
  }
  Type & set__target(
    const uint8_t & _arg)
  {
    this->target = _arg;
    return *this;
  }
  Type & set__traversal_uids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->traversal_uids = _arg;
    return *this;
  }
  Type & set__cancel_motion(
    const bool & _arg)
  {
    this->cancel_motion = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t KEEP =
    0u;
  static constexpr uint8_t LOW =
    1u;
  static constexpr uint8_t NORMAL =
    2u;

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleStructureRequest
    std::shared_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleStructureRequest
    std::shared_ptr<nav_interfaces::msg::HoleStructureRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleStructureRequest_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->session_id != other.session_id) {
      return false;
    }
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->request_id != other.request_id) {
      return false;
    }
    if (this->requirement_revision != other.requirement_revision) {
      return false;
    }
    if (this->target != other.target) {
      return false;
    }
    if (this->traversal_uids != other.traversal_uids) {
      return false;
    }
    if (this->cancel_motion != other.cancel_motion) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleStructureRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleStructureRequest_

// alias to use template instance with default allocator
using HoleStructureRequest =
  nav_interfaces::msg::HoleStructureRequest_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureRequest_<ContainerAllocator>::KEEP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureRequest_<ContainerAllocator>::LOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureRequest_<ContainerAllocator>::NORMAL;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__STRUCT_HPP_
