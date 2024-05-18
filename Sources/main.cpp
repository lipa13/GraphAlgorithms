#include <iostream>

#include "../Headers/Menu.h"
#include "../Headers/Graph/Graph.h"

using namespace std;

Menu menu;
Graph graphMST(false);
Graph graphSPA(true);

void chooseShortestPathMenu()
{
    do
    {
        menu.displayShortestPathMenu();
        int choice = menu.getChoice(6);

        if(choice==1)
        {
            // wczytanie grafu z pliku
            string path;
            cout << "\nPodaj pelna sciezke pliku: ";
            cin >> path;

            if(!graphSPA.loadFromFile(path))
            {
                cout << "\nNie udalo sie wczytac danych.\n";
            }
            else
            {
                cout << "\nDane poprawnie wczytane.\n";
            }

        }
        else if(choice==2)
        {
            // generowanie losowo grafu
            int v;
            double d;

            cout << "\nPodaj liczbe wierzcholkow: ";
            cin >> v;
            cout << "Podaj gestosc grafu: ";
            cin >> d;

            graphSPA.generateRandom(v, d);
        }
        else if(choice==3)
        {
            // wyswietl graf
            if(graphSPA.adjacencyList.data!=nullptr)
            {
                graphSPA.adjacencyList.display();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
        }
        else if(choice==4)
        {
            // algorytm dijkstry
        }
        else if(choice==5)
        {
            // algorytm bellmana-forda
        }
        else if(choice==6)
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }

    }while(true);
}

void chooseMSTMenu()
{
    do
    {
        menu.displayMSTMenu();
        int choice = menu.getChoice(6);

        if(choice==1)
        {
            // wczytanie grafu z pliku
            string path;
            cout << "\nPodaj pelna sciezke pliku: ";
            cin >> path;

            if(!graphMST.loadFromFile(path))
            {
                cout << "\nNie udalo sie wczytac danych.\n";
                return;
            }
            else
            {
                cout << "\nDane poprawnie wczytane.\n";
            }

        }
        else if(choice==2)
        {
            // wygenerowanie grafu losowo
            int v;
            double d;

            cout << "\nPodaj liczbe wierzcholkow: ";
            cin >> v;
            cout << "Podaj gestosc grafu: ";
            cin >> d;

            graphMST.generateRandom(v, d);
        }
        else if(choice==3)
        {
            // wyswietl graf
            if(graphMST.adjacencyList.data!=nullptr)
            {
                graphMST.adjacencyList.display();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
        }
        else if(choice==4)
        {
            // algorytm prima
        }
        else if(choice==5)
        {
            // algorytm kruskala
        }
        else if(choice==6)
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }

    }while(true);
}

void chooseMainMenu()
{
    do
    {
        menu.displayMainMenu();
        int choice = menu.getChoice(3);

        if(choice==1)
        {
            chooseMSTMenu();
        }
        else if(choice==2)
        {
            chooseShortestPathMenu();
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }

    }while(true);
}

int main()
{
    srand(time(nullptr));
    chooseMainMenu();
    return 0;
}
