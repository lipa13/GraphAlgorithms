#include <iostream>
#include <chrono>

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

void executeTests()
{
    Graph testGraphMST(false);
    Graph testGraphSPA(true);

    // Testy dla algorytmu Prima
    cout << "\nTESTY ALGORYTM PRIMA\n";
    for(int i=20; i<150; i+=20)
    {
        cout << "\n=== " << i << " wierzcholkow ===\n";
        for(int j=0; j<3; j++)
        {
            double d=0;

            if(j==0)
            {
                d=25;
            }
            else if(j==1)
            {
                d=50;
            }
            else if(j==2)
            {
                d=99;
            }
            cout << "\n--- gestosc " << d << "% ---\n";

            double sumListTests=0, sumMatrixTests=0;

            for(int k=0; k<50; k++)
            {
                double  listTest=0, matrixTest=0;

                testGraphMST.generateRandom(i, d);
                PrimAlgorithm testPrim(testGraphMST);

                chrono::high_resolution_clock::time_point start, end;

                // Reprezentacja listowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testPrim.runList();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                listTest = chrono::duration<double, micro>(end - start).count();
                sumListTests += chrono::duration<double, micro>(end - start).count();

                // Reprezentacja macierzowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testPrim.runMatrix();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                matrixTest = chrono::duration<double, micro>(end - start).count();
                sumMatrixTests += chrono::duration<double, micro>(end - start).count();

                cout << "test " << k+1 << "| L: " << listTest << "us  M: " << matrixTest << "us" << endl;
            }

            cout << "srednia z 50 testow| L: " << sumListTests/50 << "us  M: " << sumMatrixTests/50 << "us" << endl;
        }
    }

    // Testy dla algorytmu Kruskala
    cout << "\nTESTY ALGORYTM KRUSKALA\n";
    for(int i=20; i<150; i+=20)
    {
        cout << "\n=== " << i << " wierzcholkow ===\n";
        for(int j=0; j<3; j++)
        {
            double d=0;

            if(j==0)
            {
                d=25;
            }
            else if(j==1)
            {
                d=50;
            }
            else if(j==2)
            {
                d=99;
            }
            cout << "\n--- gestosc " << d << "% ---\n";

            double sumListTests=0, sumMatrixTests=0;

            for(int k=0; k<50; k++)
            {
                double  listTest=0, matrixTest=0;

                testGraphMST.generateRandom(i, d);
                KruskalAlgorithm testKruskal(testGraphMST);

                chrono::high_resolution_clock::time_point start, end;

                // Reprezentacja listowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testKruskal.runList();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                listTest = chrono::duration<double, micro>(end - start).count();
                sumListTests += chrono::duration<double, micro>(end - start).count();

                // Reprezentacja macierzowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testKruskal.runMatrix();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                matrixTest = chrono::duration<double, micro>(end - start).count();
                sumMatrixTests += chrono::duration<double, micro>(end - start).count();

                cout << "test " << k+1 << "| L: " << listTest << "us  M: " << matrixTest << "us" << endl;
            }

            cout << "srednia z 50 testow| L: " << sumListTests/50.0 << "us  M: " << sumMatrixTests/50.0 << "us" << endl;
        }
    }

    // Testy dla algorytmu Dijkstry
    cout << "\nTESTY ALGORYTM DIJKSTRY\n";
    for(int i=20; i<150; i+=20)
    {
        cout << "\n=== " << i << " wierzcholkow ===\n";
        for(int j=0; j<3; j++)
        {
            double d=0;

            if(j==0)
            {
                d=25;
            }
            else if(j==1)
            {
                d=50;
            }
            else if(j==2)
            {
                d=99;
            }
            cout << "\n--- gestosc " << d << "% ---\n";

            double sumListTests=0, sumMatrixTests=0;

            for(int k=0; k<50; k++)
            {
                double  listTest=0, matrixTest=0;

                testGraphSPA.generateRandom(i, d);
                int randStart = rand()%i;
                DijkstraAlgorithm testDijkstra(testGraphSPA, randStart ,0);

                chrono::high_resolution_clock::time_point start, end;

                // Reprezentacja listowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testDijkstra.runList();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                listTest = chrono::duration<double, micro>(end - start).count();
                sumListTests += chrono::duration<double, micro>(end - start).count();

                // Reprezentacja macierzowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testDijkstra.runMatrix();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                matrixTest = chrono::duration<double, micro>(end - start).count();
                sumMatrixTests += chrono::duration<double, micro>(end - start).count();

                cout << "test " << k+1 << "| L: " << listTest << "us  M: " << matrixTest << "us" << endl;
            }

            cout << "srednia z 50 testow| L: " << sumListTests/50 << "us  M: " << sumMatrixTests/50 << "us" << endl;
        }
    }

    // Testy dla algorytmu Bellmana-Forda
    cout << "\nTESTY ALGORYTM BELLMANA-FORDA\n";
    for(int i=20; i<150; i+=20)
    {
        cout << "\n=== " << i << " wierzcholkow ===\n";
        for(int j=0; j<3; j++)
        {
            double d=0;

            if(j==0)
            {
                d=25;
            }
            else if(j==1)
            {
                d=50;
            }
            else if(j==2)
            {
                d=99;
            }
            cout << "\n--- gestosc " << d << "% ---\n";

            double sumListTests=0, sumMatrixTests=0;

            for(int k=0; k<50; k++)
            {
                double  listTest=0, matrixTest=0;

                testGraphSPA.generateRandom(i, d);
                int randStart = rand()%i;
                BellmanFordAlgorithm testBellmanFord(testGraphSPA, randStart ,0);

                chrono::high_resolution_clock::time_point start, end;

                // Reprezentacja listowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testBellmanFord.runList();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                listTest = chrono::duration<double, micro>(end - start).count();
                sumListTests += chrono::duration<double, micro>(end - start).count();

                // Reprezentacja macierzowa
                start = chrono::high_resolution_clock::now(); // pierwszy pomiar - start
                testBellmanFord.runMatrix();
                end = chrono::high_resolution_clock::now(); // drugi pomiar - koniec

                matrixTest = chrono::duration<double, micro>(end - start).count();
                sumMatrixTests += chrono::duration<double, micro>(end - start).count();

                cout << "test " << k+1 << "| L: " << listTest << "us  M: " << matrixTest << "us" << endl;
            }

            cout << "srednia z 50 testow| L: " << sumListTests/50 << "us  M: " << sumMatrixTests/50 << "us" << endl;
        }
    }
}

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
            executeTests();
        }
        else if(choice==4)
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
