/*********************************************************************************************************************/
//
//  SpringDamperNonLinearEoM.h
//  Class Description: This class defines the non-linear equations of motion for a spring and damper system
//					   The equations of motion states vector is represented in the following way:
//                             X[0]  position of mass
//                             X[1]  velocity of mass
//                     The equations of motion input vector is represented in the following way:
//                             I[0] External Force
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include "SpringDamperNonLinearEoM.h"


namespace Simulation
{
	SpringDamperNonLinearEoM::SpringDamperNonLinearEoM( SpringDamperNonLinearEoM& other ){ }
	
	SpringDamperNonLinearEoM::SpringDamperNonLinearEoM(ISpringDamperDataRepository* pDataModel) : IEoM(),
	_pDataModel(pDataModel){}

	SpringDamperNonLinearEoM::~SpringDamperNonLinearEoM(){}

	void SpringDamperNonLinearEoM::CalculateRates(vector<double>& states,
		vector<double>& stateRates, vector<double>& inputValues)
	{
		stateRates[0] = states[1];	
		stateRates[1] = (-_pDataModel->GetSpringConstant()/_pDataModel->GetMass())*states[0] + 
			(-_pDataModel->GetDamperConstant()/_pDataModel->GetMass())*states[1] + 
			(inputValues[0]/_pDataModel->GetMass());
	}
}