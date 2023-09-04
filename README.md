## ROS Bare Bones Subscriber

The idea of this repo is to subscribe ROS messages from a server which is connected on the same network (physically or virtually).

On the server, this [publisher](https://github.com/arghadeep25/ROS-Bare-Bones/tree/rviz_docker) is used. So to get the messages and test the functionality, used this repo to run on different machine.

For tutorial, use this [link](https://github.com/arghadeep25/ROS_Multiple_Devices).

### Build
```
mkdir ros_bare_bones_sub && cd ros_bare_bones_sub
mkdir catkin_ws && cd catkin_ws
mkdir src && cd src
git clone git@github.com:arghadeep25/ROS-Bare-Bones-Sub.git
cd ../
catkin_make
```

### Usage
To connect to the server, get the server IP address and add in the run script

```
DEVICE_IP="192.168.0.25"
export ROS_MASTER_URI="http://${DEVICE_IP}:11311"
export ROS_IP=${DEVICE_IP}
```

Don't forget to uncomment the three lines.

```
./run.sh
```