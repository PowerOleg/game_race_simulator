#include "Camel.h"
Camel::Camel()
{
	this->speed = 10;
	this->time_before_rest = 30;
	this->cooldown = 0;
	this->cooldown_first_time = 5;
	this->cooldown_every_time = 8;
}