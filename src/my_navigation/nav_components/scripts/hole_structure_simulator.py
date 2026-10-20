#!/usr/bin/env python3
"""独立模拟结构节点；默认不启用，不连接串口，不从等待时间推断真实结构完成。"""
import time
import rclpy
from rclpy.node import Node
from nav_interfaces.msg import HoleStructureRequest, HoleStructureFeedback, NavigationPlan, HoleTraversalState


class Simulator(Node):
    def __init__(self):
        super().__init__('hole_structure_simulator')
        self.declare_parameter('enabled', False)
        self.declare_parameter('action_delay', 0.8)  # 秒，仅模拟执行时间。
        self.declare_parameter('simulated_rear_margin', 0.3)  # 米，仅模拟整车离开余量。
        if not self.get_parameter('enabled').value:
            raise RuntimeError('模拟节点默认关闭；隔离仿真中显式设置 enabled:=true')
        self.request = None
        self.started = 0.0
        self.plan = None
        self.progress = 0.0
        self.state_identity = None
        self.cancelled = False
        self.publisher = self.create_publisher(HoleStructureFeedback, 'hole_structure/feedback', 10)
        self.create_subscription(HoleStructureRequest, 'hole_structure/request', self.on_request, 10)
        qos = rclpy.qos.QoSProfile(depth=1, durability=rclpy.qos.DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(NavigationPlan, 'navigation_plan', self.on_plan, qos)
        self.create_subscription(HoleTraversalState, 'hole_traversal_state', self.on_state, 10)
        self.create_timer(0.05, self.tick)  # 20Hz心跳，完成后也持续报告当前状态。

    def on_plan(self, msg):
        self.plan = msg

    def on_state(self, msg):
        self.state_identity = (msg.session_id, msg.goal_id, msg.plan_id)
        self.progress = msg.s_progress

    def on_request(self, msg):
        if msg.cancel_motion:
            self.cancelled = True
            return
        key = (msg.session_id, msg.goal_id, msg.request_id, msg.requirement_revision)
        old = None if self.request is None else (
            self.request.session_id, self.request.goal_id, self.request.request_id, self.request.requirement_revision)
        if key != old:
            self.started = time.monotonic()
        self.request = msg
        self.cancelled = False

    def tick(self):
        if self.request is None or self.cancelled:
            return
        q = self.request
        f = HoleStructureFeedback()
        f.header.stamp = self.get_clock().now().to_msg()
        f.header.frame_id = 'map'
        f.session_id, f.goal_id = q.session_id, q.goal_id
        f.request_id, f.requirement_revision = q.request_id, q.requirement_revision
        f.target = q.target
        f.status = (f.COMPLETED if time.monotonic() - self.started >= self.get_parameter('action_delay').value
                    else f.EXECUTING)
        f.moving_transition_supported = True
        f.simulated = True
        if self.plan is not None and self.state_identity == (
                self.plan.session_id, self.plan.goal_id, self.plan.plan_id):
            margin = self.get_parameter('simulated_rear_margin').value
            clear = []
            # 这里只模拟形态/净空。真实结构适配层须用真实包络和净空反馈，不能复制此判断上车。
            occupied = []
            for p in self.plan.passages:
                a, _, _, _, _, d = p.events
                if d.range_status != d.UNKNOWN and self.progress >= d.s_path + margin:
                    clear.append(p.traversal_uid)
                elif a.range_status == a.UNKNOWN or self.progress >= a.s_path:
                    occupied.append(p.traversal_uid)
            f.cleared_traversal_uids = clear
            # 对已完成的洞逐洞释放；有下一洞需求时，core仍保留下一洞的低姿态。
            f.whole_vehicle_clear = bool(clear) or not occupied
            f.normal_clearance = bool(clear) or not occupied
        self.publisher.publish(f)


def main():
    rclpy.init()
    node = Simulator()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
