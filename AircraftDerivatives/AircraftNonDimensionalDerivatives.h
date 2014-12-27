/*********************************************************************************************************************/
//
//  AircraftNonDimensionalDerivatives.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftNonDimensionalDerivatives_h_  
#define _AircraftNonDimensionalDerivatives_h_    

#include "IAircraftCoefficients.h"
#include "IAircraftNonDimensionalDerivatives.h"
#include "IAircraftProperties.h"

namespace AircraftSimulation
{
	class AircraftNonDimensionalDerivatives : IAircraftNonDimensionalDerivatives
	{
		private:
			IAircraftCoefficients* _pCoefficients;

			double _machNumber;
			double _machNumberLimitForIncompressibleFlow;
			float _tailVolumeRatio;
			float _downwashChangeDueToAoA;
			IAircraftProperties* _properties;

			double _CX_u;
			double _CZ_u;
			double _Cm_u;
			double _CZ_q;
			double _Cm_q;
			double _CZ_alpha_dot;

			void CalculateTailVolumeRatio();
			void CalculateDownwashChangeDueToAoA();
			void CalculateCX_u();
			void CalculateCZ_u();
			void CalculateCm_u();
			void CalculateCZ_q();
			void CalculateCm_q();
			void CalculateCZ_alpha_dot();

		protected:
			void Calculate();

		public:
			AircraftNonDimensionalDerivatives(IAircraftCoefficients* coefficients, double machNumber, 
				IAircraftProperties* properties);
			virtual ~AircraftNonDimensionalDerivatives();

			virtual double GetCX_u();
			virtual double GetCZ_u();
			virtual double GetCm_u();
			virtual double GetCZ_q();
			virtual double GetCm_q();
			virtual double GetCZ_alpha_dot();
	};
}

#endif