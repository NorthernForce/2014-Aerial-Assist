#pragma once

#include "../Main.h"
#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
static const bool ON = true;
static const bool OFF = false;

template<bool Enable>
class SetEncoders: public Command {
public:
	SetEncoders() {}
	
	virtual void Initialize() {
		if(Enable) {
			Main::getDrive().EnableEncoders();
		} else {
			Main::getDrive().DisableEncoders();
		}
	}
	
	virtual void Execute() {}
	virtual bool IsFinished() { return true; }
	virtual void End() {}
	virtual void Interrupted() {}
};
