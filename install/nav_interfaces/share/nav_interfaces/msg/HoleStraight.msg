# 当前最终路径上需要保持直线的区间；嵌套在 HoleTraversal.straight_segments。
# 对应交接文档5.2：严格模式S—T；free模式S—E和X—T。
# 方向是地图中的运动切线，不是机身yaw对准要求。

# 直线区间起点的路径累计弧长，单位m，相对当前NavigationPlan.path起点。
float64 s_begin

# 直线区间终点的路径累计弧长，单位m，应不小于s_begin。
float64 s_end

# 地图坐标系的运动方向向量，草稿使用二维切向x/y；不是机身朝向角，也不是速度大小。
geometry_msgs/Vector3 direction

# true表示当前只能声明剩余直线片段；false声明完整区间，不等于该段已经走完。
bool remaining

