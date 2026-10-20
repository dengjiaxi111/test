"""Full nav_server + bridge action test in an isolated ROS domain; no serial node."""
import math
import os
import subprocess
import tempfile
import time
import unittest
import runpy
from unittest.mock import patch
from pathlib import Path

import rclpy
from rclpy.action import ActionClient
from ament_index_python.packages import get_package_prefix
from geometry_msgs.msg import TransformStamped, Twist
from nav_msgs.msg import Odometry
from nav_interfaces.action import Navigate
from robots_msgs.msg import ChassisOdom
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster
from fake_vel_transform.node import FakeVelTransform
from launch import LaunchContext


class NavigationFlow(unittest.TestCase):
    def test_launch_map_and_topic_overrides(self):
        launch_path=Path(__file__).resolve().parents[2]/'nav_bringup/launch/navigation.launch.py'
        start=runpy.run_path(str(launch_path))['start_navigation']
        with tempfile.TemporaryDirectory(prefix='navigation_launch_') as directory:
            config=Path(directory)/'config.yaml'
            config.write_text('nav_server:\n  ros__parameters:\n    map_file: /maps/configured.yaml\n')
            context=LaunchContext()
            context.launch_configurations.update({'params_file':str(config),'map_file':'',
                'use_sim_time':'false','cmd_vel_topic':'/test_cmd'})
            with patch.dict(start.__globals__,Node=lambda **kwargs: kwargs):
                node=start(context)[0]
                self.assertEqual(node['parameters'][1]['map_file'],'/maps/configured.yaml')
                self.assertEqual(node['remappings'][0][1].perform(context),'/test_cmd')
                context.launch_configurations['map_file']='/maps/explicit.yaml'
                self.assertEqual(start(context)[0]['parameters'][1]['map_file'],'/maps/explicit.yaml')
                context.launch_configurations['map_file']=''
                config.write_text('nav_server:\n  ros__parameters:\n    map_file: ""\n')
                self.assertTrue(Path(start(context)[0]['parameters'][1]['map_file']).is_file())

    def test_action_pipeline(self):
        rclpy.init()
        peer = rclpy.create_node('navigation_flow_peer')
        bridge = FakeVelTransform()
        executor = rclpy.executors.SingleThreadedExecutor()
        executor.add_node(peer)
        executor.add_node(bridge)
        tf = TransformBroadcaster(peer)
        static = StaticTransformBroadcaster(peer)
        t = TransformStamped()
        t.header.stamp = peer.get_clock().now().to_msg()
        t.header.frame_id, t.child_frame_id = 'map', 'odom'
        t.transform.translation.x, t.transform.translation.y = 3.0, 2.0
        t.transform.rotation.z = t.transform.rotation.w = math.sqrt(0.5)
        static.sendTransform(t)
        lio = peer.create_publisher(Odometry, '/Odometry', 10)
        chassis = peer.create_publisher(ChassisOdom, '/ChassisOdom', 10)
        commands = []
        peer.create_subscription(Twist, '/cmd_vel_gimbal', commands.append, 10)
        client = ActionClient(peer, Navigate, '/navigate')
        params = '''nav_server:
  ros__parameters:
    enable_static_layer: false
    enable_dynamic_layer: false
    enable_esdf: false
    control_rate: 50.0
    goal_tolerance: 0.10
    goal_timeout: 20.0
    controller_timeout: 10.0
    base_frame: base_link_fake
    nmpc:
      esdf_weight: 0.0
      odom_feedback_alpha: 0.8
      max_linear_vel: 0.5
      speed_profile:
        v_cruise: 0.4
'''
        x = y = vx = vy = 0.0
        origin = time.monotonic()
        previous = origin
        def pump(duration=0.04, localization=True, move=True):
            nonlocal x, y, vx, vy, previous
            end = time.monotonic() + duration
            while time.monotonic() < end:
                now = time.monotonic()
                dt = min(0.03, now-previous)
                previous = now
                yaw = 0.4 + 0.3*(now-origin)  # radar reference rotates independently
                if commands and move:
                    cmd = commands[-1]
                    vx = math.cos(yaw)*cmd.linear.x-math.sin(yaw)*cmd.linear.y
                    vy = math.sin(yaw)*cmd.linear.x+math.cos(yaw)*cmd.linear.y
                    x += vx*dt
                    y += vy*dt
                else:
                    vx = vy = 0.0
                if localization:
                    msg = Odometry()
                    msg.header.stamp = peer.get_clock().now().to_msg()
                    msg.header.frame_id, msg.child_frame_id = 'odom', 'base_link'
                    msg.pose.pose.position.x, msg.pose.pose.position.y = x, y
                    msg.pose.pose.orientation.z = math.sin(yaw/2)
                    msg.pose.pose.orientation.w = math.cos(yaw/2)
                    lio.publish(msg)
                    dynamic = TransformStamped()
                    dynamic.header = msg.header
                    dynamic.child_frame_id = 'base_link'
                    dynamic.transform.translation.x, dynamic.transform.translation.y = x, y
                    dynamic.transform.rotation = msg.pose.pose.orientation
                    tf.sendTransform(dynamic)
                    chassis.publish(ChassisOdom(
                        speed_x=math.cos(yaw)*vx+math.sin(yaw)*vy,
                        speed_y=-math.sin(yaw)*vx+math.cos(yaw)*vy))
                for _ in range(5):
                    executor.spin_once(timeout_sec=0.002)
        def wait(future, seconds=5, **kwargs):
            deadline = time.monotonic()+seconds
            while not future.done() and time.monotonic()<deadline:
                pump(**kwargs)
            self.assertTrue(future.done(), 'action future timed out')
            return future.result()
        def goal(gx, gy, frame='odom'):
            request = Navigate.Goal()
            request.goal_pose.header.frame_id = frame
            request.goal_pose.pose.position.x, request.goal_pose.pose.position.y = gx, gy
            request.goal_pose.pose.orientation.w = 1.0
            handle = wait(client.send_goal_async(request))
            self.assertTrue(handle.accepted)
            return handle
        try:
            with tempfile.TemporaryDirectory(prefix='navigation_flow_') as directory:
                config = Path(directory)/'params.yaml'
                config.write_text(params)
                log_path = Path(directory)/'server.log'
                with log_path.open('w') as log:
                    executable = Path(get_package_prefix('nav_components'))/'lib/nav_components/nav_server'
                    process = subprocess.Popen([str(executable), '--ros-args', '--params-file', str(config)],
                                               stdout=log, stderr=subprocess.STDOUT)
                    try:
                        deadline=time.monotonic()+8
                        while not client.server_is_ready() and time.monotonic()<deadline:
                            pump()
                            self.assertIsNone(process.poll(), log_path.read_text())
                        self.assertTrue(client.server_is_ready(), log_path.read_text())
                        pump(0.4)
                        handle = goal(0.0,0.6)  # genuine lateral motion; goal transform map<-odom must be applied
                        result = wait(handle.get_result_async(), seconds=12)
                        self.assertTrue(result.result.success, log_path.read_text())
                        self.assertLess(abs(x),0.15)
                        self.assertGreater(y,0.45)
                        self.assertTrue(any(abs(c.linear.y)>0.02 for c in commands))
                        self.assertTrue(all(c.angular.z==0 for c in commands))
                        # New target preempts a running action; old result must terminate.
                        first=goal(1.5,y)
                        old_result=first.get_result_async()
                        second=goal(-1.0,y)
                        self.assertFalse(wait(old_result).result.success)
                        # Cancellation must finish even with TF/LIO absent.
                        pump(0.25,localization=False,move=False)
                        cancel=wait(second.cancel_goal_async(),localization=False,move=False)
                        self.assertTrue(cancel.goals_canceling)
                        canceled=wait(second.get_result_async(),localization=False,move=False)
                        self.assertFalse(canceled.result.success)
                        pump(0.05,localization=False,move=False)
                        self.assertEqual(commands[-1].linear.x,0)
                        self.assertEqual(commands[-1].linear.y,0)
                    except Exception:
                        print(log_path.read_text())
                        raise
                    finally:
                        process.terminate()
                        try: process.wait(timeout=5)
                        except subprocess.TimeoutExpired:
                            process.kill(); process.wait()
        finally:
            client.destroy()
            executor.shutdown()
            bridge.destroy_node()
            peer.destroy_node()
            rclpy.shutdown()

if __name__=='__main__':
    unittest.main()
