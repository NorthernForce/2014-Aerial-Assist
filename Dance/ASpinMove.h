#pragma once

#include "AStepMove.h"


class ASpinMove: public AStepMove
{
	public:
	    ASpinMove(float duration) : AStepMove(0,0,1,duration) {}
		virtual ~ASpinMove() {}
		
	public: 
		virtual void Execute() const
		{	
			// Use the x, y, w set in the constructor for spinning
			AStepMove::Execute();
		}
		
	protected:
		int revoultions;
};
