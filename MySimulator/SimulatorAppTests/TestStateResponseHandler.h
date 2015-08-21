/*********************************************************************************************************************/
//
//  TestStateResponseHandler.h
//  Class Description: Provides a handler for state responsers to the app tests.
//
//  Created by Luke Burlovich on 13/08/2015
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _TestStateResponseHandler_h_  
#define _TestStateResponseHandler_h_ 

#include <vector>

#include "IStateResponseHandler.h"
#include "SpringDamperTestData.h"

namespace ApplicationTesting
{
	class TestStateResponseHandler : public Simulation::IStateResponseHandler
	{
		public:
			class StateResponse
			{
				public:
					double Time;
					vector<double> States;
			};

		private:
			SpringDamperTestData _expectedResponses;

		public:
			TestStateResponseHandler();
			~TestStateResponseHandler();
			virtual void Handle(double time, vector<double>& states);
	};
}

#endif