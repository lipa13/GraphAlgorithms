#ifndef AIZO_PROJEKT_2_MENU_H
#define AIZO_PROJEKT_2_MENU_H

class Menu //
{
public:
    Menu();
    void displayMainMenu(); // wyświetl menu główne
    void displayMSTMenu(); // wyświetl menu mst
    void displayShortestPathMenu(); // wyświetl menu spa
    int getChoice(int n); // pobierz wybór od użytkownika
};

#endif //AIZO_PROJEKT_2_MENU_H
