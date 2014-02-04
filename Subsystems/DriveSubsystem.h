#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "SubsystemWithCommand.hpp"
#include "../Commands/DriveWithJoystick.h"

class DriveSubsystem: public SubsystemWithCommand<DriveWithJoystick>
{
public:
	DriveSubsystem();
	void DriveMecanum(float xVel, float yVel, float rotVel);
	void init();
		
private:
	CANJaguar m_frontLeft;
	CANJaguar m_frontRight;
	CANJaguar m_backLeft;
	CANJaguar m_backRight;
	RobotDrive m_drive;
};
