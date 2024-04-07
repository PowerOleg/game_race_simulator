#pragma once

#ifndef VEHICLE_EXPORTS 
#define VEHICLE_API __declspec(dllexport) 
#else 
#define VEHICLE_API __declspec(dllimport) 
#endif

class VEHICLE_API Ground_based_vehicle
{
protected:
	int speed;
	int time_before_rest;
	double cooldown;
	int cooldown_first_time;
	int cooldown_every_time;
public:
	double go(int distance);
	virtual bool  isTired(double time, int distance, double total_distance);
};

