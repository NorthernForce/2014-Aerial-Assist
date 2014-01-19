#include "DriveSubsystem.h"
#include "../Commands/DriveWithJoystick.h"
#include "../Robotmap.h"

DriveSubsystem::DriveSubsystem() : Subsystem("DriveSubsystem"), 
    frontLeft(kFrontLeftJaguar), 
    frontRight(kFrontRightJaguar), 
    backLeft(kBackLeftJaguar), 
    backRight(kBackRightJaguar),
    drive(frontLeft, backLeft, frontRight, backRight) {
}
    
void DriveSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new DriveWithJoystick());
}

void DriveSubsystem::DriveMecanum(float XVel, float YVel, float RotVel) {
    drive.MecanumDrive_Cartesian(XVel, YVel, RotVel);
}
