// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:srv/ApplyTemporaryMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/srv/apply_temporary_map.hpp"


#ifndef NAV_INTERFACES__SRV__DETAIL__APPLY_TEMPORARY_MAP__BUILDER_HPP_
#define NAV_INTERFACES__SRV__DETAIL__APPLY_TEMPORARY_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/srv/detail/apply_temporary_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_ApplyTemporaryMap_Request_values
{
public:
  explicit Init_ApplyTemporaryMap_Request_values(::nav_interfaces::srv::ApplyTemporaryMap_Request & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::ApplyTemporaryMap_Request values(::nav_interfaces::srv::ApplyTemporaryMap_Request::_values_type arg)
  {
    msg_.values = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Request msg_;
};

class Init_ApplyTemporaryMap_Request_indices
{
public:
  explicit Init_ApplyTemporaryMap_Request_indices(::nav_interfaces::srv::ApplyTemporaryMap_Request & msg)
  : msg_(msg)
  {}
  Init_ApplyTemporaryMap_Request_values indices(::nav_interfaces::srv::ApplyTemporaryMap_Request::_indices_type arg)
  {
    msg_.indices = std::move(arg);
    return Init_ApplyTemporaryMap_Request_values(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Request msg_;
};

class Init_ApplyTemporaryMap_Request_expected_map_revision
{
public:
  explicit Init_ApplyTemporaryMap_Request_expected_map_revision(::nav_interfaces::srv::ApplyTemporaryMap_Request & msg)
  : msg_(msg)
  {}
  Init_ApplyTemporaryMap_Request_indices expected_map_revision(::nav_interfaces::srv::ApplyTemporaryMap_Request::_expected_map_revision_type arg)
  {
    msg_.expected_map_revision = std::move(arg);
    return Init_ApplyTemporaryMap_Request_indices(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Request msg_;
};

class Init_ApplyTemporaryMap_Request_expected_source_id
{
public:
  explicit Init_ApplyTemporaryMap_Request_expected_source_id(::nav_interfaces::srv::ApplyTemporaryMap_Request & msg)
  : msg_(msg)
  {}
  Init_ApplyTemporaryMap_Request_expected_map_revision expected_source_id(::nav_interfaces::srv::ApplyTemporaryMap_Request::_expected_source_id_type arg)
  {
    msg_.expected_source_id = std::move(arg);
    return Init_ApplyTemporaryMap_Request_expected_map_revision(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Request msg_;
};

class Init_ApplyTemporaryMap_Request_expected_session_id
{
public:
  Init_ApplyTemporaryMap_Request_expected_session_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ApplyTemporaryMap_Request_expected_source_id expected_session_id(::nav_interfaces::srv::ApplyTemporaryMap_Request::_expected_session_id_type arg)
  {
    msg_.expected_session_id = std::move(arg);
    return Init_ApplyTemporaryMap_Request_expected_source_id(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::ApplyTemporaryMap_Request>()
{
  return nav_interfaces::srv::builder::Init_ApplyTemporaryMap_Request_expected_session_id();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_ApplyTemporaryMap_Response_replanning_triggered
{
public:
  explicit Init_ApplyTemporaryMap_Response_replanning_triggered(::nav_interfaces::srv::ApplyTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::ApplyTemporaryMap_Response replanning_triggered(::nav_interfaces::srv::ApplyTemporaryMap_Response::_replanning_triggered_type arg)
  {
    msg_.replanning_triggered = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Response msg_;
};

class Init_ApplyTemporaryMap_Response_map_revision
{
public:
  explicit Init_ApplyTemporaryMap_Response_map_revision(::nav_interfaces::srv::ApplyTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_ApplyTemporaryMap_Response_replanning_triggered map_revision(::nav_interfaces::srv::ApplyTemporaryMap_Response::_map_revision_type arg)
  {
    msg_.map_revision = std::move(arg);
    return Init_ApplyTemporaryMap_Response_replanning_triggered(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Response msg_;
};

class Init_ApplyTemporaryMap_Response_reason
{
public:
  explicit Init_ApplyTemporaryMap_Response_reason(::nav_interfaces::srv::ApplyTemporaryMap_Response & msg)
  : msg_(msg)
  {}
  Init_ApplyTemporaryMap_Response_map_revision reason(::nav_interfaces::srv::ApplyTemporaryMap_Response::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_ApplyTemporaryMap_Response_map_revision(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Response msg_;
};

class Init_ApplyTemporaryMap_Response_success
{
public:
  Init_ApplyTemporaryMap_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ApplyTemporaryMap_Response_reason success(::nav_interfaces::srv::ApplyTemporaryMap_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ApplyTemporaryMap_Response_reason(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::ApplyTemporaryMap_Response>()
{
  return nav_interfaces::srv::builder::Init_ApplyTemporaryMap_Response_success();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace srv
{

namespace builder
{

class Init_ApplyTemporaryMap_Event_response
{
public:
  explicit Init_ApplyTemporaryMap_Event_response(::nav_interfaces::srv::ApplyTemporaryMap_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::srv::ApplyTemporaryMap_Event response(::nav_interfaces::srv::ApplyTemporaryMap_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Event msg_;
};

class Init_ApplyTemporaryMap_Event_request
{
public:
  explicit Init_ApplyTemporaryMap_Event_request(::nav_interfaces::srv::ApplyTemporaryMap_Event & msg)
  : msg_(msg)
  {}
  Init_ApplyTemporaryMap_Event_response request(::nav_interfaces::srv::ApplyTemporaryMap_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ApplyTemporaryMap_Event_response(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Event msg_;
};

class Init_ApplyTemporaryMap_Event_info
{
public:
  Init_ApplyTemporaryMap_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ApplyTemporaryMap_Event_request info(::nav_interfaces::srv::ApplyTemporaryMap_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ApplyTemporaryMap_Event_request(msg_);
  }

private:
  ::nav_interfaces::srv::ApplyTemporaryMap_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::srv::ApplyTemporaryMap_Event>()
{
  return nav_interfaces::srv::builder::Init_ApplyTemporaryMap_Event_info();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__SRV__DETAIL__APPLY_TEMPORARY_MAP__BUILDER_HPP_
