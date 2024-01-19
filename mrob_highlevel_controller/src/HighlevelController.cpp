#include "mrob_highlevel_controller/HighlevelController.hpp"

// STD
#include <string>

namespace mrob_highlevel_controller {

HighlevelController::HighlevelController(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
}

HighlevelController::~HighlevelController()
{
}

} /* namespace */
