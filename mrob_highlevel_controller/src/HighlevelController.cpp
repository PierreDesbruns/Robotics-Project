#include "mrob_highlevel_controller/HighlevelController.hpp"

// STD
#include <string>

namespace mrob_highlevel_controller {

HighlevelController::HighlevelController(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
    /**********[ SCAN SUBSCRIBER ]**********/
    if (!(nodeHandle_.getParam("scan_topic_name", scan_topicName_) && nodeHandle_.getParam("scan_queue_size", scan_queueSize_)))
    {
        ROS_ERROR("Could not find scan parameters.");
        scan_topicName_ = "/scan";
        scan_queueSize_ = 1000;
    }
    scan_subscriber_ = nodeHandle_.subscribe(scan_topicName_, scan_queueSize_, &HighlevelController::scanCallback, this);

    /**********[ CMD_VEL PUBLISHER ]**********/
    if (!(nodeHandle_.getParam("vel_topic_name", vel_topicName_) && nodeHandle_.getParam("vel_queue_size", vel_queueSize_)))
    {
        ROS_ERROR("Could not find cmd_vel parameters.");
        vel_topicName_ = "/cmd_vel";
        vel_queueSize_ = 1000;
    }
    vel_publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(vel_topicName_, vel_queueSize_);

    if (!(nodeHandle_.getParam("vel_linear_speed", vel_linSpeed_) && nodeHandle_.getParam("vel_angular_speed", vel_angSpeed_)))
    {
        vel_linSpeed_ = 1.0;
        vel_angSpeed_ = 0.5;
    }
}

HighlevelController::~HighlevelController()
{
}

void HighlevelController::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scanMsg)
{
    /**********[ SCAN SUBSCRIBER ]**********/

    // Iterator pointing to the smallest distance in scanMsg->ranges
    auto minDist_it = min_element(scanMsg->ranges.begin(), scanMsg->ranges.end());
    // Index of the smallest distance in scanMsg->ranges
    int minDist_idx = distance(scanMsg->ranges.begin(), minDist_it);
    // Distance from the pillar
    float radius_m = *minDist_it;
    // Angle from the pillar
    float angle_rad = scanMsg->angle_increment * minDist_idx;

    ROS_INFO("Radius (in m) [%f]", radius_m);
    ROS_INFO("Angle (in rad): [%f]", angle_rad);


    /**********[ CMD_VEL PUBLISHER ]**********/

    int count = 0;
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        geometry_msgs::Twist velMsg;
        velMsg.angular.z = vel_angSpeed_;
        vel_publisher_.publish(velMsg);
        ros::spinOnce;
        loop_rate.sleep();
    }
}

} /* namespace */
