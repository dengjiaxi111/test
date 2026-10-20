// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_interfaces:action/Navigate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/action/navigate.hpp"


#ifndef NAV_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_
#define NAV_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nav_interfaces/action/detail/navigate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Goal_goal_pose
{
public:
  Init_Navigate_Goal_goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::nav_interfaces::action::Navigate_Goal goal_pose(::nav_interfaces::action::Navigate_Goal::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_Goal>()
{
  return nav_interfaces::action::builder::Init_Navigate_Goal_goal_pose();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Result_total_time
{
public:
  explicit Init_Navigate_Result_total_time(::nav_interfaces::action::Navigate_Result & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_Result total_time(::nav_interfaces::action::Navigate_Result::_total_time_type arg)
  {
    msg_.total_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Result msg_;
};

class Init_Navigate_Result_message
{
public:
  explicit Init_Navigate_Result_message(::nav_interfaces::action::Navigate_Result & msg)
  : msg_(msg)
  {}
  Init_Navigate_Result_total_time message(::nav_interfaces::action::Navigate_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_Navigate_Result_total_time(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Result msg_;
};

class Init_Navigate_Result_success
{
public:
  Init_Navigate_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Result_message success(::nav_interfaces::action::Navigate_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Navigate_Result_message(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_Result>()
{
  return nav_interfaces::action::builder::Init_Navigate_Result_success();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Feedback_recovery_count
{
public:
  explicit Init_Navigate_Feedback_recovery_count(::nav_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_Feedback recovery_count(::nav_interfaces::action::Navigate_Feedback::_recovery_count_type arg)
  {
    msg_.recovery_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_state
{
public:
  explicit Init_Navigate_Feedback_state(::nav_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  Init_Navigate_Feedback_recovery_count state(::nav_interfaces::action::Navigate_Feedback::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_Navigate_Feedback_recovery_count(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_distance_remaining
{
public:
  explicit Init_Navigate_Feedback_distance_remaining(::nav_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  Init_Navigate_Feedback_state distance_remaining(::nav_interfaces::action::Navigate_Feedback::_distance_remaining_type arg)
  {
    msg_.distance_remaining = std::move(arg);
    return Init_Navigate_Feedback_state(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_current_pose
{
public:
  Init_Navigate_Feedback_current_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Feedback_distance_remaining current_pose(::nav_interfaces::action::Navigate_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_Navigate_Feedback_distance_remaining(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_Feedback>()
{
  return nav_interfaces::action::builder::Init_Navigate_Feedback_current_pose();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Request_goal
{
public:
  explicit Init_Navigate_SendGoal_Request_goal(::nav_interfaces::action::Navigate_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_SendGoal_Request goal(::nav_interfaces::action::Navigate_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Request msg_;
};

class Init_Navigate_SendGoal_Request_goal_id
{
public:
  Init_Navigate_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Request_goal goal_id(::nav_interfaces::action::Navigate_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Navigate_SendGoal_Request_goal(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_SendGoal_Request>()
{
  return nav_interfaces::action::builder::Init_Navigate_SendGoal_Request_goal_id();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Response_stamp
{
public:
  explicit Init_Navigate_SendGoal_Response_stamp(::nav_interfaces::action::Navigate_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_SendGoal_Response stamp(::nav_interfaces::action::Navigate_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Response msg_;
};

class Init_Navigate_SendGoal_Response_accepted
{
public:
  Init_Navigate_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Response_stamp accepted(::nav_interfaces::action::Navigate_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Navigate_SendGoal_Response_stamp(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_SendGoal_Response>()
{
  return nav_interfaces::action::builder::Init_Navigate_SendGoal_Response_accepted();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Event_response
{
public:
  explicit Init_Navigate_SendGoal_Event_response(::nav_interfaces::action::Navigate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_SendGoal_Event response(::nav_interfaces::action::Navigate_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Event msg_;
};

class Init_Navigate_SendGoal_Event_request
{
public:
  explicit Init_Navigate_SendGoal_Event_request(::nav_interfaces::action::Navigate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Navigate_SendGoal_Event_response request(::nav_interfaces::action::Navigate_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Navigate_SendGoal_Event_response(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Event msg_;
};

class Init_Navigate_SendGoal_Event_info
{
public:
  Init_Navigate_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Event_request info(::nav_interfaces::action::Navigate_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Navigate_SendGoal_Event_request(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_SendGoal_Event>()
{
  return nav_interfaces::action::builder::Init_Navigate_SendGoal_Event_info();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Request_goal_id
{
public:
  Init_Navigate_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::nav_interfaces::action::Navigate_GetResult_Request goal_id(::nav_interfaces::action::Navigate_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_GetResult_Request>()
{
  return nav_interfaces::action::builder::Init_Navigate_GetResult_Request_goal_id();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Response_result
{
public:
  explicit Init_Navigate_GetResult_Response_result(::nav_interfaces::action::Navigate_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_GetResult_Response result(::nav_interfaces::action::Navigate_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_GetResult_Response msg_;
};

class Init_Navigate_GetResult_Response_status
{
public:
  Init_Navigate_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_GetResult_Response_result status(::nav_interfaces::action::Navigate_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Navigate_GetResult_Response_result(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_GetResult_Response>()
{
  return nav_interfaces::action::builder::Init_Navigate_GetResult_Response_status();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Event_response
{
public:
  explicit Init_Navigate_GetResult_Event_response(::nav_interfaces::action::Navigate_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_GetResult_Event response(::nav_interfaces::action::Navigate_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_GetResult_Event msg_;
};

class Init_Navigate_GetResult_Event_request
{
public:
  explicit Init_Navigate_GetResult_Event_request(::nav_interfaces::action::Navigate_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Navigate_GetResult_Event_response request(::nav_interfaces::action::Navigate_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Navigate_GetResult_Event_response(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_GetResult_Event msg_;
};

class Init_Navigate_GetResult_Event_info
{
public:
  Init_Navigate_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_GetResult_Event_request info(::nav_interfaces::action::Navigate_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Navigate_GetResult_Event_request(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_GetResult_Event>()
{
  return nav_interfaces::action::builder::Init_Navigate_GetResult_Event_info();
}

}  // namespace nav_interfaces


namespace nav_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_FeedbackMessage_feedback
{
public:
  explicit Init_Navigate_FeedbackMessage_feedback(::nav_interfaces::action::Navigate_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::nav_interfaces::action::Navigate_FeedbackMessage feedback(::nav_interfaces::action::Navigate_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_FeedbackMessage msg_;
};

class Init_Navigate_FeedbackMessage_goal_id
{
public:
  Init_Navigate_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_FeedbackMessage_feedback goal_id(::nav_interfaces::action::Navigate_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Navigate_FeedbackMessage_feedback(msg_);
  }

private:
  ::nav_interfaces::action::Navigate_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_interfaces::action::Navigate_FeedbackMessage>()
{
  return nav_interfaces::action::builder::Init_Navigate_FeedbackMessage_goal_id();
}

}  // namespace nav_interfaces

#endif  // NAV_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_
