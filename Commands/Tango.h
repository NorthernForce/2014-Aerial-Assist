#pragma once

#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Tango: public Command {
public:
	Tango();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
