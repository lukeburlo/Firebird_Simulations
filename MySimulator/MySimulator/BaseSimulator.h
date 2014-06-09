/*********************************************************************************************************************/
//
//  BaseSimulator.h
//  Class Description: This is the product class of the builder software creation pattern. The product is the
//                     simulator.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _Simulator_h_  
#define _Simulator_h_

#include <fstream>
#include <string>
#include <vector>
#include <vector>
#include "IIntegrator.h"
#include "ScheduleInput.h"
#include "IAircraftSimulatorInput.h"

using namespace std;

namespace Simulation
{
	class BaseSimulator
	{
		private:
			void Init();

		protected:
			string _resultsFileName;
			int _fileDataWidth;
			fstream _dataStream;
			vector<string> _stateVariableNames;
			vector<double> _intialStates;
			vector<ScheduleInput> _externalInputs;
			IIntegrator* _pEoMIntegrator;

			virtual void SetHeader();
			void Intergrate(vector<double>& states, vector<double>& input, 
					double startTinme, double endTime);
			friend ostream &operator<<(ostream &out, vector<double>& states);
			

		public:
			BaseSimulator(string& fileName);
			~BaseSimulator();
			void SetEoMIntegrator(IIntegrator* EoMIntegrator);
			void SetStateNames(vector<string>& names);
			void SetIntialStates(vector<double>& states);
			void SetExternalInputs(vector<ScheduleInput>& inputs);
			//void Run(vector<double>& states, vector<double>& input);
			//virtual void Run(vector<double>& states, vector<ScheduleInput>& inputSquence);
			void Run(vector<double>& states);
			void Run();
			virtual void RecordStates(double time, vector<double>& states);
	};
}

#endif