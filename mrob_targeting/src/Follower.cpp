#include "mrob_targeting/Follower.hpp"

namespace mrob_targeting
{
Follower::Follower(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
{
    
}

/*
cv::Mat markerImage;
cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_100);
cv::aruco::generateImageMarker(dictionary, 23, 200, markerImage, 1);
cv::imwrite("marker23.png", markerImage);
cv::Mat inputImage = cv::imread("../aruco/markers/4x4_1000-0.svg");
std::vector<int> markerIds;
std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
cv::aruco::ArucoDetector detector(dictionary, detectorParams);
detector.detectMarkers(inputImage, markerCorners, markerIds, rejectedCandidates);
*/

} // namespace mrob_targeting