#!/usr/bin/env bash

HERE=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
echo "HERE=${HERE}"

DEVICE_IP="10.75.68.6"
export ROS_MASTER_URI="http://${DEVICE_IP}:11311"


source ${HERE}/../../devel/setup.bash
roslaunch ros_bare_bones_sub ros_bare_bones_sub.launch