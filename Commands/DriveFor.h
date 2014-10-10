#pragma once
#include "WPILib.h"

class DriveFor : public Command {
private:
	double m_speed;
	double m_time;
public:
	DriveFor(double speed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
