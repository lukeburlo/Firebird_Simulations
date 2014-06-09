/*********************************************************************************************************************/
//
//  ISpringDamperDataRepository.h
//  Class Description: This interface is used to define the data (i.e. constants) for different types
//                     of spring damper systems, enabling access from different types of repositories.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _ISpringDamperDataRepository_h_  
#define _ISpringDamperDataRepository_h_    

namespace Simulation
{
	class ISpringDamperDataRepository
	{
		public:
			virtual int GetMass() = 0; 
			virtual int GetSpringConstant() = 0; 
			virtual int GetDamperConstant() = 0;
	};
}

#endif