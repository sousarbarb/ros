#include <iostream>

#include "simple_publisher_subscriber/subscriber.hpp"

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_publisher_subscriber::Subscriber>());
  rclcpp::shutdown();
  return 0;
}
