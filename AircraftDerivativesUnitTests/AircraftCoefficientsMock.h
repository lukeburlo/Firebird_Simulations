#include <string>
#include <iostream>
#include <cmath> 
#include <iomanip>

#include "IAircraftCoefficients.h"

using namespace std;

static void UTASSERT(string testName, bool testPassed)
{
	cout << "Test: " << testName << " "; 
	if(testPassed)
	{
		cout << "PASSED." <<endl;
	}
	else
	{
		cout << "FAILED." <<endl;
	}

}



template< typename T> bool isEqual(T x, T y)
{
  const double epsilon = 1e-3;
  return std::abs(x - y) <= epsilon * std::abs(x);
}

template< typename T> static void UTASSERT(string testName, T expected, T actual)
{
	cout << "Test: " <<  testName << " ";

	if(isEqual<T>(expected,actual))
	//if(expected == actual)
	{
		cout << "PASSED." <<endl;
	}
	else
	{
		cout << "*** FAILED *** .... Expected: " << expected << " Actual: " << actual <<endl;
	}

}

namespace AircraftSimulation
{
	namespace UnitTests
	{
		class AircraftCoefficientsMock : public IAircraftCoefficients
		{
			public:
				 float TailEfficency;
				 double C_D_0;
				 double C_D_M;
				 double C_T_U;
				 double C_L_0;
				 double dC_m_dM;
				 double C_L_alpha_tail;
				 double C_L_alpha_wing;
				 double C_L_alpha_fuselage;

				 float GetTailEfficency(){ return TailEfficency; }
				 double GetC_D_0(){ return C_D_0; }
				 double GetC_D_M(){ return C_D_M; }
				 double GetC_T_U(){ return C_T_U; }
				 double GetC_L_0(){ return C_L_0; }
				 double GetdC_m_dM(){ return dC_m_dM; }
				 double GetC_L_alpha_tail(){ return C_L_alpha_tail; }
				 double GetC_L_alpha_wing(){ return C_L_alpha_wing; }
				 double GetC_L_alpha_fuselage(){ return C_L_alpha_fuselage; }
				  
		};
	}
}