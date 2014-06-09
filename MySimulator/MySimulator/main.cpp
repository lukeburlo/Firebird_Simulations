
#include <iostream>
#include "IAircraftSimulatorInput.h"
#include "AircraftFactory.h"

#include "ISimulatorBuilder.h"
#include "BaseSimulator.h"
#include "Director.h"
#include "AircraftSimulationBuilder.h"
#include "SpringDamperBuilder.h"
#include "ScheduleInput.h"
#include <string>
#include <vector>

using namespace Simulation;
using namespace std;

using namespace AircraftSimulation;

int main()
{ 
	try
	{
		//ISimulatorBuilder* b = new AircraftSimulation::AircraftSimulationBuilder();
		ISimulatorBuilder* b = new SpringDamperBuilder();

		Director::Instance()->Construct(b);

		BaseSimulator* sim = b->GetResult();

		sim->Run();
	}
	catch(exception& ex)
	{
		cout << ex.what();
	}
}

