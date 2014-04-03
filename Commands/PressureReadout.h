#pragma once

#include "Commands/Command.h"

class PressureReadout : public Command {
private:
	int n;
public:
	PressureReadout();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
