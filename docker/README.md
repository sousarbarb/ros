# Docker
## Usage
### Build
```sh
cd docker/

docker build -f Dockerfile.ros2 -t ros2-dev:humble  --build-arg ROS_DISTRO=humble .
docker build -f Dockerfile.ros2 -t ros2-dev:jazzy   --build-arg ROS_DISTRO=jazzy .
docker build -f Dockerfile.ros2 -t ros2-dev:lyrical --build-arg ROS_DISTRO=lyrical .
```
### Run
```sh
distrobox create                                \
  --name ros2-dev-<humble|jazzy|lyrical>        \
  --image ros2-dev:<humble|jazzy|lyrical>       \
  --hostname <humble|jazzy|lyrical>             \
  --volume "/mnt/data/datasets:/home/datasets"  \
  --nvidia --yes

distrobox enter ros2-dev-<humble|jazzy|lyrical>

sudo chown -R $USER:$USER /home/ros2lyrical
```
