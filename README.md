# 2018RobotCode
#### C++/GettingStarted: C++ ArcadeDrive code using 4 of 6 Talon SRXs.
#### Python/GettingStarted/CANTalon: Python ArcadeDrive code using all 6 Talon SRXs to drive the robot
## Deploying to the robot using Python3
Install pyfrc using this guide: http://robotpy.readthedocs.io/en/stable/install/pyfrc.html

In the directory with python code, run this command:
#### Windows:
```
py -3 ./robot.py deploy
```
#### Linux / Mac:
```
python3 ./robot.py deploy
```
Make sure the RoboRio is either on the LAN or connected through USB.
## Deploying to the robot using C++
In the directory with the build file and cmake files run these commands:
### Linux / Mac:
Before deploying, you must install the C++ toolchains on your computer.
Do this by running 
```
./gradlew installToolchain
```

For building and deploying run this code:
```
./gradlew clean
./gradlew build
./gradlew deploy
```
As with the python code you must make sure the RoboRio is either on the LAN or connected through USB to your computer.
