#include "PneumaticSubsystem.h"
#include "../Robotmap.h"

PneumaticSubsystem::PneumaticSubsystem() try : 
	SubsystemWithCommand<void>("PneumaticSubsystem")
{	
}
catch(...)
{
	std::cout << "Exception thrown from constructor." << std::endl;
	throw;
}
