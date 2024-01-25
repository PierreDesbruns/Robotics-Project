#!/bin/bash

workspace_path="../workspace"
src_path="$workspace_path/src"

mkdir $workspace_path
mkdir $src_path
ln -s -t $src_path "../../Robotics-Project/mrob_highlevel_controller"
ln -s -t $src_path "../../Robotics-Project/robotics_course"
ln -s -t $src_path "../../Robotics-Project/teleop_twist_keyboard"
ln -s -t $src_path "../../Robotics-Project/turtlebot3_simulations"
catkin_make -C $workspace_path
source "$workspace_path/devel/setup.bash"
