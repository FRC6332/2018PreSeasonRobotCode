#include "WPILib.h"
#include "CANTalon.h"


class Robot: public IterativeRobot
{
	CANTalon *frontLeft;
	CANTalon *frontRight;
    CANTalon *middleLeft;
    CANTalon *middleRight;
	CANTalon *backLeft;
	CANTalon *backRight;

	Joystick *joystick;
	RobotDrive *drive;
public:
	Robot() {

		frontRight = new CANTalon(4);
		middleRight = new CANTalon(5);
		backRight = new CANTalon(6);

		frontLeft = new CANTalon(1);
		middleLeft = new CANTalon(2);
		backLeft = new CANTalon(3);

		joystick = new Joystick(1);
		drive = new RobotDrive(frontLeft, backLeft, frontRight, backRight);
	}

	void AutonomousPeriodic()
	{
		drive->Drive(0.25,0.0);
	}

	void TeleopPeriodic()
	{
		drive->ArcadeDrive(joystick);
	}
};

START_ROBOT_CLASS(Robot)
