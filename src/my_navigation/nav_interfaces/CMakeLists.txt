cmake_minimum_required(VERSION 3.8)
project(nav_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Navigate.action"
  "msg/HoleEvent.msg"
  "msg/HoleStraight.msg"
  "msg/HoleSpeedRegion.msg"
  "msg/HoleTraversal.msg"
  "msg/NavigationPlan.msg"
  "msg/HoleStructureRequest.msg"
  "msg/HoleStructureFeedback.msg"
  "msg/HoleTraversalState.msg"
  "msg/HoleTraversalEvent.msg"
  "srv/ReloadTerrain.srv"
  "srv/GetTemporaryMap.srv"
  "srv/ApplyTemporaryMap.srv"
  "srv/GetHolePassageConfig.srv"
  "srv/ApplyHolePassageConfig.srv"
  "srv/SaveHolePassageConfig.srv"
  DEPENDENCIES geometry_msgs nav_msgs std_msgs builtin_interfaces
)

ament_package()
