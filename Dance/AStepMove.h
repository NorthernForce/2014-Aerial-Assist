#include "Dance/ADanceMove.h"


class AStepMove: ADanceMove
{
	public: 
		void AStepMove(double x, double y, double w, float duration) : 
			m_x(x), m_y(y), m_w(w), m_duration(duration) {}
		
		virtual void Execute()
		{
			Main::getDrive().DriveMecanum(m_x, m_y, m_w);
		}
	
	protected:
		double m_x; 
		double m_y;
		double m_w; 
};
