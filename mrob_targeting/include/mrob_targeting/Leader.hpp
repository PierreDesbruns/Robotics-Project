#pragma once

#include <ros/ros.h> // ROS

namespace mrob_targeting {

class Leader
{
public:
    /*!
     * Constructor
     */
    Leader(ros::NodeHandle& nodeHandle);

private:
    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

};
} /* namespace mrob_targeting */