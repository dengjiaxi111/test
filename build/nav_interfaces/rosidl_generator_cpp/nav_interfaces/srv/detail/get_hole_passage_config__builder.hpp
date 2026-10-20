// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:srv/GetHolePassageConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/get_hole_passage_config.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__BUILDER_HPP_
#define NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/srv/detail/get_hole_passage_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::GetHolePassageConfig_Request>()
{
  return ::nav_interfaces::srv::GetHolePassageConfig_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetHolePassageConfig_Response_terrain_revision
{
public:
  explicit Init_GetHolePassageConfig_Response_terrain_revision(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::GetHolePassageConfig_Response terrain_revision(::nav_interfaces::srv::GetHolePassageConfig_Response::_terrain_revision_type arg)
  {
    msg_.terrain_revision = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_config_revision
{
public:
  explicit Init_GetHolePassageConfig_Response_config_revision(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_terrain_revision config_revision(::nav_interfaces::srv::GetHolePassageConfig_Response::_config_revision_type arg)
  {
    msg_.config_revision = std::move(arg);
    return Init_GetHolePassageConfig_Response_terrain_revision(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_terrain_geometry
{
public:
  explicit Init_GetHolePassageConfig_Response_terrain_geometry(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_config_revision terrain_geometry(::nav_interfaces::srv::GetHolePassageConfig_Response::_terrain_geometry_type arg)
  {
    msg_.terrain_geometry = std::move(arg);
    return Init_GetHolePassageConfig_Response_config_revision(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_terrain_path
{
public:
  explicit Init_GetHolePassageConfig_Response_terrain_path(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_terrain_geometry terrain_path(::nav_interfaces::srv::GetHolePassageConfig_Response::_terrain_path_type arg)
  {
    msg_.terrain_path = std::move(arg);
    return Init_GetHolePassageConfig_Response_terrain_geometry(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_config_path
{
public:
  explicit Init_GetHolePassageConfig_Response_config_path(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_terrain_path config_path(::nav_interfaces::srv::GetHolePassageConfig_Response::_config_path_type arg)
  {
    msg_.config_path = std::move(arg);
    return Init_GetHolePassageConfig_Response_terrain_path(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_config_yaml
{
public:
  explicit Init_GetHolePassageConfig_Response_config_yaml(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_config_path config_yaml(::nav_interfaces::srv::GetHolePassageConfig_Response::_config_yaml_type arg)
  {
    msg_.config_yaml = std::move(arg);
    return Init_GetHolePassageConfig_Response_config_path(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_reason
{
public:
  explicit Init_GetHolePassageConfig_Response_reason(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_config_yaml reason(::nav_interfaces::srv::GetHolePassageConfig_Response::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_GetHolePassageConfig_Response_config_yaml(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_manual_config_active
{
public:
  explicit Init_GetHolePassageConfig_Response_manual_config_active(::nav_interfaces::srv::GetHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Response_reason manual_config_active(::nav_interfaces::srv::GetHolePassageConfig_Response::_manual_config_active_type arg)
  {
    msg_.manual_config_active = std::move(arg);
    return Init_GetHolePassageConfig_Response_reason(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

class Init_GetHolePassageConfig_Response_success
{
public:
  Init_GetHolePassageConfig_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetHolePassageConfig_Response_manual_config_active success(::nav_interfaces::srv::GetHolePassageConfig_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetHolePassageConfig_Response_manual_config_active(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::GetHolePassageConfig_Response>()
{
  return nav_interfaces::srv::builder::Init_GetHolePassageConfig_Response_success();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetHolePassageConfig_Event_response
{
public:
  explicit Init_GetHolePassageConfig_Event_response(::nav_interfaces::srv::GetHolePassageConfig_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::GetHolePassageConfig_Event response(::nav_interfaces::srv::GetHolePassageConfig_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Event msg_;
};

class Init_GetHolePassageConfig_Event_request
{
public:
  explicit Init_GetHolePassageConfig_Event_request(::nav_interfaces::srv::GetHolePassageConfig_Event & msg)
  : msg_(msg)
  {}
  Init_GetHolePassageConfig_Event_response request(::nav_interfaces::srv::GetHolePassageConfig_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetHolePassageConfig_Event_response(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Event msg_;
};

class Init_GetHolePassageConfig_Event_info
{
public:
  Init_GetHolePassageConfig_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetHolePassageConfig_Event_request info(::nav_interfaces::srv::GetHolePassageConfig_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetHolePassageConfig_Event_request(msg_);
  }

private:
  ::nav_interfaces::srv::GetHolePassageConfig_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::GetHolePassageConfig_Event>()
{
  return nav_interfaces::srv::builder::Init_GetHolePassageConfig_Event_info();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__SRV__DETAIL__GET_HOLE_PASSAGE_CONFIG__BUILDER_HPP_
