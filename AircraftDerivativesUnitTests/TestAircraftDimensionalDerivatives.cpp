#include "AircraftCoefficientsMock.h"
#include "AircraftDimensionalDerivatives.h"

namespace AircraftSimulation
{
	namespace UnitTests
	{
		class TestAircraftDimensionalDerivatives
		{

			private:
				IAircraftCoefficients* _pAircraftCoefficientsMock;
				void Prepare()
				{
					_pAircraftCoefficientsMock = new AircraftCoefficientsMock();
					
				}
				void TearDown();

			public:
				TestAircraftDimensionalDerivatives(){}
				~TestAircraftDimensionalDerivatives(){}

				void TestGetX_u()
				{
					
					AircraftCoefficientsMock m;
					/*m.C_D_0 =1;*/


					IAircraftCoefficients* _pM =  (IAircraftCoefficients*) &m;
					AircraftDimensionalDerivatives d(_pM);
					double i = d.GetX_u();
					
				}


		};
	}
}