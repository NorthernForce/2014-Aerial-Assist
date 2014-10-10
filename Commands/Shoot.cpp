#include "Shoot.h"
#include "../Main.h"

Shoot::Shoot() {
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
}

void Shoot::Initialize() {
	Main::getPneumatics().SetShooter(true);
}

void Shoot::Execute() {
	//Main::getPickup().SetIntakeSpeed(1.0);
	if(TimeSinceInitialized() < 0.25) {
		//Main::getPikup().SetIntakeSpeed(1.0);
	} else {
		Main::getPickup().SetIntakeSpeed(1.0);
		//Main::getPneumatics().SetShooter(true);
		Main::getPickup().SetIntakePosition(EXTEND);
	}
}

bool Shoot::IsFinished() {
	//return TimeSinceInitialized() > 2.5;
	return TimeSinceInitialized() > 1.75;
}

void Shoot::End() {
	Main::getPickup().SetIntakeSpeed(0.0);
    Main::getPneumatics().SetShooter(false);
    
    // We may want it to retract automatically, but
    // doing so uses up a good amount of air.
    //Main::getPickup().SetIntakePosition(RETRACT);
}

void Shoot::Interrupted() {
	End();
}
