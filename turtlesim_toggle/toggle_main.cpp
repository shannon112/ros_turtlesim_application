//(1)header file
#include<ros/ros.h>
#include<std_srvs/Empty.h>//rostopic info type:
#include<geometry_msgs/Twist.h>

bool forward=true;
bool toggleForward(std_srvs::Empty::Request &req,std_srvs::Empty::Response &resp){
	forward=!forward;
	ROS_INFO_STREAM("Now sending "<<(forward ? "forward" : "rotate")<<" commands.");
}

int main(int argc, char** argv){
	//(3)initialize
	ros::init(argc, argv, "turtlesim_subscriber_node");
  ros::NodeHandle nh;

	//(4)create subscriber
	ros::ServiceServer server=nh.advertiseService("toggle_forward",&toggleForward);
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);

	ros::Rate rate(2);
	while(ros::ok()){
		geometry_msgs::Twist msg;
		msg.linear.x=forward ? 1.0:0.0;
		msg.angular.z=forward ? 0.0:1.0;
		pub.publish(msg);
		ros::spinOnce();
		rate.sleep();
	}
}
