/*********************************************************************************************************************/
//
//  AircraftSimulator.cpp
//  Class Description: This is the product class of the builder software creation pattern. The product is the
//                     simulator. The AircraftSimulator class is derived from the BaseSimulator class.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/


#include <stdexcept> 
#include <iomanip>
#include "AircraftSimulator.h"
#include "AircraftConstants.h"

namespace AircraftSimulation
{
	AircraftSimulator::AircraftSimulator(double intialSpeed, string& fileName):
			BaseSimulator(fileName),
			_intialSpeed(intialSpeed)
	{
	}

	AircraftSimulator::~AircraftSimulator()
	{
	}

	void AircraftSimulator::RecordStates(double time, vector<double>& states)
	{
		int arraySize = states.size();

		if(arraySize <= 0) 
		{
			string errorString = "Simulator::RecordStates(): Invalid argument - state array is empty.";
			throw invalid_argument(errorString);
		}

		_dataStream << setw(_fileDataWidth) << time;

		// need to check data stream not null
		for(int i=0; i < arraySize; i++)
		{
			switch(i)
			{
				case VELOCITY_W:
					_dataStream << setw(_fileDataWidth) << fixed << setprecision (5) << states[i]/_intialSpeed;
					break;

				case THETA:
					_dataStream << setw(_fileDataWidth) << fixed << setprecision (5) << states[i]*RAD_TO_DEG;
					break;

				case PHI:
					_dataStream << setw(_fileDataWidth) << fixed << setprecision (5) << states[i]*RAD_TO_DEG;
					break;

				default:
					_dataStream << setw(_fileDataWidth) << fixed << setprecision (5) << states[i];

			}
		}

		_dataStream << '\n';
	}

}

