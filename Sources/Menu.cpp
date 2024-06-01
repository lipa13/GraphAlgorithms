#include "../Headers/Menu.h"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu(){}

void Menu::displayMainMenu()
{
    cout << "\n=====================================================\n";
    cout << "                     MENU GLOWNE\n";
    cout << "=====================================================\n";
    cout << "1. Wyznaczanie minimalnego drzewa rozpinajacego (MST)\n";
    cout << "2. Wyznaczanie najkrotszej sciezki w grafie (SPA)\n";
    cout << "3. Testy\n";
    cout << "4. Wyjscie\n";
    cout << "=====================================================\n";
}

void Menu::displayMSTMenu()
{
    cout << "\n===========================================\n";
    cout << "                 MENU MST\n";
    cout << "===========================================\n";
    cout << "1. Wczytaj dane z pliku\n";
    cout << "2. Wygeneruj graf losowo\n";
    cout << "3. Wyswietl graf (listowo i macierzowo)\n";
    cout << "4. Algorytm Prima (listowo i macierzowo)\n";
    cout << "5. Algorytm Kruskala (listowo i macierzowo)\n";
    cout << "6. Powrot do menu glownego\n";
    cout << "===========================================\n";
}

void Menu::displayShortestPathMenu()
{
    cout << "\n=================================================\n";
    cout << "             MENU NAJKROTSZA SCIEZKA\n";
    cout << "=================================================\n";
    cout << "1. Wczytaj dane z pliku\n";
    cout << "2. Wygeneruj graf losowo\n";
    cout << "3. Wyswietl graf (listowo i macierzowo)\n";
    cout << "4. Algorytm Dijkstry (listowo i macierzowo)\n";
    cout << "5. Algorytm Bellmana-Forda (listowo i macierzowo)\n";
    cout << "6. Powrot do menu glownego\n";
    cout << "=================================================\n";
}

int Menu::getChoice(int n)
{
    int choice;

    // pętla, która będzie kontynuowana do momentu poprawnego wprowadzenia danych
    while(true)
    {
        cout << "\nWybierz opcje " << "(1-" << n << "): ";
        cin >> choice;

        // warunek sprawdzający czy zostały poprawnie wpisane dane
        if(cin.fail())
        {
            cin.clear(); // usunięcie flagi błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignorowanie pozostałych danych w buforze
                                                                          // do końca linii
            cout << "\nNieprawidlowe dane. Wprowadz liczbe!!!";
        }
        else
        {
            break; // koniec pętli po wpisaniu poprawnych danych
        }
    }

    return choice;
}
