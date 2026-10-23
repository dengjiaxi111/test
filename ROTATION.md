> 2026-10-23已改为A同步启动对准与下降、取消准备固定限速、保留E停车预览，见 [PREPARE_AT_A.md](PREPARE_AT_A.md)。下文“S才对准/准备限速/prepare_speed”等属于历史行为与验证，不能当作当前策略或新策略的动态通行验收。

# 本轮仿真适配交付

所有改动在 `test`，原navigate、原navigatiosim2和原启动方式不覆盖。原NMPC源码、数学模型和求解器保持原样；测试副本仅在状态机/执行适配层增加S点策略与运行参数接口。

## 行为与参数

- 新增 `chassiss` 仍与实体chassis同原点，仅跟底盘yaw且保持水平；原fake定义不变。
- NAV默认地面反向目标各50°/s；平地云台关节需要约100°/s。实际角速度由真实姿态和关节反馈计算，受执行器动态影响，不宣称始终精确50。
- 修复普通NAV时“底盘暂时不转，云台也跟着不转”：底盘和枪口各自以地面为参考取±50°/s目标；云台关节速度根据底盘**实测**地面角速度补偿。旧实现错误地把云台地面目标设置为底盘实测角速度的反号，因此底盘实际转速为零时云台命令也为零。
- A按正式事件请求下降；S才选最近底盘面并对准，S之前不再提前1.5m锁定。对准/变形允许平移，E前必须低位确认、角误差≤0.05rad、两者地面角速<0.1rad/s连续0.2秒。未完成则使用E上游停车边界，不能违规放行。
- E前停车余量0.45m，制动预算1.5m/s²、延迟0.1秒。S—E为0.5m时，S处可用停车距离仅0.05m，因此接近S的速度上限通过原制动预览计算，约0.265m/s，不固定保持0.35m/s硬冲到S。
- 最后相关T/D已过、整车净空确认且无后续低姿态要求后释放对准；上部可同时恢复升高。HOLD、RECOVERY、急停禁止自动重启旋转。手动停转使用 `/rotation/stop`，明确false才解除这项锁存；故障许可仍独立有效。
- 主旋转参数在 `sim/rotation_control.yaml`；FSM参数在 `src/my_navigation/nav_bringup/config/hole_state_machine.yaml`；实际启动配置在 `sim/active_hole.yaml`。初始速度为平地/上坡2、下坡/准备/恢复0.35、坡顶0.4m/s，坡顶低速段1.5m。

## 质量、惯量与碰撞

最新下坡排查：底板厚度11→6cm、其中心相对chassis的z由−0.18085→−0.15585m；名义底面离地5→10cm，凹槽上面16cm、最上面20cm保持不变。SDF视觉/碰撞和RViz URDF同步，轮系与安装不变。详情见[下坡排查](DESCENT_DIAGNOSIS.md)。

底盘20kg，保留原重心，原底盘惯量张量按20/12同比缩放。云台本体恢复原0.8kg、原COM `(0,0,0.125)`、`Ixx=Iyy=0.0087,Izz=0.000001kg·m²`；yaw关节恢复原限矩100、限速20，控制参数沿用原定义。升降滑台0.15kg。雷达恢复原0.005kg及圆柱惯量，按用户要求仅保留外观，无碰撞体。

原本体极小yaw惯量用于减小仿真反作用。雷达偏轴等仍有惯量贡献，整车不是严格零耦合系统。新增60cm碰撞包络与升降也意味着不能承诺与旧复杂外形的所有接触/爬坡结果完全相同。

## 文件清单

| 文件 | 作用 |
|---|---|
| `scripts/generate_sim.py` | 20kg简化模型、原轮组、小惯量云台、无碰撞雷达 |
| `scripts/generate_world.py` | 原世界/原出生点、生成测试参数、加载显式保存的调参、RViz mesh URI |
| `sim/rotation_control.py` 与 `.yaml` | 地面yaw解算、反向旋转、对准与停转控制 |
| `sim/sim_bridge.py` | chassiss、真实反馈、导航/键盘唯一输出仲裁、升降 |
| `sim/keyboard_console.py` | 原按键接口、轻量终端、参数选择/增减/保存 |
| `sim/plan_markers.py` | 从正式计划生成六个大字母、小注释和引线 |
| `sim/crest.rviz` 与 `execution.rviz` | 修正MarkerArray的Topic属性、显示chassiss |
| `src/my_navigation/nav_components/src/slopehole_ros_adapter.cpp` | S触发、E许可、转速反馈和旋转禁止信号 |
| `src/my_navigation/nav_components/src/hole_runtime_tuning.cpp` | 仿真运行调参接口，调用原NMPC公开数值参数 |
| `src/my_navigation/nav_components/src/slopehole_controller.cpp` | 仅新增受限数值更新入口，保留通行上下文 |
| 对应头文件、CMakeLists/package.xml | 适配声明与rcl_interfaces依赖，均为test副本 |
| `map/hole_passages.yaml` | 两个原0.1m物理侧范围改0.5m，原地图不动 |
| `scripts/run_case.py` 与 `start_demo.sh` | NVIDIA界面、终端控制、进程与内存管理 |
| `scripts/runtime_support.py` | 转发原导航日志、保存面板最近输出、收养并清理本次全部后代进程 |
| `scripts/stop_demo.py` | 精确清理旧版启动留下的测试残留，原工程进程不处理 |

## 在线调参接口

`/hole_runtime/set_parameters_atomically` 使用现有 `rcl_interfaces/srv/SetParametersAtomically` 类型，未新增msg。

允许字段：`flat_speed/boost_speed/minimum_entry_speed/minimum_slope_speed/prepare_speed/restore_speed/max_linear_accel`。每批先验证再提交。速度范围 `(0,3.5]`，两个minimum字段还允许0关闭，且门限加滞回不能超过boost_speed；加速度范围 `(0,100]`，均仅用于仿真。速度提高时同步原NMPC最大速度；加速度同步原NMPC实际参数和FSM进度预算。事件位置、通行UID、机构请求号、已触发事件和进度不因调参清空。

不能通过手改巡航参数替代这个入口：巡航值仍会被状态机每周期更新。制动参数不随加速度改大。保存使用单独的 `save=true` 请求，原子写到测试目录；生成脚本在下次启动读取它。

## 验收证据

- `results/model_geometry.json`：20kg/0.8kg/惯量、原轮组、低姿态约24.55cm、无雷达碰撞。
- `results/rotation_smoke.json`：此前20kg实际舵轮旋转同时平移、停转反馈、对准和TF检查通过；本次云台目标速度修正后，用户正在运行的仿真占用了独占锁，尚未重跑这项物理验收。
- `checks/rotation_ground_rate.py`：固定底盘实际转速为零时仍要求云台地面目标−50°/s；修复前失败，修复后通过，并检查停转许可优先。
- `results/live_controls.json`：真实在线3m/s与10m/s²参数生效、非法批次拒绝、默认反向旋转反馈、正式六字母与RViz订阅通过。
- `results/rviz_letters.png`：实际NVIDIA RViz窗口截图；不是根据消息数宣称界面通过。截图检查期间暂停了世界。
- `results/manual_controls_smoke.json`：键盘话题实际驱动模型约0.91m，显式保存通过；验证后恢复原有调参文件。
- `checks/rotation_entry.cpp`：E许可正/反例和调参保留通行/请求；`preview_boundary.cpp`：S前制动边界；`keyboard_commands.py`：真实按键回调；`marker_retention.py`：点与六字母消息。

完整上下坡/过洞仍需单独验收，不能用暂停状态下的路径截图代替。启动与按键见 [START_DEMO.md](START_DEMO.md)。

最新退出/日志验证：`results/runtime_session.json`是实际无图形Gazebo＋navigate＋交互终端检查，导航日志、FSM名称、V切换和连续Ctrl+C通过，8个本次后代进程全部退出。`results/runtime_cleanup.json`另外验证启动器已退出、后代另建session且忽略SIGINT/SIGTERM的强制收尾，以及不影响无关进程。没有为这次检查启动GPU渲染；RViz使用同一进程管理入口，但这次实际退出检查未启动GUI。

`results/standalone_shutdown.json`验证另一种实际用法：后台启动仿真、另开独立键盘终端，键盘连续Ctrl+C后，9个测试管理器/节点全部退出。独立键盘同样转发导航文件日志、显示FSM名称；ROS context已关闭时不再发布停车消息。清理工具优先让管理器收尾，避免重复SIGINT打断节点析构。`results/marker_shutdown.json`确认六点程序正常中断无错误堆栈。

旋转模式在终端面板显示，也通过`/rotation/mode`发布。`NAV_AUTO`表示请求连续反向旋转；`HOLE_ALIGN`表示S后对准；`HOLE_SAFETY_STOP`表示HOLD/恢复/失败等安全停转；`MANUAL_STOP`表示键盘停转锁存；`KEYBOARD`表示K手动模式；`WAIT_FEEDBACK`表示实际位姿或关节反馈未及时到达；`COMMAND_ZERO`表示收到显式零旋转目标；`INVALID_ORIENTATION`表示倾角过大无法安全解算。模式表示控制器决定的**目标**，实测地面角速度仍以`/rotation/feedback`为准。发生“不转”时先看模式，再比较两者实测角速度；不要仅凭图像猜测状态机已经退出或电机没有动力。

本轮对用户当前正在运行的旧节点只读采样2.5秒：FSM=`NORMAL/CONTINUE`、安全禁止=false、无洞口对准；底盘角速度指令中位数+0.8727rad/s，实测底盘+0.9024rad/s、枪口−0.8941rad/s。这说明该窗口的普通NAV自动旋转正常，不代表每个时间点都正常。用户退出并重启仿真前，新Python控制代码不会进入已运行的进程。
