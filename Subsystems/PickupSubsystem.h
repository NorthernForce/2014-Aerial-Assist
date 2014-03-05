#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

enum Position {
	EXTEND,
	RETRACT,
};

class PickupSubsystem: public Subsystem
{
public:
	PickupSubsystem();
    void SetIntakeSpeed(float speed);
    void SetIntakePosition(Position dir);
    virtual void InitDefaultCommand();
    void init();
private:
    CANJaguar m_PickupJag;
    Relay m_PickupCyls;
};

