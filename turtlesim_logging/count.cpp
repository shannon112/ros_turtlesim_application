//(1)header file
#include<ros/ros.h>
#include<log4cxx/logger.h>

int main(int argc, char** argv){
	//(2)initailize
	ros::init(argc,argv,"turtle_logging_node");
	ros::NodeHandle nh;

	//(4)setting log level
	log4cxx::Logger::getLogger(ROSCONSOLE_DEFAULT_NAME)->setLevel(
			ros::console::g_level_lookup[ros::console::levels::Debug]
	);
	//(3)Generate log messages
	ros::Rate rate(3);//Hz

	for(int i=1;ros::ok();i++){
		float k=i*3.1415926;
		ROS_DEBUG_STREAM("Counted to "<<i);
		if((i%3)==0) ROS_INFO("%0.5f is divisible by 3.",k);
		if((i%5)==0) ROS_WARN_STREAM(std::fixed<<std::setprecision(5)<<k<<" is divisible by 5.");//std::boolalpha
		if((i%10)==0) ROS_ERROR_STREAM(i<<" is divisible by 10.");
		if((i%20)==0) ROS_FATAL_STREAM(i<<" is divisible by 20.");
		ROS_FATAL_STREAM_ONCE("This is first loop end!");
		rate.sleep();
	}
	/*
	while(ros::ok()){//performence bad
		ROS_FATAL_STREAM_THROTTLE(0.1,"This appear every 0.1s!");
	}
	*/
}
