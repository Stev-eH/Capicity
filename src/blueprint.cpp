#include <iostream>
#include "blueprint.h"

using namespace std;

Blueprint::Blueprint()
{
	x = getVar(0, true);
	y = getVar(0, false);
	area = new Building[y * x];
	// init area
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			area[(i * x) + j] = Building();
		}
	}
}

Blueprint::~Blueprint()
{

}

void Blueprint::setBuilding(bool place)
{
	bool invalid = true;
	int choice = 0;
	int buildX = 0;
	int buildY = 0;
	int posX = 0;
	int posY = 0;
	//    Gebäude setzen(mit darauffolgender Nachfrage nach Art, Länge, Breite und Position)
	// WASSERKRAFTWERK = 1, WINDKRAFTWERK = 2, SOLARPANELE = 3
	// Gebaeude plazieren
	if (place)
	{
		// Auswahl eines Gebaeudes
		while (invalid)
		{
			cout << "Welche Art von Gebaeude moechten Sie setzen?" << endl;
			cout << "1. Wasserkraftwerk" << endl;
			cout << "2. Windkraftwerk" << endl;
			cout << "3. Solarpanele" << endl;
			cout << "Bitte waehlen Sie: ";
			cin >> choice;
			if (choice > 0 && choice <= 3)
			{
				invalid = false;
			}
			else
			{
				cout << "Ihre Eingabe war fehlerhaft, bitte probieren Sie es noch einmal" << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
		}
		buildX = getVar(1, true);
		buildY = getVar(1, false);
	}
	// Gebaeude entfernen
	else
	{
		buildX = getVar(2, true);
		buildY = getVar(2, false);
	}
	posX = getVar(3, true);
	posY = getVar(3, false);
	if (posX > x || posY > y)
	{
		cout << "Ungueltige Position!! Der Baumodus wird beendet.." << endl;
	}
	else if (posX + buildX - 1 > x || posY + buildY - 1 > y)
	{
		if (place)
		{
			cout << "Das Gebaeude ragt ueber die Baugrenzen hinaus!! Der Baumodus wird beendet.." << endl;
		}
		else
		{
			cout << "Sie befinden sich ausserhalb der Baugrenzen!! Der Baumodus wird beendet.." << endl;
		}
	}
	else
	{
		for (int k = 0; k < 2; k++)
		{
			bool full = false;
			for (int i = 0; i < buildY; i++)
			{
				for (int j = 0; j < buildX; j++)
				{
					if (place)
					{
						// Mit getLabel wird die Gebaeudeart ueberprueft
						if (k == 0 && area[(i * x + posY * x) + j + posX].getLabel() != '0')
						{
							full = true;
							cout << "In dem momentanem Baubereich steht schon ein Gebaeude!!" << endl;
						}
						else if (k == 1 && full == false)
						{
							if(choice == 1)
							{
								area[(i * x + posY * x) + j + posX] = Wasserkraftwerk();
							}
							else if(choice == 2)
							{
								area[(i * x + posY * x) + j + posX] = Windkraftwerk();
							}
							else if(choice == 3)
							{
								area[(i * x + posY * x) + j + posX] = Solarpanel();
							}
							else
								;// Unreachable
						}
					}
					else
					{
						area[(i * x + posY * x) + j + posX] = Building();
					}
				}
			}
		}
	}
} // setBuilding()

int Blueprint::getVar(int type, bool isX)
{
	string heightOrLength = "";
	int var = 1000;
	if(isX)
		heightOrLength = "Laenge";
	else
		heightOrLength = "Hoehe";
	while (var == 1000)
	{
		// mit type wird die Art der Ausgabe geaendert
		// 0 = Bauflaeche
		if (type == 0)
		{
			cout << "Bitte die " << heightOrLength << " der Bauflaeche angeben: ";
		}
		else if (type == 1)
		{
			cout << "Bitte die " << heightOrLength << " des Gebaeudes angeben: ";
		}
		else if (type == 2)
		{
			cout << "Bitte die " << heightOrLength << " des zu entfernenden Baubereichs angeben: ";
		}
		else
		{
			if(isX)
				cout << "Bitte x-Position angeben: ";
			else
				cout << "Bitte y-Position angeben: ";
		}
		cin >> var;
		// Falls faulty-Input
		cin.clear();
		cin.ignore(100, '\n');
	}
	return var;
} // getVar()

float Blueprint::calcKennzahl()
{
	float totalPriceBuildings = 0;
	float totalPowerBuildings = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if(!area[(i * x) + j].isEmpty)
			{
				totalPriceBuildings += area[(i * x) + j].getPriceTotal();
				totalPowerBuildings += area[(i * x) + j].getLeistung();
			}
		}
	}
	//Abfangen Division by 0
	if((totalPriceBuildings * (x * y)) == 0)
	{
		return 0;
	}
	return ((totalPowerBuildings) / (totalPriceBuildings * (x * y)));
} // calcKennzahl()

bool Blueprint::operator==(const Blueprint& other)
{
	if((getX() == other.getX()) && (getY() == other.getY()))
	{
		bool areEqual = true;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if(area[(i * x) + j].getLabel() != other.area[(i * x) + j].getLabel())
					areEqual = false;
			}
		}
		return areEqual;
	}
	else
	{
		return false;
	}
}
