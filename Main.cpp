#include "Main.h"

Main::Main() :
	s_ballServer(kBallDataPort),
	s_ultrasonic(k_targetingUltrasonic, k_targetingUltrasonicSerialMode, k_targetingUltrasonicOn)
{}

Main& Main::getRobot() {
	return static_cast<Main&>(RobotBase::getInstance());
}

PneumaticSubsystem& Main::getPneumatics() {
	return getRobot().s_pneumatics;
}

DriveSubsystem& Main::getDrive() {
	return getRobot().s_drive;
}

PickupSubsystem& Main::getPickup() {
	return getRobot().s_pickup;
}

MaxbotixUltrasonic& Main::getUltrasonic(){
	return getRobot().s_ultrasonic;
}

OI& Main::getOI() {
	return getRobot().oi;
}

BallCmdServer& Main::getBall() {
	return getRobot().s_ballServer;
}

void Main::RobotInit() {
	oi.init();
	s_drive.init();
	s_pickup.init();
	s_ballServer.init();
	autocmd = new Auto();
	lw = LiveWindow::GetInstance();
}
	
void Main::AutonomousInit() {
	//s_drive.DisableSafety();
	s_drive.EnableEncoders();
	autocmd->Start();
}
	
void Main::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TeleopInit() {
	s_drive.EnableEncoders();
	autocmd->Cancel();
	//s_drive.EnableSafety();
}

void Main::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Main);

