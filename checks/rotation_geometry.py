#!/usr/bin/env python3
"""检查旋转适配的坐标不变量及相对地面反向同速，不启动Gazebo。"""
import sys
from pathlib import Path
import numpy as np
from scipy.spatial.transform import Rotation as Rot
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'sim'))
from rotation_control import RotationControl,horizontal_child,ground_yaw_rate

for angles in ((0,0,0),(.1,.3,1.2),(-.2,-.25,-2.8)):
    chassis=Rot.from_euler('xyz',angles)
    fake=Rot.identity()  # 原fake保持odom平行。
    horizontal=chassis*horizontal_child(chassis)
    np.testing.assert_allclose(horizontal.as_matrix(),Rot.from_euler('z',angles[2]).as_matrix(),atol=1e-12)
    upper=chassis*Rot.from_euler('z',.7)
    axis=chassis.apply([0,0,1.])
    # 让实测底盘yaw速度为+.3；补偿后的枪口地面yaw速度应为-.3。
    actual_omega=axis*(.3/ground_yaw_rate(chassis,axis))
    controller=RotationControl()
    body,joint=controller.update(chassis,upper,actual_omega,spin_rate=.3)
    assert abs(ground_yaw_rate(chassis,axis*body)-.3)<1e-12
    assert abs(ground_yaw_rate(upper,actual_omega+axis*joint)+.3)<1e-12
    # 停转初始时枪口仍在动：关节必须补偿实测底盘速度，不能只给0。
    _,joint=controller.update(chassis,upper,actual_omega,spin_rate=.3,stop=True)
    assert abs(ground_yaw_rate(upper,actual_omega+axis*joint))<1e-12
    # 底盘改变朝向，原fake→chassis转换仍须保持相同地图平移方向。
    velocity=np.array([.35,.2,0.])
    np.testing.assert_allclose(chassis.apply(chassis.inv().apply(fake.apply(velocity))),velocity,atol=1e-12)
print('PASS: chassiss水平、fake不变、平地/坡面世界yaw解耦、停转补偿、平移方向不变')
