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
	
	//First Bow
	m_tangoMoves.push_back(AMovePtr(new ABowMove(1.0))); 
	
	// First Block (up, right)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, 1.0)));
	
	// Second Block (up, left)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, .5, 1.0)));
	
	// Third Block (right, down)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, 1.0)));
	
	// Fourth Block (right, up)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, 1.0)));
	
	// Fifth Blcok (down, left)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, .5, 1.0)));
	
	// Sixth Block (down, right)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, .5, 1.0)));
	
	// Seventh Block (left, up)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, .5, 1.0)));
	
	// Eighth Block (left, down)
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 0.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(0.0, -1.0, .5, 1.0)));
	
	// Ninth Block (spin) 
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new ASpinMove(2.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 1.0, 1.0, 1.0)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(-1.0, 1.0, .5, .5)));
	m_tangoMoves.push_back(AMovePtr(new AStepMove(1.0, 1.0, .5, .5)));

	// Final Bow
	m_tangoMoves.push_back(AMovePtr(new ABowMove(1.0))); 
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
