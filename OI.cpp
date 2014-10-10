#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntake.hpp"
#include "Commands/FollowBall.h"
#include "Commands/ShootAtDistance.h"

OI::OI() : m_DriverStick(kDriverStickPort), m_ManipulatorStick(kManipulatorStickPort) {
}

void OI::init() {
	// Process operator interface input here.
    m_DriverStick.A.WhenPressed<Shoot>();
    m_DriverStick.RightBumper.WhenPressed<SetDriveMode<ENCODERS_ON> >();
    m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<ENCODERS_OFF> >();
    //m_DriverStick.X.WhenPressed<SetDriveMode<MAJOR_AXIS_ONLY> >();
    //m_DriverStick.Y.WhenPressed<SetDriveMode<BOTH_AXES> >();
    m_DriverStick.X.WhenPressed<SetDriveMode<SWAP_SIDES> >();
    m_DriverStick.B.WhileHeld<SetIntake<EXTENDED | FORWARD> >();
    m_DriverStick.Back.WhileHeld<SetIntake<REVERSE> >();
    m_DriverStick.Start.WhileHeld<FollowBall>();
    m_DriverStick.Y.WhenPressed<FollowBall>();
    
    m_ManipulatorStick.Trigger.WhenPressed<Shoot>();
    m_ManipulatorStick.Button2.WhileHeld<SetIntake<EXTENDED | FORWARD> >();
//    m_ManipulatorStick.Button2.WhenPressed<SetIntake<EXTENDED> >();
//    m_ManipulatorStick.Button2.WhenReleased<SetIntake<RETRACTED> >();
    m_ManipulatorStick.Button4.WhenPressed<SetIntake<EXTENDED | FORWARD> >();
    m_ManipulatorStick.Button5.WhenPressed<SetIntake<RETRACTED | STOPPED> >();
    m_ManipulatorStick.Button3.WhileHeld<SetIntake<REVERSE> >();
    m_ManipulatorStick.Button8.WhileHeld<ShootAtDistance>();
    m_ManipulatorStick.Button6.WhenPressed<SetIntake<STOPPED> >();
}

FRCXboxJoystick& OI::GetDriverStick() {
    return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick() {
	return m_ManipulatorStick;
}
