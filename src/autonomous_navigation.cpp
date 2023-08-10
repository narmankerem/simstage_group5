// autonoumous_navigation node 

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include <tf/transform_datatypes.h>




#include <iostream>


double obstacle_distance;
double robot_x;
double robot_y;
double robot_yaw;

//Callback function for /base_scan
void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg){
  obstacle_distance = *std::min_element (msg->ranges.begin(), msg->ranges.end());
  
    ROS_INFO("obstacle distance: %f", obstacle_distance);
}





void odomCallback(const nav_msgs::Odometry::ConstPtr& msg){
  robot_x = msg->pose.pose.position.x;
  robot_y = msg->pose.pose.position.y;
  robot_yaw = tf::getYaw(msg->pose.pose.orientation);
  //ROS_INFO("x: %f, y: %f, yaw: %f", robot_x, robot_y, robot_yaw);
}





int main(int argc, char **argv){
    
  ros::init(argc, argv, "autonomous_navigation");
  
  ros::NodeHandle n;

  //Publisher for /cmd_vel
  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  //Subscriber for /base_scan
  ros::Subscriber laser_sub = n.subscribe("base_scan", 1000, laserCallback);
  //Subscriber for /odom
  ros::Subscriber odom_sub = n.subscribe("odom", 1000, odomCallback);
  

  ros::Rate loop_rate(10); //10 Hz

  //initializations:
  geometry_msgs::Twist cmd_vel_msg;

  while (ros::ok()){
    
    // autonomous navigation with sensor feedback:
    if (obstacle_distance > 0.5){
      cmd_vel_msg.linear.x = 0.5;
      cmd_vel_msg.angular.z = 0.0;
    }
    else{
      cmd_vel_msg.linear.x = 0.0;
      cmd_vel_msg.angular.z = 0.5;
    }

    //publish velocity commands:
    cmd_vel_pub.publish(cmd_vel_msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}




