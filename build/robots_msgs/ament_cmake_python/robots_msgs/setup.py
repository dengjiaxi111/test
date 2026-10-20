from setuptools import find_packages
from setuptools import setup

setup(
    name='robots_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('robots_msgs', 'robots_msgs.*')),
)
