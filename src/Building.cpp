#include "Building.h"

Building::Building()
{
    Building(0, 0);
}

Building::Building(int length, int height)
{
    basePrice = 0.0;
	label = '.';
	this->length = length;
	this->height = height;
}
