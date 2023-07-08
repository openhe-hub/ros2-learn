#include "rclcpp/publisher.hpp"
#include "rclcpp/executors.hpp"
#include "rclcpp/logging.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/utilities.hpp"
#include "std_msgs/msg/detail/string__struct.hpp"
#include "std_msgs/msg/string.hpp"
#include <functional>
#include <memory>
#include <string>

class SubscriberNode : public rclcpp::Node {
private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub; 

  void topic_callback(const std_msgs::msg::String::SharedPtr msg){
    RCLCPP_INFO(this->get_logger(), "received: %s", msg->data.c_str());
  }

public:
  SubscriberNode(std::string name) : rclcpp::Node(name) {
    RCLCPP_INFO(this->get_logger(), "subscriber node start");
    sub = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&SubscriberNode::topic_callback, this, std::placeholders::_1));
  }
};


int main(int argc, char** argv){
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SubscriberNode>("subscriber_node");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}