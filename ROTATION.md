# 底盘旋转与 chassiss 接入

所有改动仅在 `test`。原 `navigate`、原 `navigatiosim2`、规划和 NMPC 数学文件不改。

`chassis → chassiss` 是新增动态 TF：原点重合，只跟底盘 yaw，相对 odom 始终水平。原来的 fake 原点仍随云台，三轴仍与 odom 平行。RViz 新增 `Chassiss heading` 坐标轴显示。

平移仍使用原 `/cmd_vel → navigation_to_chassis → /navigation/cmd_vel` 链。仿真适配器是 `/cmd_vel_chassis` 和 `/gimbal/cmd_vel` 的唯一发送方，在最终出口合并旋转，不重算原导航的平移速度。四轮既有解算与物理参数保持不变。不要同时让其他节点直接向这两个最终话题发指令。

## 人工旋转和停转

先运行 `bash test/start_demo.sh`。另开终端：

```bash
source /opt/ros/jazzy/setup.bash
export ROS_DOMAIN_ID=187
# 正值：底盘相对地面逆时针，枪口相对地面顺时针；须连续发送。
ros2 topic pub -r 20 /rotation/world_yaw_rate std_msgs/msg/Float64 '{data: 0.3}'
```

结束上述发布后，0.2秒内进入保持朝向。也可在另一个终端明确发送停转：

```bash
ros2 topic pub --once /rotation/stop std_msgs/msg/Bool '{data: true}'
ros2 topic echo /rotation/stopped
```

`true` 锁存停转请求，保持收到命令时的两个地面朝向；不停止导航平移。`/rotation/stopped=true` 表示两者**实测**地面 yaw 角速度均低于0.1rad/s，并连续保持0.2秒。仅收到命令、发出零指令不算完成。反馈缺失时该标志为false。

再次允许旋转/对准，需先解除锁存，再发送新的旋转指令：

```bash
ros2 topic pub --once /rotation/stop std_msgs/msg/Bool '{data: false}'
```

解除时不会重用停转前的旋转命令。锁存停转优先于自动对准；若停在错误角度，需要解除后才能继续对准。

`/rotation/feedback` 使用标准 `sensor_msgs/JointState`，不是新增msg：name依次是 `chassis_world_yaw`、`gimbal_world_yaw`，position为两者相对odom的yaw（rad），velocity为实际地面yaw变化率（rad/s）。这些是测量量，不是关节指令值。实车将来需要由真实姿态/编码器反馈提供该接口，不能直接运行Gazebo真值适配。

## 自动过洞

接近 S 时从正式计划取得洞轴，选择最近的底盘面并锁定，暂停连续反向旋转。底盘转向目标，云台关节补偿，保持枪口地面朝向；上部继续使用原来的升降请求。对准误差≤0.05rad，且两者实际角速度均<0.1rad/s，连续满足0.2秒后放行平移。洞内持续保持目标，不能恢复连续旋转。

E事件推进前检查停转许可；低姿态完成不代替停转许可。若条件未满足，保留E上游停车边界；若实测已经违规跨过E，则进入HOLD并拒绝生成“成功进入”事件。首次对准必须稳定停转后才能起步；起步后的小幅角速度波动按E上游停车边界处理，不每次都立即清零平移。角度越界或反馈缺失仍立即暂停。跨过E后继续保持锁定朝向，入口许可不作为回退到旧E停车边界的依据。D事件本身不解除朝向锁定，须原有整车净空反馈确认该通行已完成。

旋转适配参数在 `sim/rotation_control.yaml`，状态机误差阈值在 `src/my_navigation/nav_bringup/config/hole_state_machine.yaml`，均附单位和中文注释。当前Gazebo停转阈值为0.1rad/s，以容纳实测约0.04～0.06rad/s的接触瞬态；C++保守默认仍为0.03rad/s，实车需独立标定。底盘旋转上限1.2rad/s、关节上限2.4rad/s、朝向比例增益3/s、底盘零转速误差带0.01rad，仅用于当前仿真。误差带小于状态机0.05rad许可阈值，不放宽停转反馈要求。云台跟随实测底盘转速作反向补偿；受执行器响应/限幅影响，瞬态并不保证数学上的零误差。

## 文件作用

| 文件 | 作用 |
|---|---|
| `sim/rotation_control.py` | 水平参考系、地面yaw变化率、云台补偿与旋转模式 |
| `sim/rotation_control.yaml` | 旋转适配参数 |
| `sim/sim_bridge.py` | 新增TF、唯一指令合成、真实旋转反馈 |
| `src/my_navigation/nav_components/src/slopehole_ros_adapter.cpp` | 使用chassiss、检查新鲜反馈与连续停转、发送对准目标 |
| `src/my_navigation/nav_core/include/nav_core/hole_execution_types.hpp` | 旋转进入许可和阈值声明 |
| `src/my_navigation/nav_components/src/slopehole_controller.cpp` | E前检查新增许可，复用原停车边界 |
| `checks/rotation_geometry.py` | 平地/坡面坐标与旋转关系检查 |
| `checks/rotation_entry.cpp` | 未确认停转时禁止进入E |
| `checks/rotation_command_order.py` | 重复解除命令不吞旋转请求，停转后旧请求不复活 |
| `scripts/rotation_smoke.py` | 无GUI实际舵轮、旋转、停转、平移和TF验收 |

其余配套修改为头文件成员、sensor_msgs构建依赖、参数YAML及两个RViz配置。

## 当前验收结果

- 隔离包编译、坐标/旋转关系检查、停止与重新启动回调检查、E进入许可正反例通过。
- 无GUI平地物理回归通过：旋转约2.07rad时沿原平移方向行驶约1.76m，横向漂移约4.4cm；反向转速误差中位数约0.00083rad/s。停转命令不停止平移，随后可完成朝向对准；旧fake和新增chassiss的TF检查通过。
- 2026原场地单洞**未通过**：收到6个正式事件点，低姿态完成，经过A/S，未经过E/X。最远约map y=6.410m，E位于y=6.819m；坡中实测底盘瞬时yaw速度约0.99rad/s，触发进入许可/制动，最终进入进度保护HOLD。结果见 `results/crest.json`，不能据此宣称完整上下坡/过洞已经验证。
- 本轮未改模型碰撞体、轮组PID/摩擦、路径规划或NMPC速度计算；原工程602项文件哈希未变。当前问题需要继续区分轮组/地形接触与新增旋转闭环的动态影响，不能只靠放宽停转条件。
- NVIDIA GUI本轮没有启动，不能声称已验证驱动稳定性。已有NVIDIA手动入口保持可用。
