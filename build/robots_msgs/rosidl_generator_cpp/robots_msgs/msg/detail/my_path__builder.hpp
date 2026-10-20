// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/MyPath.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/my_path.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__MY_PATH__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__MY_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/my_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_MyPath_sender_id
{
public:
  explicit Init_MyPath_sender_id(::robots_msgs::msg::MyPath & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::MyPath sender_id(::robots_msgs::msg::MyPath::_sender_id_type arg)
  {
    msg_.sender_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::MyPath msg_;
};

class Init_MyPath_delta_y
{
public:
  explicit Init_MyPath_delta_y(::robots_msgs::msg::MyPath & msg)
  : msg_(msg)
  {}
  Init_MyPath_sender_id delta_y(::robots_msgs::msg::MyPath::_delta_y_type arg)
  {
    msg_.delta_y = std::move(arg);
    return Init_MyPath_sender_id(msg_);
  }

private:
  ::robots_msgs::msg::MyPath msg_;
};

class Init_MyPath_delta_x
{
public:
  explicit Init_MyPath_delta_x(::robots_msgs::msg::MyPath & msg)
  : msg_(msg)
  {}
  Init_MyPath_delta_y delta_x(::robots_msgs::msg::MyPath::_delta_x_type arg)
  {
    msg_.delta_x = std::move(arg);
    return Init_MyPath_delta_y(msg_);
  }

private:
  ::robots_msgs::msg::MyPath msg_;
};

class Init_MyPath_start_y
{
public:
  explicit Init_MyPath_start_y(::robots_msgs::msg::MyPath & msg)
  : msg_(msg)
  {}
  Init_MyPath_delta_x start_y(::robots_msgs::msg::MyPath::_start_y_type arg)
  {
    msg_.start_y = std::move(arg);
    return Init_MyPath_delta_x(msg_);
  }

private:
  ::robots_msgs::msg::MyPath msg_;
};

class Init_MyPath_start_x
{
public:
  explicit Init_MyPath_start_x(::robots_msgs::msg::MyPath & msg)
  : msg_(msg)
  {}
  Init_MyPath_start_y start_x(::robots_msgs::msg::MyPath::_start_x_type arg)
  {
    msg_.start_x = std::move(arg);
    return Init_MyPath_start_y(msg_);
  }

private:
  ::robots_msgs::msg::MyPath msg_;
};

class Init_MyPath_intention
{
public:
  Init_MyPath_intention()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyPath_start_x intention(::robots_msgs::msg::MyPath::_intention_type arg)
  {
    msg_.intention = std::move(arg);
    return Init_MyPath_start_x(msg_);
  }

private:
  ::robots_msgs::msg::MyPath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::MyPath>()
{
  return robots_msgs::msg::builder::Init_MyPath_intention();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__MY_PATH__BUILDER_HPP_
