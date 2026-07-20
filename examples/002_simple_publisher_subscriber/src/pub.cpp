#include <iostream>

#include "simple_publisher_subscriber/publisher.hpp"

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_publisher_subscriber::Publisher>());
  rclcpp::shutdown();
  return 0;
}
