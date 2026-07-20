# Examples
## Usage
### Create
```sh
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/ros2$ROS_DISTRO/ros_ws/src/examples/
ros2 pkg create                                   \
  --package-format 3                              \
  --description '<package description>'           \
  --license <package license>                     \
  --destination-directory <destination directory> \
  --build-type ament_cmake                        \
  --dependencies rclcpp <...>                     \
  --maintainer-email 'sousa.ricardob@outlook.com' \
  --maintainer-name  'Ricardo B. Sousa'           \
  --node-name <node name>                         \
  <package name>
```
### Build
```sh
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/ros2$ROS_DISTRO/ros_ws/
colcon build --merge-install --symlink-install --build-base build_release --install-base install_release --cmake-args -DCMAKE_BUILD_TYPE=Release --event-handlers status+ console_cohesion+ console_direct+ console_start_end+ console_stderr+

source install_release/setup.bash
```
