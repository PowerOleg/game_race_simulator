#pragma once
#include "Ground_based_vehicle.h"

#ifndef VEHICLE_EXPORTS 
#define VEHICLE_API __declspec(dllexport) 
#else 
#define VEHICLE_API __declspec(dllimport) 
#endif

class VEHICLE_API Fast_moving_camel : public Ground_based_vehicle
{
private:
	double cooldown_second_time;
public:
	Fast_moving_camel();
	bool isTired(double time, int distance, double total_distance) override;
};

