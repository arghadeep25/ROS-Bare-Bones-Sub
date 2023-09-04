#!/usr/bin/env bash

HERE=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
echo "HERE=${HERE}"

# DEVICE_IP="192.168.0.25"
# export ROS_MASTER_URI="http://${DEVICE_IP}:11311"
# export ROS_IP=${DEVICE_IP}

source ${HERE}/../../devel/setup.bash
roslaunch ros_bare_bones_sub ros_bare_bones_sub.launch