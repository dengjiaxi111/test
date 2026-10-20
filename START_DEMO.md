# 手动可视测试

在普通终端运行（无需重新编译）：

```bash
cd /home/dengjiaxi/simulation_seu
bash test/start_demo.sh
```

脚本启动独立2026场地、60cm升降舵轮小车、测试版navigate、机构适配器、六点显示、Gazebo和RViz。按用户要求使用NVIDIA渲染，不设置Mesa软件渲染。所有日志写入 `test/logs/crest_*.log`。原工程不启动、不覆盖。结束用启动终端的Ctrl+C，脚本会清理本次子进程；手动模式最多运行一小时。

1. 等终端显示 `READY`，在RViz顶部点 **2D Goal Pose**，左键按住后拖动并松开。机器人初始位置是地图坐标 `(4.694,5.000)`，画面已对准A2坡洞。
2. 推荐单洞目标 `(4.694,7.604)`。可直接点击坡洞另一侧，或在第二个终端精确发送下面的目标。导航采用严格中心线模式。
3. 蓝线是正式 `/plan`；`Accepted six events` 显示来自正式 `NavigationPlan` 的 A、S、E、X、T、D，标签带洞号和弧长。T和D在此人工配置中重合，不是漏画。
4. Gazebo中橙色上部自动降低/恢复。反馈基于实际升降关节位置；不是等1.5秒就假装变形完成。RViz显示路径和六点；Gazebo显示真实物理运动。

第二终端精确发送单洞目标：

```bash
source /opt/ros/jazzy/setup.bash
export ROS_DOMAIN_ID=187
ros2 topic pub --once /goal_pose geometry_msgs/msg/PoseStamped \
  '{header: {frame_id: map}, pose: {position: {x: 4.694, y: 7.604}, orientation: {w: 1.0}}}'
```

当前实际验证：平地舵轮运动、真实关节降低和恢复通过；正式单洞/双洞规划与事件显示已经接入。**2026实场地的坡前至坡顶闭环尚未通过**，之前实测会在坡前停滞并进入HOLD/退让；不能将这条启动命令理解为过洞验收已通过。暂停后可检查RViz状态文字和 `test/logs/crest_nav_server.log`。本入口没有使用位置瞬移或人工速度覆盖导航。

新增 `chassiss`、底盘/云台旋转及停转命令说明见 [ROTATION.md](ROTATION.md)。新增坐标轴在RViz中名为 `Chassiss heading`。原fake保持与odom平行。旋转时平移、实际停转反馈已通过无GUI物理回归；完整过洞仍以本页上述限制和最新结果为准。NVIDIA图形窗口由用户手动启动，未声称已经验证驱动稳定性。
