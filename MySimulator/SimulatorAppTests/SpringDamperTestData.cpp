/*********************************************************************************************************************/
//
//  SpringDamperTestData.h
//  Class Description: Contains test data for a simple spring damper simulation
//
//  Created by Luke Burlovich on 13/08/2015
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
//
/*********************************************************************************************************************/

#include "SpringDamperTestData.h"

namespace ApplicationTesting
{
	SpringDamperTestData::SpringDamperTestData()
	{
		CreateData();
	}
	SpringDamperTestData::~SpringDamperTestData(){}

	void SpringDamperTestData::AddStateDataToStore(double time, double position, double velocity)
	{
		_testData.insert(std::pair<double,SpringDamperTestData::State>(time, State(position, velocity)));
	}

	void SpringDamperTestData::CreateData()
	{
		AddStateDataToStore(0.0, 0.00603, 0.11836);
		AddStateDataToStore(0.2, 0.04991, 0.30962);
		AddStateDataToStore(0.4, 0.12532, 0.43287);
		AddStateDataToStore(0.6, 0.21844, 0.48716);
		AddStateDataToStore(0.8, 0.31602, 0.47916);
		AddStateDataToStore(1.0, 0.40675, 0.42102);
		AddStateDataToStore(1.2, 0.48210, 0.32808);
		AddStateDataToStore(1.4, 0.53675, 0.21666);
		AddStateDataToStore(1.6, 0.56856, 0.10210);
		AddStateDataToStore(1.8, 0.57825, -0.00268);
		AddStateDataToStore(2.0, 0.56879, -0.08818);
		AddStateDataToStore(2.2, 0.54466, -0.14869);
		AddStateDataToStore(2.4, 0.51112, -0.18222);
		AddStateDataToStore(2.6, 0.47349, -0.19005);
		AddStateDataToStore(2.8, 0.43656, -0.17599);
		AddStateDataToStore(3.0, 0.40419, -0.14554);
		AddStateDataToStore(3.4, 0.36247, -0.06039);
		AddStateDataToStore(4.0, 0.36203, 0.04787);
		AddStateDataToStore(4.6, 0.40233, 0.07176);
		AddStateDataToStore(5.0, 0.42705, 0.04847);
		AddStateDataToStore(5.4, 0.43968, 0.01443);
		AddStateDataToStore(6.0, 0.43567, -0.02275);
	}

	SpringDamperTestData::State SpringDamperTestData::GetStateData(double time)
	{
		State stateResponse = _testData[time];
		
		return stateResponse;
	}

}
