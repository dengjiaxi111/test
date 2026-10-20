# 完整导航计划；导航侧发布到 navigation_plan，供执行/观察方读取。
# 对应交接文档5.1；路径、逐洞事件和版本一起发送，不能混用不同计划的数据。
# speed_regions 是为分段限速补充的设计。此文件仍是审阅稿，不能视为实车已接通。

# 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
std_msgs/Header header

# 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
string session_id

# 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
string goal_id

# 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
uint64 plan_id

# 常量0：当前有效计划。不是给status自动赋值。
uint8 ACTIVE=0

# 常量1：旧计划已失效，不可继续执行。
uint8 INVALIDATED=1

# 常量2：任务已取消。
uint8 CANCELLED=2

# 常量3：任务已结束为成功；不单凭此值解除洞内结构要求。
uint8 COMPLETED=3

# 常量4：任务失败；不意味着可以自动抬高姿态。
uint8 FAILED=4

# 实际计划状态，使用上面的0—4；ACTIVE且passages为空表示有效无洞路线，不等于失效。
uint8 status

# 计划状态原因说明，例如路径受阻；这是说明文字，不应依赖解析文本作为稳定协议。
string reason

# 该计划是否声明启用过洞规划/校验约束；不等同于机构已准备完成。
bool constraints_enabled

# 本次采用的地形几何版本，例如洞口几何更新后改变。
uint64 terrain_revision

# 本次采用的规划配置版本；当前来自所选规划快照的configuration_revision，不代表所有参数均已纳入。
uint64 parameter_revision

# 本次校验采用的地图快照身份；草稿为地图摘要，不是时间戳或递增更新次数。
uint64 map_revision

# 正式接纳的最终路径，位姿点与header声明的坐标系一致；事件弧长均相对此路径。
nav_msgs/Path path

# 该最终折线路径的二维累计长度，单位m；不是机器人已行驶距离。
float64 path_length

# 该版本的通行记录列表，数据与path应来自同一接纳快照；空列表可以是合法绕行。
HoleTraversal[] passages

# 沿当前path定义的限速区间列表，可同时含坡面及坡顶后受限区。
HoleSpeedRegion[] speed_regions

