#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntake.hpp"

OI::OI() : m_DriverStick(kDriverStickPort) {
}

void OI::init() {
	// Process operator interface input here.
    m_DriverStick.A.WhenPressed<Shoot>();
    m_DriverStick.RightBumper.WhenPressed<SetDriveMode<ENCODERS_ON> >();
    m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<ENCODERS_OFF> >();
    m_DriverStick.X.WhenPressed<SetDriveMode<MAJOR_AXIS_ONLY> >();
    m_DriverStick.Y.WhenPressed<SetDriveMode<BOTH_AXES> >();
    m_DriverStick.B.WhenPressed<SetIntake<EXTEND> >();
    m_DriverStick.B.WhenReleased<SetIntake<RETRACT> >();
}

FRCXboxJoystick& OI::GetDriverStick() {
    return m_DriverStick;
}
