"""Exercise the real NavServer/adapter with controlled pose and mechanism feedback.

No Gazebo or motor commands are executed. Uses its own ROS domain (set by caller).
"""
import math
import os
from pathlib import Path
import subprocess
import tempfile
import time

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import QoSProfile, DurabilityPolicy
from geometry_msgs.msg import TransformStamped
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64, Bool
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster
from nav_interfaces.action import Navigate
from nav_interfaces.msg import NavigationPlan, HoleTraversalState
from nav_interfaces.msg import HoleStructureRequest, HoleStructureFeedback
import yaml

ROOT = Path(__file__).resolve().parents[1]
PREPARE, STOP, CONTINUE = 1, 1, 0


def check():
    with tempfile.TemporaryDirectory(prefix='seu_prepare_ros_') as directory:
        tmp = Path(directory)
        hole = yaml.safe_load((ROOT / 'src/my_navigation/nav_bringup/config/hole_state_machine.yaml').read_text())
        hole['hole_state_machine'].update(flat_speed=3., prepare_speed=.001)
        # Legacy prepare_speed is deliberately present: it must no longer cap motion.
        (tmp / 'hole.yaml').write_text(yaml.safe_dump(hole))
        params = yaml.safe_load((ROOT / 'sim/nav_params.yaml').read_text())
        params['nav_server']['ros__parameters'].update(use_sim_time=False, controller_timeout=30.)
        params['nav_server']['ros__parameters']['hole_state_machine']['config_file'] = str(tmp / 'hole.yaml')
        (tmp / 'nav.yaml').write_text(yaml.safe_dump(params))
        environment = dict(os.environ, ROS_LOG_DIR=str(tmp / 'ros'))
        os.environ['ROS_LOG_DIR'] = str(tmp / 'ros')
        process = None
        rclpy.init()
        node = Node('prepare_at_a_probe')
        seen = dict(plan=None, state=None, request=None, heading=float('nan'), inhibit=False)
        qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)
        node.create_subscription(NavigationPlan, 'navigation_plan', lambda m: seen.update(plan=m), qos)
        node.create_subscription(HoleTraversalState, 'hole_traversal_state', lambda m: seen.update(state=m), 10)
        node.create_subscription(HoleStructureRequest, 'hole_structure/request', lambda m: seen.update(request=m), 10)
        node.create_subscription(Float64, 'hole_alignment_target', lambda m: seen.update(heading=m.data), 10)
        node.create_subscription(Bool, 'hole_rotation_inhibit', lambda m: seen.update(inhibit=m.data), 10)
        odom = node.create_publisher(Odometry, '/Odometry', 10)
        fake = node.create_publisher(Odometry, '/Odometry/fake', 10)
        rotation = node.create_publisher(JointState, '/rotation/feedback', 10)
        feedback = node.create_publisher(HoleStructureFeedback, 'hole_structure/feedback', 10)
        dynamic = TransformBroadcaster(node)
        static = StaticTransformBroadcaster(node)
        transform = TransformStamped()
        transform.header.frame_id = 'map'
        transform.child_frame_id = 'odom'
        transform.transform.rotation.w = 1.
        static.sendTransform(transform)
        position = [-3.22494, -5.07467]
        sample = dict(speed=0., yaw=0., rate=.5, completed=False, clock_offset=0., velocity_enabled=True)

        def publish():
            stamp = node.get_clock().now().to_msg()
            for child, publisher in [('base_link', odom), ('base_link_fake', fake)]:
                if child == 'base_link_fake' and not sample['velocity_enabled']:
                    continue
                m = Odometry()
                m.header.stamp = (rclpy.time.Time.from_msg(stamp) +
                    rclpy.duration.Duration(seconds=sample['clock_offset'] if child == 'base_link_fake' else 0.)).to_msg()
                m.header.frame_id = 'odom'
                m.child_frame_id = child
                m.pose.pose.position.x, m.pose.pose.position.y = position
                m.pose.pose.orientation.w = 1.
                m.twist.twist.linear.x = sample['speed']
                publisher.publish(m)
            transforms = []
            for child in ('base_link', 'base_link_fake', 'chassiss'):
                t = TransformStamped()
                t.header.stamp = stamp
                t.header.frame_id = 'odom'
                t.child_frame_id = child
                t.transform.translation.x, t.transform.translation.y = position
                t.transform.rotation.z = math.sin(sample['yaw'] / 2)
                t.transform.rotation.w = math.cos(sample['yaw'] / 2)
                transforms.append(t)
            dynamic.sendTransform(transforms)
            r = JointState()
            r.header.stamp = (rclpy.time.Time.from_msg(stamp) +
                rclpy.duration.Duration(seconds=sample['clock_offset'])).to_msg()
            r.header.frame_id = 'odom'
            r.name = ['chassis_world_yaw', 'gimbal_world_yaw']
            r.position = [sample['yaw'], sample['yaw']]
            r.velocity = [sample['rate'], sample['rate']]
            rotation.publish(r)
            request = seen['request']
            if request is not None and not request.cancel_motion:
                f = HoleStructureFeedback()
                f.header.stamp = stamp
                f.session_id, f.goal_id = request.session_id, request.goal_id
                f.request_id, f.requirement_revision = request.request_id, request.requirement_revision
                f.target = request.target
                f.status = f.COMPLETED if sample['completed'] else f.EXECUTING
                f.moving_transition_supported = f.simulated = True
                feedback.publish(f)

        node.create_timer(.02, publish)

        def wait(predicate, seconds=5.):
            end = time.monotonic() + seconds
            while time.monotonic() < end:
                rclpy.spin_once(node, timeout_sec=.02)
                if predicate():
                    return
            raise AssertionError(f'condition timed out: state={seen["state"]}')

        def pump(seconds):
            end = time.monotonic() + seconds
            while time.monotonic() < end:
                rclpy.spin_once(node, timeout_sec=.02)

        try:
            with (tmp / 'nav.log').open('w') as log:
                process = subprocess.Popen([str(ROOT / 'install/nav_components/lib/nav_components/nav_server'),
                    '--ros-args', '--params-file', str(tmp / 'nav.yaml')], stdout=log, stderr=subprocess.STDOUT, env=environment)
                client = ActionClient(node, Navigate, 'navigate')
                wait(client.server_is_ready, 15.)
                pump(.5)
                goal = Navigate.Goal()
                goal.goal_pose.header.frame_id = 'map'
                goal.goal_pose.pose.position.x = -5.4892
                goal.goal_pose.pose.position.y = .33412
                goal.goal_pose.pose.orientation.w = 1.
                response = client.send_goal_async(goal)
                wait(response.done)
                assert response.result().accepted
                wait(lambda: seen['plan'] is not None and bool(seen['plan'].passages))
                plan = seen['plan']
                passage = plan.passages[0]
                a, s, e = [event.s_path for event in passage.events[:3]]
                assert 0 < a < s < e, (a, s, e)
                points = [(p.pose.position.x, p.pose.position.y) for p in plan.path.poses]
                arcs = [0.]
                for previous, current in zip(points, points[1:]):
                    arcs.append(arcs[-1] + math.dist(previous, current))

                def move(arc):
                    index = next(i for i in range(1, len(arcs)) if arcs[i] >= arc)
                    ratio = (arc - arcs[index - 1]) / (arcs[index] - arcs[index - 1])
                    position[:] = [x + ratio * (y - x) for x, y in zip(points[index - 1], points[index])]
                    pump(.04)

                arc = 0.
                while arc < a - .06:
                    arc = min(a - .06, arc + .025)
                    move(arc)
                pump(.1)
                assert seen['request'] is None and not math.isfinite(seen['heading'])
                move(a + .015)
                wait(lambda: seen['request'] is not None and math.isfinite(seen['heading']))
                wait(lambda: seen['state'] is not None and seen['state'].state == PREPARE)
                assert a + .015 < s
                assert seen['request'].target == HoleStructureRequest.LOW
                assert seen['state'].speed_limit > .01, 'legacy prepare_speed still limits motion'
                assert not seen['inhibit']
                sample['speed'] = 2.
                wait(lambda: 'emergency' in seen['state'].reason)
                pump(.1)
                assert math.isfinite(seen['heading']) and not seen['inhibit'], 'braking froze alignment'
                sample.update(speed=0., completed=True)
                pump(.35)
                assert seen['state'].decision == STOP, 'LOW alone released entry'
                sample.update(yaw=seen['heading'], rate=0.)
                wait(lambda: seen['state'].decision == CONTINUE)
                assert seen['state'].speed_limit > 1., 'completed preparation remained at the legacy .001 cap'
                print('PASS: A publishes alignment and LOW before S; no prepare cap; emergency preserves alignment; LOW+settled alignment releases braking')
                sample['clock_offset'] = .005
                pump(.7)
                assert seen['state'].decision == CONTINUE, '5ms clock phase rejected healthy feedback'
                print('PASS: 5ms source clock phase retains fresh velocity and rotation feedback')
                sample['velocity_enabled'] = False
                wait(lambda: seen['state'].state == 4)
                assert seen['state'].decision == STOP
                sample['velocity_enabled'] = True
                wait(lambda: seen['state'].state == 2 and seen['state'].decision == CONTINUE)
                print('PASS: actual velocity loss stops; fresh stable feedback restores TRAVERSE automatically')
                arc = a + .015
                while arc < s + .03:
                    arc = min(s + .03, arc + .025)
                    move(arc)
                center = position[:]
                direction = (passage.events[2].point.x - passage.events[1].point.x,
                             passage.events[2].point.y - passage.events[1].point.y)
                length = math.hypot(*direction)
                for offset in (.02, .04, .06, .08, .10, .12, .14, .16):
                    position[:] = [center[0] - offset * direction[1] / length,
                                   center[1] + offset * direction[0] / length]
                    pump(.06)
                pump(.4)
                assert seen['state'].state != 4 and seen['state'].decision == CONTINUE, 'approach lateral error froze correction'
                assert 0 < seen['state'].speed_limit < 1.5, 'uncorrected approach did not retain entry speed bound'
                for offset in (.14, .12, .10, .08, .06, .04, .02, 0.):
                    position[:] = [center[0] - offset * direction[1] / length,
                                   center[1] + offset * direction[0] / length]
                    pump(.06)
                pump(.4)
                assert seen['state'].decision == CONTINUE and seen['state'].speed_limit > 1.5
                print('PASS: 16cm lateral error before E keeps normal correction alive; position recovery removes entry bound')
        except Exception:
            print((tmp / 'nav.log').read_text(errors='replace')[-6000:])
            raise
        finally:
            if process is not None:
                process.terminate()
                try:
                    process.wait(timeout=4)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait(timeout=2)
            node.destroy_node()
            rclpy.try_shutdown()


if __name__ == '__main__':
    check()
