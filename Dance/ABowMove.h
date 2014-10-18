#pragma once

#include "ADanceMove.h"


class ABowMove: public ADanceMove
{
	public:
		ABowMove(int waitBeats) :
			ADanceMove(waitBeats){}
		virtual ~ABowMove() {}
		
		virtual void Execute() const
		{
			Main::getPickup().SetIntakePosition(EXTEND);
			
			Main::getPickup().SetIntakePosition(RETRACT);
		}
};
