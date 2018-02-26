//(1)header file
#include<ros/ros.h>

int main(int argc, char** argv){
	//(2)initailize
	ros::init(argc,argv,"turtle_anonNS_node",ros::init_options::AnonymousName);
	ros::NodeHandle nh;
	//(3)Generate log messages
	ros::Rate rate(3);//Hz

	for(int i=0;ros::ok();i++){
	//while(ros::ok()){//performence bad
		ROS_INFO_STREAM("Message from : "<<ros::this_node::getName());
		rate.sleep();
	}
}
