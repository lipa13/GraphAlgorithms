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
    while(i && queue[i].key<queue[(i-1)/2].key)
    {
        vPos[queue[i].v] = (i-1)/2;
        vPos[queue[(i-1)/2].v] = i;
        swap(queue[i], queue[(i-1)/2]);
        i = (i-1)/2;
    }
}

void PriorityQueue::insertKey(int v, int key)
{
    currentSize++;
    int i = currentSize-1;
    queue[i] = {v,key};
    vPos[v] = i;

    fix_up(i);
}

void PriorityQueue::decreaseKey(int v, int key)
{
    int i = vPos[v];
    queue[i].key = key;

    fix_up(i);
}

HeapNode PriorityQueue::extractMin()
{
    if(currentSize==0)
    {
        return{-1, numeric_limits<int>::max()};
    }

    HeapNode root = queue[0];
    HeapNode lastNode = queue[currentSize-1];
    queue[0] = lastNode;
    vPos[lastNode.v] = 0;
    vPos[root.v]=currentSize-1;
    currentSize--;

    fix_down(0);

    return root;
}

void PriorityQueue::fix_down(int p)
{
    int parent = p;
    int left = 2*p+1;
    int right = 2*p+2;

    if(left<currentSize && queue[left].key<queue[parent].key)
    {
        parent = left;
    }

    if(right<currentSize && queue[right].key<queue[parent].key)
    {
        parent = right;
    }

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
