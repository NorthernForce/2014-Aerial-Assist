#include "RangeReadout.h"
#include "WPILib.h"
#include "../Main.h"

RangeReadout::RangeReadout() {
    Requires(&Main::getUltrasonic());
}

void RangeReadout::Initialize() {
	n = 0;
}

void RangeReadout::Execute() {
	if(n%10 == 0) {
		SmartDashboard::PutNumber("Range", Main::getUltrasonic().GetRangeInInches());
		n = 0;
	}
	++n;
}

bool RangeReadout::IsFinished() {
	return false;
}

void RangeReadout::End() {
}

void RangeReadout::Interrupted() {
}
