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
	
}

void DriveSubsystem::init() {
	
	// Invert the left motors.
	    m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	    m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	    
	    // Make sure the timeout is reasonable
	    m_drive.SetExpiration(0.1);
	    
	    // Not sure that this does much.
	    //m_frontLeft.SetVoltageRampRate(50.0);
	    //m_backLeft.SetVoltageRampRate(50.0);
	    //m_frontRight.SetVoltageRampRate(50.0);
	    //m_backRight.SetVoltageRampRate(50.0);
	    m_drive.SetMaxOutput(100.0);
	    // Put jaguars in speed mode
	    m_frontLeft.DisableControl();
	    m_backLeft.DisableControl();
	    m_frontRight.DisableControl();
	    m_backRight.DisableControl();
	    
	    m_frontLeft.ConfigMaxOutputVoltage(12.0);
	    m_backLeft.ConfigMaxOutputVoltage(12.0);
	    m_frontRight.ConfigMaxOutputVoltage(12.0);
	    m_backRight.ConfigMaxOutputVoltage(12.0);
	    
	    m_frontLeft.ChangeControlMode(CANJaguar::kSpeed);
	    m_backLeft.ChangeControlMode(CANJaguar::kSpeed);
	    m_frontRight.ChangeControlMode(CANJaguar::kSpeed);
	    m_backRight.ChangeControlMode(CANJaguar::kSpeed);
	    
	    //m_frontLeft.SetPID(1.0, 0.0, 0.0);
	    //m_backLeft.SetPID(1.0, 0.0, 0.0);
	    //m_frontRight.SetPID(1.0, 0.0, 0.0);
	    //m_backRight.SetPID(1.0, 0.0, 0.0);
	    
	    m_frontLeft.SetPID(1.25, 0.02, 0.0);
	    m_backLeft.SetPID(1.25, 0.02, 0.0);
	    m_frontRight.SetPID(1.25, 0.02, 0.0);
	    m_backRight.SetPID(1.25, 0.02, 0.0);
	    
	    m_frontLeft.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	    m_backLeft.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	    m_frontRight.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	    m_backRight.SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
	    // Set encoder pulses per rev
	    m_frontLeft.ConfigEncoderCodesPerRev(256);
	    m_backLeft.ConfigEncoderCodesPerRev(256);
	    m_frontRight.ConfigEncoderCodesPerRev(256);
	    m_backRight.ConfigEncoderCodesPerRev(256);
	    //printf("Enabling Speed Mode");
	    // Tell jaguar its got quadrature encoders
	    
	    
	    
	    
	    m_frontLeft.EnableControl();
	    m_backLeft.EnableControl();
	    m_frontRight.EnableControl();
	    m_backRight.EnableControl();
}
    
void DriveSubsystem::DriveMecanum(float xVel, float yVel, float rotVel) {
	m_drive.MecanumDrive_Cartesian(xVel, yVel, rotVel);
}
