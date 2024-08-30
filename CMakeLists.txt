cmake_minimum_required(VERSION 3.0.2)
project(kinect_mode_watchdog)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp std_msgs dynamic_reconfigure freenect_camera
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

## Declare a C++ executable
add_executable(kinect_mode_watchdog src/kinect_mode_watchdog.cpp)
target_link_libraries(kinect_mode_watchdog ${catkin_LIBRARIES})
