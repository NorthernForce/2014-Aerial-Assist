#include "RangeReadout.h"
#include "WPILib.h"
#include "../Main.h"

RangeReadout::RangeReadout() {
    Requires(&Main::getUltrasonic());
}

void RangeReadout::Initialize() {
}

void RangeReadout::Execute() {
	SmartDashboard::PutNumber("Range", Main::getUltrasonic().GetRangeInInches());
}

bool RangeReadout::IsFinished() {
	return false;
}

void RangeReadout::End() {
}

void RangeReadout::Interrupted() {
}
