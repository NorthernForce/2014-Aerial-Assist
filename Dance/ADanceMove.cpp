#include <ctime>
#include "ADanceMove.h"
#include "../Commands/Tango.h"

std::size_t AMoveRunner::s_executionCount = 0; 


AMoveRunner::AMoveRunner(Tango* instance) :
		m_tangoInstance(instance)
{
	
}
void AMoveRunner::operator()(const boost::shared_ptr<ADanceMove>& move) const
{
	clock_t initialValue = clock();
	//double initialValue = //Timer::GetFPGATimestamp();//m_tangoInstance->TimeSinceInitialized();
	int beatCount = 0;
	clock_t currentTime = 0;
	while (beatCount < move->GetWaitBeats())
	{
	    // Ensure that we are feeding the saftey timer...if not
		// the robot will stop...
		Main::getDrive().Feed();
		currentTime == clock() - initialValue; //Timer::GetFPGATimestamp() - initialValue; //m_tangoInstance->TimeSinceInitialized() - initialValue;
		if (currentTime >=240)
		{
			++beatCount;
			initialValue = currentTime;
			//std::cout << "beatCount is " << beatCount << std::endl;
		}
	}
	move->Execute();
	++AMoveRunner::s_executionCount;
}
