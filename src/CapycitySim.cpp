#include "CapycitySim.h"

#include <iostream>

using namespace std;

CapycitySim::CapycitySim()
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

CapycitySim::~CapycitySim()
{
	delete[] area;
}

void CapycitySim::showMenu()
{
	int choice = 0;
	cout << "Wilkommen beim Capybara-Bausimulator" << endl;
	while (true)
	{
		cout << "1. Gebaeude setzen" << endl;
		cout << "2. Bereich loeschen" << endl;
		cout << "3. Ausgeben des aktuellen Bauplans" << endl;
		cout << "4. Beenden" << endl;
		cout << "Bitte auswaehlen: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//    Gebäude setzen(mit darauffolgender Nachfrage nach Art, Länge, Breite und Position)
			setBuilding(true);
			break;
		case 2:
			//    Bereich löschen(Betroffene Gebäude sollen nicht gelöscht, sondern dadurch nur verkleinert werden)
			setBuilding(false);
			break;
		case 3:
			//    Ausgeben des aktuellen Bauplans
			drawField();
			break;
		case 4:
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

void CapycitySim::drawField()
{
	int priceTotal = 0;
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
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < x; j++)
		{
			if(!area[(i * x) + j].isEmpty)
			{

                		cout << endl;
				cout << "x: " << j << " y: " << i << " "<< area[(i * x) + j].toString();
			}
		}
	}
	cout << endl << endl << "Gesamtpreis: " << priceTotal << endl;
} // drawField()

void CapycitySim::setBuilding(bool place)
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
}

int CapycitySim::getVar(int type, bool isX)
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

