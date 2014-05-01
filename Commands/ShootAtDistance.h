#pragma once

#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ShootAtDistance: public Command {
private:
	double startTime;
	bool ready;
public:
	ShootAtDistance();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
