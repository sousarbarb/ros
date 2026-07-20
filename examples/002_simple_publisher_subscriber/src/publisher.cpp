#include "simple_publisher_subscriber/publisher.hpp"

#include <chrono>
#include <string>

namespace simple_publisher_subscriber
{

Publisher::Publisher() : rclcpp::Node("pub"), m_count_(0)
{
  m_pub_ = this->create_publisher<std_msgs::msg::String>("talker", 10);
  m_timer_ = this->create_timer(std::chrono::seconds(1),
                                std::bind(&Publisher::TimerCb, this));
}

void Publisher::TimerCb()
{
  std_msgs::msg::String msg;

  msg.data = "Creating message number " + std::to_string(m_count_++);

  m_pub_->publish(msg);

  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
}

}  // namespace simple_publisher_subscriber