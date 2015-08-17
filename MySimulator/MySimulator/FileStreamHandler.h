/*********************************************************************************************************************/
//
//  FileStreamHandler.h
//  Class Description: This class is a base class that handles the simulation results by printing the states to a 
//                     specified file for the simulation.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _FileStreamHandler_h_  
#define _FileStreamHandler_h_    

#include <sstream>
#include "IStateResponseHandler.h"
#include "BaseSimulator.h"

namespace Simulation 
{
	class FileStreamHandler : public IStateResponseHandler
	{
		protected:
			BaseSimulator& _product;
			FileStreamHandler( FileStreamHandler& other );

		public:
			FileStreamHandler(BaseSimulator& product);
			virtual ~FileStreamHandler();
			virtual void Handle(double time,  vector<double>& states);
	};
}

#endif