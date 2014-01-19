#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveWithJoystick: public CommandBase {
public:
	DriveWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
