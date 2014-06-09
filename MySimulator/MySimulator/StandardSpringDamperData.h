/*********************************************************************************************************************/
//
//  StandardSpringDamperData.h
//  Class Description: This class  is used to define the spring damper data (i.e. constants) for  a standard response,
//  enabling access from different types of repositories.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _StandardSpringDamperData_h_  
#define _StandardSpringDamperData_h_    

#include "ISpringDamperDataRepository.h"

namespace Simulation
{
	class StandardSpringDamperData : public ISpringDamperDataRepository
	{
		public:
			int GetMass() { return 4;}
			int GetSpringConstant() { return 12; } 
			int GetDamperConstant() { return 6; }
	};
}

#endif