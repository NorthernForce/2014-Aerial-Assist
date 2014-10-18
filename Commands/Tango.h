#pragma once

#include "Commands/Command.h"
#include "../Dance/ADanceMove.h"
#include <vector>
#include "boost/shared_ptr.hpp"

/**
 *
 *
 * @author ExampleAuthor
 */
class Tango: public Command 
{
	typedef boost::shared_ptr<ADanceMove> AMovePtr;
	
	public:
		Tango();
		Tango(const Tango& other);
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
        
		
	private:
		std::vector<AMovePtr> m_tangoMoves;
};
