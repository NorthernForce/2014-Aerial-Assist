#include "ShootAtDistance.h"
#include "../Main.h"

ShootAtDistance::ShootAtDistance() {
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
}

void ShootAtDistance::Initialize() {
	ready = false;
	startTime = 0.0;
}

void ShootAtDistance::Execute() {
	if(!ready && (Main::getUltrasonic().GetRangeInInches()/12.0 - 2*Main::getDrive().GetYVel() <= 10.0)) {
		ready = true;
		startTime = TimeSinceInitialized();
	}
	if(ready) {
		if((TimeSinceInitialized() - startTime) < 0.25) {
			Main::getPneumatics().SetShooter(true);
		} else {
			Main::getPickup().SetIntakeSpeed(1.0);
			Main::getPickup().SetIntakePosition(EXTEND);
		}
	}
}

bool ShootAtDistance::IsFinished() {
	//return TimeSinceInitialized() > 2.5;
	return ready && (TimeSinceInitialized() - startTime) > 1.75;
}

void ShootAtDistance::End() {
	Main::getPickup().SetIntakeSpeed(0.0);
    Main::getPneumatics().SetShooter(false);
    
    // We may want it to retract automatically, but
    // doing so uses up a good amount of air.
    //Main::getPickup().SetIntakePosition(RETRACT);
}

void ShootAtDistance::Interrupted() {
	End();
}
