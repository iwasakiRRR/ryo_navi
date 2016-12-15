#include "ryo_navi/ryo_navi.hpp"

int main(int argv, char **argc){
	ros::init(argv,argc,"ryo_navi");
	ros::NodeHandle privateNh("~");
	ros::Rate loop_rate(100);
	navi na;
	na.init();
	while(ros::ok()){
		na.navigation();
		ros::spinOnce();
		loop_rate.sleep();
	}
return 0;
}
