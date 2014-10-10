#include "DriveFor.h"
#include "../Main.h"

DriveFor::DriveFor(double speed, double time) : m_speed(speed), m_time(time) {
	Requires(&Main::getDrive());
}

void DriveFor::Initialize() {}

void DriveFor::Execute() {
	Main::getDrive().Drive(0, m_speed, 0);
}

bool DriveFor::IsFinished() {
	return TimeSinceInitialized() > m_time;
}

void DriveFor::End() {
	Main::getDrive().Drive(0, 0, 0);
}

void DriveFor::Interrupted() {
	End();
}
