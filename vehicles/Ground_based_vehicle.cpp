#include "Ground_based_vehicle.h"
#include <iostream>

bool Ground_based_vehicle::isTired(double time, int distance, double total_distance)
{
	if (this->cooldown == cooldown_first_time)
	{
		this->cooldown = cooldown_every_time;
	}
	if (time == this->time_before_rest)
	{
		this->cooldown = cooldown_first_time;
		return true;
	}
	if (time > time_before_rest && (distance % (this->speed * this->time_before_rest) == 0) && distance < total_distance)
	{
		return true;
	}


	return false;
}

double Ground_based_vehicle::go(int total_distance)
{
	double result_time = 0.0;
	double total_distance_d = static_cast<double>(total_distance);

	for (int distance = this->speed; distance <= total_distance_d; distance += this->speed)
	{
		if (isTired(result_time, distance, total_distance_d))//result_time == time_before_rest)
		{
			result_time += cooldown;
		} 
		result_time++;
	}


	return result_time;
}
