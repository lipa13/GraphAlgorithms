#ifndef AIZO_PROJEKT_2_PRIORITYQUEUE_H
#define AIZO_PROJEKT_2_PRIORITYQUEUE_H

struct HeapNode
{
    int v;
    int key;
};

class PriorityQueue
{
    HeapNode* queue;
    int* vPos;
    int currentSize;
    int maxSize;
    void fix_down(int p);
    void fix_up(int i);

public:
    void init();
    PriorityQueue(int s);
    void clear();
    ~PriorityQueue();

    void insertKey(int v, int key);
    void decreaseKey(int v, int key);
    HeapNode extractMin();
    bool isInQueue(int v) const;
    bool isEmpty() const;
};

#endif //AIZO_PROJEKT_2_PRIORITYQUEUE_H
