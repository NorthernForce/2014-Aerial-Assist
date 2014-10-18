#pragma once

#include "ADanceMove.h"


class AStepMove: public ADanceMove
{
	public: 
		AStepMove(double x, double y, double w, int waitBeats) : 
			ADanceMove(waitBeats), m_x(x), m_y(y), m_w(w) {}
		
		virtual ~AStepMove() {}
		
		virtual void Execute() const
		{
			Main::getDrive().Drive(m_x, m_y, m_w);
		}
	
	protected:
		double m_x; 
		double m_y;
		double m_w; 
};
