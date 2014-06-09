/*********************************************************************************************************************/
//
//  AircraftSimulatorInput.cpp
//  Class Description: TODO
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <assert.h>
#include "AircraftSimulatorInputFile.h"
#include "VSTrace.h"

namespace AircraftSimulation
{
	AircraftSimulatorInputFile::AircraftSimulatorInputFile() :
				_filename("AircraftSimulatorInput.txt"),
				_aircraftName(NO_AIRCRAFT),
				_intialSpeed(0),
				_maxNumberOfControlInputs(4),
				_hasParsed(false),
				_aircraftNameMapping(CreateAircraftNameMapping()),
				_controlInputFileMapping(CreateControlInputFileMapping())
	{
		
	}

	AircraftSimulatorInputFile::~AircraftSimulatorInputFile()
	{

	}

	unordered_map<int, AircraftInputType> AircraftSimulatorInputFile::CreateControlInputFileMapping()
	{
		unordered_map<int, AircraftInputType> result;

		result[1] = AircraftInputType::ELEVATOR;
		result[2] = AircraftInputType::THROTTLE;
 		result[3] = AircraftInputType::ALERION;
		result[4] = AircraftInputType::RUDDER;

		return result;
	}

	unordered_map<string, AircraftType> AircraftSimulatorInputFile::CreateAircraftNameMapping()
	{
		unordered_map<string, AircraftType> result;

		result["BOEING-747-100"] = AircraftType::BOEING_747_100;
		
		return result;
	}

	AircraftInputType AircraftSimulatorInputFile::GetIndexFromControlInputFileMapping(int index)
	{
		return _controlInputFileMapping.find(index)->second;
	}

	ScheduleInput AircraftSimulatorInputFile::ParseControlInputString(vector<string>& inputs)
	{
		ScheduleInput result;

		vector<double> scheduledControlInputs(inputs.size() - 1, 0.0);

		for(unsigned int index=0; index < inputs.size(); index++)
		{ 
			
			if(IsDigits(inputs[index]))
			{
				double numericInput = stof(inputs[index]);
				if(0 == index)
				{
					result.TimeInterval = numericInput;
				}
				else
				{
					AircraftInputType inputType = GetIndexFromControlInputFileMapping(index);
					scheduledControlInputs[inputType] = numericInput;
				}
			}
			else
			{
				stringstream exceptionStream;
					exceptionStream << "One of the manoeuvre parameters is not the correct type. Manoeuvre parameter in postion "  
						<< "'"<< index <<"'" << " has a value of " << "'" << inputs[index] << "'. This is not a numeric type." 
						<< " Check the configuration file '" << _filename << "'";
					throw runtime_error(exceptionStream.str());
			}
		}

		result.Inputs = scheduledControlInputs;

		return result;
	}

	vector<double> AircraftSimulatorInputFile::ParseStateInputString(vector<string>& inputs)
	{

		vector<double> result;

		for(unsigned int index=0; index < inputs.size(); index++)
		{ 
			
			if(IsDigits(inputs[index]))
			{
				double numericInput = stof(inputs[index]);
				result.push_back(numericInput);
			}
			else
			{
				stringstream exceptionStream;
					exceptionStream << "One of the intial state values is not the correct type. Intial state value in postion "  
						<< "'"<< index <<"'" << " has a value of " << "'" << inputs[index] << "'. This is not a numeric type." 
						<< " Check the configuration file '" << _filename << "'";
					throw runtime_error(exceptionStream.str());
			}
		}

		return result;
	}

	bool AircraftSimulatorInputFile::GetNextValidLine(ifstream& inputFile, string& validLine)
	{
		bool result = false;
		string line = "";

		while (getline(inputFile, line))
		{
			if(line.substr(0,1) != "#" && !line.empty())
			{
				validLine = line;
				result = true;
				break;
			}
		}

		return result;
	}

	bool AircraftSimulatorInputFile::IsDigits(string &str)
	{
		return str.find_first_not_of("-0123456789.") == std::string::npos;
	}

	void AircraftSimulatorInputFile::EnsureParse()
	{
		if(!_hasParsed)
		{
			Parse();
			_hasParsed = true;
		}
	}

	void AircraftSimulatorInputFile::Parse()
	{
		ifstream infile(_filename); //need to close this

		if(infile != NULL)
		{
			try
			{
				ProcessAircraftType(infile);
				ProcessAircraftIntialSpeed(infile);
				ProcessAircraftIntialStates(infile);
				ProcessAircraftManoeuvre(infile);
				
			}
			catch(out_of_range& e)
			{
				throw;
			}
			catch(invalid_argument& e)
			{
				throw;
			}
		}
		else
		{
			stringstream exceptionStream;
			exceptionStream << "Could not find the input command  file '" << _filename <<"'";
			throw runtime_error(exceptionStream.str());
		}
	}

	void  AircraftSimulatorInputFile::SetAircraftType(string& aircraftName)
	{
		if(_aircraftNameMapping.find(aircraftName) != _aircraftNameMapping.end())
		{
			_aircraftName = _aircraftNameMapping.find(aircraftName)->second;
		}
		else
		{
			_aircraftName = NO_AIRCRAFT;
			stringstream exceptionStream;
			exceptionStream << "The aircraft type '" << aircraftName << "' in the configuration file '" 
				<< _filename <<"' is not  a valid type. Please change to a valid type.";
			throw out_of_range(exceptionStream.str());
		}
	}

	void AircraftSimulatorInputFile::SetExternalInputs(vector<string>& inputs)
	{
		ScheduleInput ScheduledControlInputs = ParseControlInputString(inputs);

		ASSERT(ScheduledControlInputs.Inputs.size() == _maxNumberOfControlInputs);		
		
		_scheduledExternalInputs.push_back(ScheduledControlInputs);

	}

	void AircraftSimulatorInputFile::SetIntialStateValues(vector<string>& inputs)
	{
		_intialStateValues = ParseStateInputString(inputs);
	}

	AircraftType  AircraftSimulatorInputFile::GetAircraftType()
	{
		EnsureParse();
		return _aircraftName;
	}

	double  AircraftSimulatorInputFile::GetAircraftIntialSpeed()
	{
		EnsureParse();
		return _intialSpeed;
	}

	vector<double> AircraftSimulatorInputFile::GetInitialStates()
	{
		EnsureParse();
		return _intialStateValues;
	}

	vector<ScheduleInput> AircraftSimulatorInputFile::GetExternalInputs()
	{
		EnsureParse();
		return _scheduledExternalInputs;
	}

	void  AircraftSimulatorInputFile::ProcessAircraftType(ifstream& inputFile)
	{
		string line = "";

		if(GetNextValidLine(inputFile, line))
		{
			try
			{
				SetAircraftType(line);
			}
			catch(out_of_range& e)
			{
				throw;
			}
		}
		else
		{
			stringstream exceptionStream;
			exceptionStream << "Could not find a valid line corresponding to an aircraft type in the configuration file '" 
				<< _filename <<"'";
			throw invalid_argument(exceptionStream.str());
		}
	}

	void  AircraftSimulatorInputFile::ProcessAircraftIntialSpeed(ifstream& inputFile)
	{
		string line = "";

		if(GetNextValidLine(inputFile, line))
		{
			istringstream iss(line);
			if (!(iss >> _intialSpeed )) 
			{ 
				stringstream exceptionStream;
				exceptionStream << "The intial speed in the configuration file '" << _filename <<"'" 
					<< " is defined as '" << line << "'. This need to be a numerical value.";
				throw invalid_argument(exceptionStream.str());
			} 
		}
		else
		{
			stringstream exceptionStream;
			exceptionStream << "Could not find a valid line corresponding to the aircraft's intialSpeed in the " <<
				"configuration file '" << _filename <<"'";
			throw invalid_argument(exceptionStream.str());
		}
	}

	void  AircraftSimulatorInputFile::ProcessAircraftIntialStates(ifstream& inputFile)
	{
		string line = "";

		if(GetNextValidLine(inputFile, line))
		{
			istringstream iss(line);
			vector<string> rawInputsAsAStrings;
			copy(istream_iterator<string>(iss),
				istream_iterator<string>(),
				back_inserter<vector<string> >(rawInputsAsAStrings));

			SetIntialStateValues(rawInputsAsAStrings);
		}
		else
		{
			stringstream exceptionStream;
			exceptionStream << "Could not find a valid line corresponding to the aircraft's intial state values in the " <<
				"configuration file '" << _filename <<"'";
			throw invalid_argument(exceptionStream.str());
		}

	}

	void  AircraftSimulatorInputFile::ProcessAircraftManoeuvre(ifstream& inputFile)
	{
		string line = "";

		while(GetNextValidLine(inputFile, line))
		{
			istringstream iss(line);
			vector<string> rawInputsAsAStrings;
			copy(istream_iterator<string>(iss),
				istream_iterator<string>(),
				back_inserter<vector<string> >(rawInputsAsAStrings));

			if(rawInputsAsAStrings.size() > _maxNumberOfControlInputs + 1)
			{
				stringstream exceptionStream;
				exceptionStream << "To many control parameters for a manoeuvre. Currently there are " <<
					"'" << rawInputsAsAStrings.size() <<"' " << "parameters. There should only be " <<
					"'" << _maxNumberOfControlInputs + 1 << "' " << "parameters for a manoeuvre "<< 
					"in the configuration file '" << _filename << "'";
				throw invalid_argument(exceptionStream.str());
			}

			SetExternalInputs(rawInputsAsAStrings);
		}

		TRACE("TRACE: The number of scheduled manoeuvres is %d.\n", _scheduledExternalInputs.size());
	}

}

