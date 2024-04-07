#pragma once

#ifndef VEHICLE_EXPORTS 
#define VEHICLE_API __declspec(dllexport) 
#else 
#define VEHICLE_API __declspec(dllimport) 
#endif

class VEHICLE_API Air_vehicle
{
protected:
	int speed;
	double decrease_path;
public:
	double go(int distance);
};

