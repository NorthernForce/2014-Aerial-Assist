#include "CommandBase.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
// This is what actually creates the storage for the subsystem pointers.
DriveSubsystem* CommandBase::s_drive = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	s_drive = new DriveSubsystem();
	
    // Make sure that OI is initalized last, because it relys on
    // creating commands that require subsystems, so if the subsystems
    // are not yet initialized there can be problems. We ran into this
    // last year.
	oi = new OI();
}
