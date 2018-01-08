#include "ctre/Phoenix.h"
#include "WPILib.h"
#include <iostream>
using namespace std;

//#include "CANTalon.h"

class Robot: public IterativeRobot
{
	TalonSRX *leftMaster;
	TalonSRX *rightMaster;
    TalonSRX *leftFrontSlave;
    TalonSRX *rightFrontSlave;
	TalonSRX *leftBackSlave;
	TalonSRX *rightBackSlave;
	Joystick *joystick;
	float clamp(float min, float max, float input) {
	if (input > max) {
		return max;
	}
	if (input < min) {
		return min;
	}
	return input;
	}
	float exponent_mirrored(float exponent, float input) {
		return pow(fabs(input), exponent) * (input > 0 ? 1.0 : -1.0);
	}


public:
	Robot() {
	rightMaster = new TalonSRX(4); //Master
	rightFrontSlave = new TalonSRX(5); //Slave
    rightFrontSlave->Set(ControlMode::Follower, 4); //Set to following ID 4
    rightBackSlave = new TalonSRX(6);  //Slave
    rightBackSlave->Set(ControlMode::Follower, 4); //Set to following ID 4
    rightMaster->SetInverted(true);
    rightFrontSlave->SetInverted(true);
	rightBackSlave->SetInverted(true);

    leftMaster = new TalonSRX(1); //Master
	leftFrontSlave = new TalonSRX(2); //Slave
    leftFrontSlave->Set(ControlMode::Follower, 1); //Set to following ID 1
    leftBackSlave = new TalonSRX(3); //Slave
    leftBackSlave->Set(ControlMode::Follower, 1); //Set to following ID 1
	joystick = new Joystick(1);
	}

	void AutonomousPeriodic()
	{
		//drive->Drive(0.25,0.0);
	}

	void TeleopPeriodic()
	{
			// float joystick_adj_y = exponent_mirrored(3.0, joystick->GetRawAxis(1)); //TODO: Use constants to define the raw axis
			// float joystick_adj_x = exponent_mirrored(2.0, joystick->GetRawAxis(4));
			// float left_tracks = clamp(-1.0, 1.0, joystick_adj_y + joystick_adj_x);
			// float right_tracks = clamp(-1.0, 1.0, joystick_adj_y - joystick_adj_x);
			float left_tracks = (joystick->GetRawAxis(1) - joystick->GetRawAxis(0));
			float right_tracks = (joystick->GetRawAxis(1) + joystick->GetRawAxis(0));
			//cout<<left_tracks<<"Y\n";
			leftMaster->Set(ControlMode::PercentOutput, left_tracks); //TODO: Change this to velocity control
			rightMaster->Set(ControlMode::PercentOutput, right_tracks);

	}
};

START_ROBOT_CLASS(Robot)
