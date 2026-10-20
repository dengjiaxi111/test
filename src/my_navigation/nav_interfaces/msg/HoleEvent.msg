# 一个计划事件的位置说明；嵌套在 HoleTraversal.events 内。
# 对应交接文档5.3；是“事件在哪里”，不是“事件已经触发”的通知。
# A不一定在S前：允许在S—E内开始变形，但必须在E前完成。
# 当前草稿缺少文档要求的reason字段；UNKNOWN/越界不能伪造有效坐标。

# 事件类型常量0：开始准备的路径事件。
uint8 A=0

# 事件类型常量1：入口固定直线开始。
uint8 S=1

# 事件类型常量2：真实入口边界；人工配置必须在此之前确认准备完成。
uint8 E=2

# 事件类型常量3：真实出口边界；参考点越过不代表整车退出。
uint8 X=3

# 事件类型常量4：出口固定直线结束；后续路径才可按规划转弯。
uint8 T=4

# 事件类型常量5：离开阶段边界；人工配置D=T，仍需反馈确认结构释放。
uint8 D=5

# 范围常量0：事件位于当前最终路径范围内。
uint8 ON_PATH=0

# 范围常量1：位于当前剩余路径起点之前，不证明准备/通过动作已经完成。
uint8 BEFORE_PATH=1

# 范围常量2：位于当前路径终点之后，不证明机器人已到达或退出。
uint8 AFTER_PATH=2

# 范围常量3：信息不足，不能可靠确定，禁止把默认坐标作为真实事件。
uint8 UNKNOWN=3

# 事件类型0—5，取A/S/E/X/T/D；与下面的range_status是两套不同编码。
uint8 type

# 事件相对当前路径的范围状态0—3，取ON_PATH/BEFORE_PATH/AFTER_PATH/UNKNOWN。
uint8 range_status

# 沿当前NavigationPlan.path起点累计到事件的弧长，单位m；不是两点直线距离。未知时不可使用。
float64 s_path

# 地图中的真实事件坐标x/y/z，单位m；只有point_valid为true时才可使用。
geometry_msgs/Point point

# 是否有可靠的真实事件坐标；false时默认(0,0,0)不表示事件位于地图原点。
bool point_valid

