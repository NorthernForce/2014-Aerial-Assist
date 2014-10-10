#include "tango.h"
#include "../Main.h"

#include <algorithm>
#include <functional>
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
	// Initialize our move runner static count
	AMoveRunner::s_executionCount = 0;
	
	// Initialize the mechanum drive system
	Main::getDrive().SetDriveMode(MecanumDrive::SPEED);	
	
	// We initialize the dance steps here.
	// Note that though we are using new AMovePtr keeps
	// track of reference counts on the contained pointer and
	// when the reference count gets to zero delete is called on 
	// the contained pointer...we're almost C++ 11...
	m_tangoMoves.push_back(AMovePtr(new AStepMove(10, 1, 0, 3)));
}

void Tango::Execute() 
{
	// Iterate through our collection of tango moves and 
	// execute each move through our move runner.
	std::for_each(m_tangoMoves.begin(), 
			      m_tangoMoves.end(), 
			      AMoveRunner());
}

bool Tango::IsFinished() 
{
	return AMoveRunner::s_executionCount == m_tangoMoves.size();
}

void Tango::End() 
{	
}

void Tango::Interrupted() 
{
	End();
}
