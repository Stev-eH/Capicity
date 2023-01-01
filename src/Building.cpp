#include "Building.h"
#include "Material.h"

#include <iostream>

Building::Building()
{
    Building(0, 0);
}

Building::Building(int length, int height)
{
    basePrice = 0.0;
	label = '.';
	numElementsPerUnit = 0;
	this->length = length;
	this->height = height;
	areaSize = length * height;
}

Wasserkraftwerk::Wasserkraftwerk(int length, int height)
{
    basePrice = 4300.5;
    label = '~';
    numElementsPerUnit = 3;
    this->length = length;
	this->height = height;
	materialsPerUnit = {Holz(), Holz(), Metall()};
	areaSize = length * height;
}

Windkraftwerk::Windkraftwerk(int length, int height)
{
    basePrice = 13000.0;
    label = 'x';
    numElementsPerUnit = 5;
    this->length = length;
	this->height = height;
	materialsPerUnit = {Metall(), Metall(), Metall(), Kunststoff(), Holz()};
areaSize = length * height;
}

Solarpanel::Solarpanel(int length, int height)
{
    basePrice = 5000.0;
    label = '#';
    numElementsPerUnit = 4;
    this->length = length;
	this->height = height;
	materialsPerUnit = {Kunststoff(), Kunststoff(), Kunststoff(), Metall()};
areaSize = length * height;
}

double Building::getPriceTotal()
{
    double sum = basePrice;

    for(int i = 0; i < areaSize ; i++)
    {
        for(int j = 0; j < numElementsPerUnit; j++)
        {
            sum += materialsPerUnit.at(j).getPrice();
        }
    }

    return sum;
}
