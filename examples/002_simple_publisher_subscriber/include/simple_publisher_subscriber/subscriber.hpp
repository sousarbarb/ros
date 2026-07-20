#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace simple_publisher_subscriber
{

class Subscriber : public rclcpp::Node
{
 public:

  Subscriber();
  ~Subscriber() = default;

 protected:

  void SubTalker(const std_msgs::msg::String::UniquePtr msg);

 protected:

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr m_sub_;
};

}  // namespace simple_publisher_subscriber
