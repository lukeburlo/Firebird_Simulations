/*********************************************************************************************************************/
//
//  TestTools.cpp
//  Class Description: Contains helper functions and tools for automated testing
//
//  Created by Luke Burlovich on 21/08/2015
//  Firebird - Aerospace Industries. 
//
//
/*********************************************************************************************************************/

#include <iostream>
#include <cmath> 
#include <iomanip>

#include"TestTools.h"

namespace FirebirdTest
{

	TestTools::TestTools(){}

	TestTools::~TestTools(){}

	template< typename T> 
	bool TestTools::IsEqual(T x, T y)
	{
	  const double epsilon = 1e-3;
	  return std::abs(x - y) <= epsilon * std::abs(x);
	}

	template< typename T> 
	void TestTools::Assert(std::string testName, T expected, T actual)
	{
		cout << "Test: " <<  testName << " ";

		if(IsEqual<T>(expected,actual))
		{
			cout << "PASSED." <<endl;
		}
		else
		{
			cout << "*** FAILED *** .... Expected: " << expected << " Actual: " << actual <<endl;
		}
	}
}