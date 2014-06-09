/*********************************************************************************************************************/
//
//  AircraftDerivatives.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftDerivatives_h_  
#define _AircraftDerivatives_h_    

#include "IAircraft.h"

namespace AircraftSimulation
{
	class AircraftDerivatives : IAircraft
	{
		public:
			virtual int GetWeight();

			virtual double GetI_x() = 0; 
			virtual double GetI_y() = 0; 
			virtual double GetI_z() = 0; 
			virtual double GetI_zx() = 0; 

			virtual double GetX_u(); 
	};
}

#endif