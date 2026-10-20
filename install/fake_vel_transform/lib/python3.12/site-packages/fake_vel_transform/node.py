"""Stage A: virtual navigation frame, gimbal base feedback and commands.

ChassisOdom has no sample stamp: receive time and a bounded nearest LIO
sample are used. No timer republishes old feedback with a new timestamp.
"""
import math
import signal
from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.qos import qos_profile_sensor_data
from rcl_interfaces.msg import ParameterDescriptor
from geometry_msgs.msg import TransformStamped, Twist
from nav_msgs.msg import Odometry
from robots_msgs.msg import ChassisOdom
from tf2_ros import TransformBroadcaster

from .core import fresh, inverse, normalize, rotate


class FakeVelTransform(Node):
    def __init__(self, **kwargs):
        super().__init__('fake_vel_transform', **kwargs)
        def param(name, default):
            return self.declare_parameter(name, default).value
        self.alpha = float(self.declare_parameter(
            'odom_feedback_alpha', 0.8,
            ParameterDescriptor(read_only=True, description='Restart bridge and MPC together to change feedback policy.')).value)
        if not math.isfinite(self.alpha) or not 0.0 <= self.alpha <= 1.0:
            raise ValueError('odom_feedback_alpha must be in [0,1]')
        self.require_feedback = self.alpha > 0.0
        self.odom_frame = param('odom_frame', 'odom')
        self.base_frame = param('base_frame', 'base_link')  # physical gimbal base
        self.fake_frame = param('fake_frame', 'base_link_fake')
        if len({self.odom_frame, self.base_frame, self.fake_frame}) != 3:
            raise ValueError('odom/base/fake frames must be distinct')
        self.cmd_timeout = float(param('command_timeout', 0.2))
        self.odom_timeout = float(param('odom_timeout', 0.2))
        self.feedback_timeout = float(param('feedback_timeout', 0.15))
        self.max_skew = float(param('feedback_pose_max_skew', 0.1))
        rate = float(param('publish_rate', 50.0))
        if not all(math.isfinite(v) and v > 0 for v in (
                self.cmd_timeout, self.odom_timeout, self.feedback_timeout, self.max_skew, rate)):
            raise ValueError('rates and timeouts must be finite and positive')
        self.tf_pub = TransformBroadcaster(self)
        self.cmd_pub = self.create_publisher(Twist, param('output_topic', '/cmd_vel_gimbal'), 1)  # gimbal velocity for the electrical layer
        self.feedback_pub = self.create_publisher(Odometry, param('fake_odom_topic', '/Odometry/fake'), 10)
        self.create_subscription(Odometry, param('odom_topic', '/Odometry'),
                                 self.on_odom, qos_profile_sensor_data)
        self.create_subscription(ChassisOdom, param('feedback_topic', '/ChassisOdom'),
                                 self.on_feedback, qos_profile_sensor_data)
        self.create_subscription(Twist, param('input_topic', '/cmd_vel'), self.on_command, 1)
        self.poses = deque(maxlen=1000)
        self.odom_received = None
        self.feedback_received = None
        self.command = None
        self.command_received = None
        self.last_now = None
        self.create_timer(1.0 / rate, self.tick)
        self.get_logger().info(f'Fixed fake frame; translation only, alpha={self.alpha}, feedback_required={self.require_feedback}.')
        self.get_logger().warn('Gimbal-base feedback uses receive time; nearest LIO pose is bounded by feedback_pose_max_skew.')

    def now(self):
        value = self.get_clock().now().nanoseconds * 1e-9
        if self.last_now is not None and value < self.last_now:
            self.poses.clear()
            self.odom_received = self.feedback_received = None
            self.stop()
        self.last_now = value
        return value

    def stop(self):
        self.command = self.command_received = None
        self.cmd_pub.publish(Twist())

    def odom_valid(self, now):
        return (bool(self.poses) and fresh(now, self.odom_received, self.odom_timeout)
                and fresh(now, self.poses[-1][0], self.odom_timeout))

    def on_odom(self, msg):
        now = self.now()
        stamp = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        p, q = msg.pose.pose.position, msg.pose.pose.orientation
        try:
            orientation = normalize((q.x, q.y, q.z, q.w))
            if (msg.header.frame_id != self.odom_frame or msg.child_frame_id != self.base_frame
                    or not all(math.isfinite(v) for v in (p.x, p.y, p.z))
                    or not fresh(now, stamp, self.odom_timeout)):
                raise ValueError('invalid odometry frame, position or timestamp')
        except ValueError:
            self.get_logger().warning('Rejected invalid/stale LIO sample; stopping.', throttle_duration_sec=2.0)
            self.odom_received = None
            self.stop()
            return
        if self.poses and stamp <= self.poses[-1][0]:
            return  # Do not refresh liveness with duplicate/out-of-order sensor samples.
        self.poses.append((stamp, orientation, (p.x, p.y, p.z)))
        self.odom_received = now
        tf = TransformStamped()
        tf.header = msg.header
        tf.header.frame_id = self.base_frame
        tf.child_frame_id = self.fake_frame
        r = tf.transform.rotation
        r.x, r.y, r.z, r.w = inverse(orientation)
        self.tf_pub.sendTransform(tf)

    def on_feedback(self, msg):
        now = self.now()
        if not self.odom_valid(now) or not all(math.isfinite(v) for v in (msg.speed_x, msg.speed_y)):
            self.get_logger().warning('Feedback rejected: no valid LIO pose or finite velocity.', throttle_duration_sec=2.0)
            self.feedback_received = None
            if self.require_feedback:
                self.stop()
            return
        stamp, q, p = min(self.poses, key=lambda sample: abs(sample[0] - now))
        if abs(stamp - now) > self.max_skew:
            self.get_logger().warning('Feedback rejected: LIO time difference exceeds limit.', throttle_duration_sec=2.0)
            self.feedback_received = None
            if self.require_feedback:
                self.stop()
            return
        self.feedback_received = now
        out = Odometry()
        out.header.stamp = self.get_clock().now().to_msg()
        out.header.frame_id, out.child_frame_id = self.odom_frame, self.fake_frame
        out.pose.pose.position.x, out.pose.pose.position.y, out.pose.pose.position.z = p
        out.pose.pose.orientation.w = 1.0
        vx, vy, _ = rotate(q, (msg.speed_x, msg.speed_y, 0.0))
        out.twist.twist.linear.x, out.twist.twist.linear.y = vx, vy
        # Pose is the bounded nearest LIO sample; no claim of hardware synchronization.
        self.feedback_pub.publish(out)

    def on_command(self, msg):
        now = self.now()
        values = (msg.linear.x, msg.linear.y, msg.linear.z,
                  msg.angular.x, msg.angular.y, msg.angular.z)
        if (not all(math.isfinite(v) for v in values)
                or any(abs(v) > 1e-9 for v in values[2:])
                or not self.odom_valid(now)
                or (self.require_feedback and not fresh(now, self.feedback_received, self.feedback_timeout))):
            self.get_logger().warning('Command rejected: check fresh LIO, feedback policy and planar finite values.', throttle_duration_sec=2.0)
            self.stop()
            return
        self.command = (msg.linear.x, msg.linear.y, 0.0)
        self.command_received = now

    def tick(self):
        now = self.now()
        if (self.command is None or not fresh(now, self.command_received, self.cmd_timeout)
                or not self.odom_valid(now)
                or (self.require_feedback and not fresh(now, self.feedback_received, self.feedback_timeout))):
            self.stop()
            return
        vx, vy, _ = rotate(inverse(self.poses[-1][1]), self.command)
        out = Twist()
        out.linear.x, out.linear.y = vx, vy
        self.cmd_pub.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = FakeVelTransform()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        # ros2 launch may relay SIGINT after the process group received it.
        signal.signal(signal.SIGINT, signal.SIG_IGN)
        if rclpy.ok():
            node.stop()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
