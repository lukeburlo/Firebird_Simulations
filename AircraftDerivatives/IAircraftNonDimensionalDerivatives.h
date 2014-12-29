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
			/*longitudinal Derivatives*/
			virtual double GetCX_u() = 0; 
			virtual double GetCZ_u() = 0;
			virtual double GetCm_u() = 0;
			virtual double GetCX_q() = 0;
			virtual double GetCZ_q() = 0;
			virtual double GetCm_q() = 0;
			virtual double GetCX_alpha_dot() = 0;
			virtual double GetCZ_alpha_dot() = 0;
			virtual double GetCm_alpha_dot() = 0;

	};
}

#endif