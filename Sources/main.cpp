#include <iostream>

#include "../Headers/Menu.h"
#include "../Headers/Graph/Graph.h"

using namespace std;

Menu menu;
Graph graphMST(false);

void chooseShortestPathMenu()
{
    do
    {
        menu.displayShortestPathMenu();
        int choice = menu.getChoice(6);

        if(choice==1)
        {
            // wczytanie grafu z pliku
        }
        else if(choice==2)
        {
            // generowanie losowo grafu
        }
        else if(choice==3)
        {
            // wyswietl graf
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
        }
        else if(choice==2)
        {
            // wygenerowanie grafu losowo
            graphMST.generateRandom(10, 25);
        }
        else if(choice==3)
        {
            // wyswietl graf
            graphMST.adjacencyList.display();
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
    srand(time(NULL));
    chooseMainMenu();
    return 0;
}
