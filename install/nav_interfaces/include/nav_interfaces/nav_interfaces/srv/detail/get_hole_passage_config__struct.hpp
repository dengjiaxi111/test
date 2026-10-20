// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_interfaces:srv/GetHolePassageConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/get_hole_passage_config.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__STRUCT_HPP_
#define NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Request __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Request __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetHolePassageConfig_Request_
{
  using Type = GetHolePassageConfig_Request_<ContainerAllocator>;

  explicit GetHolePassageConfig_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetHolePassageConfig_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Request
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Request
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetHolePassageConfig_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetHolePassageConfig_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetHolePassageConfig_Request_

// alias to use template instance with default allocator
using GetHolePassageConfig_Request =
  nav_interfaces::srv::GetHolePassageConfig_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nav_interfaces


#ifndef _WIN32
# define DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Response __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Response __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetHolePassageConfig_Response_
{
  using Type = GetHolePassageConfig_Response_<ContainerAllocator>;

  explicit GetHolePassageConfig_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->manual_config_active = false;
      this->reason = "";
      this->config_yaml = "";
      this->config_path = "";
      this->terrain_path = "";
      this->terrain_geometry = "";
      this->config_revision = 0ull;
      this->terrain_revision = 0ull;
    }
  }

  explicit GetHolePassageConfig_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reason(_alloc),
    config_yaml(_alloc),
    config_path(_alloc),
    terrain_path(_alloc),
    terrain_geometry(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->manual_config_active = false;
      this->reason = "";
      this->config_yaml = "";
      this->config_path = "";
      this->terrain_path = "";
      this->terrain_geometry = "";
      this->config_revision = 0ull;
      this->terrain_revision = 0ull;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _manual_config_active_type =
    bool;
  _manual_config_active_type manual_config_active;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;
  using _config_yaml_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _config_yaml_type config_yaml;
  using _config_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _config_path_type config_path;
  using _terrain_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _terrain_path_type terrain_path;
  using _terrain_geometry_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _terrain_geometry_type terrain_geometry;
  using _config_revision_type =
    uint64_t;
  _config_revision_type config_revision;
  using _terrain_revision_type =
    uint64_t;
  _terrain_revision_type terrain_revision;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__manual_config_active(
    const bool & _arg)
  {
    this->manual_config_active = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }
  Type & set__config_yaml(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->config_yaml = _arg;
    return *this;
  }
  Type & set__config_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->config_path = _arg;
    return *this;
  }
  Type & set__terrain_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->terrain_path = _arg;
    return *this;
  }
  Type & set__terrain_geometry(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->terrain_geometry = _arg;
    return *this;
  }
  Type & set__config_revision(
    const uint64_t & _arg)
  {
    this->config_revision = _arg;
    return *this;
  }
  Type & set__terrain_revision(
    const uint64_t & _arg)
  {
    this->terrain_revision = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Response
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Response
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetHolePassageConfig_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->manual_config_active != other.manual_config_active) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->config_yaml != other.config_yaml) {
      return false;
    }
    if (this->config_path != other.config_path) {
      return false;
    }
    if (this->terrain_path != other.terrain_path) {
      return false;
    }
    if (this->terrain_geometry != other.terrain_geometry) {
      return false;
    }
    if (this->config_revision != other.config_revision) {
      return false;
    }
    if (this->terrain_revision != other.terrain_revision) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetHolePassageConfig_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetHolePassageConfig_Response_

// alias to use template instance with default allocator
using GetHolePassageConfig_Response =
  nav_interfaces::srv::GetHolePassageConfig_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nav_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Event __attribute__((deprecated))
#else
# define DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Event __declspec(deprecated)
#endif

namespace nav_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetHolePassageConfig_Event_
{
  using Type = GetHolePassageConfig_Event_<ContainerAllocator>;

  explicit GetHolePassageConfig_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetHolePassageConfig_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::srv::GetHolePassageConfig_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nav_interfaces::srv::GetHolePassageConfig_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Event
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_interfaces__srv__GetHolePassageConfig_Event
    std::shared_ptr<nav_interfaces::srv::GetHolePassageConfig_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetHolePassageConfig_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetHolePassageConfig_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetHolePassageConfig_Event_

// alias to use template instance with default allocator
using GetHolePassageConfig_Event =
  nav_interfaces::srv::GetHolePassageConfig_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nav_interfaces

namespace nav_interfaces
{

namespace srv
{

struct GetHolePassageConfig
{
  using Request = nav_interfaces::srv::GetHolePassageConfig_Request;
  using Response = nav_interfaces::srv::GetHolePassageConfig_Response;
  using Event = nav_interfaces::srv::GetHolePassageConfig_Event;
};

}  // namespace srv

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__STRUCT_HPP_
