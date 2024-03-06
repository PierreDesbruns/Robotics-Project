#pragma once

#include <ros/ros.h> // ROS
#include <opencv2/objdetect/aruco_detector.hpp> // Aruco

namespace mrob_targeting {

class Follower
{
public:
    /*!
     * Constructor
     */
    Follower(ros::NodeHandle& nodeHandle);

private:
    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

};
} /* namespace mrob_targeting */