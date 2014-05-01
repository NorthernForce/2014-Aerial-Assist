#pragma once
#include "WPILib.h"

class DriveFor : public Command {
private:
	double speed;
	double time;
public:
	DriveFor(double speed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
