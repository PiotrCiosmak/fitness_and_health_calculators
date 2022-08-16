//
// Created by PiotrCiosmak on 10.08.2022.
//

#include "Tmenu.hpp"
#include <iostream>
#include "TMen.hpp"
#include "TWomen.hpp"

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
    do
    {
        cin >> option;
        switch (tolower(option))
        {
            case 'm':
                person = new TMen;
                break;
            case 'k':
                person = new TWomen;
                break;
            default:
                cout << "Wybrana plec nie jest poprawna!!!\n"
                        "Sprobuj ponownie" << endl;
        }
    } while (person == nullptr);
    screenClear();
    person->create();
}

void Tmenu::drawMenu()
{
    screenClear();

    cout << "Zalogowany jako: " << person->getFirstName() << ' ' << person->getLastName() <<
         "\n---MENU---\n"
         "1. Oblicz swoje BMI\n"
         "2. Oblicz swoje zapotrzebowanie kaloryczne\n"
         "3. Oblicz swoje makroskladniki\n"
         "4. Pokaz srednie BMI\n"
         "5. Pokaz srednie zapotrzebowanie kaloryczne\n"
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
            person->calculateBMI();
            break;
        case '2':
            person->calculateCalorie();
            break;
        case '3':
            person->calculateMacronutrients();
            break;
        case '4':
            TMen::calculateAvgBMI();
            TWomen::calculateAvgBMI();
            break;
        case '5':
            TMen::calculateAvgCalorie();
            TWomen::calculateAvgCalorie();
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
    delete person;
}