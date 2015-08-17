/*********************************************************************************************************************/
//
//  RungeKuttaIntegrator.cpp
//  Class Description: This class is used to intergrate a set of ordinary diiferent equations. The class uses 
//                     a 4th order runge kutta method to approximate the solution in order to obtian the state 
//                     variables.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include "RungeKuttaIntegrator.h"

namespace Simulation
{
	void RungeKuttaIntegrator::step (double t, double h, vector<double>& X, 
		vector<double>& input)
	{
		//Used array instead of containers due to performance
		int numberOfStates = X.size();
		vector<double> tmp(numberOfStates);
		vector<double> dX(numberOfStates);
		vector<double> F1(numberOfStates);
		vector<double> F2(numberOfStates);
		vector<double> F3(numberOfStates);
		vector<double> F4(numberOfStates);

		/* Calculate F1 */
		derivative(t, X, dX, input);	
		multiply(h, dX, F1);

		/* Calculate F2 */	
		multiply(0.5, F1, tmp);	
		add (X, tmp, tmp);
		derivative(t+h/2.0, tmp, dX, input);
		multiply(h, dX, F2);

		/*Calculate F3 */
		multiply(0.5, F2, tmp);	
		add (X, tmp, tmp);	
		derivative(t+h/2.0, tmp, dX, input);
		multiply(h, dX, F3);
	
		/*Calculate F4 */
		add(X, F3, tmp);
		derivative(t+h, tmp, dX, input);	
		multiply(h, dX, F4);	

		/*Calculate the weighted sum */	
		add(F2, F3, tmp);	
		multiply(2.0, tmp, tmp);
		add (F1, tmp, tmp);
		add (F4, tmp, tmp);	
		multiply(1.0/6.0, tmp, tmp);	
		add (tmp, X, X);
	}

	void RungeKuttaIntegrator::derivative(double t, vector<double>& X, vector<double>& dX,
		vector<double>& input)
	{
		_pEoM->CalculateRates(X,dX, input);
	}

	void RungeKuttaIntegrator::add(vector<double>& array1, vector<double>& array2,
		vector<double>& result)
	{
		for(unsigned int i = 0; i < array1.size(); i++) result[i] = array1[i] + array2[i];
	}

	void RungeKuttaIntegrator::multiply(double scalarValue, vector<double>& values, 
		vector<double>& result)
	{
		for (unsigned int i = 0; i < values.size(); i++) result[i] = scalarValue*values[i];
	}
	
	RungeKuttaIntegrator::RungeKuttaIntegrator(double timeStep, 
		IEoM* pEoM, IStateResponseHandler* pResultHandler) : IIntegrator()
	{
		_startTime = 0.0;
		_endTime = 0.0;
		_timeStep = timeStep;
		_pResultHandler = pResultHandler;
		_pEoM = pEoM;
	}

	RungeKuttaIntegrator::~RungeKuttaIntegrator()
	{
		
	}

	void RungeKuttaIntegrator::SetIntergrateTimeInterval(double startTime, double endTime)
	{
		_startTime = startTime;
		_endTime = endTime;
	}
	

	RungeKuttaIntegrator::RungeKuttaIntegrator(  RungeKuttaIntegrator& other )
	{ 
		_startTime = other._startTime;
		_endTime = other._endTime;
		_timeStep = other._timeStep;
		_pResultHandler =  other._pResultHandler;
		_pEoM = other._pEoM;
	}

	void RungeKuttaIntegrator::Intergrate(vector<double>& states, vector<double>& inputs)
	{
		int stateCounter = 0;
		int numberOfStates = states.size();

		//check start not greater then end time

		for(double t = _startTime; t < _endTime; t += _timeStep)
		{
				step (t, _timeStep, states, inputs);
				if(stateCounter == 0)
				{
					//change state
// t, X[0], X[1]/intialSpeed, X[2], X[3]*radToDeg, X[4], X[5], X[6], X[7]*radToDeg, X[8], X[9],X[10], X[11]); 
					// vector<double> states2 = states; cant do this
					//states2[1] = states2[1]/774.0;
					_pResultHandler->Handle(t,states);
				}
				stateCounter >= numberOfStates - 1 ? stateCounter = 0 : stateCounter++;
		}
	}

}