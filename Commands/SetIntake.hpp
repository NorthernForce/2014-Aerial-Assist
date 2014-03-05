#pragma once
#include "../Main.h"
#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
enum IntakeMode {
	EXTENDED  = 1,
	RETRACTED = 2,
	
	STOPPED   = 1<<2,
	FORWARD   = 2<<2,
	REVERSE   = 3<<2,
	
};

template<int mode>
class SetIntake: public Command {
public:
	SetIntake() { Requires(&Main::getPickup()); }
	virtual void Initialize() {}
	virtual void Execute() {
		switch(mode & 3) {
		case EXTENDED:
			Main::getPickup().SetIntakePosition(EXTEND);
			break;
		case RETRACTED:
			Main::getPickup().SetIntakePosition(RETRACT);
			break;
		default:
			break;
		}
		
		switch(mode & 7<<2) {
		case STOPPED:
			Main::getPickup().SetIntakeSpeed(0.0);
			break;
		case FORWARD:
			Main::getPickup().SetIntakeSpeed(1.0);
			break;
		case REVERSE:
			Main::getPickup().SetIntakeSpeed(-1.0);
			break;
		default:
			break;
		}
	}
	virtual bool IsFinished() { return false; }
	virtual void End() {}
	virtual void Interrupted() {}
};
