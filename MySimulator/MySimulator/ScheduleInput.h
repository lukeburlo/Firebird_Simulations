/*********************************************************************************************************************/
//
//  ScheduleInput.h
//  Class Description:  
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _ScheduleInput_h_  
#define _ScheduleInput_h_  

#include <vector>
#include <vector>

using namespace std;

namespace Simulation
{
	class ScheduleInput
	{
		public:
			ScheduleInput(){ }
			ScheduleInput(double time, vector<double> inputs):
				TimeInterval(time), Inputs(inputs){ }
			double TimeInterval;
			vector<double> Inputs;
	};
}

#endif
