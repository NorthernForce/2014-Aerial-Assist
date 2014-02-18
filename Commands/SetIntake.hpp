#pragma once
#include "../Subsystems/PickupSubsystem.h"
#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
template<Position pos>
class SetIntake: public Command {
public:
	virtual void Initialize() {
		printf("Setting Intake to %d", pos);
		Main::getPickup().SetIntakePosition(pos);
		Main::getPickup().SetIntakeSpeed( (pos==EXTEND) ? 1.0 : 0.0 );
	}
	
	virtual void Execute() {}
	virtual bool IsFinished() { return true; }
	virtual void End() {}
	virtual void Interrupted() {}
};
