#include "AircraftCoefficientsMock.h"
#include "AircraftNonDimensionalDerivatives.h"
#include "AircraftProperties.h"

namespace AircraftSimulation
{
	namespace UnitTests
	{

		class TestAircraftNonDimensionalDerivatives
		{

			private:
				IAircraftProperties* _pProperties;

				void UTest1GetCX_u()
				{
					AircraftCoefficientsMock mock;
					mock.C_D_0 = 0.057;
					mock.C_D_M = 0;
					mock.C_T_U = -0.057;
					

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);

					double CX_u = NonDimensionalDerivatives.GetCX_u();

					
					UTASSERT<double>("UTest1GetCX_u()", -0.171, CX_u);
					
					
				}
				void UTest2GetCX_u()
				{
					AircraftCoefficientsMock mock;
					mock.C_D_0 = 0.042;
					mock.C_D_M = 0.25;
					mock.C_T_U = 0;

					AircraftProperties properties;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.9, _pProperties);

					double CX_u = NonDimensionalDerivatives.GetCX_u();
					
					UTASSERT<double>("UTest2GetCX_u()", -0.309, CX_u);
				}
				void UTest1GetCZ_uForIncompressableFlow()
				{
					AircraftCoefficientsMock mock;
					mock.C_L_0 = 0.77;

					AircraftProperties properties;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);

					double CZ_u = NonDimensionalDerivatives.GetCZ_u();
					
					UTASSERT<double>("UTest1GetCZ_uForIncompressableFlow()", -1.54, CZ_u);
				}
				void UTest1GetCZ_uForCompressableFlow()
				{
					AircraftCoefficientsMock mock;
					mock.C_L_0 = 0.77;

					AircraftProperties properties;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.5, _pProperties);

					double CZ_u = NonDimensionalDerivatives.GetCZ_u();
					
					UTASSERT<double>("UTest1GetCZ_uForCompressableFlow()", -1.79667, CZ_u);
				}
				void UTest1GetCm_u()
				{
					AircraftCoefficientsMock mock;
					mock.dC_m_dM = 2;

					AircraftProperties properties;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);

					double Cm_u = NonDimensionalDerivatives.GetCm_u();
					
					UTASSERT<double>("UTest1GetCm_u()", 0.316, Cm_u);
				}
				void UTest1GetCX_q()
				{
					AircraftCoefficientsMock mock;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CX_q = NonDimensionalDerivatives.GetCX_q();
					UTASSERT<double>("UTest1GetCX_q()", 0, CX_q );
				}
				void UTest1GetCZ_q()
				{
					AircraftCoefficientsMock mock;
					mock.TailEfficency = 1;
					mock.C_L_alpha_tail = 3.5;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CZ_q = NonDimensionalDerivatives.GetCZ_q();
					UTASSERT<double>("UTest1GetCZ_q()", -7.86, CZ_q );
				}
				void UTest1GetCm_q()
				{
					AircraftCoefficientsMock mock;
					mock.TailEfficency = 1;
					mock.C_L_alpha_tail = 3.5;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double Cm_q = NonDimensionalDerivatives.GetCm_q();
					UTASSERT<double>("UTest1GetCm_q()",-35.8, Cm_q);
				}
				void UTest1GetCX_alpha()
				{
					AircraftCoefficientsMock mock;
					mock.C_L_0 = 0.77;
					mock.C_L_alpha_wing = 5.2;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CX_alpha = NonDimensionalDerivatives.GetCX_alpha();
					UTASSERT<double>("UTest1GetCX_alpha()", 0.421, CX_alpha);
				}
				void UTest1GetCZ_alpha()
				{
					AircraftCoefficientsMock mock;
					mock.C_D_0 = 0.057;
					mock.C_L_alpha_wing = 5.2;
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CZ_alpha = NonDimensionalDerivatives.GetCZ_alpha();
					UTASSERT<double>("UTest1GetCZ_alpha()", -5.26, CZ_alpha);
				}
				void UTest1GetCm_alpha()
				{
					AircraftCoefficientsMock mock;
					mock.TailEfficency = 1.0;
					mock.C_L_alpha_wing = 5.2;
					mock.C_L_alpha_tail = 3.5;
					mock.C_L_alpha_fuselage = 0.93;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double Cm_alpha = NonDimensionalDerivatives.GetCm_alpha();
					UTASSERT<double>("UTest1GetCm_alpha()", -0.885, Cm_alpha);
				}
				void UTest1GetCX_alpha_dot()
				{
					AircraftCoefficientsMock mock;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CX_alpha_dot = NonDimensionalDerivatives.GetCX_alpha_dot();
					UTASSERT<double>("UTest1GetCX_alpha_dot()", 0, CX_alpha_dot);
				}
				void UTest1GetCZ_alpha_dot()
				{
					AircraftCoefficientsMock mock;
					mock.TailEfficency = 1.0;
					mock.C_L_alpha_wing = 5.2;
					mock.C_L_alpha_tail = 3.5;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CZ_alpha_dot = NonDimensionalDerivatives.GetCZ_alpha_dot();
					UTASSERT<double>("UTest1GetCZ_alpha_dot()", -2.67, CZ_alpha_dot);
				}
				void UTest1GetCm_alpha_dot()
				{
					AircraftCoefficientsMock mock;
					mock.TailEfficency = 1.0;
					mock.C_L_alpha_wing = 5.2;
					mock.C_L_alpha_tail = 3.5;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double Cm_alpha_dot = NonDimensionalDerivatives.GetCm_alpha_dot();
					UTASSERT<double>("UTest1GetCm_alpha_dot()", -12.16, Cm_alpha_dot);
				}
				void UTest1GetCZ_delta_elevator()
				{
					AircraftCoefficientsMock mock;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CZ_delta_elevator = NonDimensionalDerivatives.GetCZ_delta_elevator();
					UTASSERT<double>("UTest1GetCZ_delta_elevator()", -0.46, CZ_delta_elevator);
				}
				void UTest1GetCm_delta_elevator()
				{
					AircraftCoefficientsMock mock;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double Cm_delta_elevator = NonDimensionalDerivatives.GetCm_delta_elevator();
					UTASSERT<double>("UTest1GetCZ_delta_elevator()", -2.09, Cm_delta_elevator);
				}

			public:
				TestAircraftNonDimensionalDerivatives()
				{
					_pProperties = new AircraftProperties();
				}
				~TestAircraftNonDimensionalDerivatives()
				{
					if (_pProperties !=0) delete _pProperties;
				}

				void Run()
				{
					UTest1GetCX_u();
					UTest2GetCX_u();
					UTest1GetCZ_uForIncompressableFlow();
					UTest1GetCZ_uForCompressableFlow();
					UTest1GetCm_u();
					UTest1GetCX_q();
					UTest1GetCZ_q();
					UTest1GetCm_q();
					UTest1GetCX_alpha();
					UTest1GetCZ_alpha();
					UTest1GetCm_alpha();
					UTest1GetCX_alpha_dot();
					UTest1GetCZ_alpha_dot();
					UTest1GetCm_alpha_dot();
					UTest1GetCZ_delta_elevator();
					UTest1GetCm_delta_elevator();
				}

		};
	}
}