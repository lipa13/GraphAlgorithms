#include <iostream>

#include "../Headers/Menu.h"
#include "../Headers/Graph/Graph.h"
#include "../Headers/Algorithms/MST/PrimAlgorithm.h"
#include "../Headers/Algorithms/MST/KruskalAlgorithm.h"
#include "../Headers/Algorithms/SPA/DijkstraAlgorithm.h"
#include "../Headers/Algorithms/SPA/BellmanFordAlgorithm.h"

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
                graphSPA.incidenceMatrix.display();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
        }
        else if(choice==4)
        {
            if(graphSPA.adjacencyList.data!=nullptr)
            {
                int startV, target;

                cout << "\nPodaj wierzcholek poczatkowy: ";
                cin >> startV;
                cout << "Podaj wierzcholek koncowy: ";
                cin >> target;

                // algorytm Dijkstry
                cout<<"\nWYNIKI ALGORYTM DIJKSTRY\n";
                DijkstraAlgorithm dijkstraAlgorithm(graphSPA, startV, target);

                dijkstraAlgorithm.runList();
                cout<<"\nReprezentacja listowa\n";
                dijkstraAlgorithm.displayResult();

                dijkstraAlgorithm.runMatrix();
                cout<<"\nReprezentacja macierzowa\n";
                dijkstraAlgorithm.displayResult();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
        }
        else if(choice==5)
        {
            if(graphSPA.adjacencyList.data!=nullptr)
            {
                int startV, target;

                cout << "Podaj wierzcholek poczatkowy: ";
                cin >> startV;
                cout << "Podaj wierzcholek koncowy: ";
                cin >> target;

                // algorytm bellmana-forda
                cout<<"\nWYNIKI ALGORYTM BELLMANA-FORDA\n";
                BellmanFordAlgorithm bellmanFordAlgorithm(graphSPA, startV, target);

                bellmanFordAlgorithm.runList();
                cout<<"\nReprezentacja listowa\n";
                bellmanFordAlgorithm.displayResult();

                bellmanFordAlgorithm.runMatrix();
                cout<<"\nReprezentacja macierzowa\n";
                bellmanFordAlgorithm.displayResult();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
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
                graphMST.incidenceMatrix.display();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
        }
        else if(choice==4)
        {
            // algorytm Prima
            if(graphMST.adjacencyList.data != nullptr)
            {
                cout<<"\nWYNIKI ALGORYTM PRIMA\n";
                PrimAlgorithm primAlgorithm(graphMST);

                primAlgorithm.runList();
                cout<<"\nReprezentacja listowa\n";
                primAlgorithm.displayResult();

                primAlgorithm.runMatrix();
                cout<<"\nReprezentacja macierzowa\n";
                primAlgorithm.displayResult();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
        }
        else if(choice==5)
        {
            // algorytm Kruskala
            if(graphMST.adjacencyList.data != nullptr)
            {
                cout<<"\nWYNIKI ALGORYTM KRUSKALA\n";
                KruskalAlgorithm kruskalAlgorithm(graphMST);

                kruskalAlgorithm.runList();
                cout<<"\nReprezentacja listowa\n";
                kruskalAlgorithm.displayResult();

                kruskalAlgorithm.runMatrix();
                cout<<"\nReprezentacja macierzowa\n";
                kruskalAlgorithm.displayResult();
            }
            else
            {
                cout << "\nNie wczytano jeszcze danych!!!\n";
            }
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
