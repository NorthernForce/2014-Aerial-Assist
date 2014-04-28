#pragma once

#include "Commands/Command.h"
#include "../Lib/Ramper.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Auto1: public Command {
private:
	Ramper r;
public:
	Auto1();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
