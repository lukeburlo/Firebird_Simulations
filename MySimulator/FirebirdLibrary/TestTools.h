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
	class TestTools
	{
		public:
			TestTools();
			~TestTools();
			template< typename T> 
			bool IsEqual(T x, T y);
			template< typename T> 
			void Assert(std::string testName, T expected, T actual);
	};
}

#endif