//(1)header file
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

ros::Publisher *pubPtr;

//(2)callback function
void commandVelocityReceived(const geometry_msgs::Twist& msg){
	geometry_msgs::Twist msgOut;
	msgOut.linear.x=-msg.linear.x;
	msgOut.angular.z=-msg.angular.z;
	pubPtr->publish(msgOut);
}

int main(int argc, char** argv){
	//(3)initialize
	ros::init(argc, argv, "turtlesim_reverse_node");
  ros::NodeHandle nh;

	//(4)create subscriber & Publisher
	ros::Subscriber sub=nh.subscribe("turtle1/cmd_vel",1000,&commandVelocityReceived);
	pubPtr=new ros::Publisher(nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel_reverse",1000));

	//(5)wait and run the callback function
	ros::spin();
	delete pubPtr;
}
