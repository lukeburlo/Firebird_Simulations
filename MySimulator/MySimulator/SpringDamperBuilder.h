/*********************************************************************************************************************/
//
//  SpringDamperBuilder.h
//  Class Description: This is the builder class of the builder software creation pattern. The class is responsible
//                     for creating model for a simple spring and damper system.
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _SpringDamperBuilder_h_  
#define _SpringDamperBuilder_h_

#include <fstream>
#include <string>
#include "ISimulatorBuilder.h"
#include "IEoM.h"
#include "IIntegrator.h"
#include "IStateResponseHandler.h"
#include <vector>
#include "ISpringDamperDataRepository.h"

namespace Simulation
{
	class SpringDamperBuilder :public ISimulatorBuilder
	{
		private:
			string _outputFileName;
			BaseSimulator* _pProduct;
			IEoM* _pEoM;
			IStateResponseHandler* _pResultHandler;
			IIntegrator* _pIntergrator;
			ISpringDamperDataRepository* _pDataModel;


		public:
			//remove default
			SpringDamperBuilder();
			SpringDamperBuilder(IStateResponseHandler* pStateHandler);
			virtual ~SpringDamperBuilder();
			void BuildCommandInputs();
			void BuildDataModel();
			void BuildEoM();
			void BuildIntergrator();
			BaseSimulator* GetSimulator();
	};
}

#endif