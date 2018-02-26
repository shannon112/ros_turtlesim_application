//(1)header file
#include<ros/ros.h>
#include<std_srvs/Empty.h>
//for std::setprecision and std::fixed


int main(int argc, char** argv){
	//(3)initialize
	ros::init(argc, argv, "turtlesim_setcolor_node");
  ros::NodeHandle nh;

	ros::service::waitForService("clear");


	ros::param::set("/background_r",255);
	ros::param::set("/background_g",255);
	ros::param::set("/background_b",0);
	//ros::param::set("/turtle1/background_r",255);
	//ros::param::set("/turtle1/background_g",255);
	//ros::param::set("/turtle1/background_b",0);

	ros::ServiceClient clearClient =nh.serviceClient<std_srvs::Empty>("/clear");
	std_srvs::Empty srv;
	clearClient.call(srv);
}
