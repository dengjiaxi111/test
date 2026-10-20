// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleTraversalEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_event.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__STRUCT_HPP_

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
# define DEPRECATED__nav_interfaces__msg__HoleTraversalEvent __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleTraversalEvent __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleTraversalEvent_
{
  using Type = HoleTraversalEvent_<ContainerAllocator>;

  explicit HoleTraversalEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->plan_id = 0ull;
      this->traversal_uid = "";
      this->sequence = 0ull;
      this->type = 0;
      this->event_arc = 0.0;
      this->progress = 0.0;
      this->attempt = 0ul;
    }
  }

  explicit HoleTraversalEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    session_id(_alloc),
    goal_id(_alloc),
    traversal_uid(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->plan_id = 0ull;
      this->traversal_uid = "";
      this->sequence = 0ull;
      this->type = 0;
      this->event_arc = 0.0;
      this->progress = 0.0;
      this->attempt = 0ul;
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
  using _plan_id_type =
    uint64_t;
  _plan_id_type plan_id;
  using _traversal_uid_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _traversal_uid_type traversal_uid;
  using _sequence_type =
    uint64_t;
  _sequence_type sequence;
  using _type_type =
    uint8_t;
  _type_type type;
  using _event_arc_type =
    double;
  _event_arc_type event_arc;
  using _progress_type =
    double;
  _progress_type progress;
  using _attempt_type =
    uint32_t;
  _attempt_type attempt;

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
  Type & set__plan_id(
    const uint64_t & _arg)
  {
    this->plan_id = _arg;
    return *this;
  }
  Type & set__traversal_uid(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->traversal_uid = _arg;
    return *this;
  }
  Type & set__sequence(
    const uint64_t & _arg)
  {
    this->sequence = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__event_arc(
    const double & _arg)
  {
    this->event_arc = _arg;
    return *this;
  }
  Type & set__progress(
    const double & _arg)
  {
    this->progress = _arg;
    return *this;
  }
  Type & set__attempt(
    const uint32_t & _arg)
  {
    this->attempt = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleTraversalEvent
    std::shared_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleTraversalEvent
    std::shared_ptr<nav_interfaces::msg::HoleTraversalEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleTraversalEvent_ & other) const
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
    if (this->plan_id != other.plan_id) {
      return false;
    }
    if (this->traversal_uid != other.traversal_uid) {
      return false;
    }
    if (this->sequence != other.sequence) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->event_arc != other.event_arc) {
      return false;
    }
    if (this->progress != other.progress) {
      return false;
    }
    if (this->attempt != other.attempt) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleTraversalEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleTraversalEvent_

// alias to use template instance with default allocator
using HoleTraversalEvent =
  nav_interfaces::msg::HoleTraversalEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__STRUCT_HPP_
