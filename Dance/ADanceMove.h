#pragma once

#include "../main.h"
#include <functional>
#include <stddef.h>
#include "boost/shared_ptr.hpp"


class ADanceMove
{
	public:
		ADanceMove(int waitBeats) : m_waitBeats(waitBeats)
			{}
		int GetWaitBeats()
		{
			return m_waitBeats;
		}
		virtual void Execute() const = 0;
		virtual void Sync() 
		{
			// To be later implemented, most likely a socket interface. 
		}
		
	protected:
		int m_waitBeats;
};


class Tango;

struct AMoveRunner 
{
	AMoveRunner(Tango*);
	
	void operator()(const boost::shared_ptr<ADanceMove>& move) const;
	static std::size_t s_executionCount; 
	Tango* m_tangoInstance;
};

