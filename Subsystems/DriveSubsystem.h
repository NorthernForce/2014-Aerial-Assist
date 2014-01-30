#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <memory>

	// Forward decl for using auto_ptr below
	class DriveWithJoystick;

class DriveSubsystem: public Subsystem 
{
	private:
		typedef std::auto_ptr<DriveWithJoystick> SmartJoyStickPtr;
			
	public:
		DriveSubsystem();
		void InitDefaultCommand();
		void DriveMecanum(float xVel, float yVel, float rotVel);
		
	private:
		Jaguar m_frontLeft;
		Jaguar m_frontRight;
		Jaguar m_backLeft;
		Jaguar m_backRight;
		RobotDrive m_drive;
		SmartJoyStickPtr m_joyStick;		
};

#endif
