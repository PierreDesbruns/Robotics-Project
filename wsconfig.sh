#!/bin/bash

workspace="../catkin_ws"
src="$workspace/src"

mkdir $workspace
mkdir $src

ln -s -t $src "../../Robotics-Project/.vscode"
ln -s -t $src "../../Robotics-Project/mrob_targeting"
ln -s -t $src "../../Robotics-Project/mrob_control"
ln -s -t $src "../../Robotics-Project/mrob_description"
ln -s -t $src "../../Robotics-Project/teleop_twist_keyboard"

catkin_make -C $workspace
source "$workspace/devel/setup.bash"
