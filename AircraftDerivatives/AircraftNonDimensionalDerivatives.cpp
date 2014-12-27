/*********************************************************************************************************************/
//
//  AircraftNonDimensionalDerivatives.cpp
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/
#include <math.h>
#include "AircraftNonDimensionalDerivatives.h"
#include "IAircraftProperties.h"

namespace AircraftSimulation
{
	AircraftNonDimensionalDerivatives::AircraftNonDimensionalDerivatives(
		IAircraftCoefficients* pCoefficients, double machNumber, IAircraftProperties* properties) :
		_pCoefficients(pCoefficients),
		_machNumber(machNumber),
		_machNumberLimitForIncompressibleFlow(0.3),
		_tailVolumeRatio(1),
		_properties(properties)
	{
		try
		{
			Calculate();
		}
		catch(...)
		{
			//TODO
		}
	}

	AircraftNonDimensionalDerivatives::~AircraftNonDimensionalDerivatives()
	{

	}

	void AircraftNonDimensionalDerivatives::Calculate()
	{
		CalculateTailVolumeRatio();
		CalculateCX_u();
		CalculateCZ_u();
		CalculateCm_u();
		CalculateCZ_q();
		CalculateCm_q();
		CalculateCZ_alpha_dot();
	}

	void AircraftNonDimensionalDerivatives::CalculateTailVolumeRatio()
	{
		_tailVolumeRatio = (_properties->GetTailMomentArm()*_properties->GetTailSurfaceArea())/
			(_properties->GetWingSurfaceArea()*_properties->GetWingChord());
	}

	void AircraftNonDimensionalDerivatives::CalculateDownwashChangeDueToAoA()
	{
		
	}

	void AircraftNonDimensionalDerivatives::CalculateCX_u()
	{
		_CX_u =-((_pCoefficients->GetC_D_M()*_machNumber) + (2*_pCoefficients->GetC_D_0())) + _pCoefficients->GetC_T_U() ;
	}

	double AircraftNonDimensionalDerivatives::GetCX_u()
	{
		return _CX_u;
	}

	void AircraftNonDimensionalDerivatives::CalculateCZ_u()
	{
		double CL_u = 0;

		if(_machNumber >= _machNumberLimitForIncompressibleFlow)
		{
			CL_u = ((pow(_machNumber, 2.0)) / (1 - pow(_machNumber, 2.0)))*_pCoefficients->GetC_L_0();
		}
		_CZ_u = -(CL_u+(2*_pCoefficients->GetC_L_0()));
	}

	double AircraftNonDimensionalDerivatives::GetCZ_u()
	{
		return _CZ_u;
	}

	void AircraftNonDimensionalDerivatives::CalculateCm_u()
	{
		_Cm_u = _pCoefficients->GetdC_m_dM() * _machNumber;
	}

	double AircraftNonDimensionalDerivatives::GetCm_u()
	{
		return _Cm_u;
	}
	void AircraftNonDimensionalDerivatives::CalculateCZ_q()
	{

		_CZ_q = -2*_pCoefficients->GetC_L_alpha_tail()*_pCoefficients->GetTailEfficency()*_tailVolumeRatio;
	}

	double AircraftNonDimensionalDerivatives::GetCZ_q()
	{
		return _CZ_q;
	}
	void AircraftNonDimensionalDerivatives::CalculateCm_q()
	{
		_Cm_q = -2*_pCoefficients->GetC_L_alpha_tail()*_pCoefficients->GetTailEfficency()*_tailVolumeRatio*
			(_properties->GetTailMomentArm()/_properties->GetWingChord());
	}

	double AircraftNonDimensionalDerivatives::GetCm_q()
	{
		return _Cm_q;
	}

	void AircraftNonDimensionalDerivatives::CalculateCZ_alpha_dot()
	{
		_CZ_alpha_dot = -2;
	}

	double AircraftNonDimensionalDerivatives::GetCZ_alpha_dot()
	{
		return _CZ_alpha_dot;
	}
}