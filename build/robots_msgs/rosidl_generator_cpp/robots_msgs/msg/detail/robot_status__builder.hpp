// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/robot_status.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robots_msgs/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robots_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_target_position_y
{
public:
  explicit Init_RobotStatus_target_position_y(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::robots_msgs::msg::RobotStatus target_position_y(::robots_msgs::msg::RobotStatus::_target_position_y_type arg)
  {
    msg_.target_position_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_target_position_x
{
public:
  explicit Init_RobotStatus_target_position_x(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_target_position_y target_position_x(::robots_msgs::msg::RobotStatus::_target_position_x_type arg)
  {
    msg_.target_position_x = std::move(arg);
    return Init_RobotStatus_target_position_y(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_projectile_allowance_17mm_remain
{
public:
  explicit Init_RobotStatus_projectile_allowance_17mm_remain(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_target_position_x projectile_allowance_17mm_remain(::robots_msgs::msg::RobotStatus::_projectile_allowance_17mm_remain_type arg)
  {
    msg_.projectile_allowance_17mm_remain = std::move(arg);
    return Init_RobotStatus_target_position_x(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_ttk_status
{
public:
  explicit Init_RobotStatus_ttk_status(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_projectile_allowance_17mm_remain ttk_status(::robots_msgs::msg::RobotStatus::_ttk_status_type arg)
  {
    msg_.ttk_status = std::move(arg);
    return Init_RobotStatus_projectile_allowance_17mm_remain(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_rebirth_need_coin
{
public:
  explicit Init_RobotStatus_rebirth_need_coin(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_ttk_status rebirth_need_coin(::robots_msgs::msg::RobotStatus::_rebirth_need_coin_type arg)
  {
    msg_.rebirth_need_coin = std::move(arg);
    return Init_RobotStatus_ttk_status(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_can_instant_rebirth
{
public:
  explicit Init_RobotStatus_can_instant_rebirth(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_rebirth_need_coin can_instant_rebirth(::robots_msgs::msg::RobotStatus::_can_instant_rebirth_type arg)
  {
    msg_.can_instant_rebirth = std::move(arg);
    return Init_RobotStatus_rebirth_need_coin(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_can_free_rebirth
{
public:
  explicit Init_RobotStatus_can_free_rebirth(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_can_instant_rebirth can_free_rebirth(::robots_msgs::msg::RobotStatus::_can_free_rebirth_type arg)
  {
    msg_.can_free_rebirth = std::move(arg);
    return Init_RobotStatus_can_instant_rebirth(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_remote_exchange_health_times
{
public:
  explicit Init_RobotStatus_remote_exchange_health_times(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_can_free_rebirth remote_exchange_health_times(::robots_msgs::msg::RobotStatus::_remote_exchange_health_times_type arg)
  {
    msg_.remote_exchange_health_times = std::move(arg);
    return Init_RobotStatus_can_free_rebirth(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_remote_exchange_projectile_times
{
public:
  explicit Init_RobotStatus_remote_exchange_projectile_times(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_remote_exchange_health_times remote_exchange_projectile_times(::robots_msgs::msg::RobotStatus::_remote_exchange_projectile_times_type arg)
  {
    msg_.remote_exchange_projectile_times = std::move(arg);
    return Init_RobotStatus_remote_exchange_health_times(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_local_exchange_projectile_allowance_17mm
{
public:
  explicit Init_RobotStatus_local_exchange_projectile_allowance_17mm(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_remote_exchange_projectile_times local_exchange_projectile_allowance_17mm(::robots_msgs::msg::RobotStatus::_local_exchange_projectile_allowance_17mm_type arg)
  {
    msg_.local_exchange_projectile_allowance_17mm = std::move(arg);
    return Init_RobotStatus_remote_exchange_projectile_times(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_supply_blood_area
{
public:
  explicit Init_RobotStatus_supply_blood_area(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_local_exchange_projectile_allowance_17mm supply_blood_area(::robots_msgs::msg::RobotStatus::_supply_blood_area_type arg)
  {
    msg_.supply_blood_area = std::move(arg);
    return Init_RobotStatus_local_exchange_projectile_allowance_17mm(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_fort_area
{
public:
  explicit Init_RobotStatus_fort_area(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_supply_blood_area fort_area(::robots_msgs::msg::RobotStatus::_fort_area_type arg)
  {
    msg_.fort_area = std::move(arg);
    return Init_RobotStatus_supply_blood_area(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_projectile_allowance_17mm
{
public:
  explicit Init_RobotStatus_projectile_allowance_17mm(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_fort_area projectile_allowance_17mm(::robots_msgs::msg::RobotStatus::_projectile_allowance_17mm_type arg)
  {
    msg_.projectile_allowance_17mm = std::move(arg);
    return Init_RobotStatus_fort_area(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_remaining_energy
{
public:
  explicit Init_RobotStatus_remaining_energy(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_projectile_allowance_17mm remaining_energy(::robots_msgs::msg::RobotStatus::_remaining_energy_type arg)
  {
    msg_.remaining_energy = std::move(arg);
    return Init_RobotStatus_projectile_allowance_17mm(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_attack_buff
{
public:
  explicit Init_RobotStatus_attack_buff(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_remaining_energy attack_buff(::robots_msgs::msg::RobotStatus::_attack_buff_type arg)
  {
    msg_.attack_buff = std::move(arg);
    return Init_RobotStatus_remaining_energy(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_vulnerability_buff
{
public:
  explicit Init_RobotStatus_vulnerability_buff(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_attack_buff vulnerability_buff(::robots_msgs::msg::RobotStatus::_vulnerability_buff_type arg)
  {
    msg_.vulnerability_buff = std::move(arg);
    return Init_RobotStatus_attack_buff(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_defence_buff
{
public:
  explicit Init_RobotStatus_defence_buff(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_vulnerability_buff defence_buff(::robots_msgs::msg::RobotStatus::_defence_buff_type arg)
  {
    msg_.defence_buff = std::move(arg);
    return Init_RobotStatus_vulnerability_buff(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_recovery_buff
{
public:
  explicit Init_RobotStatus_recovery_buff(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_defence_buff recovery_buff(::robots_msgs::msg::RobotStatus::_recovery_buff_type arg)
  {
    msg_.recovery_buff = std::move(arg);
    return Init_RobotStatus_defence_buff(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_angle
{
public:
  explicit Init_RobotStatus_angle(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_recovery_buff angle(::robots_msgs::msg::RobotStatus::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_RobotStatus_recovery_buff(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_y
{
public:
  explicit Init_RobotStatus_y(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_angle y(::robots_msgs::msg::RobotStatus::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotStatus_angle(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_x
{
public:
  explicit Init_RobotStatus_x(::robots_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_y x(::robots_msgs::msg::RobotStatus::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotStatus_y(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_id
{
public:
  Init_RobotStatus_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_x robot_id(::robots_msgs::msg::RobotStatus::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotStatus_x(msg_);
  }

private:
  ::robots_msgs::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robots_msgs::msg::RobotStatus>()
{
  return robots_msgs::msg::builder::Init_RobotStatus_robot_id();
}

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
