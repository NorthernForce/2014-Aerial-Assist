#include "DriveTo.h"
#include "../Main.h"
#include <algorithm>
#include <cmath>

DriveTo::DriveTo(double x0, double xf, double max_v, double max_a, bool initEncoders) : 
	x0(x0), xf(xf), max_v(max_v), max_a(max_a), initEncoders(initEncoders)
{
    Requires(&Main::getDrive());
    Requires(&Main::getPneumatics());
    Requires(&Main::getPickup());
}

DriveTo::DriveTo(DriveTo* first, double xf, double max_v, double max_a) : 
	x0(first->xf), xf(xf), max_v(max_v), max_a(max_a), initEncoders(false)
{
	Requires(&Main::getDrive());
}

void DriveTo::Initialize() {
	max_v = fabs(max_v);
	max_a = fabs(max_a);
	
	if(xf-x0 < 0) {
		max_v = -max_v;
		max_a = -max_a;
	}
	
	t1 = std::min(sqrt((xf-x0)/max_a),  max_v  / max_a );
	t2 = std::max(       t1,           (xf-x0) / max_v );
	t3 = t1 + t2;
	
	x1 = x0 + 0.5*max_a*t1*t1;
	//Main::getDrive().EnableEncoders(CANJaguar::kPosition, kRevsPerFoot*xf);
	if(initEncoders) {
		Main::getDrive().SetDriveMode(MecanumDrive::POSITION);
	}
}

void DriveTo::Execute() {
	double t = TimeSinceInitialized();
	/*
	if(t >= 5.0){
		t = (t_max - (t-5)) < 0 ? 0.0 : (t_max - (t-5))/t_max;
	} else {
		t = t > t_max ? 1.0 : t/t_max;
	}
	*/
	double x = 0;
	
	if(t < t1) {
		x = x0 + 0.5*max_a*t*t;
	} else if(t < t2) {
		x = x1 + max_v*(t-t1);
	} else if(t < t3) {
		x = xf - 0.5*max_a*(t3 - t)*(t3 - t);
	} else {
		x = xf;
	}
	
	//Main::getDrive().DriveMecanum(0, -c/xf, 0);
	Main::getDrive().Drive(0, x, 0);
}

bool DriveTo::IsFinished() {
	return TimeSinceInitialized() > 10.0;
	//return TimeSinceInitialized() > (t_max+1.0);
}

void DriveTo::End() {
	//Main::getDrive().EnableEncoders();
	Main::getDrive().SetDriveMode(MecanumDrive::SPEED);
}

void DriveTo::Interrupted() {
	End();
}
