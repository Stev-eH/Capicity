#include "Material.h"

Material::Material()
{
    price = 0.0;
}

Material::getPrice() {return price;}

Holz::Holz()
{
    price = 30.0;
}

Metall::Metall()
{
    price = 80.0;
}

Kunststoff::Kunststoff()
{
    price = 20.0;
}


