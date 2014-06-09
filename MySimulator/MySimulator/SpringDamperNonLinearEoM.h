/*********************************************************************************************************************/
//
//  SpringDamperNonLinearEoM.h
//  Class Description: This class defines the non-linear equations of motion for a spring and damper system
//					   The equations of motion states vector is represented in the following way:
//                             X[0]  position of mass
//                             X[1]  velocity of mass
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _SpringDamperNonLinearEoM_h_  
#define _SpringDamperNonLinearEoM_h_

#include "IEoM.h"
#include "ISpringDamperDataRepository.h"

namespace Simulation
{
	class SpringDamperNonLinearEoM : public IEoM
	{
		private:
			SpringDamperNonLinearEoM( SpringDamperNonLinearEoM& other );
			ISpringDamperDataRepository* _pDataModel;
	
		public:
			SpringDamperNonLinearEoM(ISpringDamperDataRepository* pDataModel);
			virtual ~SpringDamperNonLinearEoM();
			void CalculateRates(vector<double>& states,  vector<double>& stateRates, 
				vector<double>& inputValues);
	};
}
#endif
