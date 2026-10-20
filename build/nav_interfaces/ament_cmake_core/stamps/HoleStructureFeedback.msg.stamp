# 机构侧发往 hole_structure/feedback，导航侧接收的动作与净空反馈。
# 对应交接文档5.4、8及结构释放要求；净空、移动变形和模拟来源字段为具体补充设计。
# 真正到位/净空判断必须有真实来源；消息定义本身不测量姿态、包络或空间。
# 反馈须持续更新且与当前请求匹配；仅发一次“完成”不能永久授权运动。

# 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
std_msgs/Header header

# 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
string session_id

# 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
string goal_id

# 机构动作请求编号；新动作换号，同一个动作的消息重发沿用原编号。反馈必须回填匹配。
uint64 request_id

# 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
uint64 requirement_revision

# 本反馈所对应请求的目标姿态：0 KEEP，1 LOW，2 NORMAL；须匹配当前请求。
uint8 target

# 状态常量0：动作正在执行，不可当作准备已完成。
uint8 EXECUTING=0

# 状态常量1：所请求姿态动作已完成，仍须校验身份和时效。
uint8 COMPLETED=1

# 状态常量2：机构报告动作失败；不编码详细故障原因，当前接口仍缺细分诊断。
uint8 FAILED=2

# 本条反馈的实际执行状态0—2；仅COMPLETED可确认动作到位。
uint8 status

# 整车与相关结构的占用释放确认；不能由参考点过D直接推断。多洞时该总标志与逐洞列表的真实生成口径仍须对接明确。
bool whole_vehicle_clear

# 正常形态及变形过程包络具备所需净空；移动恢复时须持续成立，不能只确认一次。
bool normal_clearance

# 真实机构侧确认当前动作允许伴随底盘移动；不单凭此值授权运动，未知/false应停车等待。
bool moving_transition_supported

# 可解除结构占用的通行编号列表；解除洞1不能顺带清除洞2需求。须与整车/净空标志共同解释。
string[] cleared_traversal_uids

# 测试来源标记：真实机构填false，隔离模拟器填true。当前适配器要求与simulation_only配置一致；不需要在实车启动模拟器。
bool simulated


# 旧动作已结束/取消且关节停止；并非“上位机已经发出零指令”。
bool action_stopped
# 机构当前明确允许发起新动作；未知时false。
bool retry_allowed
# 0无故障；具体故障码由机构适配端定义。
uint16 fault_code
# 状态3：旧动作取消，仍需action_stopped确认。
uint8 CANCELLED=3
