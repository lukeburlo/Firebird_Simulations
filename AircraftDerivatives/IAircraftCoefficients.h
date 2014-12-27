/*********************************************************************************************************************/
//
//  IAircraftCoefficients.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IAircraftCoefficients_h_  
#define _IAircraftCoefficients_h_    

namespace AircraftSimulation
{
	class IAircraftCoefficients
	{
		public:
			virtual float GetTailEfficency() = 0;
			virtual double GetC_D_M() = 0;
			virtual double GetC_D_0() = 0;
			virtual double GetC_T_U() = 0;
			virtual double GetC_L_0() = 0;
			virtual double GetdC_m_dM() = 0;
			virtual double GetC_L_alpha_tail() = 0;
	};
}

#endif