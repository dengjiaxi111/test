# A点同步准备与连续低速补速判定

日期：2026-10-23。仅修改`test`。没有改原`navigate`、`navigatiosim2`、`navigation2026`，没有修改NMPC优化模型、求解器、机器人模型、摩擦或电机参数。

## 已确认并实现的行为

- 到A进入PREPARE，同周期发布入口对准目标、发出LOW请求。停止连续自旋，对准与下降并行，不等待S，也不等待对准完成后才发LOW。
- PREPARE不再设置独立准备速度，继续普通NMPC速度策略；仍受普通速度上限、曲率、终点和停车保护约束。
- 未确认LOW和严格入口对准都完成前，保留E上游停车边界；速度安全则保持原策略，无法保证停车时提前减速，必要时停车等待。
- 初次LOW完成、方向与角速度连续稳定后，按本次通行UID保存入口许可。取得许可后直接执行，越过停车决策边界后不会因坡面引起的角度/角速度短时波动重新挂回停车线。入口事件、速度约束、补速准入和紧停解除共用这一许可。
- 正常入口紧急制动只停平移，不禁止对准和LOW。平移连续停稳、LOW完成、入口对准同时满足后解除紧停。HOLD、故障、退让仍禁止旋转。
- 达到最低速度即清除补速无效计时；达到更高交还线且稳定后才交回普通控制。两条判据相互独立。

## 停车逻辑的具体计算

每周期以当前正式路径弧长计算：

```text
停车位置 = E.arc - entry_margin
d = max(0, 停车位置 - 当前弧长)
b = braking_deceleration
τ = control_latency
安全速度上限 = -b*τ + sqrt((b*τ)^2 + 2*b*d)
允许速度 = min(普通速度上限, 安全速度上限, 其余有效约束)
```

它来自`v*τ + v²/(2*b) ≤ d`，不增加固定的准备低速。A前也会把尚未就绪的入口停车边界预告给NMPC，避免高速到A才发现停车空间已不够。例如当前b=1.5m/s²、τ=0.1s，距停车点1.05米时上限约1.63m/s，0.35米时约0.89m/s，0.1米时约0.42m/s。

不假定机构一定能在0.7秒内完成，也不按固定等待时间伪造完成。0.7秒只是现有桥接器下降参考轨迹的时长；放行依赖实际机构完成反馈与实时旋转反馈。没有可靠完成时间预测时，使用“始终还能在入口前停住”的保守包络。

如果实测速度的反应＋制动距离已超过剩余距离（保留现有3cm数值余量），核心输出紧停；停车期间LOW请求和对准目标继续存在。LOW完成不能单独解除紧停，仍需平移稳定停止和入口对准许可。

如果尚未经过的A位于停车边界之后或过近，预览制动会阻止机器人触发A。因此接纳计划时校验`A.arc + event_tolerance < E.arc - entry_margin`，否则明确报出“增加prepare_path_distance或减小entry_margin”的配置错误。A已经在路径之前/当前已到A的剩余任务可立即准备，不按这个未来触发点规则拒绝。

初次入口许可仍要求匹配当前请求身份、修订和时效的LOW完成反馈，以及底盘/云台对准停转连续确认。许可取得后，E检查保留本次许可，不再要求角速度每帧重新稳定。未获许可实际越E不会发布进入成功事件；持续异常满HOLD期限将终止，不再反复提前返回而无限等待。真实LOW反馈过期或故障仍停车；新动作、需求变化、通行完成、任务关闭和退让重入清除许可。同请求重发、在线速度调参、保持身份的同路线重规划保留许可，其他通行UID不能继承。

## 2026-10-23 后续两项修正

同时修正NMPC速度反馈和LIO定位缓存：两者共用`TimestampedSampleCache`，维持现有10ms未来时间容差。超出容差的时间戳、过旧、重复和乱序帧被丢弃，不覆盖上一有效帧，也不刷新其接收时间。控制计算仍同时检查源数据年龄和接收年龄，旧帧真正过期后照常停车。错误坐标系、非有限速度或非法姿态维持原先的立即判无效策略。

本轮没有改变补速超时在STOP期间的计时行为，也没有改变Omni求解器、地图代价阈值或机器人动力学。构建及九项非ROS检查通过；完整Gazebo上下坡尚未验证，当前工具环境的ROS网络访问受限。详细检查记录见`results/entry_permission_fix/verification.json`。

## 最低速度检测与接管

当前实现没有新增坡脚前助跑检测区；A/S/E是洞口准备和路径事件，并不等同真实坡脚。

1. 最终路径逐段与坡面多边形求交，得到带上坡方向的实际区间。
2. 真正进入上坡后，坡脚之后的起始0.2米（默认entry_zone_length）使用minimum_entry_speed，其后使用minimum_slope_speed；不包含坡面外的上游区域。
3. 使用实测平面速度与正式路径切向点乘，得到沿坡前进速度；横滑不当作足速，倒滑为负值。
4. 在LOW就绪、通行许可、反馈新鲜、普通控制器健康、无停车边界等条件满足时，持续低于门槛0.3秒才接管。任一许可失效撤销并重新确认。
5. 接管指令沿当前路径切向，以boost_acceleration爬升到boost_speed；候选另做反应距离、制动距离、路径直线一致性和地图可行性检查，检查不通过保留普通候选。
6. 实测达到minimum时，清除连续低速的失败计时。位于`[minimum, minimum+margin)`继续接管，不因总接管时长超过2秒失败。
7. 连续达到`minimum+speed_recover_margin`满speed_recover_confirm后交回；再次低于minimum，从本次跌破重新计时。连续不足达到boost_timeout才判接管无效。

例如当前保存值minimum=1.9、margin=0.1、boost=2：实测1.95可持续接管且不失败；实测2.0稳定0.3秒后交回。普通控制器的保护减速、HOLD或停车边界不会被补速抬高。

本次没有取消补速原有准入检查，也没有修改普通NMPC在静止实测反馈下的起步指令生成。A提前准备可解除此前准备互锁，但不能仅凭本次修改宣称全部上坡困难已经消失。

## navigation2026对照（仅只读检查）

`navigation2026`的StairController针对台阶/飞坡，与本次低姿态坡洞准备不同：

| 项目 | 当前test | navigation2026飞坡代码 |
|---|---|---|
| 触发依据 | 真实上坡区间内实测前进速度不足 | 与飞坡特征的距离 |
| 准备 | A同步对准与降低，E前要求实际完成 | 2.75m进入PRE_ALIGN，2m进入COMMIT；1.5m并行抬腿和固定速度 |
| 特殊速度 | 持续低速后才接管，斜率增加到boost_speed | 默认参数在1.5m内覆写固定2m/s，未比较最低实测速度 |
| 交还 | 足速加滞回稳定确认，或离开检测/许可范围 | 越飞坡中心线0.72m后VERIFY、退出特殊段 |
| 默认启用 | test坡洞FSM开启，minimum默认0关闭、保存值可能覆盖 | 常规nav_params.yaml的enable_fly_slope_layer=false，默认不触发飞坡识别 |

位置：`navigation2026/src/my_navigation/nav_components/src/stair_controller.cpp:734`、`:813`、`:1107`，配置`nav_bringup/config/nav_params.yaml:85`、`:179`。其腿长检查在反馈缺失/过期时会直接视作通过；当前myserial未找到完整对应接线，因此不能当作真实变形完成验证。它也要求普通NMPC处于RUNNING才执行特殊地形覆盖。

## 文件与参数迁移

- `src/my_navigation/nav_components/src/slopehole_controller.cpp`：A立即LOW、普通准备速度、入口异常期限、紧停解除和A/停车线校验。
- `src/my_navigation/nav_components/src/slopehole_ros_adapter.cpp`：A开始对准、移除准备固定限速/限速区、预告停车包络、正常入口制动不冻结对准；状态/决策/原因变化写入NavServer日志。
- `src/my_navigation/nav_core/include/nav_core/slope_speed_takeover.hpp`：连续低速计时与交还确认分离。
- 删除prepare_speed控制字段和在线调参入口；旧YAML字段兼容读取但忽略，旧保存文件生成时明确忽略；不影响其他保存参数。键盘改为1～6，5是恢复速度、6是NMPC加速度。
- 机构恢复速度及原有恢复/退让行为保持，未修改物理参数。

## 验证与限制

构建：`bash test/scripts/bounded_build.sh nav_core nav_components`通过，安装产物已更新。

通过的C++检查：rotation_entry（A立即LOW、无固定准备限速、LOW/对准双条件、紧停释放、E异常期限、A/停车线配置冲突）、minimum_speed_takeover（1.95持续足速不失败、再掉速重新计时、2.0稳定交还、旧期限边界）、preview_boundary、tunnel_residence、ordinary_progress、connector_progress、projected_progress，以及核心test_slopehole_controller。

Python键盘按键/批量输入检查和模型3世界生成通过；相关Python语法及生成配置检查通过。

新增`checks/prepare_at_a_ros.py`用真实NavServer、TF和受控机构反馈验证“A到S之前就同时发布LOW/对准，紧停不冻结对准”。该检查在本执行环境中被ROS UDP socket/getifaddrs的Operation not permitted阻止，未取得通信结果，不能记为通过。此环境未完成Gazebo动态上下坡验收。

本地具备ROS通信权限时可执行：

```bash
source /opt/ros/jazzy/setup.bash
source test/install/local_setup.bash
export LD_LIBRARY_PATH="/home/dengjiaxi/dependency/acados/lib:${LD_LIBRARY_PATH:-}"
ROS_DOMAIN_ID=176 ROS_LOCALHOST_ONLY=1 /usr/bin/python3 test/checks/prepare_at_a_ros.py
```

该脚本使用隔离ROS域和受控反馈，不运行Gazebo，也不是物理通行验收。
