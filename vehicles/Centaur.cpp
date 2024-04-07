#include "Centaur.h"

Centaur::Centaur()
{
	this->speed = 15;
	this->time_before_rest = 8;
	this->cooldown = 0;
	this->cooldown_first_time = 2;
	this->cooldown_every_time = 2;
}
