# 导航侧发布 hole_traversal_state：当前五态、决策、进度和逐洞阶段。
# 对应交接文档5.4、7.1。包含云台朝向保持指令；本消息不是独立的平移运动许可协议。
# 当前准备信息只包含需求标记，不完整表达准备中/就绪/故障；此为草稿缺口。

# 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
std_msgs/Header header

# 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
string session_id

# 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
string goal_id

# 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
uint64 plan_id

# 当前五态编码：0 NORMAL，1 PREPARE，2 TRAVERSE，3 RESTORE，4 HOLD；不是顶层导航状态。
uint8 state

# 导航决策编码：0 CONTINUE，1 STOP，2 REPLAN，3 RECOVERY，4 FAILURE；HOLD状态可输出不同决策。
uint8 decision

# 机器人参考点在当前路径上的可靠累计进度，单位m；不是总里程。
float64 s_progress

# 本周期允许的平移速度模长上限，单位m/s；不能单凭观察消息绕过运动许可。
float64 speed_limit

# 当前状态/决策或暂停原因的说明文字；草稿部分分支仍比较字符串，尚非完整故障码协议。
string reason

# 核心当前保留的通行编号列表，可能包含已完成记录；顺序与下面两个数组必须一一对应。
string[] traversal_uids

# 逐通行空间阶段：0 PENDING，1 ENTRY_STRAIGHT，2 IN_HOLE，3 EXIT_STRAIGHT，4 DEPARTING，5 COMPLETE。到D可先标记COMPLETE，不单凭此值证明占用已释放。
uint8[] phases

# 逐通行的结构需求标记，实际来自Visit.demand；true不代表正在变形，也不证明准备完成，进入洞内后仍可为true。
bool[] preparing_required


# 本次通行尝试编号，0为首次，1/2为两次重试。
uint32 attempt
# 专用恢复阶段：0无，1停稳，2校验，3退让，4目标停稳，5重入检查。
uint8 recovery_phase

# 状态机明确输出的云台朝向保持指令，非从state/preparing_required推断。
# LOW和实测对准完成后为true；连续洞含洞间连接段保持true，
# 最后相关D及整车净空确认、请求NORMAL时变为false。
# 执行器保持第一次已完成对准的地面朝向，true持续期间不得重选朝向或恢复自旋。
# 不限制底盘普通旋转；HOLD/故障/退让等安全停转指令优先。
bool hold_gimbal_heading
