
/*********************************************************************************************************************/
//
//  Aircraft747100Data.h
//  Class Description: This class defines the data stability & control derviatives for the ZBoeing 747-100 aircraft
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftNavionData_h_  
#define _AircraftNavionData_h_    

#include "IAircraft.h"

namespace AircraftSimulation
{
	//change to data repository
	class AircraftNavionData : public IAircraft
	{
		public:
			AircraftNavionData() : IAircraft(){}
			virtual ~AircraftNavionData(){}

			int GetWeight() { return 2750; }

			double GetI_x() { return 1048; }
			double GetI_y() { return 3000; } 
			double GetI_z() { return 3550; } 
			double GetI_zx() { return 0; } 

			double GetX_u() { return -0.045; } 
			double GetX_w() { return 0.036; } 

			double GetZ_u()  { return -0.369; } 
			double GetZ_w()  { return -2.02; } 
			double GetZ_dw() { return 0; } 
			double GetZ_q() { return 0; } 

			double GetM_u() { return 0; } 
			double GetM_w() { return -0.05; } 
			double GetM_dw() { return -0.0051; }
			double GetM_q() { return -2.05; } 

			double GetY_v() { return -0.254; }
			double GetY_p() { return 0; } 
			double GetY_r() { return 0; } 

			double GetL_v() { return -0.091; } 
			double GetL_p() { return -8.4; } 
			double GetL_r() { return 2.19; }

			double GetN_v() { return 0.025; } 
			double GetN_p() { return -0.35; } 
			double GetN_r() { return -0.76; } 

			//Control Derivatives
			double GetX_elevator() { return 0; } 
			double GetZ_elevator() { return 0; } 
			double GetM_elevator() { return 0; }  

			double GetY_rudder() { return 0; } 
			double GetL_rudder() { return 0; }
			double GetN_rudder() { return 0; } 

			double GetY_alerion() { return 0; } 
			double GetL_alerion() { return 0; } 
			double GetN_alerion() { return 0; } 
	
			double GetX_throttle() { return 0; } 
			double GetZ_throttle() { return 0; } 
			double GetM_throttle() { return 0; } 

	};
}

#endif