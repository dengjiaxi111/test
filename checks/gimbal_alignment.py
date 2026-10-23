"""Exercise real yaw control, including the model's gimbal mounting rotation."""
import math
from pathlib import Path
import sys
import xml.etree.ElementTree as ET

from scipy.spatial.transform import Rotation as Rot

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'sim'))
from rotation_control import RotationControl, angle_error

mount = float(ET.parse(ROOT / 'sim/robot.sdf').find(
    ".//joint[@name='gimbal_yaw_joint']/pose").text.split()[5])


def converge(chassis_angles, joint_angle, target):
    control = RotationControl()
    chassis = Rot.from_euler('xyz', chassis_angles)
    upper = chassis * Rot.from_euler('z', mount + joint_angle)
    expected = upper.as_euler('xyz')[2] + math.remainder(
        target - upper.as_euler('xyz')[2], math.pi / 2)
    body_rate = 0.
    for _ in range(800):
        upper = chassis * Rot.from_euler('z', mount + joint_angle)
        body, joint = control.update(chassis, upper, chassis.apply([0., 0., body_rate]), alignment=target)
        chassis = chassis * Rot.from_rotvec([0., 0., body * .01])
        joint_angle += joint * .01
        body_rate = body
    cyaw = chassis.as_euler('xyz')[2]
    gyaw = (chassis * Rot.from_euler('z', mount + joint_angle)).as_euler('xyz')[2]
    assert abs(angle_error(target, cyaw)) < .011
    assert abs(angle_error(expected, gyaw)) < .005, (expected, gyaw)
    assert abs(math.remainder(gyaw - cyaw, math.pi / 2)) < .02, (cyaw, gyaw)


for initial in (10., 25., 60., 179., -179.):
    converge([0., 0., math.radians(35)], math.radians(initial - 35) - mount, 0.)
for yaw in (3.1, -3.1, 1.2):
    converge([0., 0., yaw + .2], -.7, yaw)
# On a slope use the physical upper orientation, rather than the raw joint angle.
converge([.1, .3, 1.2], -.8, 1.2)

# A changed passage heading must select a new target even without leaving align.
control = RotationControl()
chassis = Rot.identity()
upper = Rot.from_euler('z', .1)
control.update(chassis, upper, [0., 0., 0.], alignment=0.)
_, joint = control.update(chassis, upper, [0., 0., 0.], alignment=.4)
assert joint > 0., 'changed alignment target still holds the old gimbal heading'

# Manual/safety stop must hold the actual heading, without snapping to a face.
_, joint = control.update(chassis, upper, [0., 0., 0.], alignment=.4, stop=True)
assert abs(joint) < 1e-12
print('PASS: physical gimbal alignment, mounting offset, wraparound, slope, target change, stop')
