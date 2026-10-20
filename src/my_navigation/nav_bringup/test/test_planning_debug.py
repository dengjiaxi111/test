#!/usr/bin/env python3
"""Verify debug launch isolation and manual planning pose without a lidar."""
import importlib.util
from pathlib import Path
import tempfile
import time
import unittest
import subprocess
import signal
from unittest.mock import patch

import numpy as np
import rclpy
import yaml
from geometry_msgs.msg import PoseWithCovarianceStamped, PoseStamped
from nav_msgs.msg import Odometry, Path as NavPath
from ament_index_python.packages import get_package_prefix
from tf2_msgs.msg import TFMessage
from launch import LaunchContext
from launch.actions import IncludeLaunchDescription
from launch.utilities import perform_substitutions, normalize_to_list_of_substitutions
from launch_ros.actions import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
from rcl_interfaces.srv import SetParametersAtomically
from rclpy.parameter import Parameter


PACKAGE = Path(__file__).resolve().parents[1]


def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


run = load_module('debug_launch', PACKAGE / 'launch/run.launch.py')
rebaser = load_module('debug_rebaser', PACKAGE / 'scripts/odom_base_debug_rebaser.py')


def resolve(context, value):
    return perform_substitutions(context, normalize_to_list_of_substitutions(value))


class PlanningDebugTests(unittest.TestCase):
    def test_switches_and_tf_owners(self):
        def package_share(name):
            if name == 'nav_bringup':
                return str(PACKAGE)
            return str(PACKAGE.parents[1] / 'localization' / name)

        with patch.object(run, 'get_package_share_directory', side_effect=package_share):
            description = run.generate_launch_description()
        for static in (False, True):
            for debug in (False, True):
                with self.subTest(static=static, debug=debug), tempfile.NamedTemporaryFile(mode='w') as stream:
                    yaml.safe_dump({'nav_server': {'ros__parameters': {
                        'use_static_map_odom': static,
                        'debug_reset_odom_to_base_link': debug,
                    }}}, stream)
                    stream.flush()
                    context = LaunchContext()
                    context.launch_configurations.update({
                        'nav_params_file': stream.name,
                        'use_static_map_odom': '',
                        'debug_reset_odom_to_base_link': '',
                        'enable_lio': 'true',
                    })
                    for action in run.configure_localization_switches(context):
                        action.execute(context)
                    nodes = {resolve(context, entity.node_executable): entity
                             for entity in description.entities if isinstance(entity, Node)}
                    self.assertEqual(nodes['odom_base_debug_rebaser.py'].condition.evaluate(context), debug)
                    self.assertEqual(nodes['static_relocator.py'].condition.evaluate(context), static and not debug)
                    self.assertEqual(nodes['localization_initializer_node'].condition.evaluate(context), not static and not debug)
                    for entity in description.entities:
                        if not isinstance(entity, IncludeLaunchDescription):
                            continue
                        arguments = dict(entity.launch_arguments)
                        if 'odom_tf_topic' in arguments:
                            topic = resolve(context, arguments['odom_tf_topic'])
                            self.assertEqual(topic, '/debug/lio_tf' if debug else '/tf')
                        elif 'odom_timeout' in arguments or 'params_file' in arguments and 'map_file' not in arguments:
                            self.assertEqual(entity.condition.evaluate(context), not debug)
                    # Explicit launch values must override the selected YAML file.
                    context.launch_configurations['debug_reset_odom_to_base_link'] = 'FALSE' if debug else 'TRUE'
                    for action in run.configure_localization_switches(context):
                        action.execute(context)
                    self.assertEqual(context.launch_configurations['debug_reset_odom_to_base_link'],
                                     'false' if debug else 'true')

    def test_manual_pose_first_odom_and_tf(self):
        rclpy.init()
        node = rebaser.OdomBaseDebugRebaser()
        peer = rclpy.create_node('planning_debug_peer')
        node.fake_frame = 'base_link_fake'
        messages = []
        subscription = peer.create_subscription(TFMessage, '/tf', messages.append, 10)
        initial = PoseWithCovarianceStamped()
        initial.header.frame_id = 'map'
        initial.pose.pose.position.x = 3.0
        initial.pose.pose.position.y = 4.0
        initial.pose.pose.orientation.w = 1.0
        try:
            node.initialpose_callback(initial)
            node.timer_callback()
            self.assertTrue(node.has_anchor)
            self.assertTrue(node.awaiting_anchor_odom)
            odom = Odometry()
            odom.header.frame_id, odom.child_frame_id = 'odom', 'base_link'
            odom.pose.pose.orientation.w = 1.0
            odom.pose.pose.position.x = 100.0
            node.odom_callback(odom)
            self.assertFalse(node.awaiting_anchor_odom)
            # First odometry sample establishes the anchor instead of jumping by 100 m.
            np.testing.assert_allclose(node.anchor_odom_to_base[:3, 3], [100, 0, 0])
            moved = Odometry()
            moved.header.frame_id, moved.child_frame_id = 'odom', 'base_link'
            moved.pose.pose.orientation.w = 1.0
            moved.pose.pose.position.x = 102.0
            node.odom_callback(moved)
            deadline = time.monotonic() + 2.0
            while time.monotonic() < deadline:
                node.timer_callback()
                # A timer tick publishes two TF messages; drain both before the next tick.
                for _ in range(3):
                    rclpy.spin_once(peer, timeout_sec=0.01)
                transforms = {(tf.header.frame_id, tf.child_frame_id): tf
                              for msg in messages for tf in msg.transforms}
                if ('map', 'odom') in transforms:
                    tf = transforms[('map', 'odom')]
                    if abs(tf.transform.translation.x - 5.0) < 1e-8:
                        break
            self.assertEqual(set(transforms), {('map', 'odom'), ('odom', 'base_link'),
                                               ('base_link', 'base_link_fake')})
            self.assertAlmostEqual(transforms[('map', 'odom')].transform.translation.x, 5.0)
            self.assertAlmostEqual(transforms[('map', 'odom')].transform.translation.y, 4.0)
            for pair in [('odom', 'base_link'), ('base_link', 'base_link_fake')]:
                self.assertEqual(transforms[pair].transform.translation.x, 0.0)
                self.assertEqual(transforms[pair].transform.rotation.w, 1.0)
            initial.header.frame_id = 'odom'
            node.initialpose_callback(initial)
            self.assertIsNone(node.pending_initialpose_mat)
        finally:
            peer.destroy_subscription(subscription)
            peer.destroy_node()
            node.destroy_node()
            rclpy.shutdown()

    def test_real_nav_server_plans_from_manual_pose(self):
        self.check_real_nav_plan((2.0, 2.0), (4.0, 2.0))

    def test_real_nav_server_generates_centerline_path(self):
        with tempfile.TemporaryDirectory(prefix='centerline_planning_') as directory:
            terrain = Path(directory) / 'terrain.yaml'
            terrain.write_text(yaml.safe_dump({'regions': [{
                'id': 'test_hole', 'type': 'low_clearance', 'frame_id': 'map',
                'geometry': {'polygon': [[-2, 0], [2, 0], [2, 1], [-2, 1]]},
                'traversal': {'passable_edges': [0, 2], 'bidirectional': True},
            }]}))
            self.check_real_nav_plan((0.65, -2.05), (0.65, 2.05), {
                'terrain_file': str(terrain),
                'hole_planner': {'enabled': True, 'mode': 'centerline'},
            }, centerline=True)

    def test_real_nav_server_optimizes_both_modes_sideways_exit(self):
        with tempfile.TemporaryDirectory(prefix='optimized_sideways_exit_') as directory:
            terrain = Path(directory) / 'terrain.yaml'
            terrain.write_text(yaml.safe_dump({'regions': [{
                'id': 'test_hole', 'type': 'low_clearance', 'frame_id': 'map',
                'geometry': {'polygon': [[-2, 0], [2, 0], [2, 1], [-2, 1]]},
                'traversal': {'passable_edges': [0, 2], 'bidirectional': True},
            }]}))
            for mode in ('centerline', 'free'):
                with self.subTest(mode=mode):
                    self.check_real_nav_plan((0.65, -2.05), (1.85, 1.45), {
                        'terrain_file': str(terrain),
                        'hole_planner': {
                            'enabled': True, 'mode': mode,
                            'global': {'enabled': False},
                            'approach': {'search_prepare_distance': False},
                            'departure': {'exit_straight_length': 0.2, 'departure_distance': 0.4},
                        },
                    }, centerline=mode == 'centerline',
                        centerline_ys=[-1.5, -0.8, 0.0, 1.0, 1.2, 1.4],
                        free_lines=(0.8, 0.2) if mode == 'free' else None, max_length=8.0)

    def test_real_nav_server_skips_nearby_hole_for_ordinary_route(self):
        with tempfile.TemporaryDirectory(prefix='ordinary_nearby_hole_') as directory:
            terrain = Path(directory) / 'terrain.yaml'
            terrain.write_text(yaml.safe_dump({'regions': [{
                'id': 'nearby_hole', 'type': 'low_clearance', 'frame_id': 'map',
                'geometry': {'polygon': [[1, 3], [5, 3], [5, 4], [1, 4]]},
                'traversal': {'passable_edges': [0, 2]},
            }]}))
            self.check_real_nav_plan((2.0, 2.0), (4.0, 2.0), {
                'terrain_file': str(terrain),
                'hole_planner': {'enabled': True, 'mode': 'centerline', 'search': {'max_expansions': 1}},
            }, ordinary_y=2.0)

    def test_real_nav_server_continuous_two_holes(self):
        with tempfile.TemporaryDirectory(prefix='multi_hole_planning_') as directory:
            terrain = Path(directory) / 'terrain.yaml'
            terrain.write_text(yaml.safe_dump({'regions': [{
                'id': f'hole_{i}', 'type': 'low_clearance', 'frame_id': 'map',
                'geometry': {'polygon': [[-0.8, y], [0.8, y], [0.8, y + 0.3], [-0.8, y + 0.3]]},
                'traversal': {'passable_edges': [0, 2], 'bidirectional': True},
            } for i, y in enumerate((0.0, 1.3))]}))
            pixels = np.full((200, 200), 254, dtype=np.uint8)
            xs = -5.0 + (np.arange(200) + 0.5) * 0.05
            ys = 5.0 - (np.arange(200) + 0.5) * 0.05
            for y in (0.0, 1.3):
                pixels[np.ix_((ys > y) & (ys < y + 0.3), np.abs(xs) > 0.75)] = 0
            image = Path(directory) / 'two_holes.pgm'
            image.write_bytes(b'P5\n200 200\n255\n' + pixels.tobytes())
            map_file = Path(directory) / 'map.yaml'
            map_file.write_text(yaml.safe_dump({'image': str(image), 'resolution': 0.05, 'origin': [-5, -5, 0],
                                              'negate': 0, 'occupied_thresh': 0.65, 'free_thresh': 0.25}))
            common = {'map_file': str(map_file), 'enable_static_layer': True, 'terrain_file': str(terrain),
                      'inflation': {'radius': 0.0, 'inscribed_radius': 0.0}}
            for mode in ('centerline', 'free'):
                with self.subTest(mode=mode):
                    self.check_real_nav_plan((0.35, -2.05), (0.35, 3.05), {**common,
                        'hole_planner': {'enabled': True, 'mode': mode,
                                         'approach': {'search_prepare_distance': False}},
                    }, centerline=mode == 'centerline',
                        centerline_ys=[-1.5, -0.8, -0.2, 0.0, 0.3, 0.5, 0.8, 1.1, 1.3, 1.6, 2.1, 2.4],
                        passage_lines=[(0.0, 0.8, -1), (0.3, 0.5, 1), (1.3, 0.8, -1), (1.6, 0.5, 1)],
                        max_length=8.0)
            self.check_real_nav_plan((0.0, 0.1), (0.0, 3.05), {**common,
                'hole_planner': {'enabled': True, 'mode': 'centerline'},
            }, required_points=[(0.0, y) for y in (0.1, 0.3, 0.5, 0.8, 1.1, 1.3, 1.6, 2.1, 2.4)], max_length=3.0)

    def test_normal_navigation_replans_with_global_distances(self):
        rclpy.init()
        peer = rclpy.create_node('normal_hole_parameter_peer')
        broadcaster = TransformBroadcaster(peer)
        paths = []
        peer.create_subscription(NavPath, '/plan', paths.append, 10)
        goal_pub = peer.create_publisher(PoseStamped, '/goal_pose', 10)
        client = peer.create_client(SetParametersAtomically, '/nav_server/set_parameters_atomically')
        transform = TransformStamped()
        transform.header.frame_id, transform.child_frame_id = 'map', 'base_link_fake'
        transform.transform.translation.x, transform.transform.translation.y = 0.65, -2.05
        transform.transform.rotation.w = 1.0

        def wait_for(predicate, timeout=6.0):
            deadline = time.monotonic() + timeout
            while time.monotonic() < deadline:
                self.assertIsNone(process.poll())
                transform.header.stamp = peer.get_clock().now().to_msg()
                broadcaster.sendTransform(transform)
                rclpy.spin_once(peer, timeout_sec=0.02)
                if predicate():
                    return
            log.flush()
            log.seek(0)
            self.fail(log.read())

        def check_points(path, ys):
            points = [(p.pose.position.x, p.pose.position.y) for p in path.poses]
            indices = []
            for y in ys:
                matches = [i for i, (x, py) in enumerate(points) if abs(x) < 1e-8 and abs(py - y) < 1e-8]
                closest=sorted(points,key=lambda p: abs(p[0])+abs(p[1]-y))[:3]
                self.assertTrue(matches, f'missing normal navigation waypoint y={y}, closest={closest}')
                indices.append(matches[0])
            self.assertEqual(indices, sorted(indices))
            self.assertTrue(all(abs(x) < 1e-8 for x, _ in points[indices[1]:indices[4] + 1]))

        try:
            with tempfile.TemporaryDirectory(prefix='normal_hole_parameters_') as directory:
                terrain = Path(directory) / 'terrain.yaml'
                terrain.write_text(yaml.safe_dump({'regions': [{
                    'id': 'test_hole', 'type': 'low_clearance', 'frame_id': 'map',
                    'geometry': {'polygon': [[-2, 0], [2, 0], [2, 1], [-2, 1]]},
                    'traversal': {'passable_edges': [0, 2], 'prepare_distance': 0.4,
                                  'entry_straight_length': 0.2, 'exit_straight_length': 0.1,
                                  'departure_distance': 0.3},
                }]}))
                config = Path(directory) / 'params.yaml'
                config.write_text(yaml.safe_dump({'nav_server': {'ros__parameters': {
                    'enable_static_layer': False, 'enable_dynamic_layer': False, 'enable_esdf': False,
                    'base_frame': 'base_link_fake', 'terrain_file': str(terrain),
                    'nmpc': {'esdf_weight': 0.0},
                    'hole_planner': {'enabled': True, 'mode': 'centerline', 'use_global_distances': True,
                                     'approach': {'search_prepare_distance': False}},
                }}}))
                executable = Path(get_package_prefix('nav_components')) / 'lib/nav_components/nav_server'
                with (Path(directory) / 'server.log').open('w+') as log:
                    process = subprocess.Popen([str(executable), '--ros-args', '--params-file', str(config)],
                                               stdout=log, stderr=subprocess.STDOUT)
                    try:
                        wait_for(lambda: goal_pub.get_subscription_count() > 0 and client.service_is_ready())
                        goal = PoseStamped()
                        goal.header.frame_id = 'map'
                        goal.pose.position.x, goal.pose.position.y = 0.65, 2.05
                        goal.pose.orientation.w = 1.0
                        goal_pub.publish(goal)
                        wait_for(lambda: any(p.poses for p in paths))
                        check_points(next(p for p in paths if p.poses), [-1.5, -0.8, 0.0, 1.0, 1.5, 1.8])
                        first_count = len(paths)
                        request = SetParametersAtomically.Request()
                        request.parameters = [Parameter(name, value=value).to_parameter_msg() for name, value in [
                            ('hole_planner.approach.prepare_distance', 1.8),
                            ('hole_planner.approach.entry_straight_length', 1.0),
                            ('hole_planner.departure.exit_straight_length', 0.7),
                            ('hole_planner.departure.departure_distance', 1.0),
                            ('hole_planner.use_global_distances', True),
                        ]]
                        future = client.call_async(request)
                        wait_for(future.done)
                        self.assertTrue(future.result().result.successful, future.result().result.reason)
                        wait_for(lambda: any(p.poses for p in paths[first_count:]))
                        updated = next(p for p in paths[first_count:] if p.poses)
                        check_points(updated, [-1.8, -1.0, 0.0, 1.0, 1.7, 2.0])
                        self.assertTrue(any(not p.poses for p in paths[first_count:]), 'old path was not cleared before replan')
                        count = len(paths)
                        request.parameters = [Parameter('hole_planner.approach.entry_straight_length', value=3.0).to_parameter_msg()]
                        future = client.call_async(request)
                        wait_for(future.done)
                        self.assertFalse(future.result().result.successful)
                        end = time.monotonic() + 0.3
                        wait_for(lambda: time.monotonic() >= end)
                        self.assertEqual(len(paths), count, 'rejected parameters changed the active path')
                    finally:
                        process.send_signal(signal.SIGINT)
                        try:
                            process.wait(timeout=5.0)
                        except subprocess.TimeoutExpired:
                            process.kill()
                            process.wait()
        finally:
            peer.destroy_node()
            rclpy.shutdown()

    def test_real_nav_server_actual_map_two_holes(self):
        project = PACKAGE.parents[2]
        parameters = yaml.safe_load((PACKAGE / 'config/nav_params.yaml').read_text())['nav_server']['ros__parameters']
        parameters.update({'map_file': str(project / 'map/map.yaml'), 'terrain_file': str(project / 'map/terrain.yaml'),
                           'enable_dynamic_layer': False, 'base_frame': 'base_link_fake'})
        # 包括用户截图的起终点，检查安装后的节点最终发布的 /plan。
        for start, goal, reverse in [((6.82189, -1.35343), (-6.72366, 1.21869), False),
                                     ((-6.72366, 1.21869), (6.82189, -1.35343), True)]:
            if not reverse:
                segments = [((4.694, 6.019), (4.694, 7.169)), ((0.049, 7.604), (-1.091, 7.604))]
                alternative = [((1.809, -4.306), (0.649, -4.306)), ((-4.6935, -4.581), (-4.6935, -3.431))]
            else:
                segments = [((-1.791, 7.604), (-0.651, 7.604)), ((4.694, 7.869), (4.694, 6.719))]
                alternative = [((-4.6935, -2.731), (-4.6935, -3.881)), ((-0.051, -4.306), (1.109, -4.306))]
            with self.subTest(reverse=reverse):
                self.check_real_nav_plan(start, goal, parameters, straight_segment_options=[segments, alternative], max_length=30.0)

    def check_real_nav_plan(self, start_xy, goal_xy, parameters=None, centerline=False, ordinary_y=None,
                            centerline_ys=None, free_lines=None, max_length=None, passage_lines=None, required_points=None,
                            straight_segments=None, straight_segment_options=None):
        rclpy.init()
        node = rebaser.OdomBaseDebugRebaser()
        node.fake_frame = 'base_link_fake'
        peer = rclpy.create_node('debug_planning_peer')
        executor = rclpy.executors.SingleThreadedExecutor()
        executor.add_node(node)
        executor.add_node(peer)
        paths = []
        peer.create_subscription(NavPath, '/plan', paths.append, 10)
        initial_pub = peer.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)
        goal_pub = peer.create_publisher(PoseStamped, '/goal_pose', 10)
        initial = PoseWithCovarianceStamped()
        initial.header.frame_id = 'map'
        initial.pose.pose.position.x, initial.pose.pose.position.y = start_xy
        initial.pose.pose.orientation.w = 1.0
        goal = PoseStamped()
        goal.header.frame_id = 'map'
        goal.pose.position.x, goal.pose.position.y = goal_xy
        goal.pose.orientation.w = 1.0
        try:
            with tempfile.TemporaryDirectory(prefix='manual_planning_') as directory:
                config = Path(directory) / 'params.yaml'
                settings = {
                    'enable_static_layer': False, 'enable_dynamic_layer': False,
                    'enable_esdf': False, 'base_frame': 'base_link_fake',
                    'nmpc': {'esdf_weight': 0.0},
                }
                settings.update(parameters or {})
                config.write_text(yaml.safe_dump({'nav_server': {'ros__parameters': settings}}))
                executable = Path(get_package_prefix('nav_components')) / 'lib/nav_components/nav_server'
                with (Path(directory) / 'server.log').open('w+') as log:
                    process = subprocess.Popen([str(executable), '--ros-args', '--params-file', str(config)],
                                               stdout=log, stderr=subprocess.STDOUT)
                    try:
                        deadline = time.monotonic() + 8.0
                        sent = False
                        last_initial = 0.0
                        while not paths and time.monotonic() < deadline:
                            self.assertIsNone(process.poll())
                            if not node.has_anchor and time.monotonic() - last_initial > 0.2:
                                initial.header.stamp = peer.get_clock().now().to_msg()
                                initial_pub.publish(initial)
                                last_initial = time.monotonic()
                            # Wait until nav_server subscribes, then send a single goal.
                            if node.has_anchor and goal_pub.get_subscription_count() and not sent:
                                goal.header.stamp = peer.get_clock().now().to_msg()
                                goal_pub.publish(goal)
                                sent = True
                            executor.spin_once(timeout_sec=0.02)
                        log.flush()
                        log.seek(0)
                        self.assertTrue(paths, log.read())
                        self.assertEqual(paths[0].header.frame_id, 'map')
                        self.assertAlmostEqual(paths[0].poses[0].pose.position.x, start_xy[0], delta=0.1)
                        self.assertAlmostEqual(paths[0].poses[-1].pose.position.x, goal_xy[0], delta=0.1)
                        if ordinary_y is not None:
                            self.assertTrue(all(abs(p.pose.position.y - ordinary_y) < 0.1 for p in paths[0].poses),
                                            'ordinary navigation was diverted toward the nearby hole')
                        points = np.array([(pose.pose.position.x, pose.pose.position.y) for pose in paths[0].poses])
                        arc = np.r_[0.0, np.cumsum(np.linalg.norm(np.diff(points, axis=0), axis=1))]
                        if max_length is not None:
                            self.assertLess(arc[-1], max_length, 'sideways exit still makes a long detour')
                        for point in required_points or []:
                            self.assertTrue(np.any(np.linalg.norm(points - point, axis=1) < 1e-7), f'missing remaining point {point}')
                        if straight_segment_options:
                            options = [segments for segments in straight_segment_options if all(
                                np.any(np.linalg.norm(points - point, axis=1) < 1e-7)
                                for segment in segments for point in segment)]
                            self.assertTrue(options, 'neither legal two-hole sequence has its complete fixed segments')
                            straight_segments = options[0]
                        previous = -1
                        for begin, end in straight_segments or []:
                            start_matches = np.flatnonzero(np.linalg.norm(points - begin, axis=1) < 1e-7)
                            end_matches = np.flatnonzero(np.linalg.norm(points - end, axis=1) < 1e-7)
                            self.assertTrue(len(start_matches) and len(end_matches), f'missing fixed segment {begin} -> {end}')
                            lo, hi = start_matches[0], end_matches[0]
                            self.assertGreater(lo, previous)
                            self.assertGreater(hi, lo)
                            axis = np.asarray(end) - begin
                            delta = points[lo:hi + 1] - begin
                            self.assertTrue(np.all(np.abs(delta[:, 0] * axis[1] - delta[:, 1] * axis[0]) < 1e-7))
                            self.assertTrue(np.all(np.diff(delta @ axis) > 0), 'fixed segment reverses direction')
                            previous = hi
                        if centerline:
                            indices = []
                            for y in centerline_ys or [-1.5, -0.8, 0.0, 1.0, 1.5, 1.8]:
                                candidates = [i for i, (x, py) in enumerate(points)
                                              if abs(x) < 1e-8 and abs(py - y) < 1e-8]
                                self.assertTrue(candidates, f'missing centerline point y={y}')
                                indices.append(candidates[0])
                            self.assertEqual(indices, sorted(indices))
                            self.assertTrue(all(abs(x) < 1e-8 for x, y in points[indices[1]:indices[4] + 1]))
                        lines = passage_lines or ([(0.0, free_lines[0], -1), (1.0, free_lines[1], 1)] if free_lines else [])
                        if lines:
                            for y, length, sign in lines:
                                crossing = np.flatnonzero(np.abs(points[:, 1] - y) < 1e-8)
                                self.assertGreater(len(crossing), 0, f'missing free crossing y={y}')
                                index = crossing[0]
                                endpoints = np.flatnonzero(np.abs(arc - (arc[index] + sign * length)) < 1e-7)
                                self.assertGreater(len(endpoints), 0, f'missing free straight length={length}')
                                lo, hi = sorted([index, endpoints[0]])
                                straight = points[lo:hi + 1] - points[lo]
                                axis = points[hi] - points[lo]
                                self.assertAlmostEqual(np.linalg.norm(axis), length, delta=1e-7)
                                self.assertTrue(np.all(np.abs(straight[:, 0] * axis[1] - straight[:, 1] * axis[0]) < 1e-7),
                                                'free straight was changed by optimization')
                    finally:
                        process.send_signal(signal.SIGINT)
                        try:
                            process.wait(timeout=5.0)
                        except subprocess.TimeoutExpired:
                            process.kill()
                            process.wait()
        finally:
            executor.shutdown()
            peer.destroy_node()
            node.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    unittest.main()
