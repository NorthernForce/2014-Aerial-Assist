#include "Auto.h"
#include "../Main.h"

Auto::Auto() {
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
    Requires(&Main::getDrive());
}

void Auto::Initialize() {
	//Main::getDrive().EnableEncoders();
	Main::getDrive().SetDriveMode(MecanumDrive::SPEED);
	//unsigned long t = GetMsClock();
	//printf("AUTO-INIT:%d", t);
	//Main::getPneumatics().SetShooter(true);
}

void Auto::Execute() {
	double t = TimeSinceInitialized();
	//Main::getPickup().SetIntakeSpeed(1.0);
	if(t < 1.55) {
		Main::getPickup().SetIntakePosition(EXTEND);
		//Main::getDrive().DriveMecanum(0, -1.0, 0.0);
		Main::getDrive().Drive(0, -1.0, 0);
	} else if(t < 2.0) {
		//Main::getDrive().DriveMecanum(0,0,0);
		Main::getDrive().Drive(0,0,0);
		Main::getPickup().SetIntakePosition(RETRACT);
	} else if(t < 6.5) {
		//Main::getDrive().DriveMecanum(0,0,0);
		Main::getDrive().Drive(0,0,0);
	} else if(t < 7.5) {
		//Main::getPikup().SetIntakeSpeed(1.0);
		Main::getPneumatics().SetShooter(true);
		//Main::getDrive().DriveMecanum(0,0,0);;
		Main::getDrive().Drive(0,0,0);
	} else {
		Main::getPickup().SetIntakeSpeed(1.0);
		//Main::getPneumatics().SetShooter(true);
		Main::getPickup().SetIntakePosition(EXTEND);
		//Main::getDrive().DriveMecanum(0,0,0);
		Main::getDrive().Drive(0,0,0);
	}
}

bool Auto::IsFinished() {
	return TimeSinceInitialized() > 9.0;
	//return TimeSinceInitialized() > 2.0;
}

void Auto::End() {
	Main::getPickup().SetIntakeSpeed(0.0);
    Main::getPneumatics().SetShooter(false);
    
    // We may want it to retract automatically, but
    // doing so uses up a good amount of air.
    //Main::getPickup().SetIntakePosition(RETRACT);
}

void Auto::Interrupted() {
}
