#pragma once 
#include <WPILib.h>
#include "../Commands/PressureReadout.h"
#include "SubsystemWithCommand.hpp"

class PressureSensor : public SubsystemWithCommand<PressureReadout> {
public:
	PressureSensor(int channel);
		
	int getPSI();
	
private:
	const float PSIvolt;
	const float OffsetVoltage;
	AnalogChannel m_PressureChannel;

};
