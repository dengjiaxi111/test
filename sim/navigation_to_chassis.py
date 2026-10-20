#!/usr/bin/env python3

"""Convert planar navigation velocity from the configured frame to chassis."""

import math

import rclpy
from geometry_msgs.msg import Twist
from rclpy.duration import Duration
from rclpy.node import Node
from tf2_ros import Buffer, TransformException, TransformListener


class NavigationToChassis(Node):
    def __init__(self):
        super().__init__("navigation_to_chassis")
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        # sentry2026 UPPERPCREC_PERIOD: 20 ms communication + 60 ms processing.
        self.delay = float(self.declare_parameter("navigation_delay_seconds", 0.00).value)
        input_topic = self.declare_parameter(
            "input_topic", "/cmd_vel_gimbal"
        ).value
        self.input_frame = self.declare_parameter(
            "input_frame", "base_link"
        ).value
        output_topic = self.declare_parameter(
            "output_topic", "/navigation/cmd_vel"
        ).value
        if not math.isfinite(self.delay) or self.delay < 0.0:
            raise ValueError("navigation_delay_seconds must be finite and nonnegative")
        if not self.input_frame:
            raise ValueError("input_frame must not be empty")
        if self.delay > 0.0 and self.input_frame != "base_link":
            raise ValueError("navigation_delay_seconds requires base_link input")
        self.publisher = self.create_publisher(Twist, output_topic, 10)
        self.subscription = self.create_subscription(
            Twist, input_topic, self.convert, 10
        )

    def convert(self, command):
        try:
            correction = 0.0
            transform_time = rclpy.time.Time()
            if self.delay > 0.0:
                current = self.tf_buffer.lookup_transform(
                    "odom", "base_link", rclpy.time.Time()
                )
                transform_time = rclpy.time.Time.from_msg(current.header.stamp)
                if transform_time.nanoseconds <= int(self.delay * 1e9):
                    self.publisher.publish(Twist())
                    return
                previous = self.tf_buffer.lookup_transform(
                    "odom", "base_link",
                    transform_time - Duration(seconds=self.delay),
                )
                # MCU yaw is clockwise-positive; ROS yaw is counterclockwise.
                # Express the delayed gimbal-frame vector in the current frame.
                delta = self.yaw(current) - self.yaw(previous)
                correction = -math.atan2(math.sin(delta), math.cos(delta))
            transform = self.tf_buffer.lookup_transform(
                "chassis", self.input_frame, transform_time
            )
        except TransformException as exception:
            self.publisher.publish(Twist())
            self.get_logger().warning(
                f"Cannot convert navigation velocity to chassis: {exception}",
                throttle_duration_sec=2.0,
            )
            return

        # A single TF lookup composes every edge at one common timestamp.
        # For fake-frame input this avoids mixing a 5 Hz LIO gimbal heading
        # with a newer joint-state heading during the same velocity command.
        yaw = self.yaw(transform) + correction
        cosine, sine = math.cos(yaw), math.sin(yaw)
        output = Twist()
        output.linear.x = cosine * command.linear.x - sine * command.linear.y
        output.linear.y = sine * command.linear.x + cosine * command.linear.y
        output.linear.z = command.linear.z
        # Nav2 yaw turns the virtual heading, not the physical chassis.
        output.angular.z = 0.0
        self.publisher.publish(output)

    @staticmethod
    def yaw(transform):
        q = transform.transform.rotation
        return math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )


def main():
    rclpy.init()
    node = NavigationToChassis()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
