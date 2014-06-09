/*********************************************************************************************************************/
//
//  IAircraft.h
//  Class Description: This interface is used to define the data (stability & control derviatives) for different types
//                     of aircraft, enabling access from different types of repositories.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IAircraft_h_  
#define _IAircraft_h_    

namespace AircraftSimulation
{
	class IAircraft
	{
		public:
			virtual int GetWeight() = 0; //lb

			//Dimensional stability derviatives
			virtual double GetI_x() = 0; 
			virtual double GetI_y() = 0; 
			virtual double GetI_z() = 0; 
			virtual double GetI_zx() = 0; 

			virtual double GetX_u() = 0; 
			virtual double GetX_w() = 0; 

			virtual double GetZ_u() = 0; 
			virtual double GetZ_w() = 0; 
			virtual double GetZ_dw() = 0; 
			virtual double GetZ_q() = 0; 

			virtual double GetM_u() = 0; 
			virtual double GetM_w() = 0; 
			virtual double GetM_dw() = 0; 
			virtual double GetM_q() = 0; 

			virtual double GetY_v() = 0; 
			virtual double GetY_p() = 0; 
			virtual double GetY_r() = 0; 

			virtual double GetL_v() = 0;
			virtual double GetL_p() = 0;
			virtual double GetL_r() = 0; 

			virtual double GetN_v() = 0; 
			virtual double GetN_p() = 0; 
			virtual double GetN_r() = 0; 

			//Dimensional control derviatives
			virtual double GetX_elevator() = 0;
			virtual double GetZ_elevator() = 0; 
			virtual double GetM_elevator() = 0;

			virtual double GetY_rudder() = 0;
			virtual double GetL_rudder() = 0;
			virtual double GetN_rudder() = 0;

			virtual double GetY_alerion() = 0;
			virtual double GetL_alerion() = 0;
			virtual double GetN_alerion() = 0;

			virtual double GetX_throttle() = 0; 
			virtual double GetZ_throttle() = 0; 
			virtual double GetM_throttle() = 0; 


	};
}

#endif