#ifndef CAPYCITYSIM_H
#define CAPYCITYSIM_H

#include "Building.h"
#include "Material.h"


class CapycitySim
{
    public:
        Building* area;
        int x;
        int y;

        //TO-DO:
        //  Zuweisungsoperator
        //  Kopierkonstruktor
        CapycitySim();
        ~CapycitySim();
        int getVar(int type, bool isX);
        void drawField();
        void showMenu();
        void setBuilding(bool place);
};

#endif // CAPYCITYSIM_H
