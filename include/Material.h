#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

class Material
{
public:
	Material();
	std::string getName() const
	{
		return name;
	}
double getPrice() const
	{
		return price;
	}
	bool operator<(const Material& other) const;
protected:
	double price;
	std::string name;
};

class Holz : public Material
{
public:
	Holz();
};

class Metall : public Material
{
public:
	Metall();
};

class Kunststoff : public Material
{
public:
	Kunststoff();
};

#endif // MATERIAL_H
