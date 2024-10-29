cmake_minimum_required(VERSION 3.0.2)
project(iai_kinect_watchdog)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  rospy std_msgs dynamic_reconfigure
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# Install Python scripts
catkin_install_python(PROGRAMS
  src/kinect_mode_watchdog.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Declare a C++ executable
#add_executable(kinect_mode_watchdog src/kinect_mode_watchdog.cpp)
#target_link_libraries(kinect_mode_watchdog ${catkin_LIBRARIES})
