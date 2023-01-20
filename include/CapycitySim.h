#ifndef CAPYCITYSIM_H
#define CAPYCITYSIM_H

#include <vector>
#include "blueprint.h"
#include "Building.h"
#include "Material.h"


class CapycitySim
{
    public:
    std::vector<Blueprint> blueprints;
    Blueprint* currentPlan;
        CapycitySim();
        ~CapycitySim();


        void drawField(bool extra);
        void showMenu();
        void newPlan();
        void printAll();
};

#endif // CAPYCITYSIM_H
