#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Received: %s", msg->data.c_str());


  std::string command = "mpg123 -q /demo/resources/" + msg->data + ".mp3";
  std::system(command.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
