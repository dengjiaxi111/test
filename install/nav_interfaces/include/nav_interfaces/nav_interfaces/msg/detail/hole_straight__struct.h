// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleStraight.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_straight.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/HoleStraight in the package nav_interfaces.
/**
  * 当前最终路径上需要保持直线的区间；嵌套在 HoleTraversal.straight_segments。
  * 对应交接文档5.2：严格模式S—T；free模式S—E和X—T。
  * 方向是地图中的运动切线，不是机身yaw对准要求。
 */
typedef struct nav_interfaces__msg__HoleStraight
{
  /// 直线区间起点的路径累计弧长，单位m，相对当前NavigationPlan.path起点。
  double s_begin;
  /// 直线区间终点的路径累计弧长，单位m，应不小于s_begin。
  double s_end;
  /// 地图坐标系的运动方向向量，草稿使用二维切向x/y；不是机身朝向角，也不是速度大小。
  geometry_msgs__msg__Vector3 direction;
  /// true表示当前只能声明剩余直线片段；false声明完整区间，不等于该段已经走完。
  bool remaining;
} nav_interfaces__msg__HoleStraight;

// Struct for a sequence of nav_interfaces__msg__HoleStraight.
typedef struct nav_interfaces__msg__HoleStraight__Sequence
{
  nav_interfaces__msg__HoleStraight * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleStraight__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRAIGHT__STRUCT_H_
