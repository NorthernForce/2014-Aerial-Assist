#include "DriveFor.h"
#include "../Main.h"

DriveFor::DriveFor(double speed, double time) : speed(speed), time(time) {
	Requires(&Main::getDrive());
}

void DriveFor::Initialize() {}

void DriveFor::Execute() {
	Main::getDrive().Drive(0, speed, 0);
}

bool DriveFor::IsFinished() {
	return TimeSinceInitialized() > time;
}

void DriveFor::End() {
	Main::getDrive().Drive(0, 0, 0);
}

void DriveFor::Interrupted() {
	End();
}
