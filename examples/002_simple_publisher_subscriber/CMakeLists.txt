cmake_minimum_required(VERSION 3.20)
project(simple_publisher_subscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Source code
add_executable(pub_cpp
  src/publisher.cpp
  src/pub.cpp
)
target_include_directories(pub_cpp
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)
target_compile_features(pub_cpp PUBLIC c_std_99 cxx_std_17)
target_link_libraries(
  pub_cpp
  ${rclcpp_TARGETS}
  ${std_msgs_TARGETS}
)

add_executable(sub_cpp
  src/subscriber.cpp
  src/sub.cpp
)
target_include_directories(sub_cpp
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)
target_compile_features(sub_cpp PUBLIC c_std_99 cxx_std_17)
target_link_libraries(
  sub_cpp
  ${rclcpp_TARGETS}
  ${std_msgs_TARGETS}
)

# Package installation
install(
  TARGETS
    pub_cpp
    sub_cpp
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
  INCLUDES DESTINATION include
)

install(
  DIRECTORY include/${PROJECT_NAME}
  DESTINATION include
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
  FILES_MATCHING
    PATTERN "*.launch.xml"
    PATTERN "*.launch.py"
)

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Create ROS 2 ament package
ament_export_dependencies(
  rclcpp
  std_msgs
)

ament_package()
