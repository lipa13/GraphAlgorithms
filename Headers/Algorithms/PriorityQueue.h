#ifndef AIZO_PROJEKT_2_PRIORITYQUEUE_H
#define AIZO_PROJEKT_2_PRIORITYQUEUE_H

// struktura reprezentująca węzeł kopca
struct HeapNode
{
    int v; // wierzchołek
    int key; // klucz (priorytet)
};

// klasa reprezentująca kolejkę priorytetową w postaci kopca
class PriorityQueue
{
    HeapNode* queue; // tablica reprezentująca kolejkę priorytetową
    int* vPos; // tablica pomocnicza przechowująca pozycje wierzchołków w kolejce
    int currentSize; // aktualny rozmiar kolejki
    int maxSize; // maksymalny rozmiar kolejki
    void fix_down(int p); // metoda naprawy kopca w dół
    void fix_up(int i); // metoda naprawy kopca w górę

public:
    void init(); // inicjalizacja kolejki priorytetowej
    PriorityQueue(int s);
    void clear(); // czyszczenie kolejki priorytetowej
    ~PriorityQueue();

    void insertKey(int v, int key); // wstawienie klucza do kolejki
    void decreaseKey(int v, int key); // zmniejszenie klucza w kolejce
    HeapNode extractMin(); // wyciągnięcie minimalnego klucza z kolejki
    bool isInQueue(int v) const; // sprawdzenie, czy wierzchołek jest w kolejce
    bool isEmpty() const; // sprawdzenie, czy kolejka jest pusta
};

#endif //AIZO_PROJEKT_2_PRIORITYQUEUE_H
