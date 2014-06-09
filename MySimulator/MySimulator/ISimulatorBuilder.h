/*********************************************************************************************************************/
//
//  ISimulatorBuilder.h
//  Class Description:  This is the interface is part of the builder software creation pattern.This interface is used 
//                      to define a type of simulator that will be built.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _ISimulatorBuilder_h_  
#define _ISimulatorBuilder_h_

#include "BaseSimulator.h"

namespace Simulation
{
	class ISimulatorBuilder
	{

		public:
			virtual void BuildCommandInputs() = 0;
			virtual void BuildDataModel() = 0;
			virtual void BuildEoM() = 0;
			virtual void BuildIntergrator() = 0;
			virtual BaseSimulator* GetResult() = 0;

	};
}

#endif