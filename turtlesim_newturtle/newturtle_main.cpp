//(1)header file
#include<ros/ros.h>
#include<turtlesim/Spawn.h>

int main(int argc, char** argv){
	//(3)initialize
	ros::init(argc, argv, "turtlesim_newturtle_node");
  ros::NodeHandle nh;

	ros::ServiceClient spawnClient =nh.serviceClient<turtlesim::Spawn>("spawn");

	turtlesim::Spawn::Request req;
	turtlesim::Spawn::Response resp;

	req.x=2;
	req.y=3;
	req.theta=M_PI/2;
	req.name="Leo";

	bool success=spawnClient.call(req, resp);

	if(success){
		ROS_INFO_STREAM("Spawn a turtle named "<<resp.name);
	}else{
		ROS_ERROR_STREAM("Fail to spawn.");
	}
}
