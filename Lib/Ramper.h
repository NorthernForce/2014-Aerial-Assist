#pragma once

#include "../Robotmap.h"

class Ramper {
private:
	// Intermediate times
	double t1;
	double t2;
	// End time
	double t3;
	// Start position
	double x0;
	// Intermediate position,
	// corresponding to t1
	double x1;
	// End position
	double xf;
	// Maximum velocity
	double max_v;
	// Maximum acceleration
	double max_a;
public:
	Ramper(double x0, double xf, double max_v = kMaxDriveRPM/(kRevsPerFoot*60), double max_a = 10/2);
	double getDuration();
	double getOutput(double t);
};
