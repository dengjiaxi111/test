from setuptools import setup

setup(
    name='fake_vel_transform', version='0.1.0',
    packages=['fake_vel_transform'],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/fake_vel_transform']),
        ('share/fake_vel_transform', ['package.xml']),
        ('share/fake_vel_transform/launch', ['launch/fake_vel_transform.launch.py']),
    ],
    install_requires=['setuptools'],
    entry_points={'console_scripts': [
        'fake_vel_transform_node = fake_vel_transform.node:main',
    ]},
)
