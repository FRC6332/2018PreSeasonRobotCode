#include "WPILib.h"
#include "CANTalon.h"


class Robot: public IterativeRobot
{
	CANTalon *leftMaster;
	CANTalon *rightMaster;
    CANTalon *leftFrontSlave;
    CANTalon *rightFrontSlave;
	CANTalon *leftBackSlave;
	CANTalon *rightBackSlave;
    //CANTalon *middleLeft;
    //CANTalon *middleRight;

	Joystick *joystick;
	RobotDrive *drive;
public:
	Robot() {

		rightMaster = new CANTalon(4); //Master
		rightFrontSlave = new CANTalon(5); //Slave
        rightFrontSlave->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
        rightFrontSlave->Set(4);
        rightBackSlave = new CANTalon(6);  //Slave
        rightBackSlave->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
        rightBackSlave->Set(4);


        leftMaster = new CANTalon(1); //Master
		leftFrontSlave = new CANTalon(2); //Slave
        leftFrontSlave->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
        leftFrontSlave->Set(1);
        leftBackSlave = new CANTalon(3); //Slave
        leftBackSlave->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
        leftBackSlave->Set(1);

		joystick = new Joystick(1);
		drive = new RobotDrive(leftMaster, rightMaster);
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
