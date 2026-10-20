// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:srv/SaveHolePassageConfig.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/save_hole_passage_config.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__SAVE_HOLE_PASSAGE_CONFIG__BUILDER_HPP_
#define NAV_INTERFACES__SRV__DETAIL__SAVE_HOLE_PASSAGE_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/srv/detail/save_hole_passage_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_SaveHolePassageConfig_Request_expected_terrain_revision
{
public:
  explicit Init_SaveHolePassageConfig_Request_expected_terrain_revision(::nav_interfaces::srv::SaveHolePassageConfig_Request & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::SaveHolePassageConfig_Request expected_terrain_revision(::nav_interfaces::srv::SaveHolePassageConfig_Request::_expected_terrain_revision_type arg)
  {
    msg_.expected_terrain_revision = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Request msg_;
};

class Init_SaveHolePassageConfig_Request_expected_config_revision
{
public:
  Init_SaveHolePassageConfig_Request_expected_config_revision()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveHolePassageConfig_Request_expected_terrain_revision expected_config_revision(::nav_interfaces::srv::SaveHolePassageConfig_Request::_expected_config_revision_type arg)
  {
    msg_.expected_config_revision = std::move(arg);
    return Init_SaveHolePassageConfig_Request_expected_terrain_revision(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::SaveHolePassageConfig_Request>()
{
  return nav_interfaces::srv::builder::Init_SaveHolePassageConfig_Request_expected_config_revision();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_SaveHolePassageConfig_Response_config_revision
{
public:
  explicit Init_SaveHolePassageConfig_Response_config_revision(::nav_interfaces::srv::SaveHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::SaveHolePassageConfig_Response config_revision(::nav_interfaces::srv::SaveHolePassageConfig_Response::_config_revision_type arg)
  {
    msg_.config_revision = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Response msg_;
};

class Init_SaveHolePassageConfig_Response_config_path
{
public:
  explicit Init_SaveHolePassageConfig_Response_config_path(::nav_interfaces::srv::SaveHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_SaveHolePassageConfig_Response_config_revision config_path(::nav_interfaces::srv::SaveHolePassageConfig_Response::_config_path_type arg)
  {
    msg_.config_path = std::move(arg);
    return Init_SaveHolePassageConfig_Response_config_revision(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Response msg_;
};

class Init_SaveHolePassageConfig_Response_reason
{
public:
  explicit Init_SaveHolePassageConfig_Response_reason(::nav_interfaces::srv::SaveHolePassageConfig_Response & msg)
  : msg_(msg)
  {}
  Init_SaveHolePassageConfig_Response_config_path reason(::nav_interfaces::srv::SaveHolePassageConfig_Response::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_SaveHolePassageConfig_Response_config_path(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Response msg_;
};

class Init_SaveHolePassageConfig_Response_success
{
public:
  Init_SaveHolePassageConfig_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveHolePassageConfig_Response_reason success(::nav_interfaces::srv::SaveHolePassageConfig_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SaveHolePassageConfig_Response_reason(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::SaveHolePassageConfig_Response>()
{
  return nav_interfaces::srv::builder::Init_SaveHolePassageConfig_Response_success();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_SaveHolePassageConfig_Event_response
{
public:
  explicit Init_SaveHolePassageConfig_Event_response(::nav_interfaces::srv::SaveHolePassageConfig_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::SaveHolePassageConfig_Event response(::nav_interfaces::srv::SaveHolePassageConfig_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Event msg_;
};

class Init_SaveHolePassageConfig_Event_request
{
public:
  explicit Init_SaveHolePassageConfig_Event_request(::nav_interfaces::srv::SaveHolePassageConfig_Event & msg)
  : msg_(msg)
  {}
  Init_SaveHolePassageConfig_Event_response request(::nav_interfaces::srv::SaveHolePassageConfig_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SaveHolePassageConfig_Event_response(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Event msg_;
};

class Init_SaveHolePassageConfig_Event_info
{
public:
  Init_SaveHolePassageConfig_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveHolePassageConfig_Event_request info(::nav_interfaces::srv::SaveHolePassageConfig_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SaveHolePassageConfig_Event_request(msg_);
  }

private:
  ::nav_interfaces::srv::SaveHolePassageConfig_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::SaveHolePassageConfig_Event>()
{
  return nav_interfaces::srv::builder::Init_SaveHolePassageConfig_Event_info();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__SRV__DETAIL__SAVE_HOLE_PASSAGE_CONFIG__BUILDER_HPP_
