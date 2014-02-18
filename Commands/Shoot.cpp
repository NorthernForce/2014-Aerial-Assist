#include "Shoot.h"
#include "../Main.h"

Shoot::Shoot() {
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
}

void Shoot::Initialize() {
    Main::getPickup().SetIntakeSpeed(1.0);
    printf("Shooting\n");
}

void Shoot::Execute() {
	if(TimeSinceInitialized() > 1.0) {
		Main::getPickup().SetIntakeSpeed(0.0);
		Main::getPneumatics().SetShooter(true);
	}
}

bool Shoot::IsFinished() {
	return TimeSinceInitialized() > 1.5;
}

void Shoot::End() {
    Main::getPneumatics().SetShooter(false);
}

void Shoot::Interrupted() {
}
