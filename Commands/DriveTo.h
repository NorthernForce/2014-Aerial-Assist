#pragma once

#include "Commands/Command.h"
#include "../Robotmap.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTo: public Command {
private:
	double t1;
	double t2;
	double t3;
	double x0;
	double x1;
	double xf;
	double max_v;
	double max_a;
	bool initEncoders;
public:
	DriveTo(double x0, double xf, double max_v = kMaxDriveRPM/(kRevsPerFoot*60)/1.5, double max_a = 10/1.5, bool initEncoders = true);
	DriveTo(DriveTo* first, double xf, double max_v = kMaxDriveRPM*kRevsPerFoot/60, double max_a = 10.0);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
