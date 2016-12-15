#include <iostream>
#include <unistd.h>
#include <ros/ros.h>
#include <std_msgs/UInt32.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include "ros/ros.h"
#include "move_base/move_base.h"
#include "actionlib/client/action_client.h"
#include "actionlib/client/simple_goal_state.h"
#include "actionlib/client/simple_client_goal_state.h"
#include "actionlib/client/terminal_state.h"
#include "actionlib/client/comm_state.h"
#include <boost/thread/condition.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/scoped_ptr.hpp>
#include "ros/callback_queue.h"

class navi{
		public:typedef actionlib::ActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
		typedef actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> GoalHandleT;

		ros::CallbackQueue callback_queue;
		ros::NodeHandle n;
		move_base_msgs::MoveBaseGoal goal;
		boost::scoped_ptr<MoveBaseClient> ac_;
		GoalHandleT gh_;
		navi();
		double x;
		double y;
		double z;
		void init();
		void navigation();
		geometry_msgs::Quaternion quat;
		
	private:
	protected:
};
