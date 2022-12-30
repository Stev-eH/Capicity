// Capcity.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

using namespace std;

// Init Enum
//      LEER = 0
//      WASSERKRAFTWERK = 1
//      WINDKRAFTWERK = 2
//      SOLARPANELE = 3

enum gebaeude { LEER = 0, WASSERKRAFTWERK = 1, WINDKRAFTWERK = 2, SOLARPANELE = 3 };

int getX(int type);
int getY(int type);
void drawField(gebaeude* feld, int x, int y);
void showMenu(gebaeude* bauFeld, int x, int y);
void setBuilding(gebaeude* bauFeld,int x,int y, bool place);


int main()
{
// Testarea
    ////Test getSize
    //int area[2] = { 0 };
    //area[0] = getSizeX();
    //area[1] = getSizeY();
    //cout << "x = " << area[0] << " y = " << area[1] << endl;
    const int x = getX(00);
    const int y = getY(0);

    //Erstellung eines Arrays, welches den Baubereich repräsentiert.Elemente sollen dabei ein Enum sein,
    //welcher den Gebäudetypen darstellt(bzw.ein Feld als leer darstellt, wenn sich auf einer Position kein
    //    Gebäude befindet)
    //
    gebaeude* area = new gebaeude[y * x];

    // init area
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            // Ich wusste nicht wie Zweidimensionale Arrays in C++ gehen :(
            area[(i * x) + j] = LEER;
        }
    }

    //drawField(area, x, y);
    showMenu(area, x, y);




} // main()

//Erhalt der Länge und Breite des Baubereichs als Argument über die Kommandozeile.
// Als zwei Funktionen
int getX(int type = 2)
{
    int x = 1000;
    while (x == 1000)
    {
        if (type == 0)
        {
            cout << "Bitte die Laenge der Bauflaeche angeben: ";
        }
        else if (type == 1)
        {
            cout << "Bitte die Laenge des Gebaeudes angeben: ";
        }
        else if (type == 2)
        {
            cout << "Bitte die Laenge des zu entfernenden Baubereichs angeben: ";
        }
        else
        {
            cout << "Bitte x-Position angeben: ";
        }
        cin >> x;

        // Falls faulty-Input
        cin.clear();
        cin.ignore(100, '\n');
    }
    return x;
} // getSizeX()

int getY(int type = 2)
{
    int y = 1000;
    while (y == 1000)
    {
        if (type == 0)
        {
            cout << "Bitte die Hoehe der Bauflaeche angeben: ";
        }
        else if (type == 1)
        {
            cout << "Bitte die Hoehe des Gebaeudes angeben: ";
        }
        else if (type == 2)
        {
            cout << "Bitte die Hoehe des zu entfernenden Baubereichs angeben: ";
        }
        else
        {
            cout << "Bitte y-Position angeben: ";
        }
        cin >> y;
        cin.clear();
        cin.ignore(100, '\n');
    }
    return y;
} // getSizeY()

//    Ausgeben des aktuellen Bauplans
void drawField(gebaeude* feld, int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        cout << endl;
        for (int j = 0; j < x; j++)
        {
            switch (feld[(i * x) + j])
            {
            case 0:
                cout << "0";
                break;
            case 1:
                cout << "~";
                break;
            case 2:
                cout << "x";
                break;
            case 3:
                cout << "#";
                break;
            }

        }
    }
    cout << endl << endl;
} // drawField()

//    Anzeige eines Menüs mit folgenden Einträgen und dahinterstehender Funktionalität
void showMenu(gebaeude* bauFeld, int x, int y)
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
            setBuilding(bauFeld, x, y, true);
            break;
        case 2:
            //    Bereich löschen(Betroffene Gebäude sollen nicht gelöscht, sondern dadurch nur verkleinert werden)
            setBuilding(bauFeld, x, y, false);
            break;
        case 3:
            //    Ausgeben des aktuellen Bauplans
            drawField(bauFeld, x, y);
            break;
        case 4:
            //    Beenden des Programms
            cout << "Auf Wiedersehen!";
            return;
            break;
        default:
            choice = 0;
        }
        cin.clear();
        cin.ignore(100, '\n');
    }

}

void setBuilding(gebaeude* bauFeld, int x, int y, bool place)
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
        buildX = getX(1);
        buildY = getY(1);
    }

    // Gebaeude entfernen
    else
    {
        buildX = getX(2);
        buildY = getY(2);
    }


    posX = getX();
    posY = getY();

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
                        if (k == 0 && bauFeld[(i * x + posY * x) + j + posX] != LEER)
                        {
                            full = true;
                            cout << "In dem momentanem Baubereich steht schon ein Gebaeude!!" << endl;
                        }
                        else if (k == 1 && full == false)
                        {
                            bauFeld[(i * x + posY * x) + j + posX] = gebaeude(choice);
                        }
                    }
                    else
                    {
                        bauFeld[(i * x + posY * x) + j + posX] = LEER;
                    }
                }
            }
        }
    }

    return;

}


//
//    Prüfung ob Teile eines zu bauenden Gebäudes mit anderen Gebäuden kollidiert oder außerhalb des
//    Baubereichs liegt
//
