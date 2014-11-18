/*********************************************************************************************************************/
//
//  AircraftProperties.h
//  Class Description: Used as a store for aircraft properties
//
//  Created by Luke Burlovich on 14/10/2014
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftProperties_h_  
#define _AircraftProperties_h_

#include "IAircraftProperties.h"

namespace AircraftSimulation
{
	class AircraftProperties : public IAircraftProperties
	{
		public:
			AircraftProperties(){}
			~AircraftProperties(){}

			int TailMomentArm(){ return 0; } 

	};
}

#endif