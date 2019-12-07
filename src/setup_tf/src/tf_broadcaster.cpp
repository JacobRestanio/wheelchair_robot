#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;
  ros::Rate r(100);
  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0.131, 0, 0.991, 0), tf::Vector3(-0.4, 0.0, 1)),
        ros::Time::now(), "base_link", "laser_frame"));
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1), tf::Vector3(0.0, 0.0, 0.0)),
        ros::Time::now(), "odom", "base_link"));
  }
}