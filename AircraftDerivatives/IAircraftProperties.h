/*********************************************************************************************************************/
//
//  IAircraftProperties.h
//  Class Description: Used to define aircraft properties
//
//  Created by Luke Burlovich on 14/10/2014
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IAircraftProperties_h_  
#define _IAircraftProperties_h_

namespace AircraftSimulation
{
	class IAircraftProperties
	{
		public:
			virtual float GetTailMomentArm() = 0; 
			virtual float GetTailSurfaceArea() = 0; 
			virtual float GetWingSurfaceArea() = 0; 
			virtual float GetWingChord() = 0; 
			virtual float GetWingAspectRatio() = 0;
			virtual float GetSpanEfficiencyFactor() = 0;
			virtual float GetCentreOfGravityFromWingLeadingEdge() = 0;
			virtual float GetAerodynamicCentreFromWingLeadingEdge() = 0;
			virtual float GetElevatorFlapEffectivenessParameter() = 0;
	};
}

#endif