// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/game_status.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/game_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_GameStatus_remaining_gold_coin
{
public:
  explicit Init_GameStatus_remaining_gold_coin(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::GameStatus remaining_gold_coin(::robots_msgs::msg::GameStatus::_remaining_gold_coin_type arg)
  {
    msg_.remaining_gold_coin = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_our_fortress_status
{
public:
  explicit Init_GameStatus_our_fortress_status(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_remaining_gold_coin our_fortress_status(::robots_msgs::msg::GameStatus::_our_fortress_status_type arg)
  {
    msg_.our_fortress_status = std::move(arg);
    return Init_GameStatus_remaining_gold_coin(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_our_big_buff_activated
{
public:
  explicit Init_GameStatus_our_big_buff_activated(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_our_fortress_status our_big_buff_activated(::robots_msgs::msg::GameStatus::_our_big_buff_activated_type arg)
  {
    msg_.our_big_buff_activated = std::move(arg);
    return Init_GameStatus_our_fortress_status(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_our_small_buff_activated
{
public:
  explicit Init_GameStatus_our_small_buff_activated(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_our_big_buff_activated our_small_buff_activated(::robots_msgs::msg::GameStatus::_our_small_buff_activated_type arg)
  {
    msg_.our_small_buff_activated = std::move(arg);
    return Init_GameStatus_our_big_buff_activated(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_supply_area_occupied
{
public:
  explicit Init_GameStatus_supply_area_occupied(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_our_small_buff_activated supply_area_occupied(::robots_msgs::msg::GameStatus::_supply_area_occupied_type arg)
  {
    msg_.supply_area_occupied = std::move(arg);
    return Init_GameStatus_our_small_buff_activated(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_inner_supply_area_occupied
{
public:
  explicit Init_GameStatus_inner_supply_area_occupied(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_supply_area_occupied inner_supply_area_occupied(::robots_msgs::msg::GameStatus::_inner_supply_area_occupied_type arg)
  {
    msg_.inner_supply_area_occupied = std::move(arg);
    return Init_GameStatus_supply_area_occupied(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_external_supply_area_occupied
{
public:
  explicit Init_GameStatus_external_supply_area_occupied(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_inner_supply_area_occupied external_supply_area_occupied(::robots_msgs::msg::GameStatus::_external_supply_area_occupied_type arg)
  {
    msg_.external_supply_area_occupied = std::move(arg);
    return Init_GameStatus_inner_supply_area_occupied(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_base_hp
{
public:
  explicit Init_GameStatus_enemy_base_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_external_supply_area_occupied enemy_base_hp(::robots_msgs::msg::GameStatus::_enemy_base_hp_type arg)
  {
    msg_.enemy_base_hp = std::move(arg);
    return Init_GameStatus_external_supply_area_occupied(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_outpost_hp
{
public:
  explicit Init_GameStatus_enemy_outpost_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_base_hp enemy_outpost_hp(::robots_msgs::msg::GameStatus::_enemy_outpost_hp_type arg)
  {
    msg_.enemy_outpost_hp = std::move(arg);
    return Init_GameStatus_enemy_base_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_7_robot_hp
{
public:
  explicit Init_GameStatus_enemy_7_robot_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_outpost_hp enemy_7_robot_hp(::robots_msgs::msg::GameStatus::_enemy_7_robot_hp_type arg)
  {
    msg_.enemy_7_robot_hp = std::move(arg);
    return Init_GameStatus_enemy_outpost_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_5_robot_hp
{
public:
  explicit Init_GameStatus_enemy_5_robot_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_7_robot_hp enemy_5_robot_hp(::robots_msgs::msg::GameStatus::_enemy_5_robot_hp_type arg)
  {
    msg_.enemy_5_robot_hp = std::move(arg);
    return Init_GameStatus_enemy_7_robot_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_4_robot_hp
{
public:
  explicit Init_GameStatus_enemy_4_robot_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_5_robot_hp enemy_4_robot_hp(::robots_msgs::msg::GameStatus::_enemy_4_robot_hp_type arg)
  {
    msg_.enemy_4_robot_hp = std::move(arg);
    return Init_GameStatus_enemy_5_robot_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_3_robot_hp
{
public:
  explicit Init_GameStatus_enemy_3_robot_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_4_robot_hp enemy_3_robot_hp(::robots_msgs::msg::GameStatus::_enemy_3_robot_hp_type arg)
  {
    msg_.enemy_3_robot_hp = std::move(arg);
    return Init_GameStatus_enemy_4_robot_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_2_robot_hp
{
public:
  explicit Init_GameStatus_enemy_2_robot_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_3_robot_hp enemy_2_robot_hp(::robots_msgs::msg::GameStatus::_enemy_2_robot_hp_type arg)
  {
    msg_.enemy_2_robot_hp = std::move(arg);
    return Init_GameStatus_enemy_3_robot_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_enemy_1_robot_hp
{
public:
  explicit Init_GameStatus_enemy_1_robot_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_2_robot_hp enemy_1_robot_hp(::robots_msgs::msg::GameStatus::_enemy_1_robot_hp_type arg)
  {
    msg_.enemy_1_robot_hp = std::move(arg);
    return Init_GameStatus_enemy_2_robot_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_our_hero_y
{
public:
  explicit Init_GameStatus_our_hero_y(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_enemy_1_robot_hp our_hero_y(::robots_msgs::msg::GameStatus::_our_hero_y_type arg)
  {
    msg_.our_hero_y = std::move(arg);
    return Init_GameStatus_enemy_1_robot_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_our_hero_x
{
public:
  explicit Init_GameStatus_our_hero_x(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_our_hero_y our_hero_x(::robots_msgs::msg::GameStatus::_our_hero_x_type arg)
  {
    msg_.our_hero_x = std::move(arg);
    return Init_GameStatus_our_hero_y(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_my_base_hp
{
public:
  explicit Init_GameStatus_my_base_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_our_hero_x my_base_hp(::robots_msgs::msg::GameStatus::_my_base_hp_type arg)
  {
    msg_.my_base_hp = std::move(arg);
    return Init_GameStatus_our_hero_x(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_my_outpost_hp
{
public:
  explicit Init_GameStatus_my_outpost_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_my_base_hp my_outpost_hp(::robots_msgs::msg::GameStatus::_my_outpost_hp_type arg)
  {
    msg_.my_outpost_hp = std::move(arg);
    return Init_GameStatus_my_base_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_my_hp
{
public:
  explicit Init_GameStatus_my_hp(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_my_outpost_hp my_hp(::robots_msgs::msg::GameStatus::_my_hp_type arg)
  {
    msg_.my_hp = std::move(arg);
    return Init_GameStatus_my_outpost_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_stage_remain_time
{
public:
  explicit Init_GameStatus_stage_remain_time(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_my_hp stage_remain_time(::robots_msgs::msg::GameStatus::_stage_remain_time_type arg)
  {
    msg_.stage_remain_time = std::move(arg);
    return Init_GameStatus_my_hp(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_game_progress
{
public:
  explicit Init_GameStatus_game_progress(::robots_msgs::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_stage_remain_time game_progress(::robots_msgs::msg::GameStatus::_game_progress_type arg)
  {
    msg_.game_progress = std::move(arg);
    return Init_GameStatus_stage_remain_time(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

class Init_GameStatus_game_type
{
public:
  Init_GameStatus_game_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameStatus_game_progress game_type(::robots_msgs::msg::GameStatus::_game_type_type arg)
  {
    msg_.game_type = std::move(arg);
    return Init_GameStatus_game_progress(msg_);
  }

private:
  ::robots_msgs::msg::GameStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::GameStatus>()
{
  return robots_msgs::msg::builder::Init_GameStatus_game_type();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
