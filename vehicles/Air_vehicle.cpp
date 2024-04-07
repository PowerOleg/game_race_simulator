#include "Air_vehicle.h"

double Air_vehicle::go(int total_distance)
{
	double result_time = 0.0;
	double total_distance_d = static_cast<double>(total_distance) * this->decrease_path;
	return total_distance_d / static_cast<double>(speed);
}