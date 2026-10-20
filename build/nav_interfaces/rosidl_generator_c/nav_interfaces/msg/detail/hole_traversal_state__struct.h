// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleTraversalState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_traversal_state.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__STRUCT_H_

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
// Member 'reason'
// Member 'traversal_uids'
#include "rosidl_runtime_c/string.h"
// Member 'phases'
// Member 'preparing_required'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/HoleTraversalState in the package nav_interfaces.
/**
  * 导航侧发布 hole_traversal_state：当前五态、决策、进度和逐洞阶段。
  * 对应交接文档5.4、7.1。用于观察执行；本消息不是独立的运动许可协议。
  * 当前准备信息只包含需求标记，不完整表达准备中/就绪/故障；此为草稿缺口。
 */
typedef struct nav_interfaces__msg__HoleTraversalState
{
  /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
  std_msgs__msg__Header header;
  /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
  rosidl_runtime_c__String session_id;
  /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
  rosidl_runtime_c__String goal_id;
  /// 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
  uint64_t plan_id;
  /// 当前五态编码：0 NORMAL，1 PREPARE，2 TRAVERSE，3 RESTORE，4 HOLD；不是顶层导航状态。
  uint8_t state;
  /// 导航决策编码：0 CONTINUE，1 STOP，2 REPLAN，3 RECOVERY，4 FAILURE；HOLD状态可输出不同决策。
  uint8_t decision;
  /// 机器人参考点在当前路径上的可靠累计进度，单位m；不是总里程。
  double s_progress;
  /// 本周期允许的平移速度模长上限，单位m/s；不能单凭观察消息绕过运动许可。
  double speed_limit;
  /// 当前状态/决策或暂停原因的说明文字；草稿部分分支仍比较字符串，尚非完整故障码协议。
  rosidl_runtime_c__String reason;
  /// 核心当前保留的通行编号列表，可能包含已完成记录；顺序与下面两个数组必须一一对应。
  rosidl_runtime_c__String__Sequence traversal_uids;
  /// 逐通行空间阶段：0 PENDING，1 ENTRY_STRAIGHT，2 IN_HOLE，3 EXIT_STRAIGHT，4 DEPARTING，5 COMPLETE。到D可先标记COMPLETE，不单凭此值证明占用已释放。
  rosidl_runtime_c__uint8__Sequence phases;
  /// 逐通行的结构需求标记，实际来自Visit.demand；true不代表正在变形，也不证明准备完成，进入洞内后仍可为true。
  rosidl_runtime_c__boolean__Sequence preparing_required;
  /// 本次通行尝试编号，0为首次，1/2为两次重试。
  uint32_t attempt;
  /// 专用恢复阶段：0无，1停稳，2校验，3退让，4目标停稳，5重入检查。
  uint8_t recovery_phase;
} nav_interfaces__msg__HoleTraversalState;

// Struct for a sequence of nav_interfaces__msg__HoleTraversalState.
typedef struct nav_interfaces__msg__HoleTraversalState__Sequence
{
  nav_interfaces__msg__HoleTraversalState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleTraversalState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_TRAVERSAL_STATE__STRUCT_H_
