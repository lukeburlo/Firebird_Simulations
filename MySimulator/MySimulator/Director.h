/*********************************************************************************************************************/
//
//  Director.h
//  Class Description: This is the director class of the builder software creation pattern. The Director is in charge
//                     building the objects that are required for the simulator. The Director class is also a singleton
//                     object.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _Director_h_  
#define _Director_h_    

#include "ISimulatorBuilder.h"

namespace Simulation
{
	class Director
	{
		private:
			static Director* _instance;
			Director();

		public:
			static Director* Instance();
			void Construct(ISimulatorBuilder* builder);
	};
}

#endif