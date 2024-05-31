#include "../../../Headers/Algorithms/SPA/SPAlgorithm.h"

#include <limits>
#include <iostream>
#include <iomanip>

using namespace std;

SPAlgorithm::SPAlgorithm(Graph& g, int startV, int target) : Algorithm(g), d(nullptr), p(nullptr), s(startV), t(target) {}

SPAlgorithm::~SPAlgorithm()
{
    delete[] d;
    delete[] p;
}

void SPAlgorithm::init()
{
    d = new int[numV];
    p = new int[numV];
}

void SPAlgorithm::start()
{
    for(int i=0; i<numV; i++)
    {
        d[i] = numeric_limits<int>::max();
        p[i] = -1;
    }
    d[s] = 0;
}

void SPAlgorithm::reconstructPath(int target, int*& path, int& pathLength)
{
    pathLength = 0;
    for(int v=target; v!=-1; v=p[v])
    {
        pathLength++;
    }

    path = new int[pathLength];

    int i = pathLength-1;
    for(int v=target; v!=-1; v=p[v])
    {
        path[i--] = v;
    }
}

void SPAlgorithm::displayResult()
{
    cout << "     d[v]   Path\n";
    /*for(int i=0; i<numV; i++)
    {
        int* path;
        int pathLength;
        reconstructPath(i, path, pathLength);

        cout << left << setw(4) << "v" + to_string(i) << " " << right << setw(3) << d[i] << "    ";
        if(d[i]==0)
        {
            cout << "NO PATH (SOURCE)";
        }
        else
        {
            for(int j=0; j<pathLength; j++)
            {
                cout << path[j];
                if(j<pathLength-1)
                {
                    cout << " -> ";
                }
            }
        }
        cout << "\n";
        delete[] path;
    }*/

    int* path;
    int pathLength;
    reconstructPath(t, path, pathLength);

    cout << left << setw(4) << "v" + to_string(t) << " " << right << setw(3) << d[t] << "    ";
    if(d[t]==0)
    {
        cout << "NO PATH (SOURCE)";
    }
    else
    {
        for(int j=0; j<pathLength; j++)
        {
            cout << path[j];
            if(j<pathLength-1)
            {
                cout << " -> ";
            }
        }
    }
    cout << "\n";
    delete[] path;
}
