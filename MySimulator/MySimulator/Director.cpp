/*********************************************************************************************************************/
//
//  Director.cpp
//  Class Description: This is the director class of the builder software creation pattern. The Director is in charge
//                     building the objects that are required for the simulator. The Director class is also a singleton
//                     object.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include "Director.h"

namespace Simulation
{
	Director* Director::_instance = 0;

	Director::Director(){};

	Director* Director::Instance()
	{

		if(!_instance)
		{
			_instance = new Director();
		}
        return  _instance;
	}

	void Director::Construct(ISimulatorBuilder* builder)
	{
		builder ->BuildCommandInputs();
		builder->BuildDataModel();
		builder->BuildEoM();
		builder->BuildIntergrator();
	}

}