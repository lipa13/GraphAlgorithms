#include "../../Headers/Algorithms/PriorityQueue.h"

#include <limits>
#include <algorithm>

using namespace std;

void PriorityQueue::init()
{
    queue = new HeapNode[maxSize];
    vPos = new int[maxSize];
}

PriorityQueue::PriorityQueue(int s): currentSize(0), maxSize(s)
{
    init();
}

void PriorityQueue::clear()
{
    delete[] queue;
    delete[] vPos;
}

PriorityQueue::~PriorityQueue()
{
    clear();
}

void PriorityQueue::fix_up(int i)
{
    // naprawa kopca w górę, aby zachować właściwości kopca
    while(i>0 && queue[i].key<queue[(i-1)/2].key)
    {
        // aktualizowanie pozycji wierzchołków w kopcu
        vPos[queue[i].v] = (i-1)/2;
        vPos[queue[(i-1)/2].v] = i;
        swap(queue[i], queue[(i-1)/2]); // zamiana elementów kopca
        i = (i-1)/2; // aktualizacja wartości indeksu
    }
}

void PriorityQueue::insertKey(int v, int key)
{
    // wstawienie nowego klucza do kolejki
    currentSize++; // zwiększenie aktualnego rozmiaru
    // wstawienie klucza na ostatnie miejsce w kolejce
    int i = currentSize-1;
    queue[i] = {v,key};
    vPos[v] = i;

    fix_up(i); // naprawa kopca, żeby ustawić nowy klucz w odpowiednim miejscu
}

void PriorityQueue::decreaseKey(int v, int key)
{
    // zmniejszenie klucza dla danego wierzchołka
    int i = vPos[v];
    queue[i].key = key;

    // naprawa kopca w górę
    fix_up(i);
}

HeapNode PriorityQueue::extractMin()
{
    // wyciągnięcie minimalnego elementu z kopca
    if(currentSize==0)
    {
        return{-1, numeric_limits<int>::max()}; // zwrócenie maksymalnej wartości int, jeśli kopiec jest pusty
    }

    HeapNode root = queue[0];
    swap(queue[0], queue[currentSize-1]); // zamiana korzenia z ostatnim elementem
    vPos[queue[0].v] = 0; // aktualizacja zapisanej pozycji dla nowego korzenia
    vPos[queue[currentSize-1].v]=currentSize-1; // aktualizacja zapisanej pozycji dla węzła, który usuwamy z kolejki
    currentSize--; // zmniejszenie aktualnego rozmiaru kolejki

    fix_down(0); // naprawa kopca w dół

    return root; // zwrócenie minimalnego węzła, który usunęliśmy z kolejki
}

void PriorityQueue::fix_down(int p)
{
    int parent = p; // przypisanie wartości indeksu rodzica
    int left = 2*p+1; // obliczenie indeksu lewego potomka
    int right = 2*p+2; // obliczenie indeksu prawego potomka

    // jeśli mieścimy się w zakresie i key ordzica jest wieksze od potomka to indeks rodzica staje się indeksem potomka
    if(left<currentSize && queue[left].key<queue[parent].key)
    {
        parent = left;
    }

    if(right<currentSize && queue[right].key<queue[parent].key)
    {
        parent = right;
    }

    // jęsli indeks rodzica się zmieniamy pozycje z określonym potomkiem i przywracamy właściwosci kopca
    if(parent!=p)
    {
        vPos[queue[parent].v] = p;
        vPos[queue[p].v] = parent;
        swap(queue[parent], queue[p]);
        fix_down(parent);
    }
}

bool PriorityQueue::isInQueue(int v) const
{
    return vPos[v]<currentSize;
}

bool PriorityQueue::isEmpty() const
{
    return currentSize == 0;
}
