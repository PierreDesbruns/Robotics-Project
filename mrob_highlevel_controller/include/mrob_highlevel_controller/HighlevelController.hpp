#pragma once

// ROS
#include <ros/ros.h>

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

 private:
  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;
};

} /* namespace */
