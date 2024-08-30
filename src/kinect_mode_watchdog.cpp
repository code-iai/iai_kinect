#include "ros/ros.h"
#include "dynamic_reconfigure/client.h"
#include "std_msgs/String.h"
#include "freenect_camera/FreenectConfig.h"

int main(int argc, char **argv) {
    // Initialize the ROS node with the name "image_mode_monitor"
    ros::init(argc, argv, "kinect_mode_watchdog");
    ros::NodeHandle nh;

    // Define the parameter name
    std::string param_name = "/kinect_head/driver";

    ROS_INFO("Waiting for the parameter %s to be available", param_name.c_str());
    // Dynamic reconfigure client for the Kinect driver
    dynamic_reconfigure::Client<freenect_camera::FreenectConfig> client("/kinect_head/driver");

    // Run the node at a rate of 1 Hz
    ros::Rate loop_rate(1);

    while (ros::ok()) {
        freenect_camera::FreenectConfig config;

        ROS_INFO("Checking the parameter %s", param_name.c_str());
        // Check if the parameter exists
        if (client.getCurrentConfiguration(config)) {
            // Check the image_mode and change it if necessary
            ROS_INFO("Current image_mode: %d", config.image_mode);
            if (config.image_mode == 2) {
                config.image_mode = 1;
                client.setConfiguration(config);
                ROS_INFO("Changed image_mode from 2 to 1");
            }
        } else {
            ROS_WARN("Parameter %s not found", param_name.c_str());
        }

        // Sleep for the remaining time to enforce the loop rate
        loop_rate.sleep();
    }

    return 0;
}
