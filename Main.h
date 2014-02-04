#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "OI.h"

class Main : public IterativeRobot {
public:
	static Main& 				getRobot();
	static PneumaticSubsystem& 	getPneumatics();
	static DriveSubsystem& 		getDrive();
	static OI& 					getOI();
private:
	LiveWindow *lw;
	PneumaticSubsystem s_pneumatics;
	DriveSubsystem 	   s_drive;
	OI				   oi;
	
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

