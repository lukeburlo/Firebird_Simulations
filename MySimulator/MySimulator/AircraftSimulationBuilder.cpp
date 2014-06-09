/*********************************************************************************************************************/
//
//  ISimulatorBuilder.h
//  Class Description:  This class is part of the builder software creation pattern.The class creates the aircraft 
//                      model, equations of motion and functionality to derive the state values.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include <assert.h>
#include "AircraftSimulationBuilder.h"
#include "FileStreamHandler.h"
#include "NonLinearEoM.h"
#include <vector>
#include "Aircraft747100Data.h"
#include "AircraftSimulator.h"
#include "AircraftFactory.h"
#include "AircraftSimulatorInputFile.h"


using namespace std;
using namespace Simulation;

namespace AircraftSimulation
{
	AircraftSimulationBuilder::AircraftSimulationBuilder() : 
			ISimulatorBuilder(),
			_outputFileName("Aircraft_747-100_Respose.txt"),
			_aircraftType(NO_AIRCRAFT),
			_pProduct(0),
			_pEoM(0),
			_pResultHandler(0),
			_pIntergrator(0),
			_aircraftDataModel(0),
			_intialSpeed(0.0)
	{
		
	}

	AircraftSimulationBuilder::~AircraftSimulationBuilder()
	{
		if(_pEoM != 0) delete _pEoM;
		if(_pSimulatorInput != 0) delete _pSimulatorInput;
		if(_pResultHandler != 0) delete _pResultHandler;
		if(_pIntergrator != 0) delete _pIntergrator;
		if(_aircraftDataModel != 0) delete _aircraftDataModel;
		if(_pProduct != 0) delete _pProduct;
	}

	void AircraftSimulationBuilder::BuildCommandInputs()
	{
		 
		_pSimulatorInput = new AircraftSimulatorInputFile();
		assert(_pSimulatorInput);
		if(_pSimulatorInput)
		{
			//parse header
			vector<string> names(13);
			names[0] = "Time";
			names[1] = "dU";
			names[2] = "w";
			names[3] = "q";
			names[4] = "dTheta";
			names[5] = "v";
			names[6] = "p";
			names[7] = "r";
			names[8] = "Phi";
			names[9] = "Shi";
			names[10] = "x";
			names[11] = "y";
			names[12] = "z";



			_intialSpeed = _pSimulatorInput->GetAircraftIntialSpeed();
			_pProduct = new AircraftSimulator(_intialSpeed, _outputFileName);
			assert(_pProduct);
			_pProduct->SetStateNames(names);
			_pProduct->SetIntialStates(_pSimulatorInput->GetInitialStates());
			_pProduct->SetExternalInputs(_pSimulatorInput->GetExternalInputs());
			_aircraftType = _pSimulatorInput->GetAircraftType();
		}
		else
		{
			stringstream exceptionStream;
				exceptionStream << "ERROR - File: " << __FILE__ << " Line: " << __LINE__ <<". Could not build aircraft input." <<
					"Null pointer - type: IAircraftSimulatorInput*";
				throw runtime_error(exceptionStream.str());
		}
	}

	void AircraftSimulationBuilder::BuildDataModel()
	{
		AircraftFactory* aircraftFactory = AircraftFactory::Instance();

		if(aircraftFactory)
		{
			_aircraftDataModel = aircraftFactory->GetAircraft(_aircraftType);
		}
		else
		{
			stringstream exceptionStream;
				exceptionStream << "ERROR - File: " << __FILE__ << " Line: " << __LINE__ <<". Could not determine aircraft type." <<
					"Could not cast ISimulatorInput* to AircraftSimulatorInput* type.";
				throw runtime_error(exceptionStream.str());
		}
	}

	void AircraftSimulationBuilder::BuildEoM()
	{
		_pEoM = new NonLinearEoM(_aircraftDataModel, _intialSpeed);
	}

	void AircraftSimulationBuilder::BuildIntergrator()
	{
		_pResultHandler = new FileStreamHandler(*_pProduct);
		//need to set parameters
		_pIntergrator = new RungeKuttaIntegrator(0.001,_pEoM,_pResultHandler);
		_pProduct->SetEoMIntegrator(_pIntergrator);
	}
			
	BaseSimulator* AircraftSimulationBuilder::GetResult()
	{
		return _pProduct;
	}
}