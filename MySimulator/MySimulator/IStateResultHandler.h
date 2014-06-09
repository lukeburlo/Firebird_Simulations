/*********************************************************************************************************************/
//
//  IStateResultHandler.h
//  Class Description:  This interface is used to define a type of handler for when the states are calculated.
//                     
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _IStateResultHandler_h_  
#define _IStateResultHandler_h_

#include <vector>

using namespace std;

namespace Simulation
{
	class IStateResultHandler
	{
		public:
			virtual void Handle(double time, vector<double>& states) = 0;
	};
}

#endif