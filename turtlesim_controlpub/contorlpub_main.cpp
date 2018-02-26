//(1)header file
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>

int main(int argc, char** argv){
	//(2)initailize
	ros::init(argc,argv,"turtle_controlpub_node");
	ros::NodeHandle nh;

	//(3)Create a publisher object
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);

	//seed the random number generator
	srand(time(0));

	//get param
	//need to tpye in terminal first
	//rosparam set /turtle_controlpub_node/max_vel 0.1
	const std::string PARAM_NAME="~max_vel"; //param name
	double max_vel;//param value
	bool ok=ros::param::get(PARAM_NAME,max_vel);//get name and value
	if(!ok){
		ROS_FATAL_STREAM("could not get param"<<PARAM_NAME);
		exit(1);
	}

	//Loop at 2Hz until the node is shut down
	//(7)set the rate of iteration
	ros::Rate rate(2);
	while(ros::ok()){
		//(4)input data to msg
		geometry_msgs::Twist msg;
		msg.linear.x=max_vel*2*double(rand())/double(RAND_MAX);//0~2 go forward
		msg.angular.z=4*double(rand())/double(RAND_MAX)-2;//2~-2 turning

		//(5)publish the msg
		pub.publish(msg);

		//(6)Send a message tp rosout
		ROS_INFO_STREAM("Sending random velocity command:"
				<<"linear="<<msg.linear.x
				<<"angular="<<msg.angular.z);

		//(7)wait for next iteration
		rate.sleep();
	}
}
