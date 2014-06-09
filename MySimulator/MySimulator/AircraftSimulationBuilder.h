/*********************************************************************************************************************/
//
//  AircraftSimulationBuilder.h
//  Class Description:  This class is part of the builder software creation pattern.The class builds the aircraft 
//                      model, equations of motion and functionality to derive the state values.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftBuilder_h_  
#define _AircraftBuilder_h_  

#include <fstream>
#include <string>
#include "ISimulatorBuilder.h"
#include "IEoM.h"
#include "IIntegrator.h"
#include "RungeKuttaIntegrator.h"
#include "IStateResultHandler.h"
#include "IAircraftSimulatorInput.h"

using namespace std;
using namespace Simulation;

namespace AircraftSimulation
{

	//TODO: change class name to Simulator Builder and look at the private pointer memeber maybe put them locally
	class AircraftSimulationBuilder : public ISimulatorBuilder
	{
		private:
			string _outputFileName;
			AircraftType _aircraftType;
			IAircraftSimulatorInput* _pSimulatorInput;
			BaseSimulator* _pProduct;
			IEoM* _pEoM;
			IStateResultHandler* _pResultHandler;
			IIntegrator* _pIntergrator;
			IAircraft* _aircraftDataModel;
			double _intialSpeed;

		public:
			AircraftSimulationBuilder();
			virtual ~AircraftSimulationBuilder();
			void BuildCommandInputs();
			void BuildDataModel();
			void BuildEoM();
			void BuildIntergrator();
			BaseSimulator* GetResult();
	};
}

#endif