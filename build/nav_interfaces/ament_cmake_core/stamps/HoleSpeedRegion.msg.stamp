# 最终路径上的分段速度上限；嵌套在 NavigationPlan.speed_regions。
# 为上下坡及坡顶后限速补充的结构；它描述限制，不负责生成加减速指令。
# 不改变A/S/E/X/T/D几何；具体上限由配置和控制器共同处理。

# 限速区间起点的路径累计弧长，单位m。
float64 s_begin

# 限速区间终点的路径累计弧长，单位m；按当前最终路径解释。
float64 s_end

# 区间平移速度模长上限，单位m/s；允许更慢或停车，不是强制目标速度。
float64 speed_limit

# 当前C++编码：0平地FLAT，1上坡UPHILL，2下坡DOWNHILL，3受限RESTRICTED；消息尚未声明对应命名常量。
uint8 kind

