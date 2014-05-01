#include "Main.h"
#include "Commands/DriveTo.h"
#include "Commands/Auto1.h"

//static bool done = false;

Main::Main() :
	m_frontLeft(kFrontLeftJaguar),
	m_frontRight(kFrontRightJaguar),
	m_backLeft(kBackLeftJaguar),
	m_backRight(kBackRightJaguar),
	s_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
	s_pressure(k_pressureChannel),
	//s_ballServer(kBallDataPort),
	s_ultrasonic(k_targetingUltrasonic, k_targetingUltrasonicSerialMode, k_targetingUltrasonicOn)
{
	//printf("###Construct main\n");
	//done = true;
}

Main::~Main() {
	delete autocmd;
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

/*BallCmdServer& Main::getBall() {
	return getRobot().s_ballServer;
}*/

void Main::RobotInit() {
	s_drive.SetSafetyEnabled(false);
	//printf("###Init robot\n");
	//while(!done);
	//printf("###Done init\n");
	oi.init();
	s_drive.Init();
	s_pickup.init();
	//s_ballServer.init();
	//autocmd = new DriveTo(0.0, 10.0);// Auto();
    autocmd = new Auto1();
	//lw = LiveWindow::GetInstance();
}
	
void Main::AutonomousInit() {
	//printf("###start auto\n");
	//while(!done);
	s_drive.Feed();
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
	//printf("###start tele\n");
	//while(!done);
	s_drive.Feed();
	//s_drive.EnableEncoders();
	//s_drive.SetDriveMode(MecanumDrive::SPEED);
	autocmd->Cancel();
	//s_drive.EnableSafety();
	s_drive.SetSafetyEnabled(true);
	s_drive.Feed();
}

void Main::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Main::TestPeriodic() {
	//lw->Run();
}

START_ROBOT_CLASS(Main);

