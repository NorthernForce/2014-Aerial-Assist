#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"
#include "SubsystemWithCommand.hpp"

enum Position {
	EXTEND,
	RETRACT,
};

class PickupSubsystem: public SubsystemWithCommand<void>
{
public:
	PickupSubsystem();
    void SetIntakeSpeed(float speed);
    void SetIntakePosition(Position dir);
    void init();
private:
    CANJaguar m_PickupJag;
    Relay m_PickupCyls;
};

