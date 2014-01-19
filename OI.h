#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Lib/FRCXboxJoystick.h"

class OI {
private:
    FRCXboxJoystick m_DriverStick;
public:
	OI();
    FRCXboxJoystick& GetDriverStick();
};

#endif
