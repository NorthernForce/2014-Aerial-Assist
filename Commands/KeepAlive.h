#pragma once

#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class KeepAlive: public Command {
private:
	int n;
public:
	KeepAlive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
