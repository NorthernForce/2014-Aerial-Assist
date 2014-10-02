#include "Dance/AStepMove.h"


class ASpinMove: public AStepMove
{
	public: 
		virtual void Execute()
		{	
			//set x, y, w to proper values for spinning
			AStepMove::Execute();
		}
		
	protected:
		int revoultions;
};
