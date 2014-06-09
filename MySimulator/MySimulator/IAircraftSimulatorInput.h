/*********************************************************************************************************************/
//
//  IAircraftSimulatorInput.h
//  Class Description: TODO
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IAircraftSimulatorInput_h_  
#define _IAircraftSimulatorInput_h_    

#include <vector>
#include <vector>
#include "ScheduleInput.h"
#include "AircraftConstants.h"

using namespace Simulation;

namespace AircraftSimulation
{
	class IAircraftSimulatorInput
	{
		public: 
			virtual vector<double> GetInitialStates()  = 0 ;
			virtual vector<ScheduleInput> GetExternalInputs()  = 0;
			virtual AircraftType GetAircraftType() = 0;
			virtual double GetAircraftIntialSpeed()  = 0;
	};
}

#endif