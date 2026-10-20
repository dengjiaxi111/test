cmake_minimum_required(VERSION 3.8)
project(nav_bringup)

find_package(ament_cmake REQUIRED)

install(DIRECTORY launch config maps rviz DESTINATION share/${PROJECT_NAME})

install(PROGRAMS
  scripts/static_relocator.py
  scripts/odom_base_debug_rebaser.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(Python3 REQUIRED COMPONENTS Interpreter)
  add_test(NAME hole_execution_protocol
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/test_hole_execution_protocol.py)
  add_test(NAME planning_debug
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/test_planning_debug.py)
  set_tests_properties(planning_debug PROPERTIES
    TIMEOUT 60
    ENVIRONMENT "ROS_DOMAIN_ID=176;ROS_LOCALHOST_ONLY=1;ROS_LOG_DIR=/tmp/nav_planning_debug_logs")
endif()

ament_package()
