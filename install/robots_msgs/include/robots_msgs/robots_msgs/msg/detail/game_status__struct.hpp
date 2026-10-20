// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/GameStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/game_status.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__GameStatus __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__GameStatus __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameStatus_
{
  using Type = GameStatus_<ContainerAllocator>;

  explicit GameStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->game_type = 0;
      this->game_progress = 0;
      this->stage_remain_time = 0;
      this->my_hp = 0;
      this->my_outpost_hp = 0;
      this->my_base_hp = 0;
      this->our_hero_x = 0.0f;
      this->our_hero_y = 0.0f;
      this->enemy_1_robot_hp = 0;
      this->enemy_2_robot_hp = 0;
      this->enemy_3_robot_hp = 0;
      this->enemy_4_robot_hp = 0;
      this->enemy_5_robot_hp = 0;
      this->enemy_7_robot_hp = 0;
      this->enemy_outpost_hp = 0;
      this->enemy_base_hp = 0;
      this->external_supply_area_occupied = 0;
      this->inner_supply_area_occupied = 0;
      this->supply_area_occupied = 0;
      this->our_small_buff_activated = 0;
      this->our_big_buff_activated = 0;
      this->our_fortress_status = 0;
      this->remaining_gold_coin = 0;
    }
  }

  explicit GameStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->game_type = 0;
      this->game_progress = 0;
      this->stage_remain_time = 0;
      this->my_hp = 0;
      this->my_outpost_hp = 0;
      this->my_base_hp = 0;
      this->our_hero_x = 0.0f;
      this->our_hero_y = 0.0f;
      this->enemy_1_robot_hp = 0;
      this->enemy_2_robot_hp = 0;
      this->enemy_3_robot_hp = 0;
      this->enemy_4_robot_hp = 0;
      this->enemy_5_robot_hp = 0;
      this->enemy_7_robot_hp = 0;
      this->enemy_outpost_hp = 0;
      this->enemy_base_hp = 0;
      this->external_supply_area_occupied = 0;
      this->inner_supply_area_occupied = 0;
      this->supply_area_occupied = 0;
      this->our_small_buff_activated = 0;
      this->our_big_buff_activated = 0;
      this->our_fortress_status = 0;
      this->remaining_gold_coin = 0;
    }
  }

  // field types and members
  using _game_type_type =
    uint8_t;
  _game_type_type game_type;
  using _game_progress_type =
    uint8_t;
  _game_progress_type game_progress;
  using _stage_remain_time_type =
    uint16_t;
  _stage_remain_time_type stage_remain_time;
  using _my_hp_type =
    uint16_t;
  _my_hp_type my_hp;
  using _my_outpost_hp_type =
    uint16_t;
  _my_outpost_hp_type my_outpost_hp;
  using _my_base_hp_type =
    uint16_t;
  _my_base_hp_type my_base_hp;
  using _our_hero_x_type =
    float;
  _our_hero_x_type our_hero_x;
  using _our_hero_y_type =
    float;
  _our_hero_y_type our_hero_y;
  using _enemy_1_robot_hp_type =
    uint16_t;
  _enemy_1_robot_hp_type enemy_1_robot_hp;
  using _enemy_2_robot_hp_type =
    uint16_t;
  _enemy_2_robot_hp_type enemy_2_robot_hp;
  using _enemy_3_robot_hp_type =
    uint16_t;
  _enemy_3_robot_hp_type enemy_3_robot_hp;
  using _enemy_4_robot_hp_type =
    uint16_t;
  _enemy_4_robot_hp_type enemy_4_robot_hp;
  using _enemy_5_robot_hp_type =
    uint16_t;
  _enemy_5_robot_hp_type enemy_5_robot_hp;
  using _enemy_7_robot_hp_type =
    uint16_t;
  _enemy_7_robot_hp_type enemy_7_robot_hp;
  using _enemy_outpost_hp_type =
    uint16_t;
  _enemy_outpost_hp_type enemy_outpost_hp;
  using _enemy_base_hp_type =
    uint16_t;
  _enemy_base_hp_type enemy_base_hp;
  using _external_supply_area_occupied_type =
    uint8_t;
  _external_supply_area_occupied_type external_supply_area_occupied;
  using _inner_supply_area_occupied_type =
    uint8_t;
  _inner_supply_area_occupied_type inner_supply_area_occupied;
  using _supply_area_occupied_type =
    uint8_t;
  _supply_area_occupied_type supply_area_occupied;
  using _our_small_buff_activated_type =
    uint8_t;
  _our_small_buff_activated_type our_small_buff_activated;
  using _our_big_buff_activated_type =
    uint8_t;
  _our_big_buff_activated_type our_big_buff_activated;
  using _our_fortress_status_type =
    uint8_t;
  _our_fortress_status_type our_fortress_status;
  using _remaining_gold_coin_type =
    uint16_t;
  _remaining_gold_coin_type remaining_gold_coin;

  // setters for named parameter idiom
  Type & set__game_type(
    const uint8_t & _arg)
  {
    this->game_type = _arg;
    return *this;
  }
  Type & set__game_progress(
    const uint8_t & _arg)
  {
    this->game_progress = _arg;
    return *this;
  }
  Type & set__stage_remain_time(
    const uint16_t & _arg)
  {
    this->stage_remain_time = _arg;
    return *this;
  }
  Type & set__my_hp(
    const uint16_t & _arg)
  {
    this->my_hp = _arg;
    return *this;
  }
  Type & set__my_outpost_hp(
    const uint16_t & _arg)
  {
    this->my_outpost_hp = _arg;
    return *this;
  }
  Type & set__my_base_hp(
    const uint16_t & _arg)
  {
    this->my_base_hp = _arg;
    return *this;
  }
  Type & set__our_hero_x(
    const float & _arg)
  {
    this->our_hero_x = _arg;
    return *this;
  }
  Type & set__our_hero_y(
    const float & _arg)
  {
    this->our_hero_y = _arg;
    return *this;
  }
  Type & set__enemy_1_robot_hp(
    const uint16_t & _arg)
  {
    this->enemy_1_robot_hp = _arg;
    return *this;
  }
  Type & set__enemy_2_robot_hp(
    const uint16_t & _arg)
  {
    this->enemy_2_robot_hp = _arg;
    return *this;
  }
  Type & set__enemy_3_robot_hp(
    const uint16_t & _arg)
  {
    this->enemy_3_robot_hp = _arg;
    return *this;
  }
  Type & set__enemy_4_robot_hp(
    const uint16_t & _arg)
  {
    this->enemy_4_robot_hp = _arg;
    return *this;
  }
  Type & set__enemy_5_robot_hp(
    const uint16_t & _arg)
  {
    this->enemy_5_robot_hp = _arg;
    return *this;
  }
  Type & set__enemy_7_robot_hp(
    const uint16_t & _arg)
  {
    this->enemy_7_robot_hp = _arg;
    return *this;
  }
  Type & set__enemy_outpost_hp(
    const uint16_t & _arg)
  {
    this->enemy_outpost_hp = _arg;
    return *this;
  }
  Type & set__enemy_base_hp(
    const uint16_t & _arg)
  {
    this->enemy_base_hp = _arg;
    return *this;
  }
  Type & set__external_supply_area_occupied(
    const uint8_t & _arg)
  {
    this->external_supply_area_occupied = _arg;
    return *this;
  }
  Type & set__inner_supply_area_occupied(
    const uint8_t & _arg)
  {
    this->inner_supply_area_occupied = _arg;
    return *this;
  }
  Type & set__supply_area_occupied(
    const uint8_t & _arg)
  {
    this->supply_area_occupied = _arg;
    return *this;
  }
  Type & set__our_small_buff_activated(
    const uint8_t & _arg)
  {
    this->our_small_buff_activated = _arg;
    return *this;
  }
  Type & set__our_big_buff_activated(
    const uint8_t & _arg)
  {
    this->our_big_buff_activated = _arg;
    return *this;
  }
  Type & set__our_fortress_status(
    const uint8_t & _arg)
  {
    this->our_fortress_status = _arg;
    return *this;
  }
  Type & set__remaining_gold_coin(
    const uint16_t & _arg)
  {
    this->remaining_gold_coin = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::GameStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::GameStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::GameStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::GameStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__GameStatus
    std::shared_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__GameStatus
    std::shared_ptr<robots_msgs::msg::GameStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameStatus_ & other) const
  {
    if (this->game_type != other.game_type) {
      return false;
    }
    if (this->game_progress != other.game_progress) {
      return false;
    }
    if (this->stage_remain_time != other.stage_remain_time) {
      return false;
    }
    if (this->my_hp != other.my_hp) {
      return false;
    }
    if (this->my_outpost_hp != other.my_outpost_hp) {
      return false;
    }
    if (this->my_base_hp != other.my_base_hp) {
      return false;
    }
    if (this->our_hero_x != other.our_hero_x) {
      return false;
    }
    if (this->our_hero_y != other.our_hero_y) {
      return false;
    }
    if (this->enemy_1_robot_hp != other.enemy_1_robot_hp) {
      return false;
    }
    if (this->enemy_2_robot_hp != other.enemy_2_robot_hp) {
      return false;
    }
    if (this->enemy_3_robot_hp != other.enemy_3_robot_hp) {
      return false;
    }
    if (this->enemy_4_robot_hp != other.enemy_4_robot_hp) {
      return false;
    }
    if (this->enemy_5_robot_hp != other.enemy_5_robot_hp) {
      return false;
    }
    if (this->enemy_7_robot_hp != other.enemy_7_robot_hp) {
      return false;
    }
    if (this->enemy_outpost_hp != other.enemy_outpost_hp) {
      return false;
    }
    if (this->enemy_base_hp != other.enemy_base_hp) {
      return false;
    }
    if (this->external_supply_area_occupied != other.external_supply_area_occupied) {
      return false;
    }
    if (this->inner_supply_area_occupied != other.inner_supply_area_occupied) {
      return false;
    }
    if (this->supply_area_occupied != other.supply_area_occupied) {
      return false;
    }
    if (this->our_small_buff_activated != other.our_small_buff_activated) {
      return false;
    }
    if (this->our_big_buff_activated != other.our_big_buff_activated) {
      return false;
    }
    if (this->our_fortress_status != other.our_fortress_status) {
      return false;
    }
    if (this->remaining_gold_coin != other.remaining_gold_coin) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameStatus_

// alias to use template instance with default allocator
using GameStatus =
  robots_msgs::msg::GameStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__GAME_STATUS__STRUCT_HPP_
