// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nav_interfaces:msg/HoleStructureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_interfaces/msg/hole_structure_request.h"


#ifndef NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__STRUCT_H_
#define NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'KEEP'.
/**
  * 常量0：保持当前适用形态，不等于正常姿态；中间位置如何安全保持须由真实机构侧定义。
 */
enum
{
  nav_interfaces__msg__HoleStructureRequest__KEEP = 0
};

/// Constant 'LOW'.
/**
  * 常量1：要求低姿态；具体腿长/执行器目标由真实机构接口定义。
 */
enum
{
  nav_interfaces__msg__HoleStructureRequest__LOW = 1
};

/// Constant 'NORMAL'.
/**
  * 常量2：要求正常姿态；与KEEP不同，应在释放和净空条件成立后请求。
 */
enum
{
  nav_interfaces__msg__HoleStructureRequest__NORMAL = 2
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'session_id'
// Member 'goal_id'
// Member 'traversal_uids'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/HoleStructureRequest in the package nav_interfaces.
/**
  * 导航侧发往 hole_structure/request 的机构要求，机构控制侧接收并执行。
  * 对应交接文档5.4、7.3、8：请求身份、修订、同形态动作复用及多洞需求。
  * 组织方式参考旧stair_mode，但本文件的数字含义不复用台阶模式值。
  * LOW/NORMAL/KEEP具体怎样映射为真实下位机指令，尚需机构侧实现。
 */
typedef struct nav_interfaces__msg__HoleStructureRequest
{
  /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
  std_msgs__msg__Header header;
  /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
  rosidl_runtime_c__String session_id;
  /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
  rosidl_runtime_c__String goal_id;
  /// 机构动作请求编号；新动作换号，同一个动作的消息重发沿用原编号。反馈必须回填匹配。
  uint64_t request_id;
  /// 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
  uint64_t requirement_revision;
  /// 本次实际目标，填KEEP/LOW/NORMAL；上面的常量不会自动赋给它，须发送代码显式填写。
  uint8_t target;
  /// 当前共同需要该姿态的通行编号列表；连续两洞可同时存在，同形态可复用动作。
  rosidl_runtime_c__String__Sequence traversal_uids;
  /// 取消的是机构变形，不是底盘运动；草稿用true配KEEP按session/goal停止当前变形，不自动抬高。request_id=0为任务级取消约定，真实机构侧尚需实现。
  bool cancel_motion;
} nav_interfaces__msg__HoleStructureRequest;

// Struct for a sequence of nav_interfaces__msg__HoleStructureRequest.
typedef struct nav_interfaces__msg__HoleStructureRequest__Sequence
{
  nav_interfaces__msg__HoleStructureRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nav_interfaces__msg__HoleStructureRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAV_INTERFACES__MSG__DETAIL__HOLE_STRUCTURE_REQUEST__STRUCT_H_
