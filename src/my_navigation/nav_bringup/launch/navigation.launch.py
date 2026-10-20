#!/usr/bin/env python3
"""Omnidirectional navigation. Map/command overrides are resolved at launch time."""
import os
from pathlib import Path
import yaml
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def workspace_map_paths():
    """Find the paired map/terrain files without a machine-specific path."""
    share = Path(get_package_share_directory('nav_bringup')).resolve()
    repo = next((parent for parent in (share, *share.parents)
                 if (parent / 'map' / 'map.yaml').is_file()
                 and (parent / 'src' / 'tools' / 'pcdtoyaml').is_dir()), None)
    if repo is None:
        return None, None
    return repo / 'map' / 'map.yaml', repo / 'map' / 'terrain.yaml'



def start_navigation(context):
    params_file = LaunchConfiguration('params_file').perform(context)
    with open(params_file, encoding='utf-8') as stream:
        config = yaml.safe_load(stream)['nav_server']['ros__parameters']
    repo_map, repo_terrain = workspace_map_paths()
    map_file = (LaunchConfiguration('map_file').perform(context)
                or config.get('map_file')
                or (str(repo_map) if repo_map else
                    os.path.join(get_package_share_directory('nav_bringup'), 'maps', 'map.yaml')))
    # A custom occupancy map must not silently receive this workspace's terrain.
    terrain_file = (LaunchConfiguration('terrain_file').perform(context)
                    or (str(repo_terrain) if repo_terrain and
                        Path(map_file).resolve() == repo_map else ''))
    hole_passages_file = (LaunchConfiguration('hole_passages_file').perform(context)
                          or config.get('hole_passages_file')
                          or (str(Path(terrain_file).resolve().parent / 'hole_passages.yaml') if terrain_file else ''))
    if hole_passages_file and terrain_file and not Path(hole_passages_file).is_absolute():
        hole_passages_file = str(Path(terrain_file).resolve().parent / hole_passages_file)
    speed_overrides = {}
    for argument, parameter in (
        ('max_linear_vel', 'nmpc.max_linear_vel'),
        ('max_linear_accel', 'nmpc.max_linear_accel'),
        ('cruise_velocity', 'nmpc.speed_profile.v_cruise'),
        ('pose_timeout', 'nmpc.pose_timeout_sec'),
        ('feedback_timeout', 'nmpc.chassis_velocity_timeout_sec'),
        ('controller_timeout', 'controller_timeout'),
        ('progress_threshold', 'controller_progress_threshold'),
    ):
        value = LaunchConfiguration(argument).perform(context)
        if value:
            speed_overrides[parameter] = float(value)
    return [Node(package='nav_components', executable='nav_server', name='nav_server',
                 parameters=[params_file, {'map_file': map_file},
                             {'terrain_file': terrain_file},
                             {'hole_passages_file': hole_passages_file},
                             {'use_sim_time': LaunchConfiguration('use_sim_time')},
                             speed_overrides],
                 output='screen',
                 remappings=[('cmd_vel', LaunchConfiguration('cmd_vel_topic'))])]


def generate_launch_description():
    package = get_package_share_directory('nav_bringup')
    return LaunchDescription([
        DeclareLaunchArgument('params_file', default_value=os.path.join(package, 'config', 'nav_params.yaml')),
        DeclareLaunchArgument('map_file', default_value='', description='覆盖配置地图；为空时使用配置值或包内map.yaml'),
        DeclareLaunchArgument('terrain_file', default_value='',
                              description='特殊地形 YAML；默认随仓库 map.yaml 加载，可单独覆盖'),
        DeclareLaunchArgument('hole_passages_file', default_value='', description='每洞人工直线范围与准备距离，默认随 Terrain 加载'),
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        DeclareLaunchArgument('max_linear_vel', default_value=''),
        DeclareLaunchArgument('max_linear_accel', default_value=''),
        DeclareLaunchArgument('cruise_velocity', default_value=''),
        DeclareLaunchArgument('pose_timeout', default_value=''),
        DeclareLaunchArgument('feedback_timeout', default_value=''),
        DeclareLaunchArgument('controller_timeout', default_value=''),
        DeclareLaunchArgument('progress_threshold', default_value=''),
        DeclareLaunchArgument('cmd_vel_topic', default_value='/cmd_vel', description='fake系导航速度输出'),
        OpaqueFunction(function=start_navigation),
    ])
