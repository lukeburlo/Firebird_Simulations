/*********************************************************************************************************************/
//
//  IIntegrator.h
//  Class Description: This interface is used to define a type of intergration routine.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IIntegrator_h_  
#define _IIntegrator_h_    

#include <vector>
#include <vector>

using namespace std;

namespace Simulation
{
	class IIntegrator
	{
		public:
			virtual void SetIntergrateTimeInterval(double startTime, double endTime) = 0 ;
			virtual void Intergrate(vector<double>& states, vector<double>& inputs) = 0;
	};
}

#endif