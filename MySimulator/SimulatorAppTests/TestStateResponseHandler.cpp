/*********************************************************************************************************************/
//
//  TestStateResponseHandler.cpp
//  Class Description: Provides a handler for state responsers to the app tests.
//
//  Created by Luke Burlovich on 13/08/2015
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include "TestStateResponseHandler.h"
#include "SpringDamperTestData.h"

namespace ApplicationTesting
{
	TestStateResponseHandler::TestStateResponseHandler(){}

	TestStateResponseHandler::~TestStateResponseHandler(){}

	void TestStateResponseHandler::Handle(double time, vector<double>& states)
	{
		StateResponse aResponse;
		aResponse.Time = time;
		aResponse.States = states;

		SpringDamperTestData expect
		
	}
}
