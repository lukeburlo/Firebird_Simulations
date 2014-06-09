/*********************************************************************************************************************/
//
//  IEoM.h
//  Class Description: This interface is used to define the equations of motion of a body.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IEoM_h_  
#define _IEoM_h_    

#include <vector>
#include "IAircraft.h"
#include <vector>


using namespace std;

namespace Simulation
{
	class IEoM
	{
		public:
			virtual void CalculateRates(vector<double>& state, vector<double>& stateRates, 
				vector<double>& inputValues) = 0;
	};
}

#endif