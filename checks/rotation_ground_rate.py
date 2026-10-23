"""同一个真实控制调用：底盘卡住时，云台仍应按地面坐标反向50°/s。"""
import math
from pathlib import Path
import sys

from scipy.spatial.transform import Rotation as Rot

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'sim'))
from rotation_control import RotationControl

target = math.radians(50)
control = RotationControl()
chassis = Rot.identity()
upper = Rot.identity()

# 假设轮系/地面接触暂时使底盘实际角速度为零，机器人仍处于普通NAV。
base, joint = control.update(chassis, upper, [0., 0., 0.], spin_rate=target)
assert abs(base-target)<1e-9
assert abs(joint+target)<1e-9, f'底盘卡住时云台也不转：joint={joint}'

# 实际底盘地面角速度+0.3，关节应补偿到云台地面角速度-50°/s。
_, joint = control.update(chassis, upper, [0., 0., .3], spin_rate=target)
assert abs((.3+joint)+target)<1e-9, f'云台地面角速度没有保持-50°/s：joint={joint}'

# 状态机停转或入口对准仍然优先，不能被自动旋转覆盖。
base, joint = control.update(chassis, upper, [0., 0., 0.], spin_rate=target, stop=True)
assert abs(base)<1e-9 and abs(joint)<1e-9
print('PASS: ground-relative 50°/s targets independent; stop remains dominant')
