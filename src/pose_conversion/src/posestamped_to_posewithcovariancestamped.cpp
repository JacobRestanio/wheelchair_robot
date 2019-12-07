#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <boost/assign.hpp>

  geometry_msgs::PoseWithCovarianceStamped pwcs;

void poseStampedCallback(const geometry_msgs::PoseStamped& msg) {
  pwcs.header = msg.header;
  pwcs.pose.pose = msg.pose;
  pwcs.pose.covariance = boost::assign::list_of(0)   (0)   (0)  (0)  (0)  (0)
                                               (0)   (0)   (0)  (0)  (0)  (0)
                                               (0)   (0)   (0)  (0)  (0)  (0)
                                               (0)   (0)   (0)  (0)  (0)  (0)
                                               (0)   (0)   (0)  (0)  (0)  (0)
                                               (0)   (0)   (0)  (0)  (0)  (0) ;
  
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "posestamped_to_posewithcovariancestamped");
  ros::NodeHandle n;
  ros::Subscriber ps_sub = n.subscribe("pose_stamped", 1000, &poseStampedCallback);
  ros::Publisher pwcs_pub = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("pwcs_converted", 1000);
  ros::Rate r(1);
  
  while(n.ok()) {
    pwcs_pub.publish(pwcs);
    ros::spinOnce();
    r.sleep();
  }
  return 0;
}
    