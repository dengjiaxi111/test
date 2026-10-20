# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target robots_msgs::robots_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${robots_msgs_TARGETS}.
if(robots_msgs_TARGETS AND NOT TARGET robots_msgs::robots_msgs)
  add_library(robots_msgs::robots_msgs INTERFACE IMPORTED)
  set_target_properties(robots_msgs::robots_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${robots_msgs_TARGETS}")
endif()
