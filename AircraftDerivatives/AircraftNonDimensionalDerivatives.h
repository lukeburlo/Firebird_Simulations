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
			IAircraftProperties* _properties;

			double _machNumber;
			double _machNumberLimitForIncompressibleFlow;
			float _tailVolumeRatio;
			float _downwashChangeDueToAoA;

			double _CX_u;
			double _CZ_u;
			double _Cm_u;
			double _CX_q;
			double _CZ_q;
			double _Cm_q;
			double _CX_alpha;
			double _CZ_alpha;
			double _Cm_alpha;
			double _CX_alpha_dot;
			double _CZ_alpha_dot;
			double _Cm_alpha_dot;
			double _CZ_delta_elevator;
			double _Cm_delta_elevator;

			void CalculateTailVolumeRatio();
			void CalculateDownwashChangeDueToAoA();
			void CalculateCX_u();
			void CalculateCZ_u();
			void CalculateCm_u();
			void CalculateCX_q();
			void CalculateCZ_q();
			void CalculateCm_q();
			void CalculateCX_alpha();
			void CalculateCZ_alpha();
			void CalculateCm_alpha();
			void CalculateCX_alpha_dot();
			void CalculateCZ_alpha_dot();
			void CalculateCm_alpha_dot();
			void CalculateCZ_delta_elevator();
			void CalculateCm_delta_elevator();

		protected:
			void Calculate();

		public:
			AircraftNonDimensionalDerivatives(IAircraftCoefficients* coefficients, double machNumber, 
				IAircraftProperties* properties);
			virtual ~AircraftNonDimensionalDerivatives();

			virtual double GetCX_u();
			virtual double GetCZ_u();
			virtual double GetCm_u();
			virtual double GetCX_q();
			virtual double GetCZ_q();
			virtual double GetCm_q();
			virtual double GetCX_alpha();
			virtual double GetCZ_alpha();
			virtual double GetCm_alpha();
			virtual double GetCX_alpha_dot();
			virtual double GetCZ_alpha_dot();
			virtual double GetCm_alpha_dot();
			virtual double GetCZ_delta_elevator();
			virtual double GetCm_delta_elevator();
	};
}

#endif