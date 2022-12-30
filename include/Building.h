#ifndef BUILDING_H
#define BUILDING_H

#include "Material.h"


class Building
{
public:
	double basePrice;
	char label;
	int length;
	int height;
	Material materials[];
	Building();
	Building(int length, int height);

};
// WASSERKRAFTWERK = 1, WINDKRAFTWERK = 2, SOLARPANELE = 3

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
