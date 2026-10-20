// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/NavigationPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/navigation_plan.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__STRUCT_HPP_

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
// Member 'path'
#include "nav_msgs/msg/detail/path__struct.hpp"
// Member 'passages'
#include "nav_interfaces/msg/detail/hole_traversal__struct.hpp"
// Member 'speed_regions'
#include "nav_interfaces/msg/detail/hole_speed_region__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_interfaces__msg__NavigationPlan __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__NavigationPlan __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavigationPlan_
{
  using Type = NavigationPlan_<ContainerAllocator>;

  explicit NavigationPlan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    path(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->plan_id = 0ull;
      this->status = 0;
      this->reason = "";
      this->constraints_enabled = false;
      this->terrain_revision = 0ull;
      this->parameter_revision = 0ull;
      this->map_revision = 0ull;
      this->path_length = 0.0;
    }
  }

  explicit NavigationPlan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    session_id(_alloc),
    goal_id(_alloc),
    reason(_alloc),
    path(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->session_id = "";
      this->goal_id = "";
      this->plan_id = 0ull;
      this->status = 0;
      this->reason = "";
      this->constraints_enabled = false;
      this->terrain_revision = 0ull;
      this->parameter_revision = 0ull;
      this->map_revision = 0ull;
      this->path_length = 0.0;
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
  using _status_type =
    uint8_t;
  _status_type status;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;
  using _constraints_enabled_type =
    bool;
  _constraints_enabled_type constraints_enabled;
  using _terrain_revision_type =
    uint64_t;
  _terrain_revision_type terrain_revision;
  using _parameter_revision_type =
    uint64_t;
  _parameter_revision_type parameter_revision;
  using _map_revision_type =
    uint64_t;
  _map_revision_type map_revision;
  using _path_type =
    nav_msgs::msg::Path_<ContainerAllocator>;
  _path_type path;
  using _path_length_type =
    double;
  _path_length_type path_length;
  using _passages_type =
    std::vector<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>>;
  _passages_type passages;
  using _speed_regions_type =
    std::vector<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>>;
  _speed_regions_type speed_regions;

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
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }
  Type & set__constraints_enabled(
    const bool & _arg)
  {
    this->constraints_enabled = _arg;
    return *this;
  }
  Type & set__terrain_revision(
    const uint64_t & _arg)
  {
    this->terrain_revision = _arg;
    return *this;
  }
  Type & set__parameter_revision(
    const uint64_t & _arg)
  {
    this->parameter_revision = _arg;
    return *this;
  }
  Type & set__map_revision(
    const uint64_t & _arg)
  {
    this->map_revision = _arg;
    return *this;
  }
  Type & set__path(
    const nav_msgs::msg::Path_<ContainerAllocator> & _arg)
  {
    this->path = _arg;
    return *this;
  }
  Type & set__path_length(
    const double & _arg)
  {
    this->path_length = _arg;
    return *this;
  }
  Type & set__passages(
    const std::vector<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>> & _arg)
  {
    this->passages = _arg;
    return *this;
  }
  Type & set__speed_regions(
    const std::vector<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::msg::HoleSpeedRegion_<ContainerAllocator>>> & _arg)
  {
    this->speed_regions = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t ACTIVE =
    0u;
  static constexpr uint8_t INVALIDATED =
    1u;
  static constexpr uint8_t CANCELLED =
    2u;
  static constexpr uint8_t COMPLETED =
    3u;
  static constexpr uint8_t FAILED =
    4u;

  // pointer types
  using RawPtr =
    nav_interfaces::msg::NavigationPlan_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::NavigationPlan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::NavigationPlan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::NavigationPlan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__NavigationPlan
    std::shared_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__NavigationPlan
    std::shared_ptr<nav_interfaces::msg::NavigationPlan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigationPlan_ & other) const
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
    if (this->status != other.status) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->constraints_enabled != other.constraints_enabled) {
      return false;
    }
    if (this->terrain_revision != other.terrain_revision) {
      return false;
    }
    if (this->parameter_revision != other.parameter_revision) {
      return false;
    }
    if (this->map_revision != other.map_revision) {
      return false;
    }
    if (this->path != other.path) {
      return false;
    }
    if (this->path_length != other.path_length) {
      return false;
    }
    if (this->passages != other.passages) {
      return false;
    }
    if (this->speed_regions != other.speed_regions) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigationPlan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigationPlan_

// alias to use template instance with default allocator
using NavigationPlan =
  nav_interfaces::msg::NavigationPlan_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationPlan_<ContainerAllocator>::ACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationPlan_<ContainerAllocator>::INVALIDATED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationPlan_<ContainerAllocator>::CANCELLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationPlan_<ContainerAllocator>::COMPLETED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationPlan_<ContainerAllocator>::FAILED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__NAVIGATION_PLAN__STRUCT_HPP_
