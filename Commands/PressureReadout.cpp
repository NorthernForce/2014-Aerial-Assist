#include "PressureReadout.h"
#include "../Main.h"
#include <WPILib.h>

PressureReadout::PressureReadout() :
	n(0)
{
	Requires(&Main::getPressure());
}

void PressureReadout::Initialize() {
	n = 0;
}

void PressureReadout::Execute() {
	if((n % 20) == 0) {
		SmartDashboard::PutNumber("Pressure (PSI)", Main::getPressure().getPSI());
	}
	
	++n;
}

bool PressureReadout::IsFinished() {
	return false;
}

void PressureReadout::End() {}

void PressureReadout::Interrupted() {
	End();
}
