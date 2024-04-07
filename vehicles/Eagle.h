#pragma once
#include "Air_vehicle.h"

#ifndef VEHICLE_EXPORTS 
#define VEHICLE_API __declspec(dllexport) 
#else 
#define VEHICLE_API __declspec(dllimport) 
#endif

class VEHICLE_API Eagle : public Air_vehicle
{
public:
	Eagle();
};

