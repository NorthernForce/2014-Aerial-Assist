#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/PickupSubsystem.h"
#include "Subsystems/MecanumDrive.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/MaxbotixUltrasonic.h"
#include "Subsystems/BallCmdServer.h"
#include "Subsystems/PressureSensor.h"
#include "Commands/Auto.h"
#include "OI.h"

class Main : public IterativeRobot {
public:
	Main();
	
	static Main& 				getRobot();
	static PneumaticSubsystem& 	getPneumatics();
	static MecanumDrive& 		getDrive();
	static OI& 					getOI();
	static PickupSubsystem&     getPickup();
	static PressureSensor&		getPressure();
	
	static BallCmdServer& getBall();
	static MaxbotixUltrasonic&	getUltrasonic();
	
private:
	LiveWindow *lw;
	Command* autocmd;
	PneumaticSubsystem s_pneumatics;
	MecanumDrive 	   s_drive;
	PickupSubsystem    s_pickup;
	PressureSensor	   s_pressure;
	
	BallCmdServer s_ballServer;
	
	MaxbotixUltrasonic s_ultrasonic;
	OI				   oi;
	
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

