/*********************************************************************************************************************/
//
//  AircraftSimulator.h
//  Class Description: This is the product class of the builder software creation pattern. The product is the
//                     simulator. The AircraftSimulator class is derived from the BaseSimulator class.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftSimulator_h_  
#define _AircraftSimulator_h_

#include <fstream>
#include <string>
#include <vector>
#include "BaseSimulator.h"

using namespace std;
using namespace Simulation;

namespace AircraftSimulation
{
	class AircraftSimulator : public BaseSimulator
	{
		private:

		protected:
			double _intialSpeed;

		public:
			//TODO: need to remove intial speed
			AircraftSimulator(double intialSpeed, string& fileName);
			~AircraftSimulator();
			virtual void RecordStates(double time, vector<double>& states);
	};
}

#endif