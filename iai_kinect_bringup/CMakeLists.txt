cmake_minimum_required(VERSION 3.0.2)
project(iai_kinect_bringup)

find_package(catkin REQUIRED COMPONENTS
  iai_kinect_watchdog
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

