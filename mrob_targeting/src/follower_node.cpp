#include <ros/ros.h>
#include "mrob_targeting/Follower.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "follower");
  ros::NodeHandle nodeHandle("~");

  mrob_targeting::Follower follower(nodeHandle);

  ros::spin();
  return 0;
}
