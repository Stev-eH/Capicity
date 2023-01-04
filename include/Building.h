#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Material.h"
#include <string>


class Building
{
public:
	Building();
	double getBasePrice() {return basePrice;}
	double getPriceTotal();
	char getLabel() {return label;}
		bool isEmpty;
		std::string toString();
		std::string getName() {return name;}
protected:
    	double basePrice;
	char label;
	int length;
	int height;
	int areaSize;
	int numElementsPerUnit;
	std::string name;
	std::vector<Material> materialsPerUnit;

};

class Wasserkraftwerk : public Building
{
public:
	Wasserkraftwerk();
};

class Windkraftwerk : public Building
{
public:
    Windkraftwerk();
};

class Solarpanel : public Building
{
public:
    Solarpanel();
};

#endif // BUILDING_H
