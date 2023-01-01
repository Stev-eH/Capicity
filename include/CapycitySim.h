#ifndef CAPYCITYSIM_H
#define CAPYCITYSIM_H

enum gebaeude { LEER = 0, WASSERKRAFTWERK = 1, WINDKRAFTWERK = 2, SOLARPANELE = 3 };

class CapycitySim
{
    public:
        gebaeude* area;
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
