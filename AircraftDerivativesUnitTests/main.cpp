#include <iostream>
#include "TestAircraftNonDimensionalDerivatives.cpp"

using namespace std;
using namespace AircraftSimulation::UnitTests;

int main()
{
	TestAircraftNonDimensionalDerivatives UT;
	UT.UTest1GetCX_u();
	UT.UTest2GetCX_u();
	UT.UTest1GetCZ_uForIncompressableFlow();
	UT.UTest1GetCZ_uForCompressableFlow();
	UT.UTest1GetCm_u();
	 
	cout << "Press any key to exit...";
	cout << endl;
	cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

	return 0;
}