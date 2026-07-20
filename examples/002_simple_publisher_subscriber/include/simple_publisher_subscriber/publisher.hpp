#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace simple_publisher_subscriber
{

class Publisher : public rclcpp::Node
{
 public:

  Publisher();
  ~Publisher() = default;

 protected:

  void TimerCb();

 protected:

  rclcpp::TimerBase::SharedPtr m_timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_pub_;

  size_t m_count_;
};

}  // namespace simple_publisher_subscriber
