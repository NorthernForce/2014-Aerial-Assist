#include "OI.h"
#include "Commands/Shoot.h"

OI::OI() : m_DriverStick(kDriverStickPort) {
}

void OI::init() {
	// Process operator interface input here.
    m_DriverStick.A.WhenPressed(new Shoot);
}

FRCXboxJoystick& OI::GetDriverStick() {
    return m_DriverStick;
}
