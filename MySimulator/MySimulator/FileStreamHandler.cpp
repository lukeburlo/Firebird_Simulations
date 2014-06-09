/*********************************************************************************************************************/
//
//  FileStreamHandler.cpp
//  Class Description: This class is a base class that handles the simulation results by printing the states to a 
//                     specified file for the simulation.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#include <sstream>
#include "FileStreamHandler.h"
#include "IStateResultHandler.h"
#include "BaseSimulator.h"

namespace Simulation 
{
		FileStreamHandler::FileStreamHandler(BaseSimulator& product) : IStateResultHandler(),
			_product(product)
		{
		
		}

		FileStreamHandler::~FileStreamHandler()
		{
			
		}

		void FileStreamHandler::Handle(double time,  vector<double>& states)
		{
			try
			{
				_product.RecordStates(time, states);
			}
			catch(invalid_argument e)
			{
				stringstream ss;
				ss << "FileStreamHandler::Handle(): No state data for time " << time << 
					"Seconds - " << e.what();
				//TOdo log error
			}
			catch(...)
			{
				stringstream ss;
				ss << "FileStreamHandler::Handle(): No state data for time " << time << 
					"Seconds - unknow issue";
				//TOdo log error
			}

		}
}