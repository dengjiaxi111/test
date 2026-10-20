// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:srv/ReloadTerrain.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/reload_terrain.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__RELOAD_TERRAIN__BUILDER_HPP_
#define NAV_INTERFACES__SRV__DETAIL__RELOAD_TERRAIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/srv/detail/reload_terrain__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_ReloadTerrain_Request_expected_path
{
public:
  Init_ReloadTerrain_Request_expected_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::nav_interfaces::srv::ReloadTerrain_Request expected_path(::nav_interfaces::srv::ReloadTerrain_Request::_expected_path_type arg)
  {
    msg_.expected_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::ReloadTerrain_Request>()
{
  return nav_interfaces::srv::builder::Init_ReloadTerrain_Request_expected_path();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_ReloadTerrain_Response_replanning_triggered
{
public:
  explicit Init_ReloadTerrain_Response_replanning_triggered(::nav_interfaces::srv::ReloadTerrain_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::ReloadTerrain_Response replanning_triggered(::nav_interfaces::srv::ReloadTerrain_Response::_replanning_triggered_type arg)
  {
    msg_.replanning_triggered = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Response msg_;
};

class Init_ReloadTerrain_Response_terrain_revision
{
public:
  explicit Init_ReloadTerrain_Response_terrain_revision(::nav_interfaces::srv::ReloadTerrain_Response & msg)
  : msg_(msg)
  {}
  Init_ReloadTerrain_Response_replanning_triggered terrain_revision(::nav_interfaces::srv::ReloadTerrain_Response::_terrain_revision_type arg)
  {
    msg_.terrain_revision = std::move(arg);
    return Init_ReloadTerrain_Response_replanning_triggered(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Response msg_;
};

class Init_ReloadTerrain_Response_terrain_path
{
public:
  explicit Init_ReloadTerrain_Response_terrain_path(::nav_interfaces::srv::ReloadTerrain_Response & msg)
  : msg_(msg)
  {}
  Init_ReloadTerrain_Response_terrain_revision terrain_path(::nav_interfaces::srv::ReloadTerrain_Response::_terrain_path_type arg)
  {
    msg_.terrain_path = std::move(arg);
    return Init_ReloadTerrain_Response_terrain_revision(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Response msg_;
};

class Init_ReloadTerrain_Response_reason
{
public:
  explicit Init_ReloadTerrain_Response_reason(::nav_interfaces::srv::ReloadTerrain_Response & msg)
  : msg_(msg)
  {}
  Init_ReloadTerrain_Response_terrain_path reason(::nav_interfaces::srv::ReloadTerrain_Response::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_ReloadTerrain_Response_terrain_path(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Response msg_;
};

class Init_ReloadTerrain_Response_success
{
public:
  Init_ReloadTerrain_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReloadTerrain_Response_reason success(::nav_interfaces::srv::ReloadTerrain_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ReloadTerrain_Response_reason(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::ReloadTerrain_Response>()
{
  return nav_interfaces::srv::builder::Init_ReloadTerrain_Response_success();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_ReloadTerrain_Event_response
{
public:
  explicit Init_ReloadTerrain_Event_response(::nav_interfaces::srv::ReloadTerrain_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::ReloadTerrain_Event response(::nav_interfaces::srv::ReloadTerrain_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Event msg_;
};

class Init_ReloadTerrain_Event_request
{
public:
  explicit Init_ReloadTerrain_Event_request(::nav_interfaces::srv::ReloadTerrain_Event & msg)
  : msg_(msg)
  {}
  Init_ReloadTerrain_Event_response request(::nav_interfaces::srv::ReloadTerrain_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ReloadTerrain_Event_response(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Event msg_;
};

class Init_ReloadTerrain_Event_info
{
public:
  Init_ReloadTerrain_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReloadTerrain_Event_request info(::nav_interfaces::srv::ReloadTerrain_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ReloadTerrain_Event_request(msg_);
  }

private:
  ::nav_interfaces::srv::ReloadTerrain_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::ReloadTerrain_Event>()
{
  return nav_interfaces::srv::builder::Init_ReloadTerrain_Event_info();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__SRV__DETAIL__RELOAD_TERRAIN__BUILDER_HPP_
