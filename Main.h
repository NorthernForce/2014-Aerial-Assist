#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/PickupSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/MaxbotixUltrasonic.h"
#include "OI.h"

class Main : public IterativeRobot {
public:
	//We have to call the constuctor because MaxbotixUltrasonic 
	//does not have a default constructor. 
	Main() : 
	 s_ultrasonic(int(k_targetingUltrasonic), 
	   int(k_targetingUltrasonicSerialMode), 
	   int(k_targetingUltrasonicOn))
	{
	}
	
	static Main& 				getRobot();
	static PneumaticSubsystem& 	getPneumatics();
	static DriveSubsystem& 		getDrive();
	static OI& 					getOI();
	static PickupSubsystem&     getPickup();
	static MaxbotixUltrasonic&	getUltrasonic();
	
private:
	LiveWindow *lw;
	PneumaticSubsystem s_pneumatics;
	DriveSubsystem 	   s_drive;
	PickupSubsystem    s_pickup;
	MaxbotixUltrasonic s_ultrasonic;
	OI				   oi;
	
	
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

