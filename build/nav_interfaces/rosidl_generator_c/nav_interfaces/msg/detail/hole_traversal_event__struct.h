// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleTraversalEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_event.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'session_id'
// Member 'goal_id'
// Member 'traversal_uid'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/HoleTraversalEvent in the package nav_interfaces.
/**
  * 导航侧发布 hole_traversal_event：某个路径事件已被执行调度器触发的通知。
  * 对应交接文档5.4、7.3；区别于仅描述计划位置的HoleEvent。
  * 接收方仍须按会话/任务/通行/事件类型记录去重，不能假设外部动作恰好执行一次。
 */
typedef struct nav_interfaces__msg__HoleTraversalEvent
{
  /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
  std_msgs__msg__Header header;
  /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
  rosidl_runtime_c__String session_id;
  /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
  rosidl_runtime_c__String goal_id;
  /// 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
  uint64_t plan_id;
  /// 本次触发事件属于哪一次具体通行，与计划中的对应记录匹配。
  rosidl_runtime_c__String traversal_uid;
  /// 当前控制器实例内递增的执行事件序号，便于排查顺序；不单独作为动作去重键。
  uint64_t sequence;
  /// 已触发的事件类型：0 A，1 S，2 E，3 X，4 T，5 D。通知本身不替代真实机构反馈。
  uint8_t type;
  /// 该事件在触发时计划路径上的弧长位置，单位m。
  double event_arc;
  /// 处理该事件时参考点的可靠路径进度，单位m，可略大于event_arc。
  double progress;
  /// 所属尝试编号；历史事件不因倒退删除。
  uint32_t attempt;
} nav_interfaces__msg__HoleTraversalEvent;

// Struct for a sequence of nav_interfaces__msg__HoleTraversalEvent.
typedef struct nav_interfaces__msg__HoleTraversalEvent__Sequence
{
  nav_interfaces__msg__HoleTraversalEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleTraversalEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_EVENT__STRUCT_H_
