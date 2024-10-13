from setuptools import find_packages
from setuptools import setup

setup(
    name='flatland_msgs',
    version='2.0.0',
    packages=find_packages(
        include=('flatland_msgs', 'flatland_msgs.*')),
)
