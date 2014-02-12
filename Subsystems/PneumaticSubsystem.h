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
    void SetPickup(bool extend);
private:
    Compressor m_Compressor;
    Relay m_ShooterCyls;
    Relay m_PickupCyls;
};

