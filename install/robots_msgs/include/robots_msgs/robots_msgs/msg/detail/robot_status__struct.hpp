// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robots_msgs/msg/robot_status.hpp"


#ifndef ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robots_msgs__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__robots_msgs__msg__RobotStatus __declspec(deprecated)
#endif

namespace robots_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->angle = 0.0f;
      this->recovery_buff = 0;
      this->defence_buff = 0;
      this->vulnerability_buff = 0;
      this->attack_buff = 0;
      this->remaining_energy = 0;
      this->projectile_allowance_17mm = 0;
      this->fort_area = 0;
      this->supply_blood_area = 0;
      this->local_exchange_projectile_allowance_17mm = 0;
      this->remote_exchange_projectile_times = 0;
      this->remote_exchange_health_times = 0;
      this->can_free_rebirth = 0;
      this->can_instant_rebirth = 0;
      this->rebirth_need_coin = 0;
      this->ttk_status = 0;
      this->projectile_allowance_17mm_remain = 0;
      this->target_position_x = 0.0f;
      this->target_position_y = 0.0f;
    }
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->angle = 0.0f;
      this->recovery_buff = 0;
      this->defence_buff = 0;
      this->vulnerability_buff = 0;
      this->attack_buff = 0;
      this->remaining_energy = 0;
      this->projectile_allowance_17mm = 0;
      this->fort_area = 0;
      this->supply_blood_area = 0;
      this->local_exchange_projectile_allowance_17mm = 0;
      this->remote_exchange_projectile_times = 0;
      this->remote_exchange_health_times = 0;
      this->can_free_rebirth = 0;
      this->can_instant_rebirth = 0;
      this->rebirth_need_coin = 0;
      this->ttk_status = 0;
      this->projectile_allowance_17mm_remain = 0;
      this->target_position_x = 0.0f;
      this->target_position_y = 0.0f;
    }
  }

  // field types and members
  using _robot_id_type =
    uint8_t;
  _robot_id_type robot_id;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _angle_type =
    float;
  _angle_type angle;
  using _recovery_buff_type =
    uint8_t;
  _recovery_buff_type recovery_buff;
  using _defence_buff_type =
    uint8_t;
  _defence_buff_type defence_buff;
  using _vulnerability_buff_type =
    uint8_t;
  _vulnerability_buff_type vulnerability_buff;
  using _attack_buff_type =
    uint16_t;
  _attack_buff_type attack_buff;
  using _remaining_energy_type =
    uint8_t;
  _remaining_energy_type remaining_energy;
  using _projectile_allowance_17mm_type =
    uint16_t;
  _projectile_allowance_17mm_type projectile_allowance_17mm;
  using _fort_area_type =
    uint8_t;
  _fort_area_type fort_area;
  using _supply_blood_area_type =
    uint8_t;
  _supply_blood_area_type supply_blood_area;
  using _local_exchange_projectile_allowance_17mm_type =
    uint16_t;
  _local_exchange_projectile_allowance_17mm_type local_exchange_projectile_allowance_17mm;
  using _remote_exchange_projectile_times_type =
    uint8_t;
  _remote_exchange_projectile_times_type remote_exchange_projectile_times;
  using _remote_exchange_health_times_type =
    uint8_t;
  _remote_exchange_health_times_type remote_exchange_health_times;
  using _can_free_rebirth_type =
    uint8_t;
  _can_free_rebirth_type can_free_rebirth;
  using _can_instant_rebirth_type =
    uint8_t;
  _can_instant_rebirth_type can_instant_rebirth;
  using _rebirth_need_coin_type =
    uint16_t;
  _rebirth_need_coin_type rebirth_need_coin;
  using _ttk_status_type =
    uint8_t;
  _ttk_status_type ttk_status;
  using _projectile_allowance_17mm_remain_type =
    uint16_t;
  _projectile_allowance_17mm_remain_type projectile_allowance_17mm_remain;
  using _target_position_x_type =
    float;
  _target_position_x_type target_position_x;
  using _target_position_y_type =
    float;
  _target_position_y_type target_position_y;

  // setters for named parameter idiom
  Type & set__robot_id(
    const uint8_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__recovery_buff(
    const uint8_t & _arg)
  {
    this->recovery_buff = _arg;
    return *this;
  }
  Type & set__defence_buff(
    const uint8_t & _arg)
  {
    this->defence_buff = _arg;
    return *this;
  }
  Type & set__vulnerability_buff(
    const uint8_t & _arg)
  {
    this->vulnerability_buff = _arg;
    return *this;
  }
  Type & set__attack_buff(
    const uint16_t & _arg)
  {
    this->attack_buff = _arg;
    return *this;
  }
  Type & set__remaining_energy(
    const uint8_t & _arg)
  {
    this->remaining_energy = _arg;
    return *this;
  }
  Type & set__projectile_allowance_17mm(
    const uint16_t & _arg)
  {
    this->projectile_allowance_17mm = _arg;
    return *this;
  }
  Type & set__fort_area(
    const uint8_t & _arg)
  {
    this->fort_area = _arg;
    return *this;
  }
  Type & set__supply_blood_area(
    const uint8_t & _arg)
  {
    this->supply_blood_area = _arg;
    return *this;
  }
  Type & set__local_exchange_projectile_allowance_17mm(
    const uint16_t & _arg)
  {
    this->local_exchange_projectile_allowance_17mm = _arg;
    return *this;
  }
  Type & set__remote_exchange_projectile_times(
    const uint8_t & _arg)
  {
    this->remote_exchange_projectile_times = _arg;
    return *this;
  }
  Type & set__remote_exchange_health_times(
    const uint8_t & _arg)
  {
    this->remote_exchange_health_times = _arg;
    return *this;
  }
  Type & set__can_free_rebirth(
    const uint8_t & _arg)
  {
    this->can_free_rebirth = _arg;
    return *this;
  }
  Type & set__can_instant_rebirth(
    const uint8_t & _arg)
  {
    this->can_instant_rebirth = _arg;
    return *this;
  }
  Type & set__rebirth_need_coin(
    const uint16_t & _arg)
  {
    this->rebirth_need_coin = _arg;
    return *this;
  }
  Type & set__ttk_status(
    const uint8_t & _arg)
  {
    this->ttk_status = _arg;
    return *this;
  }
  Type & set__projectile_allowance_17mm_remain(
    const uint16_t & _arg)
  {
    this->projectile_allowance_17mm_remain = _arg;
    return *this;
  }
  Type & set__target_position_x(
    const float & _arg)
  {
    this->target_position_x = _arg;
    return *this;
  }
  Type & set__target_position_y(
    const float & _arg)
  {
    this->target_position_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robots_msgs::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const robots_msgs::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robots_msgs::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robots_msgs__msg__RobotStatus
    std::shared_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robots_msgs__msg__RobotStatus
    std::shared_ptr<robots_msgs::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->recovery_buff != other.recovery_buff) {
      return false;
    }
    if (this->defence_buff != other.defence_buff) {
      return false;
    }
    if (this->vulnerability_buff != other.vulnerability_buff) {
      return false;
    }
    if (this->attack_buff != other.attack_buff) {
      return false;
    }
    if (this->remaining_energy != other.remaining_energy) {
      return false;
    }
    if (this->projectile_allowance_17mm != other.projectile_allowance_17mm) {
      return false;
    }
    if (this->fort_area != other.fort_area) {
      return false;
    }
    if (this->supply_blood_area != other.supply_blood_area) {
      return false;
    }
    if (this->local_exchange_projectile_allowance_17mm != other.local_exchange_projectile_allowance_17mm) {
      return false;
    }
    if (this->remote_exchange_projectile_times != other.remote_exchange_projectile_times) {
      return false;
    }
    if (this->remote_exchange_health_times != other.remote_exchange_health_times) {
      return false;
    }
    if (this->can_free_rebirth != other.can_free_rebirth) {
      return false;
    }
    if (this->can_instant_rebirth != other.can_instant_rebirth) {
      return false;
    }
    if (this->rebirth_need_coin != other.rebirth_need_coin) {
      return false;
    }
    if (this->ttk_status != other.ttk_status) {
      return false;
    }
    if (this->projectile_allowance_17mm_remain != other.projectile_allowance_17mm_remain) {
      return false;
    }
    if (this->target_position_x != other.target_position_x) {
      return false;
    }
    if (this->target_position_y != other.target_position_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  robots_msgs::msg::RobotStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robots_msgs

#endif  // ROBOTS_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
