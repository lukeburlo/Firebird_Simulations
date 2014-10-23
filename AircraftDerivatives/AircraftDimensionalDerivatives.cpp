/*********************************************************************************************************************/
//
//  AircraftDimensionalDerivatives.cpp
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/


#include "AircraftDimensionalDerivatives.h"

namespace AircraftSimulation
{
	AircraftDimensionalDerivatives::AircraftDimensionalDerivatives(IAircraftCoefficients* pCoefficients) :
		_pCoefficients(pCoefficients)
	{
		Calculate();
	}

	AircraftDimensionalDerivatives::~AircraftDimensionalDerivatives()
	{

	}

	void AircraftDimensionalDerivatives::Calculate()
	{
		CalculateX_u();
	}

	void AircraftDimensionalDerivatives::CalculateX_u()
	{
		X_u = _pCoefficients->GetC_D_0();
	}

	double AircraftDimensionalDerivatives::GetX_u()
	{
		return X_u;
	}

}