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
	Ramper r1;
	Ramper r2;
	Ramper r3;
public:
	Auto1();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
