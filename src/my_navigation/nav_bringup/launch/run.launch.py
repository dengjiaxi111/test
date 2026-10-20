#!/usr/bin/env python3
"""
完整导航系统启动文件
启动组件:
  1. small_point_lio - 云台安装 LiDAR-惯性SLAM定位
  2. localization_initializer - NDT 三阶段重定位 (map → odom TF)
  3. pointcloud_obstacle_layer - 点云局部障碍层
  4. fake_vel_transform - 固定虚拟系与速度桥
  5. nav_server - 全向导航 (cmd_vel -> fake转换 -> cmd_vel_gimbal)
  6. RViz2 - 可视化 (含 2D Pose Estimate 支持)
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, PythonExpression
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    OpaqueFunction,
    SetEnvironmentVariable,
    SetLaunchConfiguration,
)
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os
from pathlib import Path
import yaml


def configure_localization_switches(context):
    """从实际选定的参数文件读取开关，命令行显式值优先。"""
    with open(LaunchConfiguration('nav_params_file').perform(context), encoding='utf-8') as stream:
        config = yaml.safe_load(stream)['nav_server']['ros__parameters']
    actions = []
    for name in ('use_static_map_odom', 'debug_reset_odom_to_base_link'):
        explicit = LaunchConfiguration(name).perform(context)
        if explicit:
            normalized = explicit.strip().lower()
            if normalized not in ('true', 'false'):
                raise ValueError(f'{name} 启动参数必须为 true 或 false')
            value = normalized == 'true'
        else:
            value = config.get(name, False)
            if not isinstance(value, bool):
                raise ValueError(f'{name} 必须为 YAML 布尔值 true 或 false')
        actions.append(SetLaunchConfiguration(name, 'true' if value else 'false'))
    return actions


def start_rviz(context):
    """Open the map editor with the same map selection as navigation.launch.py."""
    share = Path(get_package_share_directory('nav_bringup')).resolve()
    repo = next((parent for parent in (share, *share.parents)
                 if (parent / 'map' / 'map.yaml').is_file()
                 and (parent / 'src' / 'tools' / 'pcdtoyaml').is_dir()), None)
    with open(LaunchConfiguration('nav_params_file').perform(context), encoding='utf-8') as stream:
        nav_params = yaml.safe_load(stream)['nav_server']['ros__parameters']
    map_file = (LaunchConfiguration('map_file').perform(context)
                or nav_params.get('map_file')
                or (str(repo / 'map' / 'map.yaml') if repo else
                    str(share / 'maps' / 'map.yaml')))
    terrain_file = (LaunchConfiguration('terrain_file').perform(context)
                    or (str(repo / 'map' / 'terrain.yaml') if repo and
                        Path(map_file).resolve() == repo / 'map' / 'map.yaml' else ''))
    hole_passages_file = (LaunchConfiguration('hole_passages_file').perform(context)
                          or nav_params.get('hole_passages_file')
                          or (str(Path(terrain_file).resolve().parent / 'hole_passages.yaml') if terrain_file else ''))
    if hole_passages_file and terrain_file and not Path(hole_passages_file).is_absolute():
        hole_passages_file = str(Path(terrain_file).resolve().parent / hole_passages_file)
    return [Node(
        package='rviz2', executable='rviz2', name='rviz2',
        arguments=['-d', LaunchConfiguration('rviz_config')],
        parameters=[{'use_sim_time': LaunchConfiguration('use_sim_time')}],
        additional_env={
            'MAP_EDIT_NAV_PARAMS_YAML': LaunchConfiguration('nav_params_file').perform(context),
            'MAP_EDIT_MAP_YAML': map_file,
            'MAP_EDIT_TERRAIN_REGION_YAML': terrain_file,
            'MAP_EDIT_HOLE_PASSAGES_YAML': hole_passages_file,
            'MAP_EDIT_PCD_PATH': LaunchConfiguration('map_edit_pcd_path').perform(context),
        },
        output='screen',
    )]


def generate_launch_description():
    # ==================== 包路径 ====================
    nav_bringup_dir = get_package_share_directory('nav_bringup')
    pointcloud_obstacle_dir = get_package_share_directory('pointcloud_obstacle_layer')
    loc_init_dir = get_package_share_directory('localization_initializer')
    # ==================== 配置文件 ====================
    nav_params_file = os.path.join(nav_bringup_dir, 'config', 'nav_params.yaml')
    loc_init_config = os.path.join(loc_init_dir, 'config', 'initializer_params.yaml')
    
    # === 解析 initialize_params.yaml 获取点云地图路径 ===
    default_pcd_map_file = ''
    try:
        with open(loc_init_config, 'r') as f:
            loc_dict = yaml.safe_load(f)
            if loc_dict and '/**' in loc_dict:
                ros_params = loc_dict['/**'].get('ros__parameters', {})
                default_pcd_map_file = ros_params.get('map_file', '')
    except Exception as e:
        print(f"[Warning] Failed to parse initializer_params.yaml for pcd map_file: {e}")

    local_obstacle_params = os.path.join(
        pointcloud_obstacle_dir, 'config', 'local_obstacle.yaml')
    
    # RViz 配置 - 使用导航专用配置
    rviz_config_file = os.path.join(nav_bringup_dir, 'rviz', 'navigation_full.rviz')
    
    # ==================== Launch 参数 ====================
    declare_nav_params = DeclareLaunchArgument(
        'nav_params_file',
        default_value=nav_params_file,
        description='导航参数文件路径'
    )
    
    declare_local_obstacle_params = DeclareLaunchArgument(
        'local_obstacle_params_file',
        default_value=local_obstacle_params,
        description='点云局部障碍层参数文件路径'
    )
    
    declare_rviz_config = DeclareLaunchArgument(
        'rviz_config',
        default_value=rviz_config_file,
        description='RViz2 配置文件路径'
    )
    
    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='使用仿真时间'
    )

    declare_enable_navigation = DeclareLaunchArgument(
        'enable_navigation', default_value='true',
        description='是否启动全向导航；录包定位检查时可设false'
    )

    declare_enable_lio = DeclareLaunchArgument(
        'enable_lio',
        default_value='true',
        description='true: 启动 small_point_lio; false: 用 bag 中已有的 /cloud_registered、/Odometry 和 odom->base_link'
    )

    declare_lio_params = DeclareLaunchArgument(
        'lio_params_file',
        default_value=PathJoinSubstitution([
            FindPackageShare('small_point_lio'), 'config', 'mid360.yaml'
        ]),
        description='small_point_lio parameter file'
    )

    declare_publish_lidar_tf = DeclareLaunchArgument(
        'publish_lidar_tf',
        default_value='true',
        description='Publish base_link to livox_frame from the navigation workspace'
    )

    declare_enable_rviz = DeclareLaunchArgument(
        'enable_rviz', default_value='true', description='Start RViz2'
    )

    declare_fake_odom_timeout = DeclareLaunchArgument(
        'fake_odom_timeout', default_value='0.2',
        description='Maximum age of LIO odometry accepted by fake_vel_transform'
    )

    declare_feedback_pose_max_skew = DeclareLaunchArgument(
        'feedback_pose_max_skew', default_value='0.1',
        description='Maximum receive-time difference between feedback and LIO pose'
    )

    declare_use_static_map_odom = DeclareLaunchArgument(
        'use_static_map_odom',
        default_value='',
        description='留空读取参数文件；true: RViz 手动定位；false: NDT 重定位（调试模式优先）'
    )

    declare_debug_reset_odom_to_base = DeclareLaunchArgument(
        'debug_reset_odom_to_base_link',
        default_value='',
        description='留空读取参数文件；true: 手动设置规划起点，强制 odom==base_link；false: 正常导航'
    )

    # 调试节点会接管 map->odom，因此正常定位节点在调试模式下必须关闭，避免 TF 冲突。
    normal_ndt_condition = IfCondition(PythonExpression([
        "'", LaunchConfiguration('use_static_map_odom'), "' == 'false' and '",
        LaunchConfiguration('debug_reset_odom_to_base_link'), "' == 'false'"
    ]))
    normal_static_condition = IfCondition(PythonExpression([
        "'", LaunchConfiguration('use_static_map_odom'), "' == 'true' and '",
        LaunchConfiguration('debug_reset_odom_to_base_link'), "' == 'false'"
    ]))

    # ==================== 1. small_point_lio (SLAM定位) ====================
    small_point_lio_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('small_point_lio'),
                'launch',
                'small_point_lio.launch.py'
            ])
        ]),
        launch_arguments={
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'params_file': LaunchConfiguration('lio_params_file'),
            'publish_lidar_tf': LaunchConfiguration('publish_lidar_tf'),
            'odom_tf_topic': PythonExpression([
                "'/debug/lio_tf' if '", LaunchConfiguration('debug_reset_odom_to_base_link'),
                "' == 'true' else '/tf'"
            ]),
        }.items(),
        condition=IfCondition(LaunchConfiguration('enable_lio'))
    )

    fake_vel_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('fake_vel_transform'),
                'launch', 'fake_vel_transform.launch.py'
            ])
        ]),
        launch_arguments={
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'nav_params_file': LaunchConfiguration('nav_params_file'),
            'odom_timeout': LaunchConfiguration('fake_odom_timeout'),
            'feedback_pose_max_skew': LaunchConfiguration('feedback_pose_max_skew'),
        }.items(),
        condition=UnlessCondition(LaunchConfiguration('debug_reset_odom_to_base_link'))
    )

    # ==================== 2. NDT 重定位 (map → odom TF) ====================
    # 启动后请在 RViz 中使用 '2D Pose Estimate' 工具给出初始位姿
    # 配准完成后会发布 map → odom 的静态 TF，替代原来 navigation.launch.py 中的临时 TF
    localization_init_node = Node(
        package='localization_initializer',
        executable='localization_initializer_node',
        name='localization_initializer',
        condition=normal_ndt_condition,
        output='screen',
        parameters=[
            loc_init_config,
            {'auto_initialize': 'false'},
            {'use_sim_time': LaunchConfiguration('use_sim_time')},
        ],
        remappings=[
            ('/cloud_registered', '/cloud_registered'),
            ('/initialpose', '/initialpose'),
            ('/localization/aligned_scan', '/localization/aligned_scan'),
            ('/localization/map_cloud', '/localization/map_cloud'),
            ('/localization/status', '/localization/status'),
            ('/localization/fitness_marker', '/localization/fitness_marker'),
        ]
    )

    # 使用自定义的静态重定位脚本，接收 RViz 的 /initialpose 并转换为 map->odom static TF
    static_tf_map_odom = Node(
        package='nav_bringup',
        executable='static_relocator.py',
        name='static_relocator',
        condition=normal_static_condition,
        parameters=[{
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'initial_pose_override': LaunchConfiguration('static_initial_pose_override'),
            'initial_pose_x': LaunchConfiguration('static_initial_pose_x'),
            'initial_pose_y': LaunchConfiguration('static_initial_pose_y'),
            'initial_pose_yaw': LaunchConfiguration('static_initial_pose_yaw'),
            'fallback_assume_odom_equals_base': LaunchConfiguration('static_initial_pose_fallback'),
            'publish_initial_pose_on_startup': LaunchConfiguration('static_publish_initial_pose'),
        }],
        output='screen'
    )

    # 路径规划调试模式：接管 odom->base_link，并在重定位/设初值后重锚定 map 运动。
    # LIO 原始 TF 已隔离，速度桥暂停；由调试节点维护 fake 控制系的连通性。
    odom_base_debug_rebaser = Node(
        package='nav_bringup',
        executable='odom_base_debug_rebaser.py',
        name='odom_base_debug_rebaser',
        condition=IfCondition(LaunchConfiguration('debug_reset_odom_to_base_link')),
        parameters=[{
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'map_frame': 'map',
            'odom_frame': 'odom',
            'base_frame': 'base_link',
            'fake_frame': 'base_link_fake',
            'odom_topic': '/Odometry',
            'initialpose_topic': '/initialpose',
            'localization_status_topic': '/localization/status',
            'tf_rate_hz': 50.0,
        }],
        output='screen'
    )

    # 静态重定位模式下，依然需要发布点云地图以便在 RViz 中查看
    pcd_map_publisher_node = Node(
        package='pcl_ros',
        executable='pcd_to_pointcloud',
        name='pcd_publisher',
        condition=IfCondition(LaunchConfiguration('use_static_map_odom')),
        parameters=[{
            'file_name': default_pcd_map_file,
            'tf_frame': 'map',
            'use_sim_time': LaunchConfiguration('use_sim_time')
        }],
        remappings=[
            ('cloud_pcd', '/localization/map_cloud')
        ],
        output='screen'
    )

    
    # ==================== 3. 点云局部障碍层 ====================
    # 输出仍使用 /rog_map/map_2d，保持 nav_server 的 dynamic_layer_topic 不变。
    local_obstacle_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('pointcloud_obstacle_layer'),
                'launch',
                'local_obstacle_layer.launch.py'
            ])
        ]),
        launch_arguments={
            'params_file': LaunchConfiguration('local_obstacle_params_file'),
            'use_sim_time': LaunchConfiguration('use_sim_time')
        }.items(),
        condition=UnlessCondition(LaunchConfiguration('debug_reset_odom_to_base_link'))
    )

    
    # ==================== 4. 导航服务器 (规划 + NMPC控制) ====================
    navigation_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('nav_bringup'),
                'launch',
                'navigation.launch.py'
            ])
        ]),
        launch_arguments={
            'params_file': LaunchConfiguration('nav_params_file'),
            'map_file': LaunchConfiguration('map_file'),
            'terrain_file': LaunchConfiguration('terrain_file'),
            'hole_passages_file': LaunchConfiguration('hole_passages_file'),
            'cmd_vel_topic': LaunchConfiguration('cmd_vel_topic'),
            'use_sim_time': LaunchConfiguration('use_sim_time'),
            'max_linear_vel': LaunchConfiguration('max_linear_vel'),
            'max_linear_accel': LaunchConfiguration('max_linear_accel'),
            'cruise_velocity': LaunchConfiguration('cruise_velocity'),
            'pose_timeout': LaunchConfiguration('pose_timeout'),
            'feedback_timeout': LaunchConfiguration('feedback_timeout'),
            'controller_timeout': LaunchConfiguration('controller_timeout'),
            'progress_threshold': LaunchConfiguration('progress_threshold'),
        }.items(),
        condition=IfCondition(LaunchConfiguration('enable_navigation'))
    )
    
    # ==================== 5. RViz2 ====================
    rviz_node = OpaqueFunction(
        function=start_rviz,
        condition=IfCondition(LaunchConfiguration('enable_rviz'))
    )
    
    # ==================== Launch Description ====================
    return LaunchDescription([
        # 增加栈空间到 16MB，避免大点云处理时栈溢出
        SetEnvironmentVariable('ROS_STACK_SIZE', '16777216'),

        # 声明参数
        declare_nav_params,
        DeclareLaunchArgument('map_file', default_value=''),
        DeclareLaunchArgument('terrain_file', default_value=''),
        DeclareLaunchArgument('hole_passages_file', default_value='', description='每洞直线范围与路径准备事件参数文件'),
        DeclareLaunchArgument('map_edit_pcd_path', default_value='',
                              description='Optional PCD loaded into the RViz map editor'),
        DeclareLaunchArgument('cmd_vel_topic', default_value='/cmd_vel'),
        DeclareLaunchArgument('max_linear_vel', default_value=''),
        DeclareLaunchArgument('max_linear_accel', default_value=''),
        DeclareLaunchArgument('cruise_velocity', default_value=''),
        DeclareLaunchArgument('pose_timeout', default_value=''),
        DeclareLaunchArgument('feedback_timeout', default_value=''),
        DeclareLaunchArgument('controller_timeout', default_value=''),
        DeclareLaunchArgument('progress_threshold', default_value=''),
        declare_local_obstacle_params,
        declare_rviz_config,
        declare_use_sim_time,
        declare_enable_navigation,
        declare_enable_lio,
        declare_lio_params,
        declare_publish_lidar_tf,
        declare_enable_rviz,
        declare_fake_odom_timeout,
        declare_feedback_pose_max_skew,
        declare_use_static_map_odom,
        declare_debug_reset_odom_to_base,
        OpaqueFunction(function=configure_localization_switches),
        DeclareLaunchArgument('static_initial_pose_override', default_value='false'),
        DeclareLaunchArgument('static_initial_pose_x', default_value='0.0'),
        DeclareLaunchArgument('static_initial_pose_y', default_value='0.0'),
        DeclareLaunchArgument('static_initial_pose_yaw', default_value='0.0'),
        DeclareLaunchArgument('static_initial_pose_fallback', default_value='true'),
        DeclareLaunchArgument('static_publish_initial_pose', default_value='true'),
        
        # 启动节点 (按依赖顺序)
        fake_vel_launch,           # 0. base_link_fake 虚拟控制系、命令和反馈转换
        small_point_lio_launch,    # 1. LIO 里程计 (odom → base_link)
        localization_init_node,    # 2a. NDT 重定位 (map → odom)
        static_tf_map_odom,        # 2b. 静态 TF 模式 (map → odom = 0,0,0 等待 RViz)
        odom_base_debug_rebaser,   # 2c. 调试模式：强制 odom → base_link 为恒等
        pcd_map_publisher_node,    # 2b. 静态 TF 模式下发布地图点云
        local_obstacle_launch,     # 3. 点云局部障碍层 (/cloud_registered -> /rog_map/map_2d)
        navigation_launch,         # 4. 导航服务器 (规划 + NMPC)
        rviz_node,                 # 5. RViz (含 2D Pose Estimate)
    ])
