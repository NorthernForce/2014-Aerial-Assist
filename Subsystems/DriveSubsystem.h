#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem {
private:
    Jaguar frontLeft;
    Jaguar frontRight;
    Jaguar backLeft;
    Jaguar backRight;
    RobotDrive drive;
public:
	DriveSubsystem();
	void InitDefaultCommand();
    void DriveMecanum(float XVel, float YVel, float RotVel);
};

#endif
