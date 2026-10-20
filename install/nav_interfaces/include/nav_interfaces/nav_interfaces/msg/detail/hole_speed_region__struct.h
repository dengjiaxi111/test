// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_speed_region.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/HoleSpeedRegion in the package nav_interfaces.
/**
  * 最终路径上的分段速度上限；嵌套在 NavigationPlan.speed_regions。
  * 为上下坡及坡顶后限速补充的结构；它描述限制，不负责生成加减速指令。
  * 不改变A/S/E/X/T/D几何；具体上限由配置和控制器共同处理。
 */
typedef struct nav_interfaces__msg__HoleSpeedRegion
{
  /// 限速区间起点的路径累计弧长，单位m。
  double s_begin;
  /// 限速区间终点的路径累计弧长，单位m；按当前最终路径解释。
  double s_end;
  /// 区间平移速度模长上限，单位m/s；允许更慢或停车，不是强制目标速度。
  double speed_limit;
  /// 当前C++编码：0平地FLAT，1上坡UPHILL，2下坡DOWNHILL，3受限RESTRICTED；消息尚未声明对应命名常量。
  uint8_t kind;
} nav_interfaces__msg__HoleSpeedRegion;

// Struct for a sequence of nav_interfaces__msg__HoleSpeedRegion.
typedef struct nav_interfaces__msg__HoleSpeedRegion__Sequence
{
  nav_interfaces__msg__HoleSpeedRegion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleSpeedRegion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_SPEED_REGION__STRUCT_H_
