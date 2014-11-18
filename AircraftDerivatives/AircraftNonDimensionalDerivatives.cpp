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
	}

	void AircraftNonDimensionalDerivatives::CalculateTailVolumeRatio()
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

}