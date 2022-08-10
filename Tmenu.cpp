//
// Created by PiotrCiosmak on 10.08.2022.
//

#include "Tmenu.hpp"
#include <iostream>
#include "Tmen.hpp"
#include "Twomen.hpp"

using namespace std;

void Tmenu::drawStartMenu()
{
    cout << "--START---\n"
            "Wybierz swoja plec\n"
            "m - mezczyzna\n"
            "k - kobieta\n"
            "Wybieram:" << flush;
}

void Tmenu::startMenuSelection()
{
    char option;
    cin >> option;
    switch (tolower(option))
    {
        case 'm':
            p = new Tmen;
            break;
        case 'k':
            p = new Twomen;
            break;
        default:
            cout << "Wybrana plec nie jest poprawna!!!\n"
                    "Sprobuj ponownie" << endl;
    }
    screenClear();
    p->create();
}

void Tmenu::drawMenu()
{
    screenClear();

    cout << "Zalogowany jako: " << p->getFirstName() << ' ' << p->getLastName() <<
         "\n---MENU---\n"
         "1. Oblicz swoje BMI\n"
         "2. Oblicz swoje zapotrzebowanie kaloryczne\n"
         //Oblicz swoje makro składniki
         "3. Pokaz srednie BMI\n"
         "4. Pokaz srednie zapotrzebowanie kaloryczne\n"
         "0. Zakoncz prace programu\n"
         "Wybieram:" << flush;
}

void Tmenu::menuSelection()
{
    char option;
    cin >> option;
    switch (tolower(option))
    {
        case '1':
            p->calculateBMI();
            break;
        case '2':
            p->calculateCalorie();
            break;
        case '3':
            cout << "TODO3";
            break;
        case '4':
            cout << "TODO4";
            break;
        case '0':
            cout << "Opuszczanie programu";
            exit(0);
        default:
            cout << "Nie ma takiej opcji!!!\n"
                    "Sprobuj ponownie" << endl;
    }
}

void Tmenu::screenClear()
{
    system("PAUSE");
    cout << string(26, '\n');
}

Tmenu::~Tmenu()
{
    if (p != nullptr)
        delete p;
}