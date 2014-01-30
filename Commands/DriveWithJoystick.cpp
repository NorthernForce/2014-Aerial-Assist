#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
    Requires(s_drive);
}

void DriveWithJoystick::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
    // X velocity
    float x = oi->GetDriverStick().GetLeftStickX();
    // Y velocity
    float y = oi->GetDriverStick().GetLeftStickY();
    // Angular velocity
    float w = oi->GetDriverStick().GetRightStickX();
    
    //Send joystick values to SmartDashboard
    SmartDashboard::PutNumber("Left Stick X Value: ", x); 
    SmartDashboard::PutNumber("Left Stick Y Value: ", y);
    SmartDashboard::PutNumber("Right Stick X Value: ", w);
    
    //printf("Drive the joystick");

    // Send command to drive subsystem
	s_drive->DriveMecanum(x, y, w);
}

// This is a default command which should never stop, except when kicked off by another command.
bool DriveWithJoystick::IsFinished() {
	return false;
}

void DriveWithJoystick::End() {
}

void DriveWithJoystick::Interrupted() {
}
