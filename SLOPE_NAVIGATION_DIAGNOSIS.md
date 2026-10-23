# 坡洞导航诊断与修改记录

> 本文记录此前排障过程。当前已按用户新要求取消地形分段限速，新增条件补速与区域驻留恢复，见 [SLOPE_CONTROL_ARCHITECTURE.md](SLOPE_CONTROL_ARCHITECTURE.md)。本文旧运行参数和结果不代表新架构动态验收。

日期：2026-10-22。范围：隔离工作区 `test`，2026 场地副本，三模式模型中的模式 2 为主要闭环诊断对象。

**截至本记录写入时，尚未通过完整上坡—连接段—下坡验收。** 已观察到 B1 通行事件与姿态恢复完成，随后继续到 A1；A1 的底盘与实体侧壁接触，车轮转动而车体无法沿路线前进。不能把“起步不再报错”“单次 B1 通过”或纯 C++ 检查通过表述为全闭环通过。

## 修改范围与边界

- 本轮未修改 `navigate` 原工程源码。此前已完成的地图占据阈值 99 修改属于前一轮；本轮以诊断目录的 `navigate_before.diff` 记录为基线。
- 本轮状态机修改位于 `test/src/my_navigation`；模型、桥接与参数修改位于 `test/sim`、`test/scripts` 及相应隔离配置。
- 本轮未修改 NMPC 算法源码或 acados 模型/求解实现，**但确实调整了仿真 NMPC 参数**。参数变化会改变控制效果，不能宣称速度求解的运行行为完全未变。
- 质量与惯量未因本轮摩擦和轮速增益调整改变；详见 [模型参数逐项对比](results/slope_diagnosis/model_physics_changes.json)。模式 1 的原物理模型不应被当作模式 2、3 的改动对象。

## 已查明的失败链

| 问题 | 实际原因与表现 | 处理与证据 |
|---|---|---|
| 规划成功后起步报 NMPC 综合失败 | 前一轮已查明：规划器按膨胀代价 99 验收，NMPC 使用另一阈值，导致求解后的预测地图检查拒绝路径。这不是所有后续失败的统一原因。 | 已有 99 修复；当前仍需分别观察状态机原因、求解输出和实际运动。 |
| 普通路径也进入 `unreliable progress/localization jump` | 状态机把洞内 `.15m` 横向门限用于整个计划，包括完全没有坡洞的路线。原导航普通路径有自己的偏离重规划规则。 | 无坡洞计划保留位置/速度有效性与实际位移检查，普通跟踪误差交由原控制器处理。[用户修改前运行](results/slope_diagnosis/user_demo_before.json)。 |
| 小回滑被当成定位跳变 | 事件进度 `progress_` 只增不减，却用它与本次投影作“单采样位移”比较。累计回滑 `.07m` 可能超过单周期可达量，即使每次只回滑 `.01m`。 | 新增 `last_projected_arc_`：采样跳变与前一次投影比较，事件进度仍单调，不撤销或重复事件。接受新计划和退让交接同步初始化。 |
| 后退窗口无法及时拒绝慢速越界 | 搜索下界直接夹在 `progress_-backward_window`，投影结果不可能小于该下界，使显式后退检查失效。 | 搜索下界额外覆盖一帧可达量，再显式检查原 `.15m` 后退窗口。缓慢回滑 `.16m` 现在被拒绝，`.07m` 仍允许。 |
| B1 完成后连接段仍误报定位跳变 | 计划包含后续 A1，因此仅对“空通行列表”放宽普通跟踪限制不足；B1 与 A1 之间的普通连接段依然被 `.15m` 门限拦截。 | 严格投影约束限定到未完成通行的 S—T 范围；上一或当前投影处于该范围均严格检查。未知端点范围保守处理。所有区域继续检查源数据时效与真实单周期位移。[修复前 B1 完成后的失败](results/slope_diagnosis/entryslow_model2_lower.json)。 |
| 对准许可瞬间成立后又高速逼近 E | S 开始对准与低姿态完成不等于整个 S—E 段可以立即按坡段目标速度加速。曾出现制动距离不足或越过 E 时停转许可不成立。 | 测试适配层在 E 尚未发出前持续保留 S—E 准备限速和停车预告，E 后再交给坡段限速。没有取消低位/对准/停转检查。[早期许可失败](results/slope_diagnosis/mu08_navigation.json)。 |
| 手动提高到 3.5m/s 也上不去 | 手动指令绕过 NMPC，其目标速度不是地面实测速度；低摩擦、驱动跟踪、托底/接触约束仍会限制运动。单独提高 NMPC 上限不能证明轮胎有足够牵引。 | 分别进行了摩擦、加速度/代价、驱动增益及接触记录对照。不能把尚未定位的 A1 卡碰直接归因于功率不足。 |
| A1 入洞后仍不动 | B1 完成，A1 已发出 E，随后底盘在侧壁处受力并停住，约 8 秒后进入 `motion blocked/controller unavailable`。轮子仍转，故单看速度指令会误判为求解器问题。 | [有效接触诊断](results/slope_diagnosis/contacts_fixed_model2_lower.json)记录底盘和场地接触，侧壁接触点世界坐标约 `(9.434,4.234,0.767)`，对应地图 x≈-5.066；若干采样接触力超过 100 N。侧壁并非残留洞顶。 |

首次接触诊断的 0 条结果来自桥接话题写错：Gazebo Contact 系统使用完整作用域话题。修正 [contact_diagnostics.py](scripts/contact_diagnostics.py) 后，用独立短时地面接触探针确认 ROS 能收到轮胎/场地接触，再复现 A1 的底盘侧壁接触。最初的 [零数据记录](results/slope_diagnosis/contacts_model2_lower.json)不能被解释成“没有碰撞”。

测试地图的 A1 洞轴 x=-4.6935 m；Gazebo 场地两侧壁内侧约 x=-5.0665/-4.2665 m，实体中线 x=-4.6665 m，二者偏 0.027 m。曾只把 `test/map/terrain.yaml` 的 A1 低净高多边形向右移动 0.027 m：B1 仍通过，但 A1 改在右侧受阻，最终坐标约 (-4.581,-3.599) m，故单独校准地图也未解决横向摆动；已撤回该试验改动。原测试地图还有待与场地整体配准核对。

S、E 等字母是正式路径上的事件位置，不是新增控制状态。事件推进保持单调，退让使用独立执行阶段；本轮没有把普通导航恢复动作解禁为洞内任意横移/旋转。

## 当前测试参数与模型变更

实际生成入口为 [generate_world.py](scripts/generate_world.py)，运行时落到 `sim/nav_params.yaml`。后者是生成文件，不能只改它然后认为下一次启动还会保留。

| 参数 | 当前候选值 | 含义与边界 |
|---|---:|---|
| `nmpc.max_linear_vel` | 至少 `4.0m/s` | 二维平移速度上限；仍受各路段目标速度限制。 |
| `nmpc.max_linear_accel` | `10.0m/s²` | 求解器仿真加速度上限，不能作为底盘实际保证制动能力。此前测试值为 100。 |
| `nmpc.R_linear` | `1.0` | 提高控制输入代价，抑制原 `.01` 下的急剧加减速。 |
| `nmpc.contouring_weight` | `100.0` | 加强横向回到中心线；未修改原代价函数结构。 |
| `nmpc.esdf_safe_dist` | `.32m` | 本次仿真软障碍净距；原 `.5m` 软目标与 `.74–.90m` 通道不相容。`.32m` 也不等于整车所有朝向和坡面姿态的包络验收。 |
| 轮胎 `mu`、`mu2` | `.2 → .8` | 模式 2、3 模型轮胎摩擦参数；不是实车标定值。 |
| `wheel_kp` | `.28 → 1.0` | 模式 2、3 轮速比例增益；几何、质量、惯量未因此改变。 |
| 单轮力矩限制 | `2.0N·m`，未改 | 不能把速度目标等同于输出牵引能力。 |

模型逐字段对比包含原始快照哈希、质量、惯量、碰撞几何和关节限制，见 [model_physics_changes.json](results/slope_diagnosis/model_physics_changes.json)。该文件本身是结构比较，不是动态上坡通过证明。

## 已运行的纯 C++ 检查

以下检查直接编译 `slopehole_controller.cpp`，无需启动 ROS 或 Gazebo。相关回归先在缺陷版本触发断言，再验证修复后通过。

| 检查 | 已验证内容 | 本次结果 |
|---|---|---|
| [ordinary_progress.cpp](checks/ordinary_progress.cpp) | 无洞普通路径横向偏差与终点超出不被洞内门限误拦；洞内严格拒绝；源位姿过期、速度 NaN 仍 HOLD | PASS |
| [projected_progress.cpp](checks/projected_progress.cpp) | 每周期小回滑累计 `.07m` 不误判；单调事件不重放；缓慢累计 `.16m` 超过后退窗口仍拒绝 | PASS |
| [connector_progress.cpp](checks/connector_progress.cpp) | 完成第一个洞并恢复正常姿态后，双洞之间 `.4m` 跟踪偏差不直接 HOLD；第二洞 S—T 内相同偏差拒绝 | PASS |
| [rotation_entry.cpp](checks/rotation_entry.cpp) | 低姿态完成不替代对准/停转许可；未获许可不发 E；获得有效许可后才进入 | PASS |

示例执行：

```bash
g++ -std=c++17 \
  -I test/src/my_navigation/nav_core/include \
  -I test/src/my_navigation/nav_components/include \
  test/checks/connector_progress.cpp \
  test/src/my_navigation/nav_components/src/slopehole_controller.cpp \
  -o /tmp/slopehole_connector_progress
/tmp/slopehole_connector_progress
```

## 仿真证据与最终验收待补

| 运行 | 观察结果 | 证据 |
|---|---|---|
| 当前修改前普通导航 | 多次普通路径被状态机定位跳变分支中止 | [user_demo_before.json](results/slope_diagnosis/user_demo_before.json) |
| S—E 保持准备低速后，连接段修复前 | B1 的 E/X/T/D 已产生，随后恢复 NORMAL；普通连接段失败 | [entryslow_model2_lower.json](results/slope_diagnosis/entryslow_model2_lower.json) |
| 连接段修复后 | 继续到达 A1，但 A1 接近窄口阶段仍有跟踪偏差 | [connector_model2_lower.json](results/slope_diagnosis/connector_model2_lower.json) |
| 加强横向跟踪后 | B1 完成，A1 发出 E，之后运动阻塞；未完成下坡 | [contour100_model2_lower.json](results/slope_diagnosis/contour100_model2_lower.json) |
| 接触数据定位，模式 2 | B1 的 E/X/T/D 已产生并恢复 NORMAL；A1 已产生 A/S/E，低位关节实际到位。随后左侧壁接触，最终 x≈-4.755 m、进度≈8.744 m，HOLD，未到 X。正式计划 A1 X≈8.812 m。该次规划有 B1 上坡和 A1 下坡两个通行，仿真进程清理结果为空列表。启动日志有 NMPC 初始化信息，未出现 Omni 综合求解失败。 | [contacts_fixed_model2_lower.json](results/slope_diagnosis/contacts_fixed_model2_lower.json)、[运行日志](results/slope_diagnosis/contacts_fixed_model2_lower.log) |
| 跟踪权重单变量试验 | `contouring_weight: 100→300` 后仍在 A1 相近位置 HOLD，x≈-4.756 m；已恢复 100 | [contour300_model2_lower.json](results/slope_diagnosis/contour300_model2_lower.json) |
| 轮胎摩擦单变量试验 | 模式 2 `mu/mu2: 0.8→1.2` 后仍在 A1 HOLD，x≈-4.584 m；已恢复 0.8 | [mu12_model2_lower.json](results/slope_diagnosis/mu12_model2_lower.json) |
| 软避障单变量诊断 | 暂设 `esdf_weight=0`，A1 仍 HOLD，x≈-4.579 m；已恢复原权重 70 | [softzero_model2_lower.json](results/slope_diagnosis/softzero_model2_lower.json) |
| A1 洞轴地图校准单变量试验 | 地图中线向实体中线平移 0.027 m 后仍 HOLD，x≈-4.581 m；已恢复原测试地图 | [centeredA1_model2_lower.json](results/slope_diagnosis/centeredA1_model2_lower.json) |
| 最终模式 2 B1 上坡→A1 下坡→到目标 | **待填写最终运行及结果** | 待补 |
| 最终模式 3 同路线 | **待填写最终运行及结果** | 待补 |
| 反向 / 上部变形 / 六点显示等其他验收 | **未由本表自动证明，按实际运行另填** | 待补 |

完成标准应同时包含：导航成功结果、实际模型上下坡运动、正式计划事件及机构反馈、无违规越过 E、退出后恢复普通导航、进程正常清理。仅增加速度参数或让状态机不再报错均不足以满足该标准。

## 下一步测试计划（本轮按用户要求暂停）

1. 在模式 2 的 A1 E→X 段同步记录目标轮速、实测轮速、转向角、NMPC 世界/车体速度和底盘横向接触力，计算横向指令先出现还是墙体先施力。这能区分控制偏航、轮胎打滑与接触后的被动摆动。
2. 仅在已证实的原因上调单个测试模型或控制参数；每项都复跑 `lower --model 2`，要求 B1/A1 的 E/X/T/D 全部出现、机构下降与恢复反馈真实完成、最终导航结果成功。
3. 再跑 `upper --model 2`（A2 上坡、B2 下坡）、`lower/upper --model 3`、无洞 `flat_nav` 和模式 1 原模型运动对照，确认三种模型选择、正常导航与双洞路径没有回归；记录速度、姿态、接触、六点 Marker 和进程清理。
4. 上述闭环通过后才更新“完整上下坡/过洞已验证”的说明。2027 场地和实车的速度、制动、净空仍需各自标定。

本轮在完成 A1 洞轴单变量试验后按用户要求停止，没有运行上述后续测试。无效试验中的跟踪权重、轮胎摩擦、软避障权重和洞轴偏移已经恢复；保留了 JSON 与日志，便于下一次对照。
