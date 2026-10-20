# 一次具体穿洞的计划记录；嵌套在 NavigationPlan.passages 内，不单独发布。
# 对应交接文档5.2。同一个物理洞再次穿越，应有另一条通行记录。
# 当前草稿尚未完整导出文档列出的顺序、完整性、细分校验结果和容差等信息。

# 本任务中这一次具体穿越的稳定编号；同次通行重规划匹配保留，再穿同一个洞应另编号。
string traversal_uid

# 地形配置中的物理洞口区域ID；同一个洞可关联不同次通行，不能单独用来动作去重。
string hole_id

# 本次选中的洞口多边形入口边索引，编号规则来自规划器。
int32 entry_edge_id

# 本次选中的洞口多边形出口边索引，与入口共同确定通行方向。
int32 exit_edge_id

# true为严格中心线模式，false为free；默认只接纳严格模式，除非配置显式允许free。
bool centerline

# 当前候选校验是否通过；不能替代文档全部细分保证，不能表示机构准备已完成。
bool validated

# 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
uint64 requirement_revision

# 固定六项，存储顺序A/S/E/X/T/D；此数组顺序不代表事件的实际弧长顺序，A可能晚于S。
HoleEvent[6] events

# 本路径中有效的固定直线区间，区分完整段和剩余段，不能由恢复动作任意破坏。
HoleStraight[] straight_segments


# 本次入口方向与关联坡上坡方向一致；首版只允许此类失败后退让。
bool uphill_entry
