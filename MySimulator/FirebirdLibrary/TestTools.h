/*********************************************************************************************************************/
//
//  TestTools.h
//  Class Description: Contains helper functions and tools for automated testing
//
//  Created by Luke Burlovich on 21/08/2015
//  Firebird - Aerospace Industries. 
//
//
/*********************************************************************************************************************/

#ifndef _TestTools_h_  
#define _TestTools_h_  

#include <string>

namespace FirebirdTest
{
	class  TestTools
	{
		private:
			TestTools();
			~TestTools();

		public:
			template< typename T> 
			static bool IsEqual(T x, T y);
			template< typename T> 
			static void Assert(std::string testName, T expected, T actual);
	};

	//Template instantiations
	template bool TestTools::IsEqual(int, int);
	template bool TestTools::IsEqual(double, double);
	template void TestTools::Assert(std::string, int, int);
	template void TestTools::Assert(std::string, double, double);
}

#endif