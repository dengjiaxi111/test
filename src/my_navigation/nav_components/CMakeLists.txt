cmake_minimum_required(VERSION 3.8)
project(nav_components)

# 导航搜索使用秒级时间预算；默认构建也启用优化，保留调试符号。
# 显式指定 Debug/Release 等构建类型时仍使用用户选择。
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(nav_interfaces REQUIRED)
find_package(nav_core REQUIRED)
find_package(robots_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(ompl REQUIRED)

set(DEPS
    rclcpp rclcpp_action rcl_interfaces geometry_msgs nav_msgs sensor_msgs std_msgs visualization_msgs tf2 tf2_ros tf2_geometry_msgs nav_interfaces nav_core robots_msgs
)

# 头文件目录
include_directories(include)

# ========== NMPC acados solver 集成 ==========
set(ACADOS_SOLVER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nmpc_solver_omni)
set(ACADOS_SOURCE_DIR "$ENV{ACADOS_SOURCE_DIR}" CACHE PATH "acados install/source prefix")
if(NOT ACADOS_SOURCE_DIR)
    set(ACADOS_SOURCE_DIR "/home/nuc/dependency/acados" CACHE PATH "acados install/source prefix" FORCE)
endif()
set(ACADOS_INCLUDE_DIR ${ACADOS_SOURCE_DIR}/include)
set(ACADOS_LIB_DIR ${ACADOS_SOURCE_DIR}/lib)

if(EXISTS ${ACADOS_SOLVER_DIR}/libacados_ocp_solver_omni_nmpc.so)
    message(STATUS "✓ 找到 NMPC solver: ${ACADOS_SOLVER_DIR}")
    message(STATUS "✓ 使用 acados: ${ACADOS_SOURCE_DIR}")
    
    # 添加 acados include 路径
    include_directories(${ACADOS_SOLVER_DIR})
    
    # 链接 solver 库
    add_library(acados_nmpc_solver SHARED IMPORTED)
    set_target_properties(acados_nmpc_solver PROPERTIES
        IMPORTED_LOCATION ${ACADOS_SOLVER_DIR}/libacados_ocp_solver_omni_nmpc.so
        IMPORTED_NO_SONAME TRUE
    )
    
    set(HAS_NMPC TRUE)
else()
    message(FATAL_ERROR "Missing omni solver: run model_ocp/export_ocp.py first; no fallback to wheelleg/pure pursuit")
    message(WARNING "    请先运行: cd model_ocp && python3 export_ocp.py")
    set(HAS_NMPC FALSE)
endif()

# 导航服务器节点
set(NAV_SERVER_SOURCES
  src/nav_server.cpp
  src/slopehole_controller.cpp
  src/hole_execution_config.cpp
  src/hole_plan_adapter.cpp
  src/slopehole_ros_adapter.cpp
  src/hole_runtime_tuning.cpp
  src/simple_planner.cpp
  src/pure_pursuit.cpp
  src/backup_recovery.cpp
  src/spin_recovery.cpp
  src/arc_backup_recovery.cpp
  src/recovery_manager.cpp
  src/layered_map_manager.cpp
  src/terrain_region_map.cpp
  src/hole_clearance.cpp
  src/hole_geometry_previewer.cpp
  src/hole_passage_planner.cpp
  src/hole_route_planner.cpp
  src/hole_global_planner.cpp
  src/hole_connection_search.cpp
)

add_library(hole_connection_optimizer STATIC src/hole_connection_optimizer.cpp src/hole_feasible_approach.cpp src/normal_navigation_segment.cpp)
ament_target_dependencies(hole_connection_optimizer ${DEPS})

# 如果有 NMPC solver, 添加 NMPC 源文件
if(HAS_NMPC)
    list(APPEND NAV_SERVER_SOURCES src/nmpc.cpp)
    add_compile_definitions(HAS_NMPC_CONTROLLER)
endif()



add_executable(nav_server ${NAV_SERVER_SOURCES})
ament_target_dependencies(nav_server ${DEPS})
target_include_directories(nav_server PRIVATE ${OMPL_INCLUDE_DIRS})
target_link_libraries(nav_server yaml-cpp ${OMPL_LIBRARIES} hole_connection_optimizer)

add_executable(two_point_patrol src/two_point_patrol_node.cpp)
ament_target_dependencies(two_point_patrol ${DEPS})

target_include_directories(nav_server
  PRIVATE
    ${ACADOS_INCLUDE_DIR}
    ${ACADOS_INCLUDE_DIR}/blasfeo/include
    ${ACADOS_INCLUDE_DIR}/hpipm/include
)

# 链接 acados solver
if(HAS_NMPC)
    target_link_libraries(nav_server 
        acados_nmpc_solver
        ${ACADOS_LIB_DIR}/libacados.so
        ${ACADOS_LIB_DIR}/libhpipm.so
        ${ACADOS_LIB_DIR}/libblasfeo.so
    )
endif()

if(HAS_NMPC)
    install(FILES ${ACADOS_SOLVER_DIR}/libacados_ocp_solver_omni_nmpc.so DESTINATION lib)
    set_target_properties(nav_server PROPERTIES INSTALL_RPATH "$ORIGIN/..;${ACADOS_LIB_DIR}")
endif()

install(TARGETS nav_server two_point_patrol DESTINATION lib/${PROJECT_NAME})
install(PROGRAMS scripts/hole_structure_simulator.py DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY include/ DESTINATION include)

# 安装 NMPC 配置文件
if(HAS_NMPC)
    install(DIRECTORY model_ocp/
        DESTINATION share/${PROJECT_NAME}/nmpc_config
        FILES_MATCHING PATTERN "*.yaml"
    )
endif()

if(BUILD_TESTING)
    enable_testing()
    add_executable(test_slopehole_controller test/test_slopehole_controller.cpp src/slopehole_controller.cpp)
    ament_target_dependencies(test_slopehole_controller nav_core)
    target_compile_options(test_slopehole_controller PRIVATE -UNDEBUG)
    add_test(NAME slopehole_controller COMMAND test_slopehole_controller)
    add_executable(test_hole_plan_adapter test/test_hole_plan_adapter.cpp src/hole_plan_adapter.cpp src/terrain_region_map.cpp)
    ament_target_dependencies(test_hole_plan_adapter ${DEPS})
    target_link_libraries(test_hole_plan_adapter yaml-cpp)
    target_compile_options(test_hole_plan_adapter PRIVATE -UNDEBUG)
    add_test(NAME hole_plan_adapter COMMAND test_hole_plan_adapter)

    add_executable(test_hole_passage test/test_hole_passage.cpp
        src/hole_passage_planner.cpp src/hole_route_planner.cpp src/hole_global_planner.cpp src/hole_connection_search.cpp
        src/terrain_region_map.cpp src/simple_planner.cpp
        src/layered_map_manager.cpp src/hole_clearance.cpp)
    ament_target_dependencies(test_hole_passage ${DEPS})
    target_include_directories(test_hole_passage PRIVATE ${OMPL_INCLUDE_DIRS})
    target_link_libraries(test_hole_passage yaml-cpp ${OMPL_LIBRARIES} hole_connection_optimizer)
    add_test(NAME hole_passage COMMAND test_hole_passage
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml)
    set_tests_properties(hole_passage PROPERTIES TIMEOUT 60
        ENVIRONMENT "ROS_DOMAIN_ID=177;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_passage_logs")
    add_executable(test_hole_route test/test_hole_route.cpp src/hole_passage_planner.cpp
        src/hole_route_planner.cpp src/hole_global_planner.cpp src/hole_connection_search.cpp src/terrain_region_map.cpp
        src/layered_map_manager.cpp src/hole_clearance.cpp src/simple_planner.cpp)
    ament_target_dependencies(test_hole_route ${DEPS})
    target_include_directories(test_hole_route PRIVATE ${OMPL_INCLUDE_DIRS})
    target_link_libraries(test_hole_route yaml-cpp ${OMPL_LIBRARIES} hole_connection_optimizer)
    add_test(NAME hole_route COMMAND test_hole_route
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml)
    set_tests_properties(hole_route PROPERTIES TIMEOUT 90
        ENVIRONMENT "ROS_DOMAIN_ID=178;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_route_logs")
    add_test(NAME hole_route_phase_three COMMAND test_hole_route --phase-three)
    add_test(NAME hole_route_feasible_approach COMMAND test_hole_route --feasible-approach
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../nav_bringup/config/nav_params.yaml)
    set_tests_properties(hole_route_feasible_approach PROPERTIES TIMEOUT 25
        ENVIRONMENT "ROS_DOMAIN_ID=179;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_feasible_logs")
    set_tests_properties(hole_route_phase_three PROPERTIES TIMEOUT 20
        ENVIRONMENT "ROS_DOMAIN_ID=180;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_phase_three_logs")
    add_test(NAME hole_route_actual_multi COMMAND test_hole_route --actual-multi
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../nav_bringup/config/nav_params.yaml)
    set_tests_properties(hole_route_actual_multi PROPERTIES TIMEOUT 50
        ENVIRONMENT "ROS_DOMAIN_ID=178;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_actual_multi_logs")
    add_test(NAME hole_route_map_range COMMAND test_hole_route --phase-two-range
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../nav_bringup/config/nav_params.yaml)
    add_test(NAME hole_route_manual_range COMMAND test_hole_route --manual-range
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../nav_bringup/config/nav_params.yaml)
    set_tests_properties(hole_route_manual_range PROPERTIES TIMEOUT 30
        ENVIRONMENT "ROS_DOMAIN_ID=179;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_manual_range_logs")
    set_tests_properties(hole_route_map_range PROPERTIES TIMEOUT 30
        ENVIRONMENT "ROS_DOMAIN_ID=179;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_hole_map_range_logs")
    add_executable(test_hole_geometry test/test_hole_geometry.cpp)
    ament_target_dependencies(test_hole_geometry nav_core)
    target_link_libraries(test_hole_geometry yaml-cpp)
    add_test(NAME hole_geometry COMMAND test_hole_geometry)
    add_executable(test_hole_preview test/test_hole_preview.cpp
        src/hole_geometry_previewer.cpp src/terrain_region_map.cpp)
    ament_target_dependencies(test_hole_preview ${DEPS})
    target_link_libraries(test_hole_preview yaml-cpp)
    add_test(NAME hole_preview COMMAND test_hole_preview
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../nav_bringup/config/nav_params.yaml)
    set_tests_properties(hole_preview PROPERTIES ENVIRONMENT "ROS_DOMAIN_ID=175;ROS_LOCALHOST_ONLY=1")
    add_executable(test_omni_core test/test_omni_core.cpp)
    target_compile_options(test_omni_core PRIVATE -UNDEBUG)
    add_test(NAME omni_core COMMAND test_omni_core)
    add_executable(test_omni_motion test/test_omni_motion.cpp src/layered_map_manager.cpp src/hole_clearance.cpp)
    ament_target_dependencies(test_omni_motion ${DEPS})
    target_link_libraries(test_omni_motion yaml-cpp)
    add_test(NAME omni_motion COMMAND test_omni_motion)
    set_tests_properties(omni_motion PROPERTIES ENVIRONMENT "ROS_DOMAIN_ID=173;ROS_LOCALHOST_ONLY=1")
    add_executable(test_omni_controller test/test_omni_controller.cpp src/nmpc.cpp src/layered_map_manager.cpp src/hole_clearance.cpp)
    ament_target_dependencies(test_omni_controller ${DEPS})
    target_include_directories(test_omni_controller PRIVATE ${ACADOS_INCLUDE_DIR}
        ${ACADOS_INCLUDE_DIR}/blasfeo/include ${ACADOS_INCLUDE_DIR}/hpipm/include)
    target_link_libraries(test_omni_controller yaml-cpp acados_nmpc_solver
        ${ACADOS_LIB_DIR}/libacados.so ${ACADOS_LIB_DIR}/libhpipm.so ${ACADOS_LIB_DIR}/libblasfeo.so)
    add_test(NAME omni_controller COMMAND test_omni_controller)
    set_tests_properties(omni_controller PROPERTIES ENVIRONMENT "ROS_DOMAIN_ID=173;ROS_LOCALHOST_ONLY=1")
    add_executable(test_hole_clearance test/test_hole_clearance.cpp
        src/hole_clearance.cpp src/terrain_region_map.cpp src/layered_map_manager.cpp)
    ament_target_dependencies(test_hole_clearance ${DEPS})
    target_link_libraries(test_hole_clearance yaml-cpp)
    add_test(NAME hole_clearance COMMAND test_hole_clearance
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/map.yaml
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../map/terrain.yaml)
    set_tests_properties(hole_clearance PROPERTIES ENVIRONMENT "ROS_DOMAIN_ID=174;ROS_LOCALHOST_ONLY=1")
endif()

ament_package()

if(BUILD_TESTING)
    enable_testing()
    add_executable(terrain_region_map_smoke
        test/terrain_region_map_smoke.cpp
        src/terrain_region_map.cpp
    )
    ament_target_dependencies(terrain_region_map_smoke nav_core)
    target_link_libraries(terrain_region_map_smoke yaml-cpp)
    add_test(NAME terrain_region_map_smoke
        COMMAND terrain_region_map_smoke
            ${CMAKE_CURRENT_SOURCE_DIR}/test/data/terrain_sample.yaml)
endif()
