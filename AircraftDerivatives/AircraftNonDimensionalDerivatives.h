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
#include "AircraftProperties.h"

namespace AircraftSimulation
{
	class AircraftNonDimensionalDerivatives : IAircraftNonDimensionalDerivatives
	{
		private:
			IAircraftCoefficients* _pCoefficients;

			double _machNumber;
			double _machNumberLimitForIncompressibleFlow;
			double _tailEfficency;
			double _tailVolumeRatio;
			AircraftProperties _properties;

			double _CX_u;
			double _CZ_u;
			double _Cm_u;

			void CalculateTailVolumeRatio();
			void CalculateCX_u();
			void CalculateCZ_u();
			void CalculateCm_u();

		protected:
			void Calculate();

		public:
			AircraftNonDimensionalDerivatives(IAircraftCoefficients* coefficients, double machNumber, 
				AircraftProperties properties);
			virtual ~AircraftNonDimensionalDerivatives();

			virtual double GetCX_u();
			virtual double GetCZ_u();
			virtual double GetCm_u();
	};
}

#endif