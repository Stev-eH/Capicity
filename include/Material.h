#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
    public:
        double price;
        Material();
        getPrice();
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
