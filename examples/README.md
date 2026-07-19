# Examples
## Usage
### Build
```sh
source /opt/ros/$ROS_DISTRO/setup.bash

cd /home/ros2$ROS_DISTRO/ros_ws/
colcon build --merge-install --symlink-install --build-base build_release --install-base install_release --cmake-args -DCMAKE_BUILD_TYPE=Release --event-handlers status+ console_cohesion+ console_direct+ console_start_end+ console_stderr+

```
