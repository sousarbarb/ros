# ROS_DOMAIN_ID Variable
In DDS (default middleware in ROS 2 for communication), the primary mechanism
to have different logical networks sharing the same physical network is through
Domain ID. ROS 2 nodes on the same domain can discover and send messages to each
other, while ROS 2 nodes on different domains cannot. By default, all ROS 2
nodes use the domain ID 0.

**Domain ID:** [0,232]
(impacts the computation of the UDP port for discovery and communication).

**Source:**
https://docs.ros.org/en/lyrical/Concepts/Intermediate/About-Domain-ID.html

## Usage
### Run
**Terminal 1**
```sh
source /opt/ros/${ROS_DISTRO}/setup.bash

export ROS_DOMAIN_ID=21
ros2 run demo_nodes_cpp talker
```

**Terminal 2**
```sh
source /opt/ros/${ROS_DISTRO}/setup.bash

export ROS_DOMAIN_ID=20
ros2 run demo_nodes_cpp listener
# should not appear anything... Ctrl+C to exit the program

export ROS_DOMAIN_ID=21
ros2 run demo_nodes_cpp listener
# Now, it works!
```
