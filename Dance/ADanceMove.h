#include "../main.h"

class ADanceMove
{
	public:
		virtual void Execute() = 0;
		virtual void Sync() 
		{
			// To be later implemented, most likely a socket interface. 
		}
		
	protected:
		float m_duration; 
};


struct AMoveRunner
{
	void operator()(const ADanceMove& move) const
	{
		move.Execute();
	}
};



