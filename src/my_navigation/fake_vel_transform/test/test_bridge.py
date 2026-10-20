"""Run with ROS and robots_msgs sourced, using unittest (no hardware)."""
import math
import time
import unittest
import tempfile
import os
from unittest.mock import Mock

import rclpy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from robots_msgs.msg import ChassisOdom
from tf2_msgs.msg import TFMessage

from fake_vel_transform.core import fresh, inverse, normalize, rotate
from fake_vel_transform.node import FakeVelTransform
from rclpy.parameter import Parameter
from fake_vel_transform.config import feedback_policy


def odom(stamp, yaw=math.pi / 2):
    msg = Odometry()
    msg.header.frame_id, msg.child_frame_id = 'odom', 'base_link'
    msg.header.stamp.sec = int(stamp)
    msg.header.stamp.nanosec = int((stamp - int(stamp)) * 1e9)
    msg.pose.pose.position.x = 2.0
    msg.pose.pose.orientation.z = math.sin(yaw / 2)
    msg.pose.pose.orientation.w = math.cos(yaw / 2)
    return msg


class GeometryTest(unittest.TestCase):
    def test_selected_config_controls_feedback_policy(self):
        for alpha in (0.0, 0.8, 1.0, -0.1, 1.1):
            with tempfile.NamedTemporaryFile(mode='w', suffix='.yaml', delete=False) as f:
                f.write(f'nav_server:\n  ros__parameters:\n    nmpc:\n      odom_feedback_alpha: {alpha}\n      chassis_velocity_timeout_sec: 0.12\n')
                path = f.name
            try:
                if 0 <= alpha <= 1:
                    self.assertEqual(feedback_policy(path), {'odom_feedback_alpha': alpha, 'feedback_timeout': 0.12})
                else:
                    with self.assertRaises(ValueError):
                        feedback_policy(path)
            finally:
                os.unlink(path)

    def test_planar_roundtrip_and_norm(self):
        for yaw in (0, math.pi/2, -math.pi/2, math.pi-1e-8, -math.pi+1e-8):
            q = (0, 0, math.sin(yaw/2), math.cos(yaw/2))
            base = rotate(inverse(q), (1, 0, 0))
            self.assertAlmostEqual(base[0], math.cos(yaw))
            self.assertAlmostEqual(base[1], -math.sin(yaw))
            back = rotate(q, base)
            self.assertAlmostEqual(back[0], 1)
            self.assertAlmostEqual(back[1], 0)
            self.assertAlmostEqual(sum(v*v for v in base), 1)

    def test_full_rotation_inverse(self):
        q = normalize((0.2, 0.3, -0.4, 0.7))
        for vector in ((1, 0, 0), (0, 1, 0), (0, 0, 1)):
            recovered = rotate(q, rotate(inverse(q), vector))
            for actual, expected in zip(recovered, vector):
                self.assertAlmostEqual(actual, expected)
        for invalid in ((0, 0, 0, 0), (math.nan, 0, 0, 1)):
            with self.assertRaises(ValueError):
                normalize(invalid)
        self.assertFalse(fresh(1, 2, 0.2))
        self.assertFalse(fresh(2, 1, 0.2))


class BridgeTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        rclpy.init()

    @classmethod
    def tearDownClass(cls):
        rclpy.shutdown()

    def setUp(self):
        self.node = FakeVelTransform()
        self.clock = 10.0
        self.node.now = lambda: self.clock
        self.node.cmd_pub = Mock()
        self.node.feedback_pub = Mock()
        self.node.tf_pub = Mock()

    def tearDown(self):
        self.node.destroy_node()

    def ready(self):
        self.node.on_odom(odom(self.clock))
        self.node.on_feedback(ChassisOdom(speed_x=1.0, speed_y=0.0))

    def command(self):
        msg = Twist()
        msg.linear.x = 1.0
        self.node.on_command(msg)
        self.node.tick()

    def test_tf_feedback_and_command(self):
        self.ready()
        tf = self.node.tf_pub.sendTransform.call_args.args[0]
        self.assertEqual(tf.header.frame_id, 'base_link')
        self.assertEqual(tf.child_frame_id, 'base_link_fake')
        self.assertEqual(tf.header.stamp.sec, 10)
        self.assertAlmostEqual(tf.transform.rotation.z, -math.sqrt(0.5))
        feedback = self.node.feedback_pub.publish.call_args.args[0]
        self.assertEqual(feedback.child_frame_id, 'base_link_fake')
        self.assertEqual(feedback.pose.pose.orientation.w, 1)
        self.assertEqual(feedback.pose.pose.position.x, 2)
        self.assertAlmostEqual(feedback.twist.twist.linear.x, 0)
        self.assertAlmostEqual(feedback.twist.twist.linear.y, 1)
        self.assertEqual(feedback.twist.twist.angular.z, 0)
        self.command()
        out = self.node.cmd_pub.publish.call_args.args[0]
        self.assertAlmostEqual(out.linear.x, 0)
        self.assertAlmostEqual(out.linear.y, -1)
        self.node.tick()
        self.assertEqual(self.node.feedback_pub.publish.call_count, 1)

    def test_no_initial_pose_and_no_command_resurrection(self):
        self.command()
        self.assertIsNone(self.node.command)
        self.ready()
        self.command()
        self.clock += 0.3
        self.node.tick()
        self.assertIsNone(self.node.command)
        self.ready()
        self.node.tick()
        self.assertEqual(self.node.cmd_pub.publish.call_args.args[0].linear.y, 0)

    def test_each_timeout_independently(self):
        for source in ('command_received', 'feedback_received', 'odom_received'):
            self.ready()
            self.command()
            setattr(self.node, source, self.clock - 1)
            self.node.tick()
            self.assertIsNone(self.node.command, source)

    def test_rotation_updates_output_without_rotating_world_command(self):
        self.node.on_odom(odom(self.clock, yaw=0))
        self.node.on_feedback(ChassisOdom(speed_x=1.0))
        self.command()
        self.assertAlmostEqual(self.node.cmd_pub.publish.call_args.args[0].linear.x, 1)
        self.clock += 0.05
        self.node.on_odom(odom(self.clock, yaw=math.pi/2))
        self.node.tick()
        out = self.node.cmd_pub.publish.call_args.args[0]
        self.assertAlmostEqual(out.linear.x, 0)
        self.assertAlmostEqual(out.linear.y, -1)

    def test_invalid_samples_and_skew(self):
        self.ready()
        self.command()
        self.node.on_feedback(ChassisOdom(speed_x=math.nan))
        self.assertIsNone(self.node.command)
        self.ready()
        self.clock += 0.15  # LIO not timed out, but too far from receive time.
        self.node.on_feedback(ChassisOdom(speed_x=1.0))
        self.assertIsNone(self.node.feedback_received)
        self.ready()
        bad = odom(self.clock)
        bad.child_frame_id = 'wrong'
        self.node.on_odom(bad)
        self.assertIsNone(self.node.odom_received)

    def test_duplicate_pose_cannot_refresh_liveness(self):
        self.ready()
        self.clock += 0.1
        self.node.on_odom(odom(10.0))
        self.assertEqual(self.node.odom_received, 10.0)

    def test_angular_and_nonfinite_command_rejected(self):
        self.ready()
        for field, value in (('angular', 1.0), ('linear', math.inf)):
            msg = Twist()
            if field == 'angular':
                msg.angular.z = value
            else:
                msg.linear.x = value
            self.node.on_command(msg)
            self.assertIsNone(self.node.command)

    def test_clock_rewind_clears_state(self):
        self.ready()
        self.command()
        self.node.last_now = time.time() + 1e6
        FakeVelTransform.now(self.node)
        self.assertFalse(self.node.poses)
        self.assertIsNone(self.node.feedback_received)
        self.assertIsNone(self.node.command)

    def test_alpha_zero_runs_without_feedback_and_still_requires_pose(self):
        self.node.destroy_node()
        self.node = FakeVelTransform(parameter_overrides=[Parameter('odom_feedback_alpha', value=0.0)])
        self.node.now = lambda: self.clock
        self.node.cmd_pub = Mock()
        self.node.feedback_pub = Mock()
        self.node.tf_pub = Mock()
        self.command()
        self.assertIsNone(self.node.command)
        self.node.on_odom(odom(self.clock))
        self.command()
        self.assertAlmostEqual(self.node.cmd_pub.publish.call_args.args[0].linear.y, -1)
        self.node.on_feedback(ChassisOdom(speed_x=math.nan))
        self.node.tick()
        self.assertIsNotNone(self.node.command)
        self.node.feedback_pub.publish.assert_not_called()
        result = self.node.set_parameters([Parameter('odom_feedback_alpha', value=1.0)])
        self.assertFalse(result[0].successful)
        self.clock += 0.3
        self.node.tick()
        self.assertIsNone(self.node.command)


class RosGraphTest(unittest.TestCase):
    def test_real_pubsub(self):
        rclpy.init()
        bridge = FakeVelTransform()
        peer = rclpy.create_node('fake_bridge_test_peer')
        odom_pub = peer.create_publisher(Odometry, '/Odometry', 10)
        feedback_pub = peer.create_publisher(ChassisOdom, '/ChassisOdom', 10)
        command_pub = peer.create_publisher(Twist, '/cmd_vel', 10)
        commands, feedback, transforms = [], [], []
        peer.create_subscription(Twist, '/cmd_vel_gimbal', commands.append, 10)
        peer.create_subscription(Odometry, '/Odometry/fake', feedback.append, 10)
        peer.create_subscription(TFMessage, '/tf', transforms.append, 10)
        executor = rclpy.executors.SingleThreadedExecutor()
        executor.add_node(bridge)
        executor.add_node(peer)
        try:
            end = time.monotonic() + 2.0
            while time.monotonic() < end:
                stamp = peer.get_clock().now().nanoseconds * 1e-9
                odom_pub.publish(odom(stamp))
                feedback_pub.publish(ChassisOdom(speed_x=1.0))
                cmd = Twist()
                cmd.linear.x = 1.0
                command_pub.publish(cmd)
                for _ in range(12):
                    executor.spin_once(timeout_sec=0.002)
            self.assertTrue(any(abs(m.linear.y + 1) < 1e-6 for m in commands))
            self.assertTrue(any(abs(m.twist.twist.linear.y - 1) < 1e-6 for m in feedback))
            self.assertTrue(any(t.child_frame_id == 'base_link_fake' for m in transforms for t in m.transforms))
            end = time.monotonic() + 0.35
            while time.monotonic() < end:
                executor.spin_once(timeout_sec=0.01)
            self.assertEqual(commands[-1].linear.x, 0)
            self.assertEqual(commands[-1].linear.y, 0)
        finally:
            executor.shutdown()
            bridge.destroy_node()
            peer.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    unittest.main()
