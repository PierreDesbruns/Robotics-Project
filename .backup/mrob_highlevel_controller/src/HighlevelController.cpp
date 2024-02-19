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


    /**********[ VISUALIZATION_MARKER PUBLISHER ]**********/

    vis_publisher_ = nodeHandle_.advertise<visualization_msgs::Marker>("visualization_marker", 0);
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

    geometry_msgs::Twist velMsg;
    float ang_tolerance = 0.1; // angular tolerance in rad corresponding to cone centered on pi rad
    if (angle_rad > M_PI + ang_tolerance) // case pillar is on the right
        velMsg.angular.z = -vel_angSpeed_;
    else if (angle_rad < M_PI - ang_tolerance) // case pillar is on the left
        velMsg.angular.z = vel_angSpeed_;
    else
        velMsg.angular.z = 0;
    velMsg.linear.x = vel_linSpeed_;
    vel_publisher_.publish(velMsg);


    /**********[ VISUALIZATION_MARKER PUBLISHER ]**********/

    visualization_msgs::Marker marker;
    marker.header.frame_id = "base_scan";
    marker.header.stamp = ros::Time();
    marker.ns = "mrob_highlevel_controller";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = radius_m * cos(angle_rad);
    marker.pose.position.y = radius_m * sin(angle_rad);
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;
    marker.color.a = 1.0;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    vis_publisher_.publish(marker);
}

} /* namespace */
