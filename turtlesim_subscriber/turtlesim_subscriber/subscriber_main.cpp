//(1)header file
#include<ros/ros.h>
#include<turtlesim/Pose.h>//rostopic info type:
#include<iomanip>
//for std::setprecision and std::fixed

//(2)callback function
void poseMessageReceived(const turtlesim::Pose& msg){
	ROS_INFO_STREAM(std::setprecision(2)<<std::fixed
			<<"position=("<< msg.x <<","<<msg.y<<")"
			<<"direction="<< msg.theta);
}

int main(int argc, char** argv){
	//(3)initialize
	ros::init(argc, argv, "turtlesim_subscriber_node");
      	ros::NodeHandle nh;

	//(4)create subscriber
	ros::Subscriber sub=nh.subscribe("turtle1/pose",1000,&poseMessageReceived);

	//(5)wait and run the callback function
	ros::spin();

}
