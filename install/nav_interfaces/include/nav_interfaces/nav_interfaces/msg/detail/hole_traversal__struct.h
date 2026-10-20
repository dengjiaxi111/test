// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleTraversal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'traversal_uid'
// Member 'hole_id'
#include "rosidl_runtime_c/string.h"
// Member 'events'
#include "nav_interfaces/msg/detail/hole_event__struct.h"
// Member 'straight_segments'
#include "nav_interfaces/msg/detail/hole_straight__struct.h"

/// Struct defined in msg/HoleTraversal in the package nav_interfaces.
/**
  * 一次具体穿洞的计划记录；嵌套在 NavigationPlan.passages 内，不单独发布。
  * 对应交接文档5.2。同一个物理洞再次穿越，应有另一条通行记录。
  * 当前草稿尚未完整导出文档列出的顺序、完整性、细分校验结果和容差等信息。
 */
typedef struct nav_interfaces__msg__HoleTraversal
{
  /// 本任务中这一次具体穿越的稳定编号；同次通行重规划匹配保留，再穿同一个洞应另编号。
  rosidl_runtime_c__String traversal_uid;
  /// 地形配置中的物理洞口区域ID；同一个洞可关联不同次通行，不能单独用来动作去重。
  rosidl_runtime_c__String hole_id;
  /// 本次选中的洞口多边形入口边索引，编号规则来自规划器。
  int32_t entry_edge_id;
  /// 本次选中的洞口多边形出口边索引，与入口共同确定通行方向。
  int32_t exit_edge_id;
  /// true为严格中心线模式，false为free；默认只接纳严格模式，除非配置显式允许free。
  bool centerline;
  /// 当前候选校验是否通过；不能替代文档全部细分保证，不能表示机构准备已完成。
  bool validated;
  /// 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
  uint64_t requirement_revision;
  /// 固定六项，存储顺序A/S/E/X/T/D；此数组顺序不代表事件的实际弧长顺序，A可能晚于S。
  nav_interfaces__msg__HoleEvent events[6];
  /// 本路径中有效的固定直线区间，区分完整段和剩余段，不能由恢复动作任意破坏。
  nav_interfaces__msg__HoleStraight__Sequence straight_segments;
  /// 本次入口方向与关联坡上坡方向一致；首版只允许此类失败后退让。
  bool uphill_entry;
} nav_interfaces__msg__HoleTraversal;

// Struct for a sequence of nav_interfaces__msg__HoleTraversal.
typedef struct nav_interfaces__msg__HoleTraversal__Sequence
{
  nav_interfaces__msg__HoleTraversal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleTraversal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL__STRUCT_H_
