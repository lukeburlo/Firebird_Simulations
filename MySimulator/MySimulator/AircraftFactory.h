/*********************************************************************************************************************/
//
//  AircraftFactory.h
//  Class Description:  
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftFactory_h_  
#define _AircraftFactory_h_  

#include <string>
#include <map>
#include "IAircraft.h"
#include "AircraftConstants.h"

using namespace std;

namespace AircraftSimulation
{
	class AircraftFactory
	{
		private:
			static AircraftFactory* _instance;
			AircraftFactory();

		protected:
			map<AircraftType, IAircraft*> _aircrafts;
			void Register(AircraftType aircraftName, IAircraft* aircraftModel);

		public:
			~AircraftFactory();
			static AircraftFactory* Instance();
			IAircraft* GetAircraft(AircraftType aircraftName);
	};
}

#endif