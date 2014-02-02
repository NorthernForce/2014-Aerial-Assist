#include "OI.h"

OI::OI() : m_DriverStick(kDriverStickPort) {
}

void OI::init() {
	// Process operator interface input here.
}

FRCXboxJoystick& OI::GetDriverStick() {
    return m_DriverStick;
}
