# 云台保持决策迁入 C++

`SlopeHoleController` 在 LOW 和对应洞的实测对准均完成后锁存 `gimbal_heading_held_`，通过 `Output.hold_gimbal_heading` 输出。连续洞之间与 LOW 一起保持，第二洞仍须在自己的 A 取得入口许可；最后 D 与整车净空确认并请求 NORMAL 时释放。

`HoleTraversalState.hold_gimbal_heading` 明确传达此指令，ROS 适配器直接转发。仿真桥只校验执行消息的身份/版本/时效后执行，不再根据状态编码或 LOW 请求推断。旋转执行器保持第一次已完成对准的地面朝向，不重选目标；底盘普通导航和安全停转优先级保持原样。实车旋转执行器应订阅并遵守同一指令。

本次不启动 Gazebo、RViz 或导航仿真。`checks.log` 是离线回归：

- C++：未降低/未对准时不锁存、对应洞反馈校验、D1/A2间保持、HOLD不丢需求、第二洞独立入口许可、D2净空等待、最终释放、单洞和目标外洞、重规划删除后续洞。
- C++：既有入口许可、上下坡许可保持及故障/退让回归。
- Python：地面朝向保持与第二洞对准、旋转几何和安全停转回归。

`build.log` 记录 `nav_interfaces`、`nav_core`、`nav_components` 的编译安装。仅修改 test 工作区的状态机、输出消息和相应执行适配及文档/检查；没有同步原 navigate，未修改规划、NMPC、车辆模型、速度参数或启动方式。旧运行进程需要重启以加载更新后的消息及算法。
