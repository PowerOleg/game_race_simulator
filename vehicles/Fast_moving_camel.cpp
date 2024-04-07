#include "Fast_moving_camel.h"

Fast_moving_camel::Fast_moving_camel()
{
	this->speed = 40;
	this->time_before_rest = 10;
	this->cooldown = 0;
	this->cooldown_first_time = 5;
	this->cooldown_second_time = 6.5;
	this->cooldown_every_time = 8;
}

bool Fast_moving_camel::isTired(double time, int distance, double total_distance)
{
	if (time == this->time_before_rest)
	{
		this->cooldown = cooldown_first_time;
		return true;
	}
	if (time > time_before_rest && (distance % (this->speed * this->time_before_rest) == 0) && distance < total_distance)
	{
		if (this->cooldown == cooldown_second_time)
		{
			this->cooldown = cooldown_every_time;
		}
		if (this->cooldown == cooldown_first_time)
		{
			this->cooldown = cooldown_second_time;
		}
		return true;
	}


	return false;
}

