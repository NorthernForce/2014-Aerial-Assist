#include "KeepAlive.h"
#include "WPILib.h"
#include "../Main.h"

KeepAlive::KeepAlive() {
    //Requires(&Main::getBall());
}

void KeepAlive::Initialize() {
	n = 0;
}

void KeepAlive::Execute() {
	if((n%10) == 0) {
		// This will help detect if the beaglebone isn't
		// responding, and put the subsystem into a state
		// of waiting to accept new connections.
		//Main::getBall().StopFeedback();
		n = 0;
	}
	++n;
}

bool KeepAlive::IsFinished() {
	return false;
}

void KeepAlive::End() {
}

void KeepAlive::Interrupted() {
}
