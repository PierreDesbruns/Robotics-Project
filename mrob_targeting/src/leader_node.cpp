#include <ros/ros.h>
#include "mrob_targeting/Leader.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "leader");
  ros::NodeHandle nodeHandle("~");

  mrob_targeting::Leader leader(nodeHandle);

  ros::spin();
  return 0;
}