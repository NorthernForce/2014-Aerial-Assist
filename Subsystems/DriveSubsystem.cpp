#include "DriveSubsystem.h"
#include "../Commands/DriveWithJoystick.h"
#include "../Robotmap.h"

DriveSubsystem::DriveSubsystem() try : 
	Subsystem("DriveSubsystem"), 
    m_frontLeft(kFrontLeftJaguar), 
    m_frontRight(kFrontRightJaguar), 
    m_backLeft(kBackLeftJaguar), 
    m_backRight(kBackRightJaguar),
    m_drive(m_frontLeft, m_frontRight, m_backLeft, m_backRight),
    m_joyStick(0) 

{	
	//This can be removed once we get the robot running.
	m_drive.SetSafetyEnabled(false); 
}
catch(...)
{
	std::cout << "Exception thrown from constructor." << std::endl;
	throw;
}
    
void DriveSubsystem::InitDefaultCommand() 
{
	// Assign a new DriveWithJoystick pointer to our auto_ptr 
	// so that if an exception is thrown we don't leak memory
	// and so the refernce count on the auto_ptr is such that 
	// the pointer won't be deleted when InitDefaultCommand 
	// terminates.
	m_joyStick  = SmartJoyStickPtr(new DriveWithJoystick());
	
	// Hand the raw pointer over to the SetDefaultCommand 
	// member function but we still have control of it so 
	// that it can be deleted properly
	SetDefaultCommand(m_joyStick.get());
}

void DriveSubsystem::DriveMecanum(float xVel, float yVel, float rotVel) 
{
	// Capture exceptions so we have better control over
	// what is happening.
	try
	{
      //m_drive.ArcadeDrive(xVel, yVel, false); 
      m_drive.MecanumDrive_Cartesian(xVel, yVel, rotVel);
	}
	catch (const std::exception& e)
	{
      std::cout << "Exception thrown in DriveSubsystem::DriveMecanum "
    		    << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Some other exception was thrown!" << std::endl;
	}
}
