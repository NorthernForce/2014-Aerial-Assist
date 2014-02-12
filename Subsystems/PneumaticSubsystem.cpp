#include "PneumaticSubsystem.h"
#include "../Robotmap.h"

PneumaticSubsystem::PneumaticSubsystem(): 
	SubsystemWithCommand<void>("PneumaticSubsystem"),
	m_Compressor(kCompressorSwitch, kCompressorRelay),
    m_ShooterCyls(kShooterRelay),
    m_PickupCyls(kPickupRelay)
{	
	m_Compressor.Start();
    m_ShooterCyls.Set(Relay::kReverse);
}

void PneumaticSubsystem::SetShooter(bool extend) {
    if(extend) {
        m_ShooterCyls.Set(Relay::kForward);
    } else {
        m_ShooterCyls.Set(Relay::kReverse);
    }
}

void PneumaticSubsystem::SetPickup(bool extend) {
	if(extend) {
		m_ShooterCyls.Set(Relay::kForward);
	} else {
		m_ShooterCyls.Set(Relay::kReverse);
	}
}
