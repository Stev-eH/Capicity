#include "Building.h"
#include "Material.h"

#include <iostream>

Building::Building()
{
	basePrice = 0.0;
	label = '0';
	numElementsPerUnit = 0;
	isEmpty = true;
	name = "Empty";
}

Wasserkraftwerk::Wasserkraftwerk()
{
	basePrice = 4300.5;
	label = '~';
	numElementsPerUnit = 3;
	isEmpty = false;
	name = "Wasserkraftwerk";
	materialsPerUnit = {Holz(), Holz(), Metall()};
}

Windkraftwerk::Windkraftwerk()
{
	basePrice = 13000.0;
	label = 'x';
	numElementsPerUnit = 5;
	isEmpty = false;
	name = "Windkraftwerk";
	materialsPerUnit = {Metall(), Metall(), Metall(), Kunststoff(), Holz()};
}

Solarpanel::Solarpanel()
{
	basePrice = 5000.0;
	label = '#';
	numElementsPerUnit = 4;
	isEmpty = false;
	name = "Solarpanel";
	materialsPerUnit = {Kunststoff(), Kunststoff(), Kunststoff(), Metall()};
}

double Building::getPriceTotal()
{
	double sum = basePrice;

		for(int i = 0; i < numElementsPerUnit; i++)
		{
			sum += materialsPerUnit.at(i).getPrice();
		}
	return sum;
}

std::string Building::toString()
{
	std::string output = getName();
	output += " Preis: ";
	output += std::to_string(getBasePrice());
	output += " Materialien: ";


		for(int i = 0; i < numElementsPerUnit; i++)
		{
		    output += materialsPerUnit.at(i).getName();
		    output += " ";
		}

		return output;

}
