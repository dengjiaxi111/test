// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:srv/GetTemporaryMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/get_temporary_map.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__GET_TEMPORARY_MAP__BUILDER_HPP_
#define NAV_INTERFACES__SRV__DETAIL__GET_TEMPORARY_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/srv/detail/get_temporary_map__struct.hpp"
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
auto build<::nav_interfaces::srv::GetTemporaryMap_Request>()
{
  return ::nav_interfaces::srv::GetTemporaryMap_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTemporaryMap_Response_values
{
public:
  explicit Init_GetTemporaryMap_Response_values(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::GetTemporaryMap_Response values(::nav_interfaces::srv::GetTemporaryMap_Response::_values_type arg)
  {
    msg_.values = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_indices
{
public:
  explicit Init_GetTemporaryMap_Response_indices(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_values indices(::nav_interfaces::srv::GetTemporaryMap_Response::_indices_type arg)
  {
    msg_.indices = std::move(arg);
    return Init_GetTemporaryMap_Response_values(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_source_map
{
public:
  explicit Init_GetTemporaryMap_Response_source_map(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_indices source_map(::nav_interfaces::srv::GetTemporaryMap_Response::_source_map_type arg)
  {
    msg_.source_map = std::move(arg);
    return Init_GetTemporaryMap_Response_indices(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_map_revision
{
public:
  explicit Init_GetTemporaryMap_Response_map_revision(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_source_map map_revision(::nav_interfaces::srv::GetTemporaryMap_Response::_map_revision_type arg)
  {
    msg_.map_revision = std::move(arg);
    return Init_GetTemporaryMap_Response_source_map(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_source_id
{
public:
  explicit Init_GetTemporaryMap_Response_source_id(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_map_revision source_id(::nav_interfaces::srv::GetTemporaryMap_Response::_source_id_type arg)
  {
    msg_.source_id = std::move(arg);
    return Init_GetTemporaryMap_Response_map_revision(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_session_id
{
public:
  explicit Init_GetTemporaryMap_Response_session_id(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_source_id session_id(::nav_interfaces::srv::GetTemporaryMap_Response::_session_id_type arg)
  {
    msg_.session_id = std::move(arg);
    return Init_GetTemporaryMap_Response_source_id(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_map_path
{
public:
  explicit Init_GetTemporaryMap_Response_map_path(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_session_id map_path(::nav_interfaces::srv::GetTemporaryMap_Response::_map_path_type arg)
  {
    msg_.map_path = std::move(arg);
    return Init_GetTemporaryMap_Response_session_id(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_reason
{
public:
  explicit Init_GetTemporaryMap_Response_reason(::nav_interfaces::srv::GetTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Response_map_path reason(::nav_interfaces::srv::GetTemporaryMap_Response::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_GetTemporaryMap_Response_map_path(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

class Init_GetTemporaryMap_Response_success
{
public:
  Init_GetTemporaryMap_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTemporaryMap_Response_reason success(::nav_interfaces::srv::GetTemporaryMap_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetTemporaryMap_Response_reason(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::GetTemporaryMap_Response>()
{
  return nav_interfaces::srv::builder::Init_GetTemporaryMap_Response_success();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTemporaryMap_Event_response
{
public:
  explicit Init_GetTemporaryMap_Event_response(::nav_interfaces::srv::GetTemporaryMap_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::GetTemporaryMap_Event response(::nav_interfaces::srv::GetTemporaryMap_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Event msg_;
};

class Init_GetTemporaryMap_Event_request
{
public:
  explicit Init_GetTemporaryMap_Event_request(::nav_interfaces::srv::GetTemporaryMap_Event & msg)
  : msg_(msg)
  {}
  Init_GetTemporaryMap_Event_response request(::nav_interfaces::srv::GetTemporaryMap_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetTemporaryMap_Event_response(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Event msg_;
};

class Init_GetTemporaryMap_Event_info
{
public:
  Init_GetTemporaryMap_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTemporaryMap_Event_request info(::nav_interfaces::srv::GetTemporaryMap_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetTemporaryMap_Event_request(msg_);
  }

private:
  ::nav_interfaces::srv::GetTemporaryMap_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::GetTemporaryMap_Event>()
{
  return nav_interfaces::srv::builder::Init_GetTemporaryMap_Event_info();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__SRV__DETAIL__GET_TEMPORARY_MAP__BUILDER_HPP_
