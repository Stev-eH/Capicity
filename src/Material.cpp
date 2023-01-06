#include "Material.h"

Material::Material()
{
    price = 0.0;
    name = "";
}

Holz::Holz()
{
    price = 30.0;
    name = "Holz";
}

Metall::Metall()
{
    price = 80.0;
    name = "Metall";
}

Kunststoff::Kunststoff()
{
    price = 20.0;
    name = "Kunststoff";
}

// Noetig um Maps zu fuellen
bool Material::operator<(const Material& other) const
{
    if(price < other.price)
        return true;

    return false;
}


