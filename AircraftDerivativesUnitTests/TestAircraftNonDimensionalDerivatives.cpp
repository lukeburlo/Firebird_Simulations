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
				void UTest1GetCZ_q()
				{
					AircraftCoefficientsMock mock;
					mock.TailEfficency = 1;
					mock.C_L_alpha_tail = 3.5;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, _pProperties);
					
					double CZ_q = NonDimensionalDerivatives.GetCZ_q();
					UTASSERT<double>("UTest1GetCz_q()", -7.86, CZ_q );
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
					UTest1GetCZ_q();
					UTest1GetCm_q();
					UTest1GetCZ_alpha_dot();
					UTest1GetCm_alpha_dot();
				}

		
		};
	}
}