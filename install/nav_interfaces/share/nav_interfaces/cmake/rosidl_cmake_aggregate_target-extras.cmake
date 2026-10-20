# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target nav_interfaces::nav_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${nav_interfaces_TARGETS}.
if(nav_interfaces_TARGETS AND NOT TARGET nav_interfaces::nav_interfaces)
  add_library(nav_interfaces::nav_interfaces INTERFACE IMPORTED)
  set_target_properties(nav_interfaces::nav_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${nav_interfaces_TARGETS}")
endif()
