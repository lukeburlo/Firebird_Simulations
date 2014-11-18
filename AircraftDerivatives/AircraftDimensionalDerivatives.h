/*********************************************************************************************************************/
//
//  AircraftDimensionalDerivatives.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftDimensionalDerivatives_h_  
#define _AircraftDimensionalDerivatives_h_    

#include "IAircraftCoefficients.h"
//#include "IAircraft.h"


namespace AircraftSimulation
{
	class AircraftDimensionalDerivatives //: IAircraft
	{
		private:
			IAircraftCoefficients* _pCoefficients;

			void CalculateX_u();
			double X_u;

		protected:
			void Calculate();

		public:
			AircraftDimensionalDerivatives(IAircraftCoefficients* coefficients);
			virtual ~AircraftDimensionalDerivatives();

			/*virtual int GetWeight();

			virtual double GetI_x() = 0; 
			virtual double GetI_y() = 0; 
			virtual double GetI_z() = 0; 
			virtual double GetI_zx() = 0; */

			
			virtual double GetX_u(); 
	};
}

#endif