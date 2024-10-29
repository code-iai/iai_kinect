#!/usr/bin/env python

import rospy
from dynamic_reconfigure.client import Client

def main():
    # Initialize the ROS node
    rospy.init_node('kinect_mode_watchdog')
    rospy.loginfo("Kinect mode watchdog node started")

    # Create a dynamic reconfigure client for the Kinect driver
    client = Client("/kinect_head/driver")

    # Run the node at 10 Hz
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        try:
            # Get the current configuration from the dynamic reconfigure server
            config = client.get_configuration()

            # Check the image_mode parameter and change it if it's 2
            if config.get('image_mode') == 2:
                client.update_configuration({'image_mode': 1})
                rospy.loginfo("Changed image_mode from 2 to 1")
        
        except rospy.ServiceException as e:
            rospy.logwarn("Failed to communicate with dynamic reconfigure server: %s", e)

        # Sleep to maintain the loop rate
        rate.sleep()

if __name__ == '__main__':
    main()
