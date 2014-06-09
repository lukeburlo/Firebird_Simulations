/*********************************************************************************************************************/
//
//  RungeKuttaIntegrator.h
//  Class Description: This class is used to intergrate a set of ordinary diiferent equations. The class uses 
//                     a 4th order runge kutta method to approximate the solution in order to obtian the state 
//                     variables.                  
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _RungeKuttaIntegrator_h_  
#define _RungeKuttaIntegrator_h_

#include <vector>
#include "IIntegrator.h"
#include "IStateResultHandler.h"
#include "IEoM.h"

using namespace std;

namespace Simulation
{
	class RungeKuttaIntegrator : public IIntegrator
	{
		private:
			double _startTime;
			double _endTime;
			double _timeStep;
			IStateResultHandler* _pResultHandler;
			IEoM* _pEoM;
			int _numberOfStates;

			void step (double t, double h, vector<double>& X, vector<double>& input);
			void derivative(double t, vector<double>& X, vector<double>& dX,
				vector<double>& input);
			void add(vector<double>& X1, vector<double>& X2, vector<double>& R);
			void multiply(double X, vector<double>& V, vector<double>& R);
	
		public:
			RungeKuttaIntegrator(double timeStep, IEoM* pEoM, IStateResultHandler* pResultHandler);
			virtual ~RungeKuttaIntegrator();
			RungeKuttaIntegrator(RungeKuttaIntegrator& other);
			void SetIntergrateTimeInterval(double startTime, double endTime);
			void Intergrate(vector<double>& states, vector<double>& controlInputs);
			

	};
}

#endif