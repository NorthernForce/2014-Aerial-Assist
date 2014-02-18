#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"
#include "SubsystemWithCommand.hpp"

class SensorSubsystem: public SubsystemWithCommand<void>
{
public:
	SensorSubsystem();
    float getRange();
private:
    //Ultrasonic m_rangeFinder;
};

