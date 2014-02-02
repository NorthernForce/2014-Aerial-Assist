#include "Shoot.h"
#include "../Main.h"

Shoot::Shoot() {
    Requires(&Main::getPneumatics());
}

void Shoot::Initialize() {
    printf("Shooting!\n");
    Main::getPneumatics().SetShooter(true);
}

void Shoot::Execute() {
}

bool Shoot::IsFinished() {
	return TimeSinceInitialized() > 1.0;
}

void Shoot::End() {
    Main::getPneumatics().SetShooter(false);
    printf("Done Shooting!\n");
}

void Shoot::Interrupted() {
}
