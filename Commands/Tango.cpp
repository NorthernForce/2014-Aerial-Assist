#include "tango.h"
#include "../Main.h"

#include <algorithm>
#include "../Dance/ABowMove.h"
#include "../Dance/ASpinMove.h"
#include "../Dance/AStepMove.h"

Tango::Tango()
{
	Requires(&Main::getPickup());
    Requires(&Main::getDrive());
    Requires(&Main::getPneumatics());
}

void Tango::Initialize() 
{
	Main::getDrive().SetDriveMode(MecanumDrive::SPEED);	
	
	// We initialize the dance steps here
	m_tangoMoves.push_back(AStepMove(10, 1, 0, 3));
}

void Tango::Execute() 
{
/*	double t = TimeSinceInitialized(); //t is in seconds
	
	if(t < 5)
	{
		Main::getPickup().SetIntakePosition(EXTEND);
	};
*/

	
	std::for_each(m_tangoMoves.begin(), m_tangoMoves.end(), AMoveRunner());
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
