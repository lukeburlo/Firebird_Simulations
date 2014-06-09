
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

#ifndef _Aircraft747100Data_h_  
#define _Aircraft747100Data_h_    

#include "IAircraft.h"

namespace AircraftSimulation
{
	//change to data repository
	class Aircraft747100Data : public IAircraft
	{
		public:
			Aircraft747100Data() : IAircraft(){}
			virtual ~Aircraft747100Data(){}

			int GetWeight() { return 636636; }

			double GetI_x() { return 0.183e8; }
			double GetI_y() { return 0.331e8; } 
			double GetI_z() { return 0.497e8; } 
			double GetI_zx() { return -0.156e7; } 

			double GetX_u() { return -1.358e2; } 
			double GetX_w() { return 2.758e2; } 

			double GetZ_u()  { return -1.778e3; } 
			double GetZ_w()  { return -6.188e3; } 
			double GetZ_dw() { return 1.308e2; } 
			double GetZ_q() { return -1.017e5; } 

			double GetM_u() { return 3.581e3; } 
			double GetM_w() { return -3.515e4; } 
			double GetM_dw() { return -3.826e3; }
			double GetM_q() { return -1.122e7; } 

			double GetY_v() { return -1.103e3; }
			double GetY_p() { return 0; } 
			double GetY_r() { return 0; } 

			double GetL_v() { return -6.885e4; } 
			double GetL_p() { return -7.934e6; } 
			double GetL_r() { return 7.321e6; }

			double GetN_v() { return 4.790e4; } 
			double GetN_p() { return -9.809e5; } 
			double GetN_r() { return -6.590e6; } 

			//Control Derivatives
			double GetX_elevator() { return -3.717; } 
			double GetZ_elevator() { return -3.551e5; } 
			double GetM_elevator() { return -3.839e7; } 

			double GetY_rudder() { return 0.1146; } 
			double GetL_rudder() { return 1329002.82; }
			double GetN_rudder() { return -23930987.53; } 

			double GetY_alerion() { return 0; } 
			double GetL_alerion() { return -2606186.72; } 
			double GetN_alerion() { return -37587.77; } 
	
			double GetX_throttle() { return 9.66*(636636/32.2); } 
			double GetZ_throttle() { return 0; } 
			double GetM_throttle() { return 0; } 

	};
}

#endif