#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
    // Initialize the ROS node with the name "image_mode_monitor"
    ros::init(argc, argv, "kinect_mode_watchdog");
    ros::NodeHandle nh;

    // Define the parameter name
    std::string param_name = "/kinect_head/driver/image_mode";

    // Run the node at a rate of 1 Hz
    ros::Rate loop_rate(1);

    while (ros::ok()) {
        int image_mode;

        // Check if the parameter exists
        if (nh.getParam(param_name, image_mode)) {
            // If the parameter is equal to 2, change it to 1
            if (image_mode == 2) {
                nh.setParam(param_name, 1);
                ROS_INFO("Changed %s from 2 to 1", param_name.c_str());
            }
        } else {
            ROS_WARN("Parameter %s not found", param_name.c_str());
        }

        // Sleep for the remaining time to enforce the loop rate
        loop_rate.sleep();
    }

    return 0;
}