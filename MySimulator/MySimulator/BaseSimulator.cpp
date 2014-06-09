/*********************************************************************************************************************/
//
//  Simulator.cpp
//  Class Description: This is the product class of the builder software creation pattern. The product is the
//                     simulator.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include <stdexcept> 
#include <string> 
#include <iomanip>
#include "BaseSimulator.h"
#include <vector>

using namespace std;


namespace Simulation
{
	BaseSimulator::BaseSimulator(string& fileName):
			_resultsFileName(fileName), 
			_pEoMIntegrator(0),
			_fileDataWidth(20)
	{
		Init();
	}
	
	BaseSimulator::~BaseSimulator()
	{
		if(_dataStream != 0)
		{
			_dataStream.close();
		}
	}

	void BaseSimulator::Init()
	{
		if(_dataStream != 0)
		{
			if(!_resultsFileName.empty()) 
				_dataStream.open(_resultsFileName,fstream::out);
		}

		return;
	}

	void BaseSimulator::Intergrate(vector<double>& states, vector<double>& input, 
		double startTinme, double endTime)
	{
		if(_pEoMIntegrator !=0)
		{
			_pEoMIntegrator->SetIntergrateTimeInterval(startTinme, endTime);
			_pEoMIntegrator->Intergrate(states, input);
		}
		else
		{
			string errString = "Simulator::Intergrate(): The EoM Intergrator has not been built.";
			throw invalid_argument(errString);
		}
	}

	void BaseSimulator::SetEoMIntegrator(IIntegrator* EoMIntegrator)
	{
		_pEoMIntegrator = EoMIntegrator;
	}

	void BaseSimulator::SetStateNames(vector<string>& names)
	{
		_stateVariableNames = names;
	}

	void BaseSimulator::SetIntialStates(vector<double>& states)
	{
		_intialStates = states;
	}

	void BaseSimulator::SetExternalInputs(vector<ScheduleInput>& inputs)
	{
		_externalInputs = inputs;
	}

	void BaseSimulator::Run()
	{
		double startTime = 0.0;
		double endTime = 0.0;

		SetHeader();

		for (unsigned int index = 0; index < _externalInputs.size(); index++) 
		{
			endTime = _externalInputs[index].TimeInterval;
			Intergrate(_intialStates, _externalInputs[index].Inputs, startTime, endTime);
			startTime = endTime;
		}
	}


	//test
	void BaseSimulator::Run(vector<double>& states)
	{
		double startTime = 0.0;
		double endTime = 0.0;

		SetHeader();

		for (unsigned int index = 0; index < _externalInputs.size(); index++) 
		{
			endTime = _externalInputs[index].TimeInterval;
			Intergrate(states, _externalInputs[index].Inputs, startTime, endTime);
			startTime = endTime;
		}
	}

	void BaseSimulator::SetHeader()
	{
		// need to check data stream not null
		for(unsigned int i=0; i < _stateVariableNames.size(); i++)
		{
			_dataStream << setw(_fileDataWidth) << _stateVariableNames[i];
		}

		_dataStream << '\n';
	}

	void BaseSimulator::RecordStates(double time, vector<double>& states)
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
			_dataStream << setw(_fileDataWidth) << fixed << setprecision (5) << states[i];
		}

		_dataStream << '\n';

		return;
	}

}

