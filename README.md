# Meta package for the Kinect 360 in ROS on the PR2 robot

## Installation

To install the package clone the repository into your catkin workspace and build it with `catkin build`.

```bash
cd path/to/your/catkin_ws/src
git clone https://github.com/code-iai/iai_kinect.git
catkin build
```

## Usage

This package includes the a watchdog package that monitors the image mode of the Kinect 360 and reconfigures it to use the correct mode if it is not set correctly. This solves a common bug in our Kinect camera setup on the PR2 robot.

Additionally the meta package contains a bringup package to launch the kinect driver and the watchdog node together.
Currently the package works in ROS Noetic.

To launch the watchdog alone run:

```bash
roslaunch iai_kinect_watchdog kinect_mode_watchdog.launch
```

To launch the kinect driver and the watchdog together run:

```bash
roslaunch iai_kinect_bringup iai_kinect_bringup.launch
```

## Maintainer

This package is maintained by the IAI group at the University of Bremen.

Current maintainer: Jeroen Schäfer, jeroen.schaefer@outlook.de
