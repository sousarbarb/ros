#include "simple_publisher_subscriber/subscriber.hpp"

#include <string>

namespace simple_publisher_subscriber
{

Subscriber::Subscriber() : rclcpp::Node("sub")
{
  m_sub_ = this->create_subscription<std_msgs::msg::String>(
      "talker", 10,
      std::bind(&Subscriber::SubTalker, this, std::placeholders::_1));
}

void Subscriber::SubTalker(const std_msgs::msg::String::UniquePtr msg)
{
  RCLCPP_INFO(this->get_logger(), "Subscribing: '%s'", msg->data.c_str());
}

}  // namespace simple_publisher_subscriber