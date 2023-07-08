#include "rclcpp/executors.hpp"
#include "rclcpp/logging.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/utilities.hpp"
#include <memory>

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("hello_node");
    RCLCPP_INFO(node->get_logger(), "hello world");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}