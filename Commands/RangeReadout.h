#pragma once

#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class RangeReadout: public Command {
public:
	RangeReadout();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
