#include "Dance/ADanceMove.h"


class ABowMove: ADanceMove
{
	public:
		void ABowMove(float duration) :
			m_duration(duration){}
		
		virtual void Execute()
		{
			Main::getPickup().SetIntakePosition(EXTEND);
			while (m_duration > 0 )
			{
				sleep(1);
				--m_duration;
			}
			Main::getPickup().SetIntakePostion(RETRACT);
		}
			
};
