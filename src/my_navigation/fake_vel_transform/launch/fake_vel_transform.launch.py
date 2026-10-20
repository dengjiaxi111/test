from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution
from fake_vel_transform.config import feedback_policy


def start_bridge(context):
    policy = feedback_policy(LaunchConfiguration('nav_params_file').perform(context))
    return [Node(package='fake_vel_transform', executable='fake_vel_transform_node',
                 name='fake_vel_transform', output='screen',
                 parameters=[policy, {
                     'use_sim_time': LaunchConfiguration('use_sim_time'),
                     'odom_timeout': LaunchConfiguration('odom_timeout'),
                     'feedback_pose_max_skew': LaunchConfiguration('feedback_pose_max_skew'),
                 }])]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        DeclareLaunchArgument('odom_timeout', default_value='0.2'),
        DeclareLaunchArgument('feedback_pose_max_skew', default_value='0.1'),
        DeclareLaunchArgument('nav_params_file', default_value=PathJoinSubstitution([
            FindPackageShare('nav_bringup'), 'config', 'nav_params.yaml'])),
        OpaqueFunction(function=start_bridge),
    ])
