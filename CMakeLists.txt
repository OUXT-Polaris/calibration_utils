cmake_minimum_required(VERSION 3.5)
project(calibration_utils)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -fPIC)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rviz2 REQUIRED)
find_package(rviz_common REQUIRED)
find_package(rclcpp REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
set(QT_LIBRARIES Qt5::Widgets)
add_definitions(-DQT_NO_KEYWORDS)

include_directories(
  include
  ${Qt5Widgets_INCLUDE_DIRS}
)

set(headers_to_moc
  include/caliblation_utils/calibration_panel.hpp
)
foreach(header "${headers_to_moc}")
  qt5_wrap_cpp(rviz_common_moc_files "${header}")
endforeach()

add_library(${PROJECT_NAME}
  src/calibration_panel.cpp
)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rviz_common
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(
  DIRECTORY include/
  DESTINATION include
)

pluginlib_export_plugin_description_file(rviz_common plugins_description.xml)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
