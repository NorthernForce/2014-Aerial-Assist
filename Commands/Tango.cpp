#include "tango.h"
#include "../Main.h"
#include <algorithm>

Tango::Tango()
{
	Requires(&Main::getPickup());
    Requires(&Main::getDrive());
    Requires(&Main::getPneumatics());
}

void Tango::Initialize() 
{
	Main::getDrive().SetDriveMode(MecanumDrive::SPEED);	
}

void Tango::Execute() 
{
/*	double t = TimeSinceInitialized(); //t is in seconds
	
	if(t < 5)
	{
		Main::getPickup().SetIntakePosition(EXTEND);
	};
*/

	
	std::for_each();
}

bool Tango::IsFinished() 
{
	return TimeSinceInitialized() > time;
}

void Tango::End() 
{
	
}

void Tango::Interrupted() 
{
	End();
}
