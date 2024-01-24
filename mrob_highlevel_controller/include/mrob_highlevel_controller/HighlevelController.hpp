#pragma once

// ROS
#include <ros/ros.h>

// LaserScan
#include "sensor_msgs/LaserScan.h"

namespace mrob_highlevel_controller {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class HighlevelController
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  HighlevelController(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~HighlevelController();

  /*!
   * Callback function for /scan topic.
   * Prints in ROS_INFO the smallest distance measurement from vector ranges.
   * @param scanMsg message from /scan topic
   */
  void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scanMsg);

 private:
  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS subscriber to /scan topic
  ros::Subscriber scanSub_;
};

} /* namespace */
