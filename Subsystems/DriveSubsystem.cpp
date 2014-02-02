#include "DriveSubsystem.h"
#include "../Commands/DriveWithJoystick.h"
#include "../Robotmap.h"

DriveSubsystem::DriveSubsystem(): 
	SubsystemWithCommand<DriveWithJoystick>("DriveSubsystem"), 
    m_frontLeft(kFrontLeftJaguar), 
    m_frontRight(kFrontRightJaguar), 
    m_backLeft(kBackLeftJaguar), 
    m_backRight(kBackRightJaguar),
    m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight)
{	
	// Invert the left motors.
    m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
    m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
    
    // Make sure the timeout is reasonable
    m_drive.SetExpiration(0.1);
    
    // Not sure that this does much.
    m_frontLeft.SetVoltageRampRate(50.0);
    m_backLeft.SetVoltageRampRate(50.0);
    m_frontRight.SetVoltageRampRate(50.0);
    m_backRight.SetVoltageRampRate(50.0);
}
    
void DriveSubsystem::DriveMecanum(float xVel, float yVel, float rotVel) {
	m_drive.MecanumDrive_Cartesian(xVel, yVel, rotVel);
}
