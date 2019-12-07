# wheelchair_robot

# setup
Clone the repository.
You will need to cd wheelchair_robot/src and clone the following git repositories:
  cra-ros-pkg/robot_localization - https://github.com/cra-ros-pkg/robot_localization
  robopeak/rplidar_ros - https://github.com/Slamtec/rplidar_ros
  ccny-ros-pkg/scan_tools - https://github.com/ccny-ros-pkg/scan_tools

scan_tools will require additional dependencies:
  csm:
    clone this repository in your home folder - https://github.com/AndreaCensi/csm
    run the install script:
      $ cd csm && ./install_quickstart.sh
    copy the contents of csm/deployed to to /usr/:
      bin -> /usr/bin, include -> /usr/include, lib -> /usr/lib
      DO NOT overwrite any files
   
I cannot remember all the dependencies I needed to install, I will fill them out as find out.

# making the project catkin
cd to ../wheelchair_robot/src
  $ catkin_init_workspace
then you can cd to ../wheelchair_robot and
  $ catkin_make

you'll most likely run into make errors, good luck.

# launching the project
there is a launch file located in the source of the project
  $ source ../wheelchair/devel/setup.bash
  $ roslaunch wheelchair wheelchair_robot.launch
this will launch all the packages with proper paramaters.
You may need to setup rviz by adding proper displays.
  
