#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/PickupSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/MaxbotixUltrasonic.h"
#include "Subsystems/BallCmdServer.h"
#include "Commands/Auto.h"
#include "OI.h"

class Main : public IterativeRobot {
public:
	Main();
	
	static Main& 				getRobot();
	static PneumaticSubsystem& 	getPneumatics();
	static DriveSubsystem& 		getDrive();
	static OI& 					getOI();
	static PickupSubsystem&     getPickup();
	
	static BallCmdServer& getBall();
	static MaxbotixUltrasonic&	getUltrasonic();
	
private:
	LiveWindow *lw;
	Auto* autocmd;
	PneumaticSubsystem s_pneumatics;
	DriveSubsystem 	   s_drive;
	PickupSubsystem    s_pickup;
	
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

