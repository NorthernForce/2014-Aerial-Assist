#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"
#include "SubsystemWithCommand.hpp"

class PneumaticSubsystem: public SubsystemWithCommand<void>
{
public:
	PneumaticSubsystem();
private:
};

