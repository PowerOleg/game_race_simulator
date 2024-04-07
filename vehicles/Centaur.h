#pragma once
#include "Ground_based_vehicle.h"

#ifndef VEHICLE_EXPORTS 
#define VEHICLE_API __declspec(dllexport) 
#else 
#define VEHICLE_API __declspec(dllimport) 
#endif

class VEHICLE_API Centaur : public Ground_based_vehicle
{
public:
	Centaur();
};

