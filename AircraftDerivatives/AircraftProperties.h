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

			float GetTailMomentArm(){ return 46.0; }
			float GetTailSurfaceArea(){ return 233.0; } 
			float GetWingSurfaceArea(){ return 945.0; }
			float GetWingChord(){ return 10.1; }
			float GetWingAspectRatio() { return 9.75; }
			float GetSpanEfficiencyFactor() { return 0.75; }
			float GetCentreOfGravityFromWingLeadingEdge() { return 0.4; }
			float GetAerodynamicCentreFromWingLeadingEdge() { return 0.25; }

	};
}

#endif