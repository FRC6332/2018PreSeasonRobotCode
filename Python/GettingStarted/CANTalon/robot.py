#!/usr/bin/env python3

import wpilib
import ctre


class MyRobot(wpilib.SampleRobot):
    '''
        This is a short sample program demonstrating how to use the basic throttle
        mode of the new CAN Talon.
    '''

    def robotInit(self):
        self.motor0 = ctre.CANTalon(1) # Initialize the CanTalonSRX on device 1.
        self.motor1 = ctre.CANTalon(2) 
        self.motor2 = ctre.CANTalon(3)
        self.motor3 = ctre.CANTalon(4) # Initialize the CanTalonSRX on device 1.
        self.motor4 = ctre.CANTalon(5)
        self.motor5 = ctre.CANTalon(6)
        self.joy = wpilib.Joystick(1)

    def operatorControl(self):
        '''Runs the motor'''

        while self.isOperatorControl() and self.isEnabled():
            # Set the motor's output to half power.
            # This takes a number from -1 (100% speed in reverse) to +1 (100%
            # speed going forward)
            self.motor0.set(self.joy.getY() - self.joy.getX())
            self.motor1.set(self.joy.getY() - self.joy.getX())
            self.motor2.set(self.joy.getY() - self.joy.getX())
            self.motor3.set(self.joy.getY()*-1 - self.joy.getX())
            self.motor4.set(self.joy.getY()*-1 - self.joy.getX())
            self.motor5.set(self.joy.getY()*-1 - self.joy.getX())

            # print("looping at half-speed")
            # print("gety:", self.joy.getY())
            # print("getZ:", self.joy.getZ())
            # self.motor2.set(self.joy.getY())
            # self.motor3.set(self.joy.getY()*-1 - self.joy.getX())

            wpilib.Timer.delay(0.01)  # Note that the CANTalon only receives
                                      # updates every 10ms, so updating more
                                      # quickly would not gain you anything.

        self.motor.disable()

if __name__ == '__main__':
    wpilib.run(MyRobot)