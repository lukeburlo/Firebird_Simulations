/*********************************************************************************************************************/
//
//  NonLinearEoM.h
//  Class Description: This class defines the non-linear equations of motion for transport and gerneral aviation
//                     aircraft, which are not subjected to violent maneuvers.
//					   The equations of motion states vector is represented in the following way:
//                             X[0]  delta u
//                             X[1]  w
//                             X[2]  q
//                             X[3]  delta theta
//                             X[4]  v
//                             X[5]  p
//                             X[6]  r
//                             X[7]  Phi
//                             X[8]  Psi
//                             X[9]  x
//                             X[10] y
//                             X[11] z
//                     The equations of motion control vector is represented in the following way:
//                             C[0] Elevator
//                             C[1] Throttle
//                             C[2] Alerion
//                             C[3] Rundder
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _NonLinearEoM_h_  
#define _NonLinearEoM_h_

#include <vector>
#include "IEoM.h"
#include "IAircraft.h"
#include <vector>

using namespace Simulation;
using namespace std;

namespace AircraftSimulation
{
	class NonLinearEoM : public IEoM
	{
		private:
			NonLinearEoM( NonLinearEoM& other );
			IAircraft* _pAircraft;
			double _intialSpeed;

		public:
			NonLinearEoM(IAircraft* aircraft, double intialSpeed);
			virtual ~NonLinearEoM();
			void CalculateRates(vector<double>& states, vector<double>& stateRates,
				vector<double>& inputValues);
	};
}
#endif