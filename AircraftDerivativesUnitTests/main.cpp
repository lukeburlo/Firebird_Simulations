#include <iostream>
#include "TestAircraftNonDimensionalDerivatives.cpp"

using namespace std;
using namespace AircraftSimulation::UnitTests;

int main()
{
	TestAircraftNonDimensionalDerivatives UT;
	UT.Run();
	 
	cout << "Press any key to exit...";
	cout << endl;
	cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

	return 0;
}