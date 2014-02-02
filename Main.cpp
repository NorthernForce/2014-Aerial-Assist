#include "Main.h"

Main& Main::getRobot() {
	return static_cast<Main&>(RobotBase::getInstance());
}

PneumaticSubsystem& Main::getPneumatics() {
	return getRobot().s_pneumatics;
}

DriveSubsystem& Main::getDrive() {
	return getRobot().s_drive;
}

OI& Main::getOI() {
	return getRobot().oi;
}

void Main::RobotInit() {
	//Subsys::init();
	oi.init();
	lw = LiveWindow::GetInstance();
}
	
void Main::AutonomousInit() {
}
	
void Main::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TeleopInit() {
}

void Main::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Main);

