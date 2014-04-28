#include "Ramper.h"
#include "Commands/Command.h"
#include <algorithm>
#include <cmath>

Ramper::Ramper(double x0, double xf, double max_v, double max_a) : 
	x0(x0), xf(xf), max_v(fabs(max_v)), max_a(fabs(max_a)) 
{
	if(xf-x0 < 0) {
		this->max_v = -this->max_v;
		this->max_a = -this->max_a;
	}
		
	t1 = std::min(sqrt((xf-x0)/this->max_a),  this->max_v  / this->max_a );
	t2 = std::max(       t1,           (xf-x0) / this->max_v );
	t3 = t1 + t2;
		
	x1 = x0 + 0.5*this->max_a*(t1)*(t1);
	
	printf("t1:%f, t2:%f, t3:%f x0:%f, x1:%f, xf:%f max_v:%f, max_a:%f\n", t1, t2, t3, x0, x1, xf, this->max_v, this->max_a);
}

double Ramper::getDuration() {
	return t3;
}

double Ramper::getOutput(double t) {
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
	
	return x;
}
