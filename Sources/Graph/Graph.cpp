#include "../../Headers/Graph/Graph.h"

using namespace std;

Graph::Graph(bool isDirected)
    :directed(isDirected), numV(0), numE(0), adjacencyList(numV, directed), incidenceMatrix(numV, numE, directed) {}

bool Graph::isEdgeCorrect(int s, int e)
{
    if(s==e)
    {
        return false;
    }

    for(int j=0; j<numV; j++)
    {
        for(int k=0; k<adjacencyList.numberOfNeighbors[j]; k++)
        {
            if((adjacencyList.data[j][k].startV==s && adjacencyList.data[j][k].endV==e) ||
                (!directed && adjacencyList.data[j][k].startV == e && adjacencyList.data[j][k].endV == s))
            {
                return false;
            }
        }
    }

    return true;
}

void Graph::addEdge(int start, int end, int w)
{
    adjacencyList.addEdge(start, end, w);
    incidenceMatrix.addEdge(start, end, w);
}

bool Graph::loadFromFile(string& path)
{
    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    if(incidenceMatrix.data!= nullptr)
    {
        incidenceMatrix.clearMatrix();
    }

    ifstream file(path);

    // sprawdzenie, czy plik jest otwarty
    if(!file.is_open())
    {
        return false; // jeśli nie to zwraca false
    }

    file >> numE >> numV;

    adjacencyList.initList();
    incidenceMatrix.initMatrix();

    int start, end, weight;

    while(file >> start >> end >> weight)
    {
        addEdge(start, end, weight);
    }

    file.close();
    return true; // zwraca true, jeśli wczytanie danych się powiodło
}

void Graph::generateRandom(int vertices, double d)
{
    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    if(incidenceMatrix.data!= nullptr)
    {
        incidenceMatrix.clearMatrix();
    }

    numV = vertices;
    numE = static_cast<int>(d/100*vertices*(vertices-1)/2);

    adjacencyList.initList();
    incidenceMatrix.initMatrix();

    if(directed)
    {

    }
    else
    {
        // Generowanie minimalnego drzewa rozpinającego dla grafu nieskierowanego
        for (int i=1; i<numV; i++)
        {
            bool correct;
            int start, end, w;

            do
            {
                start = i;
                end = rand()%i;
                w = rand()%numV+1;

                correct = isEdgeCorrect(start, end);

            }while(!correct);

            addEdge(start, end, w);
        }
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

        addEdge(start, end, w);
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
