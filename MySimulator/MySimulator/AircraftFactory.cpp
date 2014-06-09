/*********************************************************************************************************************/
//
//  AircraftFactory.cpp
//  Class Description:  
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include "AircraftFactory.h"
#include "Aircraft747100Data.h"

namespace AircraftSimulation
{
	AircraftFactory* AircraftFactory::_instance = 0;

	AircraftFactory::AircraftFactory()
	{
		Register(BOEING_747_100, new Aircraft747100Data());
	}

	AircraftFactory::~AircraftFactory()
	{
		_aircrafts.clear();
	}

	AircraftFactory* AircraftFactory::Instance()
	{
		if(!_instance)
		{
			_instance = new AircraftFactory();
		}
        return  _instance;
	}

	void AircraftFactory::Register(AircraftType aircraftName, IAircraft* aircraftModel)
	{
		_aircrafts[aircraftName] = aircraftModel;
	}

	IAircraft* AircraftFactory::GetAircraft(AircraftType aircraftName)
	{
		return _aircrafts[aircraftName];
	}

}
