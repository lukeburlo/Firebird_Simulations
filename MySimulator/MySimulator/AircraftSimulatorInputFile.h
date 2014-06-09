/*********************************************************************************************************************/
//
//  AircraftSimulatorInputFile.h
//  Class Description: TODO
//	
//  Note: Any new aircraft types need to be defined in the construtor.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftSimulatorInputFile_h_  
#define _AircraftSimulatorInputFile_h_    

#include <string>
#include <unordered_map>
#include "IAircraftSimulatorInput.h"
#include "AircraftFactory.h"
#include "AircraftConstants.h"

using namespace Simulation;
using namespace std;

namespace AircraftSimulation
{
	//add file to class name
	class AircraftSimulatorInputFile : public IAircraftSimulatorInput
	{
		private:
			const int _maxNumberOfControlInputs;
			bool _hasParsed;

			const unordered_map<int, AircraftInputType> _controlInputFileMapping;
			unordered_map<int, AircraftInputType> CreateControlInputFileMapping();
			AircraftInputType GetIndexFromControlInputFileMapping(int index);

			const unordered_map<string, AircraftType> _aircraftNameMapping;
			unordered_map<string, AircraftType> CreateAircraftNameMapping();

			ScheduleInput ParseControlInputString(vector<string>& inputs);
			vector<double> ParseStateInputString(vector<string>& inputs);

			void Parse();

		protected:
			string _filename;
			AircraftType _aircraftName;
			double _intialSpeed;
			vector<double> _intialStateValues;
			vector<ScheduleInput> _scheduledExternalInputs;

			bool GetNextValidLine(ifstream& inputFile, string& validLine);
			bool IsDigits(string &str);

			void ProcessAircraftType(ifstream& inputFile);
			void ProcessAircraftIntialSpeed(ifstream& inputFile);
			void ProcessAircraftIntialStates(ifstream& inputFile);
			void ProcessAircraftManoeuvre(ifstream& inputFile);

			void SetAircraftType(string& aircraftName);
			void SetExternalInputs(vector<string>& inputs);
			void SetIntialStateValues(vector<string>& inputs);

			void EnsureParse();

		public: 
			AircraftSimulatorInputFile();
			~AircraftSimulatorInputFile();
			//  Parse() Exceptions:
			//		out_of_range:		When specified aircraft type has not been defined
			//		invalid_argument:	Invalid line in the configuration file or expected data does not exist
			//		runtime_error:		Can not open the defined config file.
			virtual vector<double> GetInitialStates();
			virtual vector<ScheduleInput> GetExternalInputs();
			virtual AircraftType GetAircraftType();
			virtual double GetAircraftIntialSpeed();
	};	
}

#endif