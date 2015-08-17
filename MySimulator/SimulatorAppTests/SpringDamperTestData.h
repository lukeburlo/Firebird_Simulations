/*********************************************************************************************************************/
//
//  SpringDamperTestData.h
//  Class Description: Contains test data for a simple spring damper simulation
//
//  Created by Luke Burlovich on 13/08/2015
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
// Test Data is based on:
// *Time interval 0 - 8 secs
// *Time step is 0.1 secs
//
/*********************************************************************************************************************/

#ifndef _TestStateResponseHandler_h_  
#define _TestStateResponseHandler_h_ 


#include <map>

#include "IStateResponseHandler.h"

namespace ApplicationTesting
{
	class SpringDamperTestData 
	{
		public:
			class State
			{
				public:
					State(double position, double velocity) : 
						 Position(position),
						 Velocity(velocity)
					  {}
					double Position;
					double Velocity;
			};

		public:
			std::map<double,SpringDamperTestData::State> GetData = {
				(0,State(0.00603,0.11836)

			};
	};
}

#endif