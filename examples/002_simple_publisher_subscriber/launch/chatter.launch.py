from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='simple_publisher_subscriber',
            executable='pub_cpp',
            name='publisher',
            output='screen',
        ),
        Node(
            package='simple_publisher_subscriber',
            executable='sub_cpp',
            name='subscriber',
            output='screen',
        ),
    ])
