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
			virtual int GetC_D_U() = 0;
			virtual int GetC_D_0() = 0;
			virtual int GetC_T_U() = 0;
	};
}

#endif