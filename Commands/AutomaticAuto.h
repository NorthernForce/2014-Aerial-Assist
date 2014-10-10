#pragma once
#include "Commands/CommandGroup.h"
#include "ShootAtDistance.h"
#include "DriveFor.h"

class AutomaticAuto : public CommandGroup {
public:
	AutomaticAuto() {
		AddParallel(new ShootAtDistance());
		AddParallel(new DriveFor(0.7, 2.5));
	}
};
