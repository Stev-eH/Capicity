#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Material.h"


class Building
{
public:
	double basePrice;
	char label;
	int length;
	int height;
	int areaSize;
	int numElementsPerUnit;
	std::vector<Material> materialsPerUnit;
	Building();
	Building(int length, int height);
	double getBasePrice() {return basePrice;}
	double getPriceTotal();
};
// WASSERKRAFTWERK = 1, WINDKRAFTWERK = 2, SOLARPANELE = 3

class Wasserkraftwerk : public Building
{
public:
	Wasserkraftwerk(int length, int height);
};

class Windkraftwerk : public Building
{
public:
    Windkraftwerk(int length, int height);
};

class Solarpanel : public Building
{
public:
    Solarpanel(int length, int height);
};

#endif // BUILDING_H
