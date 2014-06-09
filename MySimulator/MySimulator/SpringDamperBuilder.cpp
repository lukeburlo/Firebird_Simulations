/*********************************************************************************************************************/
//
//  SpringDamperBuilder.cpp
//  Class Description: This is the builder class of the builder software creation pattern. The class is responsible
//                     for creating model for a simple spring and damper system.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************///

#include <assert.h>
#include "SpringDamperBuilder.h"
#include "RungeKuttaIntegrator.h"
#include "FileStreamHandler.h"
#include "SpringDamperNonLinearEoM.h"
#include "StandardSpringDamperData.h"

using namespace std;

namespace Simulation
{
	SpringDamperBuilder::SpringDamperBuilder() : 
			ISimulatorBuilder(),
			_outputFileName("SpringDamperRespose.txt"),
			_pProduct(0),
			_pEoM(0),_pResultHandler(0),
			_pIntergrator(0), 
			_pDataModel(0)
	{
		_pProduct = new BaseSimulator(_outputFileName);
	}

	SpringDamperBuilder::~SpringDamperBuilder()
	{
		if(_pEoM != 0) delete _pEoM;
		if(_pResultHandler != 0) delete _pResultHandler;
		if(_pIntergrator != 0) delete _pIntergrator;
		if(_pDataModel != 0) delete _pDataModel;
		if(_pProduct != 0) delete _pProduct;

	}

	void SpringDamperBuilder::BuildCommandInputs()
	{
			assert(_pProduct);

			vector<string> headerNames(3);
			headerNames[0] = "Time";
			headerNames[1] = "Position";
			headerNames[2] = "Velocity";
			_pProduct->SetStateNames(headerNames);

			vector<double> intialStates(2);
			headerNames[0] = 0.0;
			headerNames[1] = 0.0;
			_pProduct->SetIntialStates(intialStates);

			double timeInterval = 30.0;
			vector<double> input(1,5);
			ScheduleInput scheduledInput(timeInterval, input);
			vector<ScheduleInput> scheduledInputs(1, scheduledInput);
			_pProduct->SetExternalInputs(scheduledInputs);
	}

	void SpringDamperBuilder::BuildDataModel()
	{
		_pDataModel = new StandardSpringDamperData();
	}

	void SpringDamperBuilder::BuildEoM()
	{
		//check data model not null
		_pEoM = new SpringDamperNonLinearEoM(_pDataModel);
	}

	void SpringDamperBuilder::BuildIntergrator()
	{
		_pResultHandler = new FileStreamHandler(*_pProduct);
		_pIntergrator = new RungeKuttaIntegrator(0.001,_pEoM,_pResultHandler);
		_pProduct->SetEoMIntegrator(_pIntergrator);
	}
			
	BaseSimulator* SpringDamperBuilder::GetResult()
	{
		return _pProduct;
	}

}