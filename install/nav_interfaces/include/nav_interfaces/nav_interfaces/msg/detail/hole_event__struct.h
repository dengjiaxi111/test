// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_event.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'A'.
/**
  * 事件类型常量0：开始准备的路径事件。
 */
enum
{
  nav_interfaces__msg__HoleEvent__A = 0
};

/// Constant 'S'.
/**
  * 事件类型常量1：入口固定直线开始。
 */
enum
{
  nav_interfaces__msg__HoleEvent__S = 1
};

/// Constant 'E'.
/**
  * 事件类型常量2：真实入口边界；人工配置必须在此之前确认准备完成。
 */
enum
{
  nav_interfaces__msg__HoleEvent__E = 2
};

/// Constant 'X'.
/**
  * 事件类型常量3：真实出口边界；参考点越过不代表整车退出。
 */
enum
{
  nav_interfaces__msg__HoleEvent__X = 3
};

/// Constant 'T'.
/**
  * 事件类型常量4：出口固定直线结束；后续路径才可按规划转弯。
 */
enum
{
  nav_interfaces__msg__HoleEvent__T = 4
};

/// Constant 'D'.
/**
  * 事件类型常量5：离开阶段边界；人工配置D=T，仍需反馈确认结构释放。
 */
enum
{
  nav_interfaces__msg__HoleEvent__D = 5
};

/// Constant 'ON_PATH'.
/**
  * 范围常量0：事件位于当前最终路径范围内。
 */
enum
{
  nav_interfaces__msg__HoleEvent__ON_PATH = 0
};

/// Constant 'BEFORE_PATH'.
/**
  * 范围常量1：位于当前剩余路径起点之前，不证明准备/通过动作已经完成。
 */
enum
{
  nav_interfaces__msg__HoleEvent__BEFORE_PATH = 1
};

/// Constant 'AFTER_PATH'.
/**
  * 范围常量2：位于当前路径终点之后，不证明机器人已到达或退出。
 */
enum
{
  nav_interfaces__msg__HoleEvent__AFTER_PATH = 2
};

/// Constant 'UNKNOWN'.
/**
  * 范围常量3：信息不足，不能可靠确定，禁止把默认坐标作为真实事件。
 */
enum
{
  nav_interfaces__msg__HoleEvent__UNKNOWN = 3
};

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/HoleEvent in the package nav_interfaces.
/**
  * 一个计划事件的位置说明；嵌套在 HoleTraversal.events 内。
  * 对应交接文档5.3；是“事件在哪里”，不是“事件已经触发”的通知。
  * A不一定在S前：允许在S—E内开始变形，但必须在E前完成。
  * 当前草稿缺少文档要求的reason字段；UNKNOWN/越界不能伪造有效坐标。
 */
typedef struct nav_interfaces__msg__HoleEvent
{
  /// 事件类型0—5，取A/S/E/X/T/D；与下面的range_status是两套不同编码。
  uint8_t type;
  /// 事件相对当前路径的范围状态0—3，取ON_PATH/BEFORE_PATH/AFTER_PATH/UNKNOWN。
  uint8_t range_status;
  /// 沿当前NavigationPlan.path起点累计到事件的弧长，单位m；不是两点直线距离。未知时不可使用。
  double s_path;
  /// 地图中的真实事件坐标x/y/z，单位m；只有point_valid为true时才可使用。
  geometry_msgs__msg__Point point;
  /// 是否有可靠的真实事件坐标；false时默认(0,0,0)不表示事件位于地图原点。
  bool point_valid;
} nav_interfaces__msg__HoleEvent;

// Struct for a sequence of nav_interfaces__msg__HoleEvent.
typedef struct nav_interfaces__msg__HoleEvent__Sequence
{
  nav_interfaces__msg__HoleEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_EVENT__STRUCT_H_
