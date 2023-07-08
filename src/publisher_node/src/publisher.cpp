#include "rclcpp/publisher.hpp"
#include "rclcpp/executors.hpp"
#include "rclcpp/logging.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/utilities.hpp"
#include "std_msgs/msg/detail/string__struct.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <string>

class PublisherNode : public rclcpp::Node {
private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub; 
public:
  PublisherNode(std::string name) : rclcpp::Node(name) {
    RCLCPP_INFO(this->get_logger(), "publisher node start");
    pub = this->create_publisher<std_msgs::msg::String>("topic", 10);

    rclcpp::Node::SharedPtr node_(this);
    while (true) {
        std_msgs::msg::String msg;
        msg.data = "hello!";
        pub->publish(msg);
        rclcpp::spin_some(node_);
    }
  }
};


int main(int argc, char** argv){
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PublisherNode>("publisher_node");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}