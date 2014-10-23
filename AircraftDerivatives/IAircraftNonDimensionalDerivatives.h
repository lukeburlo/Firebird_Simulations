/*********************************************************************************************************************/
//
//  IAircraftNonDimensionalDerivatives.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IAircraftNonDimensionalDerivatives_h_  
#define _IAircraftNonDimensionalDerivatives_h_    

#include "IAircraftCoefficients.h"

namespace AircraftSimulation
{
	class IAircraftNonDimensionalDerivatives 
	{
		public:
			virtual double GetCX_u() = 0; 
			virtual double GetCZ_u() = 0;
			virtual double GetCm_u() = 0;
	};
}

#endif