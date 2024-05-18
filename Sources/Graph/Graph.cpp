#include "../../Headers/Graph/Graph.h"

using namespace std;

Graph::Graph(bool isDirected):directed(isDirected), numV(0), numE(0), adjacencyList(numV, directed) {}

bool Graph::isEdgeCorrect(int s, int e)
{
    bool correct = true;

    if(s==e)
    {
        correct=false;
    }
    else
    {
        for(int j=0; j<adjacencyList.numberOfNeighbors[j]; j++)
        {
            for(int k=0; k<adjacencyList.numberOfNeighbors[j]; k++)
            {
                if((adjacencyList.data[j][k].startV==s && adjacencyList.data[j][k].endV==e) ||
                   (adjacencyList.data[j][k].endV==s && adjacencyList.data[j][k].startV==e))
                {
                    correct=false;
                    break;
                }
            }

            if(!correct)
            {
                break;
            }
        }
    }

    return correct;
}

bool Graph::loadFromFile(string& path)
{
    ifstream file(path);

    // sprawdzenie, czy plik jest otwarty
    if(!file.is_open())
    {
        return false; // jeśli nie to zwraca false
    }

    file >> numE >> numV;

    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    adjacencyList.initList();

    int start, end, weight;

    while(file >> start >> end >> weight)
    {
        adjacencyList.addEdge(start, end, weight);
    }

    file.close();
    return true; // zwraca true, jeśli wczytanie danych się powiodło
}

void Graph::generateRandom(int vertices, double d)
{
    numV = vertices;
    numE = static_cast<int>(d/100*vertices*(vertices-1)/2);

    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    adjacencyList.initList();

    // Generowanie minimalnego drzewa rozpinającego
    for (int i=1; i<numV; i++)
    {
        bool correct;
        int start, end, w;

        do
        {
            start = i;
            end = rand()%i;
            w = rand()%numV;

            correct = isEdgeCorrect(start, end);

        }while(!correct);

        adjacencyList.addEdge(start, end, w);
    }

    // Dokładanie krawędzi do określonej gęstości
    for(int i=numV-1; i<numE; i++)
    {
        bool correct;
        int start, end, w;

        do
        {
            start = rand()%numV;
            end = rand()%numV;
            w = rand()%numV+1;

            correct = isEdgeCorrect(start, end);

        }while(!correct);

        adjacencyList.addEdge(start, end, w);
    }
}

int Graph::getNumV()
{
    return numV;
}

int Graph::getNumE()
{
    return numE;
}
