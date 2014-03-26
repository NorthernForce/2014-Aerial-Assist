#include "Main.h"
#include "Commands/DriveTo.h"
#include "Commands/Auto1.h"

Main::Main() :
	s_pressure(k_pressureChannel),
	s_ballServer(kBallDataPort),
	s_ultrasonic(k_targetingUltrasonic, k_targetingUltrasonicSerialMode, k_targetingUltrasonicOn)
{
	
}

Main& Main::getRobot() {
	return static_cast<Main&>(RobotBase::getInstance());
}

PneumaticSubsystem& Main::getPneumatics() {
	return getRobot().s_pneumatics;
}

MecanumDrive& Main::getDrive() {
	return getRobot().s_drive;
}

PickupSubsystem& Main::getPickup() {
	return getRobot().s_pickup;
}

MaxbotixUltrasonic& Main::getUltrasonic(){
	return getRobot().s_ultrasonic;
}

PressureSensor& Main::getPressure(){
	return getRobot().s_pressure;
}

OI& Main::getOI() {
	return getRobot().oi;
}

BallCmdServer& Main::getBall() {
	return getRobot().s_ballServer;
}

void Main::RobotInit() {
	oi.init();
	s_drive.Init();
	s_pickup.init();
	s_ballServer.init();
	//autocmd = new DriveTo(0.0, 10.0);// Auto();
    autocmd = new Auto1();
	//lw = LiveWindow::GetInstance();
}
	
void Main::AutonomousInit() {
	//s_drive.DisableSafety();
	s_drive.SetSafetyEnabled(false);
	//s_drive.EnableEncoders();
	//s_drive.SetDriveMode(MecanumDrive::SPEED);
	autocmd->Start();
}
	
void Main::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TeleopInit() {
	//s_drive.EnableEncoders();
	//s_drive.SetDriveMode(MecanumDrive::SPEED);
	autocmd->Cancel();
	//s_drive.EnableSafety();
	s_drive.SetSafetyEnabled(true);
}

void Main::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TestPeriodic() {
	//lw->Run();
}

START_ROBOT_CLASS(Main);

