// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_state.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__STRUCT_HPP_

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
# define DEPRECATED__nav_interfaces__msg__HoleTraversalState __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleTraversalState __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleTraversalState_
{
  using Type = HoleTraversalState_<ContainerAllocator>;

  explicit HoleTraversalState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->plan_id = 0ull;
      this->state = 0;
      this->decision = 0;
      this->s_progress = 0.0;
      this->speed_limit = 0.0;
      this->reason = "";
      this->attempt = 0ul;
      this->recovery_phase = 0;
    }
  }

  explicit HoleTraversalState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    session_id(_alloc),
    goal_id(_alloc),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->plan_id = 0ull;
      this->state = 0;
      this->decision = 0;
      this->s_progress = 0.0;
      this->speed_limit = 0.0;
      this->reason = "";
      this->attempt = 0ul;
      this->recovery_phase = 0;
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
  using _state_type =
    uint8_t;
  _state_type state;
  using _decision_type =
    uint8_t;
  _decision_type decision;
  using _s_progress_type =
    double;
  _s_progress_type s_progress;
  using _speed_limit_type =
    double;
  _speed_limit_type speed_limit;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;
  using _traversal_uids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _traversal_uids_type traversal_uids;
  using _phases_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _phases_type phases;
  using _preparing_required_type =
    std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>>;
  _preparing_required_type preparing_required;
  using _attempt_type =
    uint32_t;
  _attempt_type attempt;
  using _recovery_phase_type =
    uint8_t;
  _recovery_phase_type recovery_phase;

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
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__decision(
    const uint8_t & _arg)
  {
    this->decision = _arg;
    return *this;
  }
  Type & set__s_progress(
    const double & _arg)
  {
    this->s_progress = _arg;
    return *this;
  }
  Type & set__speed_limit(
    const double & _arg)
  {
    this->speed_limit = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }
  Type & set__traversal_uids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->traversal_uids = _arg;
    return *this;
  }
  Type & set__phases(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->phases = _arg;
    return *this;
  }
  Type & set__preparing_required(
    const std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>> & _arg)
  {
    this->preparing_required = _arg;
    return *this;
  }
  Type & set__attempt(
    const uint32_t & _arg)
  {
    this->attempt = _arg;
    return *this;
  }
  Type & set__recovery_phase(
    const uint8_t & _arg)
  {
    this->recovery_phase = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleTraversalState_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleTraversalState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleTraversalState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleTraversalState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleTraversalState
    std::shared_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleTraversalState
    std::shared_ptr<nav_interfaces::msg::HoleTraversalState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleTraversalState_ & other) const
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
    if (this->state != other.state) {
      return false;
    }
    if (this->decision != other.decision) {
      return false;
    }
    if (this->s_progress != other.s_progress) {
      return false;
    }
    if (this->speed_limit != other.speed_limit) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->traversal_uids != other.traversal_uids) {
      return false;
    }
    if (this->phases != other.phases) {
      return false;
    }
    if (this->preparing_required != other.preparing_required) {
      return false;
    }
    if (this->attempt != other.attempt) {
      return false;
    }
    if (this->recovery_phase != other.recovery_phase) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleTraversalState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleTraversalState_

// alias to use template instance with default allocator
using HoleTraversalState =
  nav_interfaces::msg::HoleTraversalState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__STRUCT_HPP_
