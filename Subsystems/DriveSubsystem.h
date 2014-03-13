#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "SubsystemWithCommand.hpp"
#include "../Commands/DriveWithJoystick.h"
#include "../Robotmap.h"

class DriveSubsystem: public SubsystemWithCommand<DriveWithJoystick>
{
public:
	DriveSubsystem();
	void DriveMecanum(float xVel, float yVel, float rotVel);
	bool EnableEncoders(CANJaguar::ControlMode mode = CANJaguar::kSpeed, float maxOutput = kMaxDriveRPM/*bool invertGains = true*/);
	void DisableEncoders();
	void EnableSafety();
	void DisableSafety();
	void Flip();
	void SetMajorAxisMode(bool on);
	void SetMaxOutput(float maxOutput);
	void init();
	
	double P;
	double I;
	double D;
	int n;
private:
	bool m_majorAxisMode;
	int frontLeft_alive;
	int frontRight_alive;
	int backLeft_alive;
	int backRight_alive;
	bool backwards;
	CANJaguar m_frontLeft;
	CANJaguar m_frontRight;
	CANJaguar m_backLeft;
	CANJaguar m_backRight;
	RobotDrive m_drive;
};
