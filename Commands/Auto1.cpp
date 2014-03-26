#include "Auto1.h"
#include "../Main.h"

Auto1::Auto1() : r1(0.0, -10.0), r2(-10.0, 3.0), r3(3.0, -10.0) {
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
    Requires(&Main::getDrive());
}

void Auto1::Initialize() {
	Main::getDrive().SetDriveMode(MecanumDrive::POSITION);
}

void Auto1::Execute() {
	double t = TimeSinceInitialized();
	if(t<3.0) {
		Main::getDrive().Drive(0, r1.getOutput(t), 0);
	} else if(t<6.0){
		Main::getDrive().Drive(0, r2.getOutput(t-3.0), 0);
	} else {
		Main::getDrive().Drive(0, r3.getOutput(t-6.0), 0);
	}
}

bool Auto1::IsFinished() {
	return TimeSinceInitialized() > 10.0;
	//return TimeSinceInitialized() > 2.0;
}

void Auto1::End() {
	Main::getPickup().SetIntakeSpeed(0.0);
    Main::getPneumatics().SetShooter(false);
}

void Auto1::Interrupted() {
	End();
}
