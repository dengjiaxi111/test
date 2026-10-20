// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleStructureFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_feedback.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__STRUCT_HPP_

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
# define DEPRECATED__nav_interfaces__msg__HoleStructureFeedback __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleStructureFeedback __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleStructureFeedback_
{
  using Type = HoleStructureFeedback_<ContainerAllocator>;

  explicit HoleStructureFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
      this->status = 0;
      this->whole_vehicle_clear = false;
      this->normal_clearance = false;
      this->moving_transition_supported = false;
      this->simulated = false;
      this->action_stopped = false;
      this->retry_allowed = false;
      this->fault_code = 0;
    }
  }

  explicit HoleStructureFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
      this->status = 0;
      this->whole_vehicle_clear = false;
      this->normal_clearance = false;
      this->moving_transition_supported = false;
      this->simulated = false;
      this->action_stopped = false;
      this->retry_allowed = false;
      this->fault_code = 0;
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
  using _status_type =
    uint8_t;
  _status_type status;
  using _whole_vehicle_clear_type =
    bool;
  _whole_vehicle_clear_type whole_vehicle_clear;
  using _normal_clearance_type =
    bool;
  _normal_clearance_type normal_clearance;
  using _moving_transition_supported_type =
    bool;
  _moving_transition_supported_type moving_transition_supported;
  using _cleared_traversal_uids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _cleared_traversal_uids_type cleared_traversal_uids;
  using _simulated_type =
    bool;
  _simulated_type simulated;
  using _action_stopped_type =
    bool;
  _action_stopped_type action_stopped;
  using _retry_allowed_type =
    bool;
  _retry_allowed_type retry_allowed;
  using _fault_code_type =
    uint16_t;
  _fault_code_type fault_code;

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
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__whole_vehicle_clear(
    const bool & _arg)
  {
    this->whole_vehicle_clear = _arg;
    return *this;
  }
  Type & set__normal_clearance(
    const bool & _arg)
  {
    this->normal_clearance = _arg;
    return *this;
  }
  Type & set__moving_transition_supported(
    const bool & _arg)
  {
    this->moving_transition_supported = _arg;
    return *this;
  }
  Type & set__cleared_traversal_uids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->cleared_traversal_uids = _arg;
    return *this;
  }
  Type & set__simulated(
    const bool & _arg)
  {
    this->simulated = _arg;
    return *this;
  }
  Type & set__action_stopped(
    const bool & _arg)
  {
    this->action_stopped = _arg;
    return *this;
  }
  Type & set__retry_allowed(
    const bool & _arg)
  {
    this->retry_allowed = _arg;
    return *this;
  }
  Type & set__fault_code(
    const uint16_t & _arg)
  {
    this->fault_code = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t EXECUTING =
    0u;
  static constexpr uint8_t COMPLETED =
    1u;
  static constexpr uint8_t FAILED =
    2u;
  static constexpr uint8_t CANCELLED =
    3u;

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleStructureFeedback
    std::shared_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleStructureFeedback
    std::shared_ptr<nav_interfaces::msg::HoleStructureFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleStructureFeedback_ & other) const
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
    if (this->status != other.status) {
      return false;
    }
    if (this->whole_vehicle_clear != other.whole_vehicle_clear) {
      return false;
    }
    if (this->normal_clearance != other.normal_clearance) {
      return false;
    }
    if (this->moving_transition_supported != other.moving_transition_supported) {
      return false;
    }
    if (this->cleared_traversal_uids != other.cleared_traversal_uids) {
      return false;
    }
    if (this->simulated != other.simulated) {
      return false;
    }
    if (this->action_stopped != other.action_stopped) {
      return false;
    }
    if (this->retry_allowed != other.retry_allowed) {
      return false;
    }
    if (this->fault_code != other.fault_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleStructureFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleStructureFeedback_

// alias to use template instance with default allocator
using HoleStructureFeedback =
  nav_interfaces::msg::HoleStructureFeedback_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureFeedback_<ContainerAllocator>::EXECUTING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureFeedback_<ContainerAllocator>::COMPLETED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureFeedback_<ContainerAllocator>::FAILED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t HoleStructureFeedback_<ContainerAllocator>::CANCELLED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_FEEDBACK__STRUCT_HPP_
