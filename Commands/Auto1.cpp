#include "Auto1.h"
#include "../Main.h"

Auto1::Auto1() : r(0.0, -10.1) {
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
    Requires(&Main::getDrive());
}

void Auto1::Initialize() {
	Main::getDrive().SetDriveMode(MecanumDrive::POSITION);
	Main::getPickup().SetIntakePosition(EXTEND);
}

void Auto1::Execute() {
	double t = TimeSinceInitialized();
	
	Main::getDrive().Drive(0, r.getOutput(t), 0);
	
	if(t > 1.7 && t < 4.0) {
		Main::getPickup().SetIntakePosition(RETRACT);
	} else if(t > 4.0 && t < 4.25) {
		Main::getPneumatics().SetShooter(true);
	} else if(t > 4.25) {
		Main::getPickup().SetIntakeSpeed(1.0);
		Main::getPickup().SetIntakePosition(EXTEND);
	}
}

bool Auto1::IsFinished() {
	return TimeSinceInitialized() > 10.0;
}

void Auto1::End() {
	Main::getPickup().SetIntakeSpeed(0.0);
    Main::getPneumatics().SetShooter(false);
}

void Auto1::Interrupted() {
	End();
}
