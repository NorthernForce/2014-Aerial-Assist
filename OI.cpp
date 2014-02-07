#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/SetEncoders.hpp"

OI::OI() : m_DriverStick(kDriverStickPort) {
}

void OI::init() {
	// Process operator interface input here.
    m_DriverStick.A.WhenPressed<Shoot>();
    m_DriverStick.RightBumper.WhenPressed<SetEncoders<ON> >();
    m_DriverStick.LeftBumper.WhenPressed<SetEncoders<OFF> >();
}

FRCXboxJoystick& OI::GetDriverStick() {
    return m_DriverStick;
}
