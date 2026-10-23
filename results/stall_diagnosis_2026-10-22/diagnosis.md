# 2026-10-22 test 停车与失败诊断

范围：用户 23:23:51 截图、最近九次 NavServer 会话、对应桥接日志及最新完整 `demo.json`。本次仅调查、离线复现、保存证据；未修改控制代码、运行参数或重新启动仿真。时间均为北京时间。证据副本在 `snapshot/`，哈希见 `snapshot_sha256.json`。

## 结论与证据强度

1. **确定：存在准备流程的紧停互锁。** 真实 C++ 状态机和 Python 旋转控制均已离线复现。截图中的 PREPARE/STOP、emergency waiting 正好是该互锁的输出。截图对应会话先对准 0.58 秒就安全停转，此后直到退出没有恢复，强烈支持该解释；旧日志未保存 LOW 请求和反馈，不能声称逐帧证明了截图中所有内部条件。
2. **确定：最新 23:52 任务被键盘模式屏蔽。** 235 个导航期间采样全部处于 KEYBOARD，其中 230 个导航平移命令非零，但最终底盘平移命令全部为零。随后三个 8 秒无进展周期耗尽恢复次数。与截图那轮不同。
3. **强证据：另外至少三次失败是进入安全停车后约 5 秒终止。** 与 HOLD 的 5 秒期限吻合，但首次触发 HOLD 的具体原因没有持久记录，不能逐次归因。
4. **确定：所查近期任务均规划出路径，平滑正常结束。** 23:26 一次 NMPC 综合校验失败警告需要单独看待；它解释不了其他没有该警告的失败，更不能解释已证实的命令仲裁屏蔽。

## 最近会话时间线

| 10 月 22 日 | 现存记录 | 可以得出的结论 |
|---|---|---|
| 23:05:35 普通目标 | nav_server_13320，第 38–49 行 | 23:05:51 成功；同会话后续过 B2 失败 |
| 23:13:02 过 B2/A2 | nav_server_16710，第 67–72 行 | 有一次 RECOVERY，23:13:42 直接失败；具体 reason 缺失 |
| 23:17:31 过 B2/A2 | nav_server_18380，第 79–82 行；bridge python3_18068 第 3 行 | 23:17:38 安全停转，23:17:43 失败，间隔 4.9998 秒；此前普通导航成功 |
| 23:20:34 过 B2/A2 | nav_server_20216，第 57–60 行；bridge python3_19905 第 5–6 行 | 先对准约 12.74 秒，再安全停转，约 5 秒后失败；不能仅凭该时长断言机构准备超时 |
| 23:22:56，截图对应 | nav_server_21673，第 56–57 行；bridge python3_21362 第 4–6 行 | 已切回 NAV；23:23:01.650 对准，23:23:02.230 安全停转；23:24:46 进程收到结束信号；本会话未记录 FAILED |
| 23:26:08 目标 | nav_server_23165，第 45–59 行；bridge python3_22834 第 3–5 行 | 开始仍 KEYBOARD，8 秒无进展后才回 NAV；重规划后有一次 NMPC 综合校验失败；随后安全停转 4.9878 秒后失败 |
| 23:28:39 过 A1 | nav_server_24457，第 45–48 行；bridge python3_24156 第 4–5 行 | 已切回 NAV；安全停转 4.9939 秒后失败；无 NMPC 失败警告 |
| 23:52:23 过 A1 | nav_server_41018，第 45–71 行；bridge python3_40708 第 3–4 行 | 始终 KEYBOARD，三轮各约 8 秒无进展，两次重规划成功，恢复计数达 3 后失败 |

原始文件均在 `snapshot/test/logs/ros/`。表中的编号是进程 PID，完整文件名含启动毫秒时间戳。

## 截图对应的准备紧停互锁

真实控制链如下：

```text
首次 LOW 必须等底盘、云台对准并停转
  → 尚未对准时出现制动距离不足，设置 emergency
  → emergency 发布 hole_rotation_inhibit
  → 旋转控制进入 stop，保持当前朝向，停止追踪入口对准目标
  → 对准不能完成，首次 LOW 无法发出
  → emergency 解除又要求停稳且 LOW 已完成
  → 持续 PREPARE / STOP，等待不能发生的条件
```

对应源码：

- `test/src/my_navigation/nav_components/src/slopehole_controller.cpp:299`：首次 LOW 等 `entry_rotation_ready`。
- 同文件 `:343`：需要的反应及制动距离超过剩余停车距离时触发 emergency；`:340` 只有平移停稳连续 0.2 秒并且 LOW 完成才解除。
- `test/src/my_navigation/nav_components/src/slopehole_ros_adapter.cpp:176`：emergency 原因发布旋转禁止。
- `test/sim/sim_bridge.py:180`：旋转禁止优先于入口对准。
- `test/sim/rotation_control.py:38`：stop 模式锁当前朝向，而非继续追踪洞口目标。

首次 LOW 尚未发出时，12 秒 `prepare_timeout` 未启动；emergency 的等待同时暂停普通 8 秒无进展计时。因此截图这类卡住**不一定会自行 FAIL**，这与几次停车后 5 秒失败是不同分支。

离线使用真实状态机源码的结果，源文件保存在 `emergency_repro.cpp`：

```text
SCENARIO 0: 首次 LOW 前尚未对准
t=0     PREPARE/STOP emergency braking distance insufficient request=0
t=0.02  PREPARE/STOP emergency stop; waiting for stopped and prepared request=0
t=120   PREPARE/STOP emergency stop; waiting for stopped and prepared request=0

SCENARIO 1: LOW 已发送，无应答
t=1.02  HOLD/STOP structure acknowledgement missing
t=6.02  HOLD/FAILURE structure acknowledgement missing

SCENARIO 2: LOW 持续 EXECUTING，无完成
t=12.02 HOLD/STOP preparation timeout
t=14.02 HOLD/FAILURE no stopped/retry confirmation

SCENARIO 3: 0.82 秒收到 LOW 完成
t=0.82 TRAVERSE/CONTINUE low posture confirmed
```

复现编译命令，在仓库根目录执行：

```bash
g++ -std=c++17 -O2 -Itest/src/my_navigation/nav_components/include -Itest/src/my_navigation/nav_core/include test/results/stall_diagnosis_2026-10-22/emergency_repro.cpp test/src/my_navigation/nav_components/src/slopehole_controller.cpp -o /tmp/seu_fsm_emergency_repro
/tmp/seu_fsm_emergency_repro
```

真实 Python RotationControl 对比：入口目标 0 rad，底盘 0.4 rad、云台 0.8 rad，在不禁止旋转时输出 `(-1.2, 2.3124)`，禁止旋转时输出 `(0, 0)`。这证明对准等待被锁住的方向。

## 最新一轮：导航与键盘控制权没有交接

最新 `demo.json` 对应模型 3、手动会话，不能当作截图那轮的 trace。

- 119.301–145.701 仿真秒：235 点均为 KEYBOARD，230 点导航命令非零，最终平移命令 235 点全零。
- 导航候选速度最高 0.20 m/s，车体仅漂移 0.02275 米。
- 最终命令最大采样年龄 0.048 秒，真值里程计最大年龄 0.022 秒；无升降动作，lift 约 0.29688 米，横滚及俯仰绝对值低于 0.004 rad。
- 120.081 秒样本在快照 `demo.json:91465`：导航命令约 `(-0.0383, -0.0127)`，KEYBOARD，最终命令 `(0,0,0)`。
- 145.821 秒才切 HOLE_SAFETY_STOP，表明最新这轮安全停转是失败后的结果，不能倒过来当最初原因。

`sim_bridge.py:165` 仅在 navigation 模式转发导航；键盘模式采用键盘输入。`keyboard_console.py:80` 只有 K/N 切模式，RViz 发目标没有自动交接逻辑。因此重规划成功也不会解决控制权问题。

## 速度、旋转与物理链

截图可见准备速度 3.05 m/s、恢复速度 2.05 m/s、最低速度 1.9 m/s、NMPC 加速度 10 m/s²；最新保存配置相同。示例准备及恢复速度为 0.35 m/s。历史每次启动未独立保存配置，不能将最新值冒充所有历史值。

S→E 常为 0.8 米，扣掉 `entry_margin=0.45` 后只有 0.35 米停车窗口。按照当前制动 1.5 m/s²、延迟 0.1 秒，模型的 `v*0.1 + v²/(2*1.5)`：

| 实测平移速度 | 反应＋制动距离 |
|---|---:|
| 0.35 m/s | 0.076 米 |
| 0.8 m/s | 0.293 米 |
| 1 m/s | 0.433 米 |
| 2 m/s | 1.533 米 |
| 3.05 m/s | 3.406 米 |

若在 S 仍未准备完成且只有上述窗口，实测约超过 0.928 m/s 就满足紧停判断。控制器存在提前制动预览，设置准备上限 3.05 **不表示实际一定以此速度到 S**；它是风险放大因素，不能仅凭配置定为每轮首因。

当前 `auto_spin_dps=60` 是地面角速度 °/s，并非轮子 RPM。最新自动自转初始 2–13 秒实测底盘中位 61.68°/s、云台地面 −59.98°/s，目标基本跟上。把 100 改成 60 无法消除控制权屏蔽和互锁；自转可能通过对准耗时、舵轮切换和滑动影响触发时机，尚未完成不同速度的同路线动态对照。

停止时部分轮/舵关节仍有 2–5.7 rad/s 抖动，而车体约 0.001 m/s，提示接触/电机闭环还有次要问题；不能把轮速当作车体前进速度。没有 contacts 记录，历史轮碰墙、底盘刮擦、滑移尚不能排除。

## 规划、平滑与 NMPC

- 各轮规划均进入 CONTROLLING，接入报告 `FEASIBLE_APPROACH_CONTINUOUS`、`平滑后备原因=none`。最新总规划约 171 ms，B 样条优化 7 次迭代约 0.24 ms。
- `IMPROVEMENT_BUDGET_EXHAUSTED` 指找到可行路径后停止继续改进；其后正常进入控制，不等于规划失败。
- 23:26:21 一次 `Omni solve/constraint/map check failed; ramping to stop` 是真实异常；`nmpc.cpp:421` 对求解、约束及预测地图校验的任一失败都统一打印它。不能仅凭这条认定 acados 不收敛。
- 具体候选包括 ESDF 无效、非有限状态/输入、速度或加速度范数越限、动力学一致性不通过、预测轨迹碰到占据区。近期未见 acados 非零 status 或范数检查专用警告。需保存首次失败的细分原因及输入才能确定那次。
- 没有求解警告不代表 NMPC 的行为已被全部验证：求解成功仍可能给近零速度，参考速度还受状态机 cruise、曲率、终点制动限制。STOP 分支仍执行计算但丢弃候选，真正下发零速度（`nav_server.cpp:1416`）。
- 最新轮虽存在较低导航候选速度，最终命令被控制权屏蔽已是充分的直接停车原因；不必推断求解器卡死。

## 其余可触发停车/FAIL 的分支及证据缺口

| 层 | 可能触发条件 | 本次能否逐轮确认 |
|---|---|---|
| 路径/地图 | 路径失效、动态障碍物、预测轨迹不安全 | 无近期路径失效日志；23:26 综合校验失败待细分 |
| 进度/定位 | 位姿过期、定位跳变、S→T 横偏超过 0.15 米、倒滑超过窗口、投影歧义 | 可导致 HOLD；旧状态 reason 和原值没有保存 |
| 机构 | LOW 无应答、执行超时、完成后离开位置带、取消后未停稳或重试耗尽 | 离线复现了计时分支；旧日志不能判断哪一次实际发生 |
| 停转/对准 | 反馈过期、角速度未稳定、朝向误差未满足 | 截图的互锁已复现；首次对准没有独立期限 |
| 速度/过洞 | 补速 2 秒无效、洞内驻留 15 秒、洞外无进展、通行截止 | 当前最低速度 1.9 已启用；旧日志不能据此证明曾触发补速 |
| 发布许可 | gate 拒绝、位姿年龄不合格 | `publishMotion` 会静默停车；旧日志未保存该层拒绝原因 |
| 模式仲裁 | KEYBOARD 输入优先、手动停转未解除 | 最新轮 KEYBOARD 屏蔽已确证；截图轮已切回 NAV |
| 物理 | 撞墙、刮擦、侧滑、转向/电机抖动、关节不到位 | 最新轮全零命令不需要这些解释；其他轮未排除 |
| 时钟/算力 | Gazebo 暂停或变慢、回调超过 0.1 秒、反馈陈旧 | 普通 8 秒使用墙钟而 FSM/反馈用仿真时间，存在混用风险；未发现足以定因的性能/实时率记录 |
| 进程 | bridge/fake/conversion 异常退出 | 最新 traceback 无时间戳，可能发生在关闭阶段，不能判为停车首因 |

几个直接 FAILED 的会话，`nav_server.cpp:1411` 接到坡洞 FAILURE 后不打印具体 reason；reason 只发布 topic。`RuntimeLogs` 只保留内存最近 10 行和终端输出；`run_case.py` 每轮以写模式覆盖 `demo_*.log` 和 `demo.json`，因此旧 FSM 转移/原始反馈丢失。独立 ROS 日志保留了节点日志，才得以恢复上表部分时间线。

截至本次，可确定控制问题并复现，但**不能据现存日志宣称所有历史轮的首次异常已查清**。

## 待确认的后续工作

优先补齐按会话归档的 FSM reason、模式、LOW 请求及反馈、最终指令、NMPC 细分失败、输入年龄、ROS/墙钟时间；随后分别验证控制权交接、入口准备及紧停恢复，最后才进行相同路线的 50/60/100°/s 对照。

入口紧停的处理必须区分停车边界前可安全原地对准与洞内/碰撞风险，不能直接取消安全停转。准备流程应有明确期限和终止原因。平滑、NMPC 权重和轮胎参数需保持可比较，依据新记录决定是否调整。本次尚未实施这些行为修改，待与用户确认。
