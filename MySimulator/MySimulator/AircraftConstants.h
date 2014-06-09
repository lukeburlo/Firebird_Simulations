
/*********************************************************************************************************************/
//
//  AircraftConstants.h
//  Class Description: 
//
//  Created by Luke Burlovich on 29/11/2013
//  Version 1.0
//  Firebird - Aerospace Industries. 
//
/*********************************************************************************************************************/

#ifndef _AircraftConstants_h_  
#define _AircraftConstants_h_

namespace AircraftSimulation
{
	enum AircraftType{ NO_AIRCRAFT, BOEING_747_100 };

	//Standard Constants
	#define PI						3.1415
	#define RAD_TO_DEG				180/PI

	//Aircraft Velocity Varible Defintions
	#define VELOCITY_U				0
	#define VELOCITY_V				4
	#define VELOCITY_W				1

	//Aircraft Angular Velocity Varible Defintions
	#define VELOCITY_P				5
	#define VELOCITY_Q				2
	#define VELOCITY_R				6

	//Aircraft Attitide Varible Defintions
	#define PSI						8
	#define THETA					3  	
	#define PHI						7

	//Aircraft Position Varible Defintions
	#define POSITION_X				9
	#define POSITION_Y				10  	
	#define POSITION_Z				11


	enum AircraftInputType { ELEVATOR = 0 , THROTTLE = 1, ALERION = 2, RUDDER = 3 };
}

#endif