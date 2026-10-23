"""Keep the gimbal world heading while preserving ordinary chassis spin."""
import math
import sys
from pathlib import Path

from scipy.spatial.transform import Rotation as Rot
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'sim'))
from rotation_control import RotationControl, angle_error

control = RotationControl()
control.update(Rot.identity(), Rot.identity(), [0., 0., 0.], alignment=0.)
for step in range(700):
    chassis = Rot.from_euler('z', step * .01)
    base, joint = control.update(chassis, Rot.identity(), [0., 0., 1.], spin_rate=1., hold_gimbal=True)
    assert abs(base - 1.) < 1e-9
    assert abs(1. + joint) < 1e-9, 'gimbal spun with the chassis'
    assert abs(angle_error(control.gimbal_hold, 0.)) < 1e-9
# Orthogonal second passage does not rotate the already legal gimbal heading.
base, joint = control.update(Rot.from_euler('z', math.pi / 2), Rot.identity(), [0., 0., 0.],
                             alignment=math.pi / 2, hold_gimbal=True)
assert abs(base) < 1e-9 and abs(joint) < 1e-9
# Once the final demand is released, normal spin returns.
base, joint = control.update(Rot.identity(), Rot.identity(), [0., 0., 0.], spin_rate=1.)
assert abs(base - 1.) < 1e-9 and abs(joint + 1.) < 1e-9
print('PASS: gimbal world heading persists across chassis spin and second alignment; final release restores spin')
