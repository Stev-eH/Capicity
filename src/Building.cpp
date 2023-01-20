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
<<<<<<< HEAD
    //Changed prices and power for better Identifier calculation
	basePrice = 430.5;
	label = '~';
	numElementsPerUnit = 3;
	isEmpty = false;
	name = "Wasserkraftwerk";
	leistung = 100000;
	materialsPerUnit = {Holz(), Holz(), Metall()};
	materialien.insert({Holz(), 2});
	materialien.insert({Metall(), 1});
=======
    basePrice = 4300.5;
    label = '~';
    numElementsPerUnit = 3;
    isEmpty = false;
    name = "Wasserkraftwerk";
    materialsPerUnit = {Holz(), Holz(), Metall()};
    materialien.insert({Holz(), 2});
    materialien.insert({Metall(), 1});
>>>>>>> parent of d947e68 (Start Aufgabe 4)
}

Windkraftwerk::Windkraftwerk()
{
<<<<<<< HEAD
	basePrice = 1300.0;
	label = 'x';
	numElementsPerUnit = 5;
	isEmpty = false;
	name = "Windkraftwerk";
	leistung = 80000;
	materialsPerUnit = {Metall(), Metall(), Metall(), Kunststoff(), Holz()};
	materialien.insert({Metall(), 3});
	materialien.insert({Kunststoff(), 1});
	materialien.insert({Holz(), 1});
=======
    basePrice = 13000.0;
    label = 'x';
    numElementsPerUnit = 5;
    isEmpty = false;
    name = "Windkraftwerk";
    materialsPerUnit = {Metall(), Metall(), Metall(), Kunststoff(), Holz()};
    materialien.insert({Metall(), 3});
    materialien.insert({Kunststoff(), 1});
    materialien.insert({Holz(), 1});
>>>>>>> parent of d947e68 (Start Aufgabe 4)
}

Solarpanel::Solarpanel()
{
<<<<<<< HEAD
	basePrice = 500.0;
	label = '#';
	numElementsPerUnit = 4;
	isEmpty = false;
	name = "Solarpanel";
	leistung = 120000;
	materialsPerUnit = {Kunststoff(), Kunststoff(), Kunststoff(), Metall()};
	materialien.insert({Kunststoff(), 3});
	materialien.insert({Metall(), 1});
=======
    basePrice = 5000.0;
    label = '#';
    numElementsPerUnit = 4;
    isEmpty = false;
    name = "Solarpanel";
    materialsPerUnit = {Kunststoff(), Kunststoff(), Kunststoff(), Metall()};
    materialien.insert({Kunststoff(), 3});
    materialien.insert({Metall(), 1});
>>>>>>> parent of d947e68 (Start Aufgabe 4)
}

double Building::getPriceTotal()
{
	double sum = basePrice;
	for(std::map<Material, int>::iterator it = materialien.begin(); it != materialien.end(); it++)
	{
		for(int i = 0; i < it->second; i++)
		{
			sum += it->first.getPrice();
		}
		return sum;
	}
}

std::string Building::toString()
{
	std::string output = getName();
	output += " Preis: ";
	output += std::to_string(getBasePrice());
	output += " Materialien: ";
	for(std::map<Material, int>::iterator it = materialien.begin(); it != materialien.end(); it++)
	{
		for(int i = 0; i < it->second; i++)
		{
			output += it->first.getName();
			output += " ";
		}
	}
	return output;
}
