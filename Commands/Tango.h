#pragma once

#include "Commands/Command.h"
#include "../Dance/ADanceMove.h"
#include <vector>

/**
 *
 *
 * @author ExampleAuthor
 */
class Tango: public Command 
{
	public:
		Tango();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();

	private:
		std::vector<ADanceMove> m_tangoMoves;
};
