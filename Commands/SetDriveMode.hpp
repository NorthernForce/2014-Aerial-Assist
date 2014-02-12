#pragma once

#include "Commands/Command.h"
#include "../Main.h"

enum DriveMode {
	MAJOR_AXIS_ONLY,
	BOTH_AXES,
	ENCODERS_ON,
	ENCODERS_OFF,
};

template<DriveMode mode>
class SetDriveMode: public Command {
public:
	SetDriveMode() {}
	virtual void Initialize() {
		switch(mode) {
		case MAJOR_AXIS_ONLY:
			Main::getDrive().SetMajorAxisMode(true);
			break;
		case BOTH_AXES:
			Main::getDrive().SetMajorAxisMode(false);
			break;
		case ENCODERS_ON:
			Main::getDrive().EnableEncoders(true);
			break;
		case ENCODERS_OFF:
			Main::getDrive().DisableEncoders();
			break;
		}
	}
	
	virtual void Execute() {}
	virtual bool IsFinished() { return true; }
	virtual void End() {}
	virtual void Interrupted() {}
};
