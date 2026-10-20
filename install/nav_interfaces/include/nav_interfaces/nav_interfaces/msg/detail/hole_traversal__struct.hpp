// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal.hpp"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__STRUCT_HPP_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'events'
#include "nav_interfaces/msg/detail/hole_event__struct.hpp"
// Member 'straight_segments'
#include "nav_interfaces/msg/detail/hole_straight__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_interfaces__msg__HoleTraversal __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__msg__HoleTraversal __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HoleTraversal_
{
  using Type = HoleTraversal_<ContainerAllocator>;

  explicit HoleTraversal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->traversal_uid = "";
      this->hole_id = "";
      this->entry_edge_id = 0l;
      this->exit_edge_id = 0l;
      this->centerline = false;
      this->validated = false;
      this->requirement_revision = 0ull;
      this->events.fill(nav_interfaces::msg::HoleEvent_<ContainerAllocator>{_init});
      this->uphill_entry = false;
    }
  }

  explicit HoleTraversal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : traversal_uid(_alloc),
    hole_id(_alloc),
    events(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->traversal_uid = "";
      this->hole_id = "";
      this->entry_edge_id = 0l;
      this->exit_edge_id = 0l;
      this->centerline = false;
      this->validated = false;
      this->requirement_revision = 0ull;
      this->events.fill(nav_interfaces::msg::HoleEvent_<ContainerAllocator>{_alloc, _init});
      this->uphill_entry = false;
    }
  }

  // field types and members
  using _traversal_uid_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _traversal_uid_type traversal_uid;
  using _hole_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _hole_id_type hole_id;
  using _entry_edge_id_type =
    int32_t;
  _entry_edge_id_type entry_edge_id;
  using _exit_edge_id_type =
    int32_t;
  _exit_edge_id_type exit_edge_id;
  using _centerline_type =
    bool;
  _centerline_type centerline;
  using _validated_type =
    bool;
  _validated_type validated;
  using _requirement_revision_type =
    uint64_t;
  _requirement_revision_type requirement_revision;
  using _events_type =
    std::array<nav_interfaces::msg::HoleEvent_<ContainerAllocator>, 6>;
  _events_type events;
  using _straight_segments_type =
    std::vector<nav_interfaces::msg::HoleStraight_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::msg::HoleStraight_<ContainerAllocator>>>;
  _straight_segments_type straight_segments;
  using _uphill_entry_type =
    bool;
  _uphill_entry_type uphill_entry;

  // setters for named parameter idiom
  Type & set__traversal_uid(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->traversal_uid = _arg;
    return *this;
  }
  Type & set__hole_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->hole_id = _arg;
    return *this;
  }
  Type & set__entry_edge_id(
    const int32_t & _arg)
  {
    this->entry_edge_id = _arg;
    return *this;
  }
  Type & set__exit_edge_id(
    const int32_t & _arg)
  {
    this->exit_edge_id = _arg;
    return *this;
  }
  Type & set__centerline(
    const bool & _arg)
  {
    this->centerline = _arg;
    return *this;
  }
  Type & set__validated(
    const bool & _arg)
  {
    this->validated = _arg;
    return *this;
  }
  Type & set__requirement_revision(
    const uint64_t & _arg)
  {
    this->requirement_revision = _arg;
    return *this;
  }
  Type & set__events(
    const std::array<nav_interfaces::msg::HoleEvent_<ContainerAllocator>, 6> & _arg)
  {
    this->events = _arg;
    return *this;
  }
  Type & set__straight_segments(
    const std::vector<nav_interfaces::msg::HoleStraight_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::msg::HoleStraight_<ContainerAllocator>>> & _arg)
  {
    this->straight_segments = _arg;
    return *this;
  }
  Type & set__uphill_entry(
    const bool & _arg)
  {
    this->uphill_entry = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::msg::HoleTraversal_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::msg::HoleTraversal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__msg__HoleTraversal
    std::shared_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__msg__HoleTraversal
    std::shared_ptr<nav_interfaces::msg::HoleTraversal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HoleTraversal_ & other) const
  {
    if (this->traversal_uid != other.traversal_uid) {
      return false;
    }
    if (this->hole_id != other.hole_id) {
      return false;
    }
    if (this->entry_edge_id != other.entry_edge_id) {
      return false;
    }
    if (this->exit_edge_id != other.exit_edge_id) {
      return false;
    }
    if (this->centerline != other.centerline) {
      return false;
    }
    if (this->validated != other.validated) {
      return false;
    }
    if (this->requirement_revision != other.requirement_revision) {
      return false;
    }
    if (this->events != other.events) {
      return false;
    }
    if (this->straight_segments != other.straight_segments) {
      return false;
    }
    if (this->uphill_entry != other.uphill_entry) {
      return false;
    }
    return true;
  }
  bool operator!=(const HoleTraversal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HoleTraversal_

// alias to use template instance with default allocator
using HoleTraversal =
  nav_interfaces::msg::HoleTraversal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__STRUCT_HPP_
