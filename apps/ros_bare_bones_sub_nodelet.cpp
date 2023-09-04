/************************************
 * @file ros_barebones_sub_nodelet.cpp
 * @details ROS Bare Bones Nodelet Subscriber
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/
#include <nodelet/nodelet.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud.h>

#include <iostream>
#include <random>
#include <utils.hpp>

namespace ros_bare_bones_sub {
class ROSBareBonesSubNodelet : public nodelet::Nodelet {
 public:
  using PointT = pcl::PointXYZ;

 public:
  // Default Constructor
  ROSBareBonesSubNodelet() = default;

 public:
  // Default Destructor
  ~ROSBareBonesSubNodelet() override = default;

 private:
  /**
   * @brief init function
   */
  void onInit() override {
    // ROS nodelet info with function name
    NODELET_INFO("ROSBareBonesSubNodelet - %s", __FUNCTION__);
    nh = getNodeHandle();
    points_sub = mt_nh.subscribe(
        "/point_cloud", 1, &ROSBareBonesSubNodelet::points_callback, this);
  }

 private:
  /**
   * @brief Points Callback function
   */
  void points_callback(const sensor_msgs::PointCloud &points_msg) {
    // ROS nodelet info with function name
    NODELET_INFO("ROSBareBonesSubNodelet - %s", __FUNCTION__);
    std::cout << "Size: " << points_msg.points.size() << std::endl;
  }

 private:
  // ROS Node Handler
  ros::NodeHandle nh;
  ros::NodeHandle mt_nh;
  // Publisher and Subscriber
  ros::Subscriber points_sub;
};
PLUGINLIB_EXPORT_CLASS(ros_bare_bones_sub::ROSBareBonesSubNodelet,
                       nodelet::Nodelet)
}  // namespace ros_bare_bones_sub