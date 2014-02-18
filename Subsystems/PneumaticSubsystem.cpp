#include "PneumaticSubsystem.h"
#include "../Robotmap.h"

PneumaticSubsystem::PneumaticSubsystem(): 
	SubsystemWithCommand<void>("PneumaticSubsystem"),
	m_Compressor(kCompressorSwitchModule, kCompressorSwitch, kCompressorModule, kCompressorRelay),
    m_ShooterCyls(kShooterModule, kShooterRelay, Relay::kBothDirections)
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
