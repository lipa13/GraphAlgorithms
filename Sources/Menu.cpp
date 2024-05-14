#include "../Headers/Menu.h"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu(){}

void Menu::displayMenu()
{

}

int Menu::getChoice()
{
    int choice;

    // pętla, która będzie kontynuowana do momentu poprawnego wprowadzenia danych
    while(true)
    {
        cout << "\nWybierz opcje: ";
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
