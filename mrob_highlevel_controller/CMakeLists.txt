cmake_minimum_required(VERSION 3.0.2)
project(mrob_highlevel_controller)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  geometry_msgs
)
find_package(Eigen3 REQUIRED)

catkin_package(
 INCLUDE_DIRS include ${EIGEN3_INCLUDE_DIR}
 LIBRARIES mrob_highlevel_controller
 CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}_core
  src/HighlevelController.cpp
)

add_dependencies(${PROJECT_NAME}_core ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(${PROJECT_NAME}_node src/node.cpp)

set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME controller PREFIX "")

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_core ${catkin_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_node ${PROJECT_NAME}_core)