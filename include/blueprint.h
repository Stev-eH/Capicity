#ifndef BLUEPRINT_H
#define BLUEPRINT_H

#include "Building.h"


class Blueprint
{
public:
	Blueprint();
	~Blueprint();
	bool operator==(const Blueprint& other);
	int getX() const{return x;}
	int getY() const{return y;}
    int getVar(int type, bool isX);
	void setBuilding(bool place);
	Building* getArea() const{return area;}
	float calcKennzahl();

protected:
    int x;
	int y;
    Building* area;

private:
};

#endif // BLUEPRINT_H
