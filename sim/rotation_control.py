"""仅控制旋转；平移速度仍由原 navigate 和原坐标转换提供。"""
import math
import numpy as np
from scipy.spatial.transform import Rotation as Rot


def angle_error(target, measured):
    return math.remainder(target - measured, 2 * math.pi)


def ground_yaw_rate(orientation, world_omega):
    """由实际空间角速度计算相对地面的 Euler yaw 变化率（不是简单取 wz）。"""
    _, pitch, yaw = orientation.as_euler('xyz')
    if abs(math.cos(pitch)) < .1:
        raise ValueError('yaw is ill-conditioned near vertical pitch')
    wx, wy, wz = world_omega
    return float(wz + math.tan(pitch) * (math.cos(yaw) * wx + math.sin(yaw) * wy))


def horizontal_child(chassis):
    """chassis→chassiss：同原点、只保留底盘 yaw；不修改已有 TF。"""
    return chassis.inv() * Rot.from_euler('z', chassis.as_euler('xyz')[2])


class RotationControl:
    def __init__(self, gain=3., max_chassis_rate=1.2, max_joint_rate=2.4, heading_deadband=.01):
        self.gain = gain
        self.max_chassis_rate = max_chassis_rate
        self.max_joint_rate = max_joint_rate
        self.heading_deadband = heading_deadband
        self.mode = None
        self.chassis_hold = self.gimbal_hold = 0.
        self.alignment_target = None

    def update(self, chassis, upper, world_omega, alignment=None, spin_rate=0., stop=False, hold_gimbal=False):
        cyaw = chassis.as_euler('xyz')[2]
        gyaw = upper.as_euler('xyz')[2]
        mode = 'stop' if stop else ('align' if alignment is not None else ('spin' if spin_rate else 'hold'))
        if mode != self.mode:
            self.chassis_hold = cyaw
            if not hold_gimbal or mode == 'stop':
                self.gimbal_hold = gyaw
            self.mode = mode
        if mode == 'align':
            if not hold_gimbal and (self.alignment_target is None or abs(angle_error(alignment, self.alignment_target)) > 1e-8):
                # upper 已含安装偏角；锁定最接近实测云台朝向的合法世界yaw。
                self.gimbal_hold = gyaw + math.remainder(alignment - gyaw, math.pi / 2)
            self.alignment_target = alignment
        else:
            self.alignment_target = None
        if mode == 'spin':
            # 两者均相对地面；正值表示底盘逆时针、枪口顺时针。
            chassis_rate = float(np.clip(spin_rate, -self.max_chassis_rate, self.max_chassis_rate))
            # 云台的地面目标独立于底盘是否真的转起来；关节命令再补偿底盘实测角速度。
            # 连续洞之间只保持枪口地面朝向，底盘仍执行普通导航旋转。
            gimbal_rate = self.gain * angle_error(self.gimbal_hold, gyaw) if hold_gimbal else -spin_rate
        else:
            target = alignment if mode == 'align' else self.chassis_hold
            error = angle_error(target, cyaw)
            # 进入已允许的小误差带后给零转速，避免持续微量转向使舵轮来回调整。
            chassis_rate = 0. if abs(error)<=self.heading_deadband else float(np.clip(self.gain * error, -self.max_chassis_rate, self.max_chassis_rate))
            gimbal_rate = self.gain * angle_error(self.gimbal_hold, gyaw)
        axis = chassis.apply([0., 0., 1.])
        chassis_gain = ground_yaw_rate(chassis, axis)
        gimbal_gain = ground_yaw_rate(upper, axis)
        if abs(chassis_gain) < .1 or abs(gimbal_gain) < .1:
            raise ValueError('rotation axis cannot safely control ground yaw')
        chassis_command = chassis_rate / chassis_gain
        # 使用实测底盘角速度补偿，不能把“已发出”当成“已执行”。
        joint_command = (gimbal_rate - ground_yaw_rate(upper, world_omega)) / gimbal_gain
        return chassis_command, float(np.clip(joint_command, -self.max_joint_rate, self.max_joint_rate))
