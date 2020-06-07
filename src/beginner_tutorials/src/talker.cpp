#include "ros/ros.h"
#include "std_msgs/String.h"

#include <thread>
#include <chrono>
#include <random>
#include <string>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(0.1);

  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> distribution(1,3);

  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = std::to_string(distribution(generator));
    ROS_INFO("Sent: %s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
