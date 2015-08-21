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

#ifndef _SpringDamperTestData_h_  
#define _SpringDamperTestData_h_ 


#include <map>
#include <exception>

#include "IStateResponseHandler.h"

namespace ApplicationTesting
{
	class SpringDamperTestData 
	{
		public:
			class State
			{
				public:
					State(): Position(0.0), Velocity(0.0){}
					State(double position, double velocity) : 
						 Position(position),
						 Velocity(velocity)
					  {}
					double Position;
					double Velocity;
			};
		private:
		std::map<double,SpringDamperTestData::State> _testData;
		void AddStateDataToStore(double time, double position, double velocity);
		void CreateData();
		
		public:
			SpringDamperTestData();
			~SpringDamperTestData();
			State GetStateData(int time) throw(range_error);
	};
}

#endif