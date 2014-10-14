#pragma once

#include "../main.h"
#include <functional>
#include <stddef.h>
#include "boost/shared_ptr.hpp"

class ADanceMove
{
	public:
		ADanceMove(float duration) : m_duration(duration) {}
		virtual void Execute() const = 0;
		virtual void Sync() 
		{
			// To be later implemented, most likely a socket interface. 
		}
		
	protected:
		float m_duration; 
};


struct AMoveRunner
{
	void operator()(const boost::shared_ptr<ADanceMove>& move) const
	{
		move->Execute();
		++AMoveRunner::s_executionCount;
	}
	static std::size_t s_executionCount; 
};

