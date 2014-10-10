#pragma once

#include "ADanceMove.h"


class ABowMove: public ADanceMove
{
	public:
		ABowMove(float duration) :
			ADanceMove(duration){}
		virtual ~ABowMove() {}
		
		virtual void Execute() const
		{
			Main::getPickup().SetIntakePosition(EXTEND);
			float duration = m_duration;
			while (duration > 0 )
			{
				sleep(1);
				--duration;
			}
			Main::getPickup().SetIntakePosition(RETRACT);
		}
};
