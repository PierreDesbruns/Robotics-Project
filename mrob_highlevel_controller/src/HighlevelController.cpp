#include "mrob_highlevel_controller/HighlevelController.hpp"

// STD
#include <string>

namespace mrob_highlevel_controller {

HighlevelController::HighlevelController(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
    scanSub_ = nodeHandle.subscribe("/scan", 1000, &HighlevelController::scanCallback, this);
}

HighlevelController::~HighlevelController()
{
}

void HighlevelController::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scanMsg)
{
    ROS_INFO("Smallest distance in scan ranges: [%f]", *min_element(scanMsg->ranges.begin(), scanMsg->ranges.end()));
}

} /* namespace */
