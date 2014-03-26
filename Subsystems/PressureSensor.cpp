#include "PressureSensor.h"

PressureSensor::PressureSensor(int channel): 
	SubsystemWithCommand<void>("PressureSensor"),
	PSIvolt (22.65),
	OffsetVoltage (0.2),
	m_PressureChannel(channel)
{	
}
	
	
int PressureSensor::getPSI()
{
	return static_cast<int>((m_PressureChannel.GetVoltage() - OffsetVoltage) * PSIvolt);
}
