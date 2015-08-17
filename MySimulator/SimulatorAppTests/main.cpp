
/*********************************************************************************************************************/
//
//  main.cpp
//  Class Description: Runs application test for the spring damper simulatotions
//
//  Created by Luke Burlovich on 13/08/2015
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/



#include <iostream>
#include <memory>

#include "ISimulatorBuilder.h"
#include "BaseSimulator.h"
#include "Director.h"
#include "SpringDamperBuilder.h"
#include "TestStateResponseHandler.h"

int main()
{ 
	try
	{
		std::unique_ptr<ApplicationTesting::TestStateResponseHandler> pResponseHandler(new ApplicationTesting::TestStateResponseHandler);  

		//ISimulatorBuilder* b = new AircraftSimulation::AircraftSimulationBuilder();
		Simulation::ISimulatorBuilder* b = new Simulation::SpringDamperBuilder(pResponseHandler.get());

		Simulation::Director::Instance()->Construct(b);

		Simulation::BaseSimulator* sim = b->GetSimulator();
		

		sim->Run();


	}
	catch(exception& ex)
	{
		std::cout << ex.what();
	}
}

