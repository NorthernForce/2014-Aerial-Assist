#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"
#include "SubsystemWithCommand.hpp"

class PneumaticSubsystem: public SubsystemWithCommand<void>
{
public:
	PneumaticSubsystem();
    void SetShooter(bool extend);
private:
    Relay m_ShooterCyls;
};

