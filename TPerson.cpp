//
// Created by PiotrCiosmak on 08.08.2022.
//

#include "TPerson.hpp"
#include <string>
#include <fstream>

using namespace std;

void TPerson::create()
{
    cout << "Podaj swoje imie:";
    cin >> firstName;
    cout << "Podaj swoje nazwisko:";
    cin >> lastName;
    cout << "Podaj swoj wiek:";
    cin >> age;
    cout << "Podaj swoj wzrost (cm):";
    cin >> height;
    cout << "Podaj swoja wage (kg):";
    cin >> weight;

    char tmp;
    cout << "Wybierz swoj poziom aktywnosci fizycznej\n"
            "1 - Znikoma (brak cwiczen, praca siedzaca, szkola)\n"
            "2 - Bardzo mala (cwiczenia raz na tydzien, praca lekka)\n"
            "3 - Umiarkowana (cwiczenia 2 razy w tygodniu - sredniej intensywnosci)\n"
            "4 - Duza (dosc ciezki trening kilka razy w tygodniu)\n"
            "5 - Bardzo duza (przynajmiej 4 ciezkie treningi w tygodniu, praca fizyczna)\n"
            "Wybieram:";
    cin >> tmp;
    switch (tolower(tmp))
    {
        case '1':
            act = TPerson::sedentary;
            break;
        case '2':
            act = TPerson::light;
            break;
        case '3':
            act = TPerson::active;
            break;
        case '4':
            act = TPerson::veryActive;
            break;
        case '5':
            act = TPerson::extraActive;
            break;
        default:
            cout << "Wybrano bledny poziom aktywnosci fizycznej!!!";
            exit(-1);
    }
}

string TPerson::getFirstName()
{
    return firstName;
}

std::string TPerson::getLastName()
{
    return lastName;
}

int TPerson::getCalorie()
{
    if (calorie == 0)
    {
        cout << "Najpierw musisz obliczyc swoje zapotrzebowanie kaloryczne" << endl;
        return 0;
    }
    else
    {
        return calorie;
    }
}