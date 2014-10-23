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

			public:
				TestAircraftNonDimensionalDerivatives(){}
				~TestAircraftNonDimensionalDerivatives(){}

				void UTest1GetCX_u()
				{
					AircraftCoefficientsMock mock;
					mock.C_D_0 = 0.057;
					mock.C_D_M = 0;
					mock.C_T_U = -0.057;

					AircraftProperties properties;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, properties);

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
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.9, properties);

					double CX_u = NonDimensionalDerivatives.GetCX_u();
					
					UTASSERT<double>("UTest2GetCX_u()", -0.309, CX_u);
				}
				void UTest1GetCZ_uForIncompressableFlow()
				{
					AircraftCoefficientsMock mock;
					mock.C_L_0 = 0.77;

					AircraftProperties properties;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, properties);

					double CZ_u = NonDimensionalDerivatives.GetCZ_u();
					
					UTASSERT<double>("UTest1GetCZ_uForIncompressableFlow()", -1.54, CZ_u);
				}
				void UTest1GetCZ_uForCompressableFlow()
				{
					AircraftCoefficientsMock mock;
					mock.C_L_0 = 0.77;

					AircraftProperties properties;

					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.5, properties);

					double CZ_u = NonDimensionalDerivatives.GetCZ_u();
					
					UTASSERT<double>("UTest1GetCZ_uForCompressableFlow()", -1.79667, CZ_u);
				}
				void UTest1GetCm_u()
				{
					AircraftCoefficientsMock mock;
					mock.dC_m_dM = 2;

					AircraftProperties properties;
			
					IAircraftCoefficients* _pMock =  (IAircraftCoefficients*) &mock;
					AircraftNonDimensionalDerivatives NonDimensionalDerivatives(_pMock, 0.158, properties);

					double Cm_u = NonDimensionalDerivatives.GetCm_u();
					
					UTASSERT<double>("UTest1GetCm_u()", 0.316, Cm_u);
				}

		};
	}
}