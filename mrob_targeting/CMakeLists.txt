cmake_minimum_required(VERSION 3.0.2)
project(mrob_targeting)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

catkin_package(
 INCLUDE_DIRS include ${EIGEN3_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS}
 LIBRARIES mrob_targeting
 CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}_core
  src/Leader.cpp
  src/Follower.cpp
)

add_dependencies(${PROJECT_NAME}_core ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(leader_node src/leader_node.cpp)
add_executable(follower_node src/follower_node.cpp)

set_target_properties(leader_node PROPERTIES OUTPUT_NAME leader PREFIX "")
set_target_properties(follower_node PROPERTIES OUTPUT_NAME follower PREFIX "")

add_dependencies(leader_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(follower_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_core ${catkin_LIBRARIES})
target_link_libraries(leader_node ${PROJECT_NAME}_core)
target_link_libraries(follower_node ${PROJECT_NAME}_core)