// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/EnemyPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/enemy_pose.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/enemy_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_EnemyPose_enemy_y
{
public:
  explicit Init_EnemyPose_enemy_y(::robots_msgs::msg::EnemyPose & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::EnemyPose enemy_y(::robots_msgs::msg::EnemyPose::_enemy_y_type arg)
  {
    msg_.enemy_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::EnemyPose msg_;
};

class Init_EnemyPose_enemy_x
{
public:
  explicit Init_EnemyPose_enemy_x(::robots_msgs::msg::EnemyPose & msg)
  : msg_(msg)
  {}
  Init_EnemyPose_enemy_y enemy_x(::robots_msgs::msg::EnemyPose::_enemy_x_type arg)
  {
    msg_.enemy_x = std::move(arg);
    return Init_EnemyPose_enemy_y(msg_);
  }

private:
  ::robots_msgs::msg::EnemyPose msg_;
};

class Init_EnemyPose_enemy_num
{
public:
  explicit Init_EnemyPose_enemy_num(::robots_msgs::msg::EnemyPose & msg)
  : msg_(msg)
  {}
  Init_EnemyPose_enemy_x enemy_num(::robots_msgs::msg::EnemyPose::_enemy_num_type arg)
  {
    msg_.enemy_num = std::move(arg);
    return Init_EnemyPose_enemy_x(msg_);
  }

private:
  ::robots_msgs::msg::EnemyPose msg_;
};

class Init_EnemyPose_enemy_ori
{
public:
  explicit Init_EnemyPose_enemy_ori(::robots_msgs::msg::EnemyPose & msg)
  : msg_(msg)
  {}
  Init_EnemyPose_enemy_num enemy_ori(::robots_msgs::msg::EnemyPose::_enemy_ori_type arg)
  {
    msg_.enemy_ori = std::move(arg);
    return Init_EnemyPose_enemy_num(msg_);
  }

private:
  ::robots_msgs::msg::EnemyPose msg_;
};

class Init_EnemyPose_enemy_dist
{
public:
  Init_EnemyPose_enemy_dist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EnemyPose_enemy_ori enemy_dist(::robots_msgs::msg::EnemyPose::_enemy_dist_type arg)
  {
    msg_.enemy_dist = std::move(arg);
    return Init_EnemyPose_enemy_ori(msg_);
  }

private:
  ::robots_msgs::msg::EnemyPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::EnemyPose>()
{
  return robots_msgs::msg::builder::Init_EnemyPose_enemy_dist();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__ENEMY_POSE__BUILDER_HPP_
