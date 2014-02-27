#include "AutonomousDrive.h"
#include "../Main.h"
#include <cmath>

AutonomousDrive::AutonomousDrive() {
    Requires(&Main::getDrive());
}

void AutonomousDrive::Initialize() {
	startSystemTimeUS = GetUsClock();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousDrive::Execute() {
    // X velocity
    float x = speed;
    //x *= fabs(x);
    // Y velocity
    float y = 0;
    //y *= fabs(y);
    // Angular velocity
    float w = 0;
    //w *= fabs(w);
    
    // Send command to drive subsystem
	Main::getDrive().DriveMecanum(x, y, w);
}

// This is a default command which should never stop, except when kicked off by another command.
bool AutonomousDrive::IsFinished() {
	long runtimeUS = GetUsClock() - startSystemTimeUS;
	float runtimeseconds = runtimeUS / 1.0e6;
	if (runtimeseconds >= DriveTime){
		return true;
	} else {
		return false;
	}
	
}

void AutonomousDrive::End() {
    printf("DriveWithJoystick Ended");
}

void AutonomousDrive::Interrupted() {
    printf("DriveWithJoystick Interrupted");
}
