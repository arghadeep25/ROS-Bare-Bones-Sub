FROM ros:melodic
LABEL maintainer "Arghadeep Mazumder <arghadeep25@gmail.com>"

RUN apt-get update && apt-get install -y --no-install-recommends \
  && apt-get install -y --no-install-recommends \
  wget nano build-essential libomp-dev clang lld ros-melodic-pcl-ros \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

# Create local catkin workspace
ENV CATKIN_WS=/root/catkin_ws
RUN mkdir -p $CATKIN_WS/src
WORKDIR $CATKIN_WS/src

RUN /bin/bash -c '. /opt/ros/melodic/setup.bash; catkin_init_workspace'

COPY . /root/catkin_ws/src/rosbarebones/

WORKDIR $CATKIN_WS
RUN /bin/bash -c '. /opt/ros/melodic/setup.bash; catkin_make'
RUN sed -i "6i source \"/root/catkin_ws/devel/setup.bash\"" /ros_entrypoint.sh

RUN echo "source /root/catkin_ws/devel/setup.bash" >> ~/.bashrc

WORKDIR /
ENTRYPOINT ["/ros_entrypoint.sh"]
WORKDIR $CATKIN_WS/src/rosbarebones
CMD ["./run.sh"]