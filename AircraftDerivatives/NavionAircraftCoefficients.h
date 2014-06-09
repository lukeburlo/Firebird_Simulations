/*********************************************************************************************************************/
//
//  NavionAircraftCoefficients.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _NavionAircraftCoefficients_h_  
#define _NavionAircraftCoefficients_h_    

namespace AircraftSimulation
{
	class NavionAircraftCoefficients : IAircraftCoefficients
	{
		public:
			int GetC_D_U() { return 0; } 
			int GetC_D_0() { return 0.05; } 
			int GetC_T_U() { return 0; } 
	};
}

#endif