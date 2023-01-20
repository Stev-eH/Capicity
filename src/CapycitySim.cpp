#include "CapycitySim.h"

#include <iostream>

using namespace std;

CapycitySim::CapycitySim()
{
	currentPlan = new Blueprint();
}

CapycitySim::~CapycitySim()
{
}

void CapycitySim::showMenu()
{
	int choice = 0;
	while (true)
	{
		cout << "1. Gebaeude setzen" << endl;
		cout << "2. Bereich loeschen" << endl;
		cout << "3. Ausgeben des aktuellen Bauplans" << endl;
		cout << "4. Ausgeben aller gespeicherten Plaene" << endl;
		cout << "5. Erstellen eines neuen Plans" << endl;
		cout << "6. Beenden" << endl;
		cout << "Bitte auswaehlen: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//    Gebäude setzen(mit darauffolgender Nachfrage nach Art, Länge, Breite und Position)
			currentPlan->setBuilding(true);
			break;
		case 2:
			//    Bereich löschen(Betroffene Gebäude sollen nicht gelöscht, sondern dadurch nur verkleinert werden)
			currentPlan->setBuilding(false);
			break;
		case 3:
			//    Ausgeben des aktuellen Bauplans
			drawField(true);
			break;
		case 4:
			printAll();
			break;
		case 5:
			newPlan();
			break;
		case 6:
			//    Beenden des Programms
			cout << "Auf Wiedersehen!";
			return;
			break;
		default:
			choice = 0;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
} // showMenu()

void CapycitySim::drawField(bool extra)
{
	Building* area = currentPlan->getArea();
	int x = currentPlan->getX();
	int y = currentPlan->getY();
	int priceTotal = 0;
	// Ausgeben der Kennzahl
	cout << currentPlan->calcKennzahl() << endl;
	for (int i = 0; i < y; i++)
	{
		cout << endl;
		for (int j = 0; j < x; j++)
		{
			cout << area[(i * x) + j].getLabel() << " ";
			if(!area[(i * x) + j].isEmpty)
			{
				priceTotal += area[(i * x) + j].getBasePrice();
			}
		}
	}
	cout << endl;
//Erweitere das Ausdrucken des Plans um die Darstellung der Gebäude mit ihren Labels, einer
//Auflistung der Gebäude sowie deren benötigter Materialien, dem Einzelpreis eines Gebäudes
//sowie dem Gesamtpreis von allen Gebäuden
	if(extra)
	{
		for(int i = 0; i < y; i++)
		{
			for(int j = 0; j < x; j++)
			{
				if(!area[(i * x) + j].isEmpty)
				{
					cout << endl;
					cout << "x: " << j << " y: " << i << " " << area[(i * x) + j].toString();
				}
			}
		}
		cout << endl << endl << "Gesamtpreis: " << priceTotal << endl;
	}
} // drawField()

void CapycitySim::newPlan()
{
	bool sameExists = false;
	for (int i = 0; i < blueprints.size(); ++i)
	{
		if(*currentPlan == blueprints[i])
			sameExists = true;
	}
	if(!sameExists)
	{
		blueprints.push_back(*currentPlan);
	}

        currentPlan = new Blueprint();
}

void CapycitySim::printAll()
{
    cout << "Aktueller Plan" << endl;
    drawField(false);
    cout << endl;
    Blueprint* temp  = currentPlan;
//
//    auto bubbleSort= [](Blueprint& comp, Blueprint& other){return comp.calcKennzahl() < other.calcKennzahl();};
//    for(int i = 0; i < blueprints.size() - 1; i++)
//    {
//        for(int j = i+1; j < blueprints.size(); j++)
//        {
//            if(bubbleSort)
//            {
//                std::swap(blueprints[i], blueprints[j]);
//            }
//        }
//    }

// Konnte es mit dem sortieren nicht lösen
    for(int k = 0; k < blueprints.size() ; k++)
    {
        currentPlan = &blueprints[k];
        drawField(false);
        cout << endl;
    }

    currentPlan = temp;
}



