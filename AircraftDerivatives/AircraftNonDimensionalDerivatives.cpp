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
#include <stdio.h>
#include "AircraftNonDimensionalDerivatives.h"
#include "IAircraftProperties.h"
#include "DiagnosticsTools.h"

#define PI 3.14

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
		CalculateDownwashChangeDueToAoA();
		CalculateTailVolumeRatio();
		CalculateCX_u();
		CalculateCZ_u();
		CalculateCm_u();
		CalculateCX_q();
		CalculateCZ_q();
		CalculateCm_q();
		CalculateCX_alpha();
		CalculateCZ_alpha();
		CalculateCm_alpha();
		CalculateCX_alpha_dot();
		CalculateCZ_alpha_dot();
		CalculateCm_alpha_dot();
		CalculateCZ_delta_elevator();
		CalculateCm_delta_elevator();
	}

	void AircraftNonDimensionalDerivatives::CalculateTailVolumeRatio()
	{
		_tailVolumeRatio = (_properties->GetTailMomentArm()*_properties->GetTailSurfaceArea())/
			(_properties->GetWingSurfaceArea()*_properties->GetWingChord());
	}

	void AircraftNonDimensionalDerivatives::CalculateDownwashChangeDueToAoA()
	{
		_downwashChangeDueToAoA = (2*_pCoefficients->GetC_L_alpha_wing()) / (PI *_properties->GetWingAspectRatio());
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

	void AircraftNonDimensionalDerivatives::CalculateCX_q()
	{
		_CX_q = 0;
	}

	double AircraftNonDimensionalDerivatives::GetCX_q()
	{
		return _CX_q;
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

	void AircraftNonDimensionalDerivatives::CalculateCX_alpha()
	{
		_CX_alpha = _pCoefficients->GetC_L_0() - 
			(((2*_pCoefficients->GetC_L_0())/
			(PI*_properties->GetWingAspectRatio()*_properties->GetSpanEfficiencyFactor()))*
			_pCoefficients->GetC_L_alpha_wing());
	}

	double AircraftNonDimensionalDerivatives::GetCX_alpha()
	{
		return _CX_alpha;
	}

	void AircraftNonDimensionalDerivatives::CalculateCZ_alpha()
	{
		_CZ_alpha = -(_pCoefficients->GetC_L_alpha_wing() + _pCoefficients->GetC_D_0());
	}

	double AircraftNonDimensionalDerivatives::GetCZ_alpha()
	{
		return _CZ_alpha;
	}

	void AircraftNonDimensionalDerivatives::CalculateCm_alpha()
	{
		_Cm_alpha = (_pCoefficients->GetC_L_alpha_fuselage()) + 
			(_pCoefficients->GetC_L_alpha_wing()*(_properties->GetCentreOfGravityFromWingLeadingEdge() -
												  _properties->GetAerodynamicCentreFromWingLeadingEdge())) -
			(_tailVolumeRatio*_pCoefficients->GetTailEfficency()*_pCoefficients->GetC_L_alpha_tail()*
			(1 - _downwashChangeDueToAoA));
	}

	double AircraftNonDimensionalDerivatives::GetCm_alpha()
	{
		return _Cm_alpha;
	}

	void AircraftNonDimensionalDerivatives::CalculateCX_alpha_dot()
	{
		_CX_alpha_dot = 0;
	}

	double AircraftNonDimensionalDerivatives::GetCX_alpha_dot()
	{
		return _CX_alpha_dot;
	}

	void AircraftNonDimensionalDerivatives::CalculateCZ_alpha_dot()
	{
		_CZ_alpha_dot = -2*_tailVolumeRatio*_pCoefficients->GetTailEfficency()*_pCoefficients->GetC_L_alpha_tail()*
			_downwashChangeDueToAoA;
	}

	double AircraftNonDimensionalDerivatives::GetCZ_alpha_dot()
	{
		return _CZ_alpha_dot;
	}

	void AircraftNonDimensionalDerivatives::CalculateCm_alpha_dot()
	{
		_Cm_alpha_dot = -2*_tailVolumeRatio*_pCoefficients->GetTailEfficency()*_pCoefficients->GetC_L_alpha_tail()*
			_downwashChangeDueToAoA*(_properties->GetTailMomentArm()/_properties->GetWingChord());
	}

	double AircraftNonDimensionalDerivatives::GetCm_alpha_dot()
	{
		return _Cm_alpha_dot;
	}

	void AircraftNonDimensionalDerivatives::CalculateCZ_delta_elevator()
	{
		_CZ_delta_elevator = -_pCoefficients->GetC_L_alpha_tail()*_properties->GetElevatorFlapEffectivenessParameter()*
			_pCoefficients->GetTailEfficency()*(_properties->GetTailSurfaceArea()/_properties->GetWingSurfaceArea());
	}

	double AircraftNonDimensionalDerivatives::GetCZ_delta_elevator()
	{
		return _CZ_delta_elevator;
	}

	void AircraftNonDimensionalDerivatives::CalculateCm_delta_elevator()
	{
		_Cm_delta_elevator = -_pCoefficients->GetC_L_alpha_tail()*_properties->GetElevatorFlapEffectivenessParameter()*
			_pCoefficients->GetTailEfficency()*_tailVolumeRatio;
	}

	double AircraftNonDimensionalDerivatives::GetCm_delta_elevator()
	{
		return _Cm_delta_elevator;
	}
	

}