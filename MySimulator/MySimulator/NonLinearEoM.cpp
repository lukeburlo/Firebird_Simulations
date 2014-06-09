/*********************************************************************************************************************/
//
//  NonLinearEoM.cpp
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
//                             X[8]  Shi
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

#define GRAVITY 32.2
#define PI_OVER_180 0.0174532925
 
#include <math.h>
#include "NonLinearEoM.h"

using namespace Simulation;

namespace AircraftSimulation
{
	NonLinearEoM::NonLinearEoM(IAircraft* aircraft, double intialSpeed) : 
		_pAircraft(aircraft), _intialSpeed(intialSpeed), IEoM()
	{
	}

	NonLinearEoM::~NonLinearEoM()
	{

	}

	void NonLinearEoM::CalculateRates(vector<double>& states, vector<double>& stateRates,
		vector<double>& inputValues)
	{
		double dElevator = inputValues[0]*PI_OVER_180;    //Elevator
		double dThr = inputValues[1]*PI_OVER_180;         //Throttle
		double dAlerion = inputValues[2] * PI_OVER_180;   //Alerion
		double dRudder = inputValues[3] * PI_OVER_180;    //Rudder

		double mass = _pAircraft->GetWeight()/GRAVITY;

		stateRates[0] = ((_pAircraft->GetX_u()/mass)*states[0])+((_pAircraft->GetX_w()/mass)*states[1])+(-GRAVITY*(sin(states[3])))+
			((_pAircraft->GetX_elevator()/mass)*dElevator)+((_pAircraft->GetX_throttle()/mass)*dThr);

		stateRates[1] = ((_pAircraft->GetZ_u()/(mass-_pAircraft->GetZ_dw()))*states[0])+((_pAircraft->GetZ_w()/(mass-_pAircraft->GetZ_dw()))*states[1])+
			(((_pAircraft->GetZ_q()+(mass*_intialSpeed))/(mass-_pAircraft->GetZ_dw()))*states[2])-
			(((mass*GRAVITY)/(mass-_pAircraft->GetZ_dw()))*(1-(cos(states[3])*cos(states[7]))))+
			((_pAircraft->GetZ_elevator()/mass)*dElevator)+((_pAircraft->GetZ_throttle()/mass)*dThr);

		stateRates[2] = ((_pAircraft->GetM_u()/_pAircraft->GetI_y())*states[0])+((_pAircraft->GetM_w()/_pAircraft->GetI_y())*states[1])+
			((_pAircraft->GetM_dw()/_pAircraft->GetI_y())*stateRates[1])+((_pAircraft->GetM_q()/_pAircraft->GetI_y())*states[2])+
			((_pAircraft->GetM_elevator()/_pAircraft->GetI_y())*dElevator)+((_pAircraft->GetM_throttle()/_pAircraft->GetI_y())*dThr);
	
		stateRates[3] = (states[2]*cos(states[7]))-(states[6]*sin(states[7]));

		stateRates[4] = ((_pAircraft->GetY_v()/mass)*states[4])+((_pAircraft->GetY_p()/mass)*states[5])+
			(((_pAircraft->GetY_r()/mass)-_intialSpeed)*states[6])+(GRAVITY*(cos(states[3])*sin(states[7])))+
			((_pAircraft->GetY_rudder()/mass)*dRudder)+((_pAircraft->GetY_alerion()/mass)*dAlerion);

		double Idashx = ((_pAircraft->GetI_x()*_pAircraft->GetI_z())-(pow(_pAircraft->GetI_zx(),2)))/_pAircraft->GetI_z();
		double Idashzx = _pAircraft->GetI_zx()/((_pAircraft->GetI_x()*_pAircraft->GetI_z())-(pow(_pAircraft->GetI_zx(),2)));
	
		stateRates[5] = (((_pAircraft->GetL_v()/Idashx)+(_pAircraft->GetN_v()*Idashzx))*states[4])+(((_pAircraft->GetL_p()/Idashx)+(_pAircraft->GetN_p()*Idashzx))*states[5])+
			(((_pAircraft->GetL_r()/Idashx)+(_pAircraft->GetN_r()*Idashzx))*states[6])+
			((_pAircraft->GetL_rudder()*dRudder)+(_pAircraft->GetL_alerion()*dAlerion))/Idashx +
			((_pAircraft->GetN_rudder()*dRudder)+(_pAircraft->GetN_alerion()*dAlerion))*Idashzx;

		double Idashz = ((_pAircraft->GetI_x()*_pAircraft->GetI_z())-(pow(_pAircraft->GetI_zx(),2)))/_pAircraft->GetI_x();
	
		stateRates[6] = (((_pAircraft->GetN_v()/Idashz)+(_pAircraft->GetL_v()*Idashzx))*states[4])+(((_pAircraft->GetN_p()/Idashz)+(_pAircraft->GetL_p()*Idashzx))*states[5])+
			(((_pAircraft->GetN_r()/Idashz)+(_pAircraft->GetL_r()*Idashzx))*states[6])+
			(((_pAircraft->GetN_rudder()*dRudder)+(_pAircraft->GetN_alerion()*dAlerion))/Idashz) +
			(((_pAircraft->GetL_rudder()*dRudder)+(_pAircraft->GetL_alerion()*dAlerion))*Idashzx);
		
		stateRates[7] = states[5]+((states[2]*sin(states[7]))+(states[6]*cos(states[7])))*tan(states[3]);

		stateRates[8] = ((states[2]*sin(states[7]))+(states[6]*cos(states[7])))*(1/(cos(states[3])));

		double u = _intialSpeed + states[0];
		stateRates[9] = ((cos(states[7])*cos(states[8]))*u) + (((sin(states[7])*sin(states[3])*cos(states[8]))-(cos(states[7])*sin(states[8])))*states[4]) + (((cos(states[7])*sin(states[3])*cos(states[8]))+(sin(states[7])*sin(states[8])))*states[1]);
		stateRates[10] = ((cos(states[3])*sin(states[7]))*u) +(((sin(states[8])*sin(states[3])*sin(states[8])) + (cos(states[7])*cos(states[8]))) * states[4]) + (((cos(states[7])*sin(states[3])*sin(states[8])) - (sin(states[7])*cos(states[8]))) * states[1]);
		stateRates[11] = -(sin(states[3])) + (sin(states[3])*cos(states[3])) + (cos(states[7])*cos(states[3]));
	}

}