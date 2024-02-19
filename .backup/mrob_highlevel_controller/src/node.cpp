#include <ros/ros.h>
#include "mrob_highlevel_controller/HighlevelController.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "mrob_highlevel_controller");
  ros::NodeHandle nodeHandle("~");

  mrob_highlevel_controller::HighlevelController controller(nodeHandle);
  
  ros::spin();
  return 0;
}
